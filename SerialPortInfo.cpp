#include "SerialPortInfo.h"

SerialPortInfo::SerialPortInfo(QQuickItem *parent):
	QQuickItem(parent), QSerialPortInfo()
{
	// By default, QQuickItem does not draw anything. If you subclass
	// QQuickItem to create a visual item, you will need to uncomment the
	// following line and re-implement updatePaintNode()

	// setFlag(ItemHasContents, true);

//	emit(SerialPortInfo::availablePorts());
	m_portDelegate = SerialNumber;
}

SerialPortInfo::~SerialPortInfo()
{
}



//QString	SerialPortInfo::SerialPortInfo::portName(){
//	return m_portDelegate;
//}

SerialPortInfo::portDelegateType	SerialPortInfo::portDelegate(){
	return m_portDelegate;
}

void	SerialPortInfo::setPortDelegate(SerialPortInfo::portDelegateType d){
	m_portDelegate = d;
}

QList<int>	SerialPortInfo::standardBaudRates(){
	return QSerialPortInfo::standardBaudRates();
}

QList<QString>	SerialPortInfo::availablePorts(){
	QList<QString> r = QList<QString>();
	foreach (const QSerialPortInfo &port, QSerialPortInfo::availablePorts()){
		QString rt = QString(port.portName() + ":");
		if (SerialNumber & m_portDelegate)	rt += ':' + port.serialNumber();
		if (PortName & m_portDelegate)	rt += ':' + port.portName();
		if (SystemLocation & m_portDelegate)	rt += ':' + port.systemLocation();
		if (Description & m_portDelegate)	rt += ':' + port.description();
		if (ProductIdentifier & m_portDelegate)	rt += ':' + port.productIdentifier();
		if (VendorIdentifier & m_portDelegate)	rt += ':' + port.vendorIdentifier();
//		if (Manufacture & m_portDelegate)	rt += port.manufacture();
//		rt.chop(1);
		r.append(rt);
	}
	qDebug() << r;

	return r;
}

