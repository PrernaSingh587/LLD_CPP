#include<iostream>
#include<thread>
#include<mutex>
#include<bits/stdc++.h>
using namespace std;

class FileSystem {
    public:
        virtual void ls() = 0;

};

class Directory : public FileSystem {
    private:
        string name;
       
    public:
     vector<FileSystem*>list;
        Directory(string name) {
            this->name = name;
        }
        void add(FileSystem *f) {
            list.push_back(f);
        }
        void ls() {
            cout<<"Directory "<<name<<endl;
            for(FileSystem *f : list) f->ls();
        }
};

class File : public FileSystem {
    private:
        string name;
    public:
        File(string name) {
            this->name = name;
        }
        void ls() {
            cout<<"file "<<name<<endl;
        }
};

int main() {
    Directory *movieDirectory = new Directory("Movies");
    movieDirectory->add(new File("Border"));
    Directory *comedy = new Directory("Comedy");
    movieDirectory->add(comedy);
    Directory *f = (Directory*)movieDirectory->list[1];
    f->add(new File("jaan"));
    movieDirectory->ls();

}