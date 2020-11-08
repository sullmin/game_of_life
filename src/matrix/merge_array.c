/*
** PERSONAL PROJECT, 2020
** GOL
** File description:
** GOL
*/

#include "sim.h"

void merge_array(char **source, char **dest)
{
    for (size_t y = 0; dest[y] && source[y]; y++) {
        for (size_t x = 0; dest[y][x] && source[y][x]; x++) {
            dest[y][x] = source[y][x];
        }
    }
}