/*
** EPITECH PROJECT, 2024
** map
** File description:
** map
*/

#include <stddef.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include "conway.h"
#include "string.h"

static int my_strlen_c(char *line, char c)
{
    int len = 0;

    if (line == 0)
        return -1;
    for (; line[len] != c; len++);
    return len;
}

static char *backline_to_endline(char *line)
{
    line[my_strlen_c(line, '\n')] = '\0';
    return line;
}

static char **loop(FILE *fd, char **map, int const len)
{
    char *line = 0;
    size_t size = 0;
    int i = 1;

    for (; getline(&line, &size, fd) != -1; i++) {
        if (my_strlen_c(line, '\n') != len) {
            map[i] = 0;
            free_strarray(map);
            free(line);
            return 0;
        }
        map[i] = strdup(backline_to_endline(line));
    }
    map[i] = 0;
    free(line);
    return map;
}

static char **fill_map(FILE *fd, struct stat *sb)
{
    char *line = 0;
    size_t size = 0;
    char **map;
    int len;

    if (getline(&line, &size, fd) == -1) {
        free(line);
        return 0;
    }
    len = my_strlen_c(line, '\n');
    map = malloc(sizeof(char *) * ((sb->st_size / (len + 1) + 1)));
    if (map == 0)
        return 0;
    map[0] = strdup(backline_to_endline(line));
    map = loop(fd, map, len);
    free(line);
    return map;
}

static int is_map_valid(char **map)
{
    int isvalid = 1;

    for (int i = 0; map[i] != NULL && isvalid == 1; i++) {
        for (int j = 0; map[i][j] != '\0' && isvalid == 1; j++) {
            isvalid = (map[i][j] == 'X' || map[i][j] == '.') ? 1 : 0;
        }
    }
    return isvalid;
}

char **get_map(char const *filename)
{
    struct stat sb;
    FILE *fd;
    char **map;

    if (stat(filename, &sb) == -1) {
        perror("stat");
        return 0;
    }
    fd = fopen(filename, "r");
    if (fd == 0)
        return 0;
    map = fill_map(fd, &sb);
    fclose(fd);
    if (map == 0 || is_map_valid(map))
        return map;
    free_strarray(map);
    return 0;
}
