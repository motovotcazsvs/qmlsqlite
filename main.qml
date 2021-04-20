import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Row {
        spacing: 50

        Button {
            text: "push"
            onClicked: database.pushRecord();
        }
        Button {
            text: "pull"
            onClicked: database.pullRecord();
        }
        Button {
            text: "delete"
            onClicked: database.removeRecord(1);
        }
    }


}
