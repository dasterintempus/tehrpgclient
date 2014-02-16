#pragma once

#include <QtWidgets/QMainWindow>
#include "tehrpgclient_form.h"

namespace teh
{
	class GameClient;
	
	class MainScreen
		: public QMainWindow
	{
		Q_OBJECT
		public:
			MainScreen();
			virtual ~MainScreen();
		
		public slots:
			void addLine(QString line);
			void sendLine();
		
		private slots:
			void onConnectTriggered();
			void onDisconnectTriggered();
		
		private:
			Ui_MainWindow _ui;
			GameClient* _client;
	};	
		
}