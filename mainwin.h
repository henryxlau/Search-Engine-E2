#ifndef MAINWIN_H
#define MAINWIN_H

#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <QGridLayout>
#include <QListWidget>
#include <QGroupBox>
#include <QRadioButton>
#include <string>
#include <sstream>
#include <stdexcept>
#include <set>
#include <list>
#include <deque>
#include "Set.h"
#include "WebPage.h"
#include "pagewin.h"

// helper function
void SplitString(const std::string &, std::set<std::string> &);

class MainWin : public QMainWindow
{
	Q_OBJECT

	public:
		MainWin(QWidget *parent = 0);
		~MainWin();

	private slots:
		void readInWebsites();
		void doLookupWord();
		void populateResults(std::vector<WebPage *> *results);
		void showAbout();
		void quitButton();
		void generatePageWindow(const WebPage * site);
		int getIDfromName(std::string filename);
		void calcPageRanks(vector<WebPage*> *pageList);
		void clear();
		void usingAlpha(bool alpha);
		void usingPagerank(bool rank);
		
		void lookupPageListItem(QListWidgetItem * item);

	private:

		QPushButton    * btnSearch;
		QPushButton    * btnAbout;
		QPushButton    * btnQuit;
		QRadioButton   * alphaButton;
		QRadioButton   * pagerankButton;
		QGroupBox      * radioGroup;
		QVBoxLayout    * radioButtons;
		QLineEdit      * txtWordsInput;
		QGridLayout    * winLayout;
		QListWidget    * outputList;
		QWidget        * centerWidget;

		map<string, Set<WebPage *> > myMap;
		Set<string> wordSet;
		Set<string> page;
		vector<WebPage *> WebPageList;
		Set<WebPage *> tempSet;
		Set<WebPage *> tempSet2;
		vector<WebPage *> results;
		string input;
		bool useAlpha;
		std::locale loc;
		string lowerTemp = "";
		string temp;
};

#endif
