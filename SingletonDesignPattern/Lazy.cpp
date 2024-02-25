#include<iostream>
#include<thread>
#include<bits/stdc++.h>
using namespace std;

class Student {
    private:
        static int time;
        Student(){
            this->time++;
            cout<<"counter is "<<this->time<<endl;
        }
        static Student *obj; // static members cant be initialised inside class
    public:
        int roll;
        static Student* getInstance() {
            if(obj == NULL) return obj = new Student();
            return obj;
        }

};

int Student::time = 0;
Student *Student::obj = NULL;

void user1() {
    Student *obj = Student::getInstance();
    obj->roll = 4;
    cout<<"us1 "<<obj->roll<<endl;
}

void user2() {
    Student *obj = Student::getInstance();
    obj->roll = 45;
    cout<<"us2 "<<obj->roll<<endl;
}

int main() {
    thread t1(user1);
    thread t2(user2);

    t1.join(); t2.join();

}