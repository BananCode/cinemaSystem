#ifndef TICKET_H
#define TICKET_H

#include <vector>
#include "session.h"

struct Session;

struct Ticket
{
    int ticketId;               // Унікальний ідентифікатор квитка
    Session* session;           // Вказівник на сеанс, на який придбано квиток
    int seatNum;                // Номер місця, яке займає квиток у залі
};

extern std::vector<Ticket> tickets;

void addTicket(std::vector<Ticket>& tickets, std::vector<Session>& sessions);
void showTicket(std::vector<Ticket>& tickets);
void editTicketById(std::vector<Ticket>& tickets);
void removeTicketById(std::vector<Ticket>& tickets);

#endif
