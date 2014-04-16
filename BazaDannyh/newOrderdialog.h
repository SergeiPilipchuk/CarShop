#ifndef NEWORDERDIALOG_H
#define NEWORDERDIALOG_H

#include <QtGui>
#include <QtSql>
class QLineEdit;
class QSqlDatabase;
class QSqlQuery;

class NewOrderDialog : public QDialog
{
    Q_OBJECT
public:
    NewOrderDialog(QWidget *parent = 0);
   /* QString getFirstName(){return sfname;}
    QString getLastName(){return slname;}
    void get_marks(int &, int &, int &);
        QString get_Photo(){return photo_path;}*/
    void setComponents(int flag);
    void clear_pole();


	
public slots:
        void insert();

private:
        QLineEdit *Fio, *Tel,*KlienID,*OrdID,*OrdDate,*OrdCarID;
        QPushButton *Ok,*Cancel;
        QSqlDatabase db;
        QSqlQuery *query;
        bool GetData(QString &,int &,int &,int &,QString &,int &);



};


#endif // ADDDIALOG_H
