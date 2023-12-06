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

    // Initialize sortAverage
    double sortAverage[12][2] = {0};
    for(int i = 0; i < 12; i++)
    {
        sortAverage[i][0] = i + 1.0;
        sortAverage[i][1] = averages[i];
    }

    // Sort the array.
    for(int i = 0; i < 12; i++)
    {
        for(int j = i + 1; j < 12; j++)
        {
            if(sortAverage[i][1] < sortAverage[j][1])
            {
                double temp = sortAverage[i][1];
                sortAverage[i][1] = sortAverage[j][1];
                sortAverage[j][1] = temp;

                temp = sortAverage[i][0];
                sortAverage[i][0] = sortAverage[j][0];
                sortAverage[j][0] = temp;
            }
        }
    }

    // Classify the array.
    int marks[12] = {0};
    for(int i = 0; i < 12; i++)
    {
        marks[(int)sortAverage[i][0]] = 12 - i;
    }

    FILE* avgFile = fopen("averages.dat", "w+");
    if(!avgFile) 
    {
        printf("File not opened!");
        return 1;
    }

    printf("\n\n\nMonth\t Min T\t Max T\t Average\t Marks\n");
    for(int i = 0; i < 12; i++)
    {
        printf(
            "%d\t%d\t%d\t%lf\t%d\n",
            data[3 * i],
            data[3 * i + 1],
            data[3 * i + 2],
            averages[i],
            marks[i]
        );

        fprintf(avgFile,
            "%d\t%d\t%d\t%lf\t%d\n",
            data[3 * i],
            data[3 * i + 1],
            data[3 * i + 2],
            averages[i],
            marks[i]
        );
    }

    fclose(file);
    return 0;
}
