#include "listmodel.h"
#include "sqlitebase.h"

ListModel::ListModel(QObject *parent) :
    QSqlQueryModel(parent)
{
    this->updateModel();
}

// Метод для получения данных из модели
QVariant ListModel::data(const QModelIndex & index, int role) const
{

    // Определяем номер колонки, адрес так сказать, по номеру роли
    int columnId = role - Qt::UserRole - 1;
    // Создаём индекс с помощью новоиспечённого ID колонки
    QModelIndex modelIndex = this->index(index.row(), columnId);

    /* И с помощью уже метода data() базового класса
     * вытаскиваем данные для таблицы из модели
     * */
    return QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
}

// Метод для получения имен ролей через хешированную таблицу.
QHash<int, QByteArray> ListModel::roleNames() const
{
    /* То есть сохраняем в хеш-таблицу названия ролей
     * по их номеру
     * */
    QHash<int, QByteArray> roles;
    roles[IdRole] = "id";
    roles[number_per_day_Role] = "number_per_day";
    roles[probe_number_Role] = "probe_number";
    roles[date_year_Role] = "date_year";
    roles[date_month_Role] = "date_month";
    roles[date_day_Role] = "date_day";
    roles[time_hour_Role] = "time_hour";
    roles[time_minute_Role] = "time_minute";
    roles[gl_Role] = "gl_Role";
    roles[lc_Role] = "lc_Role";
    roles[bar_code_Role] = "bar_code";

    return roles;
}

// Метод обновления таблицы в модели представления данных
void ListModel::updateModel()
{
    // Обновление производится SQL-запросом к базе данных
    this->setQuery("SELECT ID, NUMBERPERDAY, PROBENUMBER, DATEYEAR, DATEMONTH, DATEDAY, TIMEHOUR, TIMEMINUTE, GL, LC, BARCODE FROM TABLEMEDICALMEASUREMENTS");
}

// Получение id из строки в модели представления данных
int ListModel::getId(int row)
{
    return this->data(this->index(row, 0), IdRole).toInt();
}
