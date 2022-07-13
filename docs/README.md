## Recap C++ basic conception and alogrithm ##

Try to:
- Keep the C++ style
- Understand the fundamental alogrithm
- LeetCode - Algorithms

#### Variables and types ####

When writing programs that perform useful tasks that really save us work, we need to intorduce the concept of variables. Let's imagine that I ask you to remember the number 5, and then I ask you to also memorize the number 2 at the same time. You have just stored two different values in your memory. 

The whole process described above is a simple of what a computer can do with two variables. The same process can be expressed in C++ or python. We can now define variable as a portine of memory to store a value. Each variable needs a name that identifies it and distingushes it from the others.

The values of variables are stored somewhere in an unspecified location in the computer memory as zeros and ones. Fundamental data types are basic types implemented directly by the language that represent the basic storage units supported natively by most systems. They can mainly be classified into:
- Character types
- Numerical integer types
- Floating-point types
- Boolean type

#### The concept of Pass-by-value, Pass-by-reference and Pass-by-pointer ####

*Pass-by-value*: An argument passed by value is one where a value is copied into a special location in the computer's memory (called the "stack frame"). This location is special because the function has a name for it, and you can use that name to access the (local copy of the) value. 

<div class="language-shell highlighter-rouge"><pre class="highlight"><code class="hljs ruby"><span class="nb">
void by_value(int x)
{
    x+= 0; // 8
}

int main()
{
    int z = 6; 
    by_value(z); // 6
}
</span></code></pre></div>

*Pass-by-pointer*: An argument passed by pointer is where a pointer value is copied into a special location in the computer's memory (called the "stack frame"). This local pointer can be dereferenced to access(and modify) the referent value.

<div class="language-shell highlighter-rouge"><pre class="highlight"><code class="hljs ruby"><span class="nb">
void by_pointer(int* x)
{
    *x += 0; // 8
}

int main()
{
    int z = 6;
    by_pointer( &z ); // 7
}
</span></code></pre></div>

Pass-by-reference: An argument passed by reference is where the formal argument (the name) is an alias for the actual argument(the value).
<div class="language-shell highlighter-rouge"><pre class="highlight"><code class="hljs ruby"><span class="nb">
void by_reference(int & x)
{
    x += 0; // 8
}

int main()
{
    int z = 6;
    by_reference(z); // 7
}
</span></code></pre></div>

Note that some people dislike the term pass-by-pointer. They feel it is misleading and inexact, since the  actual argument to the function is a pointer value (an address) which is passed by value into function. Hence, they say this is really pass-by-value.

#### Logical Operators ####
Builtin operators && and || perform short-circut evalution (do not evaluate the second operand if the result is known after evaluating the first), but overloaded operators behave like regular function calls and always evalute both operands.

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

#### Override Specifier ####
In a member function declaration of definition, override specifier ensures that the function is virtual and is overriding a virtual function from a base class.

+ Specifier that a virtual function overrides another virtual function.

+ The identifier override, if used, appears immediatedly after the declarator in the syntax of a member function declaration or a member function definition inside a class definition.

#### Operator Overloading ####

Overloaded operators are functions with special function names:

|  Special function name      |           |
| ------------- |-------------  |
|    Overloaded operator    |  operator op  |
|    User-defined conversion function    |  operator type  |
|    Allocation function    |  operator new / operator new []  |
|    Deallocation function    |  operator delete / operator delete []  |
...






###### Function call operator ######

When a user-defined class overloaded the function call operator, operator(), it becomes a FunctionObject type. An object of such a type can be used in a function call expression:
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

#### The Differences between Prefix and Postfix Operators ####

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

#### Storage Class Specifier ####

The storage class specifiers are a part of the decl-specifier-seq of a name's declaration syntax. Together with the scope of the name, they control two independent properties of the name: its storage and its linkage.

- auto: no specifier
- static: static or thread storage duration and internal linkage. When used in a declaration of a class member, it declares a [static members][staticmember].
- extern: static of thread storage duration and external linkage.

#### Static Member Functions ####

Static member functions are not associated with any object and cannot be virtual, const, volatile, or ref-qualified. The address of a static member function may be stored in regular pointer to function, but not in a pointer to member function.

#### Static Data Members ####

