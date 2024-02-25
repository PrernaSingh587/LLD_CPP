#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Student {
    private:
        Student(){}
        static Student *obj; // static members cant be initialised inside class
    public:
        int roll;
        static Student* getInstance() {
            return obj;
        }
};

Student *Student::obj = new Student();

int main() {
    Student *obj = Student::getInstance();
    obj->roll = 4;
    cout<<obj->roll<<endl;
}