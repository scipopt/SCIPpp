---
name: prepare-release
description: Prepare a SCIP++ release (changelog section, compare links, Conan fallback version). Use when the user asks to prepare, cut or bump a release version.
argument-hint: <version, e.g. 1.5.0>
disable-model-invocation: true
---

Prepare release `$ARGUMENTS` (dated today). Past example: `git show 5068906`.

1. Choose the SemVer level by reading `## [Unreleased]` in `changelog.md`. Warn the user if `$ARGUMENTS` does not fit,
   e.g. a patch bump with `### Added` entries, or anything below a major bump if there are breaking changes.
2. `changelog.md`:
   * Insert `## [$ARGUMENTS] - YYYY-MM-DD` directly below `## [Unreleased] - [Doc:Unreleased]`, so the unreleased
     section is empty again.
   * At the bottom, change `[Unreleased]: .../compare/<old>...main` to `compare/$ARGUMENTS...main` and add
     `[$ARGUMENTS]: https://github.com/scipopt/SCIPpp/releases/tag/$ARGUMENTS` above the previous release link.
3. `conanfile.py`: set the fallback in `set_version` to `self.version = "$ARGUMENTS"`.
4. Check that every `@since` for symbols added in this release uses `$ARGUMENTS`
   (`git diff <last-tag>..HEAD -- include/`).

Do not create tags or commits. Print the `git tag` command for the user to copy.
