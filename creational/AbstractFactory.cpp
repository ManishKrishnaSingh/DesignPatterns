#include <iostream>

using namespace std;

enum FactoryType {SMS, EML};
enum MessageType {BOOKING, INSURANCE};

string mFactoryType[2] = {"SMS", "EML"};

class Message {
  protected:
    FactoryType factoryType;
    MessageType messageType;
  public:
    Message(FactoryType facType, MessageType msgType){
        this->factoryType = facType;
        this->messageType = msgType;
    }

    virtual void sendMessage() = 0;
};

class BookingMessage : public Message {
  public:
    BookingMessage(FactoryType facType): Message(facType, BOOKING){
        sendMessage();
    }

    void sendMessage(){
        cout<<"["<<mFactoryType[factoryType]<<"] booking details sent!"<<endl;
    }
};

class InsuranceMessage : public Message {
  public:
    InsuranceMessage(FactoryType facType): Message(facType, INSURANCE){
        sendMessage();
    }

    void sendMessage(){
        cout<<"["<<mFactoryType[factoryType]<<"] insurance details sent!"<<endl;
    }
};

class SmsFactory {
  public:
    static Message* send(MessageType msgType){
        Message* message = nullptr;
        switch (msgType){
            case BOOKING:
                message = new BookingMessage(SMS);
                break;
            case INSURANCE:
                message = new InsuranceMessage(SMS);
                break;
            default:
                break;
        }
        return message;
    }
};

class EmailFactory {
  public:
    static Message* send(MessageType msgType){
        Message* message = nullptr;
        switch (msgType){
            case BOOKING:
                message = new BookingMessage(EML);
                break;
            case INSURANCE:
                message = new InsuranceMessage(EML);
                break;
        }
        return message;
    }
};

class MessageFactory {
  public:
    static Message* send(FactoryType facType, MessageType msgType){
        Message* message = nullptr;
        switch(facType){
            case SMS:
                message = SmsFactory::send(msgType);
                break;
            case EML:
                message = EmailFactory::send(msgType);
                break;
        }
        return message;
    }
};

int main(){
    MessageFactory::send(SMS,BOOKING);
    MessageFactory::send(EML,INSURANCE);
    return 0;
}

