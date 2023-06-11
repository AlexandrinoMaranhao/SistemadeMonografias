#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct cadastroOrientador   //Struct para receber os dados de cadastro de orientadores
{
  int id;
  char nome[50];
  char email[30];
  char telefone[20];
  char linkCurriculoLattes[50];
} cadO;

typedef struct cadastroAluno      //Struct para receber os dados de cadastro de alunos
{
  int id;
  char nome[50];
  char email[30];
  char telefone[20];
  char matriculaSuap[12]
  char endereco[100];
} cadA;

typedef struct cadastroMonografia      //Struct para recebr os dados de cadastro de monografias
  int id1;
  int id2;
  int id3[2];
  char data[10];
  char tituloMonografia[50];
  bool status;
  char membrosBanca[50][50];
} cadM;

	void funcaoCadastroMonografias(struct cadastroMonografia)
	{
        

	}
	void funcaoCadastroAlunosOrientadores(int op)
	{
		if(op = 1)
		{
          printf()  

		}
		else
		{

		}

	}

	void funcaoMenu()
	{
    int opcao;
    printf("Escolha qual a opção de cadastro: \n");
    scanf("%d", &opcao);

		switch(opcao)
		{
		case 1:
         funcaoCadastroAlunosOrientadores(op);
         break;
		case 2:
         funcaoCadastroAlunosOrientadores(op);
        break;
		case 3:
         funcaoCadastroMonografias();
         break;
        case 4:
         printf("Você saiu do SisCAD com sucesso.");
         break;
        default:
         printf("Opção Inválida!!");
         break;
	    }
	}


int main()
{
	printf(":::: Bem-Vindo ao SisCAD Edu ::::");
    printf("\n:::\tMENU do SISCAD\t::: ");
    printf("\n1) Cadastro de Orientador.");
    printf("\n2) Cadastro de Aluno.");
    printf("\n3) Cadastro de Monografia.");
    printf("\n4) Saída do Sistema.");
    
    while(opcao != 4)
    {
      funcaoMenu();
      
    }

    return 0;
}
