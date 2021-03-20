import QtQuick 2.6
import QtQuick.Controls 2.0
import "factorial.js" as MyScript

ApplicationWindow {
    id: rootwin
    width: 300
    height: 480
    visible: true
    title: "Main"

    function startupFunction() {
           console.log("Hello, World!");
        }

    Component.onCompleted: startupFunction();

Row {
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.verticalCenter: parent.verticalCenter

    Slider {
        id: slider
        from: 1
        value: 2
        to: 10
    }

    Label {
        id: label
        text: MyScript.factorial(slider.value)
    }

  }

}
