#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "citymodel.h"t"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList cities;
    cities << "Arvika" << "Boden" << "Eskilstuna" << "Falun"
           << "Filipstad" << "Halmstad" << "Helsingborg" << "Karlstad"
           << "Kiruna" << "Kramfors" << "Motala" << "Sandviken"
           << "Skara" << "Stockholm" << "Sundsvall" << "Trelleborg";

    CityModel *model = new CityModel(this);
    model->setCities(cities);

    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}
