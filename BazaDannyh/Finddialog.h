#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QtGui>
#include <QtSql>
class QLineEdit;
class QSqlDatabase;
class QSqlQuery;

class FindDialog : public QDialog
{
    Q_OBJECT
public:
    FindDialog(QWidget *parent = 0);
   /* QString getFirstName(){return sfname;}
    QString getLastName(){return slname;}
    void get_marks(int &, int &, int &);
        QString get_Photo(){return photo_path;}*/
    void setComponents(int flag);
    void clear_pole();
    void get_ss(QString &s){s=ss;}


	
public slots:
        void find();

private:
        QLineEdit *Mark, *Stra,*ModName,*Dvig,*Loshad,*Cen,*Cen2;
        QPushButton *Ok,*Cancel;
        QSqlDatabase db;
        QSqlQuery *query;
        QComboBox   *Korob, *Cve,*Kuz;
        bool GetData(QString &,QString &,QString &,double &,int &,QString &,int &,QString &,QString &,int &);


        QString ss;

};


#endif // ADDDIALOG_H
