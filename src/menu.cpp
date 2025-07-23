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
    std::cout << "5. Пошук і сортування\n";
    std::cout << "6. Огляд данних\n";
    std::cout << "7. Завантажити демо-дані\n";
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
       
        while (!(std::cin >> choice)) {                                         // Перевіряємо, чи введено число
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
            std::cout << "Редагуємо за айді\n";
            break;
        case 4: 
            std::cout << "Видаляємо за айді\n";
            break;
        case 0:
            std::cout << "Повернення до головного меню...\n";
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
        std::cout << "1. Додати зал\n";
        std::cout << "2. Переглянути всі зали\n";
        std::cout << "3. Редагувати залу за ID\n";
        std::cout << "4. Видалити залу за ID\n";
        std::cout << "0. Назад\n";
        std::cout << "Ваш вибір: ";
        
        while (!(std::cin >> choice)) {                                         // Перевіряємо, чи введено число
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
            showHall(halls);
            break;
        case 3:
            std::cout << "Редагуємо за айді\n";
            break;
        case 4: 
            std::cout << "Видаляємо за айді\n";
            break;
        case 0:
            std::cout << "Повернення до головного меню...\n";
            break;
        default:
            std::cout << RED;
            std::cout << "Невірний вибір. Спробуйте ще раз.\n";
            std::cout << RESET;
            break;
        }
    } while (choice != 0);
}

void manageSessionMenu(std::vector<Session>& sessions)
{
    int choice;
    do 
    {
        std::cout << BOLD << YELLOW;
        std::cout << "\n== Керування сеансами ==\n";
        std::cout << RESET;
        std::cout << "1. Додати сенс\n";
        std::cout << "2. Переглянути всі сеанси\n";
        std::cout << "3. Редагувати сеанси за ID\n";
        std::cout << "4. Видалити сеанси за ID\n";
        std::cout << "0. Назад\n";
        std::cout << "Ваш вибір: ";
        while (!(std::cin >> choice)) {                                         // Перевіряємо, чи введено число
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
            std::cout << "Редагуємо за айді\n";
            break;
        case 4: 
            std::cout << "Видаляємо за айді\n";
            break;
        case 0:
            std::cout << "Повернення до головного меню...\n";
            break;
        default:
            std::cout << RED << "Невірний вибір. Спробуйте ще раз.\n" << RESET;
            break;
        }
    } while (choice != 0);
}
void manageTicketsMenu(std::vector<Ticket>& tickets, std::vector<Session>& sessions) {
    int choice;
    Session* selectedSession = nullptr; 
 
    do {
        std::cout << BOLD << YELLOW << "\n== Керування квитками ==\n" << RESET;
        std::cout << "1. Додати квиток\n";
        std::cout << "2. Переглянути всі квитки\n";
        std::cout << "3. Редагувати квиток за ID\n";
        std::cout << "4. Видалити квиток за ID\n";
        std::cout << "0. Назад\n";
        std::cout << "Ваш вибір: ";
        
        while (!(std::cin >> choice)) {
            std::cout << RED << "Помилка! Введіть ціле число: " << RESET;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (choice) {
        case 1: {
            int ticketId, seatNum;
            std::cout << "Введіть ID квитка: ";
            std::cin >> ticketId;
            std::cout << "Введіть номер місця: ";
            std::cin >> seatNum;

            if (sessions.empty()) {
                std::cout << RED << "Немає сеансів!" << RESET << std::endl;
                break;
            }

            std::cout << "Введіть ID сеансу: ";
            int sessionId;
            std::cin >> sessionId;

            selectedSession = nullptr;
            for (auto& session : sessions) {
                if (session.sessionId == sessionId) {
                    selectedSession = &session;
                    break;
                }
            }

            if (!selectedSession) {
                std::cout << RED << "Сеанс не знайдено!" << RESET << std::endl;
                break;
            }

            addTicket(tickets, ticketId, selectedSession, seatNum);
            break;
        }
        case 2:
            showTickets(tickets);
            break;
        case 3:
            std::cout << "Функція редагування квитка (поки не реалізована)\n";
            break;
        case 4:
            std::cout << "Функція видалення квитка (поки не реалізована)\n";
            break;
        case 0:
            std::cout << "Повернення до головного меню...\n";
            break;
        default:
            std::cout << RED << "Невірний вибір. Спробуйте ще раз.\n" << RESET;
            break;
        }
    } while (choice != 0);
}
