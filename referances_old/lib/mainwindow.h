#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <iostream>
#include <fstream>
#include "set.h"
#include <map>
#include <deque>
#include "webpage.h"
#include <sstream>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMainWindow>
#include <QWidget>
#include <QLineEdit>

class MainWindow : public QMainWindow {
public:
	MainWindow();

public slots:
	


private:
	QVBoxLayout *mainLayout;
	QHBoxLayout *dataLoadLayout;
	QPushButton *loadDataButton;
	QLineEdit *dataSourceInput;


private slots:
	void doSearch();
	void loadData();



protected:


signals:



};

#endif