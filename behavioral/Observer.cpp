#include <bits/stdc++.h>

using namespace std;

class Observer {
  public:
    virtual void lock(string pnr) = 0;
    virtual void unlock(string pnr) = 0;
};

class ArchiveSystem : public Observer {
  public:
    void lock(string pnr) {
        cout<<"[Archive] # Lock => "<<pnr<<endl;
    }

    void unlock(string pnr) {
        cout<<"[Archive] # Free => "<<pnr<<endl;
    }
};

class CentralSystem : public Observer {
  public:
    void lock(string pnr) {
        cout<<"[Central] # Lock => "<<pnr<<endl;
    }

    void unlock(string pnr) {
        cout<<"[Central] # Free => "<<pnr<<endl;
    }
};

class Subject {
  public:
    virtual void add(Observer* observer) = 0;
    virtual void remove(Observer* observer) = 0;
    virtual void lock(string pnr) = 0;
    virtual void unlock(string pnr) = 0;
};

class EmergencySystem : public Subject {
    string pnr;
    list<Observer*> observers;

    void notifyLock(string pnr){
        for(Observer* observer : observers) {
            observer->lock(pnr);
        }
    }

    void notifyUnLock(string pnr){
        for(Observer* observer : observers) {
            observer->unlock(pnr);
        }
    }

  public:
    void add(Observer* observer){
        observers.push_back(observer);
    }

    void remove(Observer* observer){
        observers.remove(observer);
    }

    void lock(string pnr) {
        this->pnr = pnr;
        notifyLock(pnr);
    }

    void unlock(string pnr) {
        this->pnr = pnr;
        notifyUnLock(pnr);
    }
};

int main(){
    Subject *mySystem = new EmergencySystem();

    Observer *arSystem = new ArchiveSystem();
    Observer *csSystem = new CentralSystem();

    mySystem->add(arSystem);
    mySystem->add(csSystem);

    mySystem->lock("ABCDEF");
    mySystem->unlock("ABCDEF");

    mySystem->remove(arSystem);

    mySystem->lock("XYZXYZ");
    mySystem->unlock("XYZXYZ");

    return 0;
}

