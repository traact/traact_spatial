# /usr/bin/python3
import os
from conans import ConanFile, CMake, tools


class TraactPackage(ConanFile):
    python_requires = "traact_run_env/1.0.0@traact/latest"
    python_requires_extend = "traact_run_env.TraactPackageCmake"

    name = "traact_spatial"
    description = "Spatial datatypes and functions for traact using eigen geometry"
    url = "https://github.com/traact/traact_spatial.git"
    license = "MIT"
    author = "Frieder Pankratz"

    settings = "os", "compiler", "build_type", "arch"
    compiler = "cppstd"

    exports_sources = "src/*", "util/*", "tests/*", "CMakeLists.txt"

    def requirements(self):
        self.traact_requires("traact_core", "latest")
        self.requires("eigen/[>=3.4.0]")
        self.requires("ceres-solver/2.0.0")
        if self.options.with_tests:
            self.requires("gtest/[>=1.11.0]")

    def configure(self):
        if self.settings.build_type != "Debug":
            self.options['ceres-solver'].use_glog = True;
            self.options['ceres-solver'].use_gflags = True;
            self.options['glog'].shared = True;
            self.options['gflags'].shared = True;