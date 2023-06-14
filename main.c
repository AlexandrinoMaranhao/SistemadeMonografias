#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX 15
//Struct para receber os dados de cadastro de orientadores
typedef struct  
{
  int id;
  char nome[70];
  char email[70];
  char telefone[20];
  char titulacaoAcademica[70];
} cad_O;

//Struct para receber os dados de cadastro de alunos
typedef struct 
{
  int id;
  char nome[70];
  char email[70];
  char telefone[20];
  char matricula[12];
  char endereco[100];
} cad_A;

//Struct da banca examinadora
typedef struct
{
  char membroBanca[80];
  char departamento[10];
  
} membros_banca;

//Struct de data da defesa
typedef struct
{
  int dia;
  int mes;
  int ano;
} data;

//Struct para recebr os dados de cadastro de monografias
typedef struct 
{
  int idOrientador;
  int idAluno;
  int idOutrosOrientadores[2];
  data dataApresentacao;
  char tituloMonografia[100];
  bool status; //1 - Aprovada; 0 - Reprovada
  membros_banca examinadores[5];
} cad_M;

//Base de IDs do programa pra verificação:
int IDs[MAX*2];

//Contador de registros;
int cont_orientadores = 0;
int cont_alunos = 0;
int cont_monografias = 0;

//Protótipos para chamada das funções utilizadas
void cadastroOrientadores();
void cadastroAlunos();
void cadastroMonografias();
void loginAdmin();
void funcaoMenu();
void limpaTela();
int geraID();
int verificaQtd();

void relatorioMonografias();
void relatorioOrientadores();
void relatorioAlunos();

//Corpos das funções utlizadas
void cadastroOrientadores()
  {
    
  }  
void cadastroAlunos()
  {
   
  }
void cadastroMonografias()
	{
    /*int entrada;

    scanf("%d", &entrada);
    while(entrada != 0)
    scanf("%d", &cad_M.id1);
    scanf("%d", &cad_M.id2);
    scanf("%d\t%d",&cad_M.id3[]);

    fgets();*/

	}
void loginAdmin()
  {
  //int saida = 1;

  
  }


void funcaoMenu()
	{
    int opcao;
    do
    {
    printf(":::: Bem-Vindo ao SISCAD DCOMP::::");
    printf("\n:::\tMENU do SISCAD\t::: ");
    printf("\n1) CADASTRO DE ORIENTADOR");
    printf("\n2) CADASTRO DE ALUNO");
    printf("\n3) CADASTRO DE MONOGRAFIA");
    printf("\n4) ALTERAÇÃO DE DADOS");
    printf("\n5) RELATÓRIO DAS MONOGRAFIAS");
    printf("\n6) RELATÓRIO DOS ORIENTADORES");
    printf("\n7) RELATÓRIO DOS ALUNOS");
    printf("\n8) SALVAMENTO DAS INFORMAÇÕES ");
    printf("\n9) CARREGAMENTO DAS INFORMAÇÕES");
    printf("\n10) LOGIN");//usuário padrão admin; admin123
    printf("\n11) SAÍDA DO SISTEMA");
    scanf("%d", &opcao);

    limpaTela();
		switch(opcao)
		{
		case 1:
    cadastroOrientadores();
        break;
		case 2:
    cadastroAlunos();
        break;
		case 3:
    cadastroMonografias();
        break;
    case 4:
      printf("Escolha qual dos dados que você quer alterar: ");
      
        break;
    case 5:
      printf("Escolha qual grupo de monografias você deseja acessar: ");
        break;
    case 6:
      printf("Aqui está a lista de todos os orientadores cadastrados: ");
        break;
    case 7:
      printf("Aqui está a lista de todos os alunos cadastrados: ");
        break;
    case 8:
      printf("Deseja salvar as informações inseridas? ");
        break;
    case 9:
       printf("Deseja carregar as informações inseridas? "); 
        break;
    case 10:
      printf("Faça login no sistema");
    loginAdmin();
        break;
    case 11:
        printf("Você saiu com sucesso, todos os dados estão salvos. Até o próximo acesso.");
        break;
    default:
      printf("Opção Inválida!");
	    }
    } while(opcao != 11);
	}

void limpaTela()
  {
  system("clear");
  }



void relatorioMonografias()
  {
  int idO;
  int idA;
  int idOO[2];
  int data[10];
  char titulo[100];
  bool status; //1 - Aprovada; 0 - Reprovada
  char examinadores[50];
    
  int escolha;
  
    scanf("%d", &escolha);

    switch(escolha)
      {
        case 1:
          //while != EOF-if(status == 1) para comparar o status
          //printf todas as aprovadas
        break;
        case 2:
          //while != EOF-if(status == 0) para comparar o status
          //printf todas as reprovadas
        
        break;
        case 3:
          //função de ler e printar o arquivo (while != EOF)
          //vai puxar do arquivo
        break;
      }
  }

void relatorioOrientadores()
  {
  int id;
  char nome[70];
  char email[70];
  char telefone[20];
  char matricula[12];
  char endereco[100];
    //(while != EOF)
    //printf
  }
void relatorioAlunos()
  {
  int id;
  char nome[70];
  char email[70];
  char telefone[20];
  char titulacaoAcademica[70];
    //(while != EOF)
    //printf
  }




int main()
{
cad_O orientadores[MAX];
cad_A alunos[MAX];
cad_M monografias[MAX];

int entrada = 0;
  
printf("Esse sistema experimental se propõe a ser um sistema de cadastros de monografias");
printf("\nAcesse um das opções do nosso menu: ");
 funcaoMenu();

  
  return 0;
}
