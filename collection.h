#pragma once

#ifndef COLLECTION_H
#define COLLECTION_H

#include <QApplication>
#include <QLabel>
#include <QSlider>
#include <QScrollbar>
#include <QSpinBox>
#include <QString>



// Класс, который содержит коллекцию связанных между собой 
// виджетов (QLabel, QSlider, QSpinBox, QScrollber)

class Collection : public QObject
{
Q_OBJECT
private:
	QList<QObject*> widgets; // список, в котором хранятся виджеты (ссылки на них)

	void ConnectToOthers(QObject* o); // метод, который соединяет между собой
									  // все виджеты из коллекции

public:

	void AddWidget(QObject* o); // метод, который добавляет виджет в коллекцию
	void DeleteWidget(QObject* o); // метод, который удаляет виджет из коллекции
								   // по ссылке
	void Clear(); // метод, который удаляет все виджеты из коллекции

private slots:
	void setAllValues(int x); // слот, который изменяет все значения находящихся
							  // в коллекции виджетов
};


#endif // COLLECTION_H
