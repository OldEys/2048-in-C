#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int tabla[4][4] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int n = 4;
void generare_numar();
void afisare_ecran();
void mutarejos();
void mutaredreapta();
void mutarestanga();
void mutaresus();
int verif_castigator();
int verif_spatii();
int main()
{
    char optiune;
    char input;
    int castigator = 0;
    printf("doresti sa joci?(y/n) :\n");
    scanf("%c", &optiune);
    getchar();
    while (optiune == 'y')
    {
        generare_numar();
        while (castigator != 1 && verif_spatii() != 0)
        {
            // system("cls");
            printf("\e[1;1H\e[2J");//curatarea ecranului
            fflush(stdout);
            afisare_ecran();
            printf("dati input :(w/a/s/d)\n");
            do
            {
            scanf("%c", &input);
            getchar();

                if (input == 'w')
                    mutaresus();
                else if (input == 'a')
                    mutarestanga();
                else if (input == 's')
                    mutarejos();
                else if (input == 'd')
                    mutaredreapta();
                else
                {
                    printf("Mutare invalida\n");
                }
            } while (input != 'w' && input != 'a' && input != 's' && input != 'd');
                generare_numar();
            castigator = verif_castigator();
        }
        if (verif_castigator() == 1)
            printf("ai castigat :)\n");
        else
            printf("ai pierdut :(\n");

        printf("doresti sa joci?(y/n) :\n");
        scanf("%c", &optiune);
    }
}
void afisare_ecran()
{
    for (int i = 0; i < n; i++)
    {
        printf("----------------------------------------------------------------\n");
        for (int j = 0; j < n; j++)
        {
            printf("|\t");
            if (tabla[i][j] == 0)
                printf(" \t");
            else
                printf("%d\t", tabla[i][j]);
        }
        printf("|\n");
    }
}
void miscaresus(int i, int j)
{
    if ((tabla[i - 1][j] != 0 && tabla[i - 1][j] != tabla[i][j]) || i == 0)
        return;
    else if (tabla[i - 1][j] == tabla[i][j])
    {
        tabla[i - 1][j] = 2 * tabla[i][j];
        tabla[i][j] = 0;
    }
    else
    {
        tabla[i - 1][j] = tabla[i][j];
        tabla[i][j] = 0;
        miscaresus(i - 1, j);
    }
}
void mutaresus()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            miscaresus(i, j);
}
void miscarejos(int i, int j)
{
    if ((tabla[i + 1][j] != 0 && tabla[i + 1][j] != tabla[i][j]) || i == n - 1)
        return;
    else if (tabla[i + 1][j] == tabla[i][j])
    {
        tabla[i + 1][j] = 2 * tabla[i][j];
        tabla[i][j] = 0;
    }
    else
    {
        tabla[i + 1][j] = tabla[i][j];
        tabla[i][j] = 0;
        miscarejos(i + 1, j);
    }
}
void mutarejos()
{
    for (int i = n - 1; i >= 0; i--)
        for (int j = n - 1; j >= 0; j--)
            miscarejos(i, j);
}
void miscarestanga(int i, int j)
{
    if ((tabla[i][j - 1] != 0 && tabla[i][j - 1] != tabla[i][j]) || j == 0)
        return;
    else if (tabla[i][j - 1] == tabla[i][j])
    {
        tabla[i][j - 1] = 2 * tabla[i][j];
        tabla[i][j] = 0;
    }
    else
    {
        tabla[i][j - 1] = tabla[i][j];
        tabla[i][j] = 0;
        miscarestanga(i, j - 1);
    }
}
void mutarestanga()
{
    for (int j = 0; j < n; j++)
        for (int i = 0; i < n; i++)
            miscarestanga(i, j);
}
void miscaredreapta(int i, int j)
{
    if ((tabla[i][j + 1] != 0 && tabla[i][j + 1] != tabla[i][j]) || j == n - 1)
        return;
    else if (tabla[i][j + 1] == tabla[i][j])
    {
        tabla[i][j + 1] = 2 * tabla[i][j];
        tabla[i][j] = 0;
    }
    else
    {
        tabla[i][j + 1] = tabla[i][j];
        tabla[i][j] = 0;
        miscaredreapta(i, j + 1);
    }
}
void mutaredreapta()
{
    for (int j = n - 1; j >= 0; j--)
        for (int i = n - 1; i >= 0; i--)
            miscaredreapta(i, j);
}

int verif_spatii()
{
    int spatii_libere = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (tabla[i][j] == 0)
                spatii_libere++;
    return spatii_libere;
}
void generare_numar()
{
    srand(time(0));
    int a, b;
    do
    {
        a = rand() % 4;
        b = rand() % 4;
        if (tabla[a][b] == 0)
        {
            tabla[a][b] = 2;
            break;
        }
    } while (tabla[a][b] != 0);
}
int verif_castigator()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (tabla[i][j] == 2048)
                return 1;
    return 0;
}
