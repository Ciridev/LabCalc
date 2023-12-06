#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define NUM 3

typedef unsigned long long int u64;

int throw()
{
    return lrand48() % 6 + 1;
}

int* hist(int dices, int throws, int* count, int num)
{
    int* result = (int*)calloc(dices + 1, sizeof(int));

    for(int i = 0; i < throws; i++)
    {
        for(int j = 0; j < dices; j++)
        {
            if(throw() == num)
            {
                count[i]++;
            }
        }

        result[count[i]]++;
    }

    return result;
}

int main(int argc, char** argv)
{
    srand48(time(NULL));
    FILE* file = fopen("histogram.dat", "w+");
    if(!file) return 1;

    int num_dices = 20;
    int num_throws = 20;

    int* count = (int*)calloc(num_throws, sizeof(int));
    int* histogram = hist(num_dices, num_throws, count, NUM);

    for(int i = 0; i <= num_dices; i++)
    {
        fprintf(file, "%d %lf\n", i, histogram[i] / (double)num_throws);
    }

    fclose(file);
    free(count);

    return 0;
}