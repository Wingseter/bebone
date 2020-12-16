#include "bebone.h"

bebone::bebone(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    // DB ¿¬°á
    QString connectionTemplate = "DRIVER={SQL SERVER};SERVER=%1;DATABASE=%2;";

    QString connectionString = connectionTemplate.arg(server).arg(dbName);
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName(connectionString);
    db.setUserName(id);
    db.setPassword(pw);
    connected = db.open();

    if (connected) {
        refresh();
    }
    connect(ui.refreshButton, SIGNAL(clicked()), this, SLOT(refreshButtonClicked()));

}

void bebone::refresh()
{
    model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM Users", db);

    ui.beboneTable->setModel(model);
    ui.beboneTable->show();
}

void bebone::refreshButtonClicked()
{
    refresh();
}