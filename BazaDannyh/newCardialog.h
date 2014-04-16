#ifndef NEWCARDIALOG_H
#define NEWCARDIALOG_H

#include <QtGui>
#include <QtSql>
class QLineEdit;
class QSqlDatabase;
class QSqlQuery;

class NewCarDialog : public QDialog
{
    Q_OBJECT
public:
    NewCarDialog(QWidget *parent = 0);
   /* QString getFirstName(){return sfname;}
    QString getLastName(){return slname;}
    void get_marks(int &, int &, int &);
        QString get_Photo(){return photo_path;}*/
    void setComponents(int flag);
    void clear_pole();


	
public slots:
        void insert();

private:
        QLineEdit *Mark, *Stra,*ModName,*Dvig,*Loshad,*Cen;
        QPushButton *Ok,*Cancel;
        QSqlDatabase db;
        QSqlQuery *query;
        QComboBox   *Korob, *Cve,*Kuz;
        bool GetData(QString &,QString &,QString &,double &,int &,QString &,int &,QString &,QString &);


        QString SProductName, SCategory,SSupplier;
        int IQuantityPerUnit;
};


#endif // ADDDIALOG_H
