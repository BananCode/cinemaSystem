#include "iostream"
#include "menu.h"
#include "colors.h"

int getUserChoice()
{
    int choice;

    do
    {
        std::cin >> choice;
        if (std::cin.fail() || choice < 0 || choice > 5)
        {
            std::cin.clear();
            std::cout << "Помилка! Не коректнмй вибір виберіть функцію від 0 до 5: ";
        }
    } while (std::cin.fail() || choice < 0 || choice > 5);

    return choice;
}

void mainMenu()
{
    std::cout << BOLD << GREEN << "\n=== Головне меню ===\n" << RESET;
    std::cout << CYAN << "1. Керування фільмами\n";
    std::cout << "2. Керування залами\n";
    std::cout << "3. Керування сеансами\n";
    std::cout << "4. Керування квитками\n";
    std::cout << "5. Пошук і сортування\n";
    std::cout << "0. Вихід\n" << RESET;
    std::cout << GREEN << UNDERLINE << "Ваш вибір: " << RESET;
}

void manageFilmsMenu()
{
    int choice;
    do 
    {
        std::cout << "\n== Керування фільмами ==\n";
        std::cout << "1. Додати фільм\n";
        std::cout << "2. Переглянути всі фільми\n";
        std::cout << "3. Редагувати фільм за ID\n";
        std::cout << "4. Видалити фільм за ID\n";
        std::cout << "0. Назад\n";
        std::cout << "Ваш вибір: ";
        std::cin >> choice;

        switch (choice) 
        {
        case 1:
            std::cout << "Додаємо фільм\n";
            break;
        case 2:
            std::cout << "Переглядаємо всі фільми\n";
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
            std::cout << "Невірний вибір. Спробуйте ще раз.\n";
            break;
        }
    } while (choice != 0);
}

void manageHallMenu()
{
    int choice;
    do 
    {
        std::cout << "\n== Керування залами ==\n";
        std::cout << "1. Додати зал\n";
        std::cout << "2. Переглянути всі зали\n";
        std::cout << "3. Редагувати залу за ID\n";
        std::cout << "4. Видалити залу за ID\n";
        std::cout << "0. Назад\n";
        std::cout << "Ваш вибір: ";
        std::cin >> choice;

        switch (choice) 
        {
        case 1:
            std::cout << "Додаємо зал\n";
            break;
        case 2:
            std::cout << "Переглядаємо всі зали\n";
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
            std::cout << "Невірний вибір. Спробуйте ще раз.\n";
            break;
        }
    } while (choice != 0);
}

void manageSessionMenu()
{
    int choice;
    do 
    {
        std::cout << "\n== Керування сеансами ==\n";
        std::cout << "1. Додати сенс\n";
        std::cout << "2. Переглянути всі сеанси\n";
        std::cout << "3. Редагувати сеанси за ID\n";
        std::cout << "4. Видалити сеанси за ID\n";
        std::cout << "0. Назад\n";
        std::cout << "Ваш вибір: ";
        std::cin >> choice;

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
            std::cout << "Невірний вибір. Спробуйте ще раз.\n";
            break;
        }
    } while (choice != 0);
}

void manageTicketsMenu()
{
    int choice;
    do 
    {
        std::cout << "\n== Керування квитками ==\n";
        std::cout << "1. Додати квиток\n";
        std::cout << "2. Переглянути квитки\n";
        std::cout << "3. Редагувати квиток за ID\n";
        std::cout << "4. Видалити квиток за ID\n";
        std::cout << "0. Назад\n";
        std::cout << "Ваш вибір: ";
        std::cin >> choice;

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
            std::cout << "Невірний вибір. Спробуйте ще раз.\n";
            break;
        }
    } while (choice != 0);
}
