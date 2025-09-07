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
    std::cout << BOLD << YELLOW << "\n=== Add New Hall ===\n" << RESET;
    std::cout << CYAN << "Enter hall name: " << RESET;
    while (true)
    {
        std::getline(std::cin, newHall.hallName);
        if (newHall.hallName.empty())
        {
            std::cout << RED << "Error: Hall name cannot be empty!\n" << RESET;
            std::cout << CYAN << "Enter hall name: " << RESET;
        }
        else
            break;
    }

    std::cout << CYAN << "Enter number of seats: " << RESET;
    while (true)
    {
        std::cin >> newHall.seatCount;
        if (std::cin.fail())
        {
            std::cout << RED << "Error: Enter an integer!\n" << RESET;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (newHall.seatCount <= 0)
            std::cout << RED << "Error: Enter a positive number!\n" << RESET;
        else
            break;
    }

    std::cout << CYAN << "Enter hall ID: " << RESET;
    while (true)
    {
        std::cin >> newHall.hallId;
        isUnique = true;
        if (std::cin.fail())
        {
            std::cout << RED << "Error: Enter an integer!\n" << RESET;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (newHall.hallId <= 0)
            std::cout << RED << "Error: Enter a positive number!\n" << RESET;
        else
        {
            for (const auto& hall : halls)
                if (newHall.hallId == hall.hallId)
                {
                    std::cout << RED << "This ID already exists, enter ID again: " << RESET;
                    isUnique = false;
                    break;
                }
            if (isUnique)
                break;
        }
    }

    halls.push_back(newHall);
    std::cout << GREEN << "Hall added successfully!\n" << RESET;
}

void showHalls(std::vector<Hall>& halls)
{
    if (halls.empty())
    {
        std::cout << RED << "\nError: No halls available!\n" << RESET;
        return;
    }
    else
    {
        std::cout << BOLD << YELLOW << "\n=== List of Halls ===\n" << RESET;
        std::cout << BOLD << GREEN << std::left << std::setw(10) << "ID" << std::setw(20) << "Name" << std::setw(15) << "Seats" << RESET << "\n";
        std::cout << std::string(45, '-') << "\n";
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
        std::cout << RED << "\nError: No halls available!\n" << RESET;
        return;
    }
    else
    {
        showHalls(halls);
        std::cout << YELLOW << "\nEnter ID of hall to edit: " << RESET;
        while (true)
        {
            std::cin >> hallId;
            if (std::cin.fail())
            {
                std::cout << RED << "Error: Enter an integer!\n" << RESET;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else if (hallId <= 0)
                std::cout << RED << "Error: Enter a positive number!\n" << RESET;
            else
                break;
        }

        for (auto& hall : halls)
            if (hallId == hall.hallId)
            {
                std::cin.ignore();
                std::cout << CYAN << "Enter new hall name: " << RESET;
                while (true)
                {
                    std::getline(std::cin, hall.hallName);
                    if (hall.hallName.empty())
                    {
                        std::cout << RED << "Error: Hall name cannot be empty!\n" << RESET;
                        std::cout << CYAN << "Enter new hall name: " << RESET;
                    }
                    else
                        break;
                }

                std::cout << CYAN << "Enter new number of seats: " << RESET;
                while (true)
                {
                    std::cin >> hall.seatCount;
                    if (std::cin.fail())
                    {
                        std::cout << RED << "Error: Enter an integer!\n" << RESET;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    else if (hall.seatCount <= 0)
                        std::cout << RED << "Error: Enter a positive number!\n" << RESET;
                    else
                        break;
                }
                std::cout << MAGENTA << "\nHall edited successfully!\n" << RESET;
                found = true;
                break;
            }
        if (!found)
            std::cout << RED << "\nError: Hall with ID " << hallId << " not found!\n" << RESET;
    }
}

void removeHallById(std::vector<Hall>& halls)
{
    int hallId;
    bool found = false;

    if (halls.empty())
    {
        std::cout << RED << "\nError: No halls available!\n" << RESET;
        return;
    }
    else
    {
        showHalls(halls);
        std::cout << YELLOW << "\nEnter ID of hall to delete: " << RESET;
        while (true)
        {
            std::cin >> hallId;
            if (std::cin.fail())
            {
                std::cout << RED << "Error: Enter an integer!\n" << RESET;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else if (hallId <= 0)
                std::cout << RED << "Error: Enter a positive number!\n" << RESET;
            else
                break;
        }

        for (auto it = halls.begin(); it != halls.end(); ++it)
            if (it->hallId == hallId)
            {
                halls.erase(it);
                std::cout << MAGENTA << "\nHall deleted successfully!\n" << RESET;
                found = true;
                break;
            }
        if (!found)
            std::cout << RED << "\nError: Hall with ID " << hallId << " not found!\n" << RESET;
    }
}

void searchHallsById(std::vector<Hall>& halls)
{
    int hallId;
    bool found = false;

    std::cout << BOLD << YELLOW << "\n=== Search Halls by ID ===\n" << RESET;
    std::cout << CYAN << "Enter hall ID: " << RESET;

    while (true)
    {
        std::cin >> hallId;
        if (std::cin.fail())
        {
            std::cout << RED << "Error: Enter an integer!\n" << RESET;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (hallId <= 0)
            std::cout << RED << "Error: Enter a positive number!\n" << RESET;
        else
            break;
    }

    if (halls.empty())
    {
        std::cout << RED << "\nError: No halls available!\n" << RESET;
        return;
    }

    std::cout << BOLD << YELLOW << "\n=== Search Results ===\n" << RESET;
    std::cout << BOLD << GREEN << std::left << std::setw(10) << "ID" << std::setw(20) << "Name" << std::setw(15) << "Seats" << RESET << "\n";
    std::cout << std::string(45, '-') << "\n";

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
        std::cout << RED << "Hall with ID " << hallId << " not found!\n" << RESET;
}
