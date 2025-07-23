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

extern std::vector<Session> sessions;

void addSession(std::vector<Session>& sessions);
void showSession(std::vector<Session>& sessions);

#endif
