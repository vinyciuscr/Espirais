#include <stdlib.h> 
#include <stdio.h>

int main(){


    int direcao;
    int x = 0, y = 0;

    int step_size = 1;
    int contagem = 0;
    int atual = 1;
    int passagem = 0;
    int i = 0;
    int ponto_atual = 0;
    int n;
    int f = 1;

     scanf("%d",&n);


    while(f){

    direcao = i % 4;

        while(atual <= step_size){
            if (direcao == 0) {
                y = y + 1; 
            }
            if (direcao == 1) {
                x = x - 1;  
            }
            if (direcao == 2) {
                y = y - 1;  
            }
            if (direcao == 3) {
                x = x + 1;  
            }
        ponto_atual++;
        atual++;
        if(ponto_atual == n){
            f = 0;
            break;
        }
        }

        passagem++;

        if(passagem % 2 == 0){
            step_size++;
        }

        atual = 1;
        i++;

    }

    printf("%d %d", x, y);

    return 0;
}
