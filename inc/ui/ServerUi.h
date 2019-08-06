/*
 * Author: pedrito.
 * Date: 06/08/19
 */

#ifndef SERVER_MAINWINDOW_H
#define SERVER_MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <inc/Client.h>
#include "Singleton.h"

namespace Ui {
	class ServerUI;
}

class ServerUI : public QMainWindow, public Singleton<ServerUI> {
	Q_OBJECT
		friend class Singleton<ServerUI>;
	public:
	public slots:
		void addClient(Client *client);
	private:
		explicit ServerUI(QWidget *parent = 0);
		~ServerUI();
		Ui::ServerUI *ui;
};

#endif //SERVER_MAINWINDOW_H
