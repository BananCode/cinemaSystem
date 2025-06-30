#ifndef SESSION_H
#define SESSION_H

#include <string>

struct Film;
struct Hall;

struct Session
{
	int id;
	Film* film;          
	Hall* hall;          
	std::string time;    
};

#endif
