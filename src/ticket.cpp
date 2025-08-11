#include "ticket.h"
#include <iostream>
#include <iomanip>
#include "colors.h"

std::vector<Ticket> tickets;

void addTicket(std::vector<Ticket>& tickets, std::vector<Session>& sessions)
{
    int ticketId;
    int sessionId;
    int seatNum;
    bool isUnique = false;
    Session* selectedSession = nullptr;

    std::cout << BOLD << YELLOW << "\n=== Додавання нового квитка ===\n" << RESET;

    std::cout << CYAN << "Введіть ID квитка: " << RESET;
    while (true)
    {
        std::cin >> ticketId;
        isUnique = true;

        if (std::cin.fail())
        {
            std::cout << RED << "Помилка! Введіть ціле число: " << RESET;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (ticketId <= 0)
            std::cout << RED << "Помилка! Введіть додатнє число: " << RESET;
        else
        {
            for (int i = 0; i < tickets.size(); i++)
                if (ticketId == tickets[i].ticketId)
                {
                    std::cout << RED << "Цей ID вже існує, введіть ID ще раз: " << RESET;
                    isUnique = false;
                    break;
                }
            if (isUnique)
                break;
        }
    }

    std::cout << CYAN << "Введіть номер місця: " << RESET;
    while (true)
    {
        std::cin >> seatNum;
        if (std::cin.fail())
        {
            std::cout << RED << "Помилка! Введіть ціле число: " << RESET;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (seatNum <= 0)
            std::cout << RED << "Помилка! Введіть додатнє число: " << RESET;
        else
            break;
    }

    if (sessions.empty())
    {
        std::cout << RED << "\nПомилка: сеансів ще немає!\n" << RESET;
        return;
    }

    showSession(sessions);
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

    selectedSession = nullptr;
    for (auto& session : sessions)
        if (session.sessionId == sessionId)
        {
            selectedSession = &session;
            break;
        }

    if (!selectedSession)
    {
        std::cout << RED << "Сеанс не знайдено!\n" << RESET;
        return;
    }

    if (seatNum > selectedSession->hall->seatCount)
    {
        std::cout << RED << "Помилка: номер місця перевищує кількість місць у залі!\n" << RESET;
        return;
    }

    for (const auto& ticket : tickets)
        if (ticket.session == selectedSession && ticket.seatNum == seatNum)
        {
            std::cout << RED << "Місце зайнято!" << RESET << std::endl;
            return;
        }

    Ticket newTicket{ ticketId, selectedSession, seatNum };
    tickets.push_back(newTicket);
    std::cout << GREEN << "Квиток успішно додано!\n" << RESET;
}

void showTicket(std::vector<Ticket>& tickets)
{
    if (tickets.empty())
    {
        std::cout << RED << "\nПомилка: квитків ще немає!\n" << RESET;
        return;
    }
    else
    {
        std::cout << BOLD << YELLOW << "\n=== Список квитків ===\n" << RESET;
        std::cout << BOLD << GREEN << std::left << std::setw(10) << "ID" << std::setw(15) << "Місце" << std::setw(30) << "Фільм" << std::setw(20) << "Зал" << RESET << "\n";
        std::cout << std::string(65, '-') << "\n";
        for (const auto& ticket : tickets)
            std::cout << MAGENTA << std::setw(10) << ticket.ticketId << RESET 
                      << CYAN << std::setw(15) << ticket.seatNum << RESET 
                      << YELLOW << std::setw(30) << ticket.session->movie->filmName << RESET 
                      << BLUE << std::setw(20) << ticket.session->hall->hallName << RESET << "\n";
    }
}

void editTicketById(std::vector<Ticket>& tickets)
{
    int ticketId;
    int sessionId;
    int seatNum;
    int ticketIndex = -1;
    bool found = false;
    bool sessionFound = false;

    if (tickets.empty())
    {
        std::cout << RED << "\nПомилка: квитків ще немає!\n" << RESET;
        return;
    }
    else
    {
        showTicket(tickets);

        std::cout << CYAN << "Введіть ID квитка для редагування: " << RESET;
        while (!(std::cin >> ticketId))
        {
            std::cout << RED << "Помилка! Введіть ціле число: " << RESET;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        for (int i = 0; i < tickets.size(); i++)
            if (ticketId == tickets[i].ticketId)
            {
                ticketIndex = i;
                found = true;
            }

        if (!found)
        {
            std::cout << RED << "Квиток не знайдено!\n" << RESET;
            return;
        }

        if (sessions.empty())
        {
            std::cout << RED << "\nПомилка: сеансів ще немає!\n" << RESET;
            return;
        }
        else
        {
            showSession(sessions);

            std::cout << CYAN << "Виберіть ID сеансу: " << RESET;
            while (!(std::cin >> sessionId))
            {
                std::cout << RED << "Помилка! Введіть ціле число: " << RESET;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            for (int i = 0; i < sessions.size(); i++)
                if (sessions[i].sessionId == sessionId)
                {
                    tickets[ticketIndex].session = &sessions[i];
                    sessionFound = true;
                    break;
                }

            if (!sessionFound)
            {
                std::cout << RED << "Сеанс не знайдено!\n" << RESET;
                return;
            }

            std::cout << CYAN << "Введіть номер місця: " << RESET;
            while (!(std::cin >> seatNum))
            {
                std::cout << RED << "Помилка! Введіть ціле число: " << RESET;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            for (int i = 0; i < tickets.size(); i++)
                if (i != ticketIndex && tickets[i].session == tickets[ticketIndex].session && tickets[i].seatNum == seatNum)
                {
                    std::cout << RED << "Місце зайнято!\n" << RESET;
                    return;
                }

            tickets[ticketIndex].seatNum = seatNum;
            std::cout << MAGENTA << "\nКвиток успішно відредаговано!\n" << RESET;
        }
    }
}

void removeTicketById(std::vector<Ticket>& tickets)
{
    int ticketId;
    bool found = false;

    if (tickets.empty())
    {
        std::cout << RED << "\nПомилка: квитків ще немає!\n" << RESET;
        return;
    }
    else
    {
        showTicket(tickets);

        std::cout << YELLOW << "\nВведіть ID квитка для видалення: " << RESET;
        while (!(std::cin >> ticketId))
        {
            std::cout << RED << "Помилка! Введіть ціле число: " << RESET;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        for (int i = 0; i < tickets.size(); i++)
            if (ticketId == tickets[i].ticketId)
            {
                tickets.erase(tickets.begin() + i);
                std::cout << MAGENTA << "\nКвиток успішно видалено!\n" << RESET;
                found = true;
                break;
            }
        if (!found)
            std::cout << RED << "\nПомилка: квиток з таким ID не знайдено!\n" << RESET;
    }
}

void searchTicketsById(std::vector<Ticket>& tickets)
{
    int ticketId;
    bool found = false;

    std::cout << BOLD << YELLOW << "\n=== Пошук квитків за ID ===\n" << RESET;
    std::cout << CYAN << "Введіть ID квитка: " << RESET;

    while (true)
    {
        std::cin >> ticketId;
        if (std::cin.fail())
        {
            std::cout << RED << "Помилка! Введіть ціле число: " << RESET;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (ticketId <= 0)
            std::cout << RED << "Помилка! Введіть додатнє число: " << RESET;
        else
            break;
    }

    if (tickets.empty())
    {
        std::cout << RED << "\nПомилка: квитків ще немає!\n" << RESET;
        return;
    }
    
    std::cout << BOLD << YELLOW << "\n=== Результати пошуку ===\n" << RESET;
    std::cout << BOLD << GREEN << std::left << std::setw(10) << "ID" << std::setw(15) << "Місце" << std::setw(30) << "Фільм" << std::setw(20) << "Зал" << RESET << "\n";
    std::cout << std::string(65, '-') << "\n";

    for (const auto ticket : tickets)
        if (ticket.ticketId == ticketId) 
        {
            std::cout << MAGENTA << std::setw(10) << ticket.ticketId << RESET
                << CYAN << std::setw(15) << ticket.seatNum << RESET
                << YELLOW << std::setw(30) << ticket.session->movie->filmName << RESET
                << BLUE << std::setw(20) << ticket.session->hall->hallName << RESET << "\n";
            found = true;
            break;
        }

    if (!found)
        std::cout << RED << "Квиток з ID " << ticketId << " не знайдено!\n" << RESET;
}
