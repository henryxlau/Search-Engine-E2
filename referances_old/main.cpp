#include "Set.h"
#include "WebPage.h"
#include <stdexcept>
#include <sstream>

int main(int argc, char * argv[])
{
	map<string, Set<WebPage> > myMap;
	Set<string> wordSet;
	Set<string> page;
	Set<WebPage> WebPageList;
	Set<WebPage> tempSet;
	Set<WebPage> tempSet2;
	string input;
	locale loc;
	string lowerTemp = "";
	string temp;

	ifstream inFile(argv[1]);
	string file;
	if (inFile.good())
	{
		while (!inFile.eof())
		{
			inFile >> file;
			WebPage webpage(file);
			WebPageList.insert(webpage);
		}
	}
	else
	{
		cout << "ERROR - File did not open" << endl;
		return 0;
	}

	for (Set<WebPage>::iterator p = WebPageList.begin(); p != WebPageList.end(); ++p)
	{
		page = p->allWords();

		for (Set<string>::iterator setVal = page.begin(); setVal != page.end(); ++setVal)
		{
			try
			{
				myMap.insert(pair<string, Set<WebPage> >(*setVal, Set<WebPage>()));
			}
			catch (logic_error & )
			{
				//Do nothing
				//cout << "Key already exist" << endl;
			}
			myMap[*setVal].insert(*p); 
		}
	}

	cout << "Welcome to my Search engine!" << endl
		 << "(Type \".\" to end program)" << endl
		 << "==============================================================" << endl;

	do { 
		cout << "Search: ";
		input = "";
		cin >> input;
		
		if (input == "AND")
		{
			wordSet.~Set();
			tempSet.~Set();
			tempSet2.~Set();
			getline(cin, input);
			replace(input.begin(), input.end(), '(', ' ');
			replace(input.begin(), input.end(), ')', ' ');
			replace(input.begin(), input.end(), ',', ' ');
			
			stringstream ss1(input);
			while (ss1 >> temp)
			{
				locale loc;
				string lowerTemp1;
				for(unsigned int j = 0; j < temp.length(); j++)
				{
					lowerTemp1 = lowerTemp1 + tolower(temp[j], loc);
				}
				wordSet.insert(lowerTemp1);
			}
			
			try
			{
				for (Set<string>::iterator setVal2 =  wordSet.begin(); setVal2 != wordSet.end(); ++setVal2)
				{
					tempSet = myMap[*setVal2];
					++setVal2;
					if (setVal2 != wordSet.end())
					{
						tempSet2 = myMap[*setVal2];
						tempSet = tempSet.setIntersection(tempSet2);
					}
				}
			}
			catch (logic_error & )
			{
				//Do nothing
				//cout << e.what() << endl;
			}

			try 
			{
				if (input != ".")
				{
					if (!tempSet.empty())
					{
						cout << "Here are the WebPage(s) for your search:" << endl;
						tempSet.printSet();
					}
					else
						cout << "Sorry, no WebPage(s) found for your search." << endl;
				}
			}
			catch (logic_error & e)
			{
				if (input != ".")
					cout << e.what() << endl;
			}

		}
		else if (input == "OR")
		{
			wordSet.~Set();
			tempSet.~Set();
			tempSet2.~Set();
			getline(cin, input);
			replace(input.begin(), input.end(), '(', ' ');
			replace(input.begin(), input.end(), ')', ' ');
			replace(input.begin(), input.end(), ',', ' ');
			
			stringstream ss2(input);
			while (ss2 >> temp)
			{
				locale loc;
				string lowerTemp2;
				for(unsigned int j = 0; j < temp.length(); j++)
				{
					lowerTemp2 = lowerTemp2 + tolower(temp[j], loc);
				}
				wordSet.insert(lowerTemp2);
			}

			try {
				for (Set<string>::iterator setVal2 =  wordSet.begin(); setVal2 != wordSet.end(); ++setVal2)
				{
					tempSet = myMap[*setVal2];
					++setVal2;
					if (setVal2 != wordSet.end())
					{
						tempSet2 = myMap[*setVal2];
						tempSet = tempSet.setUnion(tempSet2);
					}
				}
			}
			catch (logic_error & )
			{
				//Do nothing
				//cout << e.what() << endl;
			}

			try 
			{
				if (input != ".")
				{
					if (!tempSet.empty())
					{
						cout << "Here are the WebPage(s) for your search:" << endl;
						tempSet.printSet();
					}
					else
						cout << "Sorry, no WebPage(s) found for your search." << endl;
				}
			}
			catch (logic_error & e)
			{
				if (input != ".")
					cout << e.what() << endl;
			}

		}
		else
		{
			for(unsigned int j = 0; j < input.length(); j++)
			{
				lowerTemp = lowerTemp + tolower(input[j], loc);
			}

			input = lowerTemp;
			lowerTemp = "";

			try 
			{
				if (input != ".")
				{
					cout << "Here are the WebPage(s) for your search:" << endl;
					myMap[input].printSet();
				}
			}
			catch (logic_error & )
			{
				if (input != ".")
					cout << "Sorry, No Webpage(s) found for your search." << endl;
					//cout << e.what() << endl;
			}
		}

		if (input == ".")
			cout << "Program ends! Good-bye!" << endl;

	} while (input != ".");

	//myMap.~Map();
	//wordSet.~Set();
	//page.~Set();
	//WebPageList.~Set();
	//tempSet.~Set();
	//tempSet2.~Set();

	return 0;
}