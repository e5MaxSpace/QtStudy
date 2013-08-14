#ifndef SETTINGSVIEWER_H
#define SETTINGSVIEWER_H

#include <QDialog>

namespace Ui {
class SettingsViewer;
}

class QSettings;
class QTreeWidgetItem;
class SettingsViewer : public QDialog
{
    Q_OBJECT
    
public:
    explicit SettingsViewer(QWidget *parent = 0);
    ~SettingsViewer();
    
private:
    Ui::SettingsViewer *ui;

    QString m_organization;
    QString m_application;

    void readSettings();
    void addChildSettings(QSettings &settings, QTreeWidgetItem *parent, const QString &group);
};

#endif // SETTINGSVIEWER_H
