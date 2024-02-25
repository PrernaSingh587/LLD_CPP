#include<iostream>
#include<thread>
#include<mutex>
#include<bits/stdc++.h>
using namespace std;

class BasePizza {
    public:
        virtual int cost()=0;
};

class Margeritta : public BasePizza {
    public:
        int cost() {
            return 10;
        }
};

class VegDelight : public BasePizza {
    public:
        int cost() {
            return 25;
        }
};

class FarmHouse : public BasePizza {
    public:
        int cost() {
            return 100;
        }
};

class PizzaDecorator : public BasePizza {
    protected:
    BasePizza *bp;
    public:
        PizzaDecorator(){}
        PizzaDecorator(BasePizza *bp) {
            this->bp = bp;
        }
};

class Cheese : public PizzaDecorator {
    public:
        Cheese() {}
        Cheese(BasePizza *bp) : PizzaDecorator(bp) {
        }
        int cost() {
            cout<<"Add cheese\n";
            return this->bp->cost()+10;
        }
};  

class Jalepeno : public PizzaDecorator {
    public:
        Jalepeno() {}
        Jalepeno(BasePizza *bp) : PizzaDecorator(bp) {
        }
        int  cost() {
            cout<<"Add Jalepeno\n";
            return this->bp->cost()+14;
        }
};

class Olives : public PizzaDecorator {
    public:
        Olives() {}
        Olives(BasePizza *bp) : PizzaDecorator(bp) {
        }
        int cost() {
            cout<<"Add Olives\n";
            return this->bp->cost()+17;
        }
};


int main() {
    BasePizza *bp = new Jalepeno(new Cheese(new Olives(new Cheese(new Margeritta()))));
    cout<<bp->cost()<<endl;

}