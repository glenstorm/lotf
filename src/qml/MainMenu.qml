
import Qt.labs.settings 1.0
import QtQuick 2.7
import QtQuick.Controls 2.2

Component {
	Rectangle {
		color: "#bae1ff"

		Column {
			anchors.horizontalCenter: parent.horizontalCenter
			anchors.verticalCenter: parent.verticalCenter

			spacing: 10

			MenuButton {
				text: qsTr("New Game")
				onClicked: mainStack.push(newGame)
			}

			MenuButton {
				text: qsTr("Credits")
				onClicked: mainStack.push(credits)
			}

			MenuButton {
				text: qsTr("Quit to OS")
				onClicked: Qt.quit()
			}
		}

		NewGame {
			id: newGame
		}

		Credits {
			id: credits
		}

		Settings {
			id: settings

			property string sideOfSquare: "100"
			property string flyCapacity: "0"
			property string flyStupidity: "300"
		}
	}
}
