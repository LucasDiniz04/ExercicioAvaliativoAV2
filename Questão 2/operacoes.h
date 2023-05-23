//definindo as structs
typedef struct No{
    int data;
    struct No* proximo;
} No;

typedef struct{
    No* cabeca;
} Pilha;

typedef struct{
    No* frente;
    No* tras;
} Fila;

typedef struct ArvoreNo{
    int data;
    struct ArvoreNo* esquerda;
    struct ArvoreNo* direita;
} ArvoreNo;

//declarando funções pra pilha
void push(Pilha* Pilha, int valor);
int pop(Pilha* Pilha);
void imprimirPilha(Pilha* Pilha);
void limparPilha(Pilha* Pilha);
void imprimirCabeca(Pilha* Pilha);

//declarando funções pra fila
void enFila(Fila* Fila, int valor);
int deFila(Fila* Fila);
void imprimirFila(Fila* Fila);
void limparFila(Fila* Fila);
int encontrarMaior(Fila* Fila);
int encontrarMenor(Fila* Fila);

//declarando funções pra árvore
ArvoreNo* criarNo(int valor);
ArvoreNo* inserir(ArvoreNo* raiz, int valor);
void imprimirEmOrdem(ArvoreNo* raiz);
ArvoreNo* busca(ArvoreNo* raiz, int valor);
void imprimirDireitaEsquerda(ArvoreNo* raiz);
int maiorElemento(ArvoreNo* raiz);

//função de pilha
void push(Pilha* Pilha, int valor){
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->data = valor;
    novoNo->proximo = Pilha->cabeca;
    Pilha->cabeca = novoNo;
}

int pop(Pilha* Pilha){
    if (Pilha->cabeca == NULL){
        printf("Pilha vazia!\n");
        return 1;
    }

    int valor = Pilha->cabeca->data;
    No* temp = Pilha->cabeca;
    Pilha->cabeca = Pilha->cabeca->proximo;
    free(temp);

    return valor;
}

void imprimirPilha(Pilha* Pilha){
    No* atual = Pilha->cabeca;
    while (atual != NULL){
        printf("%d ", atual->data);
        atual = atual->proximo;
    }
}

void limparPilha(Pilha* Pilha){
    No* atual = Pilha->cabeca;
    while (atual != NULL){
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    Pilha->cabeca = NULL;
}

void imprimirCabeca(Pilha* Pilha){
    if (Pilha->cabeca == NULL){
        printf("Pilha vazia!\n");
    } else{
        printf("cabecao da pilha: %d\n", Pilha->cabeca->data);
    }
}

//função de Fila
void enFila(Fila* Fila, int valor){
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->data = valor;
    novoNo->proximo = NULL;

    if (Fila->tras == NULL){
        Fila->frente = novoNo;
        Fila->tras = novoNo;
    } else{
        Fila->tras->proximo = novoNo;
        Fila->tras = novoNo;
    }
}

int deFila(Fila* Fila){
    if (Fila->frente == NULL){
        printf("Fila vazia!\n");
        return 1;
    }

    int valor = Fila->frente->data;
    No* temp = Fila->frente;

    if (Fila->frente == Fila->tras){
        Fila->frente = NULL;
        Fila->tras = NULL;
    } else{
        Fila->frente = Fila->frente->proximo;
    }

    free(temp);
    return valor;
}

void imprimirFila(Fila* Fila){
    No* atual = Fila->frente;
    while (atual != NULL){
        printf("%d ", atual->data);
        atual = atual->proximo;
    }
}

void limparFila(Fila* Fila){
    No* atual = Fila->frente;
    while (atual != NULL){
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    Fila->frente = NULL;
    Fila->tras = NULL;
}

int encontrarMaior(Fila* Fila){
    if (Fila->frente == NULL){
        printf("Fila vazia!\n");
        return 1;
    }

    int maior = Fila->frente->data;
    No* atual = Fila->frente->proximo;
    while (atual != NULL){
        if (atual->data > maior){
            maior = atual->data;
        }
        atual = atual->proximo;
    }
    return maior;
}

int encontrarMenor(Fila* Fila){
    if (Fila->frente == NULL){
        printf("Fila vazia!\n");
        return 1;
    }

    int menor = Fila->frente->data;
    No* atual = Fila->frente->proximo;
    while (atual != NULL){
        if (atual->data < menor){
            menor = atual->data;
        }
        atual = atual->proximo;
    }
    return menor;
}

//função de árvore
ArvoreNo* criarNo(int valor){
    ArvoreNo* novoNo = (ArvoreNo*)malloc(sizeof(ArvoreNo));
    novoNo->data = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

ArvoreNo* inserir(ArvoreNo* raiz, int valor){
    if (raiz == NULL){
        return criarNo(valor);
    }

    if (valor < raiz->data){
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->data){
        raiz->direita = inserir(raiz->direita, valor);
    }

    return raiz;
}

void imprimirEmOrdem(ArvoreNo* raiz){
    if (raiz != NULL){
        imprimirEmOrdem(raiz->esquerda);
        printf("%d ", raiz->data);
        imprimirEmOrdem(raiz->direita);
    }
}

ArvoreNo* busca(ArvoreNo* raiz, int valor){
    if (raiz == NULL || raiz->data == valor){
        return raiz;
    }

    if (valor < raiz->data){
        return busca(raiz->esquerda, valor);
    }

    return busca(raiz->direita, valor);
}

void imprimirDireitaEsquerda(ArvoreNo* raiz){
    if (raiz != NULL){
        imprimirDireitaEsquerda(raiz->direita);
        printf("%d ", raiz->data);
        imprimirDireitaEsquerda(raiz->esquerda);
    }
}

int maiorElemento(ArvoreNo* raiz){
    if (raiz == NULL){
        printf("Arvore vazia!\n");
        return 1;
    }

    while (raiz->direita != NULL){
        raiz = raiz->direita;
    }
    return raiz->data;
}
