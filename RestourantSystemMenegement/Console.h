#pragma once
#include <iostream>
#include "Adminside.h"
#include "Ingredient.h"
#include "Recipeitem.h"
#include "Meal.h"
#include "Table.h"
#include "Stock.h"
#include "Kitchen.h"
#include "Restourant.h"
#include "Datebase.h"
#include "FileHelper.h"
#include <Windows.h>

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGREY 7
#define DARKGREY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15
#define BLINK 128
using namespace std;
using namespace Adminside;
class Console {
public:
	//Admin
	Admin* admin1 = new Admin("admin", "admin");
	Admin* admin2 = new Admin("Tural", "123456");
	Admin* admin3 = new Admin("Murad", "654321");
	Admin** admins = new Admin * [3]{ admin1,admin2,admin3 };
	//Ingredients
	Ingredient* mushroom = new Mushrooms("Kend Gobeleyi", 0.1, 15, 3, 2, 3.50);
	Ingredient* meat = new Meat("Mal eti", 10, 25, 10, 10, 2.10);
	Ingredient* spice = new Spices("Duz", 2, 5, 3, 1, 1.30);
	Ingredient* cheese = new Cheese("Holland Pendiri", 1, 8, 3, 5, 2.20);
	Ingredient* tomato = new Tomatoes("Zire Pomidoru", 0.1, 8, 3, 1, 5.10);
	Ingredient** ing = new Ingredient * [5]{ mushroom,meat,spice,cheese,tomato };
	//RecipeItem
	ReciepeItem* reciep = new ReciepeItem(mushroom, 13);
	ReciepeItem* reciep1 = new ReciepeItem(meat, 1);
	ReciepeItem* reciep2 = new ReciepeItem(spice, 1);
	ReciepeItem* reciep3 = new ReciepeItem(cheese, 1);
	ReciepeItem* reciep4 = new ReciepeItem(tomato, 1);
	ReciepeItem** items = new ReciepeItem * [5]{ reciep,reciep1,reciep2,reciep3,reciep4 };
	ReciepeItem** items1 = new ReciepeItem * [4]{ reciep,reciep1,reciep2,reciep3 };
	ReciepeItem** items2 = new ReciepeItem * [3]{ reciep,reciep1,reciep2 };
	//Meals
	Meal* meal = new Meal(items, 5, "Dolma");
	Meal* meal1 = new Meal(items1, 4, "Pizza");
	Meal* meal2 = new Meal(items2, 3, "Bozbash");
	Meal** meals = new Meal * [3]{ meal,meal1,meal2 };
	//Tables
	Table* table1 = new Table("1)T-1", false);
	Table* table2 = new  Table("2)T-2", false);
	Table* table3 = new Table("3)T-3", false);
	Table* table4 = new Table("4)T-4", false);
	Table** tables = new Table * [4]{ table1,table2,table3,table4 };
	//Restoran
	Restourant* restourant = new Restourant("Restourant Unity", "Yasamal", "Baku", admins, tables);
	//Stock
	Stock* stock = new Stock(items, 5);
	//Kitchen
	Kitchen* kitchen = new Kitchen(items, 5, meals, 3);
	//Datebase
	DateBase* datebase = new DateBase(admins, tables, meals);
	short choose = 0;
	short selectTable = 0;
	short chooseadmin;
	short chooseMenu;
	short chooseBack;

