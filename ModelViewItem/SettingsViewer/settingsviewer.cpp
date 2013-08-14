#include "settingsviewer.h"
#include "ui_settingsviewer.h"

#include <QSettings>

SettingsViewer::SettingsViewer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsViewer),
    m_organization("Trolltech"),
    m_application("Designer")
{
    ui->setupUi(this);

    ui->treeWidget->setColumnCount(2);
    ui->treeWidget->setHeaderLabels(QStringList()<<tr("Key")<<tr("Value"));
}

SettingsViewer::~SettingsViewer()
{
    delete ui;
}

void SettingsViewer::readSettings()
{
    QSettings settings(m_organization, m_application);

    ui->treeWidget->clear();
    addChildSettings(settings, NULL, "");

    ui->treeWidget->sortByColumn(0);
    ui->treeWidget->setFocus();
}

void SettingsViewer::addChildSettings(QSettings &settings, QTreeWidgetItem *parent, const QString &group)
{
    if (parent == NULL)
        parent = ui->treeWidget->invisibleRootItem();

    settings.beginGroup(group);

    QTreeWidgetItem *item = NULL;
    foreach (QString key, settings.childKeys())
    {
        QTreeWidgetItem *item = new QTreeWidgetItem(parent);
        item->setText(0, key);
        item->setText(1, settings.value(key).toString());
    }
    foreach (QString group, settings.childGroups())
    {
        item = new QTreeWidgetItem(parent);
        item->setText(0, group);

        addChildSettings(settings, item, group);
    }
    settings.endGroup();
}
