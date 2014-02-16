#include "mainscreen.h"
#include "gameclient.h"
#include <QtWidgets/QInputDialog>
#include <iostream>

namespace teh
{
	MainScreen::MainScreen()
		: _client(0)
	{
		_ui.setupUi(this);
		
		connect(_ui.actionQuit, &QAction::triggered, this, &MainScreen::close);
		connect(_ui.actionConnect, &QAction::triggered, this, &MainScreen::onConnectTriggered);
		connect(_ui.actionDisconnect, &QAction::triggered, this, &MainScreen::onDisconnectTriggered);
		connect(_ui.enterButton, &QPushButton::clicked, this, &MainScreen::sendLine);
		connect(_ui.inputLineEdit, &QLineEdit::returnPressed, this, &MainScreen::sendLine);
	}

	MainScreen::~MainScreen()
	{
		if (_client)
			_client->deleteLater();
	}
	
	void MainScreen::addLine(QString line)
	{
		std::cerr << "Adding line: " << line.toStdString() << std::endl;
		_ui.outputPlainTextEdit->setPlainText(_ui.outputPlainTextEdit->toPlainText() + line + "\n");
	}
	
	void MainScreen::sendLine()
	{
		addLine("-> " + _ui.inputLineEdit->text());
		if (_client)
		{
			_client->sendLine(_ui.inputLineEdit->text());
		}
		_ui.inputLineEdit->clear();
	}
	
	void MainScreen::onConnectTriggered()
	{
		if (!_client)
		{
			bool ok;
			QString serveraddr = QInputDialog::getText(this, tr("Enter Server Address"),
						 tr("Server Address:"), QLineEdit::Normal,
						 tr("localhost"), &ok);
			if (ok && !serveraddr.isEmpty())
			{
				_client = new GameClient(this);
				connect(_client, &GameClient::lineArrived, this, &MainScreen::addLine);
				connect(_client, &GameClient::connectionClose, this, &MainScreen::onDisconnectTriggered);
				connect(_client, &GameClient::beginPlaying, this, &MainScreen::startGame);
				_client->start(serveraddr);
			}
		}
	}
	
	void MainScreen::onDisconnectTriggered()
	{
		if (_client)
		{
			_client->deleteLater();
			_client = 0;
			addLine(tr("Disconnected."));
		}
	}
	
	void MainScreen::startGame()
	{
		_ui.inputLineEdit->setFocus(Qt::PopupFocusReason);
	}
}