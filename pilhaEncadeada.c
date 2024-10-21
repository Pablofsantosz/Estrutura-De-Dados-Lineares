#include <stdlib.h>
#include <stdio.h>
typedef struct StackNode{
    int info;
    struct StackNode *prox;
}StackNode;

typedef StackNode* Stack;

void  inicializar(Stack *pilha){
    *pilha =NULL;
}
int isFull(Stack pilha){
    return 0;

}
int isEmpty(Stack pilha){
    if(pilha  == NULL){
        return 1;
        // Pilha vazia

    }
    else{
        return 0;
    }
}

void push(Stack *pilha,int valor){
    StackNode *novo;
    novo =(StackNode*)malloc(sizeof(StackNode));
    novo->info = valor;
    novo->prox = NULL;
    if(isEmpty(*pilha)== 1){
        *pilha = novo;
    }
    else{
        novo->prox =*pilha;
        *pilha = novo;
    }
}


int pop(Stack *pilha){
    StackNode* aux  = *pilha;
    int valor;
    *pilha = (*pilha)->prox;
    valor = aux->info;
    free(aux);
    return valor;
}
int top (Stack pilha){
    return pilha->info;
}

int main(){
    Stack pilha1,pilha2;
    int num,aux;
    inicializar(&pilha1);
    inicializar(&pilha2);

    if(isFull(pilha1)==1){
        printf("Stack full");
        return 1;

    }
    else{
        printf("informe um numero\n ");
        scanf("%d",&num);
        while(num!=0){
            aux=num%10;
            push(&pilha1,aux);
            num/=10;
        }
    }

    if(isFull(pilha2)==1){
        printf("Pilha 2 esta cheia ");
        return 1;
    }else{
        while(!isEmpty(pilha1)){
            aux = pop(&pilha1);
            push(&pilha2,aux);
        }
    }


    printf("Numero invertido :");
    while(!isEmpty(pilha2)){
        aux = pop(&pilha2);
        printf("%d",aux);  
    }
}
