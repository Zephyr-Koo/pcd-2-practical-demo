#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4996)

int main()
{
#pragma region Q1b (i) (4 marks)
    struct product {
        char   prodName[20],
               grade[3];
        int    weight;
        double price;
    };
#pragma endregion Q1b (i) (4 marks)

#pragma region Q1b (ii) (5 marks)
    struct product
        localFruit,
        seasonFruit = { "Durian", "D18", 1, 18.5 };
#pragma endregion Q1b (ii) (5 marks)

#pragma region Q1b (iii) (5 marks)
    typedef struct {
        char supName[30],
             phoneNo[12];
        struct product fruit[20];
    } SUPPLIER;
    
    SUPPLIER supplier;
#pragma endregion Q1b (iii) (5 marks)

#pragma region Q1b (iv) (7 marks)
    int index = 0;

    do
    {
        printf("Enter product name : ");
        gets(supplier.fruit[index].prodName);

        printf("Enter grade        : ");
        gets(supplier.fruit[index].grade);

        printf("Enter weight       : ");
        scanf("%d", &supplier.fruit[index].weight);

        printf("Enter price        : ");
        scanf("%lf", &supplier.fruit[index].price);

        puts("");
        rewind(stdin);
        index++;

    } while (index < 20 && strcmp(supplier.fruit[index].prodName, "-1") != 0);
#pragma endregion Q1b (iv) (7 marks)

    return 0;
}
