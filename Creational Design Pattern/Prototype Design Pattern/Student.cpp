#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Prototype {
    virtual Prototype *clone()=0;
};

class Student : public Prototype {
    private :
        int id;
    public :
        string name;
        int roll;
        Student() {}
        Student(int id, string name, int roll) {
            this->id = id;
            this->name = name;
            this->roll = roll;
        }
        Student(Student *stu) {
            this->id = stu->id;
            this->name = stu->name;
            this->roll = stu->roll;
        }
        Prototype *clone() {
            return new Student(this);
        }
        void display() {
            cout<<this->id<<" "<<this->name<<" "<<this->roll<<endl;
        }
};

int main() {
    Student *stu = new Student(1,"praveen",445);
    Student *ptu = (Student*)stu->clone();
    ptu->display();
}