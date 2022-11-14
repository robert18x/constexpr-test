from conan import ConanFile
from conan.tools.files import copy
import os

class ConstexprTestConan(ConanFile):
    name = "constexpr-test"
    version = "0.1.1"
    description = ""
    license = ""
    topics = ("test", "constexpr", "header-only")
    homepage = ""
    exports_sources = "constexpr_test/*"
    no_copy_source = True

    def package_id(self):
        self.info.clear()

    def package(self):
        # copy(self, "LICENSE", src=self.source_folder, dst=os.path.join(self.package_folder, "licenses"))
        copy(self, "*.h", src=self.source_folder, dst=os.path.join(self.package_folder, "include"))
