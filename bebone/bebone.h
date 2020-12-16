#pragma once

#include <QtWidgets/QMainWindow>
#include <QtSql/qsqldatabase.h>
#include <QtSql/qsqltablemodel.h>
#include <qdebug.h>
#include "ui_bebone.h"
#include "static.h"

class bebone : public QMainWindow
{
    Q_OBJECT
private:
    QSqlDatabase db;
    QSqlQueryModel* model;
    bool connected;

public:
    bebone(QWidget *parent = Q_NULLPTR);

private:
    Ui::beboneClass ui;
    void refresh();

public slots:
    void refreshButtonClicked();
};
