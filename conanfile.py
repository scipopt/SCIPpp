from conan import ConanFile
from conan.errors import ConanInvalidConfiguration
from conan.tools.build import check_min_cppstd
from conan.tools.cmake import CMake, CMakeToolchain, cmake_layout
from conan.tools.microsoft import check_min_vs, is_msvc
from conan.tools.scm import Git, Version


class ScipPlusPlus(ConanFile):
    name = "scippp"
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps"
    exports_sources = "CMakeLists.txt", "source/*", "include/*"
    description = "SCIP++ is a C++ wrapper for SCIP's C interface"
    package_type = "library"
    topics = ("mip", "solver", "linear", "programming")
    license = "Apache-2.0"
    homepage = "https://github.com/scipopt/SCIPpp"
    options = {
        "with_tests": [True, False],
        "with_utils": [True, False],
        "shared": [True, False],
        "fPIC": [True, False]
    }
    default_options = {
        "with_tests": False,
        "with_utils": False,
        "shared": False,
        "fPIC": True
    }

    @property
    def _min_cppstd(self):
        return 17

    @property
    def _compilers_minimum_version(self):
        return {
            "gcc": "8",
            "clang": "7",
            "apple-clang": "11",
            "msvc": "192"
        }

    def validate(self):
        if self.settings.compiler.cppstd:
            check_min_cppstd(self, self._min_cppstd)
        check_min_vs(self, 192)
        if not is_msvc(self):
            minimum_version = self._compilers_minimum_version.get(str(self.settings.compiler), False)
            if minimum_version and Version(self.settings.compiler.version) < minimum_version:
                raise ConanInvalidConfiguration(
                    f"{self.ref} requires C++{self._min_cppstd}, which your compiler does not support."
                )

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC

    def configure(self):
        if self.options.shared:
            self.options.rm_safe("fPIC")

    def set_version(self):
        if self.version is None:
            git = Git(self, folder=self.recipe_folder)
            try:
                self.version = git.run("describe --tags --dirty=-d").strip()
            except:
                self.version = "1.1.0"

    def layout(self):
        cmake_layout(self)

    def requirements(self):
        self.requires("scip/8.1.0", transitive_headers=True)
        if self.options.with_tests:
            self.requires("boost/[>=1.84.0 <2]")  # required only for tests

    def generate(self):
        tc = CMakeToolchain(self)
        tc.variables[self.name + "_version"] = self.version
        tc.variables["BUILD_TESTS"] = self.options.with_tests
        tc.variables["BUILD_UTILS"] = self.options.with_utils
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["ScipPP"]
