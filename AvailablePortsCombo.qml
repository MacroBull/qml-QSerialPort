import QtQuick 2.0
import QtQuick.Controls 1.3
import QSerialPort 1.0

ComboBox {

	property string portName;
	property variant portDelegateList;

	portName: portDelegateList[currentIndex].split(':')[0];

	model:ListModel{}

	function updateSPI(){
		portDelegateList = globalInfo.availablePorts
		model.clear()
		for (var i in portDelegateList){
			model.append( {text:portDelegateList[i].slice(portDelegateList[i].indexOf('::')+2)} )
		}
	}

	SerialPortInfo {
		id: globalInfo

		portDelegate: SerialPortInfo.PortName + SerialPortInfo.Description;

		onAvailablePortsChanged:updateSPI()
	}

	Component.onCompleted:updateSPI()
}

	


