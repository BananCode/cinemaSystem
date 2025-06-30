#include <iostream>
#include "menu.h"
#include "film.h"
#include "hall.h"
#include "session.h"
#include "ticket.h"
#include "colors.h"

int main()
{
	int choice;
	do
	{
		mainMenu();
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			manageFilmsMenu();
			break;
		case 2:
			manageHallMenu();
			break;
		case 3:
			manageSessionMenu();
			break;
		case 4:
			manageTicketsMenu();
			break;
		case 0:
			std::cout << GREEN;
			std::cout << "Вихід з програми... До зустрічі 👋\n";
			std::cout << "Гарного дня!\n";
			std::cout << RESET;
			break;
		default:
			std::cout << RED << "Невірний вибір. Спробуйте ще раз.\n";
			break;
		}
	} while (choice != 0);

	return 0;
}
