 #include <stdlib.h>
#include <stdio.h>

int main(){


    int direcao = 0; //direção da "seta"
    int x = 0, y = 0; //ponto inicial

    int step_size = 1; //o quanto cada direção irá "andar"
    int atual = 1; //auxiliar na contagem dos steps
    int i = 0; //variável auxiliar
    int ponto_atual = 0; //varável auxiliar para cálcular as coordenadas até n
    int n; //valor de entrada
    int f = 1; //flag
    int direita = 1, noroeste = 1, sudoeste = 2; //número incial de steps de cada direção
    int flag = 0; //variável auxiliar

    scanf("%d",&n); //entrada

    while(f){ //loop infinito

    if(n == 0){ //caso n seja a origem
        f = 0;
        break;
    }

    direcao = i % 3; //como temos um ciclo de 3 direções podemos calcula-lá com base no módulo de 3 seguindo a seguinte ordem: direita, noroeste, sudoeste.

    if(direcao == 0){ //caso a direção seja a direita
        if(ponto_atual == 0){
            atual = direita; //na origem a direção para a direita repete 1 vez
        }
        else if(ponto_atual == 4){
            atual = direita + 4; //no ponto 4 a direção para a direita repete 5 vezes
        }
        else if(ponto_atual == 16){
            atual = direita + 7; //no ponto 16 a direção para a direita repete 8 vezes
        }
        else if(ponto_atual > 16){ // a partir do ponto 16 o número de steps para a direita passa a ser contínuo incrementando em 2
            atual = 8 + flag;
            flag = flag + 2;
        }
    }
    else if(direcao == 1){
        atual = noroeste; //começa em 1 e é incrementando em 2 toda vez que se repete
        noroeste = noroeste + 2;
    }
    else if(direcao == 2){
        atual = sudoeste; //começa em 2 e é incrementada em 2 toda vez que se repete 
        sudoeste = sudoeste + 2;
    }

        while(step_size <= atual){ //a direção se repete até que se atinja o step determinado para cada uma pela lógica acima
            if (direcao == 0) { // dependendo da direção ocorre o incremento ou decremento do valor de x ou y ou os dois
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
        ponto_atual++; //a cada interação se avança um ponto
        step_size++; //o step_size avança para a direção repetir até o número atua.
        if(ponto_atual == n) { //condicional para verificar se n já foi atingido
            f = 0; // caso seja verdadeiro, a flag irá passar a ser falsa e iremos sair do while
            break;
        }
        
    }

        step_size = 1; // volta a ser 1 para auxiliar corretamente o a variável atual

        atual = 0; //é reinicializada
        i++; //aumenta para irmos para a próxima direção
        
    }

    printf("%d %d", x, y); //imprime as coordenadas de n
    return 0;
}
