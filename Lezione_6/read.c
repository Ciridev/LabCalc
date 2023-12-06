#include <stdio.h>

int main(int argc, char** argv)
{
    FILE* file = fopen("temperatures.dat", "r");
    if(!file)
    {
        printf("File not opened!");
        return 1;
    }

    int data[36] = {0};
    double averages[12] = {0};

    printf("Month\t Min T\t Max T\t Average\n");
    for(int i = 0; i < 12; i++)
    {
        fscanf(
            file, 
            "%d %d %d",
            &data[3 * i],
            &data[3 * i + 1],
            &data[3 * i + 2]
        );

        averages[i] = (data[3 * i + 1] + data[3 * i + 2]) / 2.0;

        printf(
            "%d\t%d\t%d\t%lf\n",
            data[3 * i],
            data[3 * i + 1],
            data[3 * i + 2],
            averages[i]
        );
    }

    fclose(file);
    return 0;
}