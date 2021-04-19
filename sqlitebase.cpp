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
    query.bindValue(":imageData1", inByteArray1);
    query.bindValue(":imageData2", inByteArray2);
    //query.bindValue(":hesh", "0");
    query.bindValue(":precent", "19");
    if(!query.exec()) qDebug() << "Error inserting filds into table" << query.lastError();
}

void sqlitebase::pullRecord()
{

}

void sqlitebase::removeRecord()
{

}
