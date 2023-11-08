#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int X = rand() % 36 + 1;
    printf("%d: %s %s", X, (X % 2 ? "O" : "E"), (X <= 18 ? "M" : "P"));

    return 0;
}