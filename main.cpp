#include <iostream>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>


using namespace std;
using json= nlohmann::json;


string url="https://codeforces.com/api/";


string make_req(string& url)
{
    cpr::Response response = cpr::Get(cpr::Url{url});
    return response.text;
}

/* -- BLOGS -- */
string blogEntry(string action,string id)
{
    if(action=="view")
    {
        url+="blogEntry.view?blogEntryId="+id;
    }
    if(action=="comments")
    {
      url+="blogEntry.comments?blogEntryId="+id;
    }
    return make_req(url);
}


/* -- CONTESTS -- */
/*
string contest_hacks(string id, string asManager)
{
    url+="contest.hacks?contestId="+id;
    return make_req(url);
}

string contest_list( string gym, string groupCode)
{
    if(gym=="true")url+="contest.lists?gym="+gym;
    return make_req(url);
}

string contest_ratingChanges(string id)
{
    url+="contest.ratingChanges?contestId="+id;
    return make_req(url);
}

string contest_standings(string id, string asManager, string from, string count, string handles, string room, string showUnofficial, string participantTypes)
{

    url+="contest.standings?contestId="+id+"&from="+from+"&count="+count+"&showUnofficial=true";
    return make_req(url);
}
*/


void problemset();
void recentActions();
void user();


int main(int argc, char* argv[])
{
    if(argc<2) return -1;
    string command = argv[1];
    if(command=="blogEntry")
    {
        json j = json::parse(blogEntry(argv[2],argv[3]));
        std::cout << j.dump(4) << std::endl;
    }
    /*
    if(command=="contest")
    {
        string sub = argv[2];
        if(sub=="hacks")
        {
            json j = json::parse(contest_hacks(argv[3],argv[4]));
            cout << j.dump(4) << '\n';
        }
        if(sub=="list")
        {
            json j = json::parse(contest_list(argv[3],argv[4]));
            cout << j.dump(4) << '\n';
        }
        if(sub=="ratingChanges")
        {
            json j = json::parse(contest_ratingChanges(argv[2]));
            cout << j.dump(4) << '\n';
        }
        if(sub=="standings")
        {
            json j = json::parse(contest_standings(argv[3],argv[4],argv[5],argv[6],argv[7],argv[8],argv[9], argv[10]));
            cout << j.dump(4) << '\n';
        }
    }
    */
} 
