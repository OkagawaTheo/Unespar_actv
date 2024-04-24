#include <stdio.h>

int main() {
    int bolas_neve[9];
    int total_bolas_neve = 0;
    
    char nomes_renas[][8] = {"Dasher", "Dancer", "Prancer", "Vixen", "Comet", "Cupid", "Donner", "Blitzen", "Rudolph"};

    for (int i = 0; i < 9; i++) {
        scanf("%d", &bolas_neve[i]);
        total_bolas_neve += bolas_neve[i];
    }

    int rena_vencedora = (total_bolas_neve - 1) % 9;

    
    printf("%s\n", nomes_renas[rena_vencedora]);

}
