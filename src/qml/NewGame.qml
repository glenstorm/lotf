import QtQuick 2.7
import QtQuick.Controls 2.2

Component {
	Item {
	Rectangle {
		id: drawGridId
		width: parent.width - 200
		height: parent.height

		Canvas {
			id: drawingCanvas
			anchors.left: parent.left
        	property int wgrid: 10
			width: settings.sideOfSquare*wgrid
			height: settings.sideOfSquare*wgrid

			onPaint: {
				var ctx = getContext("2d")
				ctx.lineWidth = 2
				ctx.strokeStyle = "blue"
				ctx.beginPath()
				ctx.moveTo(0, 0);
				ctx.lineTo(0, height);
				ctx.moveTo(0, height);
				ctx.lineTo(width, height);
				ctx.moveTo(width, height);
				ctx.lineTo(width, 0);
				ctx.moveTo(width, 0);
				ctx.lineTo(0, 0);
				ctx.closePath()
				ctx.stroke()


				ctx.lineWidth = 0.1
				ctx.strokeStyle = "grey"
				ctx.beginPath()
				var nrows = height/wgrid;
				for(var i = 0; i < nrows+1; i++) {
					ctx.moveTo(0, wgrid*i);
					ctx.lineTo(width, wgrid*i);
				}

				var ncols = width/wgrid
				for (var j=0; j < ncols+1; j++) {
					ctx.moveTo(wgrid*j, 0);
					ctx.lineTo(wgrid*j, height);
				}
				ctx.closePath()
				ctx.stroke()
			}
		}
	}

	Rectangle {
		id: sideSetsId
		anchors.left: drawGridId.right
		anchors.leftMargin: 5

		Row {
			spacing: 10
			anchors.fill: parent

			Column {
				TextField {
					id: sideOfSquare
					text: settings.sideOfSquare
					validator: IntValidator {bottom: 1;}
					placeholderText: qsTr("Side of a square")
				}

				TextField {
					id: flyStupidity
					text: settings.flyStupidity
					validator: IntValidator {bottom: 1;}
					placeholderText: qsTr("Fly stupidity")
				}

				MenuIntButton {
					text: qsTr("Start")
					onClicked: {
						settings.sideOfSquare = sideOfSquare.text;
						settings.flyStupidity = flyStupidity.text;

						// TODO: create threads for each fly
					}
				}

				MenuIntButton {
					text: qsTr("Stop")
				}
			}
		}
	}
	}
}
