#include <bits/stdc++.h>

using namespace std;

class Ignition {
  public:
    void ignitionOn() {
        cout<<"Turn on the IgnitionKey.\n";
    }
};

class HeadLight {
  public:
    void headLightOn() {
        cout<<"Turn on the Head-Lights.\n";
    }
};

class Car {
  private:
    Ignition ignition;
    HeadLight headLight;
  public:
    void start() {
        cout<<"Starting the car..\n";
        ignition.ignitionOn();
        headLight.headLightOn();
        cout<<"Car is moving on the road!";
    }
};

int main() {
    Car myCar;
    myCar.start();
    return 0;
}

