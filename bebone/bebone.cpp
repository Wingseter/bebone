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

    // 버튼 연결
    connect(ui.refreshButton, SIGNAL(clicked()), this, SLOT(refreshButtonClicked()));
    connect(ui.searchButton, SIGNAL(clicked()), this, SLOT(searchButtonClicked()));
}

void bebone::refresh()
{
    // 전체 User 목록 출력
    model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM Users", db);

    ui.beboneTable->setModel(model);
    ui.beboneTable->show();
}

void bebone::searchButtonClicked()
{
    // 특정 id 사용자 출력
    QSqlQuery query;
    query.prepare("EXEC dbo.user_search :userId");
    query.bindValue(":userId", ui.idInput->text());
    query.exec();
    qDebug() << query.lastError();

    query.next();
    ui.name->setText(query.value(1).toString());
    ui.address->setText(query.value(2).toString());
    ui.email->setText(query.value(3).toString());
    query.finish();
}

void bebone::refreshButtonClicked()
{
    refresh();
}