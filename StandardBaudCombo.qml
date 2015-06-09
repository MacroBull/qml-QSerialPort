import QtQuick 2.0
import QtQuick.Controls 1.3
import QSerialPort 1.0

ComboBox {

	property int baudRate;

	model:ListModel{}

	baudRate:currentText

	SerialPortInfo {
		id: globalInfo
	}

	Component.onCompleted: {
		var list = globalInfo.standardBaudRates
		for (var i in list){
			model.append( {text:list[i]} )
		}
	}
}

	


