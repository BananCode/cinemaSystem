#include "film.h"
#include <iostream>
#include "colors.h"

std::vector<Film> films;

void addFilm(std::vector<Film>& films)
{
    Film newFilm;
    bool isUnique = false;
    std::cin.ignore();
    std::cout << "\nДодайте новий фільм:\n";
    std::cout << "Введіть назву фільму: ";
    std::getline(std::cin, newFilm.name);
    std::cout << "Введіть жанр фільму: ";
    std::getline(std::cin, newFilm.genre);
    std::cout << "Введіть ID фільму: ";

    while (!isUnique)
    {
        std::cin >> newFilm.id;
        isUnique = true;

        for (int i = 0; i < films.size(); i++)
            if (newFilm.id == films[i].id)
            {
                std::cout << RED;
                std::cout << "\nЦей ID вже існує введіть айді ще раз: ";
                std::cout << RESET;
                isUnique = false;
                break;
            }
    }

    films.push_back(newFilm);
}

void showFilms(std::vector<Film>& films)
{
    if (films.size() == 0)
        std::cout << "\nФільмів ще не має\n";
    else
        for (int i = 0; i < films.size(); i++)
        {
            std::cout << YELLOW;
            std::cout << "\nФільм " << i + 1 << ": ";
            std::cout << "\nНазва фільму: " << films[i].name;
            std::cout << "\nЖанр фільму: " << films[i].genre;
            std::cout << "\nАйді фільму: " << films[i].id << "\n";
            std::cout << RESET;
        }
}
