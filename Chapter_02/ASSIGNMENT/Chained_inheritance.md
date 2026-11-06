
................Chained inheritance explanation...........................................

Chained (Multilevel) Inheritance: Person → Student → GraduateStudent
//1. Overview

This program demonstrates chained (multilevel) inheritance in C++ using a university example. Three classes are arranged in a chain: Person is the base class, Student inherits from Person, and GraduateStudent inherits from Student. Because of the chain, a GraduateStudent also receives everything that Person provides, without rewriting any of that code.

//2. The classes


Level	Class	Inherits from	Data members	Member functions

1	Person	none (base class)	name, age	introduce()
2	Student	Person	studentId, course	showStudentInfo()
3	GraduateStudent	Student	thesisTopic, supervisor	showResearchInfo()
3. How inheritance works in this program
Student is declared with class Student : public Person, so it receives name, age and introduce().
GraduateStudent is declared with class GraduateStudent : public Student, so it receives the members of Student and, through Student, the members of Person.

The data members of Person and Student are protected. This lets derived classes use them directly (for example, showResearchInfo() prints name and studentId), while outside code cannot change them.
Each derived class constructor calls its parent's constructor in the initialiser list (for example, Student(...) : Person(n, a)), so the inherited members are set up first.

//4. What main() demonstrates

A Person object calls its own introduce().
A Student object calls introduce() (inherited from Person) and showStudentInfo() (its own).
A GraduateStudent object calls introduce() (inherited from Person, two levels up), showStudentInfo() (inherited from Student) and showResearchInfo() (its own).


//5. Sample output


--- Person object ---

Hi, I am Amina, 40 years old.

--- Student object (inherits from Person) ---
Hi, I am Brian, 20 years old.
Student ID: S1001, Course: Computer Science

--- GraduateStudent object (inherits from Student and Person) ---
Hi, I am Carol, 25 years old.
Student ID: G2005, Course: Data Science
Carol (G2005) is researching "KNN classification" under Dr. Okello.

//6. How to compile and run

g++ -std=c++11 chained_inheritance.cpp -o chained_inheritance
./chained_inheritance

//7. Hand-drawn illustration

See inheritance.jpeg in this folder. It shows the three classes as boxes with arrows pointing from each child up to its parent.



