#ifndef SERIALPORT_PLUGIN_H
#define SERIALPORT_PLUGIN_H

#include <QQmlExtensionPlugin>

class SerialPortPlugin : public QQmlExtensionPlugin
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
	void registerTypes(const char *uri);
};

#endif // SERIALPORT_PLUGIN_H

