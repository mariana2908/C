#include <stdio.h>
#include <ctype.h>

int main(void)
{
    printf("Hello, World\n");

    char *name;
    printf("Name: ");
    scanf("%s", &name);

    printf("Hello, %s\n", name);
    return 0;
}