#ifndef PAGEWIN_H
#define PAGEWIN_H

#include <QWidget>
#include <QTextEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <QGridLayout>
#include <QListWidget>
#include <string>
#include <sstream>
#include <stdexcept>
#include <set>
#include <list>
#include <deque>
#include "Set.h"
#include "WebPage.h"
#include <QLabel>


class PageWin : public QMainWindow {
	Q_OBJECT

	public:
		PageWin(QWidget *parent = 0);
		~PageWin();

		void setSource(const WebPage *newSource);

	private slots:
		void updateComponents();

	private:

		QHBoxLayout *outermostLayout;
		QVBoxLayout *linksLayout;
		QTextEdit   *siteDisplay;
		QListWidget *incomingLinksList;
		QListWidget *outgoingLinksList;
		QWidget     *centerWidget;
		QLabel      *incomingLabel;
		QLabel      *outcomingLabel;

		const WebPage * source; 

		QWidget *mainWindow;

};



#endif
