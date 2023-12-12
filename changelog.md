# Changelog
The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html) since its version 1.0.0.

## [Unreleased] - [Doc:Unreleased]

### Changed

- [PR20](https://github.com/scipopt/SCIPpp/pull/20) `LinExpr` can be constructed from any arithmetic type without
  requiring a `static_cast`.

### Added

- [PR18](https://github.com/scipopt/SCIPpp/pull/18) Add `Var::isVoid`.

## [1.1.0] - 2023-10-15

### Changed

- [PR14](https://github.com/scipopt/SCIPpp/pull/14) Using SCIP 8.0.4 now.

### Added

- [PR12](https://github.com/scipopt/SCIPpp/pull/12)
  Expose SCIP counterparts via `Model::epsilon`, `Model::round`, and `Model::isZero`.
- [PR11](https://github.com/scipopt/SCIPpp/pull/11)
  IO methods `Model::writeOrigProblem` to write a model to a file or standard output.

### Fixed

- [PR12](https://github.com/scipopt/SCIPpp/pull/12)
  Added more const-correctness

## [1.0.2] - 2023-08-12

### Fixed

- [PR7](https://github.com/scipopt/SCIPpp/pull/7)
  Export symbols on Windows.

## [1.0.1] - 2023-08-10

### Added

- [PR6](https://github.com/scipopt/SCIPpp/pull/6)
  Added attributes `description`, `package_type`, `topics`, `license`, and `homepage` to `conanfile.py`.

### Fixed

- [PR6](https://github.com/scipopt/SCIPpp/pull/6)
  Downgraded minimum CMake version from 3.16 to 3.15.7

## [1.0.0] - 2023-08-09

Initial release

[Doc:Unreleased]: https://scipopt.github.io/SCIPpp/
[Unreleased]: https://github.com/scipopt/SCIPpp/compare/1.1.0...main
[1.1.0]: https://github.com/scipopt/SCIPpp/releases/tag/1.1.0
[1.0.2]: https://github.com/scipopt/SCIPpp/releases/tag/1.0.2
[1.0.1]: https://github.com/scipopt/SCIPpp/releases/tag/1.0.1
[1.0.0]: https://github.com/scipopt/SCIPpp/releases/tag/1.0.0
