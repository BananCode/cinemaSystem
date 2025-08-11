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
        std::cout << RED << "\nПомилка: немає фільмів або залів!\n" << RESET;
        return;
    }

	std::cin.ignore(); 
    std::cout << BOLD << YELLOW << "\n=== Додавання нового сеансу ===\n" << RESET;
    std::cout << CYAN << "Введіть ID сеансу: " << RESET;

    while (true)
    {
        std::cin >> newSession.sessionId;
        isUnique = true;

        if (std::cin.fail())
        {
            std::cout << RED << "Помилка! Введіть ціле число: " << RESET;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (newSession.sessionId <= 0)
            std::cout << RED << "Помилка! Введіть додатнє число: " << RESET;
        else
        {
            for (int i = 0; i < sessions.size(); i++)
                if (newSession.sessionId == sessions[i].sessionId)
                {
                    std::cout << RED << "Цей ID вже існує, введіть ID ще раз: " << RESET;
                    isUnique = false;
                    break;
                }
            if (isUnique)
                break;
        }
    }

    showFilms(films);
    std::cout << CYAN << "Виберіть ID фільму: " << RESET;
    while (true)
    {
        std::cin >> filmId;

        if (std::cin.fail())
        {
            std::cout << RED << "Помилка! Введіть ціле число: " << RESET;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (filmId <= 0)
            std::cout << RED << "Помилка! Введіть додатнє число: " << RESET;
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
        std::cout << RED << "\nПомилка: фільм з таким ID не знайдено!\n" << RESET;
        return;
    }

    showHalls(halls);
    std::cout << CYAN << "Виберіть ID залу: " << RESET;
    while (true)
    {
        std::cin >> hallId;

        if (std::cin.fail())
        {
            std::cout << RED << "Помилка! Введіть ціле число: " << RESET;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (hallId <= 0)
            std::cout << RED << "Помилка! Введіть додатнє число: " << RESET;
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
        std::cout << RED << "\nПомилка: зал з таким ID не знайдено!\n" << RESET;
        return;
    }
    
    std::cout << CYAN << "Введіть час сеансу (наприклад, 2025-07-17 18:00): " << RESET;
    std::cin.ignore();
    while (true)
    {
        std::getline(std::cin, newSession.sessionTime);
        if (newSession.sessionTime.empty())
        {
            std::cout << RED << "Помилка: час сеансу не може бути порожнім!\n" << RESET;
            std::cout << CYAN << "Введіть час сеансу (наприклад, 2025-07-17 18:00): " << RESET;
        }
        else
            break;
    }

    sessions.push_back(newSession);
    std::cout << GREEN << "Сеанс успішно додано!\n" << RESET;
}

void showSession(std::vector<Session>& sessions)
{
    if (sessions.empty())
        std::cout << RED << "\nПомилка: сеансів ще немає!\n" << RESET;
    else
    {
        std::cout << BOLD << YELLOW << "\n=== Список сеансів ===\n" << RESET;
        std::cout << BOLD << GREEN << std::left << std::setw(10) << "ID" << std::setw(20) << "Фільм" << std::setw(15) << "Зал" << std::setw(20) << "Час" << RESET << "\n";
        std::cout << std::string(65, '-') << "\n";
        for (const auto& session : sessions)
            std::cout << MAGENTA << std::setw(10) << session.sessionId << RESET 
                      << CYAN << std::setw(20) << session.movie->filmName << RESET 
                      << YELLOW << std::setw(15) << session.hall->hallName << RESET 
                      << BLUE << std::setw(20) << session.sessionTime << RESET << "\n";
    }
}

void editSessionById(std::vector<Session>& sessions)
{
    bool found = false;
    bool filmFound = false;
    bool hallFound = false;
    int filmId;
    int hallId;
    int sessionId;
    int sessionIndex = -1;

    if (films.empty() || halls.empty())
    {
        std::cout << RED << "\nПомилка: немає фільмів або залів!\n" << RESET;
        return;
    }

    showSession(sessions);

    std::cout << CYAN << "\nВведіть ID сеансу для редагування: " << RESET;
    while (true)
    {
        std::cin >> sessionId;
        if (std::cin.fail())
        {
            std::cout << RED << "Помилка! Введіть ціле число: " << RESET;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (sessionId <= 0)
            std::cout << RED << "Помилка! Введіть додатнє число: " << RESET;
        else
            break;
    }

    for (int i = 0; i < sessions.size(); i++)
        if (sessions[i].sessionId == sessionId)
        {
            sessionIndex = i;
            found = true;
            break;
        }
    
    if (!found)
    {
        std::cout << RED << "Сеанс з ID " << sessionId << " не знайдено!\n" << RESET;
        return;
    }

    showFilms(films);
    std::cout << CYAN << "Виберіть ID фільму: " << RESET;
    while (true)
    {
        std::cin >> filmId;
        if (std::cin.fail())
        {
            std::cout << RED << "Помилка! Введіть ціле число: " << RESET;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (filmId <= 0)
            std::cout << RED << "Помилка! Введіть додатнє число: " << RESET;
        else
            break;
    }

    for (int i = 0; i < films.size(); i++)
        if (films[i].filmId == filmId)
        {
            sessions[sessionIndex].movie = &films[i];
            filmFound = true;
            break;
        }

    if (!filmFound)
    {
        std::cout << RED << "Фільм з ID " << filmId << " не знайдено!\n" << RESET;
        return;
    }

    showHalls(halls);
    std::cout << CYAN << "Введіть ID залу: " << RESET;
    while (true)
    {
        std::cin >> hallId;
        if (std::cin.fail())
        {
            std::cout << RED << "Помилка! Введіть ціле число: " << RESET;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (hallId <= 0)
            std::cout << RED << "Помилка! Введіть додатнє число: " << RESET;
        else
            break;
    }

    for (int i = 0; i < halls.size(); i++)
        if (halls[i].hallId == hallId)
        {
            sessions[sessionIndex].hall = &halls[i];
            hallFound = true;
        }

    if (!hallFound)
    {
        std::cout << RED << "Зал з ID " << hallId << " не знайдено!\n" << RESET;
        return;
    }

    std::cout << CYAN << "Введіть час сеансу (наприклад, 2025-07-17 18:00): " << RESET;
    std::cin.ignore();
    while (true)
    {
        std::getline(std::cin, sessions[sessionIndex].sessionTime);
        if (sessions[sessionIndex].sessionTime.empty())
        {
            std::cout << RED << "Помилка: час сеансу не може бути порожнім!\n" << RESET;
            std::cout << CYAN << "Введіть час сеансу (наприклад, 2025-07-17 18:00): " << RESET;
        }
        else
            break;
    }

    std::cout << GREEN << "Сеанс успішно відредаговано!\n" << RESET;
}

void removeSessionById(std::vector<Session>& sessions)
{
    int sessionId;
    bool found = false;

    if (sessions.empty())
    {
        std::cout << RED << "\nПомилка: сеансів ще немає!\n" << RESET;
        return;
    }
    else
    {
        showSession(sessions);

        std::cout << CYAN << "\nВведіть ID сеансу для видалення: " << RESET;
        while (true)
        {
            std::cin >> sessionId;
            if (std::cin.fail())
            {
                std::cout << RED << "Помилка! Введіть ціле число: " << RESET;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else if (sessionId <= 0)
                std::cout << RED << "Помилка! Введіть додатнє число: " << RESET;
            else
                break;
        }

        for (int i = 0; i < sessions.size(); i++)
            if (sessionId == sessions[i].sessionId)
            {
                sessions.erase(sessions.begin() + i);
                std::cout << MAGENTA << "\nСеанс успішно видалено!\n" << RESET;
                found = true;
                break;
            }
        if (!found)
            std::cout << RED << "Сеанс з ID " << sessionId << " не знайдено!\n" << RESET;
    }
}

void searchSessionsById(std::vector<Session>& sessions)
{
    int sessionId;
    bool found = false;

    std::cout << BOLD << YELLOW << "\n=== Пошук сеансів за ID ===\n" << RESET;
    std::cout << CYAN << "Введіть ID сеансу: " << RESET;

    while (true)
    {
        std::cin >> sessionId;
        if (std::cin.fail())
        {
            std::cout << RED << "Помилка! Введіть ціле число: " << RESET;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (sessionId <= 0)
            std::cout << RED << "Помилка! Введіть додатнє число: " << RESET;
        else
            break;
    }

    if (sessions.empty())
    {
        std::cout << RED << "\nПомилка: сеансів ще немає!\n" << RESET;
        return;
    }

    std::cout << BOLD << YELLOW << "\n=== Результати пошуку ===\n" << RESET;
    std::cout << BOLD << GREEN << std::left << std::setw(10) << "ID" << std::setw(30) << "Фільм" << std::setw(15) << "Зал" << std::setw(20) << "Час" << RESET << "\n";
    std::cout << std::string(75, '-') << "\n";

    for (const auto session : sessions)
        if (session.sessionId == sessionId)
        {
            std::cout << MAGENTA << std::setw(10) << session.sessionId << RESET
                << CYAN << std::setw(30) << (session.movie ? session.movie->filmName : "Н/Д") << RESET
                << YELLOW << std::setw(15) << (session.hall ? session.hall->hallName : "Н/Д") << RESET
                << BLUE << std::setw(20) << session.sessionTime << RESET << "\n";
            found = true;
            break;
        }

    if (!found) 
        std::cout << RED << "Сеанс з ID " << sessionId << " не знайдено!\n" << RESET;
}
