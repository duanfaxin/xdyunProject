
#include <algorithm>

#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>

#include "./include/GetDisplayContent.hpp"
#include <unistd.h>

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
        // std::cout << __FUNCTION__ << "    " << __LINE__ << endl;
        // 解析图片，为图片创建链接URL
        if (fileReadTool.readImagesToString("/home/xdyun/xdyunGit/xdyunProject/Display/images/123.jpg"))
        {
            std::string imageData = fileReadTool.getContent();
            response.headers().add<Http::Header::ContentType>("image/png");
            response.send(Http::Code::Ok, imageData);
        }
        else
        {
            response.send(Http::Code::Not_Found);
        }

        // std::string imagePath = "/home/xdyun/xdyunGit/xdyunProject/Display/images/123.jpg"; // + request.param(":image").as<std::string>();
        // std::ifstream imageFile(imagePath, std::ios::binary);
        // if (imageFile)
        // {
        //     // std::cout << " found" << endl;
        //     std::ostringstream oss;
        //     oss << imageFile.rdbuf();
        //     std::string imageData = oss.str();
        //     response.headers().add<Http::Header::ContentType>("image/png");
        //     response.send(Http::Code::Ok, imageData);
        // }
        // else
        // {
        //     std::cout << "not found" << endl;
        //     response.send(Http::Code::Not_Found);
        // }
    }

    void doIndex(const Rest::Request &request, Http::ResponseWriter response)
    {
        fileReadTool.Clear();
        fileReadTool.readFromFileToString("/home/xdyun/xdyunGit/xdyunProject/Display/index.html");
        std::string content = fileReadTool.getContent();
        response.send(Http::Code::Ok, content);
    }

    void doRunAll(const Rest::Request &request, Http::ResponseWriter response)
    {
        fileReadTool.Clear();
        fileReadTool.readFromFileToString("/home/xdyun/xdyunGit/xdyunProject/Display/newIndex.html");
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
    Port port(9080);

    int thr = 4;

    Address addr(Ipv4::any(), port);

    std::cout << "Cores = " << hardware_concurrency() << std::endl;
    std::cout << "Using " << thr << " threads" << std::endl;

    StatsEndpoint stats(addr);

    stats.init(thr);
    stats.start();
}
