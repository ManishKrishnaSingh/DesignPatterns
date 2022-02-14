#include <bits/stdc++.h>

using namespace std;

class Processor {
  protected:
    Processor* _processor;
  public:
    Processor(Processor* processor){
        this->_processor = processor;
    };

    virtual void handleNumber(int number){
        if(this->_processor != nullptr){
            _processor->handleNumber(number);
        }
    }
};

class ZeroProcessor : public Processor {
  public:
    ZeroProcessor(Processor* processor):Processor(processor){}

    void handleNumber(int number) {
        if (number == 0){
            cout<<"Processor [zero] : "<<number<<endl;
        } else {
            _processor->handleNumber(number); //non-zero numbers
        }
    }
};

class PositiveProcessor : public Processor {
  public:
    PositiveProcessor(Processor* processor):Processor(processor){}

    void handleNumber(int number) {
        if (number > 0){
            cout<<"Processor [+ive] : "<<number<<endl;
        } else {
            _processor->handleNumber(number); //non-positive numbers
        }
    }
};

class NegativeProcessor : public Processor {
  public:
    NegativeProcessor(Processor* processor):Processor(processor){}

    void handleNumber(int number) {
        if (number < 0){
            cout<<"Processor [-ive] : "<<number<<endl;
        } else {
            _processor->handleNumber(number); //non-negative numbers
        }
    }
};

class ChainProcessor {
    Processor* _chainProcessor;
  public:
    ChainProcessor(){
        _chainProcessor = new NegativeProcessor(new ZeroProcessor(new
        PositiveProcessor(nullptr)));
    }

    void handleNumber(int number) {
        _chainProcessor->handleNumber(number);
    }
};

int main(){
    ChainProcessor *chain = new ChainProcessor();

    //Chain of responsibility
    chain->handleNumber(0);
    chain->handleNumber(50);
    chain->handleNumber(-25);
    chain->handleNumber(100);

    return 0;
}

