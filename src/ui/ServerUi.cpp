/*
 * Author: pedrito.
 * Date: 06/08/19
 */


#include <ui/ServerUi.h>
#include <inc/ui/ListItem.h>
#include <inc/ui/ServerUi.h>
#include <inc/Server.h>
#include <QtCore/QStringListModel>

#include "ui_ServerUi.h"

ServerUI::ServerUI(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::ServerUI)
{
	ui->setupUi(this);
	ui->selectedClient->setEnabled(false);
	ui->listWidget->connect(ui->listWidget->selectionModel(),
		SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
		this, SLOT(handleSelectionChange(QItemSelection)));
	connect(ui->kickButton, SIGNAL (released()), this, SLOT (kickClient()));

}

ServerUI::~ServerUI()
{
	delete ui;
}

void ServerUI::addClient(Client *client)
{
	ListItem *itm = new ListItem(client);
	ui->listWidget->addItem(itm);
}

void ServerUI::removeClient(Client *client)
{
	QAbstractItemModel *model = ui->listWidget->model();
	for (int i = 0; i < model->rowCount(); i++) {
		ListItem *item = (ListItem *)ui->listWidget->item(i);
		if  (std::stol(item->getId()) == client->getId()) {
			// ui->listWidget->model()->removeRow(0);
			return;
		}
	}
}

void ServerUI::handleSelectionChange(const QItemSelection &selection)
{
	QModelIndex index = selection.indexes().first();
	std::cout << index.row() << std::endl;
	ListItem *item = (ListItem *)ui->listWidget->item(index.row());
	Client *client = Server::findClientById(std::stol(item->getId()));
	if (client) {
		selectedClient = client;
		ui->selectedClient->setEnabled(true);

	}
}

void ServerUI::kickClient()
{
	selectedClient->kick("Kicked");
}

