#include <iostream>
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
        std::cout << RED << "Помилка: немає фільмів або залів!" << RESET << std::endl;
        return;
    }

	std::cin.ignore(); 
	std::cout << "\nДодайте сеанс:\n";
	std::cout << "Введіть ID сеансу: ";

    while (!isUnique)
    {
        std::cin >> newSession.sessionId;
        isUnique = true;

        for (int i = 0; i < sessions.size(); i++)
            if (newSession.sessionId == sessions[i].sessionId)
            {
                std::cout << RED;
                std::cout << "\nЦей ID вже існує введіть айді ще раз: ";
                std::cout << RESET;
                isUnique = false;
                break;
            }
    }

    showFilms(films);
    std::cout << "Виберіть ID фільму: ";
    std::cin >> filmId;

    for (int i = 0; i < films.size(); i++)
        if (films[i].filmId == filmId)
        {
            newSession.movie = &films[i];
            found = true;
        }

    if (!found)
    {
        std::cout << RED << "Фільм не знайдено!" << RESET << std::endl;
        return;
    }

    showHall(halls);
    std::cout << "Виберіть ID залу: ";
    std::cin >> hallId;
    found = false;

    for (int i = 0; i < halls.size(); i++)
        if (halls[i].hallId == hallId)
        {
            newSession.hall = &halls[i];
            found = true;
        }

    if (!found)
    {
        std::cout << RED << "Зал не знайдено!" << RESET << std::endl;
        return;
    }
    
    std::cout << "Введіть час сеансу (наприклад, 2025-07-17 18:00): ";
    std::cin.ignore();
    std::getline(std::cin, newSession.sessionTime);

    sessions.push_back(newSession);
    std::cout << GREEN << "Сеанс додано!" << RESET << std::endl;
}

void showSession(std::vector<Session>& sessions)
{
    if (sessions.size() == 0)
        std::cout << RED << "\nСеансів ще немає\n" << RESET;
    else
        for (int i = 0; i < sessions.size(); i++)
        {
            std::cout << "\nСеанс " << i + 1 << ": ";
            std::cout << "\nНазва фільму: " << sessions[i].movie->filmName;
            std::cout << "\nНазва залу: " << sessions[i].hall->hallName;
            std::cout << "\nЧас проведення сеансу: " << sessions[i].sessionTime << "\n";
        }
}
