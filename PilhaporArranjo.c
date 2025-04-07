#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxTam 2

typedef int Apontador;

typedef struct
{
    int cod, idade;
}TipoItem;

typedef struct
{
    TipoItem Item[MaxTam];
    Apontador Topo;
}TipoPilha;

TipoPilha Pilha, Pilha2;
TipoItem x;
int tamanho = 0, maior = 0, menor = 100000;

void FPVazia(TipoPilha *Pilha){
    Pilha->Topo = 0;
}
int Vazia(TipoPilha Pilha)
{
    return(Pilha.Topo == 0);
}
void Empilhar(TipoItem x, TipoPilha *Pilha)
{
    if(Pilha->Topo == MaxTam){
        printf("A pilha esta cheia!\n");
    }else{
    Pilha->Item[Pilha->Topo] = x;
    Pilha->Topo++;
    //printf("Inserido\n");
        if(x.idade < menor){
            menor = x.idade;
        }
        if(x.idade > maior){
            maior = x.idade;
        }
    }
}
void Imprime(TipoPilha Pilha){
    for(int i = 0; i< Pilha.Topo ; i++){
        printf("\nCodigo: %d\nIdade: %d", Pilha.Item[i].cod, Pilha.Item[i].idade);
    }
}
void Desempilha(TipoItem *x, TipoPilha *Pilha)
{
    if(Vazia(*Pilha) == 1){
        printf("Pilha Vazia!\n");
    }else{
        *x = Pilha->Item[Pilha->Topo-1];
        //printf("\nCodigo: %d\nIdade: %d", x->cod, x->idade);
        Pilha->Topo--;
    }
}
void TopoFundo(TipoPilha Pilha){
    if(Vazia(Pilha) == 1){
        printf("Pilha Vazia!\n");
    }else{
        printf("Topo ao Fundo");
        for(int i = Pilha.Topo - 1; i >= 0; i--){
            printf("\nCodigo: %d\nIdade: %d",  Pilha.Item[i].cod, Pilha.Item[i].idade);
        }
    }
}

void FundoTopo(TipoPilha Pilha){
    if(Vazia(Pilha) == 1){
        printf("Pilha Vazia!\n");
    }else{
        printf("Fundo ao Topo");
        for(int i = 0; i <=Pilha.Topo -1 ; i++){
            printf("\nCodigo: %d\nIdade: %d",  Pilha.Item[i].cod, Pilha.Item[i].idade);
        }
    }
}
int Tamanho(TipoPilha Pilha){
    return (Pilha.Topo);
}
void Procura(TipoItem x, TipoPilha Pilha){
    bool encontrou = false;
    if(Vazia(Pilha) == 1){
        printf("Erro: Pilha Vazia!\n");
    }else{
        for(int i = 0; i <=Pilha.Topo -1 ; i++){
            if(Pilha.Item[i].cod == x.cod){
                printf("\nElemento encontrado:\n Codigo: %d\n Idade: %d",  Pilha.Item[i].cod, Pilha.Item[i].idade);
                encontrou = true;
            }
        }
    }
    if(!encontrou){
        printf("\nElemento nao localizado!");
    }
}
void DividirPilha(TipoPilha *Pilha, TipoPilha *Pilha2) {
    int tam = Pilha->Topo;
    int metade = tam / 2;

    for (int i = 0; i < metade; i++) {
        Desempilha(&x, Pilha);
        Empilhar(x, Pilha2);
    }
}

void CalculosIdade(TipoPilha Pilha){
    int somaIdades = 0;
    double media = 0;
    printf("Maior idade: %d", maior);
    printf("\nMenor idade: %d", menor);
    for (int i = 0; i < Pilha.Topo; i++) {
        somaIdades += Pilha.Item[i].idade;
    }
    media = somaIdades/Pilha.Topo;
    printf("\nMedia Aritmetica: %.2f",media);
}

int main()
{
    int opcao, pilhavazia, tampilha;
    do {
        printf("\n\n--------Menu---------\n");
        printf("\nDigite a opcao desejada:\n");
        printf("0 - Sair\n");
        printf("1 - Esvaziar Pilha\n");
        printf("2 - Verificar Pilha\n");
        printf("3 - Empilhar elemento na pilha\n");
        printf("4 - Imprimir elementos da Pilha\n");
        printf("5 - Desempilhar elemento\n");
        printf("6 - Imprimir do Topo ao Fundo\n");
        printf("7 - Imprimir do Fundo ao Topo\n");
        printf("8 - Tamanho da pilha\n");
        printf("9 - Procurar elemento na pilha\n");
        printf("10 - Dividir pilha\n");
        printf("11 - Maior, menor e media das idades\n");

        scanf("%d", &opcao);
        switch (opcao) {
            case 0:
                printf("PROGRAMA ENCERRADO");
                break;
            case 1:
                FPVazia(&Pilha);
                printf("\nPilha Esvaziada\n");
                break;
            case 2:
                pilhavazia= Vazia(Pilha);
                if(pilhavazia==1){
                    printf("A pilha esta vazia\n");
                }else{
                printf("A pilha nao esta vazia\n");
                }
                break;
            case 3:
                printf("Informe o codigo:\n");
                scanf("%d",&x.cod);
                printf("Informe a idade:\n");
                scanf("%d",&x.idade);
                Empilhar(x, &Pilha);
                break;
            case 4:
                Imprime(Pilha);
                break;
            case 5:
                Desempilha(&x, &Pilha);
                break;
            case 6:
                TopoFundo(Pilha);
                break;
            case 7:
                FundoTopo(Pilha);
                break;
            case 8:
                tampilha = Tamanho(Pilha);
                printf("\nA pilha tem %d elemento(s)!", tampilha);
                break;
            case 9:
                printf("Qual o codigo do elemento pesquisado?\n");
                scanf("%d",&x.cod);
                Procura(x, Pilha);
                break;
            case 10:
                DividirPilha(&Pilha, &Pilha2 );
                printf("\nPilha 1:");
                Imprime(Pilha);
                printf("\nPilha 2:");
                Imprime(Pilha2);
                break;
            case 11:
                CalculosIdade(Pilha);
                break;
            default:
                printf("\nOpcao invalida\n\n");
        }
        _getch(); // Segura a tela
        system("cls"); // limpa a tela
    } while (opcao != 0);
}
