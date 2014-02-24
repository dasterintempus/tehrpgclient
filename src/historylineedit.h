#pragma once

#include <QtWidgets/QLineEdit>
#include <QtGui/QKeyEvent>

namespace teh
{
	class HistoryLineEdit
		: public QLineEdit
	{
		Q_OBJECT
		public:
			HistoryLineEdit(QWidget* parent = 0);
			HistoryLineEdit(const QString& text, QWidget* parent = 0);
		public slots:
			void rememberLine(QString line);
		protected:
			void keyPressEvent(QKeyEvent* event);
		private:
			int _backscrollpos;
			QVector<QString> _linehistory;
			QString _currentline;
	};
}