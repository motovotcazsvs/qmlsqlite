#ifndef SQLITEBASE_H
#define SQLITEBASE_H

#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QFile>
#include <QSqlError>


class sqlitebase : public QObject
{
    Q_OBJECT
public:
    explicit sqlitebase(QObject *parent = 0);

signals:

public slots:
    void pushRecord();
    void pullRecord();
    void removeRecord();
private:
    QSqlDatabase db;
    QSqlQuery query;
};

#endif // SQLITEBASE_H
