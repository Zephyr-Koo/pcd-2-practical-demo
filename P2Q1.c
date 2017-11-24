#include <stdio.h>
#include <string.h>
#pragma warning(disable: 4996)

typedef struct {
    char   artist[50];
    char   album[80];
    int    yearOfRelease;
    double price;
    int    totalPlayingTime;
} Cd;

int main()
{
    // (a)
    Cd cdList[10] =
    {
        { "Epik High", "We've Done Something Beautiful", 2017, 119.90, 43 },
        { "BTS", "Love Yourself: Her", 2017, 132.90, 73 },
        { "Urban Zakapa", "Moai (Seo Taiji Remake)", 2017, 4.90, 4 },
        { "Bolbbalgan4", "Red Diary Page. 1", 2017, 89.90, 32 },
        { "Heize", "And July", 2016, 79.90, 42 },
        { "BTS", "The Most Beautiful Moment in Life", 2015, 99.90, 52 },
        { "AKMU", "Play", 2014, 89.90, 69 },
        { "Epik High", "Shoebox", 2014, 89.90, 55 },
        { "BTS", "Dark & Wild", 2014, 74.90, 47 },
        { "Block B", "HER", 2014, 88.80 , 30 }
    };

    // (b)

    /*puts("Artist \t\t Album \t\t\t Year released \t Price \t\t Playing Time(min)");
    puts("------------------------------------------------------------------------------------------");

    for (int i = 0; i < 10; i++)
    {
        char shortenedAlbum[19] = "";

        if (strlen(cdList[i].album) < 15)
        {
            strcpy(shortenedAlbum, cdList[i].album);
        }
        else
        {
            strncpy(shortenedAlbum, cdList[i].album, 15);
            strcat(shortenedAlbum, "...");
        }

        printf("%-12s \t %-15s \t %d \t\t %6.2f \t %2d\n",
            cdList[i].artist, shortenedAlbum, cdList[i].yearOfRelease,
            cdList[i].price, cdList[i].totalPlayingTime);
    }

    puts("\n");*/

    // (c)
    
    /*int noOfAlbumBefore2016 = 0;

    puts("[ ALBUM BEFORE 2016 ]");
    puts("Artist \t\t Album \t\t\t Year released \t Price \t\t Playing Time(min)");
    puts("------------------------------------------------------------------------------------------");

    for (int i = 0; i < 10; i++)
    {
        if (cdList[i].yearOfRelease >= 2016)
            continue;

        char shortenedAlbum[19] = "";

        if (strlen(cdList[i].album) < 15)
        {
            strcpy(shortenedAlbum, cdList[i].album);
        }
        else
        {
            strncpy(shortenedAlbum, cdList[i].album, 15);
            strcat(shortenedAlbum, "...");
        }

        printf("%-12s \t %-15s \t %d \t\t %6.2f \t %2d\n",
            cdList[i].artist, shortenedAlbum, cdList[i].yearOfRelease,
            cdList[i].price, cdList[i].totalPlayingTime);

        noOfAlbumBefore2016++;
    }

    printf("\n%d record(s) found for album before year 2016.", noOfAlbumBefore2016);
    puts("\n");*/
    
    // (d) Input: "BTS"

    /*char performerName[50];
    int  noOfAlbumByPerformer = 0;

    printf("Performer's Name to search: ");
    gets(performerName);

    puts("\nCD Name \t\t\t\t Year released \t Price \t\t Playing Time(min)");
    puts("------------------------------------------------------------------------------------------");

    for (int i = 0; i < 10; i++)
    {
        if (strcmp(cdList[i].artist, performerName) == 0)
        {
            printf("%-35s \t %d \t\t %6.2f \t %2d\n",
                cdList[i].album, cdList[i].yearOfRelease,
                cdList[i].price, cdList[i].totalPlayingTime);

            noOfAlbumByPerformer++;
        }
    }

    printf("\n%d record(s) found for Performer's Name = %s",
        noOfAlbumByPerformer, performerName);
    puts("\n");*/
    
    // (e) Input: "BTS" | 100

    char   performerName[50];
    double maxPrice, totalPrice = 0;
    int    noOfAlbumBelowMaxPrice = 0;

    printf("Performer's Name to search: ");
    gets(performerName);

    printf("Maximum album price (RM)  : ");
    scanf("%lf", &maxPrice);

    puts("\nCD Name \t\t\t\t Year released \t Price \t\t Playing Time(min)");
    puts("------------------------------------------------------------------------------------------");

    for (int i = 0; i < 10; i++)
    {
        if (strcmp(cdList[i].artist, performerName) == 0 &&
            cdList[i].price <= maxPrice)
        {
            printf("%-35s \t %d \t\t %5.2f \t\t %2d\n",
                cdList[i].album, cdList[i].yearOfRelease,
                cdList[i].price, cdList[i].totalPlayingTime);

            noOfAlbumBelowMaxPrice++;
            totalPrice += cdList[i].price;
        }
    }

    printf("\n%d record(s) found for album by %s under   RM %.2lf.",
        noOfAlbumBelowMaxPrice, performerName, maxPrice);

    if (noOfAlbumBelowMaxPrice > 0)
    {
        printf("\nThe total cost to purchase these albums is RM %.2lf.", totalPrice);
    }

    puts("\n");
    return 0;
}
