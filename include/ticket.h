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

extern std::vector<Ticket> tickets; // Глобальний вектор квитків

void addTicket(std::vector<Ticket>& tickets, std::vector<Session>& sessions);  // Додати новий квиток
void showTicket(std::vector<Ticket>& tickets);                                 // Вивід всіх квитків
void editTicketById(std::vector<Ticket>& tickets);                             // Редагування квитка за ID  
void removeTicketById(std::vector<Ticket>& tickets);                           // Видалення квитка за ID
void searchTicketsById(std::vector<Ticket>& tickets);                          // Пошук квитків за ID

#endif
