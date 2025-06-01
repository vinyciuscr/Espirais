#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(){


    int x = 0, y = 0;

    int variacao_x[8] = {-1, 0, 1, 1, 1, 1, 0, -1}; //com base nas 8 direçẽos que formam cada camada do coração ocorre uma determinada mudança no parâmetro x nesse ordem de valores
    int variacao_y[8] = {1, 1, 0, -1, 1, 0, -1, -1}; //o mesmo vale para y

    int steps[8] = {2, 1, 1, 1, 1, 1, 2, 2}; //o número de vezes que cada direção se repete
    
    int f = 1; //variável auxiliar

    int ponto_atual = 0; //ponto incial

    int n = 0; //entrada n

    scanf("%d", &n);//comando de entrada para o valor n

    

    while(f){ //loop inifinito
    
    if(n == 0){ //caso n seja a origem
        f = 0;
        break;
    }
        for(int i = 0; i < 8; i++){ //precisamos percorrer todas as 8 direções para formar o coração
            for (int j = 0; j < steps[i]; j++){ //loop até que se atinja o número de steps determinado para cada direção através do vetor steps
                x += variacao_x[i]; //a variação de x com base na direção executada
                y += variacao_y[i]; //a variação de y com base na direção executada
                ponto_atual++; //a cada interação o ponto atual incrementa em 1
                
                if(ponto_atual == n){ //caso o valor de n tenha sido atingido
                f = 0;
                break; //saida para o primeiro for
              }
            }
        if(f == 0){
            break; //saida para o segundo for
        }
            if(i == 7){ //quando se chega na última direção é preciso incrementar o número de steps de cada direção
                for(int k = 0; k < 8; k++){
                    if(k != 3 && k != 4){ //o número de steps das direções 3 e 4 não é alterado, já que eles permancem o mesmo durante toda a espiral
                        steps[k]++; //incrementa em 1 o número de steps de cada direção, com a excesão citada acima.
                    }
                }
            }

        }
        if(f == 0){
            break; //saída para o while
        }
    }

    printf("%d %d", x, y); //imprime as coordenadas de n
    return 0;
}
