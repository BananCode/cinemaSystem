#include "iostream"
#include "menu.h"
#include "film.h"
#include "hall.h"
#include "colors.h"

void mainMenu()
{
    std::cout << BOLD << YELLOW << "\n=== Головне меню ===\n" << RESET;
    std::cout << GREEN;
    std::cout << "1. Керування фільмами\n";
    std::cout << "2. Керування залами\n";
    std::cout << "3. Керування сеансами\n";
    std::cout << "4. Керування квитками\n";
    std::cout << "5. Пошук і сортування\n";
    std::cout << "6. Огляд данних\n";
    std::cout << "7. Завантажити демо-дані\n";
    std::cout << "0. Вихід\n";
    std::cout << RESET;
    std::cout << YELLOW  << "Ваш вибір: " << RESET;
}

void manageFilmsMenu()
{
    int choice;
    do 
    {
        std::cout << BOLD << YELLOW;
        std::cout << "\n== Керування фільмами ==\n";
        std::cout << RESET;
        std::cout << "1. Додати фільм\n";
        std::cout << "2. Переглянути всі фільми\n";
        std::cout << "3. Редагувати фільм за ID\n";
        std::cout << "4. Видалити фільм за ID\n";
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
            std::cout << RED;
            std::cout << "Невірний вибір. Спробуйте ще раз.\n";
            std::cout << RESET;
            break;
        }
    } while (choice != 0);
}

void manageHallMenu()
{
    int choice;
    do 
    {
        std::cout << BOLD << YELLOW;
        std::cout << "\n== Керування залами ==\n";
        std::cout << RESET;
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

void manageSessionMenu()
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
            std::cout << "Додаємо сенс\n";
            break;
        case 2:
            std::cout << "Переглядаємо всі сеанси\n";
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

void manageTicketsMenu()
{
    int choice;
    do 
    {
        std::cout << BOLD << YELLOW;
        std::cout << "\n== Керування квитками ==\n";
        std::cout << RESET;
        std::cout << "1. Додати квиток\n";
        std::cout << "2. Переглянути квитки\n";
        std::cout << "3. Редагувати квиток за ID\n";
        std::cout << "4. Видалити квиток за ID\n";
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
            std::cout << "Функція додавання квитка (поки не реалізована)\n";
            break;
        case 2:
            std::cout << "Функція перегляду квитків (поки не реалізована)\n";
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
            std::cout << RED;
            std::cout << "Невірний вибір. Спробуйте ще раз.\n";
            std::cout << RESET;
            break;
        }
    } while (choice != 0);
}
