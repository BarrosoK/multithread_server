/*
 * Author: pedrito.
 * Date: 06/08/19
 */


#include <ui/ServerUi.h>
#include <inc/ui/ListItem.h>
#include "ui_ServerUi.h"

ServerUI::ServerUI(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::ServerUI)
{
	ui->setupUi(this);
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

