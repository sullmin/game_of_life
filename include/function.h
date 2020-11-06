/*
** PERSONNAL PROJECT, 2019
** GOL
** File description:
** GOL
*/

#ifndef FUNC_H
#define FUNC_H

#include "vector_t.h"

void merge_array(char **source, char **dest);
char **get_term_matrix(vector_t *size_term);
void display_term_matrix(char **matrix);
char **read_rec(const char *filepath);
void simulation(char **matrix);
vector_t get_term_size(void);
void destroy(void **tab);

#endif