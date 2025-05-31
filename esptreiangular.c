 #include <stdlib.h>
#include <stdio.h>

int main(){


    int direcao = 0;
    int x = 0, y = 0;

    int step_size = 1;
    int atual = 1;
    int passagem = 0;
    int i = 0;
    int ponto_atual = 0;
    int n;
    int f = 1;
    int direita = 1, noroeste = 1, sudoeste = 2;
    int flag = 0;

    scanf("%d",&n);

    while(f){

    if(n == 0){
        f = 0;
        break;
    }

    //corrigir o problema da direita

    direcao = i % 3;

    if(direcao == 0){
        if(ponto_atual == 0){
            atual = direita;
        }
        else if(ponto_atual == 4){
            atual = direita + 4;
        }
        else if(ponto_atual == 16){
            atual = direita + 7;
        }
        else if(ponto_atual > 16){
            atual = 8 + flag;
            flag = flag + 2;
        }
    }
    else if(direcao == 1){
        atual = noroeste;
        noroeste = noroeste + 2;
    }
    else if(direcao == 2){
        atual = sudoeste;
        sudoeste = sudoeste + 2;
    }

        while(step_size <= atual){
            if (direcao == 0) {
                x = x + 1; 
            }
            if (direcao == 1) {
                x = x - 1;
                y = y + 1;  
            }
            if (direcao == 2) {
                y = y - 1;
                x = x - 1;  
            }
        ponto_atual++;
        step_size++;
        if(ponto_atual == n) {
            f = 0;
            break;
        }
        
    }

        step_size = 1;

        atual = 0;
        i++;
        
    }

    printf("%d %d", x, y);
    return 0;
}