Static data member are not associated with any object. They exist even if no objects of the class have been defined. There is only one instance of the static data member in the entire program with static duratio, unless the keyword thread_local is used, in which case there is one such object per thread with thread storage duration.

Note: 
- An inline static data member can be defined in the class defined and may specify an initializer. It does not need an out-of-class definition.
- A constant static data member can be initialized with an initializer in which every expression is a constant expression, right inside the class definition.

#### Storage Duration ####

All objects in a program have one of the following storage duration:
- automatic storage duration: The storage for the object is allocated at the beginning of the enclosing code block and deallocated at the end.
- static storage duration: The storage for the object is allocated when the program begins and deallocated when the program ends. Only one instance of object exists.
- thread storage duration: The storage for the object is allocated when the thread begins and deallocated when the thread ends. Each thread has its own instance of the object.
- dynamic storage duration: The storage for the object is allocated and deallocated upon request by using dynamic memory allocation functions.

#### What is a helper ####

A Helper class is a lesser known code smell where a coder has identified some miscellaneous, commonly used operations and attempted to make them reusable by lumping them together in an unnatural grouping. Successive developers have then come onto the project and not realised that the helper class exists, and have consequently rewitten the smae common operations, or even created more Helper classes.

#### Multiprocessing ####

Multiprocessing is the use of two or more central processing units (CPUs) within a single computer system. The term also refers to the ability of a system to support more than one processor or the ability to allocate tasks between them. There are many variations on this basic theme, and the definition of multiprocessing can vary with context, mostlt as a function of how CPUs are definition.

#### Volatile ####

Volatile is used to signify to the compiler not to optimize use of the variable that is declared volatile. Sometimes, it's necessary to guarantee that a variable is up to date. For example, when a different thread requires that it has a certain value.

#### Static Variable and Extern Variable ####
Static variables have very special properties:
- In class definitions: static variables have a single value along all the instantiations of the class, and do not require an object of a class to be used, and btw, they are initialised automatically, so you don't have to worry about initialising them.

```
class MyClass
{
    static int x;
}
```

- In functions: static variables in functions do not depend on the function scope. This means, if you call a function once, and you call it again, the same value of the static variable will remain unchanged. In general, static means the variable is independent of every scope in the program. This is very useful when you wanna avoid using global variables.


Extern variables is simple another name for global variables.





## Reference ## 
[1] [__builtin_popcount](https://tmt514.gitbooks.io/the-code-tactics-book/content/2.5/popcount.html)

[2] [bitset File Reference](https://gcc.gnu.org/onlinedocs/gcc-4.6.3/libstdc++/api/a00775.html)

[3] [使用 Git Bisect 快速找到第一個有問題的 Commit](https://www.gss.com.tw/blog/使用-git-bisect-快速找到第一個有問題的-commit)
Development environment: neovim, doxygen, try to cultivate the "brain debug" ability

[4] cppreference [static members](https://en.cppreference.com/w/cpp/language/static). [Storage class specifiers](https://en.cppreference.com/w/cpp/language/storage_duration), [Logical operators](https://en.cppreference.com/w/cpp/language/operator_logical), [Operator Overloading](https://en.cppreference.com/w/cpp/language/operators), [Override Specifier](https://en.cppreference.com/w/cpp/language/override)

[5] [StackExchange: What is a helper? Is it a design pattern? Is it an algorithm?](https://softwareengineering.stackexchange.com/questions/247267/what-is-a-helper-is-it-a-design-pattern-is-it-an-algorithm)

[6] [cplusplus: Variables and types](https://www.cplusplus.com/doc/tutorial/variables/)

[7] [cplusplus: Process v/s Threads](https://www.cplusplus.com/forum/unices/34816/)

[8] [Differences between extern and static variables.](https://www.cplusplus.com/forum/unices/67240/#msg358922)

[9] [Pure Virtual Functions](https://www.geeksforgeeks.org/pure-virtual-functions-and-abstract-classes/)

[10] [stackoverflow: What is the difference between prefix and postfix operators?](https://stackoverflow.com/questions/7031326/what-is-the-difference-between-prefix-and-postfix-operators)

[staticmember]:https://en.cppreference.com/w/cpp/language/static "https://en.cppreference.com/w/cpp/language/static"
