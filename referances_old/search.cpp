#include <iostream>
#include <fstream>
#include "set.h"
#include <map>
#include <deque>
#include "webpage.h"
#include <sstream>
#include <QApplication>
#include "mainwindow.h"

void showSites(Set<WebPage*> sites);

int main(int argc, char* argv[]) {

	QApplication app(argc, argv);
	MainWindow *window = new MainWindow();

	window->setWindowTitle("Search Engine");
	window->show();


 	
	// if(argc != 2) {
	// 	std::cerr << "Usage: ./search datasource" << std::endl;
	// 	return 1;
	// }

	deque<WebPage*> pages = deque<WebPage*>();

	char* fileSource = "data/sites.txt";//argv[1];
	std::ifstream fileRead(fileSource);

	while(!fileRead.fail()) {
		std::string webPageName;
		getline(fileRead, webPageName);
		if(!fileRead.fail()) {
			WebPage* addition = new WebPage(webPageName);
			try {
				pages.push_back(addition);
			}
			catch (const std::exception & e) {

			}
		}
	}

	map<std::string, Set<WebPage*>*> index = map<std::string, Set<WebPage*>*>();
	int numSites = pages.size();

	for(int i = 0; i < numSites; i++) {
		string sender = pages[i]->filename();
		set<string> senderOutgoing = pages[i]->allOutgoingLinks();
		set<string>::iterator iter = senderOutgoing.begin();
		while(iter != senderOutgoing.end()) {
			string targetName = *iter;
			for(int j = 0; j < numSites; j++) {
				if (pages[j]->filename() == "data/" + targetName) {
					try {
						pages[j]->addIncomingLink(sender);
					}
					catch(const std::exception & e) {
						std::cerr << "could not add incoming link" << std::endl;
					}
				}
			}
			++iter;
		}
	}


	for(int i = 0; i < numSites; i++) {
		Set<std::string> siteWords = Set<std::string> (pages[i]->allWords());
		set<std::string>::iterator siteWordsIter = siteWords.begin();
		int numWords = siteWords.size();
		for(int i = 0; i < numWords; i++) {
			std::string theWord = *siteWordsIter++;
			Set<WebPage*>* matching = new Set<WebPage*>();
			for (int k =0; k < numSites; k++) {
				Set<std::string> otherSitesWords = pages[k]->allWords();
				if (otherSitesWords.contains(theWord)) {
					matching->insert(matching->end(),pages[k]);
				}
			}
			try {
				index.insert(index.end(), std::pair<std::string, Set<WebPage*>*>(theWord, matching));
			}
			catch (const std::exception &e) {
			}
		}
	}

	bool quitRequested = false;
	while (!quitRequested) {
		std::cerr << "Enter your search query below..." << std::endl;

		std::string input;

		getline(std::cin, input); //Take input
// //		std::cin.ignore('\n');
		if(input.length() > 0) { //Make sure it isn't empty
			if(input[0] == '.') {
				quitRequested = true;
				std::cerr << "\nQuitting the program.\n\n";
			} else {
				for(int i = 0; i < input.length(); i++) {
					input[i] = tolower(input[i]);
				}
				std::stringstream ss;
				ss.str(input);
				std::string option;
				ss >> option;
				std::string action;
				std::cerr << option << std::endl;
				std::getline(ss >> std::ws, action);
				if(option == "and" || option == "or") {
					if(action[0] != '(' && action.length() != 0) {
						std::cerr << "Bad input given" << std::endl;
					} else {
						deque<std::string> words = deque<std::string>();
						bool insideWord = false;
						Set<std::string> innerWords = Set<std::string>();
						int startIndex = 0;
						int endIndex = 0;
						for(unsigned int i = 0; i < action.length(); i++) {

							//Check to see if the char at line[i] is within the ASCII bounds of upper/lower case alphabet letters
							if((action[i] >= 48 && action[i] <= 57) || (action[i] >= 65 && action[i] <= 90) || (action[i] >= 97 && action[i] <= 122)) {
								if(insideWord == false) {
									startIndex = i;
								}
								insideWord = true;		//If yes, then it is inside a word
							} else {
								if(insideWord == true) {  //else the word has ended
									insideWord = false;
									endIndex = i;
									int length = endIndex - startIndex;
									innerWords.insert(innerWords.end(), action.substr(startIndex,length));
									if(action[i] == ')') {
										break;
									}
								}
							}
						}
						endIndex = action.length();
						int length = endIndex - startIndex;
						if(insideWord == true) {
							innerWords.insert(innerWords.end(), action.substr(startIndex,length));
						}

						set<std::string>::iterator innerWordsIter = innerWords.begin();
						if(option == "and") {
							Set<WebPage*> matches = Set<WebPage*>();
							matches = *index.at(*innerWordsIter++);
							for(unsigned int i = 0; i < innerWords.size() - 1; i++) {
								try {
									matches = matches.setIntersection(*index.at(*innerWordsIter++));
								}
								catch (const std::exception &e) {
								}
							}
							showSites(matches);
						} else if(option == "or") {
							std::cerr << "Entering OR logic" << std::endl;
							Set<WebPage*> matches = Set<WebPage*>();
							for(unsigned int i = 0; i < innerWords.size(); i++) {
								try {
									matches = matches.setUnion(*index.at(*innerWordsIter++));
								}
								catch (const std::exception &e) {

								}
							}
							showSites(matches);
						}
					}
				} else {
					try {
						Set<WebPage*> sites = *index.at(input);
						showSites(sites);
					}
					catch(const std::out_of_range &e) {
						std::cerr << "No results found" << std::endl;
					}	
				}
			}
		}
	}
	return app.exec();
}

void showSites(Set<WebPage*> sites) {
	set<WebPage*>::iterator sitesIter = sites.begin();
	int size = sites.size();
	std::cerr << size << " sites found." << std::endl;
	if (size == 0) {
		std::cerr << "No results found" << std::endl;
		return;
	}
	int place = 0;
	while(place < size) {
		std::cerr << "Showing Result:" << std::endl;
		WebPage displayMe = **sitesIter++;
		std::cerr << displayMe << std::endl;
		std::cerr << "\n\nFor next, type 'next'; to quit results page, type 'quit'" << std::endl;
		std::string input;
		std::cin >> input;
		if(input == "quit" || place >= size) {
			std::cerr << "Leaving..." << std::endl;
			std::cin.ignore(1);
			return;
		}
		if(input == "next") {
			place++;
		}
	}
	std::cerr << "End of results." << std::endl;
	std::cin.ignore(1);
}