import QtQuick 2.7
import QtQuick.Controls 2.2

Item {
	Flickable {
		id: mapflickable
		width: mainWindow.width
		height: mainWindow.height
		boundsBehavior: Flickable.OvershootBounds
	}
}
