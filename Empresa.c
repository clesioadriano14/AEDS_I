#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

    typedef struct{
        char nome[50];
        int telefone;
        int data_nasc[3];
    }   Funcionario;

    int main()
{
    int mes_consulta, i;
    bool consulta = false;
    Funcionario funcionario[2];
    for(i=0;i<2;i++){
    printf("Informe o funcionario %d:\n",i+1);
    printf("Nome: ");
    scanf(" %[^\n]",funcionario[i].nome);
    printf("Telefone: ");
    scanf("%d",&funcionario[i].telefone);
    printf("Informe o dia do seu aniversario: ");
    scanf("%d",&funcionario[i].data_nasc[0]);
    printf("Informe o mes do seu aniversario: ");
    scanf("%d",&funcionario[i].data_nasc[1]);
    printf("Informe o ano do seu aniversario: ");
    scanf("%d",&funcionario[i].data_nasc[2]);
    }
    printf("Informe o mes de consulta: ");
    scanf("%d",&mes_consulta);
    for(i=0;i<2;i++){
    if(mes_consulta == funcionario[i].data_nasc[1])
    {
    consulta = true;
    printf("Aniversariantes do mes %d:\n",mes_consulta);
    printf("Nome: %s\n",funcionario[i].nome);
    printf("Telefone: %d\n",funcionario[i].telefone);
    printf("Dia do aniversario: %d\n",funcionario[i].data_nasc[0]);
    }
    }
    if (consulta == false)
    {
    printf("Nenhum registro no mes %d.",mes_consulta);
    }
}
