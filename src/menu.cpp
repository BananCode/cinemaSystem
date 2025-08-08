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
    std::cout << BOLD << YELLOW << "\n=== Головне меню ===\n" << RESET;
    std::cout << GREEN << "1. Керування фільмами\n";
    std::cout << "2. Керування залами\n";
    std::cout << "3. Керування сеансами\n";
    std::cout << "4. Керування квитками\n";
    std::cout << "5. Огляд данних\n";
    std::cout << "6. Завантажити демо-дані\n";
    std::cout << "7. Зберегти дані\n";
    std::cout << "0. Вихід\n" << RESET;
    std::cout << YELLOW  << "Ваш вибір: " << RESET;
}

void manageFilmsMenu(std::vector<Film>& films)
{
    int choice;
    do 
    {
        std::cout << BOLD << YELLOW << "\n== Керування фільмами ==\n" << RESET;
        std::cout << GREEN << "1. Додати фільм\n";
        std::cout << "2. Переглянути всі фільми\n";
        std::cout << "3. Редагувати фільм за ID\n";
        std::cout << "4. Видалити фільм за ID\n";
        std::cout << "0. Назад\n" << RESET;
        std::cout << YELLOW << "Ваш вибір: " << RESET;
       
        while (!(std::cin >> choice)) 
        {                                                                       // Перевіряємо, чи введено число
            std::cout << RED << "Помилка! Введіть ціле число: " << RESET;
            std::cin.clear();                                                   // Очищаємо стан помилки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаємо буфер
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
        case 0:
            std::cout << MAGENTA << "Повернення до головного меню...\n" << RESET;
            break;
        default:
            std::cout << RED << "Невірний вибір. Спробуйте ще раз.\n" << RESET;
            break;
        }
    } while (choice != 0);
}

void manageHallMenu(std::vector<Hall>& halls)
{
    int choice;
    do 
    {
        std::cout << BOLD << YELLOW << "\n== Керування залами ==\n" << RESET;
        std::cout << GREEN << "1. Додати зал\n";
        std::cout << "2. Переглянути всі зали\n";
        std::cout << "3. Редагувати зали за ID\n";
        std::cout << "4. Видалити зал за ID\n";
        std::cout << "0. Назад\n" << RESET;
        std::cout << YELLOW << "Ваш вибір: " << RESET;
        
        while (!(std::cin >> choice)) 
        {                                                                        // Перевіряємо, чи введено число
            std::cout << RED << "Помилка! Введіть ціле число: " << RESET;
            std::cin.clear();                                                   // Очищаємо стан помилки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаємо буфер
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
        case 0:
            std::cout << MAGENTA << "Повернення до головного меню...\n" << RESET;
            break;
        default:
            std::cout << RED << "Невірний вибір. Спробуйте ще раз.\n" << RESET;
            break;
        }
    } while (choice != 0);
}

void manageSessionMenu(std::vector<Session>& sessions)
{
    int choice;
    do 
    {
        std::cout << BOLD << YELLOW << "\n== Керування сеансами ==\n" << RESET;
        std::cout << GREEN << "1. Додати сенс\n";
        std::cout << "2. Переглянути всі сеанси\n";
        std::cout << "3. Редагувати сеанси за ID\n";
        std::cout << "4. Видалити сеанси за ID\n";
        std::cout << "0. Назад\n" << RESET;
        std::cout << YELLOW << "Ваш вибір: " << RESET;
       
        while (!(std::cin >> choice)) 
        {                                                                       // Перевіряємо, чи введено число
            std::cout << RED << "Помилка! Введіть ціле число: " << RESET;
            std::cin.clear();                                                   // Очищаємо стан помилки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаємо буфер
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
        case 0:
            std::cout << MAGENTA << "Повернення до головного меню...\n" << RESET;
            break;
        default:
            std::cout << RED << "Невірний вибір. Спробуйте ще раз.\n" << RESET;
            break;
        }
    } while (choice != 0);
}

void manageTicketsMenu(std::vector<Ticket>& tickets, std::vector<Session>& sessions) 
{
    int choice;
    do {
        std::cout << BOLD << YELLOW << "\n== Керування квитками ==\n" << RESET;
        std::cout << GREEN << "1. Додати квиток\n";
        std::cout << "2. Переглянути всі квитки\n";
        std::cout << "3. Редагувати квиток за ID\n";
        std::cout << "4. Видалити квиток за ID\n";
        std::cout << "0. Назад\n" << RESET;
        std::cout << YELLOW << "Ваш вибір: " << RESET;
        
        while (!(std::cin >> choice)) 
        {
            std::cout << RED << "Помилка! Введіть ціле число: " << RESET;
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
        case 0:
            std::cout << MAGENTA << "Повернення до головного меню...\n" << RESET;
            break;
        default:
            std::cout << RED << "Невірний вибір. Спробуйте ще раз.\n" << RESET;
            break;
        }
    } while (choice != 0);
}
