#pragma once
#include <string>
#include "Meal.h"
class Order :public Base {
	string table_no;
	Meal* meal;
	int amount;
	bool accepted;
	bool cancel;
public:
	static int id;
	Order() = default;
	Order(string tableno, Meal* meal, int amount) :Base(++id)
	{
		setTableNo(tableno);
		setMeals(meal);
		setAmount(amount);
	}
	static int getId() {
		return id;
	}
	string getTableNo()const {
		return table_no;
	}
	Meal* getmeals()const {
		return meal;
	}
	int getAmount()const {
		return amount;
	}
	bool getAccapted() {
		return accepted;
	}
	bool getCancel() {
		return cancel;
	}
	void setTableNo(const string no) {
		if (!no.empty()) {
			this->table_no = no;
		}
		else
		{
			throw InvalidArgumentException("No is empty", __LINE__, "exception.txt");
		}
	}
	void setMeals(Meal* meals) {
		this->meal = meals;
	}
	void setAmount(const int amount) {
		this->amount = amount;
	}
	void show()const {
		cout << "Table No : " << getTableNo() << endl;
		cout << "Meal Amount : " << getAmount() << endl;
		cout << "Order id : " << getId() << endl;
		for (int i = 0; i < amount; i++)
		{
			meal[i].show();
		}
	}
};