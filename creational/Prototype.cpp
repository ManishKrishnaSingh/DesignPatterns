#include <iostream>
#include <unordered_map>

using namespace std;

class BookingView {
  public:
    virtual BookingView* clone() const = 0;
    virtual void createView(string iIdentifier) = 0;
};

class AgencyView : public BookingView {
  public:
    BookingView* clone() const override {
        return new AgencyView(*this);
    }

    void createView(string iIdentifier) {
        cout<<"Agency["<<iIdentifier<<"] - View created!"<<endl;
    }
};

class AirlineView : public BookingView {
  public:
    BookingView* clone() const override {
        return new AirlineView(*this);
    }

    void createView(string iIdentifier) {
        cout<<"Airline["<<iIdentifier<<"] - View created!"<<endl;
    }
};

class ViewFactory {
    unordered_map<string, BookingView*> mView;
  public:
    ViewFactory() {
        mView["Agency"]  = new AgencyView();
        mView["Airline"] = new AirlineView();
    }

    ~ViewFactory() {
        delete mView["Agency"];
        delete mView["Airline"];
    }

    BookingView *clone(string vType) {
        return mView[vType]->clone();
    }
};

int main() {
    BookingView *view = nullptr;
    ViewFactory *factory = new ViewFactory();

    view = factory->clone("Agency");
    view->createView("Yatra.com");

    view = factory->clone("Airline");
    view->createView("Spicejet");

    return 0;
}
