import QtQuick 2.7
import QtQuick.Controls 2.2

Rectangle {
	id: button

	//width: buttonText.width + paddingHorizontal * 2
	//height: buttonText.height + paddingVertical * 2

	property int paddingHorizontal: 10
	property int paddingVertical: 5
	property bool active: true
	property bool isPressed: false

	property alias pressedColor: pressedRect.color

	property alias text: buttonText.text
	property string activeTextColor: "black"
	property string inactiveTextColor: "gray"

	property alias tooltip: tt.text

	signal clicked

	Text {
		id: buttonText
		anchors.centerIn: parent
		font.pixelSize: 18
		color: active? activeTextColor : inactiveTextColor
	}

	ToolTip {
		id: tt
		visible: false
	}

	Rectangle {
		id: pressedRect
		anchors.fill: parent
		color: "gray"
		visible: isPressed
		z: 10
		opacity: 0.5
		radius: parent.radius
	}

	Rectangle {
		anchors.fill: parent
		color: "white"
		visible: !active
		z: 10
		opacity: 0.5
		radius: parent.radius
	}

	MouseArea {
		id: mouseArea
		anchors.fill: parent
		hoverEnabled: true

		onClicked: if (button.active) button.clicked()

		onPressed: {
			if (button.active) isPressed = true
		}
		onReleased: {
			if (button.active) isPressed = false
		}

		onEntered: {
			if (active) cursorShape = Qt.PointingHandCursor;
			if (tooltip) tt.visible = true;
		}
		onExited: {
			if (active) cursorShape = Qt.ArrowCursor;
			if (tooltip) tt.visible = false;
		}
	}
}
