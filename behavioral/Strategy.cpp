#include <bits/stdc++.h>

using namespace std;

class MailParser {
  public:
    virtual void parse(string fileName) = 0;
};

class TextMailParser : public MailParser {
  public:
    void parse(string fileName) {
        cout<<"Text Mail Parser : "<<fileName<<endl;
    }
};

class HtmlMailParser : public MailParser {
  public:
    void parse(string fileName) {
        cout<<"Html Mail Parser : "<<fileName<<endl;
    }
};

class Context {
    MailParser* mParser;
  public:
    Context(MailParser* iParser){
        this->mParser = iParser;
    }

    void executeParser(string fileName){
        this->mParser->parse(fileName);
    }
};

int main(){
    Context* ctx = nullptr;

    ctx = new Context(new TextMailParser());
    ctx->executeParser("abc.txt");

    ctx = new Context(new HtmlMailParser());
    ctx->executeParser("xyz.html");

    return 0;
}

