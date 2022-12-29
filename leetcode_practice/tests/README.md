## Building GoogleTest with CMake ##

### Quick Start ###

build integration test included in the binary, using the GoogleTest CMake module:

```
$ cd ..

$ cmake -S . -B build
-- The C compiler identification is AppleClang 13.1.6.13160021
-- The CXX compiler identification is AppleClang 13.1.6.13160021
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
...
/Users/shi-rongliu/Documents/GitHub/cplusplus_practice/Sphinx-C_plus_plus-Practice/leetcode_practice/include
-- Configuring done
-- Generating done
-- Build files have been written to: /Users/shi-rongliu/Documents/GitHub/cplusplus_practice/Sphinx-C_plus_plus-Practice/leetcode_practice/build

$ cmake --build build
[  7%] Building CXX object src/CMakeFiles/solutions.dir/solutions.cc.o
[ 14%] Linking CXX shared library libsolutions.dylib
[ 14%] Built target solutions
...
[ 78%] Building CXX object _deps/googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
[ 85%] Linking CXX static library ../../../lib/libgmock.a
[ 85%] Built target gmock
[ 92%] Building CXX object _deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o
[100%] Linking CXX static library ../../../lib/libgmock_main.a
[100%] Built target gmock_main
```

## Reference ##

+ [Quickstart: Building with CMake](https://google.github.io/googletest/quickstart-cmake.html)


