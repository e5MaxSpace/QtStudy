#ifndef FLOWCHARTSYMBOLPICKER_H
#define FLOWCHARTSYMBOLPICKER_H

#include <QDialog>

namespace Ui {
class FlowChartSymbolPicker;
}

class FlowChartSymbolPicker : public QDialog
{
    Q_OBJECT
    
public:
    explicit FlowChartSymbolPicker(const QMap<int/*id*/, QString/*symbol name*/> &symbols, QWidget *parent = 0);
    ~FlowChartSymbolPicker();

    int selectedId() const;

public slots:
    virtual void done(int r);
    
private:
    Ui::FlowChartSymbolPicker *ui;

    int m_id;
    QIcon iconForSymbol(const QString &symbolName) const;
};

#endif // FLOWCHARTSYMBOLPICKER_H
