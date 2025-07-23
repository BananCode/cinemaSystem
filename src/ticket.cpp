#include "ticket.h"
#include <iostream>
#include "colors.h"

std::vector<Ticket> tickets;

void addTicket(std::vector<Ticket>& tickets, int ticketId, Session* session, int seatNum) {
    if (session == nullptr || (session->hall && seatNum > session->hall->seatCount)) {
        std::cout << RED << "Помилка: некоректний сеанс або місце!" << RESET << std::endl;
        return;
    }
    for (const auto& ticket : tickets) {
        if (ticket.ticketId == ticketId) {
            std::cout << RED << "Цей ID квитка вже існує!" << RESET << std::endl;
            return;
        }
        if (ticket.session == session && ticket.seatNum == seatNum) {
            std::cout << RED << "Місце зайнято!" << RESET << std::endl;
            return;
        }
    }
    Ticket newTicket{ ticketId, session, seatNum };
    tickets.push_back(newTicket);
    std::cout << GREEN << "Квиток додано!" << RESET << std::endl;
}

void showTickets(std::vector<Ticket>& tickets)
{
    if (tickets.size() == 0)
        std::cout << RED << "\nКвитків ще не має\n" << RESET;
    else
        for (int i = 0; i < tickets.size(); i++)
        {
            std::cout << "\nКвиток " << i + 1 << ": ";
            std::cout << "\nАйді квитка: " << tickets[i].ticketId;
            std::cout << "\nНомер місця квитка: " << tickets[i].seatNum;
            std::cout << "\nЗал: " << tickets[i].session->hall->hallName;
            std::cout << "\nНазва фільму: " << tickets[i].session->movie->filmName << "\n";
        }
}
