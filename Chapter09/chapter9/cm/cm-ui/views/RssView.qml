import QtQuick 2.9
import assets 1.0
import components 1.0

Item {
    Rectangle {
        anchors.fill: parent
        color: Style.colourBackground
    }

    ListView {
        id: itemsView
        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
            bottom: commandBar.top
            margins: Style.sizeHeaderMargin
        }
        clip: true
        model: masterController.ui_rssChannel ? masterController.ui_rssChannel.ui_items : 0
        delegate: RssItemDelegate {
            rssItem: modelData
        }
    }

    CommandBar {
        id: commandBar
        commandList: masterController.ui_commandController.ui_rssViewContextCommands
    }
}
