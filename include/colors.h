#ifndef COLORS_H
#define COLORS_H

#define RESET     "\033[0m"
#define BLACK     "\033[30m"
#define RED       "\033[31m"
#define GREEN     "\033[32m"
#define YELLOW    "\033[33m"
#define BLUE      "\033[34m"
#define MAGENTA   "\033[35m"
#define CYAN      "\033[36m"
#define WHITE     "\033[37m"

#define BOLD      "\033[1m"
#define UNDERLINE "\033[4m"

#define INFO(msg)    std::cout << CYAN << "[INFO] " << RESET << msg << std::endl
#define SUCCESS(msg) std::cout << GREEN << "[SUCCESS] " << RESET << msg << std::endl
#define ERROR(msg)   std::cout << RED << "[ERROR] " << RESET << msg << std::endl
#define WARN(msg)    std::cout << YELLOW << "[WARNING] " << RESET << msg << std::endl

#endif
