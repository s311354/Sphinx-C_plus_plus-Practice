### The basic concept of bewteen c++98 and c++11 ###

C++11 is the second major version of C++ and the most important update since C++98. A large number of changes were introduced to both standardize existing practices and imporve the abstractions available to the C++ programmers. Since 2011, currently, C++ updates every 3 years regularly.

### Namesapce ###

A container that includes classes and other typess and defines a declarative region that provides a way to keep one set of names separate from another. (Default namespace is global namespace.)

You can access names declared inside a namespace the same way you access a nested class name by using the scope resolution (::) operator. The identifier used for a namespace name should be unique.

If you have delcared a namesapce, you can extend the orginal namespace by adding new declarations.

See the <a href="https://en.cppreference.com/w/cpp/language/namespace">Cppreference Namesapce page</a> for more info.

### Templates ###

Templates are very useful when implementing generic constucts like **vectors**, **stacks**, **lists**, **queses** which can be used with any arbitrary type. C++ templates allow one to implement a generic Queue<T> template that has a type parameter T. There are two kinds of templates: class templates and function templates.

Class Templates:
- It provides a specfication for generating classes based on parameters.
- **It is instantiated by passing a given set of types to it as template arguments**.

For a simple example:
```
template <class T>
class mypair {
    T a, b;

    public:
        mypair (T first, T second) { a = first; b = second; }
        T getmax();
};

template <class T>
T mypair<T>::getmax()
{
    T retval;
    retval = a > b ? a : b;
    return retval;
}

int main() {
    mypair <int> myobject (100, 76);
    return 0;
}
```

Function Templates:
- Special function that can operate with generic types
- Allow to create a function template whose functionality can **be adapted to more than one type or class without repeating the entire code for each type**.

For a simple example:
```
template <class T>
T Min(const T &a, const T &b) {
    if (a < b) return a;
    else return b;
}
```

Non-type Parameters for Templates:
- Besides the template arguments that are preceded by class or typename keyworks, which represent types, templates can also have regular typed parameters, similar to those found in functions.

For a simple example:
```
template <class T, int N>
class mysequence {
        T memblock [N];
    public:
        void setmember(int x, T value);
};

template <class T, int N>
void mysequence<T, N>::setmember(int x, T value) { memblock[x] = value; }

int main() {
    mysequence <int, 5> myints;
    myints.setmember(0, 100);
    return 0;
}
```

See the <a href="https://en.cppreference.com/w/cpp/language/templates">Cppreference Templates page</a> for more info.

### Standard Templates Library (STL) ###

A software library partially included in the C++ Standard Library. It provides **Containers**, **Iterators**, **Algorithms**, and **Fnuctors**. The STL provides a ready-made set of common classes for C++, such as containers and associative arrayss, that can be used with any built-in type and with any user-defined type that supports some elementary operations.

This approach provides **compile-time polymorphism that is often more efficient** than traditional run-time polymorphism.

The standard sqeuence continers include vector, deque, and list. The standard associative container are set, multiset, map, multimap and bitset.

|  Type      |    Containers       |     	|
| ------------- |-------------  | ------- |
|    Sequence Containers    |    std::array, std::vector, std::deque, std::forward_list, std::list          |        |
|    Containers Adaptors    |    std::stack, std::queue, std::priority_queue          |        |
|    Associative Containers     | std::set, std::multiset, std::map, std::multimap      |   |
|    Unorderred Associative Containers  | std::unordered_set, std::unordered_mulitset, std::unordered_map, std::unordered_mulitmap  |   |

### The concept of vector ###

The std::vector<T>'s elements are stroed contiguously, which means that elements can be accessed not only through iterators, but also using offsets to regular points to elements. This means that a pointer to an element of a vector may be passed to any function that expects a pointer to an element of an arry.

Vectors are sequence containers representing arrays that can change in size. Just like arrays, vector use contiguous storage location for their elements, which means that their elements can also be accessed using offsets on regular pointers to its elements, and just as efficiency as in arrays. But unlike arrays, their size can change dynamically, with thei storage being handled automativally by the container.

Internally, vectors use a <span style="background-color: #FFFF00">dynamically allocated array to their elements</span>. This array may need to reallocated in order to grow in size when new elements are inserted, which implies allocating a new array and moving all elements to it. This is relatively expensive task in terms of processing time, and thus, vectors do not rellocate each time an element is added to the container.

Instead, vectors containers may allocate some extra storage to accommodate for possible growth, and thus the container may have an actual capacity greater than the storage strictly needed to contain its elements (i.e., its size).

Therefore, compared to arrays, <span style="background-color: #FFFF00">vectors comsume more memory in exchange for the ability to manage storage and grow dynamically in an efficient way</span>.

Compared to the other dynamic sequence containers (deque, lists and forward_list), <span style="background-color: #FFFF00">vectors are very efficient accessing its elements (just like arrays) and relatively efficient adding or removing elements from its end</span>.

For operation that involve <span style="background-color: #FFFF00">inserting or removing elements at positions other than the end </span>. <span style="background-color: #FFFF00">they perform worse than the others</span>, and have less consistent iterators and references than list and forward_list.

### The concept of queue and stack ###

The std::queue class is a container adaptor that gives the programmer tha functionality of a queue- specifically, a FIFO data structure. The queue pushes the elements on the back of the underlying container and pops them from the front. (key member functions: std::queue.front(), std::queue.back(), std::queue.push(), std::queue.pop(), ...)

The std::stack class is a container adaptor that gives the programmer the functionality of a stack - specifically, a LIFO data structure. The stack pushes and pops the element from the back of the underlying container, known as the top of the stack. (key member functions: std::stack.top(), std::stack().push, std::stack.pop(), ...)

See the <a href="https://en.cppreference.com/w/cpp/container/vector">Cppreference std::vector page</a> for more info.

### The concept of priority_queue ###

A priority queue is a container adaptor that provides constant time lookup of the largest (by default) element, at the expense of logarithmic insertion and extraction.

Working with a priority_queue is similar to managing a heap in some random access container, with the benefit of not being able to accidentally invalidate the heap.

Example:
```
#include <queue>
#include <vector>

int main() {
    const auto data = {1,8,5,6,3,4,0,9,7,2};
    std::priority_queue<int, std::vector<int>, std::greater<int>>
        q2(data.begin(), data.end());

    print_queue(q2);
}
```

Output:
```
0 1 2 3 4 5 6 7 8 9
```

See the <a href="https://en.cppreference.com/w/cpp/container/priority_queue">Cppreference std::priority_queue page</a> for more info.

### The concept of pair ###

std::pair is a class template that provides a way to store two heterogeneous objects as a single unit. A pair is a specific case of a std::tuple with two elements.

Note:
- std::make_pair( T1 t, T2 u ); creates a std::pair objects, deducing the target type from the types of arguments.

See the <a href="https://en.cppreference.com/w/cpp/utility/pair">Cppreference std::pair page</a> for more info.

