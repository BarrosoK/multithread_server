/*
 * Author: pedrito.
 * Date: 07/08/19
 */

#ifndef SERVER_LISTITEM_H
#define SERVER_LISTITEM_H

#include <iostream>
#include <QtWidgets/QListWidgetItem>
#include <inc/Client.h>

class ListItem : public QListWidgetItem
{
	private:
		std::string id;
		bool selected;
	public:
		explicit ListItem(Client *client) {
			id = std::to_string(client->getId());
			setText(id.c_str());
		}
		std::string getId() {
			return id;
		}

};

#endif //SERVER_LISTITEM_H
