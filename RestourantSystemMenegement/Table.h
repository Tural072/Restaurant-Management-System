#pragma once
#include <iostream>
#include <string>
#include "Base.h"
#include "Order.h"
#include "Notification.h"

class Table :public Base {
	string no;
	Order** orders;
	int orderCount;
	int table_count;
	bool isEmpty;
	Notification** notifications;
	int notificationCount;
public:
	Table() :no(""), orderCount(0), table_count(1), isEmpty(false) {}
	Table(const string no, bool isEmpty, int count = 1)
	{
		setNo(no);
		setIsEmpty(isEmpty);
		setTableCount(count);
	}
	Notification** getNotification()const {
		return notifications;
	}
	int getNotificationCount()const {
		return notificationCount;
	}
	int getTableCount()const {
		return table_count;
	}
	string getNo()const {
		return no;
	}
	int getCount()const {
		return orderCount;
	}
	Order** getOrders()const {
		return orders;
	}
	bool getIsEmpty()const {
		return isEmpty;
	}
	void setNotification(Notification** notifications) {
		this->notifications = new Notification * [notificationCount] {};
		for (size_t i = 0; i < notificationCount; i++)
		{
			this->notifications = notifications;
		}
	}
	void setNotificationCount(const int notificationCount) {
		if (notificationCount > 0)
		{
			this->notificationCount = notificationCount;
		}
		else
		{
			throw InvalidArgumentException("Notification count < 0", __LINE__, "exception.txt");
		}
	}
	void setTableCount(int count) {
		if (count >= 0) {
			this->table_count = count;
		}
		else
		{
			throw InvalidArgumentException("Table count < 0", __LINE__, "exception.txt");
		}
	}
	void setIsEmpty(bool isEmpty) {
		this->isEmpty = isEmpty;
	}
	void setOrderCount(const int orderCount) {
		if (orderCount > 0)
		{
			this->orderCount = orderCount;
		}
		else
		{
			throw InvalidArgumentException("Order count < 0", __LINE__, "exception.txt");
		}
	}
	void setNo(const string no) {
		if (!no.empty())
		{
			this->no = no;
		}
		else
		{
			throw InvalidArgumentException("Table no is empty", __LINE__, "exception.txt");
		}
	}
	void setOrders(Order** orders) {
		this->orders = new Order * [orderCount] {};
		for (size_t i = 0; i < orderCount; i++)
		{
			this->orders[i] = orders[i];
		}
	}
	void showTable() {
		for (int i = 0; i < table_count; i++)
		{
			cout << "Table no : " << getNo() << endl;
		}
	}
	void addNotification(Notification* notification) {
		auto newNotfications = new Notification * [notificationCount + 1]{};
		for (size_t i = 0; i < notificationCount; i++)
		{
			newNotfications[i] = this->notifications[i];
		}
		newNotfications[notificationCount] = notification;
		++notificationCount;
		notifications = newNotfications;
		newNotfications = nullptr;
	}
	void showNotification()const {
		for (size_t i = 0; i < notificationCount; i++)
		{
			notifications[i]->show();
		}
	}
	bool checkTable(Table* tables) {
		for (int i = 0; i < table_count; i++)
		{
			if (tables->getIsEmpty() == false) {
				return false;
			}
			else {
				return true;
			}
		}
	}
	void show()const {
		cout << "=============Table Info==============" << endl;
		cout << "Table no : " << getNo() << endl;
	}
};