#include <bits/stdc++.h>

using namespace std;

class Criteria {
  public:
    virtual void accept(class Visitor *) = 0;
};

class Flight : public Criteria {
    string flight;
  public:
    void accept(Visitor *);

    Flight(string flight){
        this->flight = flight;
    }

    string andCondition(){
        return " AND FLIGHT_NUMBER='"+flight+"'";
    }
};

class Segment : public Criteria {
    string origin;
    string destination;
  public:
    void accept(Visitor *);

    Segment(string origin, string destination){
        this->origin = origin;
        this->destination = destination;
    }

    string andCondition(){
        return " AND (ORIGIN='"+origin+"' AND DESTINATION='"+destination+"')";
    }
};

class Visitor{
  protected:
    string listQuery;
  public:
    virtual void visit(Flight *) = 0;
    virtual void visit(Segment *) = 0;

    string getQuery(){
        return listQuery;
    }
};

class ListPassenger : public Visitor{
  public:
    void visit(Flight *flight){
        this->listQuery += flight->andCondition();
    }

    void visit(Segment *segment){
        this->listQuery += segment->andCondition();
    }

    ListPassenger(string prefix){
        this->listQuery = "SELECT * from PASSENGER_DATA WHERE LAST_NAME='"+prefix+"'";
    }
};

void Flight::accept(Visitor *v){
    v->visit(this);
}

void Segment::accept(Visitor *v){
    v->visit(this);
}

int main(){
    Criteria *criteria[]={new Flight("6E1234"),new Segment("DEL","BLR"),0};

    ListPassenger listPassenger("SINGH");
    for(int i=0; criteria[i]; i++){
        criteria[i]->accept(&listPassenger);
    }

    string listPassengerQuery = listPassenger.getQuery();
    cout << "[QUERY] = " << listPassengerQuery << endl;

    return 0;
}

