import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Row {
        id: row
        spacing: 50

        Button {
            text: "push"
            onClicked: {
                database.pushRecord();
                myModel.updateModel(); // И обновляем модель данных с новой записью
            }
        }
        Button {
            text: "pull"
            onClicked: {
                database.pullRecord();
                myModel.updateModel(); // И обновляем модель данных с новой записью
            }
        }
        Button {
            text: "delete"
            onClicked: {
                //database.removeRecord(myModel.getId(/*tableView.currentRow*/2));
                database.removeRecord(2);
                myModel.updateModel();  // Обновляем модель данных
            }
        }
    }

    TableView {
        id: tableView
        anchors.top: row.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 5

        TableViewColumn {
            role: "id"
            title: "ID"
        }
        TableViewColumn {
            role: "number_per_day"
            title: "№ за день"
        }
        TableViewColumn {
            role: "probe_number"
            title: "№ пробника"
        }
        TableViewColumn {
            role: "date_year"
            title: "год"
        }
        TableViewColumn {
            role: "date_month"
            title: "месяц"
        }
        TableViewColumn {
            role: "date_day"
            title: "день"
        }
        TableViewColumn {
            role: "time_hour"
            title: "часы"
        }
        TableViewColumn {
            role: "time_minute"
            title: "минуты"
        }
        TableViewColumn {
            role: "gl_Role"
            title: "глюкоза"
        }
        TableViewColumn {
            role: "lc_Role"
            title: "лактата"
        }
        TableViewColumn {
            role: "bar_code"
            title: "штрих-код"
        }


        model: myModel
    }
}
