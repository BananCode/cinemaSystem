#ifndef HALL_H
#define HALL_H

#include <string>
#include <vector>

struct Hall
{
	int hallId;              // ID залу
	std::string hallName;    // назва залу
	int seatCount;			 // кількість місць
};

extern std::vector<Hall> halls; // Глобальний вектор залів

void addHall(std::vector<Hall>& halls);                    // Додати новий зал
void showHalls(std::vector<Hall>& halls);                  // Вивід всіх залів
void editHallById(std::vector<Hall>& halls);               // Редагування залу за ID  
void removeHallById(std::vector<Hall>& halls);             // Видалення залу за ID
void searchHallsById(std::vector<Hall>& halls);			   // Пошук залів за ID

#endif
