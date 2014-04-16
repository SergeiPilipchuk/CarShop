#include "procedurdialog.h"
//#include "constants.h"

ProcedurDialog::ProcedurDialog(QWidget *parent):
        QDialog(parent)
{
    QLabel *Datalbl = new QLabel("Enter Data");
    Data = new QLineEdit;

    Ok = new QPushButton("Ok");
    Cancel = new QPushButton("Cancel");

    connect(Cancel,SIGNAL(clicked()),this,SLOT(reject()));
    connect(Ok,SIGNAL(clicked()),this,SLOT(set_parametr()));


        QHBoxLayout*Layout=new QHBoxLayout;
        Layout->addWidget(Datalbl);
        Layout->addWidget(Data);

        QHBoxLayout*ButtonLayout=new QHBoxLayout;
        ButtonLayout->addWidget(Ok);
        ButtonLayout->addWidget(Cancel);

	QVBoxLayout *vbox=new QVBoxLayout;
        vbox->addLayout(Layout);
        vbox->addLayout(ButtonLayout);

    setLayout(vbox);
    setWindowTitle("Parametr");
}
void ProcedurDialog::set_parametr(){
sd=Data->text();
accept();}


