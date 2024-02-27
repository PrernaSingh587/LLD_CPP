#include<iostream>
#include<thread>
#include<mutex>
#include<bits/stdc++.h>
using namespace std;


//Hiding some APIs or data members
class EmployeeDAO {
    public:
        void insertEmp() {
            cout<<"insertEmp\n";
        }
        void getEmp(int id) {
            cout<<"getEmp "<<id<<endl;
        } 
        void delEmp(int id) {
            cout<<"DelEmp "<<id<<endl;
        }
};

class NonAdminFacade {
    public:
        void insertEmp() {
            cout<<"insertEmp\n";
        }
        void getEmp(int id) {
            cout<<"getEmp "<<id<<endl;
        } 
};


int main() {
    NonAdminFacade *naf = new NonAdminFacade();
    naf->insertEmp();
    naf->getEmp(5);

}