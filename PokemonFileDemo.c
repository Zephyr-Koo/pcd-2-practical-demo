/*
    NOTE: You can use .txt extension for binary file as well if you
          want to although it's not recommended. It's just a convention
          to use .bin/.dat to indicate a binary formatted file.
*/

#define TEXT_FILE   "POKEMON_TEXT.txt"
#define BINARY_FILE "POKEMON_BINARY.dat"

#define TEXT_WRITE_FORMAT "%s|%s|%d\n"
#define TEXT_READ_FORMAT "%[^|]|%[^|]|%d\n"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4996)

void createTextFile(),
     createBinaryFile();
     
void readTextFile(),
     readBinaryFile();

void deleteElectricPokemons(),
     deletePokemonsFromTextFile(char*),
     deletePokemonsFromBinaryFile(char*);

// This approach was inspired by Mr Shoong
void deletePokemonsWithTempFile(char*);

typedef struct {
    char name[20],
         type[20];
    int  hp;
} Pokemon;

Pokemon pokemonList[5] =
{
   { "Pikachu", "Electric", 777 },
   { "Charizard", "Fire", 3333 },
   { "Magikarp", "Water", 111 },
   { "Articuno", "Ice", 5555 },
   { "Zapdos", "Electric", 5555 },
};

int main()
{
    createTextFile();
    createBinaryFile();

    deleteElectricPokemons(); // Try comment it and observe the file output

    puts("");
    readTextFile();

    puts("");
    readBinaryFile();

    return 0;
}

void createTextFile()
{
    FILE *fOutput = fopen(TEXT_FILE, "w");

    if (fOutput != NULL)
    {
        for (int i = 0; i < 5; i++)
        {
            fprintf(fOutput, TEXT_WRITE_FORMAT, pokemonList[i].name, pokemonList[i].type, pokemonList[i].hp);
        }

        printf("%s   created successfully! =) \n", TEXT_FILE);
        fclose(fOutput);
    }
    else
    {
        puts("Failed to write text file. =(");
    }
}

void createBinaryFile()
{
    FILE *fOutput = fopen(BINARY_FILE, "wb");

    if (fOutput != NULL)
    {
        for (int i = 0; i < 5; i++)
        {
            fwrite(&pokemonList[i], sizeof(pokemonList[i]), 1, fOutput);
        }

        printf("%s created successfully! =) \n", BINARY_FILE);
        fclose(fOutput);
    }
    else
    {
        puts("Failed to write binary file. =(");
    }
}

void readTextFile()
{
    FILE *fInput = fopen(TEXT_FILE, "r");

    if (fInput != NULL)
    {
        Pokemon pokemon;

        printf("Reading %s... \n\n", TEXT_FILE);

        while (fscanf(fInput, TEXT_READ_FORMAT, pokemon.name, pokemon.type, &pokemon.hp) != EOF)
        {
            printf("Name: %s \n", pokemon.name);
            printf("Type: %s \n", pokemon.type);
            printf("HP  : %d \n", pokemon.hp);
            puts("");
        }

        fclose(fInput);
    }
}

void readBinaryFile()
{
    FILE *fInput = fopen(BINARY_FILE, "rb");

    if (fInput != NULL)
    {
        Pokemon pokemon;

        printf("Reading %s... \n\n", BINARY_FILE);

        do
        {
            fread(&pokemon, sizeof(Pokemon), 1, fInput);
            
            if (!feof(fInput))
            {
                printf("Name: %s \n", pokemon.name);
                printf("Type: %s \n", pokemon.type);
                printf("HP  : %d \n", pokemon.hp);
                puts("");
            }
        } while (!feof(fInput));

        fclose(fInput);
    }
}

void deleteElectricPokemons()
{
    char type[] = "Electric";

    deletePokemonsFromTextFile(type);
    deletePokemonsFromBinaryFile(type);

    //deletePokemonsWithTempFile(type);
}

void deletePokemonsFromTextFile(char *type)
{
    FILE *fInput = fopen(TEXT_FILE, "r");

    int index = 0;
    Pokemon pokemons[100]; // assume there are maximum 100 pokemons in the file
    

    if (fInput != NULL)
    {
        while (fscanf(fInput, TEXT_READ_FORMAT, pokemons[index].name, pokemons[index].type, &pokemons[index].hp) != EOF)
        {
            index++;
        }

        fclose(fInput);
    }

    FILE *fOutput = fopen(TEXT_FILE, "w"); // rewrite the same file with new content

    if (fOutput != NULL)
    {
        for (int i = 0; i < index; i++)
        {
            // Keep the records that doesn't match the delete criteria
            if (strcmp(pokemons[i].type, type) != 0)
            {
                fprintf(fOutput, TEXT_WRITE_FORMAT, pokemonList[i].name, pokemonList[i].type, pokemonList[i].hp);
            }
        }

        printf("%s   updated successfully! =) \n", TEXT_FILE);
        fclose(fOutput);
    }
    else
    {
        puts("Failed to modify text file. =(");
    }
}


void deletePokemonsFromBinaryFile(char *type)
{
    FILE *fInput = fopen(BINARY_FILE, "rb");

    int index = 0;
    Pokemon pokemons[100]; // assume there are maximum 100 pokemons in the file

    if (fInput != NULL)
    {
        do
        {
            fread(&pokemons[index], sizeof(Pokemon), 1, fInput);

            if (!feof(fInput))
            {
                index++;
            }
        } while (!feof(fInput));

        fclose(fInput);
    }

    FILE *fOutput = fopen(BINARY_FILE, "wb"); // rewrite the same file with new content

    if (fOutput != NULL)
    {
        for (int i = 0; i < index; i++)
        {
            // Keep the records that doesn't match the delete criteria
            if (strcmp(pokemons[i].type, type) != 0)
            {
                fwrite(&pokemons[i], sizeof(pokemons[i]), 1, fOutput);
            }
        }

        printf("%s   updated successfully! =) \n", TEXT_FILE);
        fclose(fOutput);
    }
    else
    {
        puts("Failed to modify text file. =(");
    }
}

void deletePokemonsWithTempFile(char *type)
{
    char tempFile[]         = "temp.txt";
    char deleteCommand[100] = "del ";
    char renameCommand[100] = "ren ";

    FILE *fInput  = fopen(TEXT_FILE, "r"),
         *fOutput = fopen(tempFile, "w");

    int     index = 0;
    Pokemon pokemons[100]; // assume there are maximum 100 pokemons in the file


    if (fInput != NULL && fOutput != NULL)
    {
        while (fscanf(fInput, TEXT_READ_FORMAT, pokemons[index].name, pokemons[index].type, &pokemons[index].hp) != EOF)
        {
            index++;
        }

        for (int i = 0; i < index; i++)
        {
            // Keep the records that doesn't match the delete criteria
            if (strcmp(pokemons[i].type, type) != 0)
            {
                fprintf(fOutput, TEXT_WRITE_FORMAT, pokemonList[i].name, pokemonList[i].type, pokemonList[i].hp);
            }
        }

        // Close the file stream before modification (delete/rename)
        fclose(fInput);
        fclose(fOutput);

        strcat(deleteCommand, TEXT_FILE);  // del POKEMON_TEXT.txt
        strcat(renameCommand, tempFile);   // ren temp.txt
        strcat(renameCommand, " ");        // ren temp.txt (space)
        strcat(renameCommand, TEXT_FILE);  // ren temp.txt POKEMON_TEXT.txt

        system(deleteCommand);
        system(renameCommand);
    }
}
