/*
 *      main.cpp
 *
 *
 * Copyright (C) 2017 Max V. Stotsky <maxstotsky@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published
 * by the Free Software Foundation; version 3 or later.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <QApplication>
#include <QQmlApplicationEngine>


int main(int argc, char** argv)
{
	QGuiApplication app(argc, argv);

	app.setOrganizationName("lotf");
	app.setOrganizationDomain("lotf.com");
	app.setApplicationName("Lotf");

	QQmlApplicationEngine engine;
	engine.load(QUrl("qrc:/main.qml"));
	return app.exec();
}

