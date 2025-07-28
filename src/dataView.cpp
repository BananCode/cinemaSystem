#include "dataView.h"
#include <iostream>
#include <iomanip>

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
