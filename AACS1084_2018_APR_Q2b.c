#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable: 4996)

int main()
{
    // (i) START
    FILE *fPtr1, *fPtr2;
    // (i) END

    // (ii) START
    fPtr1 = fopen("temperature.txt", "r");
    fPtr2 = fopen("averageTemp.txt", "w");
    // (ii) END

    // (iii) START
    if (fPtr1 == NULL || fPtr2 == NULL)
    {
        puts("Unable to open the file(s)");
        exit(-1);
    }
    // (iii) END

    // (iv) START
    int noOfWeek,
        temperatureMON,
        temperatureTUE,
        temperatureWED,
        temperatureTHU,
        temperatureFRI,
        temperatureSAT,
        temperatureSUN;

    double averageTemperature;

    char rowHeader[100];

    fscanf(fPtr1, "%[^\n]\n", rowHeader); // move cursor to next row

    while (fscanf(fPtr1,
        "%d %d %d %d %d %d %d %d\n",
        &noOfWeek,
        &temperatureMON,
        &temperatureTUE,
        &temperatureWED,
        &temperatureTHU,
        &temperatureFRI,
        &temperatureSAT,
        &temperatureSUN) != EOF)
    {
        averageTemperature = (temperatureMON + 
                              temperatureTUE +
                              temperatureWED +
                              temperatureTHU +
                              temperatureFRI +
                              temperatureSAT +
                              temperatureSUN) / 7.0;

        fprintf(fPtr2, "%d %.2f \n", noOfWeek, averageTemperature);
    }

    fclose(fPtr1);
    fclose(fPtr2);
    // (iv) END

    puts("");
    return 0;
}
