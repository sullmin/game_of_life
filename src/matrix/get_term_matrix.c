/*
** PERSONAL PROJECT, 2020
** GOL
** File description:
** GOL
*/

#include "sim.h"

vector_t get_term_size(void)
{
    struct winsize window;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &window);
    return (vector_t) {window.ws_col, window.ws_row} ;
}

char **get_term_matrix(vector_t *size_term)
{
    char **matrix = NULL;

    matrix = malloc(sizeof(char *) * (size_term->y + 1));
    if (!matrix)
        return NULL;
    matrix[size_term->y] = NULL;
    for (ssize_t i = 0; i < size_term->y; i++) {
        matrix[i] = malloc(sizeof(char) * (size_term->x + 1));
        if (!matrix[i])
            return NULL;
        matrix[i][size_term->x] = '\0';
        for (ssize_t x = 0; x < size_term->x; x++)
            matrix[i][x] = EMPTY;
    }
    return matrix;
}