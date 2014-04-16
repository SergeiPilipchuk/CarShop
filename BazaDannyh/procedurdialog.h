#ifndef PROCEDURDIALOG_H
#define PROCEDURDIALOG_H

#include <QtGui>
#include <QMainWindow>
#include <QtSql>
class QLineEdit;
class QSqlDatabase;
class QSqlQuery;
class ProcedurDialog : public QDialog
{
    Q_OBJECT
public:
    ProcedurDialog(QWidget *parent = 0);
    void get_Date(QString &D){ D=sd;}
    void clear_pole(){Data->clear();}
private:
    QLineEdit *Data;
    QPushButton *Ok, *Cancel;
    QString sd;
public slots:
    void set_parametr();
};


#endif // ADDDIALOG_H
