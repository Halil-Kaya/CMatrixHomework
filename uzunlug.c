#include<stdio.h>
#include<stdlib.h>
#include <time.h>



int main(){

    char* cumleler[2];

    cumleler[0] = "halil kaya";

    printf("%s",cumleler[0]);

    int cumleninUzunlugu = 0;
    while (cumleler[0][cumleninUzunlugu] != '\0')
    {
        cumleninUzunlugu++;
    }

    printf("\ncumlenin uzunlugu: %d",cumleninUzunlugu);
    



    return 0;
}
