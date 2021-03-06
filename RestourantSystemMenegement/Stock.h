#pragma once
#include "ItemBase.h"
#include "RecipeItem.h"

class Stock :public ItemBase {
	ReciepeItem** items;
	int curretncount;
public:
	Stock() = default;
	Stock(ReciepeItem** item, int itemcount) :ItemBase(itemcount)
	{
		setItems(item);
	}
	ReciepeItem** getItems()const {
		return items;
	}
	void increaseIngredientCount(ReciepeItem* items, const int amount) {

		items->setCount(items->getCount() + amount);
	}
	void decreaseIngredientCount(ReciepeItem* items, const int amount) {

		items->setCount(items->getCount() - amount);
	}
	int count = ItemBase::getCount();
	void setItems(ReciepeItem** items) {
		this->items = new ReciepeItem * [count] {};
		for (int i = 0; i < count; i++)
		{
			this->items[i] = items[i];
		}
	}
	int currentCount = ItemBase::getCount();
	void show()const {
		for (int i = 0; i < currentCount; i++)
		{
			items[i]->show();
		}
	}
	void showDetail()const {
		for (int i = 0; i < currentCount; i++)
		{
			items[i]->showDetail();
		}
	}
	string namein;
	double moneyin;
	double fatin;
	double proteinin;
	double carbohydratesin;
	double kcalin;
	int ingCount;
	void inputIngredient() {
		cout << "Enter The Ingredient name : " << endl; // Proqram cokur reqem daxil edende
		cin >> namein;
		cout << "Enter The Ingredient price : " << endl;
		cin >> moneyin;
		cout << "Enter The Ingredient fat : " << endl;
		cin >> fatin;
		cout << "Enter The Ingredient protein : " << endl;
		cin >> proteinin;
		cout << "Enter The Ingredient carboHydrates : " << endl;
		cin >> carbohydratesin;
		cout << "Enter The Ingredient kcal : " << endl;
		cin >> kcalin;
		cout << "Enter the ingredient amount : " << endl;
		cin >> ingCount;
	}
	void addIngredientinStock() {
		inputIngredient();
		Ingredient* ingredient = new Ingredient(namein, moneyin, fatin, proteinin, carbohydratesin, kcalin);
		auto newIngredient = new ReciepeItem * [currentCount + 1]{};
		for (int i = 0; i < currentCount; i++)
		{
			newIngredient[i] = items[i];
		}
		newIngredient[currentCount] = new ReciepeItem(ingredient, 1);
		++currentCount;
		items = newIngredient;
		newIngredient = nullptr;
	}
	void deleteIngredient(int id) {
		auto newIngreedient = new ReciepeItem * [currentCount - 1]{};
		for (int i = 0; i < id; i++)
		{
			newIngreedient[i] = items[i];
		}
		for (int i = id, i2 = id + 1; i2 < currentCount; i++, i2++)
		{
			newIngreedient[i] = items[i2];
		}
		items = newIngreedient;
		--currentCount;
		newIngreedient = nullptr;
	}
};
istream& operator>>(istream& in, Ingredient& stock) {
	string name;
	double money;
	double fat;
	double protein;
	double carbohydrates;
	double kcal;
	cout << "Enter The Ingredient name: " << endl;
	in >> name;
	cout << "Enter The Ingredient price: " << endl;
	in >> money;
	cout << "Enter The Ingredient fat: " << endl;
	in >> fat;
	cout << "Enter The Ingredient protein: " << endl;
	in >> protein;
	cout << "Enter The Ingredient carboHydrates: " << endl;
	in >> carbohydrates;
	cout << "Enter The Ingredient kcal: " << endl;
	in >> kcal;
	return in;
}