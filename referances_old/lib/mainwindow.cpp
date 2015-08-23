#include "mainwindow.h"

using namespace std;

MainWindow::MainWindow() {
	QVBoxLayout *mainLayout = new QVBoxLayout();
	QHBoxLayout *dataLoadLayout = new QHBoxLayout();
	QPushButton *loadDataButton = new QPushButton();
	QLineEdit *dataSourceInput = new QLineEdit();
	dataLoadLayout->addWidget(dataSourceInput);
	dataLoadLayout->addWidget(loadDataButton);
	mainLayout->addLayout(dataLoadLayout);
	this->setLayout(mainLayout);
	this->show();
}