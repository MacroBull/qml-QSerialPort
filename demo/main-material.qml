import QtQuick 2.4

import Material 0.1

import QSerialPort 1.0

ApplicationWindow {
	title: "Serial Test"
	width: 640
	height: 480
	
	SerialPort{
		id: sp
	}
	
	theme {
		primaryColor: Palette.colors["blue"]["500"]
		primaryDarkColor: Palette.colors["blue"]["700"]
		accentColor: Palette.colors["teal"]["500"]
		tabHighlightColor: "white"
	}
	
	initialPage:	InitialPage {
		id: mainForm1
		title: "Serial Test"
		anchors.fill: parent
		
		AvailablePortsMenu {
			id:port
			anchors.verticalCenter: parent.verticalCenter
			anchors.verticalCenterOffset: -50
			width: parent.width / 4
			maxVisibleItems: 8
			anchors.horizontalCenterOffset: -parent.width / 7
			anchors.horizontalCenter: parent.horizontalCenter
		}
		StandardBaudMenu {
			id:baud
			anchors.verticalCenter: parent.verticalCenter
			anchors.verticalCenterOffset: -50
			width: parent.width / 4
			maxVisibleItems: 8
			anchors.horizontalCenter: parent.horizontalCenter
			anchors.horizontalCenterOffset: parent.width / 7
		}
		
		button1.text:"Test/Read"
		button2.text:"Open/Close"
		button3.text:"Send something"
		
		button1.onClicked: {
			console.log(port.portName, baud.baudRate)
			label1.text = sp.readLine()
		}
		
		button2.checkable: true
		button2.onClicked: {
			if (button2.checked) {
				sp.setup(port.portName, baud.baudRate)
				console.log('Open:', sp.open())
			}
			else {
				sp.close()
			}
		}
		button3.onClicked: {
			sp.write("2333")
		}
		
	}
}
