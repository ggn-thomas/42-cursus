
#include <stdio.h>
int main()
{
    int fd;
    char    *tab;
    int i;

    i = 1;
    fd = open("test.txt", O_RDONLY);
    while ((tab = get_next_line(fd)))
    {
        printf("appel %d", i);
        printf(":\n%s", tab);
        free(tab);
        i++;
    }
   close(fd);
    return (0);
}