	string addchoose;
	int choosekitchen;
	int selection;
	void kitchenMenu() {
		system("Color E4");
		if (chooseadmin == 2) {
			cout << "1)Show all orders" << endl;
			cout << "2)Accept Orders" << endl;
			cout << "3)Cancel Orders" << endl;
			cout << "4)Show all Meals" << endl;
			cout << "5)Add Meal" << endl;
			cout << "6)Delete Meal" << endl;
			cout << "7)Update Meal" << endl;
			cout << "8)Stock" << endl;
			cout << "9)Show all notifications" << endl;
			cout << "10)Back to main menu" << endl;
			cout << "Your Selection : \n";
			cin >> choosekitchen;
			if (choosekitchen == 1) {
				kitchen->showOrders();
				FileHelper::Append_file_in_text_format("error.log", "Admin saw order\n");
				wrongChoiceKitchen();
			}
			else if (choosekitchen == 2) {
				if (kitchen->getOrderCount() != 0)
				{
					cout << "===========Orders===========" << endl;
					kitchen->showOrders();
					int id;
					cout << "Input ID : ";
					cin >> id;
					kitchen->accaptedOrder(id);
					Notification* notification = new Notification("Kitchen", __DATE__, "Accepted order", tables[selectTable - 1]->getNo());
					tables[selectTable - 1]->addNotification(notification);
					FileHelper::Append_file_in_text_format("error.log", "Accapted Order\n");
				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
					cout << "Order not yet..." << endl;
					Sleep(1000);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
					system("cls");
					kitchenMenu();
				}
			}
			else if (choosekitchen == 3) {
				if (kitchen->getOrderCount() != 0)
				{
					cout << "===========Orders===========" << endl;
					kitchen->showOrders();
					int id;
					cout << "Input ID : ";
					cin >> id;
					kitchen->cancelOrder(id);
					FileHelper::Append_file_in_text_format("error.log", "Canceled Order\n");
					Notification* notification = new Notification("Kitchen", __DATE__, "Order Canceled", tables[selectTable - 1]->getNo());
					tables[selectTable - 1]->addNotification(notification);
				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
					cout << "Order not yet..." << endl;
					Sleep(1000);
					system("cls");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
					kitchenMenu();
				}
			}
			else if (choosekitchen == 4) {
				cout << "===========Meals Info===========" << endl;
				kitchen->showAllMeals();
				FileHelper::Append_file_in_text_format("error.log", "Admin saw dishes\n");
				wrongChoiceKitchen();
			}
			else if (choosekitchen == 5) {
				stock->showDetail();
				string name;
				cout << "Input Meal name : " << endl;
				cin >> name;
				short id;
				int count = 0;
				cout << "How many Ingredient you want add your Meal?" << endl;
				cin >> count;
				for (size_t i = 0; i < count; i++)
				{
					cout << "Input ID : " << endl;
					cin >> id;
					ReciepeItem** items1 = new ReciepeItem * [count] {items[id - 1]};
				}
				Meal* meal = new Meal(items1, count, name);
				kitchen->addMeals(meal);
				FileHelper::Append_file_in_text_format("error.log", "Meals added\n");
				wrongChoiceKitchen();
			}
			else if (choosekitchen == 6) {
				kitchen->showAllMeals();
				short id;
				cout << "Input ID : " << endl;
				cin >> id;
				kitchen->deleteMeal(id - 1);
				FileHelper::Append_file_in_text_format("error.log", "Meals deleted\n");
				wrongChoiceKitchen();
			}
			else if (choosekitchen == 7) {
				kitchen->showAllMeals();
				cout << "Enter The ID : " << endl;
				short id;
				cin >> id;
				kitchen->UpdateMeal(id);
				FileHelper::Append_file_in_text_format("error.log", "Meals updated\n");
				wrongChoiceKitchen();
			}
			else if (choosekitchen == 8) {
				cout << "===========Detail Show===========" << endl;
				stock->showDetail();
				FileHelper::Append_file_in_text_format("error.log", "Admin saw meals detailed\n");
				wrongChoiceKitchen();
			}
			else if (choosekitchen == 9)
			{
				if (kitchen->getNotificationCount()!=0)
				{
				kitchen->showNotifiactions();
				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
					cout << "Notification not yet..." << endl;
					Sleep(1000);
					system("cls");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
					kitchenMenu();
				}
			}
			else if (choosekitchen == 10)
			{
				system("cls");
				Start();
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
				cout << "Wrong choice!" << endl;
				cout << "Select : ";
				Sleep(1000);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
				system("cls");
				kitchenMenu();
			}
		}
	}
	void wrongAddChoice() {
		if (chooseBack == 1)
		{
			system("cls");
			stockMenu();
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
			cout << "Wrong choice!" << endl;
			cout << "Select : ";
			Sleep(1000);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			cin >> chooseBack;
			wrongAddChoice();
		}
	}
	void addAgain() {
		cout << "If you add ingredient again?(Yes/No)" << endl;
		cin >> addchoose;
		if (addchoose == "YES" || addchoose == "yes"||addchoose=="Yes") {
			while (true) {
				stock->addIngredientinStock();
				cout << "1)Back to Stock" << endl;
				cout << "2)Add again" << endl;
				cout << "Select : ";
				cin >> chooseBack;
				system("cls");
				if (chooseBack == 1)
				{
					stockMenu();
				}
				else if (chooseBack == 2)
				{
					addAgain();
				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
					cout << "Wrong choice!" << endl;
					cout << "Select : ";
					Sleep(1000);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
					cin >> chooseBack;
					wrongAddChoice();
				}
			}
		}
		else if (addchoose == "NO" || addchoose == "no"||addchoose=="No") {
			cout << "1)Back to Stock" << endl;
			cout << "Select : ";
			cin >> chooseBack;
			system("cls");
			while (true)
			{
				if (chooseBack == 1)
				{
					system("cls");
					stockMenu();
				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
					cout << "Wrong choice!" << endl;
					cout << "Select : ";
					Sleep(1000);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
					cin >> chooseBack;
					wrongAddChoice();
				}
			}
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
			cout << "Wrong choiche!" << endl;
			Sleep(1000);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			addAgain();
		}
	}
	void stockMenu() {
		system("Color E4");
		if (chooseadmin == 1) {
			cout << "1)Show All Ingredients" << endl;
			cout << "2)Add Ingredients" << endl;
			cout << "3)Increase ingredient amount" << endl;
			cout << "4)Decrease ingredient amount" << endl;
			cout << "5)Delete Ingredient" << endl;
			cout << "6)Back to main menu" << endl;
			cout << "7)Exit" << endl << endl;
			int admin1s;
			cout << "Select : ";
			cin >> admin1s;
			if (admin1s == 1) {
				system("cls");
				stock->show();
				FileHelper::Append_file_in_text_format("error.log", "Admin saw all ingredient\n");
				wrongChoiceStock();
			}
			else if (admin1s == 2) {
				int admin2s = 0;
				for (int i = 0; i < 5; i++)
				{
					items[i]->showDetail();
				}
				system("cls");
				stock->addIngredientinStock();
				FileHelper::Append_file_in_text_format("error.log", "Admin added new ingredient\n");
				addAgain();
			}
			else if (admin1s == 6) {
				system("cls");
				Start();
			}
			else if (admin1s == 7)
			{
				exit(-1);
			}
			else if (admin1s == 5) {
				int id2 = 0;
				system("cls");
				stock->showDetail();
				cout << "Input ID : " << endl;
				cin >> id2;
				stock->deleteIngredient(id2 - 1);
				FileHelper::Append_file_in_text_format("error.log", "Admin delete ingredient\n");
				wrongChoiceStock();
			}
			else if (admin1s == 3)
			{
				int id3;
				system("cls");
				cout << "What kind of ingredient ?" << endl;
				stock->showDetail();
				cout << "Input ID : ";
				cin >> id3;
				int increase = 0;
				cout << "Input amount : ";
				cin >> increase;
				stock->increaseIngredientCount(items[id3 - 1], increase);
				FileHelper::Append_file_in_text_format("error.log", "Admin increased ingredient count\n");
				wrongChoiceStock();
			}
			else if (admin1s == 4)
			{
				int id3;
				cout << "What kind of ingredient ?" << endl;
				stock->showDetail();
				cout << "Input ID : " << endl;
				cin >> id3;
				int decrease = 0;
				cout << "Input amount : " << endl;
				cin >> decrease;
				stock->decreaseIngredientCount(items[id3 - 1], decrease);
				FileHelper::Append_file_in_text_format("error.log", "Admin decreased ingredient count\n");
				wrongChoiceStock();
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
				cout << "Wrong choice!" << endl;
				Sleep(1000);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
				system("cls");
				stockMenu();
			}
		}
	};
	void adminSide() {
		system("Color E4");
		if (choose == 1) {
			string username;
			string password;
			cout << "Input username : ";
			cin >> username;
			cout << "Input Password : ";
			cin >> password;
			if (restourant->AdminCheck(username, password)) {
				FileHelper::Append_file_in_text_format("error.log", "Admin succesufuly loged in\n");
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
				cout << "Password is correct! " << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
				Sleep(2300);
				system("cls");
				system("Color E4");
				cout << "1)Stock" << endl;
				cout << "2)Kitchen" << endl;
				cout << "3)Exit" << endl;
				cout << "4)Back to main manu" << endl << endl;
				cout << "Select : " << endl;
				cin >> chooseadmin;
				if (chooseadmin == 4)
				{
					system("cls");
					Start();
				}
				else
				{
					if (chooseadmin == 1)
					{
						system("cls");
						stockMenu();
					}
					else if (chooseadmin == 2)
					{
						system("cls");
						kitchenMenu();
					}
					else if (chooseadmin == 3)
					{
						system("cls");
						exit(-1);
					}
					else if (chooseadmin == 4)
					{
						system("cls");
						Start();
					}
					else
					{
						Sleep(1000);
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
						cout << "Please login again!" << endl;
						Sleep(1000);
						system("cls");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
						adminSide();
					}
				}
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
				cout << "Incorrect Password" << endl;
				FileHelper::Append_file_in_text_format("error.log", "Admin entered incorrect password\n");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
				Sleep(1000);
				system("cls");
				adminSide();
			}
		}
	}
	void clientSide() {
		system("Color E4");
		if (choose == 2) {
			cout << "Please Choose Table" << endl;
			system("cls");
			for (int i = 0; i < 4; i++)
			{
				tables[i]->showTable();
			}
			cout << "Your selection : ";
			cin >> selectTable;
			if (selectTable <= 4)
			{
				if (tables[selectTable - 1]->checkTable(tables[selectTable - 1]) == false) {

					FileHelper::Append_file_in_text_format("error.log", "Client choosed table\n");
					system("cls");
					tables[selectTable - 1]->setIsEmpty(true);
					tables[selectTable - 1]->getIsEmpty() == true;
					clientMenu();
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
					cout << "Table is full please select another table" << endl;
					FileHelper::Append_file_in_text_format("error.log", "Client choosed table is full\n");
					Sleep(1000);
					system("cls");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
					clientSide();
				}
			}
			else
			{
				clientSide();
			}

		}
	}
	void wrongChoiceKitchen() {
		cout << endl << "1)Back to table" << endl;
		cout << "Select : ";
		cin >> chooseBack;
		system("cls");
		if (chooseBack == 1)
		{
			kitchenMenu();
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
			cout << "Wrong choice!" << endl;
			cout << "Backing menu..." << endl;
			Sleep(1500);
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			kitchenMenu();
		}
	}
	void wrongChoiceStock() {
		cout << endl << "1)Back to table" << endl;
		cout << "Select : ";
		cin >> chooseBack;
		system("cls");
		if (chooseBack == 1)
		{
			stockMenu();
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
			cout << "Wrong choice!" << endl;
			cout << "Backing menu..." << endl;
			Sleep(1500);
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			stockMenu();
		}
	}
	void wrongChoiceClient() {
		cout << endl << "1)Back to table" << endl;
		cout << "Select : ";
		cin >> chooseBack;
		system("cls");
		if (chooseBack == 1)
		{
			clientMenu();
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
			cout << "Wrong choice!" << endl;
			cout << "Backing menu..." << endl;
			Sleep(1500);
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			clientMenu();
		}
	}
	void clientMenu() {
		system("Color E4");
		cout << "1)Order" << endl;
		cout << "2)Exit restoran" << endl;
		cout << "3)Show detail meal" << endl;
		cout << "4)Back" << endl;
		cout << "5)Search meal" << endl;
		cout << "6)Show notifications" << endl;
		cout << "7)Show menu" << endl;
		cout << "Select : ";
		cin >> selection;
		if (selection == 1) {
			kitchen->showAllMeals();
			cout << "Please input you favorite meals ID : " << endl;
			int chooseMeal;
			cin >> chooseMeal;
			cout << "Do you want add Ingredient?(Yes/No)" << endl;
			string add;
			cin >> add;
			if (add == "YES") {
				int ig = 0;
				for (int i = 0; i < 5; i++)
				{
					items[i]->showDetail();
				}
				cout << "Input ID : ";
				cin >> ig;
				meals[chooseMeal - 1]->addIngredient(items[ig - 1]);
				cout << meals[chooseMeal - 1]->getName() << "is Cooked" << endl;
				FileHelper::Append_file_in_text_format("error.log", "Client meal order\n");
				Notification* notification = new Notification("Client side", __DATE__, meals[chooseMeal - 1]->getName(), tables[selectTable - 1]->getNo());
				kitchen->addNotfication(notification);
				double rating;
				cout << "Please rate the food[1-5]" << endl;
				cin >> rating;
				cout << "Thank For Order" << endl;
				system("cls");
				meals[chooseMeal - 1]->showDetail();
			}
			else {
				system("cls");
				Order* order = new Order(tables[selectTable - 1]->getNo(), meals[chooseMeal - 1], 1);
				kitchen->addOrders(order);
				FileHelper::Append_file_in_text_format("error.log", "Client ordered meal\n");
				Notification* notification = new Notification("Client side", __DATE__, meals[chooseMeal - 1]->getName(), tables[selectTable - 1]->getNo());
				int ingAmount = meal[chooseMeal - 1].getIngredientCount();
				kitchen->addNotfication(notification);
				double rating;
				cout << "Please rate the food[1-5]" << endl;
				cin >> rating;
				cout << "Thanks For Order" << endl;
				system("cls");
				Start();
			}
		}
		else if (selection == 2) {
			system("cls");
			cout << "Thanks for your choiche see you later!" << endl;
			exit(-1);
		}
		else if (selection == 3)
		{
			kitchen->showAllMeals();
			int id;
			cout << "Enter ID : ";
			cin >> id;
			for (int i = 0; i < 3; i++)
			{
				datebase->showDetailMealsWithId(id);
				FileHelper::Append_file_in_text_format("error.log", "Client saw meal detailed\n");
			}
			wrongChoiceClient();
		}
		else if (selection == 4)
		{
			system("cls");
			tables[selectTable - 1]->setIsEmpty(false);
			clientSide();
		}
		else if (selection == 5)
		{
			string name;
			cout << "Enter name : " << endl;
			cin >> name;
			kitchen->searchMeal(name);
			wrongChoiceClient();
		}
		else if (selection == 6)
		{
			if (tables[selectTable - 1]->getNotificationCount() != 0)
			{
				tables[selectTable - 1]->showNotification();
				wrongChoiceClient();
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
				cout << "Notification not found" << endl;
				Sleep(1000);
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
				clientMenu();
			}
		}
		else if (selection == 7)
		{
			kitchen->showAllMeals();
			wrongChoiceClient();
		}
	}
	void Start() {
		system("Color E4");
		cout << "\t\t\t\t\t================WELCOME===============" << endl << endl;
		cout << "\t\t\t\t\t1)Admin";
		cout << "\t\t2)Client";
		cout << "\t3)Exit" << endl << endl;
		cout << "\t\t\t\t\t\t\tSelect :";
		cin >> choose;
		if (choose == 1)
		{
			system("cls");
			adminSide();
		}
		else if (choose == 2)
		{
			system("cls");
			clientSide();
		}
		else if (choose == 3)
		{
			system("cls");
			exit(-1);
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
			cout << "Wrong choice!" << endl;
			cout << "Select : ";
			Sleep(1000);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			system("cls");
			Start();
		}
	}
};