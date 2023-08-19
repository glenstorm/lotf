
import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Window 2.2

Window {
	id: mainWindow
	visible: true

	Rectangle {
		id: mainArea
		anchors.fill: parent

		StackView {
			id: mainStack
			initialItem: mainMenu
			anchors.fill: parent
		}

		MainMenu {
			id: mainMenu
		}
	}

	Component.onCompleted: {
		mainWindow.showFullScreen();
	}

	Shortcut {
		sequence: StandardKey.Quit
		context: Qt.ApplicationShortcut
		onActivated: Qt.quit()
	}
}
