#include "ticket.h"
#include <iostream>
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
        std::cout << RED << "Сеанс не знайдено!" << RESET << std::endl;
        return;
    }

    if (seatNum > selectedSession->hall->seatCount)
    {
        std::cout << RED << "Помилка: місце перевищує кількість місць у залі!" << RESET << std::endl;
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
    std::cout << YELLOW << "Квиток успішно додано!\n" << RESET;
}


void showTicket(std::vector<Ticket>& tickets)
{
    if (tickets.size() == 0)
        std::cout << RED << "\nПомилка: квитків ще немає!\n" << RESET;
    else
        for (int i = 0; i < tickets.size(); i++)
        {
            std::cout << GREEN << "\nКвиток " << i + 1 << ": " << RESET;
            std::cout << YELLOW << "\nАйді квитка: " << RESET << tickets[i].ticketId;
            std::cout << YELLOW << "\nНомер місця квитка: " << RESET << tickets[i].seatNum;
            std::cout << YELLOW << "\nЗал: " << RESET << tickets[i].session->hall->hallName;
            std::cout << YELLOW << "\nНазва фільму: " << RESET << tickets[i].session->movie->filmName << "\n";
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

    if (tickets.size() == 0)
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

        if (sessions.size() == 0)
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

    if (tickets.size() == 0)
        std::cout << RED << "\nПомилка: квитків ще немає!\n" << RESET;
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
