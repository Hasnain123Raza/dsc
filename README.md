# Data Structure C (DSC)

## Introduction

DSC is a project that attempts to capture a lot of the common data structures in C.

## Building and Installing

The project builds and installs a static library and its headers that contain all of the data structures. To build the program navigate to the project directory and run `mkdir build && cd build` to create a build directory and navigate into it. After that run `../configure` to run autotools configurations. This will generate a Makefile in the build directory that you can use to build ot install the project.

Run `make` to make the project. This should generate the `libdsc.a` file in your build directory. To run the unit tests please ensure that you have already installed `bcunit` headers and library. After that run `make check`.

To install the library, run `make install` and to uninstall run `make uninstall`. Please note you might need sudo permissions to install and uninstall. After installation, you can use this library in your own C programs by including the headers and linking the library.

## Links

Doxygen: https://hasnain123raza.github.io/dsc/

Github: https://github.com/Hasnain123Raza/dsc