#include <iostream>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>


using namespace std;
using json= nlohmann::json;


string url="https://codeforces.com/api/";

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"
#define MAGENTA "\033[35m"
#define BLUE    "\033[34m"

void help()
{
std::cout << BOLD << YELLOW << "🔹 contest.list\n" << RESET;
std::cout << "    - Returns the list of contests.\n";
std::cout << "    - Parameters:\n";
std::cout << "        - " << GREEN << "gym" << RESET << " (optional): true/false to include gym contests.\n\n";
std::cout << BOLD << YELLOW << "🔹 contest.standings\n" << RESET;
std::cout << "    - Returns the standings of a contest.\n";
std::cout << "    - Parameters:\n";
std::cout << "        - " << GREEN << "contestId" << RESET << " (required): ID of the contest.\n";
std::cout << "        - " << GREEN << "from" << RESET << " (optional): Starting rank.\n";
std::cout << "        - " << GREEN << "count" << RESET << " (optional): Number of participants to return.\n";
std::cout << "        - " << GREEN << "handles" << RESET << " (optional): Semicolon-separated list of handles.\n";
std::cout << "        - " << GREEN << "room" << RESET << " (optional): Room number.\n";
std::cout << "        - " << GREEN << "showUnofficial" << RESET << " (optional): true/false to include unofficial participants.\n\n";
std::cout << BOLD << YELLOW << "🔹 contest.status\n" << RESET;
std::cout << "    - Returns submissions for a contest.\n";
std::cout << "    - Parameters:\n";
std::cout << "        - " << GREEN << "contestId" << RESET << " (required): ID of the contest.\n";
std::cout << "        - " << GREEN << "handle" << RESET << " (optional): User handle.\n";
std::cout << "        - " << GREEN << "from" << RESET << " (optional): Starting submission index.\n";
std::cout << "        - " << GREEN << "count" << RESET << " (optional): Number of submissions to return.\n\n";

std::cout << BOLD << YELLOW << "🔹 contest.ratingChanges\n" << RESET;
std::cout << "    - Returns rating changes after a contest.\n";
std::cout << "    - Parameters:\n";
std::cout << "        - " << GREEN << "contestId" << RESET << " (required): ID of the contest.\n\n";

// Problem Methods
std::cout << BOLD << YELLOW << "🔹 problemset.problems\n" << RESET;
std::cout << "    - Returns all problems.\n";
std::cout << "    - Parameters:\n";
std::cout << "        - " << GREEN << "tags" << RESET << " (optional): Semicolon-separated list of tags.\n\n";
    std::cout << BOLD << YELLOW << "🔹 problemset.recentStatus\n" << RESET;
std::cout << "    - Returns recent submissions.\n";
std::cout << "    - Parameters:\n";
std::cout << "        - " << GREEN << "count" << RESET << " (required): Number of submissions to return (max 10000).\n";
std::cout << "        - " << GREEN << "from" << RESET << " (optional): Starting submission index.\n\n";

// User Methods
std::cout << BOLD << YELLOW << "🔹 user.info\n" << RESET;
std::cout << "    - Returns information about one or several users.\n";
std::cout << "    - Parameters:\n";
std::cout << "        - " << GREEN << "handles" << RESET << " (required): Semicolon-separated list of handles.\n\n";

std::cout << BOLD << YELLOW << "🔹 user.rating\n" << RESET;
std::cout << "    - Returns rating history of a user.\n";
std::cout << "    - Parameters:\n";
std::cout << "        - " << GREEN << "handle" << RESET << " (required): User handle.\n\n";

std::cout << BOLD << YELLOW << "🔹 user.status\n" << RESET;
std::cout << "    - Returns submissions of a user.\n";
std::cout << "    - Parameters:\n";
std::cout << "        - " << GREEN << "handle" << RESET << " (required): User handle.\n";
std::cout << "        - " << GREEN << "from" << RESET << " (optional): Starting submission index.\n";
std::cout << "        - " << GREEN << "count" << RESET << " (optional): Number of submissions to return.\n\n";

std::cout << BOLD << YELLOW << "🔹 user.blogEntries\n" << RESET;
std::cout << "    - Returns blog entries of a user.\n";
std::cout << "    - Parameters:\n";
std::cout << "        - " << GREEN << "handle" << RESET << " (required): User handle.\n\n";

// Blog Methods
std::cout << BOLD << YELLOW << "🔹 blogEntry.view\n" << RESET;
std::cout << "    - Returns a blog entry.\n";
std::cout << "    - Parameters:\n";
std::cout << "        - " << GREEN << "blogEntryId" << RESET << " (required): ID of the blog entry.\n\n";

std::cout << BOLD << YELLOW << "🔹 blogEntry.comments\n" << RESET;
std::cout << "    - Returns comments on a blog entry.\n";
std::cout << "    - Parameters:\n";
std::cout << "        - " << GREEN << "blogEntryId" << RESET << " (required): ID of the blog entry.\n\n";

// Recent Actions
std::cout << BOLD << YELLOW << "🔹 recentActions\n" << RESET;
std::cout << "    - Returns recent actions.\n";
std::cout << "    - Parameters:\n";
std::cout << "        - " << GREEN << "maxCount" << RESET << " (required): Number of recent actions to return (max 100).\n\n";
}


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
    if(argc<2) 
    {
        help();
        return -1;
    }
    string command = argv[1];
    if (command == "help") help();
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
