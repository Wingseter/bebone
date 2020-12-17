#pragma once

#include <QtWidgets/QMainWindow>
#include <QtSql/qsqldatabase.h>
#include <QtSql/qsqltablemodel.h>
#include <QtSql/qsqlquery.h>
#include <QtSql/qsqlerror.h>
#include <qmessagebox.h>
#include <qdebug.h>
#include "ui_bebone.h"
#include "static.h"

class bebone : public QMainWindow
{
    Q_OBJECT
private:
    // 데이터 베이스 변수
    QSqlDatabase db;
    // 연결 완료 저장 변수
    bool connected;
    // 메시지 박스
    QMessageBox msgBox;

public:
    // 테이블 포틴터
    QSqlQueryModel* model;
    // 생성자
    bebone(QWidget *parent = Q_NULLPTR);

private:
    // ui 정보 저장 변수
    Ui::beboneClass ui;
    // 테이블 새로고침
    void refresh();

public slots:
    // 검색 버튼 클릭시 호출
    void searchButtonClicked();
    // 새로고침 버튼 클릭시 호출
    void refreshButtonClicked();
    // 명부 입력 버튼 클릭시 호출
    void inputButtonClicked();
};
