
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hanoi.h"

int MAX_DISQUES = 64;

void fill_nombre_disque(int tab[])
{
    for (int i = 0; i < MAX_DISQUES; i++)
        tab[i] = i + 1;
}

void write_in(char *filname, int nombre_disques, double duration)
{
    FILE *fichier = fopen(filname, "a");
    fprintf(fichier, "Nombre disque %d : Temps : %lf \n", nombre_disques, duration);
    fclose(fichier);
}

int main()
{

    int NOMBRE_DISQUE[MAX_DISQUES];

    fill_nombre_disque(NOMBRE_DISQUE);

    clock_t start, end;

    for (int i = 0; i < MAX_DISQUES; i++)
    {
        char tour_A = 'A';
        char tour_B = 'B';
        char tour_C = 'C';

        start = clock();
        play_hanoi(NOMBRE_DISQUE[i], tour_A, tour_B, tour_C);
        end = clock();

        double duration = ((double)end - start) / CLOCKS_PER_SEC;
        write_in("hanoi_result.txt", NOMBRE_DISQUE[i], duration);
    }

    return 0;
}