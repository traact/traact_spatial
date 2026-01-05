# /usr/bin/python3
import os
from conan import ConanFile


class TraactPackage(ConanFile):
    python_requires = "traact_base/0.0.0@traact/latest"
    python_requires_extend = "traact_base.TraactPackageCmake"

    name = "traact_spatial"
    version = "0.0.0"
    description = "Spatial datatypes and functions for traact using eigen geometry"
    url = "https://github.com/traact/traact_spatial.git"
    license = "MIT"
    author = "Frieder Pankratz"

    settings = "os", "compiler", "build_type", "arch"
    compiler = "cppstd"

    exports_sources = "src/*", "include/*", "tests/*", "CMakeLists.txt"

    options = {
        "shared": [True, False],
        "with_tests": [True, False],
        "trace_logs_in_release": [True, False],
    }

    default_options = {
        "shared": True,
        "with_tests": True,
        "trace_logs_in_release": True,
    }    

    def requirements(self):
        self.requires("traact_base/0.0.0@traact/latest")
        self.requires("traact_core/0.0.0@traact/latest")
        self.requires("eigen/3.4.0", transitive_headers=True, force=True)
        self.requires("ceres-solver/2.1.0", transitive_headers=True, transitive_libs=True)        

    def configure(self):
        #if self.settings.build_type != "Debug":
        #    self.options['ceres-solver'].use_glog = True
        #    self.options['ceres-solver'].use_gflags = True
        #    self.options['glog'].shared = True
        #    self.options['gflags'].shared = True
        pass

    def _after_package_info(self):
        self.cpp_info.libs = ["traact_spatial"]
