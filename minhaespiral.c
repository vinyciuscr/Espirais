#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(){


    int x = 0, y = 0;

    int variacao_x[7] = {-1, 0, 1, 1, 1, 0, -1};
    int variacao_y[7] = {1, 1, 0, -1, 1, -1, -1};

    int steps[7] = {2, 1, 1, 1, 1, 2, 2};
    
    int f = 1;

    int ponto_atual = 0;

    int n = 0;

    scanf("%d", &n);

    

    while(f){
    
    if(n == 0){
        f = 0;
        break;
    }
        for(int i = 0; i < 7; i++){
            for (int j = 0; j < steps[i]; j++){
                x += variacao_x[i];
                y += variacao_y[i];
                ponto_atual++;
                if(ponto_atual == n){
                f = 0;
                break;
              }
            }
            if(i == 6){
                for(int k = 0; k < 7; k++){
                    if(k != 3 && k != 4){
                        steps[k]++;
                    }
                }
            }

        }
    }

    printf("%d %d", x, y);
    return 0;
}
