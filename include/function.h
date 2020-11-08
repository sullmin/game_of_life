/*
** PERSONNAL PROJECT, 2019
** GOL
** File description:
** GOL
*/

#ifndef FUNC_H
#define FUNC_H

#include <stdbool.h>
#include "vector_t.h"

bool sim_manage(char ***matrix, vector_t *before);
void merge_array(char **source, char **dest);
char **get_term_matrix(vector_t *size_term);
void display_term_matrix(char **matrix);
bool end_of_simulation(char **matrix);
char **read_rec(const char *filepath);
vector_t get_term_size(void);
void destroy(void **tab);

#endif