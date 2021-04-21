#include "sqlitebase.h"

sqlitebase::sqlitebase(QObject *parent) : QObject(parent)
{

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/QtProject/qmlsqlite/MedicalMeasurements1.db3");//для windows
    //db.setDatabaseName("C:/QT_PROJECTS/untitled5/Compare.db3");//для малинки
    //db.open();
}


void sqlitebase::pushRecord()
{

    db.open();
    QSqlQuery query;
/*//работает
    query.prepare("INSERT INTO TABLEMEDICALMEASUREMENTS(ID, NUMBERPERDAY, PROBENUMBER, DATEYEAR, DATEMONTH, DATEDAY, TIMEHOUR, TIMEMINUTE, GL, LC, BARCODE)"
                    "VALUES(9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1)");
    query.exec();
    */
/*//не работает
    query.prepare("INSERT INTO TABLEMEDICALMEASUREMENTS(ID, NUMBERPERDAY, PROBENUMBER, DATEYEAR, DATEMONTH, DATEDAY, TIMEHOUR, TIMEMINUTE, GL, LC, BARCODE)"
                    "VALUES(:id, :number_per_day, :probe_number, :date_year, :date_month, :date_day, time_hour, time_minute, gl, lc, bar_code);");

    const QVariant ds1(51);
    const QVariant ds2(51);
    const QVariant ds3(51);
    const QVariant ds4(51);
    const QVariant ds5(51);
    const QVariant ds6(51);
    const QVariant ds7(51);
    const QVariant ds8(51);
    const QVariant ds9(51);
    const QVariant ds10(51);
    const QVariant ds11(51);
    query.bindValue(":id", ds1);
    query.bindValue(":number_per_day", ds2);
    query.bindValue(":probe_number", ds3);
    query.bindValue(":date_year", ds4);
    query.bindValue(":date_month", ds5);
    query.bindValue(":date_day", ds6);
    query.bindValue(":time_hour", ds7);
    query.bindValue(":time_minute",ds8);
    query.bindValue(":gl", ds9);
    query.bindValue(":lc", ds10);
    query.bindValue(":bar_code", ds11);
    query.exec();
*/

    //работает
    QSqlQuery Qr;
    QString SQL=QString("INSERT INTO TABLEMEDICALMEASUREMENTS VALUES (%1,'%2','%3',%4,%5,%6,'%7','%8','%9','%10','%11');")
    .arg(1).arg(51).arg(51).arg(51).arg(51).arg(51).arg(51).arg(51).arg(51).arg(51).arg(51);
    Qr.exec(SQL);
    db.close();
}


void sqlitebase::pullRecord()
{
    db.open();
    QSqlQuery query;
    //QString id, number_per_day, probe_number, date_year, date_month, date_day, time_hour, time_minute, gl, lc, bar_code;
    query.exec("SELECT ID, NUMBERPERDAY, PROBENUMBER, DATEYEAR, DATEMONTH, DATEDAY, TIMEHOUR, TIMEMINUTE, GL, LC, BARCODE FROM TABLEMEDICALMEASUREMENTS");
    while(query.next()){
        QString id = query.value(0).toString();
        QString number_per_day = query.value(1).toString();
        QString probe_number = query.value(2).toString();
        QString date_year = query.value(3).toString();
        QString date_month = query.value(4).toString();
        QString date_day = query.value(5).toString();
        QString time_hour = query.value(6).toString();
        QString time_minute = query.value(7).toString();
        QString gl = query.value(8).toString();
        QString lc = query.value(9).toString();
        QString bar_code = query.value(10).toString();
        qDebug() << id << " " << number_per_day << " " << probe_number << " " << date_year << " " << date_month << " "
                 << date_day << " " << time_hour << " " << time_minute << " " << gl << " " << lc << " " << bar_code;
    }

    db.close();
}

void sqlitebase::removeRecord(const int id)
{
    // Удаление строки из базы данных будет производитсья с помощью SQL-запроса
    QSqlQuery query;
    db.open();
    // Удаление производим по id записи, который передается в качестве аргумента функции
    query.prepare("DELETE FROM " "TABLEMEDICALMEASUREMENTS" " WHERE id= :ID ;");
    query.bindValue(":ID", id);

    // Выполняем удаление
    query.exec();
    db.close();
}
