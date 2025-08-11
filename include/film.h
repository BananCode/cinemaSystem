#ifndef FILM_H
#define FILM_H

#include <string>
#include <vector>

enum Genre // Перелік жанрів
{
    Comedy,
    Drama,
    Action,
    Horror,
    Fantasy,
    Thriller,
    Documentary,
    GenreCount // Для підрахунку кількості жанрів
};

extern const std::string genreNames[GenreCount]; // Масив жанрів

struct Film
{
    int filmId;               // Унікальний ідентифікатор фільму
    std::string filmName;     // Назва фільму      
    Genre genre;              // Жанр фільму
};

extern std::vector<Film> films; // Глобальний вектор фільмів

void addFilm(std::vector<Film>& films);                     // Додати новий фільм до вектора
void showFilms(std::vector<Film>& films);                   // Вивести всі фільми у списку
void editFilmById(std::vector<Film>& films);                // Редагувати фільм за ID
void removeFilmById(std::vector<Film>& films);              // Видалити фільм за ID
void searchFilmsById(std::vector<Film>& films);             // Пошук фільмів за ID

#endif
