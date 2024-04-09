
#include <algorithm>

#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>

#include "./include/GetDisplayContent.hpp"

using namespace Pistache;

namespace Generic
{

    void handleReady(const Rest::Request &, Http::ResponseWriter response)
    {
        response.send(Http::Code::Ok, "1");
    }

}

class StatsEndpoint
{
public:
    explicit StatsEndpoint(Address addr)
        : httpEndpoint(std::make_shared<Http::Endpoint>(addr))
    {
    }

    void init(size_t thr = 2)
    {
        auto opts = Http::Endpoint::options()
                        .threads(static_cast<int>(thr));
        httpEndpoint->init(opts);
        setupRoutes();
    }

    void start()
    {
        httpEndpoint->setHandler(router.handler());
        httpEndpoint->serve();
    }

private:
    void setupRoutes()
    {
        using namespace Rest;
        // Routes::Get(router, "", Routes::bind(&StatsEndpoint::doRunAll, this));     // 绑定回调函数
        Routes::Get(router, "/images", Routes::bind(&StatsEndpoint::getImages, this)); // 绑定回调函数
        Routes::Get(router, "/", Routes::bind(&StatsEndpoint::doIndex, this));         // 绑定回调函数
        Routes::Get(router, "/run", Routes::bind(&StatsEndpoint::doRunAll, this));     // 绑定回调函数
        Routes::Get(router, "/run/:id", Routes::bind(&StatsEndpoint::doRunID, this));
        Routes::Post(router, "/params_json", Routes::bind(&StatsEndpoint::doPostParamsJson, this));
        Routes::Post(router, "/runresult/:id/time/:time/predictday/:day", Routes::bind(&StatsEndpoint::doGetRunResult, this)); // 需要确认
        Routes::Post(router, "/eleusers", Routes::bind(&StatsEndpoint::doAddTarget, this));
        Routes::Delete(router, "/eleusers/:id", Routes::bind(&StatsEndpoint::doDeleteTarget, this));
        Routes::Put(router, "/eleusers", Routes::bind(&StatsEndpoint::doModifyTarget, this));
        Routes::Get(router, "/eleusers/:id", Routes::bind(&StatsEndpoint::doGetTarget, this));
    }

    void getImages(const Rest::Request &request, Http::ResponseWriter response)
    {
        fileReadTool.Clear();
        fileReadTool.readFromFileToString("/home/xdyun/xdyunGit/xdyunProject/Display/newIndex.html");
        std::string content = fileReadTool.getContent();
        response.send(Http::Code::Ok, content);
    }

    void doIndex(const Rest::Request &request, Http::ResponseWriter response)
    {
        fileReadTool.Clear();
        fileReadTool.readFromFileToString("/home/xdyun/xdyunGit/xdyunProject/Display/newIndex.html");
        std::string content = fileReadTool.getContent();
        response.send(Http::Code::Ok, content);
    }

    void doRunAll(const Rest::Request &request, Http::ResponseWriter response)
    {
        fileReadTool.Clear();
        fileReadTool.readFromFileToString("/home/xdyun/xdyunGit/xdyunProject/HttpServer/Display/index.html");
        std::string content = fileReadTool.getContent();
        // response.send(Http::Code::Ok, "doRunAll");
        response.send(Http::Code::Ok, content);
    }

    void doRunID(const Rest::Request &request, Http::ResponseWriter response)
    {
        auto id = request.param(":id").as<int>();
        response.send(Http::Code::Ok, "doRunID" + std::to_string(id));
    }

    void doPostParamsJson(const Rest::Request &request, Http::ResponseWriter response)
    {
        auto body = request.body();
        response.send(Http::Code::Ok, "doPostParamsJson" + body);
    }

    void doGetRunResult(const Rest::Request &request, Http::ResponseWriter response)
    {
        auto body = request.body();
        response.send(Http::Code::Ok, "doGetRunResult" + body);
    }

    void doAddTarget(const Rest::Request &request, Http::ResponseWriter response)
    {
        auto body = request.body();
        response.send(Http::Code::Ok, "doAddTarget" + body);
    }

    void doDeleteTarget(const Rest::Request &request, Http::ResponseWriter response)
    {
        auto body = request.body();
        response.send(Http::Code::Ok, "doDeleteTarget" + body);
    }

    void doModifyTarget(const Rest::Request &request, Http::ResponseWriter response)
    {
        auto body = request.body();
        response.send(Http::Code::Ok, "doModifyTarget" + body);
    }

    void doGetTarget(const Rest::Request &request, Http::ResponseWriter response)
    {
        auto body = request.body();
        response.send(Http::Code::Ok, "doGetTarget" + body);
    }

    using Lock = std::mutex;
    using Guard = std::lock_guard<Lock>;

    std::shared_ptr<Http::Endpoint> httpEndpoint;
    Rest::Router router;

    // 私有成员工具
private:
    FileReadTool fileReadTool;
};

int main(int argc, char *argv[])
{
    Port port(8080);

    int thr = 4;

    Address addr(Ipv4::any(), port);

    std::cout << "Cores = " << hardware_concurrency() << std::endl;
    std::cout << "Using " << thr << " threads" << std::endl;

    StatsEndpoint stats(addr);

    stats.init(thr);
    stats.start();
}
