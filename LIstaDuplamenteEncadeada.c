#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct listNode{
    int info;
    struct listNode *prox;
    struct listNOde *ant;
}ListNode;

typedef struct list{
    ListNode *inicio;
    ListNode *fim;
    int qtd;
}List;

void inicializar(List *lista){
    lista->inicio=NULL;
    lista->fim= NULL;
    lista->qtd=0;
}

int isEmpty(List lista){
    if(lista.qtd==0){
        return TRUE;
    }
    else{
        return FALSE;
    }

}

void inserirInicio(List *lista,int valor){
    ListNode *novo;
    novo=(ListNode*)malloc(sizeof(ListNode));
    novo->info=valor;
    novo->ant=NULL;
    novo->prox=NULL;
    if(isEmpty(*lista)==1){
        lista->inicio=novo;
        lista->fim=novo;

    }
    else{ 
        novo->prox=lista->inicio;
        lista->inicio->ant=novo;
        lista->inicio=novo;


    }
    lista->qtd++;
    printf("Numero inserido\n");

}
void inserirFinal(List *lista,int valor){
    ListNode *novo;
    novo=(ListNode*)malloc(sizeof(ListNode));
    novo->info=valor;
    novo->ant=NULL;
    novo->prox=NULL;
    if(isEmpty(*lista)==TRUE){
        lista->inicio=novo;
        lista->fim=novo;

    }
    else{
        novo->ant=lista->fim;
        lista->fim->prox=novo;
        lista->fim=novo;
        novo->prox=NULL;

    }
    lista->qtd++;
    printf("Numero inserido\n");
}

void ListarFrente(List lista){
    ListNode *aux;
    if(isEmpty(lista)==TRUE){
        printf("lista vazia\n");
        return;
    }
    else{
        aux = lista.inicio;
        while(aux!=NULL){
            printf("%d\n",aux->info);
            aux=aux->prox;
        }
    }

}
void De_Tras_Pra_Frente_listar(List lista){
    ListNode *aux;
    if(isEmpty(lista)==TRUE){
        printf("Lista vazia \n");
        
    }
    else{
        aux = lista.fim;
        while(aux!=NULL){

            printf("%d\n",aux->info);
            aux = aux->ant;
        }
    }

}

void removerUltimo(List *lista){
    ListNode *aux;
    if(isEmpty(*lista)==TRUE){
        printf("Lista vazia \n");
    }
    else{
        if (lista->qtd==1){
            aux=lista->inicio;
            lista->inicio =NULL;
            lista->fim =NULL;
            free(aux);
        }
        else{
            aux = lista->fim;
            lista->fim=lista->fim->ant;
            free(aux);
            lista->fim->prox=NULL;   
        }
        lista->qtd--;
    }
}

void removerPrimeiro(List *lista){
    ListNode *aux;
    if(isEmpty(*lista)==TRUE){
        printf("LIsta vazia\n");
        return;
    }
    else{
        if(lista->qtd==1){
            aux = lista->inicio;
            lista->inicio=NULL;
            lista->fim=NULL;
            free(aux);
        }
        else{
            aux = lista->inicio;
            lista->inicio=lista->inicio->prox;
            lista->inicio->ant=NULL;
            free (aux);
        }
        lista->qtd--;
    }
}

int busca(List lista,int valor){
    if(isEmpty(lista)==1){
        return FALSE;
    }
    else{
        ListNode *aux;
        aux=lista.inicio;
        while(aux!=NULL){
            if(aux->info==valor){
                return TRUE;
            }
            else{
                return FALSE;
            }
            aux=aux->prox;
        }
    }
}
int isFull(){
    return 0;

}

void opcoes (){
    printf("\n==Informe uma das opções==\n");
    printf("1-inserir no inicio \n");
    printf("2-Inserir no final \n");
    printf("3-Lista na ordem normal \n");
    printf("4-Lista de tras pra frente \n");
    printf("5-remover ultimo \n");
    printf("6-remover Primeiro termo \n");
    printf("7-Buscar termo \n");
    printf("0-ENCERRAR PROGRAMA \n");
}

int main (){
    List lista1;
    int num, op;
    inicializar(&lista1);

    do{
        opcoes();
        scanf("%d",&op);
        switch(op){
            case 1:
                if(isFull(lista1)==TRUE){
                    printf("lista 1 cheia\n");
                }
                else{
                    printf("Infomre um numero para inserir no inicio da lista\n");
                    scanf("%d",&num);
                    inserirInicio(&lista1,num);
                }
                break;

            case 2:
                if(isFull(lista1)==TRUE){
                    printf("Lista cheia\n");
                }
                else{
                    printf("Infomre um numero para inserir no final da lista\n");
                    scanf("%d",&num);
                    inserirFinal(&lista1,num);
                }
                break;

            case 3:
                if(isEmpty(lista1)==TRUE){
                    printf("Lista vazia\n");

                }
                else{
                    printf("lista de valores dentro da lista\n");
                    ListarFrente(lista1);
                }
                break;

            case 4:
                if(isEmpty(lista1)==TRUE){
                    printf("Lista vazia\n");
                }
                else{
                    printf("lista de valores dentro da lista\n");
                    De_Tras_Pra_Frente_listar(lista1);
                }

                break;

            case 5:
                if(isEmpty(lista1)==TRUE){
                    printf("Lista vazia\n");
                }
                else{
                    removerUltimo(&lista1);

                }
                break;

            case 6:
                if(isEmpty(lista1)==TRUE){
                    printf("Lista vazia\n");
                }
                else{
                    removerPrimeiro(&lista1);
                }

                break;
            case 7:
                if(isEmpty(lista1)==TRUE){
                    printf("Lista vazia\n");
                }
                else{
                    printf("informe um valor para buscar na lista.\n");
                    scanf("%d",&num);
                    int aux = busca(lista1,num);
                    if(aux ==TRUE){
                        printf("Numero esta na lista\n");
                    }
                    else{
                        printf("Numero nao etsa na lista \n");
                    }
                }

                break;
            case 0:
                printf("Programa finalizado\n");
                
                break;
            default:
                printf("nenhuma das opções validas escolhidas \n");
                
                break;
        }
    }while(op!=0);
    return 0;
}

