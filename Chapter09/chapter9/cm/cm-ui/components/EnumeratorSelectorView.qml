import QtQuick 2.9
import QtQuick.Controls 2.2
import CM 1.0
import assets 1.0

Item {
    id: stringSelectorView
    property DropDown dropDown
    property EnumeratorDecorator enumeratorDecorator
    property int selectedValue

    ScrollView {
        id: scrollView
        visible: true
        anchors.fill: parent
        anchors {
            top: parent.bottom
             left: parent.left
             right: parent.right
             bottom: parent.top
             margins: Style.sizeScreenMargin
        }

        Flow {
            flow: Grid.TopToBottom
            spacing: Style.sizeControlSpacing
            height: scrollView.height

            Repeater {
                id: repeaterAnswers
                model: dropDown.ui_values
                delegate:
                    Rectangle {
                        property bool isSelected: modelData.ui_key.ui_value === enumeratorDecorator.ui_value
                        width: Style.widthDataControls
                        height: Style.heightDataControls
                        radius: Style.sizeDataControlsRadius
                        color: isSelected ? Style.colourDataControlsBackgroundSelected : Style.colourDataSelectorBackground

                        Text {
                            anchors {
                                fill: parent
                                margins: Style.heightDataControls / 4
                            }
                            text: modelData.ui_description
                            color: Style.colourDataSelectorFont
                            font.pixelSize: Style.pixelSizeDataControls
                            verticalAlignment: Qt.AlignVCenter
                        }

                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                selectedValue = modelData.ui_key;
                                contentFrame.pop();
                            }
                        }
                    }
            }
        }
    }

    Binding {
        target: enumeratorDecorator
        property: "ui_value"
        value: selectedValue
    }
}
