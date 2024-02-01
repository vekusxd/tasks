from conan import ConanFile
class TEst(ConanFile):
    name = "WtTest"
    version = "0.0.1"
    settings = "os", "compiler", "arch", "build_type"
    generators = "CMakeDeps", "CMakeToolchain"

    def requirements(self):
        self.requires("wt/4.10.1")