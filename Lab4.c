#include <stdio.h>
#include <string.h>

#define LEN 4

char *strnsub(char *p, int n);

int main()
{
    char line[] = "His textbook was bought from that bookstore";  
    char *p1, *p2;

    for (p1 = line; *p1 != '\0'; ++p1)
        for (p2 = p1 + 1; *p2 != '\0'; ++p2)
            if (strncmp(p1, p2, 4) == 0)
                goto done;

done:
    printf ("the first substring: %s\n", strnsub(p1, LEN));
    printf ("the second substring: %s\n", strnsub(p2, LEN));

    return 0;
}

char *strnsub(char *p, int n)
{
    static char buffer[64];

    sprintf(buffer, "%.*s", n, p);

    return buffer;
}
