#include <iostream>
#include <vector>
#include "menu.h"
#include "film.h"
#include "hall.h"
#include "session.h" 
#include "ticket.h"
#include "colors.h"

void mainMenu()
{
    std::cout << BOLD << YELLOW << "\n=== Main Menu ===\n" << RESET;
    std::cout << GREEN << "1. Manage Films\n";
    std::cout << "2. Manage Halls\n";
    std::cout << "3. Manage Sessions\n";
    std::cout << "4. Manage Tickets\n";
    std::cout << "5. View Data\n";
    std::cout << "6. Load Demo Data\n";
    std::cout << "7. Save Data\n";
    std::cout << "8. Load Data\n";
    std::cout << "0. Exit\n" << RESET;
    std::cout << YELLOW << "Your choice: " << RESET;
}

void manageFilmsMenu(std::vector<Film>& films)
{
    int choice;
    do
    {
        std::cout << BOLD << YELLOW << "\n== Manage Films ==\n" << RESET;
        std::cout << GREEN << "1. Add Film\n";
        std::cout << "2. View All Films\n";
        std::cout << "3. Edit Film by ID\n";
        std::cout << "4. Delete Film by ID\n";
        std::cout << "5. Search Films\n";
        std::cout << "0. Back\n" << RESET;
        std::cout << YELLOW << "Your choice: " << RESET;

        while (!(std::cin >> choice))
        {
            std::cout << RED << "Error: Enter an integer!\n" << RESET;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (choice)
        {
        case 1:
            addFilm(films);
            break;
        case 2:
            showFilms(films);
            break;
        case 3:
            editFilmById(films);
            break;
        case 4:
            removeFilmById(films);
            break;
        case 5:
            searchFilmsById(films);
            break;
        case 0:
            std::cout << MAGENTA << "Returning to main menu...\n" << RESET;
            break;
        default:
            std::cout << RED << "Invalid choice. Try again.\n" << RESET;
            break;
        }
    } while (choice != 0);
}

void manageHallMenu(std::vector<Hall>& halls)
{
    int choice;
    do
    {
        std::cout << BOLD << YELLOW << "\n== Manage Halls ==\n" << RESET;
        std::cout << GREEN << "1. Add Hall\n";
        std::cout << "2. View All Halls\n";
        std::cout << "3. Edit Hall by ID\n";
        std::cout << "4. Delete Hall by ID\n";
        std::cout << "5. Search Halls\n";
        std::cout << "0. Back\n" << RESET;
        std::cout << YELLOW << "Your choice: " << RESET;

        while (!(std::cin >> choice))
        {
            std::cout << RED << "Error: Enter an integer!\n" << RESET;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (choice)
        {
        case 1:
            addHall(halls);
            break;
        case 2:
            showHalls(halls);
            break;
        case 3:
            editHallById(halls);
            break;
        case 4:
            removeHallById(halls);
            break;
        case 5:
            searchHallsById(halls);
            break;
        case 0:
            std::cout << MAGENTA << "Returning to main menu...\n" << RESET;
            break;
        default:
            std::cout << RED << "Invalid choice. Try again.\n" << RESET;
            break;
        }
    } while (choice != 0);
}

void manageSessionMenu(std::vector<Session>& sessions)
{
    int choice;
    do
    {
        std::cout << BOLD << YELLOW << "\n== Manage Sessions ==\n" << RESET;
        std::cout << GREEN << "1. Add Session\n";
        std::cout << "2. View All Sessions\n";
        std::cout << "3. Edit Session by ID\n";
        std::cout << "4. Delete Session by ID\n";
        std::cout << "5. Search Sessions\n";
        std::cout << "0. Back\n" << RESET;
        std::cout << YELLOW << "Your choice: " << RESET;

        while (!(std::cin >> choice))
        {
            std::cout << RED << "Error: Enter an integer!\n" << RESET;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (choice)
        {
        case 1:
            addSession(sessions);
            break;
        case 2:
            showSession(sessions);
            break;
        case 3:
            editSessionById(sessions);
            break;
        case 4:
            removeSessionById(sessions);
            break;
        case 5:
            searchSessionsById(sessions);
            break;
        case 0:
            std::cout << MAGENTA << "Returning to main menu...\n" << RESET;
            break;
        default:
            std::cout << RED << "Invalid choice. Try again.\n" << RESET;
            break;
        }
    } while (choice != 0);
}

void manageTicketsMenu(std::vector<Ticket>& tickets, std::vector<Session>& sessions)
{
    int choice;
    do {
        std::cout << BOLD << YELLOW << "\n== Manage Tickets ==\n" << RESET;
        std::cout << GREEN << "1. Add Ticket\n";
        std::cout << "2. View All Tickets\n";
        std::cout << "3. Edit Ticket by ID\n";
        std::cout << "4. Delete Ticket by ID\n";
        std::cout << "5. Search Tickets\n";
        std::cout << "0. Back\n" << RESET;
        std::cout << YELLOW << "Your choice: " << RESET;

        while (!(std::cin >> choice))
        {
            std::cout << RED << "Error: Enter an integer!\n" << RESET;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (choice)
        {
        case 1:
            addTicket(tickets, sessions);
            break;
        case 2:
            showTicket(tickets);
            break;
        case 3:
            editTicketById(tickets);
            break;
        case 4:
            removeTicketById(tickets);
            break;
        case 5:
            searchTicketsById(tickets);
            break;
        case 0:
            std::cout << MAGENTA << "Returning to main menu...\n" << RESET;
            break;
        default:
            std::cout << RED << "Invalid choice. Try again.\n" << RESET;
            break;
        }
    } while (choice != 0);
}
