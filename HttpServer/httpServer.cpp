// // #include <pistache/endpoint.h>
// // #include <string>
// // #include <fstream>
// // using namespace Pistache;

// // struct HelloHandler : public Http::Handler{
// //     HTTP_PROTOTYPE(HelloHandler);
// //     void onRequest(const Http::Request&, Http::ResponseWriter writer) override {
// //         std::string index = "";
// //         std::ifstream file("../index.html");
// //         if(!file.is_open())
// //         {
// //            std::cerr << "无法打开文件" << std::endl;
// //            return ;
// //         }
// //          std::string line;
// //         while (getline(file, line)) { // 逐行读取
// //             index += line;
// //         }
// //         writer.send(Http::Code::Ok,index);
// //     }
// // };

// // int main() {
// //   Http::listenAndServe<HelloHandler>(Pistache::Address("*:9080"));
// // }

// #include <iostream>
// #include <string>
// #include <unordered_map>
// #include <vector>

// // 压缩函数
// std::string compress(const std::string &input)
// {
//     std::unordered_map<std::string, int> dictionary;
//     std::string output = "";
//     int dictSize = 256;

//     for (int i = 0; i < 256; i++)
//     {
//         dictionary[std::string(1, i)] = i;
//     }

//     std::string w = "";
//     for (char c : input)
//     {
//         std::string wc = w + c;
//         if (dictionary.find(wc) != dictionary.end())
//         {
//             w = wc;
//         }
//         else
//         {
//             output += std::to_string(dictionary[w]) + " ";
//             dictionary[wc] = dictSize++;
//             w = std::string(1, c);
//         }
//     }

//     if (!w.empty())
//     {
//         output += std::to_string(dictionary[w]);
//     }

//     return output;
// }

// // 解压缩函数
// std::string decompress(std::string &input)
// {
//     std::unordered_map<int, std::string> dictionary;
//     std::string output = "";
//     int dictSize = 256;

//     for (int i = 0; i < 256; i++)
//     {
//         dictionary[i] = std::string(1, i);
//     }

//     std::vector<int> compressed;
//     std::string::size_type pos = 0;
//     std::string token;
//     while ((pos = input.find(' ', pos)) != std::string::npos)
//     {
//         token = input.substr(0, pos);
//         compressed.push_back(std::stoi(token));
//         input.erase(0, pos + 1);
//     }

//     std::string w = std::string(1, compressed[0]);
//     output += w;
//     for (size_t i = 1; i < compressed.size(); i++)
//     {
//         std::string entry;
//         if (dictionary.find(compressed[i]) != dictionary.end())
//         {
//             entry = dictionary[compressed[i]];
//         }
//         else if (compressed[i] == dictSize)
//         {
//             entry = w + w[0];
//         }
//         else
//         {
//             throw "Bad compressed k";
//         }
//         output += entry;
//         dictionary[dictSize++] = w + entry[0];
//         w = entry;
//     }

//     return output;
// }

// int main()
// {
//     std::string input = "TOBEORNOTTOBEORTOBrere";
//     std::string compressed = compress(input);
//     std::cout << "Compressed: " << compressed << std::endl;
//     std::string decompressed = decompress(compressed);
//     std::cout << "Decompressed: " << decompressed << std::endl;
//     return 0;
// }

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, int> compressLZW(const string &input)
{
    unordered_map<string, int> dictionary;
    for (int i = 0; i < 256; i++)
    {
        dictionary[string(1, char(i))] = i;
    }

    string current = "";
    unordered_map<string, int> compressedData;
    int code = 256;

    for (char c : input)
    {
        string currentPlusC = current + c;
        if (dictionary.find(currentPlusC) != dictionary.end())
        {
            current = currentPlusC;
        }
        else
        {
            compressedData[current] = dictionary[current];
            dictionary[currentPlusC] = code;
            code++;
            current = string(1, c);
        }
    }

    if (!current.empty())
    {
        compressedData[current] = dictionary[current];
    }

    return compressedData;
}

string decompressLZW(const unordered_map<string, int> &compressedData)
{
    unordered_map<int, string> dictionary;
    for (int i = 0; i < 256; i++)
    {
        dictionary[i] = string(1, char(i));
    }

    int code = 256;
    string current = "";
    string output = "";

    for (const auto &pair : compressedData)
    {
        int k = pair.second;
        string entry;
        if (dictionary.find(k) != dictionary.end())
        {
            entry = dictionary[k];
        }
        else if (k == code)
        {
            entry = current + current[0];
        }
        else
        {
            throw logic_error("Bad compressed k");
        }

        output += entry;

        if (!current.empty())
        {
            dictionary[code] = current + entry[0];
            code++;
        }

        current = entry;
    }

    return output;
}

int main()
{
    string input = "ABABABAABABABA";
    unordered_map<string, int> compressedData = compressLZW(input);

    string decompressedOutput = decompressLZW(compressedData);

    cout << "Original: " << input << endl;
    cout << "Decompressed: " << decompressedOutput << endl;

    return 0;
}
