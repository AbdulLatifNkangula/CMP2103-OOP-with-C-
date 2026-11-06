......................Polymorphism explanation...................................................

Runtime Polymorphism: Shape → Circle, Rectangle, Triangle

//1. Overview

This program demonstrates runtime polymorphism in C++ using geometric shapes. A parent class Shape declares virtual functions, and three derived classes (Circle, Rectangle and Triangle) override them. When a function is called through a base-class pointer or reference, C++ decides at run time which version to run, based on the real type of the object. The same call therefore produces different behaviour for different objects.

//2. The classes

Class	Role	Data members	Overrides
Shape	Parent (abstract) class	none	declares virtual area() = 0 and virtual describe()
Circle	Derived	radius	area() = π × r², describe()
Rectangle	Derived	width, height	area() = w × h, describe()
Triangle	Derived	base, height	area() = ½ × b × h, describe()

//3. Key points of the design

Virtual functions: area() and describe() are declared virtual in Shape. This is what allows the correct overridden version to be chosen at run time.
Pure virtual function: area() = 0 means every shape must provide its own area(), and a plain Shape object cannot be created.
Overriding: each derived class replaces the functions using override, so the compiler checks that the signatures match.
Virtual destructor: virtual ~Shape() makes sure the correct destructor runs when a derived object is deleted through a Shape*.

//4. What main() demonstrates
Base-class pointers: an array Shape* shapes[3] holds pointers to a Circle, a Rectangle and a Triangle. A loop calls shapes[i]->describe() and shapes[i]->area(). The call is identical every time, but the result depends on the actual object.
Base-class reference: the function printInfo(const Shape& s) takes a reference to the base class. Passing a Circle and then a Rectangle to it again gives different results.
Cleanup: the objects created with new are deleted at the end.

//5. Sample output

--- Through base-class pointers ---
Circle with radius 3 -> area = 28.2743
Rectangle 4 x 5 -> area = 20
Triangle with base 6 and height 2.5 -> area = 7.5

--- Through a base-class reference ---
Circle with radius 1 -> area = 3.14159
Rectangle 2 x 3 -> area = 6

//6. How to compile and run
g++ -std=c++11 polymorphism.cpp -o polymorphism
./polymorphism

//7. Hand-drawn illustration

See polymorphism.jpeg in this folder. It shows Shape at the top with arrows from the three derived classes, and a Shape* pointer pointing to different objects, with the different results beside them.

