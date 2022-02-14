#include <bits/stdc++.h>

using namespace std;

class Subject {
  public:
    virtual void handleRequest() const = 0;
};

class RealSubject : public Subject {
  public:
    void handleRequest() const override {
        cout<<"RealSubject : Handling request."<<endl;
    }
};

class ProxySubject : public Subject {
    RealSubject* subject;

    bool hasAccessToRealSubject() const {
        srand(time(0));
        int random = rand()%100;
        if(random <= 50){
            return true;
        } else {
            return false;
        }
    }

    void logAccessToRealSubject() const {
        cout<<"ProxySubject: Log request time."<<endl;
    }

  public:
    ProxySubject(RealSubject *iSubject) {
        this->subject = new RealSubject(*iSubject);
    }

    ~ProxySubject() {
        delete this->subject;
    }

    void handleRequest() const override {
        if(this->hasAccessToRealSubject()){
            this->subject->handleRequest();
            this->logAccessToRealSubject();
        }
    }
};

int main() {
    RealSubject *realSubject = new RealSubject();
    realSubject->handleRequest();

    ProxySubject *proxySubject = new ProxySubject(realSubject);
    proxySubject->handleRequest();

    return 0;
}

