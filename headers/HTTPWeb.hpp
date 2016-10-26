#include <string>

#ifndef HTTPWEB_HPP
#define HTTPWEB_HPP

class HTTPWeb {
public:
    HTTPWeb();
    ~HTTPWeb();
    std::string get(const std::string& url);
    bool post(const std::string& url, const std::string& data);
private:
    void* curl;
};
#endif
