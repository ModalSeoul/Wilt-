#include "headers/HTTPWeb.hpp"
#include <curl/curl.h>
#include <curl/easy.h>
#include <curl/curlbuild.h>
#include <sstream>
#include <iostream>

using namespace std;

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
    string data( (const char*) ptr, (size_t) size * nmemb );
    *( (stringstream*) stream) << data << endl;
    return size * nmemb;
}

HTTPWeb::HTTPWeb()
{
    curl = curl_easy_init();
}

HTTPWeb::~HTTPWeb()
{
    curl_easy_cleanup(curl);
}

string HTTPWeb::get(const string& url)
{
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    std::stringstream out;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK)
    {
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
    }
    return out.str();
}

bool HTTPWeb::post(const string& url, const string& data)
{
    curl_global_init(CURL_GLOBAL_ALL);
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_POST, 1);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
            return true;
        }
        return false;
    }
}
