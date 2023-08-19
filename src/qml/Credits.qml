import QtQuick 2.7

Component {
	Rectangle {
		color: "#ffdfba"

		Column {
			anchors.horizontalCenter: parent.horizontalCenter
			anchors.verticalCenter: parent.verticalCenter

			MenuIntButton {
				text: qsTr("Back")
				onClicked: mainStack.pop()
			}
		}
	}
}
