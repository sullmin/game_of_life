/*
** PERSONAL PROJECT, 2020
** GOL
** File description:
** GOL
*/

#include "sim.h"

static size_t count_neighbour_alive(char **matrix, vector_t *pos)
{
    size_t count = 0;

    for (ssize_t y = pos->y - 1; y <= pos->y + 1; y++) {
        for (ssize_t x = pos->x - 1; x <= pos->x + 1; x++) {
            if (x < 0 || y < 0 || !matrix[y] || !matrix[y][x])
                continue;
            if (matrix[y][x] == ALIVE || matrix[y][x] == NEXT_DEAD)
                count += (x == pos->x && y == pos->y) ? 0 : 1;
        }
    }
    return count;
}

static void i_am_deus(char **matrix, vector_t pos)
{
    size_t nb_alive = count_neighbour_alive(matrix, &pos);

    if (matrix[pos.y][pos.x] == ALIVE) {
        matrix[pos.y][pos.x] = (nb_alive == 2 || nb_alive == 3) ? ALIVE : NEXT_DEAD;
    } else {
        matrix[pos.y][pos.x] = (nb_alive == 3) ? NEXT_ALIVE : EMPTY;
    }
}

void simulation(char **matrix)
{
    for (size_t y = 0; matrix[y]; y++) {
        for (size_t x = 0; matrix[y][x]; x++) {
            i_am_deus(matrix, (vector_t) {x, y});
        }
    }
    for (size_t y = 0; matrix[y]; y++) {
        for (size_t x = 0; matrix[y][x]; x++) {
            if (matrix[y][x] == NEXT_ALIVE)
                matrix[y][x] = ALIVE;
            else if (matrix[y][x] == NEXT_DEAD)
                matrix[y][x] = EMPTY;
        }
    }
}