[![Documentation Status](https://readthedocs.org/projects/sphinx-c-plus-plus-practice/badge/?version=latest)](https://sphinx-c-plus-plus-practice.readthedocs.io/en/latest/?badge=latest) ![Build](https://github.com/s311354/Sphinx-C_plus_plus-Practice/actions/workflows/cmake.yml/badge.svg)

## Sphinx C_plus_plus Practice

### Introduction ###

This library is the C++ version of Leetcode quiz. It is used for the Sphinx documentation tutorial specifically.

### Plot ###

This tutorial used a simple c++ project (Leetcode Sample Project) to demonstrates how to use Sphinx to generate HTML-based documents. The generatd documents look like the picture below.

<figure><center><img src="./images/layout.png" width="80%"></center></figure>

### Files ###

The layout of the Leetcode Sample Project after we delete the docs and build folders in [`leetcode_practice`](leetcode_practice/) look like:

```
.
|-- docs
|   |-- DOCUMENTATION_STL.md
|   |-- doxygen
|   |   `-- Doxyfile
|   |-- README.md
|   |-- requirements.txt
|   `-- sphinx
|       |-- make.bat
|       |-- Makefile
|       |-- README.md
|       `-- source
|           |-- api.rst
|           |-- conf.py
|           |-- contents.rst
|           |-- guide.rst
|           |-- index.rst
|           `-- readme_link.rst
|-- images
|   `-- layout.png
|-- leetcode_practice
|   |-- CMakeLists.txt
|   |-- examples
|   |   |-- CMakeLists.txt
|   |   `-- unit
|   |       |-- CMakeLists.txt
|   |       |-- main.cc
|   |       `-- unit
|   |-- files
|   |   |-- balancedstone.txt
|   |   |-- CMakeLists.txt
|   |   |-- critical.txt
|   |   `-- input.txt
|   |-- include
|   |   |-- config.h.in
|   |   |-- solutions.h
|   |   `-- utils.h
|   |-- src
|   |   |-- CMakeLists.txt
|   |   |-- README.md
|   |   `-- solutions.cc
|   `-- tests
|       |-- CMakeLists.txt
|       |-- leetcode_integration_test.cc
|       `-- README.md
`-- README.md
```

To build the code that configurated by in CMakeLists.txt file, you can follow with the commands below in the [`leetcode_practice`](\leetcode_practice) directory:
```
$ cmake -B build
$ cmake --build build
```

### Installation ###

Assumptions and Requirements

+ Sphinx 1.3.6
+ C++ 11
+ CMake 3.25
+ Doxygen 1.8.11
+ Boost

Note: Sphinx can run on Ubuntu 16.4 LTS and MacOS. 

## Reference ##

+ [Breathe’s documentation](https://breathe.readthedocs.io/en/latest/)

+ [C/C++ Documentation Using Sphinx](https://leimao.github.io/blog/CPP-Documentation-Using-Sphinx/)

+ [Using Sphinx for Python Documentation](https://shunsvineyard.info/2019/09/19/use-sphinx-for-python-documentation/)

+ [Sample Binary Tree Library](https://python-sample-code.readthedocs.io/en/latest/readme.html)
