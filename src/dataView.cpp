#include "dataView.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

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

void loadAllData(std::vector<Film>& films, std::vector<Hall>& halls, std::vector<Session>& sessions, std::vector<Ticket>& tickets)
{
    std::string line;
    std::string currentSection;

    std::ifstream inputFile("cinema_data.txt");
    if (!inputFile) 
    {
        std::cout << RED << "Не вдалося відкрити файл для читання!" << RESET << std::endl;
        return;
    }

    films.clear();
    halls.clear();
    sessions.clear();
    tickets.clear();

    while (std::getline(inputFile, line))
    {
        if (line == "=== Фільми ===")
            currentSection = "films";
        else if (line == "=== Зали ===")
            currentSection = "halls";
        else if (line == "=== Сеанси ===")
            currentSection = "sessions";
        else if (line == "=== Квитки ===")
            currentSection = "ticket";
        else if (!line.empty())
        {
            std::stringstream ss(line);
            if (currentSection == "films")
            {
                Film film;
                std::string idStr;
                std::string name;
                std::string genreStr;

                std::getline(ss, idStr, ',');
                std::getline(ss, name, ',');
                std::getline(ss, genreStr, ',');

                film.filmId = std::stoi(idStr);
                film.filmName = name;
                
                if (genreStr == "Action")
                    film.genre = Genre::Action;
                else if (genreStr == "Comedy")
                    film.genre = Genre::Comedy;
                else if (genreStr == "Documentary")
                    film.genre = Genre::Documentary;
                else if (genreStr == "Drama")
                    film.genre = Genre::Drama;
                else if (genreStr == "Fantasy")
                    film.genre = Genre::Fantasy;
                else if (genreStr == "GenreCount")
                    film.genre = Genre::GenreCount;
                else if (genreStr == "Horror")
                    film.genre = Genre::Horror;
                else if (genreStr == "Thriller")
                    film.genre = Genre::Thriller;

                films.push_back(film);
            }
            else if (currentSection == "halls")
            {
                Hall hall;
                std::string hallIdStr;
                std::string hallName;
                std::string seatCountStr;

                std::getline(ss, hallIdStr, ',');
                std::getline(ss, hallName, ',');
                std::getline(ss, seatCountStr, ',');

                hall.hallId = std::stoi(hallIdStr);
                hall.hallName = hallName;
                hall.seatCount = std::stoi(seatCountStr);

                halls.push_back(hall);
            }
            else if (currentSection == "sessions")
            {
                Session session;
                std::string sessionIdStr;
                std::string filmName;
                std::string hallName;
                std::string sessionTime;

                std::getline(ss, sessionIdStr, ',');
                std::getline(ss, filmName, ',');
                std::getline(ss, hallName, ',');
                std::getline(ss, sessionTime, ',');

                session.sessionId = std::stoi(sessionIdStr);
                session.movie = nullptr;
                for (auto& f : films) 
                    if (f.filmName == filmName) 
                    {
                        session.movie = &f;
                        break;
                    }
                
                session.hall = nullptr;
                for (auto& h : halls) 
                    if (h.hallName == hallName) {
                        session.hall = &h;
                        break;
                    }
                
                session.sessionTime = sessionTime;

                sessions.push_back(session);
            }
            else if (currentSection == "ticket")
            {
                Ticket ticket;
                std::string ticketIdStr;
                std::string sessionIdStr;
                std::string seatNumStr;

                std::getline(ss, ticketIdStr, ',');
                std::getline(ss, sessionIdStr, ',');
                std::getline(ss, seatNumStr, ',');

                ticket.ticketId = std::stoi(ticketIdStr);
                ticket.seatNum = std::stoi(seatNumStr);

                ticket.session = nullptr;
                int sessionId = std::stoi(sessionIdStr);
                for (auto& s : sessions) 
                    if (s.sessionId == sessionId) 
                    {
                        ticket.session = &s;
                        break;
                    }

                tickets.push_back(ticket);
            }
        }
    }
}
