#include <iostream>

using namespace std;

class Notification {
  public:
    virtual void sendNotification() = 0;
};

class SmsNotification : public Notification {
  public:
    void sendNotification() {
        cout<<"Notify by SMS!"<<endl;
    }
};

class MailNotification : public Notification {
  public:
    void sendNotification() {
        cout<<"Notify by MAIL!"<<endl;
    }
};

class NotificationFactory {
  public:
    Notification* getNotification(string notifyType){
        if(notifyType.compare("SMS")==0){
            return new SmsNotification();
        } else if(notifyType.compare("MAIL")==0){
            return new MailNotification();
        }
        return nullptr;
    }
};

int main(){
    NotificationFactory* factory = new NotificationFactory();

    Notification* sms = factory->getNotification("SMS");
    sms->sendNotification();

    Notification* mail = factory->getNotification("MAIL");
    mail->sendNotification();

    return 0;
}

