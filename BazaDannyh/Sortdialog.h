#ifndef SORTDIALOG_H
#define SORTDIALOG_H

#include <QtGui>
#include <QtSql>
class QLineEdit;
class QSqlDatabase;
class QSqlQuery;

class SortDialog : public QDialog
{
    Q_OBJECT
public:
    SortDialog(QWidget *parent = 0);
   /* QString getFirstName(){return sfname;}
    QString getLastName(){return slname;}
    void get_marks(int &, int &, int &);
        QString get_Photo(){return photo_path;}*/
    void get_stolbec(int &s){s=Stolbik;return;}
    void clear_pole();


	
public slots:
        void sorting();

private:
        QLineEdit *Stolbec;
        QPushButton *Ok,*Cancel;
        QSqlDatabase db;
        QSqlQuery *query;
        bool GetData(QString &);


        int Stolbik;

};


#endif // ADDDIALOG_H
