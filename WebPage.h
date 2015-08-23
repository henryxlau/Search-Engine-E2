#ifndef WEBPAGE_H
#define WEBPAGE_H
#include "Set.h"
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <locale>
using namespace std;

class WebPage {
public:
	WebPage ();
	WebPage (string filename);
	~WebPage ();
	Set<string> allWords () const;
	int pageID;
	WebPage & operator=(const WebPage & other);
	bool operator<(const WebPage & other) const;
	bool operator==(const WebPage & other);
	friend ostream & operator<< (ostream & os, const WebPage & page);
	const Set<string> * allOutgoingLinks () const;
	const Set<string> * allIncomingLinks () const;
	string filename () const;
	void parse (string total, string temp);
	void addIncomingLink (string start);
	void addOutgoingLink (string target);
	double getPageRank() const;
	void setPageRank(double val);


	string getTotalWebPage() const;
private:
	double pageRank;
	string totalWebPage;
	string fileName;
	Set<string> words;
	Set<string> outgoingLink;
	Set<string> incomingLink;
	// you get to decide what goes here.
};

      /* Adds a link from the current page to the target
         in the current page's storage. */

#endif //WEBPAGE_H
