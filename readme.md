# SCIP++: A C++ wrapper for SCIP

![CI Status](https://github.com/scipopt/SCIPpp/actions/workflows/main.yml/badge.svg)
[![Coverage](https://img.shields.io/codecov/c/github/scipopt/SCIPpp)](https://app.codecov.io/github/scipopt/SCIPpp)
[![Doxygen](https://img.shields.io/badge/documentation-Doxygen-blue)](https://scipopt.github.io/SCIPpp/)
[![Conan Center](https://img.shields.io/conan/v/scippp)](https://conan.io/center/recipes/scippp)

SCIP++ is a C++ wrapper for SCIP's C interface.
It automatically manages the memory, and provides a simple interface to create linear expressions and inequalities.

## Usage

The documentation, including examples for all features, can be found at https://scipopt.github.io/SCIPpp/

Here is an example where we create a new model for a knapsack problem, add binary variables with their values as
coefficients in the objective function, add the capacity constraint built from a linear expression, ask SCIP to solve
the maximization problem, and print the packed items.

```cpp
#include <iostream>
#include <scippp/model.hpp>
#include <scippp/parameters.hpp>
#include <vector>

using namespace scippp;

int main()
{
    std::vector<int> weights { 3, 4, 3, 3, 3, 3, 4, 2, 4, 1 };
    std::vector<int> values { 230, 134, 52, 60, 151, 95, 201, 245, 52, 55 };

    Model model("Knapsack");
    auto x { model.addVars("x_", weights.size(), values, VarType::BINARY) };
    LinExpr weight;
    for (size_t i { 0 }; i < weights.size(); ++i) {
        weight += weights[i] * x[i];
    }
    model.addConstr(weight <= 14, "capacity");
    model.setObjsense(Sense::MAXIMIZE);
    model.setParam(params::DISPLAY::VERBLEVEL, 0);
    model.solve();

    if (model.getNSols() > 0) {
        auto sol { model.getBestSol() };
        for (size_t i { 0 }; i < x.size(); ++i) {
            if (x[i].getSolValAsInt(sol) == 1) {
                std::cout << "pack item " << i << "\n";
            }
        }
    }
}
```

## Features

* Create a model with a new SCIP data structure or with an existing one, with or without SCIP's default plugins.
* Add variables one at a time, as a vector, or as an array for structured bindings (`scippp::Model::addVar`,
  `scippp::Model::addVars`). The objective coefficients can be given by any object providing an index operator.
* Build linear expressions (`scippp::LinExpr`) and add linear inequalities and equations as constraints
  (`scippp::Model::addConstr`).
* Set the optimization goal (`scippp::Model::setObjsense`) and all SCIP parameters in a type-safe way
  (`scippp::Model::setParam` with `scippp::params`).
* Solve the model and query its status, the number of solutions, the best solution, and the values of the variables in
  a solution (`scippp::Model::solve`, `scippp::Model::getStatus`, `scippp::Model::getNSols`,
  `scippp::Model::getBestSol`, `scippp::Var::getSolVal`).
* Add initial solutions to SCIP's solution pool (`scippp::InitialSolution`, `scippp::Model::addSolution`).
* Query solving statistics in a type-safe way (`scippp::Model::getSolvingStatistic` with `scippp::statistics`).
* Generate an Irreducible Infeasible Subsystem (`scippp::Model::generateIIS`).
* Write the original problem to a file or to standard output (`scippp::Model::writeOrigProblem`).
* Use SCIP's numerics (`scippp::Model::epsilon`, `scippp::Model::round`, `scippp::Model::isZero`,
  `scippp::Model::infinity`).
* Install custom message handlers derived from
  [`scip::ObjMessagehdlr`](https://www.scipopt.org/doc/html/classscip_1_1ObjMessagehdlr.php)
  (`scippp::Model::setMessagehdlr`).
* Include custom plugins:
  * constraint handlers derived from
    [`scip::ObjConshdlr`](https://www.scipopt.org/doc/html/classscip_1_1ObjConshdlr.php)
    (`scippp::Model::includeConshdlr`),
  * event handlers derived from
    [`scip::ObjEventhdlr`](https://www.scipopt.org/doc/html/classscip_1_1ObjEventhdlr.php)
    (`scippp::Model::includeEventhdlr`),
  * primal heuristics derived from
    [`scip::ObjHeur`](https://www.scipopt.org/doc/html/classscip_1_1ObjHeur.php)
    (`scippp::Model::includeHeur`),
  * presolvers derived from
    [`scip::ObjPresol`](https://www.scipopt.org/doc/html/classscip_1_1ObjPresol.php)
    (`scippp::Model::includePresol`), and
  * propagators derived from
    [`scip::ObjProp`](https://www.scipopt.org/doc/html/classscip_1_1ObjProp.php)
    (`scippp::Model::includeProp`).
* Access the raw SCIP object for features not yet supported (`scippp::Model::scip`).

## Build

### Without Conan

We use [Conan](https://conan.io/center/) as package manager.
That is not required! As long as `find_package(scip CONFIG REQUIRED)` (and `find_package(Boost CONFIG REQUIRED)` for
the tests) work(s), any kind of dependency management system can be used.

Build and install:

```bash
cmake .
make ScipPP
make install
```

Build and run tests:

```bash
cmake -DBUILD_TESTS=ON .
make tests
./test/tests
```

### With Conan v2 and CMake v3.19 or later

Build and install:

```bash
conan install .
cmake --preset conan-release .
cmake --build build/Release --target ScipPP
cmake --install build/Release
```

Build and run tests:

```bash
conan install -o with_tests=True .
cmake --preset conan-release .
cmake --build build/Release --target tests
build/Release/test/tests
```

If your setting of OS, compiler, C++ or stdlib version is one where conan-center does not host pre-compiled binaries,
add `--build=missing` when you run `conan install`. The dependencies will then be built from source (don't worry, they
will be available only for projects using conan, they do not interfere with versions you might already have installed
on the system). So, when you see an error message like

```
ERROR: Missing prebuilt package for 'bliss/0.77', 'boost/1.81.0', 'bzip2/1.0.8', 'gmp/6.2.1', 'libbacktrace/cci.20210118', 'scip/8.0.3', 'soplex/6.0.3', 'zlib/1.2.13'
Check the available packages using 'conan list bliss/0.77:* -r=remote'
or try to build locally from sources using the '--build=missing' argument
```

change the install-command to

```bash
conan install --build=missing .
```

### With Conan v2 and CMake v3.18 or earlier

When CMake presets are not support, use the toolchain file that conan generates.

Build and install:

```bash
conan install .
cmake . -G "Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE=./build/Release/generators/conan_toolchain.cmake -DCMAKE_POLICY_DEFAULT_CMP0091=NEW -DCMAKE_BUILD_TYPE=Release
make ScipPP
make install
```

Build and run tests:

```bash
conan install -o with_tests=True .
cmake . -G "Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE=./build/Release/generators/conan_toolchain.cmake -DCMAKE_POLICY_DEFAULT_CMP0091=NEW -DCMAKE_BUILD_TYPE=Release
make tests
./build/Release/test/tests
```

## Utils

Use `gen_constexpr_parameters` to transform all SCIP parameters into constexpr `scippp::params::Param<T>` objects which
can be added to the `parameters.hpp` header.

Use `extract_solvingstats` to transform all SCIP methods that access solving statistics into static const
`scippp::statistics::Statistic<T>` objects which can be added to the `solving_statistics.hpp` header.

## Maintainer

This project is maintained by Ivo Hedtke `ivo (dot) hedtke (at) dbschenker (dot) com`.

## Code of Conduct

SCIP++ follows the Contributor Covenant Code of Conduct v2, see [code_of_conduct.md](code_of_conduct.md).

## Contributor License Agreement

This project does not use a CLA.

## License

SCIP++ is licensed under the Apache-2 license, see [LICENSE](LICENSE).
