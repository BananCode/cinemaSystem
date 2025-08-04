#include "film.h"
#include <iostream>
#include "colors.h"

std::vector<Film> films;

void addFilm(std::vector<Film>& films)
{
    Film newFilm;
    bool isUnique = false;

    std::cin.ignore();
    std::cout << BOLD << YELLOW << "\n=== Додавання нового фільму ===\n" << RESET;
    std::cout << CYAN << "Введіть назву фільму: " << RESET;
    while (true)
    {
        std::getline(std::cin, newFilm.filmName);

        if (newFilm.filmName.empty())
        {
            std::cout << RED << "Помилка: назва фільму не може бути порожньою!\n" << RESET;
            std::cout << CYAN << "Введіть назву фільму: " << RESET;
        }
        else 
            break;
    }

    std::cout << CYAN << "Введіть жанр фільму: " << RESET;
    while (true)
    {
        std::getline(std::cin, newFilm.genre);

        if (newFilm.genre.empty())
        {
            std::cout << RED << "Помилка: жанр фільму не може бути порожнім!\n" << RESET;
            std::cout << CYAN << "Введіть жанр фільму: " << RESET;
        }
        else
            break;
    }
    
    std::cout << CYAN << "Введіть ID фільму: " << RESET;
    while (true)
    {
        std::cin >> newFilm.filmId;
        isUnique = true;

        if (std::cin.fail())
        {
            std::cout << RED << "Помилка! Введіть ціле число: " << RESET;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (newFilm.filmId <= 0)
            std::cout << RED << "Помилка! Введіть додатнє число: " << RESET;
        else
        {
            for (int i = 0; i < films.size(); i++)
                if (newFilm.filmId == films[i].filmId)
                {
                    std::cout << RED << "Цей ID вже існує, введіть ID ще раз: " << RESET;
                    isUnique = false;
                    break;
                }
            if (isUnique)
                break;
        }
    }

    films.push_back(newFilm);
    std::cout << GREEN << "Фільм успішно додано!\n" << RESET;
}

void showFilms(std::vector<Film>& films)
{
    if (films.empty())
        std::cout << RED << "\nПомилка: фільмів ще немає!\n" << RESET;
    else
        for (int i = 0; i < films.size(); i++)
        {
            std::cout << GREEN << "\nФільм " << i + 1 << ": " << RESET;
            std::cout << YELLOW << "\nАйді фільму: " << RESET << films[i].filmId;
            std::cout << YELLOW << "\nНазва фільму: " << RESET << films[i].filmName;
            std::cout << YELLOW << "\nЖанр фільму: " << RESET << films[i].genre << "\n";
        }
}

void editFilmById(std::vector<Film>& films)
{
    int filmId;
    bool found = false;

    if (films.empty())
        std::cout << RED << "\nПомилка: фільмів ще немає!\n" << RESET;
    else
    {
        showFilms(films);

        std::cout << CYAN << "\nВведіть ID фільму для редагування: " << RESET;
        while (true)
        {
            std::cin >> filmId;
            if (std::cin.fail())
            {
                std::cout << RED << "Помилка! Введіть ціле число: " << RESET;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else if (filmId <= 0)
                std::cout << RED << "Помилка! Введіть додатнє число: " << RESET;
            else
                break;
        }

        std::cin.ignore();

        for (int i = 0; i < films.size(); i++)
        {
            if (filmId == films[i].filmId)
            {
                found = true;
                std::cout << GREEN << "\nФільм знайдено!\n" << RESET;
                std::cout << CYAN << "Введіть нову назву фільму: " << RESET;
                while (true)
                {
                    std::getline(std::cin, films[i].filmName);

                    if (films[i].filmName.empty())
                    {
                        std::cout << RED << "Помилка: назва фільму не може бути порожньою!\n" << RESET;
                        std::cout << CYAN << "Введіть нову назву фільму: " << RESET;
                    }
                    else
                        break;
                }

                std::cout << CYAN << "Введіть новий жанр фільму: " << RESET;
                while (true)
                {
                    std::getline(std::cin, films[i].genre);

                    if (films[i].genre.empty())
                    {
                        std::cout << RED << "Помилка: жанр фільму не може бути порожнім!\n" << RESET;
                        std::cout << CYAN << "Введіть новий жанр фільму: " << RESET;
                    }
                    else
                        break;
                }
                std::cout << MAGENTA << "\nФільм успішно відредаговано!\n" << RESET;
                break;
            }
        }
        if (!found)
            std::cout << RED << "\nПомилка: фільм з таким ID не знайдено!\n" << RESET;
    }
}

void removeFilmById(std::vector<Film>& films)
{
    int filmId;
    bool found = false;

    if (films.empty())
        std::cout << RED << "\nПомилка: фільмів ще немає!\n" << RESET;
    else
    {
        showFilms(films);

        std::cout << CYAN << "\nВведіть ID фільму для видалення: " << RESET;
        while (true)
        {
            std::cin >> filmId;
            if (std::cin.fail())
            {
                std::cout << RED << "Помилка! Введіть ціле число: " << RESET;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else if (filmId <= 0)
                std::cout << RED << "Помилка! Введіть додатнє число: " << RESET;
            else
                break;
        }

        for (int i = 0; i < films.size(); i++)
            if (filmId == films[i].filmId)
            {
                films.erase(films.begin() + i);
                std::cout << MAGENTA << "\nФільм успішно видалено!\n" << RESET;
                found = true;
                break;
            }
        if (!found)
            std::cout << RED << "\nПомилка: фільм з таким ID не знайдено!\n" << RESET;
    }
}
