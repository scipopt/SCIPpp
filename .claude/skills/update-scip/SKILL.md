---
name: update-scip
description: Update SCIP++ to a new SCIP version (Conan requirement, CI, generated parameters and statistics, changelog). Use when the user asks to bump, upgrade or update SCIP.
argument-hint: <scip-version, e.g. 10.1.0>
---

Update SCIP++ to SCIP `$ARGUMENTS`. Past examples: `git log --grep "Update to SCIP"`.

1. `conanfile.py`: set `self.requires("scip/$ARGUMENTS", ...)`. First check that this version exists on Conan Center.
2. `.github/workflows/main.yml`, job `test_without_conan`: update both occurrences of the `scipoptsuite_*.deb`
   release URL / file name.
3. Regenerate `include/scippp/parameters.hpp`. Do not edit it by hand.
   * Build the generator (it needs Boost headers, hence `with_tests`):
     `conan install -o with_utils=True -o with_tests=True --build=missing .`, `cmake --preset conan-release .`,
     `cmake --build build/Release --target gen_constexpr_parameters`.
   * Run `build/Release/utils/gen_constexpr_parameters`. Its output replaces everything between
     `// NOLINTBEGIN(readability-identifier-naming)` and `// NOLINTEND(...)`. Keep the hand-written header and
     footer, and set the `// updated for SCIP ...` comment.
   * Review the diff. Removed or renamed parameters break the API: point them out to the user and add them to the
     changelog.
4. Check whether `scip_solvingstats.h` changed (new or removed `SCIPget*(SCIP*)` functions). If it did, regenerate
   `include/scippp/solving_statistics.hpp` with `utils/extract_solvingstats.py` (dependencies in
   `utils/requirements.txt`) and update its `updated for SCIP` comment.
5. `changelog.md`: under `## [Unreleased]` → `### Changed`, add `- [PRnn](...) Update to SCIP $ARGUMENTS.` Ask the
   user for the PR number if it is unknown.

Build and run the tests only if the user asks.
