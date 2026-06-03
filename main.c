#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

static int parse_int(const char *text, int *value)
{
    char *end;
    long converted;

    if (text == NULL || *text == '\0')
        return (0);
    errno = 0;
    converted = strtol(text, &end, 10);
    if (errno != 0 || *end != '\0' || converted < INT_MIN || converted > INT_MAX)
        return (0);
    *value = (int)converted;
    return (1);
}

static int parse_arguments(int argc, char **argv, int *values)
{
    int i;

    i = 1;
    while (i < argc)
    {
        if (!parse_int(argv[i], &values[i - 1]))
            return (0);
        i++;
    }
    return (1);
}

int main(int argc, char **argv)
{
    int values[8];

    if (argc != 9)
    {
        printf("[ERROR] The number of arguments needs to be 8\n");
        return (1);
    }
    if (!parse_arguments(argc, argv, values))
    {
        printf("[ERROR] All arguments must be valid integers\n");
        return (1);
    }
    printf("%d\n", argc - 1);
    return (0);
}
