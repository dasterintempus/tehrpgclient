#include "gameclient.h"
#include "mainscreen.h"
#include <QtWidgets/QInputDialog>
#include <sha.h>
#include <iostream>
#include <sstream>
#include <iomanip>

namespace teh
{
	GameClient::GameClient(QWidget* parent)
		: QObject(parent), _parent(parent), _challengenext(false), _charnamesincoming(false)
	{
		
	}
	
	GameClient::~GameClient()
	{
		_socket.disconnect();
	}
	
	void GameClient::start(const QString& server)
	{
		std::cerr << "Starting game client." << std::endl;
		connect(&_socket, &QTcpSocket::readyRead, this, &GameClient::dataReady);
		connect(&_socket, &QTcpSocket::disconnected, this, &GameClient::socketClose);
		connect(&_socket, &QTcpSocket::bytesWritten, this, &GameClient::dataSent);
		connect(&_socket, &QTcpSocket::stateChanged, this, &GameClient::socketStateChange);
		
		std::cerr << "Trying to connect." << std::endl;
		_socket.connectToHost(server, 3137);
		if (_socket.waitForConnected(3000))
		{
			std::cerr << "Connected" << std::endl;
			emit lineArrived(tr("Connected!"));
			
			bool ok;
			QString username = QInputDialog::getText(_parent, tr("Login"),
						 tr("Username:"), QLineEdit::Normal,
						 tr(""), &ok);
			if (ok && !username.isEmpty())
			{
				sendLine("/login " + username);
			}
		}
		else
		{
			std::cerr << "Timed out" << std::endl;
			emit lineArrived(tr("Unable to connect."));
			emit connectionClose();
		}
	}
	
	void GameClient::sendLine(QString line)
	{
		_outbuffer.append(line);
		_outbuffer.append("\n");
		_socket.write(_outbuffer);
	}
	
	void GameClient::dataReady()
	{
		//std::cerr << "Data ready " << _socket.bytesAvailable() << std::endl;
		while (_socket.canReadLine())
		{
			char data[4096];
			qint64 bytesread = _socket.readLine(data, sizeof(data));
			//std::cerr << "Data read (" << bytesread << ") " << data << std::endl;
			QString qstr(data);
			qstr = qstr.mid(0, qstr.size()-1);
			if (qstr == "")
				continue;
			std::cerr << "Read line: '" << qstr.toStdString() << "'" << std::endl;
			examineLine(qstr);
			emit lineArrived(qstr);
		}
	}
	
	void GameClient::dataSent(qint64 bytes)
	{
		_outbuffer = _outbuffer.mid(bytes);
		if (_outbuffer.size() > 0)
		{
			_socket.write(_outbuffer);
		}
	}
	
	void GameClient::socketClose()
	{
		emit connectionClose();
	}
	
	void GameClient::socketStateChange(QAbstractSocket::SocketState state)
	{
		switch (state)
		{
			case QAbstractSocket::ClosingState:
				emit connectionClose();
				break;
			case QAbstractSocket::UnconnectedState:
				emit connectionClose();
				break;
			default:
				break;
		}
	}
	
	void GameClient::examineLine(const QString& line)
	{
		if (_challengenext)
		{
			_challengenext = false;
			bool ok;
			QString password = QInputDialog::getText(_parent, tr("Enter Password"),
						 tr("Password:"), QLineEdit::Password,
						 tr(""), &ok);
			if (ok && !password.isEmpty())
			{
				std::string hexpassword = to_hex(hash_sha512(password.toStdString()));
				std::string response = to_hex(hash_sha512(line.toStdString() + hexpassword));
				std::string responseline = "/passwd " + response;
				sendLine(responseline.c_str());
			}
			else
			{
				emit connectionClose();
			}
		}
		else if (_charnamesincoming)
		{
			if (line == "---")
			{
				_charnamesincoming = false;
				if (_charnames.size() > 0)
				{
					bool ok = false;
					QString character = QInputDialog::getItem(_parent, tr("Select Character"),
									tr("Character:"), _charnames, 0, false, &ok);
					if (ok && !character.isEmpty())
					{
						sendLine("/select \"" + character + "\"");
					}
				}
				_charnames.clear();
			}
			else
			{
				if (line.at(0) == '*')
				{
					_charnamesincoming = false; // Cancel, we're already logged in
					_charnames.clear();
				}
				else
				{
					_charnames << line;
				}
			}
		}
		else
		{
			if (line == "Logged in.")
			{
				//sendLine("/listchars");
			}
			else if (line == "Challenge:")
			{
				_challengenext = true;
			}
			else if (line == "Characters:")
			{
				_charnamesincoming = true;
			}
			else if (line.mid(0, 20) == "Selected character: ")
			{
				emit beginPlaying();
			}
		}
	}
	
	std::string hash_sha512(const std::string& input)
	{
		CryptoPP::SHA512 sha;
		unsigned char* buffer = new unsigned char[sha.DigestSize()];
		unsigned char* inputbytes = new unsigned char[input.size()];
		memcpy(inputbytes, input.c_str(), input.size());
		sha.CalculateDigest(buffer, inputbytes, input.size());
		char* hashedbytes = new char[sha.DigestSize()];
		memcpy(hashedbytes, buffer, sha.DigestSize());
		std::string hashed(hashedbytes, sha.DigestSize());
		delete buffer;
		delete inputbytes;
		delete hashedbytes;
		return hashed;
	}
	
	std::string to_hex(const std::string& input)
	{
		std::stringstream conv;
		
		conv << std::hex << std::setfill('0');
		
		for (std::size_t i = 0; i != input.size(); ++i)
		{
			unsigned int current_byte_number = static_cast<unsigned int>(static_cast<unsigned char>(input[i]));
			conv << std::setw(2) << current_byte_number;
		}
		
		return conv.str();
	}
	
}