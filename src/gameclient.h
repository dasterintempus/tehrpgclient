#pragma once

#include <QtCore/QObject>
#include <QtNetwork/QTcpSocket>
#include <QtCore/QStringList>

namespace teh
{
	class MainScreen;
	
	class GameClient
		: public QObject
	{
		Q_OBJECT
		public:
			GameClient(QWidget* parent = 0);
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
			void beginPlaying();
		private:
			void examineLine(const QString& line);
			QWidget* _parent;
		
			QTcpSocket _socket;
			QByteArray _outbuffer;
		
			bool _challengenext;
			bool _charnamesincoming;
		
			QStringList _charnames;
	};
	
	std::string hash_sha512(const std::string& input);
	std::string to_hex(const std::string&input);
}