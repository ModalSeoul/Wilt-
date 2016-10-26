#include <string>

#ifndef HTTPWEB_HPP
#define HTTPWEB_HPP

class HTTPWeb {
public:
    HTTPWeb();
    ~HTTPWeb();
    std::string download(const std::string& url);
private:
    void* curl;
};
#endif
