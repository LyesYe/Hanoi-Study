void play_hanoi(int nombre_disque,char tour_A,char tour_B,char tour_C);


void play_hanoi(int nombre_disque,char tour_A,char tour_B,char tour_C) {    
    if (nombre_disque != 0){
        play_hanoi(nombre_disque-1,tour_A,tour_B,tour_C);
        // printf("Deplacement du disque de %c vers %c \n",tour_A,tour_C);
        play_hanoi(nombre_disque-1,tour_B,tour_C,tour_A);
    }
}