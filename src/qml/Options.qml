
import QtQuick 2.7
import QtQuick.Controls 2.2

Component {
	Rectangle {
		color: "#ffbdbd"

		Column {
			anchors.horizontalCenter: parent.horizontalCenter
			anchors.verticalCenter: parent.verticalCenter

			spacing: 10

			Row {
				spacing: 10
				anchors.horizontalCenter: parent.horizontalCenter

				Text {
					text: qsTr("Your name")
					anchors.verticalCenter: parent.verticalCenter
				}

				TextField {
					id: username
					text: settings.username
					placeholderText: qsTr("Enter your name")
				}
			}

			Row {
				spacing: 20
				anchors.horizontalCenter: parent.horizontalCenter

				MenuIntButton {
					text: qsTr("Save")
					onClicked: {
						settings.username = username.text;
						mainStack.pop();
					}
				}
				MenuIntButton {
					text: qsTr("Back")
					onClicked: mainStack.pop()
				}
			}
		}
	}
}

