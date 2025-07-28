#include "demo.h"
#include <iostream>
#include <string>

void loadDemoData(std::vector<Film>& films, std::vector<Hall>& halls, std::vector<Session>& sessions, std::vector<Ticket>& tickets)
{
	//Додаємо фільми до вектора
	films.push_back({1, "Матриця", "HORROR"});  
	films.push_back({2, "Початок", "COMEDY"});

	//Додаємо зали до вектора
	halls.push_back({ 1, "Зал: 1",  50 });      
	halls.push_back({ 2, "Зал: 2", 100 });

	//Вказівники на фільми та зали
	Film* movie1 = &films[0];
	Film* movie2 = &films[1];
	Hall* hall1 = &halls[0];
	Hall* hall2 = &halls[1];

	//Додаємо сеанси до вектора
	sessions.push_back({ 1, movie1, hall1, "2025-07-17 18:00" });
	sessions.push_back({ 2, movie2, hall2, "2025-07-17 20:00" });

	//Вказівники на сеанси
	Session* session1 = &sessions[0];
	Session* session2 = &sessions[1];

	//Додаємо квитки до вектора
	tickets.push_back({ 1, session1, 10 });
	tickets.push_back({ 2, session2, 50 });
}
