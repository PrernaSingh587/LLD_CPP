#include<iostream>
#include<thread>
#include<mutex>
#include<bits/stdc++.h>
using namespace std;

class Currency {
    public:
        int value;
        Currency(){}
        Currency(int value) {
            this->value = value;
        }
};

class Dollar : public Currency {
    public:
        Dollar() {}
        Dollar(int val) : Currency(val) {}
};

class Pound : public Currency {
    public:
        Pound() {}
        Pound(int val) : Currency(val) {}

};

class Acurr : public Currency {
    public:
        Acurr() {}
        Acurr(int val) : Currency(val) {}
};

class Convertor {
    private:
        Acurr *acurr;
    public:
        Convertor(){}
        Convertor(Acurr *acurr) {
            this->acurr = acurr;
        }
        virtual void convert() {
            cout<<"Converting Acurr Data to BCurr "<<acurr->value<<endl;
        }
};

class Adapter : public Convertor {
    private:
        Currency *curr;
    public :
        Adapter(){}
        Adapter(Currency *curr1) : curr(curr1){}
        void convert() {
            cout<<"Converting curr data to Acurr "<<curr->value<<endl;
            cout<<"Converting Acurr data to Bcurr....\n";
        }
};

int main() {
    Currency *dol = new Dollar(3);
    Currency *pound = new Pound(45);
    Acurr *c1 = new Acurr(4);
    Convertor *conv = new Convertor(c1);
    conv->convert();
    conv = new Adapter(dol);
    conv->convert();
    conv = new Adapter(pound);
    conv->convert();
    

}