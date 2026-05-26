#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    (void)argv;
    if (argc != 9)
    {
        printf("[ERROR] The number of arguments needs to be 8.");
        return 1;
    }
    printf("%d", argc - 1);
    return 0;
}