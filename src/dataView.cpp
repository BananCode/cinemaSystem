#include "dataView.h"
#include <iostream>
#include <iomanip>
#include <fstream>

void showAllData(std::vector<Film>& films, std::vector<Hall>& halls, std::vector<Session>& sessions, std::vector<Ticket>& tickets)
{
    std::cout << BOLD << YELLOW;
    std::cout << std::left;
    std::cout << std::setw(18) << "Фільм" << " | "
        << std::setw(10) << "Зал" << " | "
        << std::setw(24) << "Час сесії" << " | "
        << std::setw(10) << "Місце" << "\n";
    std::cout << RESET;

    std::cout << std::string(60, '-') << "\n";

    for (const auto& t : tickets)
    {
        Session* s = t.session;
        if (!s) continue;

        Film* film = s->movie;
        Hall* hall = s->hall;

        if (!film || !hall) continue;

        std::cout << std::setw(20) << film->filmName << " | "
            << CYAN << std::setw(10) << hall->hallName << RESET << " | "
            << GREEN << std::setw(15) << s->sessionTime << RESET << " | "
            << CYAN << std::setw(10) << t.seatNum << RESET << "\n";
    }
}

void saveAllData(std::vector<Film>& films, std::vector<Hall>& halls, std::vector<Session>& sessions, std::vector<Ticket>& tickets)
{
    std::ofstream cinemaData("cinema_data.txt");

    if (!cinemaData)
    {
        std::cout << RED << "Помилка: не вдалось відкрити файл\n" << RESET;
        return;
    }

    cinemaData << "=== Фільми ===\n";
    
    for (const auto film : films)
        cinemaData << film.filmId << ", " << film.filmName << ", " << film.genre << "\n";

    cinemaData << "\n=== Зали ===\n";
    
    for (const auto hall : halls)
        cinemaData << hall.hallId << ", " << hall.hallName << ", " << hall.seatCount << "\n";

    cinemaData << "\n=== Сеанси ===\n";
    
    for (const auto session : sessions)
        cinemaData << session.sessionId << ", " << session.movie->filmName << ", " << session.hall->hallName << ", " << session.sessionTime << "\n";

    cinemaData << "\n=== Квитки ===\n";
    
    for (const auto ticket : tickets)
        cinemaData << ticket.ticketId << ", " << ticket.session->sessionId << ", " << ticket.seatNum << "\n";

    cinemaData.close();
}
