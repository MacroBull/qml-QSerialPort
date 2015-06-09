#ifndef SERIALPORTINFO_H
#define SERIALPORTINFO_H

#include <QQuickItem>
#include <QtSerialPort/QSerialPortInfo>



class SerialPortInfo : public QQuickItem, public QSerialPortInfo
{
	Q_OBJECT
	Q_DISABLE_COPY(SerialPortInfo)
	Q_ENUMS(portDelegateType)
	Q_PROPERTY(QList<int> standardBaudRates READ standardBaudRates CONSTANT)
	Q_PROPERTY(QList<QString> availablePorts READ availablePorts NOTIFY availablePortsChanged)
	Q_PROPERTY(portDelegateType portDelegate READ portDelegate WRITE setPortDelegate)
//	Q_PROPERTY(QString portName READ portName)

public:
	SerialPortInfo(QQuickItem *parent = 0);
	~SerialPortInfo();

	enum portDelegateType {
		SerialNumber	=	0x1,
		PortName	=	0x2,
		SystemLocation	=	0x4,
		Description	=	0x8,
		ProductIdentifier	=	0x10,
		VendorIdentifier	=	0x20,
		Manufacture	=	0x40,
	};

//	Q_INVOKABLE QString	description();
//	Q_INVOKABLE quint16	productIdentifier();
//	Q_INVOKABLE quint16	vendorIdentifier();
//	Q_INVOKABLE bool	isBusy();
//	Q_INVOKABLE bool	isNull();
//	Q_INVOKABLE QString	manufacturer();
//	QString	portName();
//	Q_INVOKABLE	QString	serialNumber();
//	Q_INVOKABLE	QString	systemLocation();

	portDelegateType	portDelegate();
	void	setPortDelegate(portDelegateType d);
	QList<QString>	availablePorts();
	QList<int>	standardBaudRates();

signals:
	void availablePortsChanged();

private:
	portDelegateType	m_portDelegate;// = SerialNumber;
};

#endif // SERIALPORTINFO_H

