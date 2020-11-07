/*
** PERSONAL PROJECT, 2020
** GOL
** File description:
** GOL
*/

#include "sim.h"

bool end_of_simulation(char **matrix)
{
    for (size_t y = 0; matrix[y]; y++) {
        for (size_t x = 0; matrix[y][x]; x++) {
            if (matrix[y][x] == ALIVE)
                return false;
        }
    }
    return true;
}