#ifndef FILM_H
#define FILM_H

#include <string>
#include <vector>

struct Film
{
    int id;               
    std::string name;     
    std::string genre;    
};

extern std::vector<Film> films;

void addFilm(std::vector<Film>& films);                 
void showFilms(std::vector<Film>& films);               
void findFilm(std::vector<Film>& films);                
void editFilmById(std::vector<Film>& films, int id);    
void removeFilmById(std::vector<Film>& films, int id);  

#endif
