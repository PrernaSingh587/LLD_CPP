#include<iostream>
#include<thread>
#include<mutex>
#include<bits/stdc++.h>
using namespace std;

class Invoice {
    public:
        void generateInvoice() {
            cout<<"generateInvoice\n";
        }
};

class Product {
     public:
        void getProduct() {
            cout<<"getProduct\n";
        }
};

class Payment {
     public:
        void makePayment() {
            cout<<"makePayment\n";
        }
};

class Notification {
     public:
        void sendNotif() {
            cout<<"sendNotif\n";
        }
};

class OrderFacade {

    public :
        void createOrder() {
            Product *pro = new Product();
            pro->getProduct();
            Payment *p = new Payment();
            p->makePayment();
            Invoice *inv = new Invoice();
            inv->generateInvoice();
            Notification *notf = new Notification();
            notf->sendNotif();
        }
};

int main() {
    OrderFacade *orf = new OrderFacade();
    orf->createOrder();

}