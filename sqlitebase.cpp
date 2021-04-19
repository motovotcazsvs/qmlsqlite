#include "sqlitebase.h"

sqlitebase::sqlitebase(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/QtProject/qmlsqlite/MedicalMeasurements.db3");//для windows
    //db.setDatabaseName("C:/QT_PROJECTS/untitled5/Compare.db3");//для малинки
    db.open();


}

sqlitebase::~sqlitebase()
{

}

void sqlitebase::pushRecord()
{
    query.prepare("INSERT INTO TABLEMEDICALMEASUREMENTS(NUMBERPERDAY, PROBENUMBER, DATEYEAR, DATEMONTH, DATEDAY, TIMEHOUR, TIMEMINUTE, GL, LC, BARCODE)"
                  "VALUES(:number_per_day, :probe_number, :date_year, :date_month, :date_day, time_hour, time_minute, gl, lc, bar_code);");
    query.bindValue(":NUMBERPERDAY", "10");
    query.bindValue(":PROBENUMBER", "4");
    query.bindValue(":date_year", "2021");
    query.bindValue(":date_month", "4");
    query.bindValue(":date_day", "19");
    query.bindValue(":time_hour", "17");
    query.bindValue(":time_minute", "9");
    query.bindValue(":gl", "9.91");
    query.bindValue(":lc", "3.88");
    query.bindValue(":bar_code", "444444444");
    if(!query.exec()) qDebug() << "Error inserting filds into table" << query.lastError();
}

void sqlitebase::pullRecord()
{

}

void sqlitebase::removeRecord()
{

}
