#include<iostream>
#include<thread>
#include<mutex>
#include<bits/stdc++.h>
using namespace std;

class Breathe {
    public:
        virtual void breatheProcess(string name) = 0;
};

class GillBreathe : public Breathe {
    public:
        void breatheProcess(string name) {
            cout<<name<<" Gill Breathe\n";
        }
};

class NoseBreathe : public Breathe {
    public:
        void breatheProcess(string name) {
            cout<<name<<" Nose Breathe\n";
        }
};

class WhaleBreathe : public Breathe {
    public:
        void breatheProcess(string name) {
            cout<<name<<" whale Breathe\n";
        }
};

class LivingThings {
    protected:
        Breathe *breathe ;
    public:
        LivingThings(){}
        LivingThings(string name, Breathe *breath) {
            this->name = name;
            this->breathe = breath;
        }
        string name;
        virtual void breatheProcess() = 0;
};

class Human: public LivingThings {
    
    public:
        Human(){}
        Human(string name, Breathe *breathe) : LivingThings(name,breathe){}
        void breatheProcess() {
            breathe->breatheProcess(name);
        }
        

};

class Fish: public LivingThings {
    
    public:
        Fish(){}
        Fish(string name, Breathe *breathe) : LivingThings(name,breathe){}
        void breatheProcess() {
            breathe->breatheProcess(name);
        }

};

class Whale: public LivingThings {
    
    public:
        Whale(){}
        Whale(string name, Breathe *breathe) : LivingThings(name,breathe){}
        void breatheProcess() {
            breathe->breatheProcess(name);
        }
        

};

//can extend living things and one dimension (breatheprocess ) independently

int main() {
    Breathe *breathe = new GillBreathe();
    LivingThings *liv = new Human("Aditya", breathe);
    liv->breatheProcess();
    liv = new Whale("Whale", new NoseBreathe() );
    liv->breatheProcess();


}