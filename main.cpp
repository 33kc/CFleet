#include<iostream>
#include<vector>
#include<string>
using namespace std;

string baseUrl = "https://codeforces.com/api/";

void help()
{
	cout << "Usage: dfslgjndsgsudfhgsidufbgi <section> <subcommands...>\n";
}

void blog(vector<string> parameters)
{
	if (parameters.size() >= 2 && parameters[0] == "comments")
	{
		string blogEntryId = parameters[1];
		string fullUrl = baseUrl + "blogEntry.comments?blogEntryId=" + blogEntryId;
		cout << "Calling: " << fullUrl << endl;
		// do the api call later
	}
	else
	{
		cout << "Usage: someNameThatIwillCOmeUpwithLaterBecauseImOutofCreativityRN blog comments <blogEntryId>\n";
	}
}

void contest(vector<string> parameters)
{
	
}

void problemset(vector<string> parameters)
{
	
}

void recentActions(int count)
{
	
}

void user(vector<string> parameters)
{

}

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		help();
		return 1;
	}

	string section = argv[1];
	vector<string> subparams;
	for (int i = 2; i < argc; i++) subparams.push_back(argv[i]);

	if (section == "user") user(subparams);
	else if (section == "contest") contest(subparams);
	else if (section == "problemset") problemset(subparams);
	else if (section == "blog") blog(subparams);
	else help();

	return 0;
}
