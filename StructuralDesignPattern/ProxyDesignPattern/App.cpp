#include<iostream>
#include<thread>
#include<mutex>
#include<bits/stdc++.h>
using namespace std;

class WebAppInterface {
    public:
        virtual void addEmp(string cl)  = 0;
        virtual void delEmp(string cl ) = 0;
        virtual void signUp(string cl) = 0;
        virtual void signOut(string cl) = 0;
        virtual void login(string cl) = 0;
       
};

class API : public WebAppInterface {
    public :
        void addEmp(string cl) {
            cout<<"Add Emp"<<endl;
        }
        
        void delEmp(string cl) {
            cout<<"del emp"<<endl;
        }

        void signUp(string cl) {
            cout<<"sign up\n";
        }

        void signOut(string cl) {
            cout<<"Sign Out\n";
        }

        void login(string cl) {
            cout<<"Login\n";
        }


};

class Proxy : public WebAppInterface {
    private:
        API *api;
    public:
        Proxy(API *api) : api(api){}
        void addEmp(string cl) {
            if(cl == "ADMIN")
                api->addEmp(cl);
            else cout<<"Add Emp Error"<<endl;
        }
        
        void delEmp(string cl) {
            if(cl == "ADMIN")
                api->delEmp(cl);
             else cout<<"Add Del Error"<<endl;
        }

        void signUp(string cl) {
            api->signUp(cl);
        }

        void signOut(string cl) {
            if(cl=="ADMIN" || cl=="USER")
            api->signOut(cl);
            else cout<<"error signout\n";
        }

        void login(string cl) {
             if(cl=="ADMIN" || cl=="USER")
            api->login(cl);
            else cout<<"Login error\n";
            
        }

};

int main() {
    API *api = new API();
    WebAppInterface *web = new Proxy(api);
    web->addEmp("ADMIN");
    web->login("RANDOM");
    web->signUp("djfd");
    web->delEmp("USER");
    web->signOut("USER");

}