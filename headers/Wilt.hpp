#include <string>
#include "HTTPDownloader.hpp"

#ifndef WILT_H
#define WILT_H

class Wilt {
public:
    std::string getLeaderboard(); 

protected:
    HTTPDownloader request;
    const std::string apiUrl = "https://modal.moe/api/";
};
#endif
