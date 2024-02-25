#include<iostream>
using namespace std;

//Interface of a builder of Desktop
class DesktopBuilder2 {

    public:
    string ram;
    string keyboard;
    string cpu;
    string gpu;
    string mouse;
        
        virtual DesktopBuilder2* buildRam() = 0;
        virtual DesktopBuilder2* buildCPU() = 0;
        virtual DesktopBuilder2* buildGPU() = 0;
        virtual DesktopBuilder2* buildMouse() = 0;
        virtual DesktopBuilder2* buildKeyboard() = 0;
        //virtual Desktop *getComputer() = 0;
};

//Concrete Main product Desktop
class Desktop {
    public : 
    string ram;
    string keyboard;
    string cpu;
    string gpu;
    string mouse;
    Desktop() {}
    Desktop(DesktopBuilder2 *db) {
        ram = db->ram;
        keyboard = db->keyboard;
        cpu = db->cpu;
        gpu = db->gpu;
        mouse  = db->mouse;
    }

    string getRam() {
        return this->ram;
    }
    void setRam(string ram) {
        this->ram = ram;
    }

    string getKeyboard() {
        return this->keyboard;
    }
    void setKeyboard(string keyboard) {
        this->keyboard = keyboard;
    }

    string getMouse() {
        return this->mouse;
    }
    void setMouse(string mouse) {
        this->mouse = mouse;
    }

    void setGpu(string gpu) {
        this->gpu = gpu;
    }
    string getGpu() {
        return this->gpu;
    }

    void setCpu(string cpu) {
        this->cpu = cpu;
    }
    string getCpu() {
        return this->cpu;
    }

};

//Interface of a builder of Desktop
class DesktopBuilder {
    protected:
        Desktop *dtobject;
    public:
        DesktopBuilder() {
            this->dtobject = new Desktop();
        }
        virtual void buildRam() = 0;
        virtual void buildCPU() = 0;
        virtual void buildGPU() = 0;
        virtual void buildMouse() = 0;
        virtual void buildKeyboard() = 0;
        virtual Desktop *getComputer() = 0;
};



//Concrete builder class - 1
class DellDesktopBuilder : public DesktopBuilder {
    public:
        void buildCPU() {
            this->dtobject->setCpu("DELL CPU");
            
        }
        void buildGPU() {
            this->dtobject->setGpu("DELL GPU");
            
        }
        void buildKeyboard() {
            this->dtobject->setKeyboard("DELL Keyboard");
            
        }
        void buildRam() {
            this->dtobject->setRam("DELL Ram");
            
        }
        void buildMouse() {
            this->dtobject->setMouse("DELL Mouse");
         
        }
        Desktop *getComputer() {
            return this->dtobject;
        }
};

//Concrete builder class - 2
class HpDesktopBuilder : public DesktopBuilder {
    public:
        void buildCPU() {
            this->dtobject->setCpu("Hp CPU");
            
        }
        void buildGPU() {
            this->dtobject->setGpu("Hp GPU");
            
        }
        void buildKeyboard() {
            this->dtobject->setKeyboard("Hp Keyboard");
           
        }
        void buildRam() {
            this->dtobject->setRam("Hp Ram");
            
        }
        void buildMouse() {
            this->dtobject->setMouse("Hp Mouse");
           
        }
        Desktop *getComputer() {
            return this->dtobject;
        }
};

//Concrete builder class - 3
class MacDesktopBuilder : public DesktopBuilder2 {

    public:
        DesktopBuilder2* buildCPU() {
            cpu = "Mac CPU";
            return this;
            
        }
        DesktopBuilder2* buildGPU() {
            gpu = "Mac GPU";
            return this;
            
        }
        DesktopBuilder2* buildKeyboard() {
            keyboard = "Mac Keyboard";
            return this;
           
        }
        DesktopBuilder2* buildRam() {
            ram = "Mac Ram";
            return this;
            
        }
        DesktopBuilder2* buildMouse() {
            mouse = "Mac Mouse";
            return this;
           
        }
        // Desktop *getComputer() {
        //     return new Desktop(this);
        // }
};

//Concrete Director Class
class Director {
    private:
        DesktopBuilder *dtBuilder;
    public:
        Director(DesktopBuilder *dtBuilder) {
            this->dtBuilder = dtBuilder;
        }
        Desktop *createComputer() {
            this->dtBuilder->buildCPU();
            this->dtBuilder->buildGPU(); 
            this->dtBuilder->buildKeyboard();
            return this->dtBuilder->getComputer();
        }

};

int main() {
    Director *d1 = new Director(new HpDesktopBuilder());
    Director *d2 = new Director(new DellDesktopBuilder());
    Desktop *hp = d1->createComputer();
    Desktop *dell = d2->createComputer();

    DesktopBuilder2 *mc = new MacDesktopBuilder();
    Desktop *mac = new Desktop(mc->buildKeyboard()->buildCPU()->buildGPU()->buildRam());

    cout<<hp->getCpu()<<"/ "<<hp->getGpu()<<"/ "<<hp->getMouse()<<"/ "<<hp->getKeyboard()<<"/ "<<hp->getRam()<<" /"<<endl;
    cout<<"--------------------------------------------\n";
    cout<<dell->getCpu()<<"/ "<<dell->getGpu()<<"/ "<<dell->getMouse()<<"/ "<<dell->getKeyboard()<<". "<<dell->getRam()<<" /"<<endl;
    cout<<"--------------------------------------------\n";
    cout<<mac->getCpu()<<"/ "<<mac->getGpu()<<"/ "<<mac->getMouse()<<"/ "<<mac->getKeyboard()<<"/ "<<mac->getRam()<<" /"<<endl;
}
