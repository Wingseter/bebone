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
    // ������ ���̽� ����
    QSqlDatabase db;
    // ���� �Ϸ� ���� ����
    bool connected;
    // �޽��� �ڽ�
    QMessageBox msgBox;

public:
    // ���̺� ��ƾ��
    QSqlQueryModel* model;
    // ������
    bebone(QWidget *parent = Q_NULLPTR);

private:
    // ui ���� ���� ����
    Ui::beboneClass ui;
    // ���̺� ���ΰ�ħ
    void refresh();

public slots:
    // �˻� ��ư Ŭ���� ȣ��
    void searchButtonClicked();
    // ���ΰ�ħ ��ư Ŭ���� ȣ��
    void refreshButtonClicked();
    // ��� �Է� ��ư Ŭ���� ȣ��
    void inputButtonClicked();
};
