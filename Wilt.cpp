#include "headers/Wilt.hpp"
#include <string>
#include <iostream>

using namespace std;

string Wilt::getLeaderboard()
{
    std::string req = request.get(apiUrl + "members/most_scrobbles/?leaderboard=true");
    std::cout << req << std::endl;
    return req;
}

void Wilt::postScrobble()
{
    const std::string data = "song=NiceMan&artist=coolbro";
    request.post(apiUrl + "scrobbles/", data);
}

