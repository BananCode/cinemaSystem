#ifndef MENU_H
#define MENU_H

#include <vector>
#include "film.h"
#include "hall.h"
#include "session.h"
#include "ticket.h"

void mainMenu();
void manageFilmsMenu(std::vector<Film>& films);
void manageHallMenu(std::vector<Hall>& halls);
void manageSessionMenu(std::vector<Session>& sessions);
void manageTicketsMenu(std::vector<Ticket>& tickets, std::vector<Session>& sessions);

#endif
