#include "webpage.h"
#include <sstream>
#include "set.h"
#include <cctype>


WebPage::WebPage () {
	fileGiven = false;
}

WebPage::WebPage (std::string filename) {
	std::ifstream file;
	name = filename;
	file.open(filename);
	if (file.fail()) {
		throw(std::runtime_error(std::string("Failed to open file.")));
	} else {
		fileGiven = true;
	}
	while(!file.fail()) {
		std::string buffer = "";
		file >> buffer;
		if(!file.fail()) {
			data += (buffer + " ");
		}
	}
	for(unsigned int i = 0; i < data.length(); i++) {
		data[i] = tolower(data[i]);
	}
	file.close();

	std::stringstream ss;
	ss.str(data);
	while(!ss.fail()) {
		std::string word = "";
		ss >> word;
		unsigned int start, end = 0;
		for(unsigned int i = 0; i < word.length(); i++) {		
			if(word[i] == '[') {
				start = i+1;
			}
			if(word[i] == ']') {
				end = i;
			}
		}
		if(!(start == 0 && end == 0) && start < word.length() && end < word.length()) {
			string otherFileName = word.substr(start, end - start);
			addOutgoingLink(otherFileName);
		}
	}
}

WebPage::~WebPage () {

}

std::string WebPage::filename() const {
	return name;
}

Set<string> WebPage::allOutgoingLinks() const {
	return outgoingLinks;
}

Set<string> WebPage::allIncomingLinks() const {
	return incomingLinks;
}

void WebPage::addIncomingLink(string start) {
	incomingLinks.insert(incomingLinks.end(),start);
}

void WebPage::addOutgoingLink(string target) {
	outgoingLinks.insert(outgoingLinks.end(),target);
}

std::string WebPage::getData() const {
	return data;
}

void WebPage::updateOtherSites() {
	set<string>::iterator outgoingLinksIterator = outgoingLinks.begin();
	while(outgoingLinksIterator != outgoingLinks.end()) {

	}
}

Set<std::string> WebPage::allWords () const {
	std::stringstream ss;
	ss.str(data);
	Set<std::string>* words = new Set<std::string>();
	while(!ss.fail()) {
		std::string word = "";
		ss >> word;
		bool insideWord = false;
		bool skipForBracket = false;
		Set<std::string> innerWords = Set<std::string>();
		int startIndex = 0;
		int endIndex = 0;
		for(unsigned int j = 0; j < word.length(); j++) {
			if(word[j] == '[') {
				skipForBracket = true;
			}
			if(word[j] == ']') {
				skipForBracket = false;
			}

			//Check to see if the char at line[j] is within the ASCII bounds of upper/lower case alphabet letters
			if(isalnum(word[j]) && !skipForBracket) {
				if(insideWord == false) {
					startIndex = j;
				}
				insideWord = true;		//If yes, then it is inside a word
			} else {
				if(insideWord == true) {  //else the word has ended
					insideWord = false;
					endIndex = j;
					int length = endIndex - startIndex;
					innerWords.insert(innerWords.end(),word.substr(startIndex,length));
				}
			}
		}
		if(insideWord) {
			endIndex = word.length();
		}
		int length = endIndex - startIndex;
		if(length > 0) {
			innerWords.insert(innerWords.end(),word.substr(startIndex,length));
		}
		set<std::string>::iterator innerWordsIter = innerWords.begin();
		for(unsigned int i = 0; i < innerWords.size(); i++) {
			if(innerWordsIter != innerWords.end()) {
				std::string addition = *innerWordsIter;
				innerWordsIter++;
				if (!words->contains(addition)) {
					words->insert(words->end(),addition);
				}
			}
		}
	}	
	return *words;
}

std::ostream & operator<< (std::ostream & os, const WebPage & page) {
	os << page.filename() << std::endl;	
	os << page.getData();
	return os;
}