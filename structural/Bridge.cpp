#include <bits/stdc++.h>

using namespace std;

class TravelClass {
  public:
    virtual void applyTravelClass() = 0;
};

class EconomyClass : public TravelClass {
  public:
    void applyTravelClass() {
        cout<<"Apply Class : Economy;"<<endl;
    }
};

class BusinessClass : public TravelClass {
  public:
    void applyTravelClass() {
        cout<<"Apply Class : Business;"<<endl;
    }
};

class Booking {
  protected:
    TravelClass* bookingClass;
  public:
    virtual void createBooking() = 0;
};

class AirBooking : public Booking {
  public:
    AirBooking(TravelClass* iClass){
        this->bookingClass = iClass;
    }

    void createBooking() {
        cout << "BookingType : Air;" << endl;
        this->bookingClass->applyTravelClass();
    }
};

class CarBooking : public Booking {
  public:
    CarBooking(TravelClass* iClass){
        this->bookingClass = iClass;
    }

    void createBooking() {
        cout << "BookingType : Car;" << endl;
        this->bookingClass->applyTravelClass();
    }
};

class HotelBooking : public Booking {
  public:
    HotelBooking(TravelClass* iClass){
        this->bookingClass = iClass;
    }

    void createBooking() {
        cout << "BookingType : Hotel;" << endl;
        this->bookingClass->applyTravelClass();
    }
};

int main(int argc, char* argv[]) {
    Booking* airBooking = new AirBooking(new EconomyClass());
    airBooking->createBooking();

    Booking* carBooking = new CarBooking(new BusinessClass());
    carBooking->createBooking();

    Booking* htlBooking = new HotelBooking(new BusinessClass());
    htlBooking->createBooking();

    return 0;
}
