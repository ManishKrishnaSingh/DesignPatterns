#include <iostream>

using namespace std;

template <typename Derived>
class Vehicle {
  public:
    void drive(){
        static_cast<Derived*>(this)->driveVehicle();
    };

    void driveVehicle() {
        cout<<"Driving my Vehicle!"<<endl;
    }
};

class Car : public Vehicle<Car> {
    string carName;
  public:
    Car(string name){
        this->carName = name;
    }

    void driveVehicle() {
        cout<<"Driving my "<<carName<<" Car!"<<endl;
    }
};

class Bus : public Vehicle<Bus> {
    string busName;
  public:
    Bus(string name){
        this->busName = name;
    }

    void driveVehicle() {
        cout<<"Driving my "<<busName<<" Bus!"<<endl;
    }
};

int main(){
    auto myCar = new Car("Honda");
    myCar->drive();

    auto myBus = new Bus("Volvo");
    myBus->drive();

    return 0;
}

