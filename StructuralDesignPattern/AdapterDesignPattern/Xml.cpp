#include<iostream>
#include<thread>
#include<mutex>
#include<bits/stdc++.h>
using namespace std;

class Data {
    public:
        virtual void showData() = 0;
};

class XML : public Data {
    public:
        string num;
        XML(){}
        XML(string num) {
            this->num = num;
        }
        void showData() {
            cout<<num<<" ";
        }
};

class Json : public Data {
    public:
        string num;
        Json(){}
        Json(string num) {
            this->num = num;
        }
        void showData() {
            cout<<num<<" ";
        }
};

class DataAnalyticsTool  {
     
    public:
       Data *data;
        DataAnalyticsTool(Data *data) {
            this->data = data;
        }
        virtual void analyse () {
            cout<<"Analysin data ...\n";
        };
};

class Adapter : public DataAnalyticsTool {
    public:
        Adapter(Data *data) : DataAnalyticsTool(data) {}
        void analyse() {
            data->showData();
            cout<<"Converting this data to compatible data ....\n";
            cout<<"Analysing converted data\n";
        }

};

class Client {
    private :
        DataAnalyticsTool *tool;
    public:
        Client(){}
        Client(DataAnalyticsTool* tool) {
            this->tool = tool;
        }
        void processData() {
            tool->analyse();
        }
};

int main() {
    DataAnalyticsTool *tool = new Adapter(new XML("xml1233"));
    Client *c1 = new Client(tool),*c2;
    
    tool = new Adapter(new Json("Json1234"));
    c2 = new Client(tool);
    c1->processData();
    c2->processData();
    

}