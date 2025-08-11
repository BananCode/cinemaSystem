#include "film.h"
#include <iostream>
#include <iomanip>
#include "colors.h"

std::vector<Film> films;

const std::string genreNames[GenreCount] // Масив жанрів
{
    "Comedy",
    "Drama",
    "Action",
    "Horror",
    "Fantasy",
    "Thriller",
    "Documentary"
};

void addFilm(std::vector<Film>& films)
{
    Film newFilm;
    bool isUnique = false;
    int genreChoice;

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

    std::cout << CYAN << "Виберіть жанр фільму: \n" << RESET;
    for (int i = 0; i < GenreCount; i++)
        std::cout << YELLOW << i + 1 << " - " << genreNames[i] << RESET << "\n";

    while (true)
    {
        std::cout << CYAN << "Введіть номер жанру (1-" << GenreCount << "): " << RESET;
        std::cin >> genreChoice;
        if (std::cin.fail() || genreChoice < 1 || genreChoice > GenreCount)
        {
            std::cout << RED << "Помилка! Введіть число від 1 до " << GenreCount << "\n" << RESET;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            newFilm.genre = static_cast<Genre>(genreChoice - 1);
            break;
        }
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
    {
        std::cout << BOLD << YELLOW << "\n=== Список фільмів ===\n" << RESET;
        std::cout << BOLD << GREEN << std::left << std::setw(10) << "ID" << std::setw(20) << "Назва" << std::setw(15) << "Жанр" << RESET << "\n";
        std::cout << std::string(35, '-') << "\n";
        for (const auto film : films)
            std::cout << MAGENTA << std::setw(10) << film.filmId << RESET 
                      << CYAN << std::setw(20) << film.filmName << RESET
                      << YELLOW << std::setw(15) << genreNames[film.genre] << RESET << "\n";
    }
}

void editFilmById(std::vector<Film>& films)
{
    int filmId;
    bool found = false;
    int genreChoice;

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

                std::cout << CYAN << "Виберіть новий жанр фільму: \n" << RESET;
                for (int i = 0; i < GenreCount; i++)
                    std::cout << YELLOW << i + 1 << " - " << genreNames[i] << RESET << "\n";

                while (true)
                {
                    std::cout << CYAN << "Введіть номер жанру (1-" << GenreCount << "): " << RESET;
                    std::cin >> genreChoice;
                    if (std::cin.fail() || genreChoice < 1 || genreChoice > GenreCount)
                    {
                        std::cout << RED << "Помилка! Введіть число від 1 до " << GenreCount << "\n" << RESET;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    else
                    {
                        films[i].genre = static_cast<Genre>(genreChoice - 1);
                        break;
                    }
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

void searchFilmsById(std::vector<Film>& films)
{
    int filmId;
    bool found = false;

    std::cout << BOLD << YELLOW << "\n=== Пошук фільмів за ID ===\n" << RESET;
    std::cout << CYAN << "Введіть ID фільму: " << RESET;

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

    if (films.empty()) 
    {
        std::cout << RED << "\nПомилка: фільмів ще немає!\n" << RESET;
        return;
    }

    std::cout << BOLD << YELLOW << "\n=== Результати пошуку ===\n" << RESET;
    std::cout << BOLD << GREEN << std::left << std::setw(10) << "ID" << std::setw(30) << "Назва" << std::setw(15) << "Жанр" << RESET << "\n";
    std::cout << std::string(55, '-') << "\n";

    for (const auto film : films)
        if (film.filmId == filmId)
        {
            std::cout << MAGENTA << std::setw(10) << film.filmId << RESET
                << CYAN << std::setw(30) << film.filmName << RESET
                << YELLOW << std::setw(15) << genreNames[film.genre] << RESET << "\n";
            found = true;
            break;
        }
    
    if (!found) 
        std::cout << RED << "Фільм з ID " << filmId << " не знайдено!\n" << RESET;
}
