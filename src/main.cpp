#include <iostream>
#include "menu.h"
#include "film.h"
#include "hall.h"
#include "session.h"
#include "ticket.h"
#include "demo.h"
#include "dataView.h"
#include "colors.h"

int main()
{
	std::vector<Film> films;
	std::vector<Hall> halls;
	std::vector<Session> sessions;
	std::vector<Ticket> tickets;
	int choice;
	
	do
	{
		mainMenu();
		while (!(std::cin >> choice)) {						    // Перевіряємо, чи введено число
			std::cout << RED << "Помилка! Введіть ціле число: " << RESET;
			std::cin.clear();                                                   // Очищаємо стан помилки
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаємо буфер
		}

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
		case 5:
			break;
		case 6:
			showAllData(films, halls, sessions, tickets);
			break;
		case 7:
			loadDemoData(films, halls, sessions, tickets);
                std::cout << CYAN << "\nДемо-дані завантажено." << RESET << std::endl;
			break;
		case 0:
			std::cout << YELLOW;
			std::cout << "\nВихід з програми... До зустрічі 👋\n";
			std::cout << "Гарного дня!\n";
			std::cout << RESET;
			break;
		default:
			std::cout << RED;
			std::cout << "Невірний вибір. Спробуйте ще раз.\n";
			std::cout << RESET;
			break;
		}
	} while (choice != 0);

	return 0;
}
