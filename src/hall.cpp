#include "hall.h"
#include <iostream>
#include <iomanip>
#include "colors.h"

std::vector<Hall> halls;

void addHall(std::vector<Hall>& halls)
{
    Hall newHall;
    bool isUnique = false;

    std::cin.ignore();
    std::cout << BOLD << YELLOW << "\n=== Додавання нового залу ===\n" << RESET;
    std::cout << CYAN << "Введіть назву залу: " << RESET;
    while (true)
    {
        std::getline(std::cin, newHall.hallName);
        if (newHall.hallName.empty())
        {
            std::cout << RED << "Помилка: назва залу не може бути порожньою!\n" << RESET;
            std::cout << CYAN << "Введіть назву залу: " << RESET;
        }
        else
            break;
    }

    std::cout << CYAN << "Введіть кількість місць у залі: " << RESET;
    while (true)
    {
        std::cin >> newHall.seatCount;
        if (std::cin.fail())
        {
            std::cout << RED << "Помилка! Введіть ціле число: " << RESET;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (newHall.seatCount <= 0)
            std::cout << RED << "Помилка! Введіть додатнє число: " << RESET;
        else
            break;
    }

    std::cout << CYAN << "Введіть ID залу: " << RESET;
    while (true)
    {
        std::cin >> newHall.hallId;
        isUnique = true;
        if (std::cin.fail())
        {
            std::cout << RED << "Помилка! Введіть ціле число: " << RESET;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (newHall.hallId <= 0)
            std::cout << RED << "Помилка! Введіть додатнє число: " << RESET;
        else
        {
            for (const auto& hall : halls)
                if (newHall.hallId == hall.hallId)
                {
                    std::cout << RED << "Цей ID вже існує, введіть ID ще раз: " << RESET;
                    isUnique = false;
                    break;
                }
            if (isUnique)
                break;
        }
    }

    halls.push_back(newHall);
    std::cout << GREEN << "Зал успішно додано!\n" << RESET;
}

void showHalls(std::vector<Hall>& halls)
{
    if (halls.empty())
    {
        std::cout << RED << "\nПомилка: залів ще немає!\n" << RESET;
        return;
    }
    else
    {
        std::cout << BOLD << YELLOW << "\n=== Список залів ===\n" << RESET;
        std::cout << BOLD << GREEN << std::left << std::setw(10) << "ID" << std::setw(20) << "Назва" << std::setw(15) << "Місць" << RESET << "\n";
        std::cout << std::string(35, '-') << "\n";
        for (const auto& hall : halls)
            std::cout << MAGENTA << std::setw(10) << hall.hallId << RESET 
                      << CYAN << std::setw(20) << hall.hallName << RESET 
                      << YELLOW << std::setw(15) << hall.seatCount << RESET << "\n";
    }
}

void editHallById(std::vector<Hall>& halls)
{
    int hallId;
    bool found = false;

    if (halls.empty())
    {
        std::cout << RED << "\nПомилка: залів ще немає!\n" << RESET;
        return;
    }
    else
    {
        showHalls(halls);
        std::cout << CYAN << "\nВведіть ID залу для редагування: " << RESET;
        while (true)
        {
            std::cin >> hallId;
            if (std::cin.fail())
            {
                std::cout << RED << "Помилка! Введіть ціле число: " << RESET;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else if (hallId <= 0)
                std::cout << RED << "Помилка! Введіть додатнє число: " << RESET;
            else
                break;
        }

        std::cin.ignore();
        for (auto& hall : halls)
        {
            if (hallId == hall.hallId)
            {
                found = true;
                std::cout << GREEN << "\nЗал знайдено!\n" << RESET;
                std::cout << CYAN << "Введіть нову назву залу: " << RESET;
                while (true)
                {
                    std::getline(std::cin, hall.hallName);
                    if (hall.hallName.empty())
                    {
                        std::cout << RED << "Помилка: назва залу не може бути порожньою!\n" << RESET;
                        std::cout << CYAN << "Введіть нову назву залу: " << RESET;
                    }
                    else
                        break;
                }

                std::cout << CYAN << "Введіть кількість місць у залі: " << RESET;
                while (true)
                {
                    std::cin >> hall.seatCount;
                    if (std::cin.fail())
                    {
                        std::cout << RED << "Помилка! Введіть ціле число: " << RESET;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    else if (hall.seatCount <= 0)
                        std::cout << RED << "Помилка! Введіть додатнє число: " << RESET;
                    else
                        break;
                }
                std::cout << GREEN << "Зал успішно відредаговано!\n" << RESET;
                break;
            }
        }
        if (!found)
            std::cout << RED << "\nПомилка: зал з таким ID не знайдено!\n" << RESET;
    }
}

void removeHallById(std::vector<Hall>& halls)
{
    int hallId;
    bool found = false;

    if (halls.empty())
    {
        std::cout << RED << "\nПомилка: залів ще немає!\n" << RESET;
        return;
    }
    else
    {
        showHalls(halls);
        std::cout << YELLOW << "\nВведіть ID залу, який хочете видалити: " << RESET;
        while (true)
        {
            std::cin >> hallId;
            if (std::cin.fail())
            {
                std::cout << RED << "Помилка! Введіть ціле число: " << RESET;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else if (hallId <= 0)
                std::cout << RED << "Помилка! Введіть додатнє число: " << RESET;
            else
                break;
        }

        for (auto it = halls.begin(); it != halls.end(); ++it)
            if (it->hallId == hallId)
            {
                halls.erase(it);
                std::cout << MAGENTA << "\nЗал успішно видалено!\n" << RESET;
                found = true;
                break;
            }
        if (!found)
            std::cout << RED << "\nПомилка: зал з таким ID не знайдено!\n" << RESET;
    }
}

void searchHallsById(std::vector<Hall>& halls)
{
    int hallId;
    bool found = false;

    std::cout << BOLD << YELLOW << "\n=== Пошук залів за ID ===\n" << RESET;
    std::cout << CYAN << "Введіть ID залу: " << RESET;

    while (true)
    {
        std::cin >> hallId;
        if (std::cin.fail())
        {
            std::cout << RED << "Помилка! Введіть ціле число: " << RESET;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (hallId <= 0)
            std::cout << RED << "Помилка! Введіть додатнє число: " << RESET;
        else
            break;
    }

    if (halls.empty())
    {
        std::cout << RED << "\nПомилка: залів ще немає!\n" << RESET;
        return;
    }

    std::cout << BOLD << YELLOW << "\n=== Результати пошуку ===\n" << RESET;
    std::cout << BOLD << GREEN << std::left << std::setw(10) << "ID" << std::setw(30) << "Назва" << std::setw(15) << "Жанр" << RESET << "\n";
    std::cout << std::string(55, '-') << "\n";

    for (const auto hall : halls)
        if (hall.hallId == hallId)
        {
            std::cout << MAGENTA << std::setw(10) << hall.hallId << RESET
                << CYAN << std::setw(20) << hall.hallName << RESET
                << YELLOW << std::setw(15) << hall.seatCount << RESET << "\n";
            found = true;
            break;
        }

    if (!found) 
        std::cout << RED << "Зал з ID " << hallId << " не знайдено!\n" << RESET;
}
