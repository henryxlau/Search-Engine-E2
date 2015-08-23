#include <iostream>
#include <string>
#include <fstream>
#include "Set.h"
#include <map>
#include "WebPage.h"
using namespace std;

//Global Variables
Set<string> data;

void DFS(string filename)
{
	data.insert(filename);
	WebPage * seedPage = new WebPage(filename);
	Set<string> outLinks = *(seedPage->allOutgoingLinks());

	for (Set<string>::iterator it = outLinks.begin(); it != outLinks.end(); ++it)
	{
		bool contains = (data.find(*it) != data.end());
		if (contains == 0)
		{
			DFS(*it);
		}
	}
}

int main(int argc, char *argv[])
{
	DFS(argv[1]);

	ofstream outFile(argv[2]);

	for (Set<string>::iterator d = data.begin(); d != data.end(); ++d)
	{
		outFile << (*d) << endl;
	}
}