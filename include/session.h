#ifndef SESSION_H
#define SESSION_H

#include <string>
#include <vector>
#include "film.h"
#include "hall.h"

struct Film;
struct Hall;

struct Session
{
	int sessionId;
	Film* movie;                // Вказівник на фільм, що показується на цьому сеансі
	Hall* hall;                 // Вказівник на зал, де проводиться сеанс
	std::string sessionTime;    // Час проведення сеансу у форматі строки
};

extern std::vector<Session> sessions; // Глобальний вектор сеансів
           
void addSession(std::vector<Session>& sessions);                  // Додавання нового сеансу
void showSession(std::vector<Session>& sessions);                 // Вивід всіх сеансів
void editSessionById(std::vector<Session>& sessions);             // Редагувати сеансу за ID
void removeSessionById(std::vector<Session>& sessions);           // Видалити сеанс за ID
void searchSessionsById(std::vector<Session>& sessions);		  // Пошук сеансів за ID

#endif
