#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

srand(time(0));
int num_j = rand() % 11;
int num_m = rand() % 11;

printf("\nJoão jogou %d",num_j);
printf("\nMaria jogou %d",num_m);

if ((num_j+num_m) % 2 == 0){
    printf("\n%d + %d = PAR!\n",num_j,num_m);
} else{
    printf("\n%d + %d = IMPAR!\n",num_j,num_m);
}

}