#include "WebPage.h"
#include "Set.h"
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <locale>

WebPage::WebPage ()	{}// constructor that creates an empty page

WebPage::WebPage (string filename, int id)
{
	ifstream inFile;
	string temp;
	string total = "";

	inFile.open(filename.c_str());
	while (!inFile.eof())
	{
		getline(inFile, temp);
		total += temp + "\n";
	}

	parse(total, temp);

	fileName = filename;
	pageRank = 0;
	pageID = id;
}
      /* constructor that initializes the page from the given file.
         Should throw an exception if the file does not exist
         or has other problems. */

WebPage::~WebPage () {}
// destructor

double WebPage::getPageRank() const {
	return pageRank;
}

void WebPage::setPageRank(double val) {
	pageRank = val;
}

std::string WebPage::getTotalWebPage() const {
	return totalWebPage;
}

Set<string> WebPage::allWords () const
{
	return words;
}
      /* Returns a set containing all individual words on the web page. */

WebPage & WebPage::operator=(const WebPage & other)
{
	if (this != &other)
	{
		words = other.words;
		this->totalWebPage = other.totalWebPage;
	}
	return *this;
}

bool WebPage::operator<(const WebPage & other) const
{
	return this->fileName < other.fileName;
}

bool WebPage::operator==(const WebPage & other)
{
	if(this->totalWebPage == other.totalWebPage)
		return true;
	return false;
}

ostream & operator<< (ostream & os, const WebPage & page)
{
	os << page.totalWebPage;

	return os;
}
      /* Declares an operator we can use to print the web page. */

const Set<string> * WebPage::allOutgoingLinks () const
{
	return &outgoingLink;
}
      /* Returns "pointers" to all webpages that this page has links to. 
         As discussed above, this could be as a set or via an iterator,
         and it could be as actual pointers, or as strings, 
         or possibly other. */   

const Set<string> * WebPage::allIncomingLinks () const
{
	return &incomingLink;
}
      /* Returns "pointers" to all webpages that link to this page. 
         Same consideration as previous function. */   

string WebPage::filename () const
{
	return fileName;
}
      /* Returns the filename from which this page was read. */

    /* Based on which overall architecture you choose, you may 
       also need/want some or all of the following functions. */

void WebPage::parse (string total, string temp)
{
	string linkName = "";
	string linkFile = "";
	int start = 0;
	int end = 0;
	
	for (unsigned int j = 0; j < 2; j++)
	{
		for (unsigned int i = 0; i < total.length(); i++)
		{
			if (total[i] == '[')
			{
				start = i;
				i++;
				while (total[i] != ']')
				{
					linkName += total[i];
					i++; 
				}
				i++;
				if (total[i] == '(')
				{
					i++;
					while (total[i] != ')')
					{
						linkFile += total[i];
						i++;
					}
					i++;
					end = i;
					total.erase(total.begin()+start, total.begin()+end);
					addOutgoingLink(linkFile);
					linkName = "";
					linkFile = "";
				}
			}
		}
	}
	
	totalWebPage = total;

	replace(total.begin(), total.end(), '!', ' ');
	replace(total.begin(), total.end(), '\\', ' ');
	replace(total.begin(), total.end(), '#', ' ');
	replace(total.begin(), total.end(), '$', ' ');
	replace(total.begin(), total.end(), '%', ' ');
	replace(total.begin(), total.end(), '&', ' ');
	replace(total.begin(), total.end(), '\'', ' ');
	replace(total.begin(), total.end(), '(', ' ');
	replace(total.begin(), total.end(), ')', ' ');
	replace(total.begin(), total.end(), '*', ' ');
	replace(total.begin(), total.end(), '+', ' ');
	replace(total.begin(), total.end(), ',', ' ');
	replace(total.begin(), total.end(), '-', ' ');
	replace(total.begin(), total.end(), '.', ' ');
	replace(total.begin(), total.end(), '/', ' ');
	replace(total.begin(), total.end(), ':', ' ');
	replace(total.begin(), total.end(), ';', ' ');
	replace(total.begin(), total.end(), '<', ' ');
	replace(total.begin(), total.end(), '>', ' ');
	replace(total.begin(), total.end(), '=', ' ');
	replace(total.begin(), total.end(), '?', ' ');
	replace(total.begin(), total.end(), '@', ' ');
	replace(total.begin(), total.end(), '[', ' ');
	replace(total.begin(), total.end(), ']', ' ');
	replace(total.begin(), total.end(), '\"', ' ');
	replace(total.begin(), total.end(), '/', ' ');
	replace(total.begin(), total.end(), '^', ' ');
	replace(total.begin(), total.end(), '_', ' ');
	replace(total.begin(), total.end(), '\'', ' ');
	replace(total.begin(), total.end(), '{', ' ');
	replace(total.begin(), total.end(), '}', ' ');
	replace(total.begin(), total.end(), '|', ' ');
	replace(total.begin(), total.end(), '~', ' ');

	stringstream buffer(total);
	while (buffer >> temp)
	{
		locale loc;
		string lowerTemp;
		for(unsigned int j = 0; j < temp.length(); j++)
		{
			lowerTemp = lowerTemp + tolower(temp[j], loc);
		}
		words.insert(lowerTemp);
	}
}
      /* actually parses the content of the filename that was passed 
         to the constructor into the object. */

void WebPage::addIncomingLink (string start)
{
	incomingLink.insert(incomingLink.end(),start);
}
      /* Adds a link from start to the current page 
         in the current page's storage. */

void WebPage::addOutgoingLink (string target)
{
	outgoingLink.insert(outgoingLink.end(),target);
}
