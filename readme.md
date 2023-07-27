# SCIP++: A C++ wrapper for SCIP

![CI Status](https://github.com/scipopt/SCIPpp/actions/workflows/main.yml/badge.svg)
![Coverage](https://img.shields.io/codecov/c/github/scipopt/SCIPpp)
[![Doxygen](https://img.shields.io/badge/documentation-Doxygen-blue)](https://scipopt.github.io/SCIPpp/)

SCIP++ is a C++ wrapper for SCIP's C interface.
It automatically manages the memory, and provides a simple interface to create linear expressions and inequalities.

## Usage

The documentation can be found at https://scipopt.github.io/SCIPpp/

Here is a simple example where we create a new model, add two variables, add a linear inequality as constraint, and ask
SCIP to solve the maximization problem.

```cpp
#include <scippp/model.hpp>
using namespace scippp;
int main() {
    Model model("Simple");
    auto x1 = model.addVar("x_1", 1);
    auto x2 = model.addVar("x_2", 1);
    model.addConstr(3 * x1 + 2 * x2 <= 1, "capacity");
    model.setObjsense(Sense::MAXIMIZE);
    model.solve();
}
```

### Model Creation

A model can be created

* without an existing SCIP environment,
* with an existing SCIP environment where all default plugins should be added to, and
* with an existing SCIP environment where no additional plugins should be added to.

```cpp
Model m1("ModelWithoutExistingSCIPEnvironment");

SCIP* scip2;
SCIPcreate(&scip2);
Model m2("ModelWithExistingSCIPEnvironmentWhereDefaultPluginsWillBeAdded", scip2);

SCIP* scip3;
SCIPcreate(&scip3);
SCIPincludeDefaultPlugins(scip3);
Model m3("ModelWithExistingSCIPEnvironmentWhereNoPluginsWillBeAdded", scip3, false);
```

### Adding Variables

Variables can be added

* one at a time,
* multiple in a vector, and
* multiple when the number is known at compile time.

```cpp
Model model("Example");

auto x = model.addVar("x");
auto vec = model.addVars("x_", 42);
const auto& [x0, x1] = model.addVars<2>("x_");
```

When adding multiple variables simultaneously to the model, they all have a coefficient of zero in the objective
function by default.
This can be changed to one by `scippp::COEFF_ONE`:
```cpp
const auto& [x1, x2] = model.addVars<2>("x_", COEFF_ONE);
```

For the coefficient, any object providing an index operator can be used:
```cpp
double operator[](std::size_t index) const
```

### Adding Constraints

Linear inequalities can be added to the model. They can be built from linear expressions:

```cpp
const auto& [x0, x1, x2, x3] = model.addVars<4>("x_");

LinExpr sum1;
sum1 += 42 * x0;
sum1 += x1;
model.addConstr(sum1 <= 0.5, "constraint1");

LinExpr sum2 = x1 + x2;
model.addConstr(sum2 == 1.25, "constraint2");

model.addConstr(1 <= x2 + 2 * x3, "constraint3");
```

### Setting Parameters

The namespace `scippp::params` contains all parameters shown https://www.scipopt.org/doc/html/PARAMETERS.php in the
header `parameters.hpp`. They are strongly typed, so that no string can be set as the value for a parameter expecting an
integer. Instead of using the predefined parameters, one can also use `scippp::params::Param<T>` directly.

```cpp
model.setParam(params::LIMITS::MAXSOL, 1);
model.setParam(params::DISPLAY::VERBLEVEL, 0);
model.setParam(params::Param<bool>("write/printzeros"), true);
```

The optimization goal can be changed by:
```cpp
model.setObjsense(Sense::MAXIMIZE);
```

### Accessing a Solution

A model can be asked for the status and the number of solutions.
A variable can be asked for its value in a given solution.

```cpp
const auto& [x0, x1] = model.addVars<2>("x_");
model.solve();
if (model.getNSols() > 0 && model.getStatus() == SCIP_STATUS_OPTIMAL) {
    Solution sol { model.getBestSol() };
    cout << "x0 + x1 =" << x0.getSolVal(sol) + x1.getSolVal(sol) << endl;
}
```

### Features Not Yet Supported

For features not yet supported by SCIP++, one can access the underlying raw SCIP object via

```cpp
SCIP* scip = model.scip();
```

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

## Maintainer

This project is maintained by Ivo Hedtke `ivo (dot) hedtke (at) dbschenker (dot) com`.

## Code of Conduct

SCIP++ follows the Contributor Covenant Code of Conduct v2, see [code_of_conduct.md](code_of_conduct.md).

## Contributor License Agreement

This project does not use a CLA.

## License

SCIP++ is licensed under the Apache-2 license, see [LICENSE](LICENSE).
