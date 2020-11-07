/*
** PERSONAL PROJECT, 2020
** GOL
** File description:
** GOL
*/

#include "sim.h"

void display_term_matrix(char **matrix)
{
    for (size_t y = 0; matrix[y + 2]; y++) {
        for (size_t x = 0; matrix[y][x]; x++) {
            fprintf(stdout, "%c", matrix[y][x]);
        }
        if (matrix[y + 2])
            fprintf(stdout, "\n");
    }
}