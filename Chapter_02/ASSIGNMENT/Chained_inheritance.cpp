// Chained (multilevel) inheritance: Person -> Student -> GraduateStudent
#include <iostream>
#include <string>

using namespace std;
 
// LEVEL 1: base class (grandparent)
class Person {
protected:                       // protected: visible to derived classes
    string name;
    int age;
 
public:
    Person(const string& n, int a) : name(n), age(a) {}
 
    void introduce() const {
        cout << "Hi, I am " << name << ", " << age << " years old." << endl;
    }
};
 
// LEVEL 2: derived from Person (parent)
class Student : public Person {
protected:
    string studentId;
    string course;
 
public:
   Student(const string& n, int a, const string& id, const string& c)
        : Person(n, a), studentId(id), course(c) {}   // calls the Person constructor
 
    void showStudentInfo() const {
        cout << "Student ID: " << studentId << ", Course: " << course << endl;
    }
};
 
// LEVEL 3: derived from Student (child), so it also gets everything from Person
class GraduateStudent : public Student {
private:
    string thesisTopic;
    string supervisor;
 
public:
    GraduateStudent(const string& n, int a, const string& id, const string& c,
                    const string& topic, const string& sup)
        : Student(n, a, id, c), thesisTopic(topic), supervisor(sup) {}
 
    void showResearchInfo() const {
        // name is inherited from Person, studentId from Student: both are used here
        cout << name << " (" << studentId << ") is researching \""
             << thesisTopic << "\" under " << supervisor << "." << endl;
    }
};
 
int main() {
    cout << "--- Person object ---" << endl;
    Person p("Amina", 40);
    p.introduce();
 
    cout << "\n--- Student object (inherits from Person) ---" << endl;
    Student s("Brian", 20, "S1001", "Computer Science");
    s.introduce();             // inherited from Person
    s.showStudentInfo();     
    
    
 cout << "\n--- GraduateStudent object (inherits from Student and Person) ---" << endl;
    GraduateStudent g("Carol", 25, "G2005", "Data Science",
                      "KNN classification", "Dr. Okello");
    g.introduce();             // inherited from Person (grandparent)
    g.showStudentInfo();       // inherited from Student (parent)
    g.showResearchInfo();      // defined in GraduateStudent itself
 
    return 0;
}
 