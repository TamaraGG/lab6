#include "collection.h"

// соединение между собой всех виджетов из коллекции (с помощью сигналов и слотов)
void Collection::ConnectToOthers(QObject* o)
{
	if (o->metaObject()->className() == QString("QSlider") ||
		o->metaObject()->className() == QString("QSpinBox") ||
		o->metaObject()->className() == QString("QScrollBar"))
	{
		QObject::connect(o, SIGNAL(valueChanged(int)), this, SLOT(setAllValues(int)));
	}
}


// добавление виджета в коллекцию по ссылке
void Collection::AddWidget(QObject* o)
{
	if (!widgets.contains(o))
	{
		widgets.append(o);
		ConnectToOthers(o);
	}
}

// удаление виджета из коллекции по ссылке
void Collection::DeleteWidget(QObject* o)
{
	widgets.removeOne(o);
}

// удаление всех методов из коллеции
void Collection::Clear()
{
	widgets.clear();
}

// слот: изменение значений всех виджетов
void Collection::setAllValues(int x)
{
	for (auto it = widgets.begin(); it != widgets.end(); it++)
	{
		if ((*it)->metaObject()->className() == QString("QLabel"))
		{
			qobject_cast<QLabel*>(*it)->setText(QString::number(x));
		}
		else if ((*it)->metaObject()->className() == QString("QSlider"))
		{
			qobject_cast<QSlider*>(*it)->setValue(x);
		}
		else if ((*it)->metaObject()->className() == QString("QSpinBox"))
		{
			qobject_cast<QSpinBox*>(*it)->setValue(x);
		}
		else if ((*it)->metaObject()->className() == QString("QScrollBar"))
		{
			qobject_cast<QScrollBar*>(*it)->setValue(x);
		}
	}
}
