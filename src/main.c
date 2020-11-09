/*
** PERSONAL PROJECT, 2020
** GOL
** File description:
** GOL
*/

#include "sim.h"

static int get_nb_loop(struct timespec fix_time)
{
    struct timespec actual = {0};
    size_t nb_sec = 0;
    long double nb_nsec = 0;

    clock_gettime(CLOCK_REALTIME, &actual);
    nb_sec = actual.tv_sec  - fix_time.tv_sec;
    nb_nsec = actual.tv_nsec  - fix_time.tv_nsec;
    return (nb_sec + (nb_nsec / BILLION)) * FPS;
}

static bool main_loop(const char *filepath)
{
    char **matrix = read_rec(filepath);
    vector_t before = {-1, -1};
    struct timespec fix_time = {0};
    int loop = 0;

    if (!matrix)
        return false;
    clock_gettime(CLOCK_REALTIME, &fix_time);
    while (!end_of_simulation(matrix)) {
        loop = get_nb_loop(fix_time);
        for (; loop > 0; loop--) {
            if (!sim_manage(&matrix, &before))
                return NULL;
            if (loop == 1)
                clock_gettime(CLOCK_REALTIME, &fix_time);
        }
    }
    return true;
}

int main(int ac, char **av)
{
    if (ac != 2)
        return EXIT_ERROR;
    if (!main_loop(av[1]))
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}