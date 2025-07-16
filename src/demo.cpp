#include "demo.h"
#include <iostream>
#include <string>

void loadDemoData(std::vector<Film>& films, std::vector<Hall>& halls, std::vector<Session>& sessions, std::vector<Ticket>& tickets)
{


	films.push_back({1, "Матриця", "HORROR"});
	films.push_back({1, "Початок", "COMEDY"});

	halls.push_back({ 1, "Матриця",  50 });
	halls.push_back({ 2, "Початок", 100 });

	Film* movie1 = &films[0];
	Film* movie2 = &films[1];
	Hall* hall1 = &halls[0];
	Hall* hall2 = &halls[1];

	sessions.push_back({ 1, movie1, hall1, "2025-07-17 18:00" });
	sessions.push_back({ 2, movie2, hall2, "2025-07-17 20:00" });

	Session* session1 = &sessions[0];

	tickets.push_back({ 1, session1, 10 });

}
