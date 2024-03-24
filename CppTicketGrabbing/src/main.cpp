#include <iostream>
#include <curl/curl.h>

size_t writeCallback(char* ptr, size_t size, size_t nmemb, std::string* data) {
    data->append(ptr, size * nmemb);
    return size * nmemb;
}

int main() {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl_global_init(CURL_GLOBAL_ALL); //初始化
    curl = curl_easy_init();
    if (curl) {
        // curl_easy_setopt(curl, CURLOPT_URL, "https://www.baidu.com/");
        curl_easy_setopt(curl, CURLOPT_URL, "https://login.stashbox1.com/#/login");
        const char *postFields = "username=18100125832&password=xiaofeng250*";
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postFields);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "Failed to fetch URL: " << curl_easy_strerror(res) << std::endl;
        } else {
            std::cout << "Received data: " << std::endl;
            std::cout << readBuffer << std::endl;
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return 0;
}
//https://passport.baidu.com/v2/?login&tpl=mn&u=http%3A%2F%2Fwww.baidu.com%2F&sms=5
//  curl_easy_setopt(curl, CURLOPT_POST, 1L);
 
//         // 设置POST字段
//         const char *postFields = "username=你的用户名&password=你的密码";
//         curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postFields);
 
//         // 设置写数据回调函数
//         curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
 
//         // 设置写数据的用户参数
//         curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
 
//         // 执行HTTPS请求
//         res = curl_easy_perform(curl);
// curl_easy_setopt(curl, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
// curl_easy_setopt(curl, CURLOPT_USERNAME, "your_username");
// curl_easy_setopt(curl, CURLOPT_PASSWORD, "your_password");