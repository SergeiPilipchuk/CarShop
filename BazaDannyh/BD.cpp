#include <QtGui>
#include <QtSql>
#include <QWidget>
#include "MainWindow.h"
bool CreateConnection(){
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC","mydb");//статический метод вызова
    db.setHostName("BOSS");
    db.setDatabaseName("SQLServer2");
    db.setUserName("db_user");
    db.setPassword("");
    if(!db.open())
    {
        QMessageBox box;
        box.setText(db.lastError().text());
        box.exec();
        db.close();
        return false;
    }
    QMessageBox box;
    box.setText("Connection is open");
    box.exec();
    return true;
}

int main(int argc,char **argv){
    QApplication app(argc,argv);
    bool result=CreateConnection();
        if(!result)
            return -1;

    MainWindow Window;
    Window.show();

/*
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC","mydb");
    db.setDatabaseName("SQLServer");
    if (!db.open()){
        QMessageBox box;
        box.setText("Error:Can't connect to database");
        box.exec();
        return -1;}*/

    return app.exec();
}

