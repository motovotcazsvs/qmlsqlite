#ifndef SQLITEBASE_H
#define SQLITEBASE_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>


class sqlitebase : public QObject
{
    Q_OBJECT
public:
    explicit sqlitebase(QObject *parent = 0);

signals:

public slots:
    void pushRecord();
    void inserIntoTable();
    void pullRecord();
    void removeRecord(const int);
private:
    QSqlDatabase db;

};

#endif // SQLITEBASE_H
