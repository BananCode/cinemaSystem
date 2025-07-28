#include "film.h"
#include <iostream>
#include "colors.h"

std::vector<Film> films;

void addFilm(std::vector<Film>& films)
{
    Film newFilm;
    bool isUnique = false;

    std::cin.ignore();
    std::cout << YELLOW << "\nДодайте фільм:\n" << RESET;
    std::cout << CYAN << "Введіть назву фільму: " << RESET;
    std::getline(std::cin, newFilm.filmName);
    std::cout << CYAN << "Введіть жанр фільму: " << RESET;
    std::getline(std::cin, newFilm.genre);
    std::cout << CYAN << "Введіть ID фільму: " << RESET;

    while (!isUnique)
    {
        std::cin >> newFilm.filmId;
        isUnique = true;

        for (int i = 0; i < films.size(); i++)
            if (newFilm.filmId == films[i].filmId)
            {
                std::cout << RED << "\nЦей ID вже існує введіть айді ще раз: " << RESET;
                isUnique = false;
                break;
            }
    }

    films.push_back(newFilm);
}

void showFilms(std::vector<Film>& films)
{
    if (films.size() == 0)
        std::cout << RED << "\nФільмів ще не має\n" << RESET;
    else
        for (int i = 0; i < films.size(); i++)
        {
            std::cout << GREEN << "\nФільм " << i + 1 << ": " << RESET;
            std::cout << YELLOW << "\nНазва фільму: " << RESET << films[i].filmName;
            std::cout << YELLOW << "\nЖанр фільму: " << RESET << films[i].genre;
            std::cout << YELLOW << "\nАйді фільму: " << RESET << films[i].filmId << "\n";
        }
}

void editFilmById(std::vector<Film>& films)
{
    int filmId;
    if (films.size() == 0)
        std::cout << RED << "\nФільмів ще не має\n" << RESET;
    else
    {
        showFilms(films);

        std::cout << YELLOW << "\nВведіть айді фільму який хочете редагувати: " << RESET;
        while (!(std::cin >> filmId)) 
        {
            std::cout << RED << "Помилка! Введіть ціле число: " << RESET;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cin.ignore();

        for (int i = 0; i < films.size(); i++)
        {
            if (filmId == films[i].filmId)
            {
                std::cout << GREEN << "Фільм знайдено:" << RESET;
                std::cout << CYAN << "\nВведіть нову назву фільму: " << RESET;
                std::getline(std::cin, films[i].filmName);
                std::cout << CYAN << "Введіть новий жанр фільму: " << RESET;
                std::getline(std::cin, films[i].genre);
                break;
                std::cout << GREEN << "Фільм успішно відредаговано!\n" << RESET;
            }
        }
    }
}

void removeFilmById(std::vector<Film>& films)
{
    int filmId;
    if (films.size() == 0)
        std::cout << RED << "\nФільмів ще не має\n" << RESET;
    else
    {
        showFilms(films);

        std::cout << YELLOW << "\nВведіть айді фільма який хочете вмдалити: " << RESET;
        while (!(std::cin >> filmId))
        {
            std::cout << RED << "Помилка! Введіть ціле число: " << RESET;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        for (int i = 0; i < films.size(); i++)
        {
            if (filmId == films[i].filmId)
            {
                films.erase(films.begin() + i);
                break;
            }
        }
    }
}
