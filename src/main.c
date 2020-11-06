/*
** PERSONAL PROJECT, 2020
** GOL
** File description:
** GOL
*/

#include "sim.h"

static bool main_loop(const char *filepath)
{
    char **matrix = read_rec(filepath);
    char **source = NULL;
    vector_t before = {-1, -1};
    vector_t act = {-1, -1};
    struct timespec fix_time = {0};
    struct timespec actual = {0};
    size_t loop = 0;

    if (!matrix)
        return false;
    clock_gettime(CLOCK_MONOTONIC_RAW, &fix_time);
    while (true) {
        clock_gettime(CLOCK_MONOTONIC_RAW, &actual);
        loop = actual.tv_sec  - fix_time.tv_sec;
        actual.tv_sec = 0;
        while (loop > 0) {
            //start
            act = get_term_size();
            if (!matrix || before.x != act.x || before.y != act.y) {
                before = act;
                source = matrix;
                matrix = get_term_matrix(&act);
                merge_array(source, matrix);
                if (source) {
                    destroy((void **) source);
                    source = NULL;
                }
                if (!matrix)
                    return false;
            }
            simulation(matrix);
            fprintf(stdout, "\e[1;1H\e[2J");
            fflush(stdout);
            display_term_matrix(matrix);
            //end
            if (loop == 1)
                clock_gettime(CLOCK_MONOTONIC_RAW, &fix_time);
            loop--;
        }
    }
    return true;
}

int main(int ac, __attribute__((unused)) char **av)
{
    if (ac != 2)
        return EXIT_ERROR;
    if (!main_loop(av[1]))
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}