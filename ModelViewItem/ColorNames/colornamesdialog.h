#ifndef COLORNAMESDIALOG_H
#define COLORNAMESDIALOG_H

#include <QDialog>

namespace Ui {
class ColorNamesDialog;
}

class QStringListModel;
class QSortFilterProxyModel;
class ColorNamesDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ColorNamesDialog(QWidget *parent = 0);
    ~ColorNamesDialog();
    
private slots:
    void on_filterLineEdit_textChanged(const QString &text);
    void on_syntaxComboBox_currentIndexChanged(int index);

private:
    Ui::ColorNamesDialog *ui;

    QStringListModel *m_sourceModel;
    QSortFilterProxyModel *m_proxyModel;

    void reapplyFilter();
};

#endif // COLORNAMESDIALOG_H
