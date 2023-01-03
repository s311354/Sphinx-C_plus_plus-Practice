Notes:
======

The fundamental features/concept of features (classes)
-----------------------------------------------------------------------------

Classes
^^^^^^^^^^^^^^

A class can have the following kinds of members (data members, members functions, nested types):

Data members
'''''''''''''

+ `non-static data members <https://en.cppreference.com/w/cpp/language/data_members>`_, including `bit-fields <https://en.cppreference.com/w/cpp/language/bit_field>`_

Non-static data members are declared in a member specification of a class.

The simple example declared non-static data members in a member specification of a class::

    class S
    {
        int n;              // non-static data member
        int &r;             // non-static data member of reference type
        int a[2] = {1, 2}   // non-static data member with default member initializer (C++ 11)

        struct NestedS
        {
            std::string s;
        } d5;               // non-static data member of nested type

        unsigned int bit : 2;       // two-bit unsigned bitfield, allowed values are 0,1,2

        // will usually occupy 2 bytes
        // 3 bits: value of b1
        // 2 bits: unused
        // 6 bits: value of b2
        // 2 bits: value of b3
        // 3 bits: unused
        unsigned char b1 : 3, : 2, b2 : 6, b3 : 2;
    }

See the `cppreference Non-static data members page <https://en.cppreference.com/w/cpp/language/data_members>`_ for more info.

+ `static data members <https://en.cppreference.com/w/cpp/language/static#Static_data_members>`_

Static data members are not associated with any object. They exist even if no objects of the class have been defined.

There is only one instance of the static data member in the entire program with **static storage duration**, unless the keyword thread_local is used, in which case there is one such object per thread with thread storage duration (since C++11).

Static data members cannot be mutable.

Static data members of a class in namespace scope have external linkage if the class itself has external linkage.

The simple example declared static data members in a member specification of a class::

    struct X
    {
        const static int n = 1;
        static const int k = 1;
        const static int m{2};                      // (since C++11)
        constexpr static int arr[] = { 1, 2, 3 };   // constexpr static data member (since C++11)
        inline static int y = 1;                    // inline static data member (since C++17)
    }

Note: static storage duration means the storage for the object is allocated when the program begins and deallocated when the program ends. Only one instance of object exists.

See the `cppreference static members page <https://en.cppreference.com/w/cpp/language/static#Static_data_members>`_ for more info.

Members functions
''''''''''''''''''

+ `non-static member functions <https://en.cppreference.com/w/cpp/language/member_functions>`_

A non-static member function is a function that is declared in a member specification of a class without a static or frend specifier.

The example declared non-static member functions::

    class S
    {
        S(): data(12) {}                 // constructors are member functions too
        int mf1();                       // non-static member function declaration
        virtual void mf2() final;        // can be virtual, can use final/override (since C++11)
        int mf3() const { return data; }
        int data;
    };

See the `cppreference non-static member functions page <https://en.cppreference.com/w/cpp/language/member_functions>`_ for more info.

+ `static member functions <https://en.cppreference.com/w/cpp/language/static#Static_member_functions>`_

static member functions are not associated with any object. When called, they **have no this pointer**.

static member functions **cannot** be virtual, const, volatile, or ref-qualified.

The address of a static member function may be stored in a regular pointer to function, but not in a pointer to member function.

See the `cppreference static member functions <https://en.cppreference.com/w/cpp/language/static#Static_member_functions>`_ for more info.

...

Nested types:
''''''''''''''

+ `nested classes <https://en.cppreference.com/w/cpp/language/nested_types>`_

A declaration of a class/struct or union may appear within another class. Such declaration declares a nested class.

The example declared nested class::

    struct enclose
    {
        struct inner
        {
            static int x;
            void f(int i);
        };
    };

    int enclose::inner::x = 1;
    void enclose::inner::f(int i) {}

See the `cppreference nested classes page <https://en.cppreference.com/w/cpp/language/nested_types>`_ for more info.

Copy Assignment Operator
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

A copy assignment operator of class T is a non-template non-static member function with the name 'operator=' that takes exactly one parameter of type T, T&, const T&, volatile T&, or const volatile T&. For a type to be CopyAssignable, it must have a public copy assignment operator.

