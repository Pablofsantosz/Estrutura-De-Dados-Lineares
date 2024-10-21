#define TAMANHO 5
typedef struct pilha
{
    int dados[TAMANHO];
    int topo;

}Stack;

void iniciarlizar( Stack *pilha){
    pilha->topo=-1;
}
int isEmpy(Stack pilha){
    if(pilha.topo == -1){
        //PIlha vazia
        return 1;

    }else{
        return 0;
    }

}
int isFull(Stack pilha){
    if(pilha.topo ==TAMANHO-1){
        // Fila esta cheia
        return 1;
    }
    else{
        return 0;
    }
}
void push(Stack *pilha,int valor){
    pilha->topo = pilha->topo +1;
    pilha->dados[pilha->topo] = valor;
}

void pop(Stack *pilha){
    int aux = pilha->dados[pilha->topo];
    pilha->topo =pilha->topo-1;
    return aux;

}
int top(Stack pilha){
    return pilha.dados[pilha.topo];
}
// Se liga na notação de vetor(struct) e de ponteiroo!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// vetor = pilha.dados 
// ponteiro = pilha->dados

