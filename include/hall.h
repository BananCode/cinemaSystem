#ifndef HALL_H
#define HALL_H

#include <string>
#include <vector>

struct Hall
{
	int hallId;              // ID залу
	std::string hallName;    // назва залу
	int seatCount;	         // кількість місць
};

extern std::vector<Hall> halls;

void addHall(std::vector<Hall>& halls); 
void showHall(std::vector<Hall>& halls);

#endif
