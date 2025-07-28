#include "hall.h"
#include <iostream>
#include "colors.h"

std::vector<Hall> halls;

void addHall(std::vector<Hall>& halls)
{
    Hall newHall;
    bool isUnique = false;
    
    std::cin.ignore();
    std::cout << YELLOW << "\nДодайте зал:\n" << RESET;
    std::cout << CYAN << "Введіть назву залу: " << RESET;
    std::getline(std::cin, newHall.hallName);
    std::cout << CYAN << "Введіть кількість місць у залі: " << RESET;
    std::cin >> newHall.seatCount;
    std::cout << CYAN << "Введіть ID залу: " << RESET;

    while (!isUnique)
    {
        std::cin >> newHall.hallId;
        isUnique = true;

        for (int i = 0; i < halls.size(); i++)
            if (newHall.hallId == halls[i].hallId)
            {
                std::cout << RED << "\nЦей ID вже існує введіть айді ще раз: " << RESET;
                isUnique = false;
                break;
            }
    }

    halls.push_back(newHall);
}

void showHalls(std::vector<Hall>& halls)
{
    if (halls.size() == 0)
        std::cout << RED << "\nЗалів ще не має\n" << RESET;
    else
        for (int i = 0; i < halls.size(); i++)
        {
            std::cout << GREEN << "\nЗал " << i + 1 << ": " << RESET;
            std::cout << YELLOW << "\nНазва залу: " << RESET << halls[i].hallName;
            std::cout << YELLOW << "\nКількість місць у залі: " << RESET << halls[i].seatCount;
            std::cout << YELLOW << "\nАйді залу: " << RESET << halls[i].hallId << "\n";
        }
}

void editHallById(std::vector<Hall>& halls)
{
    int hallId;
    if (halls.size() == 0)
        std::cout << RED << "\nЗалів ще не має\n" << RESET;
    else
    {
        showHalls(halls);

        std::cout << YELLOW << "\nВведіть айді зала який хочете редагувати: " << RESET;
        while (!(std::cin >> hallId))
        {
            std::cout << RED << "Помилка! Введіть ціле число: " << RESET;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cin.ignore();

        for (int i = 0; i < halls.size(); i++)
        {
            if (hallId == halls[i].hallId)
            {
                std::cout << GREEN << "Зал знайдено:" << RESET;
                std::cout << CYAN << "\nВведіть нову назву залу: " << RESET;
                std::getline(std::cin, halls[i].hallName);
                std::cout << CYAN << "Введіть кількість місць у залі: " << RESET;
                std::cin >> halls[i].seatCount;
                std::cout << GREEN << "Зал успішно відредаговано!\n" << RESET;
            }
        }
    }
}

void removeHallById(std::vector<Hall>& halls)
{
    int hallId;
    if (halls.size() == 0)
        std::cout << RED << "\nЗалів ще не має\n" << RESET;
    else
    {
        showHalls(halls);

        std::cout << YELLOW << "\nВведіть айді залу який хочете вмдалити: " << RESET;
        while (!(std::cin >> hallId))
        {
            std::cout << RED << "Помилка! Введіть ціле число: " << RESET;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        for (int i = 0; i < halls.size(); i++)
        {
            if (hallId == halls[i].hallId)
            {
                halls.erase(halls.begin() + i);
                break;
            }
        }
    }
}
