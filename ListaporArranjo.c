#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#define InicioArranjo 1
#define MaxTam 5

typedef int Apontador;

typedef struct {
    int cod, idade;
} TipoItem;

typedef struct {
    TipoItem Item[MaxTam];
    Apontador Primeiro;
    Apontador Ultimo;
} TipoLista;

TipoLista Lista;
TipoItem x;
Apontador pos;

void FLVazia(TipoLista *Lista) {
    Lista->Primeiro = 0;
    Lista->Ultimo = 0;
}

int Vazia(TipoLista Lista) {
    return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista) {
    if (Lista->Ultimo >= MaxTam) {
        printf("\nA lista está cheia\n");
    } else {
        Lista->Item[Lista->Ultimo] = x;
        Lista->Ultimo++;
    }
}

void Imprime(TipoLista Lista) {
    for (int i = Lista.Primeiro; i < Lista.Ultimo; i++) {
        printf("\nCodigo: %d", Lista.Item[i].cod);
        printf("\nIdade: %d\n", Lista.Item[i].idade);
    }
}

void Retira(Apontador pos, TipoLista *Lista) {
    if (Vazia(*Lista) || pos < 0 || pos >= Lista->Ultimo) {
        printf("Erro ao retirar elemento\n");
    } else {
        for (int i = pos -1; i < Lista->Ultimo - 1; i++) {
            Lista->Item[i] = Lista->Item[i + 1];
        }
        Lista->Ultimo--;
        printf("Elemento retirado\n");
    }
}

void Retira2(Apontador pos, TipoLista *Lista) {
    if (Vazia(*Lista) || pos < 0 || pos >= Lista->Ultimo) {
        printf("Erro ao retirar elemento\n");
    } else {
        for (int i = pos; i < Lista->Ultimo - 1; i++) {
            Lista->Item[i] = Lista->Item[i + 1];
        }
        Lista->Ultimo--;
        printf("Elemento retirado\n");
    }
}

void Procura(TipoLista Lista, TipoItem x) {
    bool encontrou = false;
    if (Lista.Primeiro == Lista.Ultimo) {
        printf("Lista vazia\n");
    } else {
        for (int i = Lista.Primeiro; i < Lista.Ultimo; i++) {
            if (Lista.Item[i].cod == x.cod) {
                printf("Elemento encontrado: \nCodigo: %d\nIdade: %d\n", Lista.Item[i].cod, Lista.Item[i].idade);
                encontrou = true;
                break;
            }
        }
        if (!encontrou) {
            printf("Elemento não encontrado\n");
        }
    }
}

void InsereP(TipoLista *Lista, TipoItem x) {
    if (Lista->Ultimo >= MaxTam) {
        printf("\nA lista está cheia\n");
    } else {
        for (int i = Lista->Ultimo; i > Lista->Primeiro; i--) {
            Lista->Item[i] = Lista->Item[i - 1];
        }
        Lista->Item[Lista->Primeiro] = x;
        Lista->Ultimo++;
    }
}

void InsereQ(Apontador pos, TipoLista *Lista, TipoItem x) {
    if (Lista->Ultimo >= MaxTam) {
        printf("\nA lista está cheia\n");
    } else if (pos < 0 || pos > Lista->Ultimo) {
        printf("Posição inválida\n");
    } else {
        for (int i = Lista->Ultimo; i > pos; i--) {
            Lista->Item[i] = Lista->Item[i - 1];
        }
        Lista->Item[pos] = x;
        Lista->Ultimo++;
    }
}

int main() {
    int opcao, resposta;
    setlocale(LC_ALL, "");
    FLVazia(&Lista);
    do {
        printf("\n\n--------Menu---------\n");
        printf("\nDigite a opcao desejada:\n");
        printf("0 - Sair\n");
        printf("1 - Esvaziar lista\n");
        printf("2 - Verificar se a lista esta vazia\n");
        printf("3 - Inserir elemento\n");
        printf("4 - Imprimir lista\n");
        printf("5 - Retirar elemento da lista antes da posicao determinada\n");
        printf("6 - Retirar elemento da lista\n");
        printf("7 - Pesquisar elemento na lista pelo codigo\n");
        printf("8 - Inserir na primeira posição da lista\n");
        printf("9 - Inserir elemento em qualquer lugar informado pelo usuário\n");

        scanf("%d", &opcao);
        switch (opcao) {
            case 0:
                printf("PROGRAMA ENCERRADO");
                break;
            case 1:
                FLVazia(&Lista);
                printf("\nA LISTA VAZIA\n");
                break;
            case 2:
                resposta = Vazia(Lista);
                if (resposta == 1)
                    printf("\nLista está vazia\n");
                else
                    printf("\nLista não está vazia\n");
                break;
            case 3:
                printf("Digite o codigo: \n");
                scanf("%d", &x.cod);
                printf("Digite a idade: \n");
                scanf("%d", &x.idade);
                Insere(x, &Lista);
                break;
            case 4:
                Imprime(Lista);
                break;
            case 5:
                printf("Qual a posicao do elemento: ");
                scanf("%d", &pos);
                Retira(pos, &Lista);
                break;
            case 6:
                printf("Qual a posicao do elemento: ");
                scanf("%d", &pos);
                Retira2(pos, &Lista);
                break;
            case 7:
                printf("Digite o codigo do elemento requerido: ");
                scanf("%d", &x.cod);
                Procura(Lista, x);
                break;
            case 8:
                printf("Digite o código: ");
                scanf("%d", &x.cod);
                printf("\nDigite a idade: ");
                scanf("%d", &x.idade);
                InsereP(&Lista, x);
                break;
            case 9:
                printf("Informe o indice onde o elemento será inserido:\n");
                scanf("%d", &pos);
                printf("Digite o código: ");
                scanf("%d", &x.cod);
                printf("\nDigite a idade: ");
                scanf("%d", &x.idade);
                InsereQ(pos, &Lista, x);
                break;
            default:
                printf("\nOpção inválida\n\n");
        }
        _getch(); // Segura a tela
        system("cls"); // limpa a tela
    } while (opcao != 0);

    return 0;
}
