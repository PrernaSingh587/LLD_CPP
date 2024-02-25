#include<iostream>
#include<thread>
#include<mutex>
#include<bits/stdc++.h>
using namespace std;

class Input {
    public:
        virtual int result() = 0;
};

class Number : public Input {
    public:
        int num;
        Number(int num) {
            this->num = num;
        }
        int result() {
            cout<<num<<" ";
            return num;
        }
};

class Multiply : public Input {
    public:
        vector<Input*>list;
        void add(Input *f) {
            list.push_back(f);
        }
        int result() {
            int i=1,ans=0;
            cout<<"( ";
            for(Input *f : list) {
                int h = f->result();
                cout<<" ";
                if(i==1) { ans+=h; cout<<"* ";}
                else
                ans*=h;
                i++;
                
            }
            cout<<") ";
             return ans;
        }
};

class Add : public Input {
    public:
        vector<Input*>list;
        void add(Input *f) {
            list.push_back(f);
        }
        int result() {
            int i=1,ans=0;
            cout<<"( ";
            for(Input *f : list) {
                int h = f->result();
                cout<<" ";
                if(i==1) { ans+=h; cout<<"+ ";}
                else
                ans+=h;
                i++;
                
            }
            cout<<") ";
             return ans;
        }
};

class Subtract : public Input { 
    public:
        vector<Input*>list;
        void add(Input *f) {
            list.push_back(f);
        }
        int result() {
            int i=1,ans=0;
            cout<<"( ";
            for(Input *f : list) {
                int h = f->result();
                cout<<" ";
                if(i==1) { ans+=h; cout<<"- ";}
                else
                ans-=h;
                i++;
               
            }
            cout<<") ";
            
             return ans;
        }
};


int main() {
    Number *num1 = new Number(3);
    Multiply *mul1 = new Multiply();
    Subtract *sub1 = new Subtract();
    Number *n2 = new Number(4), *n3 = new Number(2);
    sub1->add(n2);
    sub1->add(n3);
    mul1->add(num1); mul1->add(sub1);
    Number *n4 = new Number(40);
    Multiply *mul2 = new Multiply();
    mul2->add(mul1); mul2->add(sub1);
    cout<<mul2->result();

}