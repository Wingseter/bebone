#include "bebone.h"

bebone::bebone(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    // DB 연결
    QString connectionTemplate = "DRIVER={SQL SERVER};SERVER=%1;DATABASE=%2;";

    QString connectionString = connectionTemplate.arg(server).arg(dbName);
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName(connectionString);
    db.setUserName(id);
    db.setPassword(pw);
    connected = db.open();

    // 연결 성공
    if (connected) {
        refresh();
    }
    connect(ui.refreshButton, SIGNAL(clicked()), this, SLOT(refreshButtonClicked()));
    connect(ui.beboneTable, SIGNAL(clicked(const QModelIndex &)), this, SLOT(beboneTableClicked(const QModelIndex &)));
}

void bebone::refresh()
{
    model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM Users", db);

    ui.beboneTable->setModel(model);
    ui.beboneTable->show();
}

void bebone::beboneTableClicked(const QModelIndex& index)
{
    if (index.isValid()) {
        QString cellText = index.data().toString();
        ui.name->setText(cellText);
    }
}

void bebone::refreshButtonClicked()
{
    refresh();
}