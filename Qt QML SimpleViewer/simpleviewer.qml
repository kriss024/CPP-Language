import QtQuick 2.0
import QtQuick.Window 2.2

Window {
    id: mainWindow
    visible: true
    width: 320
    height: 480

    Rectangle {
    width: parent.width
    height: parent.height
    gradient:
    Gradient {
    GradientStop { position: 0.0; color: "slategray" }
    GradientStop { position: 1.0; color: "lightsteelblue" }
    }

    Text {
        id: helloText
        anchors.centerIn: parent
        text: "Hello World!"
        font.bold: true
        PropertyAnimation on font.pointSize {
            from: 1
            to: 24
            duration: 2000
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            console.log("I was \"" + parent + "\"!")
            console.log("Bye for now!")
            Qt.quit();
            }
        }
    }
}