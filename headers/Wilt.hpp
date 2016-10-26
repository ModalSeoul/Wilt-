#include <string>
#include "HTTPWeb.hpp"

#ifndef WILT_H
#define WILT_H

class Wilt {
public:
    std::string getLeaderboard();
    void postScrobble();

protected:
    HTTPWeb request;
    const std::string apiUrl = "https://modal.moe/api/";
};
#endif
