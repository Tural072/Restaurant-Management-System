#pragma once
#include"Base.h"
#include "Exception.h"
#include <string>
using namespace std;
using namespace Exception;
class Ingredient :public Base {
	string name;
	double money;
	double fat;
	double protein;
	double carbohydrates;
	double kcal;
public:
	static int ingredietnid;
	Ingredient() :name(""), fat(0), protein(0), carbohydrates(0), kcal(0), money(0) {}
	Ingredient(const string name, const double fat, const double protein, const double carbohydrates, const int kcal, const double money)
		:Base(++ingredietnid)
	{
		setName(name);
		setFat(fat);
		setProtein(protein);
		setCarbohydrates(carbohydrates);
		setKcal(kcal);
		setMoney(money);
	}
	static int getID() {
		return ingredietnid;
	}
	string getName()const {
		return name;
	}
	double getFat()const {
		return fat;
	}
	double getProtein()const {
		return protein;
	}
	double getCarbohydrates()const {
		return carbohydrates;
	}
	double getMoney()const {
		return money;
	}
	double getKcal()const {
		return kcal;
	}
	void setName(const string name) {
		if (!name.empty())
		{
			this->name = name;
		}
		else
		{
			throw InvalidArgumentException("Name is empty", __LINE__, "exception.txt");
		}
	}
	void setMoney(const double money) {
		if (money >= 0) {
			this->money = money;
		}
		else
		{
			throw InvalidArgumentException("Money < 0", __LINE__, "exception.txt");
		}
	}
	void setFat(const double fat) {
		if (fat > 0)
		{
			this->fat = fat;
		}
		else
		{
			throw InvalidArgumentException("Fat < 0", __LINE__, "exception.txt");
		}
	}
	void setProtein(const double protein) {
		if (protein > 0)
		{
			this->protein = protein;
		}
		else
		{
			throw InvalidArgumentException("Protein < 0", __LINE__, "exception.txt");
		}
	}
	void setCarbohydrates(const double carbohydrates) {
		if (carbohydrates > 0)
		{
			this->carbohydrates = carbohydrates;
		}
		else
		{
			throw InvalidArgumentException("Carbohydrates < 0", __LINE__, "exception.txt");
		}
	}
	void setKcal(const double kcal) {
		if (kcal > 0)
		{
			this->kcal = kcal;
		}
		else
		{
			throw InvalidArgumentException("Kcal < 0", __LINE__, "exception.txt");
		}
	}
	void showDetail() const {
		cout << "_________Ingredient_________" << endl;
		cout << "Id : " << getId() << endl;
		cout << "Name : " << getName() << endl;
		cout << "Price : " << getMoney() << endl;
		cout << "Fats : " << getFat() << endl;
		cout << "Protein : " << getProtein() << endl;
		cout << "Carbohydrats : " << getCarbohydrates() << endl;
		cout << "Kcal : " << getKcal() << endl << endl;
	}
	void show()const {
		cout << "Name : " << getName() << endl;
	}
};
class Mushrooms :public Ingredient {
public:
	Mushrooms(string name, const double fat, const double protein, const double carbohydrates, const int kcal, const double money)
		:Ingredient(name, fat, protein, carbohydrates, kcal, money)
	{
	}
	void show()const {
		Ingredient::show();
	}
};
class Meat :public Ingredient {
public:
	Meat(string name, const double fat, const double protein, const double carbohydrates, const int kcal, const double money)
		:Ingredient(name, fat, protein, carbohydrates, kcal, money)
	{
	}
	void show()const {
		Ingredient::show();
	}
};
class Spices :public Ingredient {
public:
	Spices(string name, const double fat, const double protein, const double carbohydrates, const int kcal, const double money)
		:Ingredient(name, fat, protein, carbohydrates, kcal, money)
	{
	}
	void show()const {
		Ingredient::show();
	}
};
class Cheese :public Ingredient {
public:
	Cheese(string name, const double fat, const double protein, const double carbohydrates, const int kcal, const double money)
		:Ingredient(name, fat, protein, carbohydrates, kcal, money) {}
};
class Tomatoes :public Ingredient {
public:
	Tomatoes(string name, const double fat, const double protein, const double carbohydrates, const int kcal, const double money)
		:Ingredient(name, fat, protein, carbohydrates, kcal, money) {}
};