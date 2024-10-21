#include <stdlib.h>
#include <string.h>

typedef struct listNode{
    int info;
    struct listNode* prox;
    

}ListNode;

typedef struct Lse{
    ListNode* inicio;
    ListNode* fim;
    int qtd;
}List;

void inicializar(List *lista){
    lista->inicio == NULL;
    lista->fim ==NULL;
    lista->qtd=0;
    
}
int isEmpty(List lista){
    if(lista.qtd==0){
        return 1;
        //LIsta vazia
    }else{
        return 0;
    }

}
void inserirFinal(List* lista ,int valor){
    ListNode *novo;
    novo =(ListNode*)malloc(sizeof(ListNode));
    novo->info=valor;
    novo->prox==NULL;
    if(isEmpty(*lista)==1){
        lista->inicio=novo;
        lista->fim=novo;
    }
    else{
        lista->fim->prox=novo;
        lista->fim=novo;
    }
    lista->qtd++;

}
void inserirInicio(List*lista ,int valor){
    ListNode *novo;
    novo=(ListNode*)malloc(sizeof(ListNode));
    novo->info=valor;
    novo->prox=NULL;
    if(isEmpty(*lista)==1){
        lista->inicio=novo;
        lista->fim=novo;
    }
    else{
        novo->prox=lista->inicio;
        lista->inicio = novo;
        
    }
    lista->qtd++;

}

void removerInicio(List *lista){
    ListNode *aux ;

    if(isEmpty(*lista)==1){//caso nao tenha termos 
        printf("Lista vazia \n");
        return ;
    }
    else{
        aux = lista->inicio;
        lista->inicio = lista->inicio->prox;//ou aux->prox
        
    }
    if(lista->inicio ==NULL){//caso tenha so um termo
        lista->fim =NULL;

    }
    lista->qtd --;
    free(aux);
}
void  removerFinal(List *lista){
    ListNode *atual;
    
    if(isEmpty(*lista)==1){
        printf("vazia\n");
        return;
    }
    if(lista->qtd==1){
        free(lista->inicio);
        lista->inicio==NULL;
        lista->fim==NULL;

    }

    else {
        atual =lista->inicio;
        while(atual->prox!=lista->fim){
            atual = atual->prox;
        }
        atual->prox=NULL;
        free(lista->fim);
        lista->fim=atual;

    }
    
    lista->qtd++;

    
}
void listarTodos(List lista) {
    ListNode* aux;
    if (isEmpty(lista) == 1) {
        printf ("Fila vazia! \n");
    }
    else {
        aux = lista.inicio;
        while (aux != NULL) {
            printf ("%s \n", aux->info);
            aux = aux->prox;
        }
    }
}

int buscar (List lista ,int valor){//busca sequencial simples
    ListNode* aux;
    if (isEmpty(lista) == 1) {
        return 0;
    }
    else {
        aux = lista.inicio;
        while (aux != NULL) {
            if(aux->info==valor){
                return 1;
                //achei
            }
            aux = aux->prox;
        }
        return 0;
        
    }
}
