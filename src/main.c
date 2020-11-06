/*
** PERSONAL PROJECT, 2020
** GOL
** File description:
** GOL
*/

#include "sim.h"

int main(int ac, __attribute__((unused)) char **av)
{
    char **matrix = NULL;

    if (ac != 2)
        return EXIT_ERROR;
    matrix = get_term_matrix();
    display_term_matrix(matrix);
    destroy((void **) matrix);
    return EXIT_SUCCESS;
}