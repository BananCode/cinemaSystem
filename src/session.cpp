#include <iostream>
#include <iomanip>
#include "session.h"
#include "film.h"
#include "hall.h"
#include "colors.h"

std::vector<Session> sessions;

void addSession(std::vector<Session>& sessions)
{
    Session newSession;
    bool isUnique = false;
    bool found = false;
    int filmId;
    int hallId;

    if (films.empty() || halls.empty())
    {
        std::cout << RED << "\nError: No films or halls available!\n" << RESET;
        return;
    }

    std::cin.ignore();
    std::cout << BOLD << YELLOW << "\n=== Add New Session ===\n" << RESET;
    std::cout << CYAN << "Enter session ID: " << RESET;

    while (true)
    {
        std::cin >> newSession.sessionId;
        isUnique = true;

        if (std::cin.fail())
        {
            std::cout << RED << "Error: Enter an integer!\n" << RESET;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (newSession.sessionId <= 0)
            std::cout << RED << "Error: Enter a positive number!\n" << RESET;
        else
        {
            for (int i = 0; i < sessions.size(); i++)
                if (newSession.sessionId == sessions[i].sessionId)
                {
                    std::cout << RED << "This ID already exists, enter ID again: " << RESET;
                    isUnique = false;
                    break;
                }
            if (isUnique)
                break;
        }
    }

    showFilms(films);
    std::cout << CYAN << "Select film ID: " << RESET;
    while (true)
    {
        std::cin >> filmId;
        if (std::cin.fail())
        {
            std::cout << RED << "Error: Enter an integer!\n" << RESET;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (filmId <= 0)
            std::cout << RED << "Error: Enter a positive number!\n" << RESET;
        else
            break;
    }

    for (int i = 0; i < films.size(); i++)
        if (films[i].filmId == filmId)
        {
            newSession.movie = &films[i];
            found = true;
            break;
        }

    if (!found)
    {
        std::cout << RED << "\nError: Film with ID " << filmId << " not found!\n" << RESET;
        return;
    }

    showHalls(halls);
    std::cout << CYAN << "Select hall ID: " << RESET;
    while (true)
    {
        std::cin >> hallId;
        if (std::cin.fail())
        {
            std::cout << RED << "Error: Enter an integer!\n" << RESET;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (hallId <= 0)
            std::cout << RED << "Error: Enter a positive number!\n" << RESET;
        else
            break;
    }

    found = false;
    for (int i = 0; i < halls.size(); i++)
        if (halls[i].hallId == hallId)
        {
            newSession.hall = &halls[i];
            found = true;
            break;
        }

    if (!found)
    {
        std::cout << RED << "\nError: Hall with ID " << hallId << " not found!\n" << RESET;
        return;
    }

    std::cin.ignore();
    std::cout << CYAN << "Enter session time (YYYY-MM-DD HH:MM): " << RESET;
    while (true)
    {
        std::getline(std::cin, newSession.sessionTime);
        if (newSession.sessionTime.empty())
        {
            std::cout << RED << "Error: Session time cannot be empty!\n" << RESET;
            std::cout << CYAN << "Enter session time: " << RESET;
        }
        else
            break;
    }

    sessions.push_back(newSession);
    std::cout << GREEN << "Session added successfully!\n" << RESET;
}

void showSession(std::vector<Session>& sessions)
{
    if (sessions.empty())
    {
        std::cout << RED << "\nError: No sessions available!\n" << RESET;
        return;
    }
    else
    {
        std::cout << BOLD << YELLOW << "\n=== List of Sessions ===\n" << RESET;
        std::cout << BOLD << GREEN << std::left << std::setw(10) << "ID" << std::setw(30) << "Film" << std::setw(15) << "Hall" << std::setw(20) << "Time" << RESET << "\n";
        std::cout << std::string(75, '-') << "\n";
        for (const auto& session : sessions)
            std::cout << MAGENTA << std::setw(10) << session.sessionId << RESET
            << CYAN << std::setw(30) << (session.movie ? session.movie->filmName : "N/A") << RESET
            << YELLOW << std::setw(15) << (session.hall ? session.hall->hallName : "N/A") << RESET
            << BLUE << std::setw(20) << session.sessionTime << RESET << "\n";
    }
}

void editSessionById(std::vector<Session>& sessions)
{
    int sessionId;
    bool found = false;

    if (sessions.empty())
    {
        std::cout << RED << "\nError: No sessions available!\n" << RESET;
        return;
    }
    else
    {
        showSession(sessions);
        std::cout << YELLOW << "\nEnter ID of session to edit: " << RESET;
        while (true)
        {
            std::cin >> sessionId;
            if (std::cin.fail())
            {
                std::cout << RED << "Error: Enter an integer!\n" << RESET;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else if (sessionId <= 0)
                std::cout << RED << "Error: Enter a positive number!\n" << RESET;
            else
                break;
        }

        for (auto& session : sessions)
            if (sessionId == session.sessionId)
            {
                int filmId;
                int hallId;
                bool filmFound = false;
                bool hallFound = false;

                showFilms(films);
                std::cout << CYAN << "Select new film ID: " << RESET;
                while (true)
                {
                    std::cin >> filmId;
                    if (std::cin.fail())
                    {
                        std::cout << RED << "Error: Enter an integer!\n" << RESET;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    else if (filmId <= 0)
                        std::cout << RED << "Error: Enter a positive number!\n" << RESET;
                    else
                        break;
                }

                for (auto& film : films)
                    if (film.filmId == filmId)
                    {
                        session.movie = &film;
                        filmFound = true;
                        break;
                    }

                if (!filmFound)
                {
                    std::cout << RED << "\nError: Film with ID " << filmId << " not found!\n" << RESET;
                    return;
                }

                showHalls(halls);
                std::cout << CYAN << "Select new hall ID: " << RESET;
                while (true)
                {
                    std::cin >> hallId;
                    if (std::cin.fail())
                    {
                        std::cout << RED << "Error: Enter an integer!\n" << RESET;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    else if (hallId <= 0)
                        std::cout << RED << "Error: Enter a positive number!\n" << RESET;
                    else
                        break;
                }

                for (auto& hall : halls)
                    if (hall.hallId == hallId)
                    {
                        session.hall = &hall;
                        hallFound = true;
                        break;
                    }

                if (!hallFound)
                {
                    std::cout << RED << "\nError: Hall with ID " << hallId << " not found!\n" << RESET;
                    return;
                }

                std::cin.ignore();
                std::cout << CYAN << "Enter new session time (YYYY-MM-DD HH:MM): " << RESET;
                while (true)
                {
                    std::getline(std::cin, session.sessionTime);
                    if (session.sessionTime.empty())
                    {
                        std::cout << RED << "Error: Session time cannot be empty!\n" << RESET;
                        std::cout << CYAN << "Enter new session time: " << RESET;
                    }
                    else
                        break;
                }

                std::cout << MAGENTA << "\nSession edited successfully!\n" << RESET;
                found = true;
                break;
            }
        if (!found)
            std::cout << RED << "\nError: Session with ID " << sessionId << " not found!\n" << RESET;
    }
}

void removeSessionById(std::vector<Session>& sessions)
{
    int sessionId;
    bool found = false;

    if (sessions.empty())
    {
        std::cout << RED << "\nError: No sessions available!\n" << RESET;
        return;
    }
    else
    {
        showSession(sessions);
        std::cout << YELLOW << "\nEnter ID of session to delete: " << RESET;
        while (true)
        {
            std::cin >> sessionId;
            if (std::cin.fail())
            {
                std::cout << RED << "Error: Enter an integer!\n" << RESET;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else if (sessionId <= 0)
                std::cout << RED << "Error: Enter a positive number!\n" << RESET;
            else
                break;
        }

        for (int i = 0; i < sessions.size(); i++)
            if (sessionId == sessions[i].sessionId)
            {
                sessions.erase(sessions.begin() + i);
                std::cout << MAGENTA << "\nSession deleted successfully!\n" << RESET;
                found = true;
                break;
            }
        if (!found)
            std::cout << RED << "Session with ID " << sessionId << " not found!\n" << RESET;
    }
}

void searchSessionsById(std::vector<Session>& sessions)
{
    int sessionId;
    bool found = false;

    std::cout << BOLD << YELLOW << "\n=== Search Sessions by ID ===\n" << RESET;
    std::cout << CYAN << "Enter session ID: " << RESET;

    while (true)
    {
        std::cin >> sessionId;
        if (std::cin.fail())
        {
            std::cout << RED << "Error: Enter an integer!\n" << RESET;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (sessionId <= 0)
            std::cout << RED << "Error: Enter a positive number!\n" << RESET;
        else
            break;
    }

    if (sessions.empty())
    {
        std::cout << RED << "\nError: No sessions available!\n" << RESET;
        return;
    }

    std::cout << BOLD << YELLOW << "\n=== Search Results ===\n" << RESET;
    std::cout << BOLD << GREEN << std::left << std::setw(10) << "ID" << std::setw(30) << "Film" << std::setw(15) << "Hall" << std::setw(20) << "Time" << RESET << "\n";
    std::cout << std::string(75, '-') << "\n";

    for (const auto session : sessions)
        if (session.sessionId == sessionId)
        {
            std::cout << MAGENTA << std::setw(10) << session.sessionId << RESET
                << CYAN << std::setw(30) << (session.movie ? session.movie->filmName : "N/A") << RESET
                << YELLOW << std::setw(15) << (session.hall ? session.hall->hallName : "N/A") << RESET
                << BLUE << std::setw(20) << session.sessionTime << RESET << "\n";
            found = true;
            break;
        }

    if (!found)
        std::cout << RED << "Session with ID " << sessionId << " not found!\n" << RESET;
}