The example of user-defined copy assignment::

    struct A
    {
        int n;
        std::string s1;

        A() = default;
        A(A const&) = default;

        // user-defined copy assignment (copy-and-swap idiom)
        A& operator=(A other)
        {
            std::swap(n, other.n);
            std::swap(s1, other.s1);
            return *this;
        }
    };

    struct B : A
    {
        std::string s2; // implicitly-defined copy assignment
    }

    int main()
    {
        A a1, a2;
        a1 = a2; // user-defined copy assignment
        B b1, b2;
        b2.s1 = "foo";
        b2.s2 = "bar";
        b1 = b2; // implicitly-defined copy assignment
        std::cout << "b1.s1" = << b1.s1 << "; b1.s2 = " << b1.s2 << "\n";
    }

    ========================
    b1.s1 = foo; b1.s2 = bar

See the `cppreference Copy assignment operator page <https://en.cppreference.com/w/cpp/language/copy_assignment>`_ for more info.

CMake Tools
-------------------

CMake is a tool to manage building of source code. Orginally, CMake was designed as a gengerator for various dialects of Makefile. It is widely used for the C and C++ language, but it may be used to build soruce code of other language too.

cmake-modules (FetchContent)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

See the `CMake cmake-modules page <https://cmake.org/cmake/help/latest/manual/cmake-modules.7.html>`_ for more info.

FetchContent
'''''''''''''''

This module enables populating content at configure time via any method supported by the ExternalPorject module.

The simple of declaring content details for some dependencies::

    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        703bd9caab50b139428cea1aaff9974ebee5742e # release-1.10.0
    )
    FetchContent_MakeAvailable(googletest)

The FetchContent_MakeAvailable() command ensure the named dependencies have been populated, either by an earlier call or by populating them itself. When performing the population, it will also add them to the main build, if possible, so that the main build can use the populated projects' targets, etc.

See the `Cmake FetchContent page <https://cmake.org/cmake/help/latest/module/FetchContent.html>`_ for more info.

GitHub Actions
---------------------

GitHub Actions jobs can be automatically triggered, where you run, and how you can interact with the code in your repository.

See the `GitHub Actions page <https://docs.github.com/en/actions>`_ for more info.

Using Jobs in Workflow
^^^^^^^^^^^^^^^^^^^^^^^^

A Workflow run is made up of one or more jobs, which run in parallel by default. To run jobs sequentially, you can define dependencies on other jobs using the 'jobs.<job_id>.needs' keyword. Each job runs in a runner environment specified by 'runs-on'.

See the `Using jobs in a workflow page <https://docs.github.com/en/actions/using-jobs/using-jobs-in-a-workflow>`_ for more info.

Workflow syntax for GitHub Actions
'''''''''''''''''''''''''''''''''''

A workflow is a configurable automated process made up of one or more jobs. You can create a YAML file to define your workflow configuration.

The simple example creating a cmake workflow configuration::

    name: CMake

    on:
      push:
        branches: [ "main" ]
      pull_request:
        branches: [ "main" ]

    env:
      # Customize the CMake build type here (Release, Debug, RelWithDebInfo, etc.)
      BUILD_TYPE: Release

    jobs:
      build:
        # The CMake configure and build commands are platform agnostic and should work equally well on Windows or Mac.
        # You can convert this to a matrix build if you need cross-platform coverage.
        # See: https://docs.github.com/en/free-pro-team@latest/actions/learn-github-actions/managing-complex-workflows#using-a-build-matrix
        runs-on: ubuntu-latest

        steps:
        - uses: actions/checkout@v3

        - name: Install Boost library
          run: sudo apt-get install libboost-all-dev

        - name: Configure CMake
          # Configure CMake in a 'build' subdirectory. `CMAKE_BUILD_TYPE` is only required if you are using a single-configuration generator such as make.
          # See https://cmake.org/cmake/help/latest/variable/CMAKE_BUILD_TYPE.html?highlight=cmake_build_type
          working-directory: ${{github.workspace}}/leetcode_practice
          run: cmake -B build -DCMAKE_BUILD_TYPE=${{env.BUILD_TYPE}}

        - name: Build
          # Build your program with the given configuration
          working-directory: ${{github.workspace}}/leetcode_practice
          run: cmake --build build --config ${{env.BUILD_TYPE}}

        - name: Test
          working-directory: ${{github.workspace}}/leetcode_practice/build
          # Execute tests defined by the CMake configuration.
          # See https://cmake.org/cmake/help/latest/manual/ctest.1.html for more detail
          run: ${{github.workspace}}/leetcode_practice/build/tests/leetcode_integration_test
          # run: ctest -C ${{env.BUILD_TYPE}}

See the `Workflow syntax for GitHub Actions page <https://docs.github.com/en/actions/using-workflows/workflow-syntax-for-github-actions#on>`_ for more info.
