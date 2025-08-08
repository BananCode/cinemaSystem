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
	int mainMenuChoice;
	
	do
	{
		mainMenu();
		while (!(std::cin >> mainMenuChoice)) 
		{																		// Перевіряємо, чи введено число
			std::cout << RED << "Помилка! Введіть ціле число: " << RESET;
			std::cin.clear();                                                   // Очищаємо стан помилки
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаємо буфер
		}

		switch (mainMenuChoice)
		{
		case 1:
			manageFilmsMenu(films);
			break;
		case 2:
			manageHallMenu(halls);
			break;
		case 3:
			manageSessionMenu(sessions);
			break;
		case 4:
			manageTicketsMenu(tickets, sessions);
			break;
		case 5:
			showAllData(films, halls, sessions, tickets);
			break;
		case 6:
			loadDemoData(films, halls, sessions, tickets);
                std::cout << CYAN << "\nДемо-дані завантажено.\n" << RESET;
			break;
		case 7:
			saveAllData(films, halls, sessions, tickets);
			std::cout << CYAN << "\nДані успішно збережено!\n" << RESET;
			break;
		case 8:
			loadAllData(films, halls, sessions, tickets);
			std::cout << CYAN << "\nДані успішно завантажено!\n" << RESET;
			break;
		case 0:
			std::cout << YELLOW << "\nВихід з програми... До зустрічі 👋\n";
			std::cout << "Гарного дня!\n" << RESET;
			break;
		default:
			std::cout << RED << "Невірний вибір. Спробуйте ще раз.\n" << RESET;
			break;
		}
	} while (mainMenuChoice != 0);

	return 0;
}
