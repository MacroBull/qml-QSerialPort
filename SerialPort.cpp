/*
*
*  Under GPL License
*
*/

#include "SerialPort.h"

SerialPort::SerialPort(QQuickItem *parent):
	QQuickItem(parent)
{

}


 void SerialPort::setup(const QString portName, int baudRate, QString eol){
	 m_serial.setPortName(portName);
	 m_serial.setBaudRate(baudRate);
	 serialEOL = eol;
 }

 bool SerialPort::open(QFile::OpenMode mode){
	 return m_serial.open(mode);
 }

 void SerialPort::close(){
	 m_serial.close();
 }

 QString	SerialPort::read(qint64 maxSize){
	 qint64 cnt;
	 char *buf;

	 buf = (char *)malloc(maxSize);
	 cnt = m_serial.read(buf, maxSize);

	 return QString::fromUtf8(buf, cnt);
 }

 QString	SerialPort::readLine(qint64 maxSize){
	 qint64 cnt;
	 char *buf;

	 buf = (char *)malloc(maxSize);
	 cnt = m_serial.readLine(buf, maxSize);

	 return QString::fromUtf8(buf, cnt);
 }

 bool	SerialPort::write(QString s){
	 return s.length() ==  m_serial.write(s.toUtf8());
 }

 bool	SerialPort::writeLine(QString s){
	 return write(s + serialEOL);
 }

