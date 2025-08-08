#ifndef FILM_H
#define FILM_H

#include <string>
#include <vector>

enum Genre 
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

extern const std::string genreNames[GenreCount];

struct Film
{
    int filmId;               // Унікальний ідентифікатор фільму
    std::string filmName;     // Назва фільму      
    Genre genre;
};

extern std::vector<Film> films;

void addFilm(std::vector<Film>& films);                     // Додати новий фільм до вектора
void showFilms(std::vector<Film>& films);                   // Вивести всі фільми у списку
void editFilmById(std::vector<Film>& films);                // Редагувати фільм за його ID
void removeFilmById(std::vector<Film>& films);              // Видалити фільм зі списку за його ID

#endif
