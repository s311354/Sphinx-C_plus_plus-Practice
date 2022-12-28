Notes:
======

The fundamental features/concept of features (classes, separate compilation)
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

There is only one instance of the static data member in the entire program with static storage duration, unless the keyword thread_local is used, in which case there is one such object per thread with thread storage duration (since C++11).

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

static member functions are not associated with any object. When called, they have **no this pointer**.

static member functions **cannot** be virtual, const, volatile, or ref-qualified.

The address of a static member function may be stored in a regular pointer to function, but not in a pointer to member function.

See the `cppreference static member functions <https://en.cppreference.com/w/cpp/language/static#Static_member_functions>`_ for more info.

...

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
