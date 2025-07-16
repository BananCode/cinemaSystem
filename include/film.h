#ifndef FILM_H
#define FILM_H

#include <string>
#include <vector>

struct Film
{
    int filmId;               // Унікальний ідентифікатор фільму
    std::string filmName;     // Назва фільму
    std::string genre;        // Жанр фільму
};

extern std::vector<Film> films;

void addFilm(std::vector<Film>& films);                     // Додати новий фільм до вектора
void showFilms(std::vector<Film>& films);                   // Вивести всі фільми у списку
void editFilmById(std::vector<Film>& films, int filmId);    // Редагувати фільм за його ID
void removeFilmById(std::vector<Film>& films, int filmId);  // Видалити фільм зі списку за його ID

#endif
