# 42 c++ modules

hey, this repo contains my solutions for the **c++ modules** of the 42 school curriculum. basically, it's a series of exercises to learn **object-oriented programming (oop)**, starting from the basics of c++98 and going up to advanced stl usage.

## about the project

the goal here is to transition from c to c++. unlike modern c++, these excersises are strictly constrained to the **c++98 standard** to ensure a deep understanding of the language's mechanics, memmory management, and class design before using modern abstractions.

### key requirements
* **standard:** c++98 (`-std=c++98`).
* **compilation:** `c++ -wall -wextra -werror`.
* **memory management:** strict management of allocations (no leaks allowed!!).
* **style:** orthodox canonical form (ocf) is requiered for classes from module 02 onwards.
* **forbidden:** `printf`, `malloc`, `free`, and external libs (boost, etc.).

## Installation

this repo includes a helper script to automatically compile and check the exercises.

```
git clone https://github.com/01-kali/CPP-42.git && cd CPP-42
```

```
./cpp_launcher.sh
```

## modules breakdown

| module | topic | key concepts |
| :--- | :--- | :--- |
| **module 00** | **intro** | namespaces, classes, member functions, stdio streams, initialization lists, static, const. |
| **module 01** | **memory & pointers** | `new`/`delete`, references vs pointers, file i/o, switch statements. |
| **module 02** | **polymorphism (ad-hoc)** | operator overloading, orthodox canonical form, fixed-point numbers. |
| **module 03** | **inheritance** | inheritance basics, scavtrap, fragtrap, diamond inheritance. |
| **module 04** | **subtype polymorphism** | abstract classes, interfaces, pure virtual functions, deep copies. |
| **module 05** | **exceptions** | try/catch blocks, custom exceptions, bureaucracy simulation. |
| **module 06** | **c++ casts** | scalar conversion, `static_cast`, `reinterpret_cast`, `dynamic_cast`, serialization. |
| **module 07** | **templates** | function templates, class templates, array template. |
| **module 08** | **stl (basic)** | templated containers, iterators, algos (`easyfind`, `span`, `mutatedstack`). |
| **module 09** | **stl (advanced)** | bitcoin exchange (map), rpn (stack), pmergeme (ford-johnson sort). |

## detailed content

### module 00: basics
* **ex00 (megaphone):** basic standard output and string manipulation.
* **ex01 (phonebook):** a contact management software. handles strict field rules and basic class interaction.
* **ex02 (account):** recreating a lost `.cpp` file based on a header and a log file.

### module 01: memory
* **ex00 (braiiiiiiinnnzzzz):** allocating on the stack vs. heap.
* **ex01 (moar brainz!):** allocating arrays of objects.
* **ex02 (hi this is brain):** understanding references vs pointers.
* **ex03 (unnecessary violence):** composition and passing objects by reference.
* **ex04 (sed is for losers):** file manipulation and string replacement without `std::string::replace`.
* **ex05/06 (harl):** pointers to member functions and switch statements.

### module 02: ad-hoc polymorphism
this one is tricky because we have to manually implement fixed-point numbers since c++ doesn't have them built-in.

* **ex00-02 (fixed):** creating a fixed-point number class to handle floating point precision manually, including operator overloading (+, -, *, /, ++, --, >, <, etc.).
* **ex03 (bsp):** binary space partitioning to determine if a point is inside a triangle.

### module 03: inheritance
* **ex00-02 (traps):** creating a chain of inheriting robots (`claptrap` -> `scavtrap` -> `fragtrap`).
* **ex03 (diamondtrap):** solving the diamond problem using virtual inheritance/shadowing.


### module 04: subtype polymorphism
* **ex00 (polymorphism):** virtual functions using animal, dog, and cat classes.
* **ex01 (brain):** implementing deep copies to prevent memmory leaks in derived classes.
* **ex02 (abstract class):** converting animal to an abstract class that cannot be instantiated.
* **ex03 (interface):** implementing a materia system with pure abstract classes (interfaces).

### module 05: exceptions
* **ex00 (bureaucrat):** basics of throwing and catching exceptions (`gradetoohigh`, `gradetoolow`).
* **ex01 (form):** interaction between classes with exception handling.
* **ex02 (concrete forms):** executing specific actions (shrubbery, robotomy, presidential pardon).
* **ex03 (intern):** generating forms dynamically.

### module 06: casts
* **ex00 (conversion):** converting scalar types (char, int, float, double) and handling pseudo-literals (nan, inf).
* **ex01 (serialization):** converting pointers to `uintptr_t` and back.
* **ex02 (identify):** identifying the real type of an object (`a`, `b`, or `c`) at runtime using `dynamic_cast`.

### module 07: templates
* **ex00 (start):** simple function templates (`swap`, `min`, `max`).
* **ex01 (iter):** a generic function to iterate over any array type.
* **ex02 (array):** a generic array class template handling memory and out-of-bounds exceptions.

