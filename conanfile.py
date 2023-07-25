from conan import ConanFile
from conan.tools.cmake import CMake, CMakeToolchain, cmake_layout
from conan.tools.scm import Git


class ScipPlusPlus(ConanFile):
    name = "scippp"
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps"
    exports_sources = "CMakeLists.txt", "source/*", "include/*"
    options = {
        "with_tests": [True, False]
    }
    default_options = {
        "with_tests": False,
    }
    _full_version: str = None

    def set_version(self):
        git = Git(self, folder=self.recipe_folder)
        try:
            self._full_version = git.run("describe --tags --dirty=-d").strip()
            self.version = self._full_version.split('-')[0]
        except:
            self.version = "0.0.0"

    def layout(self):
        cmake_layout(self)

    def requirements(self):
        self.requires("scip/8.0.3", transitive_headers=True)
        if self.options.with_tests:
            self.requires("boost/1.81.0")  # required only for tests

    def generate(self):
        tc = CMakeToolchain(self)
        tc.variables[self.name + "_version"] = self._full_version
        tc.variables["BUILD_TESTS"] = self.options.with_tests
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
