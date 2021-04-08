#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>
#include <cstdlib>
#include "Adminside.h"
#include "Exception.h"
#include "Base.h"
#include "ItemBase.h"
#include "Ingredient.h"
#include "RecipeItem.h"
#include "Global.V.h"
#include "Meal.h"
#include "MealItem.h"
#include "Order.h"
#include "Notification.h"
#include "Table.h"
#include "Datebase.h"
#include "Restourant.h"
#include "Stock.h"
#include "Kitchen.h"
#include "FileHelper.h"
#include "Console.h"





using namespace std;

using namespace Exception;

using namespace Adminside;

int Ingredient::ingredietnid = 0;
int Meal::id = 0;
int Admin::adminId = 0;
int Order::id = 0;


void main()
{
	system("Color E4");
	HWND hwnd = GetConsoleWindow();
	HMENU hmenu = GetSystemMenu(hwnd, FALSE);
	EnableMenuItem(hmenu, SC_CLOSE, MF_GRAYED);
	Console c;
	try
	{
		c.Start();
	}
	catch (...)
	{
		cout << "Exception occured" << endl;
	}
}