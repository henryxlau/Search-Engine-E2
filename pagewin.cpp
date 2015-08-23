#include "pagewin.h"
#include <iostream>

PageWin::PageWin(QWidget *parent)  : QMainWindow(parent) {

	outermostLayout = new QHBoxLayout;
	linksLayout = new QVBoxLayout;
	siteDisplay    = new QTextEdit;
	incomingLinksList = new QListWidget;
	outgoingLinksList = new QListWidget;
	incomingLabel = new QLabel;
	outcomingLabel = new QLabel;

	incomingLabel->setText("Incoming Links:");
	outcomingLabel->setText("Outcoming Links:");

	centerWidget  = new QWidget(this);
	centerWidget->setLayout(outermostLayout);
	this->setCentralWidget(centerWidget);

	outermostLayout->addWidget(siteDisplay);
	outermostLayout->addLayout(linksLayout);
	linksLayout->addWidget(incomingLabel);
	linksLayout->addWidget(incomingLinksList);
	linksLayout->addWidget(outcomingLabel);
	linksLayout->addWidget(outgoingLinksList);

	mainWindow = parent;
	source = NULL;

	connect(incomingLinksList, SIGNAL(itemDoubleClicked(QListWidgetItem *)), this->parent(), SLOT(lookupPageListItem(QListWidgetItem *)));
	connect(outgoingLinksList, SIGNAL(itemDoubleClicked(QListWidgetItem *)), this->parent(), SLOT(lookupPageListItem(QListWidgetItem *)));

}

PageWin::~PageWin()
{
	delete outermostLayout;
	delete linksLayout;
	delete siteDisplay;
	delete incomingLinksList;
	delete outgoingLinksList;
	delete incomingLabel;
	delete outcomingLabel;
	delete centerWidget;
}

void PageWin::setSource(const WebPage *newSource) {
	this->source = newSource;
	updateComponents();
}


void PageWin::updateComponents() {
	if(source == NULL) {
		return;
	}

	siteDisplay->setText(QString::fromStdString(source->getTotalWebPage()));

	for (Set<std::string>::iterator incomingIter = source->allIncomingLinks()->begin(); incomingIter != source->allIncomingLinks()->end(); ++incomingIter)
	{
		//std::cerr << "add" << std::endl;
		QListWidgetItem *result = new QListWidgetItem(incomingLinksList);
		result->setText(QString::fromStdString(*incomingIter));

	}

	for (Set<std::string>::iterator outgoingIter = source->allOutgoingLinks()->begin(); outgoingIter != source->allOutgoingLinks()->end(); ++outgoingIter)
	{
		//std::cerr << "add" << std::endl;
		QListWidgetItem *result = new QListWidgetItem(outgoingLinksList);
		result->setText(QString::fromStdString(*outgoingIter));

	}
}
