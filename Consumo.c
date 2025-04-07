#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opcao;
    do{
    system("cls");
    int verifica;
    char nome[60];
    int tipo_apto, qtd_dia;
    float taxaServico, total_diaria, total = 0.00, subtotal = 0.00, valor_dia, consumo;
    printf("Nome do hospede: ");
    getchar();
    fgets(nome, sizeof(nome), stdin);
    printf("Qual o tipo de apto: (1-4) ");
    scanf("%d",&tipo_apto);
    switch(tipo_apto){
    case 1:
        valor_dia = 150.00;
        break;
    case 2:
        valor_dia = 100.00;
        break;
    case 3:
        valor_dia = 75.00;
        break;
    case 4:
        valor_dia = 50.00;
        break;
    default:
        printf("apto invalido!\n");
        return 1;
    }
    printf("Quantas diarias? ");
    scanf("%d",&qtd_dia);
    printf("Quanto foi consumido? ");
    scanf("%f",&consumo);
    total_diaria = valor_dia * qtd_dia;
    subtotal = total_diaria + consumo;
    taxaServico = subtotal * 0.10;
    total = taxaServico + subtotal;

    printf("\n--- Conta Final ---\n");
    printf("Nome: %s",nome);
    printf("\nTipo do apartamento: %d", tipo_apto);
    printf("\nNumero de diarias: %d", qtd_dia);
    printf("\nValor unitario da diaria: R$ %.2f", valor_dia);
    printf("\nValor total das diarias: R$ %.2f", total_diaria);
    printf("\nValor do consumo interno: R$ %.2f", consumo);
    printf("\nSubtotal: R$ %.2f", subtotal);
    printf("\nValor da taxa de servico: R$ %.2f", taxaServico);
    printf("\nTotal: R$ %.2f\n",total);

    printf("\nDeseja cadastrar outro hóspede? 1 - Sim   2 - Nao\n");
    scanf("%d", &opcao);

    }while (opcao == 1);
    return 0;
}
