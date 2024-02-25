#include<iostream>
#include<thread>
#include<mutex>
#include<bits/stdc++.h>
using namespace std;

mutex mtx;

class Vehicle {
    public:
    virtual void drive()=0;
};

class Car : public Vehicle {
    public:
    void drive() {
        cout<<"car drive\n";
    }
};

class Bike : public Vehicle {
    public:
    void drive() {
        cout<<"bike drive\n";
    }
};

class Truck: public Vehicle {
    public:
    void drive() {
        cout<<"truck drive\n";
    }
};

class VehicleFactory {
    public:
    Vehicle *veh;
    Vehicle *getInstance(string input) {
            if(input=="car")
                veh = new Car();
                
            if(input=="bike")
                veh = new Bike();
            
           if(input=="truck")
                veh = new Truck();
        return veh;       
    }
};

int main() {
    VehicleFactory *vf = new VehicleFactory();
    Vehicle *veh = vf->getInstance("car");
    veh->drive();

    veh = vf->getInstance("bike");
    veh->drive();

    veh = vf->getInstance("truck");
    veh->drive();

}