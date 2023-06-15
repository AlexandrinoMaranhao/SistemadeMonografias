#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#define MAX 15

//Struct para receber os dados de cadastro de orientadores
typedef struct  
{
  int id;
  char nome[70];
  char email[70];
  char titulacao[70];
  char telefone[20];
  char lattes[70];
//int orientacoes;
} dadosOrientador;

//Struct para receber os dados de cadastro de alunos
typedef struct 
{
  int id;
  char nome[70];
  char email[70];
  char telefone[20];
  char matricula[15];
  char endereco[100];
} dadosAluno;

//Struct dos membros da banca examinadora
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
} dadosMonografia;

//Base de IDs do programa pra verificação:
int IDs[MAX*2];

//Contador de registros;
int cont_orientadores = 0;
int cont_alunos = 0;
int cont_monografias = 0;

//Protótipos para chamada das funções utilizadas
void limpaTela();
void funcaoMenu();
void cadastroOrientadores(dadosOrientador *orientadores);
void cadastroAlunos(dadosAluno *alunos);
void cadastroMonografias(dadosMonografia *monografias, dadosOrientador orientadores[], dadosAluno alunos[]);
//void loginAdmin();
//void alteraDados(dadosMonografia *monografias, dadosOrientador *rientadores, dadosAluno *alunos);
void salvaDados();
void carregaDados();
void printaMonografias();
void printaOrientadores();
void printaAlunos();
void inicializa_ids();
void adiciona_id(int novo_id);
int geradorID();
int verificaQtdCadastros(int cont);

//Corpos das funções utlizadas
void limpaTela()
  {
  system("clear");
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
    printf("\n4) ALTERAÇÃO DE DADOS CADASTRADOS");
    printf("\n5) RELATÓRIO DAS MONOGRAFIAS");
    printf("\n6) RELATÓRIO DOS ORIENTADORES");
    printf("\n7) RELATÓRIO DOS ALUNOS");
    printf("\n8) SALVAMENTO DAS INFORMAÇÕES ");
    printf("\n9) CARREGAMENTO DAS INFORMAÇÕES");
    printf("\n10) SAÍDA DO SISTEMA");
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
    printf("Escolha qual item e quais dados você deseja alterar: ");
      
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
    printf("Você saiu do sistema com sucesso. Aguardamos pelo seu próximo acesso.");
        break;
    default:
      printf("Opção Inválida! Tente novamente");
	    }
    } while(opcao != 10);
	}

void cadastroOrientadores(dadosOrientador *orientadores)
  {
    int checagem = verificaQtdCadastros(cont_orientadores);
    
    if(checagem == 0)
    {
    printf("Quantidade máxima de cadastros excedida, não é possível realizar mais cadastros");
    }
    else
    {
    printf("Digite o nome do(a) orientador(a):\n");
    getchar();
    fgets(orientadores[cont_orientadores].nome, 70, stdin); 
    
    printf("\nDigite o email do(a) orientador(a):\n");
    fgets(orientadores[cont_orientadores].email, 70, stdin);
    
    printf("\nDigite a titulação do(a) orientador(a):\n");
    fgets(orientadores[cont_orientadores].titulacao, 70, stdin);
    
    printf("\nDigite o telefone do(a) orientador(a):\n");
    fgets(orientadores[cont_orientadores].telefone, 20, stdin);
    
    printf("\nInsira o link do currículo do(a) orientador(a):\n");
    fgets(orientadores[cont_orientadores].lattes, 70, stdin);

    orientadores[cont_orientadores].id = geradorID(); 
    adiciona_id(orientadores[cont_orientadores].id);
    
    limpaTela();
    printf("CADASTRO DO ORIENTADOR %s REALIZADO COM SUCESSO!\n",orientadores[cont_orientadores].nome);
    cont_orientadores++;
    sleep(2);
    limpaTela();
    
    }
  } 

void cadastroAlunos(dadosAluno *alunos)
  {
    int checagem = verificaQtdCadastros(cont_alunos);
    
   if(checagem == 0)
    {
    printf("Quantidade máxima de cadastros excedida, não é possível realizar mais cadastros");
    }
    else
    {
    printf("Digite o nome do(a) aluno(a):\n");
    getchar();
    fgets(alunos[cont_alunos].nome, 70, stdin); 
    
    printf("\nDigite o email do(a) aluno(a):\n");
    fgets(alunos[cont_alunos].email, 70, stdin);
    
    printf("\nDigite o telefone do(a) aluno(a):\n");
    fgets(alunos[cont_alunos].telefone, 20, stdin);
    
    printf("\nInsira o numero da matricula do aluno(a):\n");
    fgets(alunos[cont_alunos].matricula, 15, stdin);
    
    printf("\nInsira o link do currículo do(a) orientador(a):\n");
    fgets(alunos[cont_alunos].endereco, 100, stdin);

    alunos[cont_alunos].id = geradorID(); 
    adiciona_id(alunos[cont_alunos].id);
    
    limpaTela();
    printf("CADASTRO DO ALUNO %s REALIZADO COM SUCESSO!\n",alunos[cont_alunos].nome);
    cont_alunos++;
    sleep(2);
    limpaTela();
    
    }
  }

void cadastroMonografias(dadosMonografia *monografias, dadosOrientador orientadores[], dadosAluno alunos[])
	{
   
	}

/*void loginAdmin()
  {
  //char usuarioAdmin[] = {'admin'}
  //char senha[] = {'admin123'}
  //int saida = 1;
    
  //strcpy
  }*/

//void alteraDados(){}

void printaMonografias()
  {
  int idO;
  int idA;
  int idOO[2]; //00 = Outros Orientadores
  int data[10];
  char titulo[100];
  bool status; //1 - Aprovada; 0 - Reprovada
  char examinadores[50];
    
  int escolhaGrupo;
  
    scanf("%d", &escolhaGrupo);

    switch(escolhaGrupo)
      {
        case 1:
          //while != EOF
          //if(status == 1) para comparar o status
          //else 
          //printf todas as aprovadas
        break;
        case 2:
          //while != EOF-
          //if(status == 0) para comparar o status
          //else
          //printf todas as reprovadas
        
        break;
        case 3:
          //função de ler e printar o arquivo (while != EOF)
          //vai puxar do arquivo
        break;
      }
  }

void printaOrientadores()
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
void printaAlunos()
  {
  int id;
  char nome[70];
  char email[70];
  char telefone[20];
  char titulacaoAcademica[70];
    //(while != EOF)
    //printf
  }

int verificaQtdCadastros(int cont)
  {
  if (cont+1 >= MAX)
  {
    return 0; //Incapaz de realizar cadastro devido ao tamanho excedido do vetor de cadastros do contador utilizado como parâmetro
    
  }else
  {
    return 1; //Ainda há possibilidades de cadastros
  }
  }//Verifica se é possível ou não inserir novo cadastro





int main()
{
dadosOrientador orientadores[MAX];
dadosAluno alunos[MAX];
dadosMonografia monografias[MAX];

int entrada = 0;
  
printf("Esse sistema experimental se propõe a ser um sistema de cadastros de monografias");
printf("\nAcesse um das opções do nosso menu: ");
 funcaoMenu();
  return 0;
}
