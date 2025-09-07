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

    std::cout << BOLD << YELLOW << "\n=== Add New Ticket ===\n" << RESET;

    std::cout << CYAN << "Enter ticket ID: " << RESET;
    while (true)
    {
        std::cin >> ticketId;
        isUnique = true;

        if (std::cin.fail())
        {
            std::cout << RED << "Error: Enter an integer!\n" << RESET;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (ticketId <= 0)
            std::cout << RED << "Error: Enter a positive number!\n" << RESET;
        else
        {
            for (int i = 0; i < tickets.size(); i++)
                if (ticketId == tickets[i].ticketId)
                {
                    std::cout << RED << "This ID already exists, enter ID again: " << RESET;
                    isUnique = false;
                    break;
                }
            if (isUnique)
                break;
        }
    }

    std::cout << CYAN << "Enter seat number: " << RESET;
    while (true)
    {
        std::cin >> seatNum;
        if (std::cin.fail())
        {
            std::cout << RED << "Error: Enter an integer!\n" << RESET;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (seatNum <= 0)
            std::cout << RED << "Error: Enter a positive number!\n" << RESET;
        else
            break;
    }

    if (sessions.empty())
    {
        std::cout << RED << "\nError: No sessions available!\n" << RESET;
        return;
    }

    showSession(sessions);
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

    selectedSession = nullptr;
    for (auto& session : sessions)
        if (session.sessionId == sessionId)
        {
            selectedSession = &session;
            break;
        }

    if (!selectedSession)
    {
        std::cout << RED << "Session not found!\n" << RESET;
        return;
    }

    if (seatNum > selectedSession->hall->seatCount)
    {
        std::cout << RED << "Error: Seat number exceeds hall capacity!\n" << RESET;
        return;
    }

    Ticket newTicket;
    newTicket.ticketId = ticketId;
    newTicket.session = selectedSession;
    newTicket.seatNum = seatNum;
    tickets.push_back(newTicket);
    std::cout << GREEN << "Ticket added successfully!\n" << RESET;
}

void showTicket(std::vector<Ticket>& tickets)
{
    if (tickets.empty())
    {
        std::cout << RED << "\nError: No tickets available!\n" << RESET;
        return;
    }
    else
    {
        std::cout << BOLD << YELLOW << "\n=== List of Tickets ===\n" << RESET;
        std::cout << BOLD << GREEN << std::left << std::setw(10) << "ID" << std::setw(15) << "Seat" << std::setw(30) << "Film" << std::setw(20) << "Hall" << RESET << "\n";
        std::cout << std::string(75, '-') << "\n";
        for (const auto& ticket : tickets)
            std::cout << MAGENTA << std::setw(10) << ticket.ticketId << RESET
            << CYAN << std::setw(15) << ticket.seatNum << RESET
            << YELLOW << std::setw(30) << (ticket.session && ticket.session->movie ? ticket.session->movie->filmName : "N/A") << RESET
            << BLUE << std::setw(20) << (ticket.session && ticket.session->hall ? ticket.session->hall->hallName : "N/A") << RESET << "\n";
    }
}

void editTicketById(std::vector<Ticket>& tickets)
{
    int ticketId;
    bool found = false;

    if (tickets.empty())
    {
        std::cout << RED << "\nError: No tickets available!\n" << RESET;
        return;
    }
    else
    {
        showTicket(tickets);
        std::cout << YELLOW << "\nEnter ID of ticket to edit: " << RESET;
        while (true)
        {
            std::cin >> ticketId;
            if (std::cin.fail())
            {
                std::cout << RED << "Error: Enter an integer!\n" << RESET;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else if (ticketId <= 0)
                std::cout << RED << "Error: Enter a positive number!\n" << RESET;
            else
                break;
        }

        for (auto& ticket : tickets)
            if (ticketId == ticket.ticketId)
            {
                int sessionId;
                int seatNum;

                showSession(sessions);
                std::cout << CYAN << "Enter new session ID: " << RESET;
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

                Session* selectedSession = nullptr;
                for (auto& session : sessions)
                    if (session.sessionId == sessionId)
                    {
                        selectedSession = &session;
                        break;
                    }

                if (!selectedSession)
                {
                    std::cout << RED << "Session not found!\n" << RESET;
                    return;
                }

                std::cout << CYAN << "Enter new seat number: " << RESET;
                while (true)
                {
                    std::cin >> seatNum;
                    if (std::cin.fail())
                    {
                        std::cout << RED << "Error: Enter an integer!\n" << RESET;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    else if (seatNum <= 0)
                        std::cout << RED << "Error: Enter a positive number!\n" << RESET;
                    else if (seatNum > selectedSession->hall->seatCount)
                        std::cout << RED << "Error: Seat number exceeds hall capacity!\n" << RESET;
                    else
                        break;
                }

                ticket.session = selectedSession;
                ticket.seatNum = seatNum;
                std::cout << MAGENTA << "\nTicket edited successfully!\n" << RESET;
                found = true;
                break;
            }
        if (!found)
            std::cout << RED << "\nError: Ticket with ID " << ticketId << " not found!\n" << RESET;
    }
}

void removeTicketById(std::vector<Ticket>& tickets)
{
    int ticketId;
    bool found = false;

    if (tickets.empty())
    {
        std::cout << RED << "\nError: No tickets available!\n" << RESET;
        return;
    }
    else
    {
        showTicket(tickets);
        std::cout << YELLOW << "\nEnter ID of ticket to delete: " << RESET;
        while (!(std::cin >> ticketId))
        {
            std::cout << RED << "Error: Enter an integer!\n" << RESET;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        for (int i = 0; i < tickets.size(); i++)
            if (ticketId == tickets[i].ticketId)
            {
                tickets.erase(tickets.begin() + i);
                std::cout << MAGENTA << "\nTicket deleted successfully!\n" << RESET;
                found = true;
                break;
            }
        if (!found)
            std::cout << RED << "\nError: Ticket with ID " << ticketId << " not found!\n" << RESET;
    }
}

void searchTicketsById(std::vector<Ticket>& tickets)
{
    int ticketId;
    bool found = false;

    std::cout << BOLD << YELLOW << "\n=== Search Tickets by ID ===\n" << RESET;
    std::cout << CYAN << "Enter ticket ID: " << RESET;

    while (true)
    {
        std::cin >> ticketId;
        if (std::cin.fail())
        {
            std::cout << RED << "Error: Enter an integer!\n" << RESET;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (ticketId <= 0)
            std::cout << RED << "Error: Enter a positive number!\n" << RESET;
        else
            break;
    }

    if (tickets.empty())
    {
        std::cout << RED << "\nError: No tickets available!\n" << RESET;
        return;
    }

    std::cout << BOLD << YELLOW << "\n=== Search Results ===\n" << RESET;
    std::cout << BOLD << GREEN << std::left << std::setw(10) << "ID" << std::setw(15) << "Seat" << std::setw(30) << "Film" << std::setw(20) << "Hall" << RESET << "\n";
    std::cout << std::string(75, '-') << "\n";

    for (const auto ticket : tickets)
        if (ticket.ticketId == ticketId)
        {
            std::cout << MAGENTA << std::setw(10) << ticket.ticketId << RESET
                << CYAN << std::setw(15) << ticket.seatNum << RESET
                << YELLOW << std::setw(30) << (ticket.session && ticket.session->movie ? ticket.session->movie->filmName : "N/A") << RESET
                << BLUE << std::setw(20) << (ticket.session && ticket.session->hall ? ticket.session->hall->hallName : "N/A") << RESET << "\n";
            found = true;
            break;
        }

    if (!found)
        std::cout << RED << "Ticket with ID " << ticketId << " not found!\n" << RESET;
}
