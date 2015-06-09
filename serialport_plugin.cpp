#include "serialport_plugin.h"
#include "SerialPortInfo.h"
#include "SerialPort.h"

#include <qqml.h>

void SerialPortPlugin::registerTypes(const char *uri)
{
	// @uri SerialPort
	qmlRegisterType<SerialPortInfo>(uri, 1, 0, "SerialPortInfo");
	qmlRegisterType<SerialPort>(uri, 1, 0, "SerialPort");
}


