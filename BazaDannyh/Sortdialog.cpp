#include "Sortdialog.h"

SortDialog::SortDialog(QWidget *parent):
        QDialog(parent)
{

    QLabel *Stolbeclbl = new QLabel("Enter nomer stolbca");
    Stolbec = new QLineEdit;

    Ok = new QPushButton("Ok");
    Cancel = new QPushButton("Cancel");

    db=QSqlDatabase::database("mydb");
    query=new QSqlQuery(db);

   connect(Cancel,SIGNAL(clicked()),this,SLOT(reject()));
   // connect(addBtn,SIGNAL(clicked()),this,SLOT(add()));

        QGridLayout *layout = new QGridLayout;
    layout->addWidget(Stolbeclbl,0,0);
    layout->addWidget(Stolbec,0,1);


    QHBoxLayout *buttonLayout2=new QHBoxLayout;
    buttonLayout2->addWidget(Ok);
    buttonLayout2->addWidget(Cancel);

        QVBoxLayout *vbox=new QVBoxLayout;
        vbox->addLayout(layout);
        vbox->addLayout(buttonLayout2);

       connect(Ok,SIGNAL(clicked()),this,SLOT(sorting()));


    setLayout(vbox);
    setWindowTitle("Sorting");
}


bool SortDialog::GetData(QString &Stolb){
    //Stolbec
    Stolb=Stolbec->text();
    if (Stolb.isEmpty()){
        QMessageBox::warning(this,"Error","Stolbec can't be empty");
        return false;
    }
return true;
}

void SortDialog::sorting(){
   QString stb;
    bool res=GetData(stb);
    if (!res) {QMessageBox::information(this,"Error","Kukaracha"); return;}
    Stolbik=stb.toInt();
   accept();


}
void SortDialog::clear_pole(){
    Stolbec->clear();

}
