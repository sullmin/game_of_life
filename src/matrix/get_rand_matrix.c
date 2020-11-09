/*
** PERSONAL PROJECT, 2020
** GOL
** File description:
** GOL
*/

#include "sim.h"

char **get_rand_matrix(void)
{
    size_t rand_val = 0;
    vector_t size_term = get_term_size();
    char **matrix = get_term_matrix(&size_term);

    if (!matrix)
        return NULL;
    for (ssize_t y = 0; matrix[y]; y++) {
        for (ssize_t x = 0; matrix[y][x]; x++) {
            rand_val = rand() % 100;
            matrix[y][x] = (rand_val < RAND_FILL_PROB) ? ALIVE : EMPTY;
        }
    }
    return matrix;
}