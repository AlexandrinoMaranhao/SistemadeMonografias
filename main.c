#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct CadastroOrientador
{
  int id;
  char nome[50];
  char email[30];
  char telefone[20];
  char linkCurriculoLattes[50];
};
struct CadastroAluno
{
  int id;
  char nome[50];
  char email[30];
  char telefone[20];
  char matriculaSuap[12]
  char endereco[100];
};

struct CadastroMonografia
{
  int id1;
  int id2;
  int id3[2];
  char data[10];
  char tituloMonografia[50];
  bool status;
  char membrosBanca[50][50];
};

void funcaoCadastroMonografias(struct CadastroMonografia)
{


}
void funcaoCadastroAlunosOrientadores(int op)
{
    if(op = 1)
    {


    }
    else
    {

    }

}

void funcaoMenu()
{
    int opcao;
    printf("Escolha qual a op��o de cadastro: \n");
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
    }

}
int main()
{






    return 0;
}