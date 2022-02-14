#include <bits/stdc++.h>

using namespace std;

class FileDownloader {
  public:
    virtual void download(string downloadType, string fileName) = 0;
};

class AdvancedDownloader {
  public:
    virtual void downloadPdf(string fileName) = 0;
    virtual void downloadXls(string fileName) = 0;
};

class XlsDownloader : public AdvancedDownloader {
  public:
    void downloadXls(string fileName) {
        cout<<"Downloading [XLS] => "<<fileName<<endl;
    }

    void downloadPdf(string fileName) {
        //do nothing
    }
};

class PdfDownloader : public AdvancedDownloader {
  public:
    void downloadXls(string fileName) {
        //do nothing
    }

    void downloadPdf(string fileName) {
        cout<<"Downloading [PDF] => "<<fileName<<endl;
    }
};

class DownloaderAdapter : public FileDownloader {
  private:
    AdvancedDownloader *advancedDownloader;
  public:
    DownloaderAdapter(string fileType){
        if(fileType.compare("PDF")==0){
            advancedDownloader = new PdfDownloader();
        } else if(fileType.compare("XLS")==0){
            advancedDownloader = new XlsDownloader();
        }
    }

    void download(string fileType, string fileName) {
        if(fileType.compare("PDF")==0){
            advancedDownloader->downloadPdf(fileName);
        } else if(fileType.compare("XLS")==0){
            advancedDownloader->downloadXls(fileName);
        }
    }
};

class ReportDownloader : public FileDownloader {
  private:
    DownloaderAdapter * adapter;
  public:
    void download(string fileType, string fileName) {
        if(fileType.compare("CSV")==0){
            cout<<"Downloading [CSV] => "<<fileName<<endl;
        } else if(fileType.compare("PDF") || fileType.compare("XLS")){
            adapter = new DownloaderAdapter(fileType);
            adapter->download(fileType, fileName);
        } else {
            cout<<"Invalid format: "<<fileType<<" not supported"<<endl;
        }
    }
};

int main(){
    ReportDownloader *downloader = new ReportDownloader();

    downloader->download("CSV", "xxx.csv");
    downloader->download("PDF", "abc.pdf");
    downloader->download("XLS", "xyz.xls");

    return 0;
}

