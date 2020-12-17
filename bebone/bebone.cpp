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
    connect(ui.submitButton, SIGNAL(clicked()), this, SLOT(inputButtonClicked()));
}

void bebone::refresh()
{
    // 전체 User 목록 불러오기
    model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM Visitors", db);

    // 전체 User 출력
    ui.beboneTable->setModel(model);
    ui.beboneTable->show();
}

void bebone::searchButtonClicked()
{
    // 특정 사용자 검색
    QSqlQuery query;
    if (ui.byId->isChecked()) {
        query.prepare("EXEC dbo.find_visitor_id :userId");
        query.bindValue(":userId", ui.idInput->text());
        query.exec();
    }
    else if (ui.byName->isChecked()) {
        query.prepare("EXEC dbo.find_visitor_by_name :name");
        query.bindValue(":name", ui.idInput->text());
        query.exec();
    }

    query.next();
    ui.name->setText(query.value(1).toString());
    ui.address->setText(query.value(2).toString());
    ui.phone->setText(query.value(3).toString());

    query.finish();
}

void bebone::refreshButtonClicked()
{
    refresh();
}

void bebone::inputButtonClicked()
{
    QString name = ui.nameInput->text() ;
    QString location = ui.addInput->text();
    QString phone = ui.phoneInput->text();


    // 입력 가능 검사
    if (!QString::compare(name, "", Qt::CaseInsensitive)) {
        msgBox.setText("InputName.");
        msgBox.exec();
        return;
    }
    if (!QString::compare(location, "", Qt::CaseInsensitive)) {
        msgBox.setText("Input Location.");
        msgBox.exec();
        return;
    }
    if (!QString::compare(phone, "", Qt::CaseInsensitive)) {
        msgBox.setText("Input PhoneNumber.");
        msgBox.exec();
        return;
    }

    // 새로운 유저 입력
    QSqlQuery query;
    query.prepare("EXEC dbo.input_new_user :Name,:Location,:Phone");
    query.bindValue(":Name", name);
    query.bindValue(":Location", location);
    query.bindValue(":Phone", phone);
    query.exec();

    refresh();
}
