#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

#define MaxTam 3

typedef int Apontador;

typedef struct {
    int cod;
} TipoItem;

typedef struct {
    TipoItem Item[MaxTam];
    Apontador Frente;
    Apontador Tras;
} TipoFila;

TipoFila Fila;
TipoItem x;
Apontador pos;
int tamanho =0;

void FFVazia(TipoFila *Fila) {
    Fila->Frente = 1;
    Fila->Tras = Fila->Frente;
    tamanho = 0;
}

int Vazia(TipoFila Fila) {
    return (Fila.Tras == Fila.Frente);
    //Fila linear
}

void Enfileira(TipoItem x, TipoFila *Fila){
    if(Fila->Tras % MaxTam + 1 == Fila->Frente){
        printf("\nA fila está cheia\n");
    }else {
        Fila->Item[Fila->Tras - 1] = x;
        tamanho++;
        Fila->Tras = Fila->Tras % MaxTam + 1;
    }
}

void Imprime(TipoFila Fila){
    for(int i = Fila.Frente - 1; i<Fila.Tras - 1; i++){
        printf("\nCodigo: %d", Fila.Item[i].cod);
    }
}

void Desinfileira(TipoItem *x, TipoFila *Fila){
    if(Vazia(*Fila)){
        printf("Fila Vazia!!");
    }
    else{
        *x = Fila->Item[Fila->Frente-1];
        printf("Elemento de codigo: %d desinfileirado",x->cod);
        Fila->Frente = Fila->Frente % MaxTam + 1;
        tamanho--;
    }
}
int Desinfileira2(TipoItem *x, TipoFila *Fila){
    int desin=0;
    if(Fila->Tras == Fila->Frente){
        desin = 1;
    }
    else{
        *x = Fila->Item[Fila->Frente-1];
        desin = 2;
        Fila->Frente = Fila->Frente % MaxTam + 1;
        tamanho--;
    }
    return(desin);
}

int Tamanho(TipoFila Fila) {
    return (tamanho);
}

void Procura(TipoFila Fila, TipoItem x) {
    bool encontrou = false;
    if (Fila.Frente == Fila.Tras) {
        printf("Fila vazia\n");
    } else {
        for (int i = Fila.Frente; i < Fila.Tras; i++) {
            if (Fila.Item[i].cod == x.cod) {
                printf("Elemento encontrado: \nCodigo: %d", Fila.Item[i].cod);
                encontrou = true;
                break;
            }
        }
        if (!encontrou) {
            printf("Elemento não encontrado\n");
        }
    }
}

int main(){

    int opcao, resposta,tamfila, desinfinal;
    FFVazia(&Fila);
    do{
        printf("\n\n--------Menu---------\n");
        printf("\nDigite a opcao desejada:\n");
        printf("0 - Sair\n");
        printf("1 - Esvaziar Fila\n");
        printf("2 - Verificar Fila vazia\n");
        printf("3 - Enfileirar elemento na fila\n");
        printf("4 - Imprimir lista\n");
        printf("5 - Desinfileirar elemento da Fila\n");
        printf("6 - Tamanho da fila\n");
        printf("7 - Buscar elemento na fila\n");
        printf("8 - Desinfileirar diferente\n");

        scanf("%d", &opcao);
        switch (opcao) {
            case 0:
                printf("PROGRAMA ENCERRADO");
                break;
            case 1:
                FFVazia(&Fila);
                printf("FILA ESVAZIADA\n");
                break;
            case 2:
                resposta = Vazia(Fila);
                if(resposta == 1){
                    printf("A fila esta vazia\n");
                }else{
                    printf("A fila nao esta vazia\n");
                }
                break;
            case 3:
                printf("Enfileirando elemento(s)\n");
                printf("Digite o codigo: \n");
                scanf("%d",&x.cod);
                Enfileira(x, &Fila);
                break;
            case 4:
                Imprime(Fila);
                break;
            case 5:
                printf("Desinfileirando elemento(s)\n");
                Desinfileira(&x, &Fila);
                break;
            case 6:
                tamfila = Tamanho(Fila);
                printf("Tamanho da fila: %d",tamfila);
                break;
            case 7:
                printf("Informe o codigo a ser buscado:\n");
                scanf("%d",&x.cod);
                Procura(Fila, x);
                break;
            case 8:
                printf("Desinfileirando elemento(s)\n");
                desinfinal = Desinfileira2(&x, &Fila);
                if(desinfinal == 1){
                    printf("Fila Vazia");
                }else if(desinfinal = 2){
                    printf("Elemento desinfileirado");
                }
                break;
            default:
                printf("\nOpção inválida\n\n");
        }
        _getch(); // Segura a tela
        system("cls"); // limpa a tela
    }while(opcao != 0);
    return 0;
}
