/*
** PERSONAL PROJECT, 2020
** GOL
** File description:
** GOL
*/

#include "sim.h"

static bool rec_call_read(FILE *file, size_t pos, char ***load)
{
    char *line = NULL;
    size_t size = 0;
    ssize_t ret = getline(&line, &size, file);

    if (ret == -1 || pos > LIMIT_SIZE) {
        *load = malloc(sizeof(char *) * (pos + 1));
        if (!(*load))
            return false;
    } else {
        if (line && line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = '\0';
        if (!rec_call_read(file, pos + 1, load))
            return false;
    }
    (*load)[pos] = (ret == -1 || pos > LIMIT_SIZE) ? NULL : line;
    return true;
}

char **read_rec(const char *filepath)
{
    FILE *file = fopen(filepath, "r");
    char **load = NULL;

    if (file == NULL)
        return NULL;
    if (!rec_call_read(file, 0, &load))
        return NULL;
    fclose(file);
    return load;
}