#ifndef TEAMLEADERS_H
#define TEAMLEADERS_H

#include <QDialog>

namespace Ui {
class TeamLeaders;
}

class TeamLeaders : public QDialog
{
    Q_OBJECT
    
public:
    explicit TeamLeaders(const QStringList &leaders, QWidget *parent = 0);
    ~TeamLeaders();

    QStringList leaders() const;

private slots:
    void on_insertButton_clicked();
    void on_deleteButton_clicked();
    
private:
    Ui::TeamLeaders *ui;
};

#endif // TEAMLEADERS_H
