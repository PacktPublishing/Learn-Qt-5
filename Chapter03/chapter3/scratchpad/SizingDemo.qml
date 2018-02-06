import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 1024
    height: 768
    title: qsTr("Scratchpad")
    color: "#ffffff"
    Column {
        id: columnWithText
        Text {
            id: text1
            text: "Text 1"
        }
        Text {
            id: text2
            text: "Text 2"
            width: 300
            height: 20
        }
        Text {
            id: text3
            text: "Text 3 Text 3 Text 3 Text 3 Text 3 Text 3 Text 3 Text 3 Text 3 Text 3 Text 3 Text 3 Text 3 Text 3 Text 3 Text 3 Text 3 Text 3 Text 3 Text 3 Text 3 Text 3 Text 3 Text 3 Text 3 Text 3 Text 3 Text 3 Text 3 Text 3 Text 3 Text 3 Text 3 Text 3 Text 3 Text 3 Text 3"
        }
        Text {
            id: text4
            text: "Text 4 Text 4 Text 4 Text 4 Text 4 Text 4 Text 4 Text 4 Text 4 Text 4 Text 4 Text 4 Text 4 Text 4 Text 4 Text 4 Text 4 Text 4 Text 4 Text 4 Text 4 Text 4 Text 4 Text 4 Text 4 Text 4 Text 4 Text 4 Text 4 Text 4 Text 4 Text 4 Text 4 Text 4 Text 4 Text 4 Text 4"
            width: 300
        }
        Text {
            id: text5
            text: "Text 5 Text 5 Text 5 Text 5 Text 5 Text 5 Text 5 Text 5 Text 5 Text 5 Text 5 Text 5 Text 5 Text 5 Text 5 Text 5 Text 5 Text 5 Text 5 Text 5 Text 5 Text 5 Text 5 Text 5 Text 5 Text 5 Text 5 Text 5 Text 5 Text 5 Text 5 Text 5 Text 5 Text 5 Text 5 Text 5 Text 5"
            width: 300
            wrapMode: Text.Wrap
        }
    }
    Column {
        id: columnWithRectangle
        Rectangle {
            id: rectangle
            anchors.fill: parent
        }
    }
    Component.onCompleted: {
        console.log("Text1 - implicitWidth:" + text1.implicitWidth + " implicitHeight:" + text1.implicitHeight + " width:" + text1.width + " height:" + text1.height)
        console.log("Text2 - implicitWidth:" + text2.implicitWidth + " implicitHeight:" + text2.implicitHeight + " width:" + text2.width + " height:" + text2.height)
        console.log("Text3 - implicitWidth:" + text3.implicitWidth + " implicitHeight:" + text3.implicitHeight + " width:" + text3.width + " height:" + text3.height)
        console.log("Text4 - implicitWidth:" + text4.implicitWidth + " implicitHeight:" + text4.implicitHeight + " width:" + text4.width + " height:" + text4.height)
        console.log("Text5 - implicitWidth:" + text5.implicitWidth + " implicitHeight:" + text5.implicitHeight + " width:" + text5.width + " height:" + text5.height)
        console.log("ColumnWithText - implicitWidth:" + columnWithText.implicitWidth + " implicitHeight:" + columnWithText.implicitHeight + " width:" + columnWithText.width + " height:" + columnWithText.height)
        console.log("Rectangle - implicitWidth:" + rectangle.implicitWidth + " implicitHeight:" + rectangle.implicitHeight + " width:" + rectangle.width + " height:" + rectangle.height)
        console.log("ColumnWithRectangle - implicitWidth:" + columnWithRectangle.implicitWidth + " implicitHeight:" + columnWithRectangle.implicitHeight + " width:" + columnWithRectangle.width + " height:" + columnWithRectangle.height)
    }
}
