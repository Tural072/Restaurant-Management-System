#pragma once
#include "Meal.h"
#include "Notification.h"
#include "Adminside.h"
#include "Table.h"
using namespace Adminside;
class DateBase {
	Meal** meals;
	Notification** notification;
	Admin** admins;
	Table** tables;
	int table_count;
	int meals_count;
	int admins_count;
public:
	DateBase() = default;
	DateBase(Admin** admins, Table** tables, Meal** meals)
	{
		setMeals(meals);
		setAdmin(admins);
		setTables(tables);
	}
	void showDetailMealsWithId(int id) {
		for (int i = 0; i < 3; i++)
		{
			if (id == meals[i]->getId()) {
				meals[i]->showDetail();
			}
		}
	}
	void setMeals(Meal** meals) {
		this->meals = meals;
	}
	void setNotifications(Notification** notificaions) {
		this->notification = notificaions;
	}
	void setAdmin(Admin** admins) {
		this->admins = admins;
	}
	void setTables(Table** tables) {
		this->tables = tables;
	}
};