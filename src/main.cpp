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
		showMenu();
		choice = getUserChoice();

		switch (choice)
		{
		case 1:
			std::cout << "лввввв\n";
			break;
		default:
			std::cout << RED << "Помилка! Ви вибрали не вірну опцію повторіть знову\n" << RESET;
			break;
		}
	} while (choice != 0);

	return 0;
}
