#include "dataView.h"
#include <iostream>
#include <iomanip>

void showAllData(std::vector<Film>& films, std::vector<Hall>& halls, std::vector<Session>& sessions, std::vector<Ticket>& tickets)
{
    std::cout << std::left;
    std::cout << std::setw(20) << "Фільм" << " | "
        << std::setw(10) << "Зал" << " | "
        << std::setw(15) << "Час сесії" << " | "
        << std::setw(10) << "Місце" << "\n";

    std::cout << std::string(60, '-') << "\n";

    for (const auto& t : tickets)
    {
        Session* s = t.session;
        if (!s) continue;

        Film* film = s->movie;
        Hall* hall = s->hall;

        if (!film || !hall) continue;

        std::cout << std::setw(20) << film->filmName << " | "
            << std::setw(10) << hall->hallName << " | "
            << std::setw(15) << s->sessionTime << " | "
            << std::setw(10) << t.seatNum << "\n";
    }

}
