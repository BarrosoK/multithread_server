/*
 * Author: pedrito.
 * Date: 06/08/19
 */

#ifndef SERVER_MAINWINDOW_H
#define SERVER_MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <inc/Client.h>
#include <QtCore/QItemSelection>
#include "Singleton.h"

namespace Ui {
	class ServerUI;
}

class ServerUI : public QMainWindow, public Singleton<ServerUI> {
	Q_OBJECT
		friend class Singleton<ServerUI>;
	public slots:
		void addClient(Client *client);
		void removeClient(Client *client);
		void handleSelectionChange(const QItemSelection& selection);
		void kickClient();
	private:
		explicit ServerUI(QWidget *parent = 0);
		~ServerUI();
		Ui::ServerUI *ui;
		Client *selectedClient;
};

#endif //SERVER_MAINWINDOW_H
