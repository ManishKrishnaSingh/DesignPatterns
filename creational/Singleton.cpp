#include <mutex>
#include <atomic>
#include <iostream>

using namespace std;

class Singleton {
  private:
    static mutex mtx;
    static atomic<Singleton*> instance;
    Singleton() {
        cout<<"Constructor"<<endl;
    }

  public:
    static Singleton* getInstance(){
        if(instance == nullptr) {
            lock_guard<mutex> lock(mtx);
            if(instance == nullptr) {
                instance = new Singleton();
            }
        }
        return instance;
    }

    void doSomething(){
        cout<<"Do Something!!!!!"<<endl;
    }
};

std::mutex Singleton::mtx;
atomic<Singleton*> Singleton::instance {nullptr};

int main(){
    Singleton *s1,*s2;

    s1=Singleton::getInstance();
    s1->doSomething();

    s2=Singleton::getInstance();
    s2->doSomething();

    return 0;
}

