/*
** PERSONAL PROJECT, 2020
** GOL
** File description:
** GOL
*/

#include "sim.h"

void destroy(void **tab)
{
    for (size_t i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}