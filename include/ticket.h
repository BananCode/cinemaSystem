#ifndef TICKET_H
#define TICKET_H

struct Session;

struct Ticket
{
    int id;              
    Session* session;    
    int seatNumber;      
};

#endif
