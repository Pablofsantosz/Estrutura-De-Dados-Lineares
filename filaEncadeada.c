#include <stdlib.h>
#include <stdio.h>
typedef struct queueNode{
    int info;
    struct queueNode *prox;
}QueueNode;

typedef struct queue{
    QueueNode* inicio;
    QueueNode * final;
}Queue;

void inicializar(Queue *fila){
    fila->final= NULL;
    fila->inicio=NULL;
}

int isEmpty(Queue fila){
    if(fila.inicio == NULL && fila.final == NULL){
        return 1;
        //FILA VAZIA
    }
    else{
        return 0;
    }
}


int isFull(){
    return 0;
}

void enQueue(Queue *fila,int valor){
    QueueNode *novo;
    novo = (QueueNode*)malloc(sizeof(QueueNode));
    novo->info = valor;
    novo->prox =NULL;
    if(isEmpty(*fila)==1){
        fila->final =novo;
        fila->inicio=novo;
    }
    else{
        fila->final->prox=novo;
        fila->final =novo;
    }
}
int deQueue(Queue *fila){
    
    QueueNode* aux =fila->inicio;
    int valor = aux->info;
    fila->inicio=fila->inicio->prox;
    free(aux);
    if (fila->inicio == NULL) {
        fila->final = NULL;
    }
    return valor;
}

int head(Queue fila){
    if (!isEmpty(fila)) {
        return fila.inicio->info;
    } else {
        printf("Fila vazia");
        return -1;
    }
}
