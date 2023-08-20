
import QtQuick 2.7
import QtQuick.Controls 2.2

Component {
	Rectangle {
		color: "#ffbdbd"

		Column {
			anchors.horizontalCenter: parent.horizontalCenter
			anchors.verticalCenter: parent.verticalCenter

			spacing: 20

			Row {
				spacing: 10
				anchors.horizontalCenter: parent.horizontalCenter
				Text {
					text: qsTr("Settings")
					anchors.verticalCenter: parent.verticalCenter
					font.pointSize: 24;
				}
			}

			Row {
				spacing: 10
				anchors.horizontalCenter: parent.horizontalCenter

				TextField {
					id: sideOfSquare
					text: settings.sideOfSquare
					validator: IntValidator {bottom: 1;}
					placeholderText: qsTr("Side of a square")
				}

				TextField {
					id: flyCapacity
					text: settings.flyCapacity
					validator: IntValidator {bottom: 1;}
					placeholderText: qsTr("Fly capacity")
				}

				TextField {
					id: flyStupidity
					text: settings.flyStupidity
					validator: IntValidator {bottom: 1;}
					placeholderText: qsTr("Fly stupidity")
				}
			}

			Row {
				spacing: 10
				anchors.horizontalCenter: parent.horizontalCenter

				MenuIntButton {
					text: qsTr("Back")
					onClicked: mainStack.pop()
				}

				MenuIntButton {
					text: qsTr("Start Game")
					onClicked: {
						settings.sideOfSquare = sideOfSquare.text;
						settings.flyCapacity = flyCapacity.text;
						settings.flyStupidity = flyStupidity.text;

						mainStack.push(newGame)
					}
				}
			}
		}
	}
}
