from conan import ConanFile

class ConstexprTestConan(ConanFile):
    name = "constexpr-test"
    version = 0.1
    description = ""
    license = ""
    topics = ("test", "constexpr", "header-only")
    homepage = ""
    exports_sources = "constexpr_test/*"
    no_copy_source = True

    def package(self):
        self.copy("*.h")
