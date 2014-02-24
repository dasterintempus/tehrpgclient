#include "historylineedit.h"

namespace teh
{
	HistoryLineEdit::HistoryLineEdit(QWidget* parent)
		: QLineEdit(parent), _backscrollpos(0), _currentline("")
	{

	}
	
	HistoryLineEdit::HistoryLineEdit(const QString& text, QWidget* parent)
		: QLineEdit(text, parent), _backscrollpos(0), _currentline("")
	{
	
	}
	
	void HistoryLineEdit::rememberLine(QString line)
	{
		_linehistory.push_front(line);
		if (_linehistory.size() > 100)
			_linehistory.pop_back();
	}
	
	void HistoryLineEdit::keyPressEvent(QKeyEvent* event)
	{
		int key = event->key();
		if (key == Qt::Key_Up)
		{
			if (_backscrollpos == 0)
				_currentline = text();
			_backscrollpos++;
			if (_backscrollpos > _linehistory.size())
				_backscrollpos = _linehistory.size();
			setText(_linehistory[_backscrollpos-1]);
		}
		else if (key == Qt::Key_Down)
		{
			_backscrollpos--;
			if (_backscrollpos < 1)
			{
				_backscrollpos = 0;
				setText(_currentline);
				_currentline = "";
			}
			else
			{
				setText(_linehistory[_backscrollpos-1]);
			}
		}
		else
		{
			QLineEdit::keyPressEvent(event);
		}
	}
}