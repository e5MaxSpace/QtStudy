#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "currencymodel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMap<QString, double> currencyMap;
    currencyMap.insert("AUD", 1.3259);
    currencyMap.insert("CHF", 1.2970);
    currencyMap.insert("CZK", 24.510);
    currencyMap.insert("DKK", 6.2168);
    currencyMap.insert("EUR", 0.8333);
    currencyMap.insert("GBP", 0.5661);
    currencyMap.insert("HKD", 7.7562);
    currencyMap.insert("JPY", 112.92);
    currencyMap.insert("NOK", 6.5200);
    currencyMap.insert("NZD", 1.4697);
    currencyMap.insert("SEK", 7.8180);
    currencyMap.insert("SGD", 1.6901);
    currencyMap.insert("USD", 1.0000);

    CurrencyModel *model = new CurrencyModel(this);
    model->setCurrencyMap(currencyMap);

    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}
