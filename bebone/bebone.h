#pragma once

#include <QtWidgets/QMainWindow>
#include <QtSql/qsqldatabase.h>
#include <QtSql/qsqltablemodel.h>
#include <QtSql/qsqlquery.h>
#include <qdebug.h>
#include <QtSql/qsqlerror.h>
#include "ui_bebone.h"
#include "static.h"

class bebone : public QMainWindow
{
    Q_OBJECT
private:
    QSqlDatabase db;
    bool connected;

public:
    QSqlQueryModel* model;
    bebone(QWidget *parent = Q_NULLPTR);

private:
    Ui::beboneClass ui;
    void refresh();

public slots:
    void searchButtonClicked();
    void refreshButtonClicked();
};
