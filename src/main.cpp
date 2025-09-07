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
        while (true)
        {
            std::cin >> mainMenuChoice;
            if (std::cin.fail())
            {
                std::cout << RED << "Error: Enter an integer!\n" << RESET;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else
                break;
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
            std::cout << CYAN << "\nDemo data loaded successfully.\n" << RESET;
            break;
        case 7:
            saveAllData(films, halls, sessions, tickets);
            std::cout << CYAN << "\nData saved successfully!\n" << RESET;
            break;
        case 8:
            loadAllData(films, halls, sessions, tickets);
            std::cout << CYAN << "\nData loaded successfully!\n" << RESET;
            break;
        case 0:
            std::cout << YELLOW << "\nExiting program... Goodbye 👋\n";
            std::cout << "Have a nice day!\n" << RESET;
            break;
        default:
            std::cout << RED << "Invalid choice. Try again.\n" << RESET;
            break;
        }
    } while (mainMenuChoice != 0);

    return 0;
}
