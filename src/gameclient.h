#pragma once

#include <QtCore/QObject>
#include <QtNetwork/QTcpSocket>

namespace teh
{
	class MainScreen;
	
	class GameClient
		: public QObject
	{
		Q_OBJECT
		public:
			GameClient(QWidget* parent);
			~GameClient();
		
			void start(const QString& server);
		
		public slots:
			void sendLine(QString line);
		
		private slots:
			void dataReady();
			void dataSent(qint64 bytes);
			void socketClose();
			void socketStateChange(QAbstractSocket::SocketState state);
		signals:
			void lineArrived(QString line);
			void connectionClose();
		private:
			void examineLine(const QString& line);
			QWidget* _parent;
		
			QTcpSocket _socket;
			QByteArray _outbuffer;
		
			bool _loggedin;
			bool _challengenext;
	};
	
	std::string hash_sha512(const std::string& input);
	std::string to_hex(const std::string&input);
}