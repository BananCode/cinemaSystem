#include "iostream"
#include "menu.h"
#include "colors.h"

void showMenu()
{
	std::cout << "=== Меню ===\n";
	std::cout << "0. Вихід\n";
	std::cout << "Ваш вибір: ";
}

int getUserChoice()
{
	int choice;

	do
	{
		std::cin >> choice;
		if (std::cin.fail() || choice < 0 || choice > 3)
		{
			std::cin.clear();
			std::cout << RED << "Помилка! Не коректнмй вибір виберіть функцію від 0 до 3: " << RESET;
		}
	} while (std::cin.fail() || choice < 0 || choice > 3);
	
	return choice;
}