### module 08: stl (basic)
* **ex00 (easy find):** finding integers in containers.
* **ex01 (span):** storing and searching spans (shortest/longest) in a collection of numbers.
* **ex02 (mutated abomination):** making `std::stack` iterable by inheriting and exposing underlying container iterators.

### module 09: stl (advanced)
this is the last one. requires understanding the ford-johnson sorting algo.

* **ex00 (bitcoin exchange):** processing csv databases and dates using `std::map`.
* **ex01 (rpn):** evaluating reverse polish notation expressions using `std::stack`.
* **ex02 (pmergeme):** sorting large sequences of integers using the ford-johnson (merge-insert) algorithm with two different containers.

## resources:

### Module 00  
- [Namespaces in C++](https://iamsorush.com/posts/namespace-cpp/)  
- [Namespaces explained](https://hackingcpp.com/cpp/lang/namespaces.html)  
- [Classes and Objects - GeeksforGeeks](https://www.geeksforgeeks.org/c-classes-and-objects/)  
- [C++ Core Guidelines: Class Rules](https://www.modernescpp.com/index.php/c-core-guidelines-class-rules/)  
- [C++ Classes and Objects - Medium article](https://medium.com/@pawan2505/c-classes-and-objects-4c60de81aa2d)  
- [C++ I/O tutorial](https://www3.ntu.edu.sg/home/ehchua/programming/cpp/cp10_IO.html)  
- [Constructors explained](https://icarus.cs.weber.edu/~dab/cs1410/textbook/9.Classes_And_Objects/constructors.html)  
- [Static keyword in C++](https://www.scaler.com/topics/cpp-static/)  
- [Static functions in C++](https://codingzap.com/static-function-in-c/)  
- [Const keyword in C++](https://www.geeksforgeeks.org/const-keyword-in-cpp/)  

### Module 01  
- [New and Delete operators](https://www.geeksforgeeks.org/new-and-delete-operators-in-cpp-for-dynamic-memory/)  
- [Function pointer to member function](https://www.geeksforgeeks.org/function-pointer-to-member-function-in-cpp/)  
- [References in C++](https://unstop.com/blog/references-in-cpp)  

### Module 02  
- [Overview of Polymorphism](https://intro2oop.sdds.ca/E-Polymorphism/overview-of-polymorphism)  
- [Operator overloading in C++](https://www.geeksforgeeks.org/operator-overloading-cpp/)  
- [C++ operator overloading slides](https://web.engr.oregonstate.edu/~budd/Books/cforj/info/slides/Chapter5/tsld034.htm)  
- [Point inside a 2D triangle (StackOverflow)](https://stackoverflow.com/questions/2049582/how-to-determine-if-a-point-is-in-a-2d-triangle#:~:text=find%20the%20vectors%20connecting%20the,point%20is%20inside%20the%20triangle.)  

### Module 03  
- [Inheritance in C++ - W3Schools](https://www.w3schools.in/cplusplus/inheritance)  
- [Inheritance in C - GeeksforGeeks](https://www.geeksforgeeks.org/inheritance-in-c/)  
- [Inheritance tutorial - cplusplus.com](https://cplusplus.com/doc/tutorial/inheritance/)  

### Module 04  
- [Polymorphism in C++](https://www.geeksforgeeks.org/cpp-polymorphism/)  
- [C++ Object Layout](https://nimrod.blog/posts/what-does-cpp-object-layout-look-like/)  
- [C++ Virtual Table](https://nimrod.blog/posts/cpp-virtual-table-tables/)  
- [C++ Interfaces](https://techvidvan.com/tutorials/cpp-interface/)  
- [Pure virtual destructor](https://www.geeksforgeeks.org/pure-virtual-destructor-c/)  
- [Pure virtual functions and abstract classes](https://www.geeksforgeeks.org/pure-virtual-functions-and-abstract-classes/)  

### Module 05  
- [Exception Handling in C++](https://www.geeksforgeeks.org/cpp/exception-handling-c/)  
- [Handling Exceptions](https://docs.oracle.com/cd/E13203_01/tuxedo/tux81/creclient/except.htm)  

### Module 06  
- [Explicit type conversion](https://en.cppreference.com/w/cpp/language/explicit_cast.html)  
- [Explicit type conversion (casting) and static_cast](https://www.learncpp.com/cpp-tutorial/explicit-type-conversion-casting-and-static-cast/)  
- [Type punning](https://en.wikipedia.org/wiki/Type_punning)

### Module 07
- [An introduction to C++ templates](https://blog.feabhas.com/2014/05/an-introduction-to-c-templates/)  
- [Templates in C++](https://www.geeksforgeeks.org/cpp/templates-cpp/)  

### Module 08
- [Containers in C++ STL](https://www.geeksforgeeks.org/cpp/containers-cpp-stl/)  
- [Standard Template Library (STL) in C++](https://www.geeksforgeeks.org/cpp/the-c-standard-template-library-stl/)  
- [Introduction to Iterators in C++](https://www.geeksforgeeks.org/cpp/introduction-iterators-c/)  

### Module 09
- [Ford-Johnson Algorithm: Human Explanation & Visualisation](https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91)  
