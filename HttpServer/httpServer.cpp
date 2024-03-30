#include <pistache/endpoint.h>
#include <string>
#include <fstream>
using namespace Pistache;

struct HelloHandler : public Http::Handler{
    HTTP_PROTOTYPE(HelloHandler);
    void onRequest(const Http::Request&, Http::ResponseWriter writer) override {
        std::string index = "";
        std::ifstream file("../index.html");
        if(!file.is_open())
        {
           std::cerr << "无法打开文件" << std::endl;
           return ;
        }
         std::string line;
        while (getline(file, line)) { // 逐行读取
            index += line;
        }
        writer.send(Http::Code::Ok,index);
    }
};


int main() {
  Http::listenAndServe<HelloHandler>(Pistache::Address("*:9080"));
}


