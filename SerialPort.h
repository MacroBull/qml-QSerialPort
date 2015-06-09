/*
*
*  Under GPL License
*
*/

#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QQuickItem>
#include <QtSerialPort/QSerialPort>

class SerialPort : public QQuickItem
{
	Q_OBJECT
public:
	SerialPort(QQuickItem *parent = 0);

	Q_INVOKABLE void setup(const QString portName, int baudRate = 9600, QString eol=QString("\n"));
	Q_INVOKABLE bool open(QFile::OpenMode mode = QIODevice::ReadWrite);
	Q_INVOKABLE void close();
	Q_INVOKABLE QString	read(qint64 maxSize = 4096);
	Q_INVOKABLE QString	readLine(qint64 maxSize = 4096);
	Q_INVOKABLE bool	write(QString s);
	Q_INVOKABLE bool	writeLine(QString s);

	/*Async+*/

signals:

public slots:

private:
	QString	serialEOL;
	QSerialPort	m_serial;
};

#endif // SERIALPORT_H
