#include <bits/stdc++.h>

using namespace std;

class Report {
  public:
    virtual void addHeader() = 0;
    virtual void addRecord() = 0;
    virtual void addFooter() = 0;
};

class AccountReport : public Report {
  public:
    void addHeader() {
        cout<<"Add Account Report Header.."<<endl;
    }

    void addRecord(){
        cout<<"Add Account Report Record.."<<endl;
    }

    void addFooter(){
        cout<<"Add Account Report Footer!!"<<endl;
    }
};

class TransactionReport : public Report {
  public:
    void addHeader() {
        cout<<"Add Transaction Report Header.."<<endl;
    }

    void addRecord(){
        cout<<"Add Transaction Report Record.."<<endl;
    }

    void addFooter(){
        cout<<"Add Transaction Report Footer!!"<<endl;
    }
};

class Command {
  public:
    virtual void execute() = 0;
};

class AccountReportCommand : public Command {
    Report *report;
  public:
    AccountReportCommand(Report* iReport){
        this->report = iReport;
    }

    void execute() {
        report->addHeader();
        report->addRecord();
        report->addFooter();
    }
};

class TransactionReportCommand : public Command {
    Report *report;
  public:
    TransactionReportCommand(Report* iReport){
        this->report = iReport;
    }

    void execute() {
        report->addHeader();
        report->addRecord();
        report->addFooter();
    }
};

class ReportGenerator {
    Command* cmd;
  public:
    void setCommand(Command* cmd) {
        this->cmd = cmd;
    }

    void generate() {
        this->cmd->execute();
    }
};

int main(){
    Report* report1 = new AccountReport();
    Command* acCmd = new AccountReportCommand(report1);

    Report* report2 = new TransactionReport();
    Command* txCmd = new TransactionReportCommand(report2);

    ReportGenerator *reportGenerator = new ReportGenerator();

    reportGenerator->setCommand(acCmd);
    reportGenerator->generate();

    reportGenerator->setCommand(txCmd);
    reportGenerator->generate();

    return 0;
}

