#define FRIEND_SIZE 5
#define BINARY_FILE "StaffRecords.dat"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4996)

void saveFriendList();
void displayFriendList();

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char name[50];
    Date dateOfBirth;
    char gender;
} Friend;

Friend friendList[FRIEND_SIZE] =
{
    { "Koo", 25, 10, 1991, 'M' },
    { "Ng" ,  3,  3, 1991, 'F' },
    { "Lim", 29,  2, 2000, 'M' },
    { "Chan", 1,  1, 1999, 'F' },
    { "Tan", 11, 12, 1993, 'M' }
};

int main()
{
    saveFriendList();

    puts("");
    displayFriendList();

    return 0;
}


void saveFriendList()
{
    FILE *fOutput = fopen(BINARY_FILE, "wb"); // write to binary file

    if (fOutput != NULL)
    {
        for (int i = 0; i < FRIEND_SIZE; i++)
        {
            fwrite(&friendList[i], sizeof(friendList[i]), 1, fOutput);
        }

        printf("%s created successfully! \n", BINARY_FILE);
        fclose(fOutput);
    }
}


void displayFriendList()
{
    FILE *fInput = fopen(BINARY_FILE, "rb"); // read from file content

    if (fInput != NULL)
    {
        Friend friend;

        printf("Reading %s... \n\n", BINARY_FILE);

        do
        {
            fread(&friend, sizeof(friend), 1, fInput);

            if (!feof(fInput))
            {
                printf("Name   : %s \n", friend.name);

                printf("DOB    : %d/%d/%d \n",
                    friend.dateOfBirth.day,
                    friend.dateOfBirth.month,
                    friend.dateOfBirth.year);

                printf("Gender : %c \n", friend.gender);

                puts("");
            }
        } while (!feof(fInput));

        fclose(fInput);
    }
}
