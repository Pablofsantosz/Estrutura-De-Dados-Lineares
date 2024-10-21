#define TAM 10
#include <stdlib.h>
#include <stdio.h>
typedef struct queue{
    int inicio, final;
    int dados[TAM];
} Queue;
void inicializar (Queue*fila){
    fila->inicio = 0;
    fila->final= -1;
}

int isEmpty(Queue fila){
    if(fila.inicio>fila.final){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(Queue fila){
    if(fila.final==TAM-1){
        return 1;
    }
    else{
        return 0; 
    }
}

void enQueue(Queue *fila,int valor){
    fila->final++;
    fila->dados[fila->final] = valor;

}

int deQueue(Queue *fila){
    int retorno = fila->dados[fila->inicio];
    for(int i = 0 ;i <fila->final;i++){
        fila->dados[i]=fila->dados[i+1];
    }
    fila->final--;
    return retorno;

}
int head(Queue fila){
    return fila.dados[fila.inicio];
}
void opcoes(){
    printf("==Escolha uma das opçoes abaixo==\n");
    printf("1-Colocar na fila\n");
    printf("2-tirar da fila\n");
    printf("3-Ver Head\n");
    printf("0-encerrar programa\n");
    
}

int main(){
    Queue fila1;
    int num,op,aux;
    inicializar(&fila1);
    do{
        opcoes();
        scanf("%d",&op);
        switch(op){
            case 1:
                if(isFull(fila1)==1){
                    printf("Pilha esta cheia\n");
                    
                }
                else{
                    printf("Informe o numero que voce quer colocar na pilha:\n");
                    scanf("%d",&num);
                    enQueue(&fila1,num);
                    printf("Numero enfileirado\n");
                }

                break;
            case 2:
                if(isEmpty(fila1)==1){
                    printf("Pilha vazia\n");
                }
                else{
                    aux = deQueue(&fila1);
                    printf("Valor desefilerado : %d\n",aux);  
                }
                

                break;
            case 3 :
                aux = head(fila1);
                printf("O primeiro valor da fila é %d\n",aux);
                

                break;
            case 0:
                printf("programa finalizado ");
                return 1;
                break;
            default:
                break;
        }

    
    }while(op!=0);
}




