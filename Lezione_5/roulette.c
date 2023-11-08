#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10003838

int main()
{
    srand(time(NULL));
    FILE* file = fopen("isto.dat", "w+");

    // EM, EP, OM, OP
    int frequencies[4] = {0};
    int occurencies[36] = {0};

    for(int i = 0; i < N; i++)
    {
        int X = rand() % 36 + 1;
        printf("Throw #%d\n", i);
        printf("%d: %s %s\n\n", X, (X % 2 ? "O" : "E"), (X <= 18 ? "M" : "P"));

        frequencies[(X % 2) * 2 + (X > 18)]++;
        occurencies[X % 36]++;
    }

    // Print all the frequencies
    printf(
        "[EM : %lf], [EP : %lf], [OM : %lf], [OP : %lf]", 
        (double)frequencies[0] / N,
        (double)frequencies[1] / N,
        (double)frequencies[2] / N,
        (double)frequencies[3] / N
    );

    for(int i = 0; i < 36; i++)
    {
        fprintf(file, "%d %d %lf\n", i + 1, occurencies[i], (double)occurencies[i] / N);
    }

    fclose(file);

    return 0;
}