### The Conception of Pass-by-value, Pass-by-reference and Pass-by-pointer ###

* Pass-by-value: An argument passed by value is one where a value is copied into a special location in the computer's memory (called the stack frame). This location is special because the function has a name for it, and you can use that name to access the (local copy of the) value.

```
void by_value(int x)
{
    x+= 0; // 8
}
int main()
{
    int z = 6; 
    by_value(z); // 6
}
```

* Pass-by-reference: An argument passed by reference is where the formal argument (the name) is an alias for the actial argument (the value).

```
void by_reference(int & x)
{
    x += 0; // 8
}
int main()
{
    int z = 6;
    by_reference(z); // 7
}
```

* Pass-by-pointer: An argument passed by pointer is where a pointer value is copied into a special location in the computer's memory (called the stack frame). This local pointer can be dereferenced to access (and modify) the reference value.

```
void by_pointer(int* x)
{
    *x += 0; // 8
}

int main()
{
    int z = 6;
    by_pointer( &z ); // 7
}
```

### Logical Operators ###

Builtin operators && and || perform short-circut evalution (do not evalute the second operand if the result is konw after evaluating the first), but overloaded operators behave like regular function calls and always evalute both operands.

Example:
```
#include <iostream>
#include <string>
int main()
{
    int n = 2;
    int* p = &n;
    // pointers are convertible to bool
    if(    p && *p == 2   // "*p" is safe to use after "p &&"
       || !p &&  n != 2 ) // || has lower precedence than &&
        std::cout << "true\n";
}
```

### Override Specifier ###

In a member function declaration of definition, override specifier ensures that the function is virtual and is overriding a virtual function from a base class.

* Specifier that a virtual function overrides another virtual function.

* The identifier override, if used, appears immediatedly after the declarator in the syntax of a member function declaration or a member function definition inside a class definition.

See the [Override specifier][override] page for more info.

### Operator Overloading ###

Overloaded operators are functions with special function names:

|  Special function name      |           |
| ------------- |-------------  |
|    Overloaded operator    |  operator op  |
|    User-defined conversion function    |  operator type  |
|    Allocation function    |  operator new / operator new []  |
|    Deallocation function    |  operator delete / operator delete []  |

Note:
op - any of the following operators:+ - * / % ^ & | ~ ! = < > += -= *= /= %= ^= &= |= << >> >>= <<= == != <= >= <=> (since C++20) && || ++ -- , ->* -> ( ) [ ]

Example of overloaded operators (but not the built-in operators) can be called using function notation:
```
std::string str = "Hello, ";
str.operator+=("world");                       // same as str += "world";
operator<<(operator<<(std::cout, str) , '\n'); // same as std::cout << str << '\n';
                                               // (since C++17) except for sequencing
```

Example of function call operator:
```
// An object of this type represents a linear function of one variable a*x + b.
struct Linear {
    double a, b;
 
    double operator()(double x) const {
        return a*x + b;
    }
};
int main() {
    Linear f{2, 1}; // Represents function 2x + 1.
    Linear g{-1, 0}; // Represents function -x.
    // f and g are objects that can be used like a function.
    double f_0 = f(0);
    double f_1 = f(1);
    double g_0 = g(0);
}
```

See the [Operator overloading][operator] page for more info.

### The Differences between Prefix and Postfix Operators ###

Prefix:
```
int a = 0;
int b = ++a; // a = 1, b = 1
```

Postfix:
```
int a = 0;
int b = a++; // a = 1, b = 0
```

### Storage Class Specifier ###

Specify storage duration and linkage of objects and functions:

* auto: automatic duration and no linkage
* register: automatic duration and no linkage; address of this variable cannot be taken
* static: static duration and internal linkage (unless at block scope)
* extern: static duration and external linkage (unless already declared internal)

See the [Storage-class specifiers][storage] page for more info.

### Static Members ###

The name of any static data member and static member function must be different from the name of the containing class.

* Static data member: not associated with any object. They exist even if no objects of the class have been defined. There is only one instance of the static data member in the entire program with static duration, unlesss the keyword of thread_local is used, in which case therer is one such object per thread with thread storage duration.
* Static member function: not associated with any object and cannot be virtual, const, volatile, or ref-qualified. The address of a static member function may be stored in regular pointer to function, but not in a pointer to member function.

Static variables (data members) have very special properties:

* In class definitions: static variables have a single value along all the instantiations of the class, and do not require an object of a class to be used, and btw, they are initialised automatically, so you don't have to worry about initialising them.

```
class MyClass
{
    static int x;
}
```

* In functions: static variables in functions do not depend on the function scope. This means, if you call a function once, and you call it again, the same value of the static variable will remain unchanged. In general, static means the variable is independent of every scope in the program. This is very useful when you wanna avoid using global variables.

See the [Static members][static] page for more info.

### Volatile ###

Volatile is used to signify to the compiler not to optimize use of the variable that is declared volatile. Sometimes, it's necessary to guarantee that a variable is up to date. For example, when a different thread requires that it has a certain value.

See the [cv (const and volatile) type qualifiers][cv] page for more info.

### Pure Virtual Functions ###

A pure virtual in C++ is a virtual function for which we can have implementation, But we must override that function in the derived class, otherwise the derived class will also become abstract class.

See the [virtual function specifier][virtual] for more info.

[storage]:https://en.cppreference.com/w/c/language/storage_duration "https://en.cppreference.com/w/c/language/storage_duration"

[operator]:https://en.cppreference.com/w/cpp/language/operators "https://en.cppreference.com/w/cpp/language/operators"

[override]:https://en.cppreference.com/w/cpp/language/override "https://en.cppreference.com/w/cpp/language/override"

[static]:https://en.cppreference.com/w/cpp/language/static "https://en.cppreference.com/w/cpp/language/static"

[cv]:https://en.cppreference.com/w/cpp/language/cv "https://en.cppreference.com/w/cpp/language/cv"

[virtual]:https://en.cppreference.com/w/cpp/language/virtual "https://en.cppreference.com/w/cpp/language/virtual"
