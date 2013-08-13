#include "gotocelldialog.h"

#include <QtGui>

GoToCellDialog::GoToCellDialog(QWidget *parent)
    : QDialog(parent)
{
    this->setupUi(this); //第1个this指Ui::GoToCellDialog，第2个this指(QDialog) 即 Ui::GoToCellDialog->setupUi(QDialog)

    QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
    lineEdit->setValidator(new QRegExpValidator(regExp, this));

    connect(okButton, SIGNAL(clicked()), SLOT(accept()));
    connect(cancelButton, SIGNAL(clicked()), SLOT(reject()));
}

void GoToCellDialog::on_lineEdit_textChanged()
{
    // bool	hasAcceptableInput () const
    // This property holds whether the input satisfies the inputMask and the validator.
    // By default, this property is true.
    okButton->setEnabled(lineEdit->hasAcceptableInput());
}
