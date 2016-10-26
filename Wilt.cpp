#include "headers/Wilt.hpp"
#include <string>
#include <iostream>

using namespace std;

string Wilt::getLeaderboard()
{
    std::string t = request.download(apiUrl + "members/most_scrobbles/?leaderboard=true");
    std::cout << t << std::endl;
    return t;
}

