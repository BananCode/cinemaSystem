#include "hall.h"
#include <iostream>
#include "colors.h"

std::vector<Hall> halls;

void addHall(std::vector<Hall>& halls)
{
    Hall newHalls;
    bool isUnique = false;
    
    std::cin.ignore();
    std::cout << "\nДодайте зал:\n";
    std::cout << "Введіть назву залу: ";
    std::getline(std::cin, newHalls.hallName);
    std::cout << "Введіть кількість місць у залі: ";
    std::cin >> newHalls.seatCount;
    std::cout << "Введіть ID залу: ";

    while (!isUnique)
    {
        std::cin >> newHalls.hallId;
        isUnique = true;

        for (int i = 0; i < halls.size(); i++)
            if (newHalls.hallId == halls[i].hallId)
            {
                std::cout << RED;
                std::cout << "\nЦей ID вже існує введіть айді ще раз: ";
                std::cout << RESET;
                isUnique = false;
                break;
            }
    }

    halls.push_back(newHalls);
}

void showHall(std::vector<Hall>& halls)
{
    if (halls.size() == 0)
    {
        std::cout << RED;
        std::cout << "\nЗалів ще не існує\n";
        std::cout << RESET;
    }
    else
        for (int i = 0; i < halls.size(); i++)
        {
            std::cout << YELLOW;
            std::cout << "\nЗал " << i + 1 << ": ";
            std::cout << "\nНазва залу: " << halls[i].hallName;
            std::cout << "\nКількість місць у залі: " << halls[i].seatCount;
            std::cout << "\nАйді залу: " << halls[i].hallId << "\n";
            std::cout << RESET;
        }
}
