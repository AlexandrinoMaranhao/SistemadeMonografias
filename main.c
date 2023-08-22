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

// Versão 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
//#include <windows.h>  = para IDEs e sistemas Windows;

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

} dadosOrientador;

//Struct para receber os dados de cadastro de alunos
typedef struct 
{
  int id;
  char nome[70];
  char email[70];
  char telefone[20];
  char matricula[20];
  char endereco[100];
} dadosAluno;

//Struct dos membros da banca examinadora
typedef struct
{
  char nomemembroBanca[80];
  char departamento[10];
  
} membros_banca;

//Struct de data da defesa da monografia
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
  int id_outrosOrientadores[2];
  data dataApresentacao;
  char titulo[100];
  bool status; //1 - Aprovada; 0 - Reprovada
  membros_banca examinadores[5];
} dadosMonografia;

//Base de IDs do programa pra verificação:
int IDs[MAX*2];

//Contador de registros;
int cont_orientadores = 0;
int cont_alunos = 0;
int cont_monografias = 0;

//Protótipos das funções utilizadas
void limpaTela();
void funcaoMenu();
void cadastroOrientadores(dadosOrientador *orientadores);
void cadastroAlunos(dadosAluno *alunos);
void cadastroMonografias(dadosMonografia *monografias, dadosOrientador orientadores[], dadosAluno alunos[]);
void alteraDados(dadosMonografia *monografias, dadosOrientador *orientadores, dadosAluno *alunos);
void salvaDados_arquivo();
void carregaDados_arquivo();
void printaMonografias();
void printaOrientadores();
void printaAlunos();
void inicializa_ids();
int gerador_id();
void adiciona_id(int novo_id);
int verificaQtdCadastros(int cont);
int buscaAluno_id();
int buscaOrientador_id();

//Corpos das funções utlizadas
void limpaTela()
  {
  system("clear");
  }//Função para limpar a tela

void funcaoMenu()
	{
    int opcao;
    dadosMonografia monografias;
    dadosOrientador orientadores[MAX];
    dadosAluno alunos[MAX];
    
    do
    {
    printf("\n:::: BEM-VINDO AO SISCAD MONOGRAFIAS DCOMP::::");
    printf("\n:::\tMENU DO SISCAD MONOGRAFIAS\t::: ");
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
    printf("\nESCOLHA UMA DAS OPÇÕES: \n");
    scanf("%d", &opcao);

    limpaTela();
		switch(opcao)
		{
		case 1:
      limpaTela();
    cadastroOrientadores(orientadores);
        break;
		case 2:
      limpaTela();
    cadastroAlunos(alunos);
        break;
		case 3:
      limpaTela();
    cadastroMonografias(&monografias, orientadores, alunos);
        break;
    case 4:
      limpaTela();
    printf("Escolha qual item e quais dados você deseja alterar: ");
    alteraDados(&monografias, orientadores, alunos);
        break;
    case 5:
      limpaTela();
    printf("Escolha qual grupo de monografias você deseja mostrar: ");
      printaMonografias(monografias);
        break;
    case 6:
      limpaTela();
    printf("Aqui está a lista de todos os orientadores cadastrados: ");
      printaOrientadores(orientadores);
        break;
    case 7:
      limpaTela();
    printf("Aqui está a lista de todos os alunos cadastrados: ");
      printaAlunos(alunos);
        break;
    case 8:
      limpaTela();
    printf("Deseja salvar as informações inseridas? \n");
      salvaDados_arquivo();
        break;
    case 9:
      limpaTela();
      printf("Deseja carregar as informações inseridas? \n");
        carregaDados_arquivo();
        break;
    case 10:
      limpaTela();
    printf("Você saiu do sistema com sucesso. Aguardamos pelo seu próximo acesso.");
        break;
    default:
      printf("Opção Inválida! Tente novamente");
	    }
    } while(opcao != 10);
	}//Função do menu de opções

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

    orientadores[cont_orientadores].id = gerador_id(); 
    adiciona_id(orientadores[cont_orientadores].id);
    
    limpaTela();
    printf("CADASTRO DO ORIENTADOR %s REALIZADO COM SUCESSO!\n",orientadores[cont_orientadores].nome);
    cont_orientadores++;
    sleep(2);
    limpaTela();
    
    }
  }//Cadastro de orientadores no sistema

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
    
    printf("\nInsira o endereço do(a) aluno(a):\n");
    fgets(alunos[cont_alunos].endereco, 100, stdin);

    alunos[cont_alunos].id = gerador_id(); 
    adiciona_id(alunos[cont_alunos].id);
    
    limpaTela();
    printf("CADASTRO DO ALUNO %s REALIZADO COM SUCESSO!\n",alunos[cont_alunos].nome);
    cont_alunos++;
    sleep(2);
    limpaTela();
    
    }
  }//Cadastro de alunos no sistema

void alteraDados(dadosMonografia *monografias, dadosOrientador *orientadores, dadosAluno *alunos)
  {
    int escolha;

    scanf("%d", &escolha);
    while(escolha != 0)
      {     
        switch (escolha)
        {
        case 1:
            // Modify monografias
            // Example: Change the title of the first monografia
            printf("Enter the new title: ");
           // scanf("%s", monografias[].titulo);
            break;
        case 2:
            // Modify orientadores
            // Example: Change the name of the second orientador
            printf("Enter the new name: ");
            //scanf("%s", orientadores[1].nome);
            break;
        case 3:
            // Modify alunos
            // Example: Change the email of the third aluno
            printf("Enter the new email: ");
            //scanf("%s", alunos[].email);
            break;
        case 0:
            break;
        default:
            printf("Invalid option! Try again");
        }
      }
  } //Para alterar dados já inseridos

void printaMonografias(dadosMonografia *monografias)
  { 
  int escolhaGrupo;
  //int contAprovadas = 0, contReprovadas = 0;
  
    scanf("%d", &escolhaGrupo);

    switch(escolhaGrupo)
      {
        case 1:
          //while (X != EOF)
          //if(status == 1){para comparar o status
          //contAprovadas++}
          //else 
          //printf todas as aprovadas
        break;
        case 2:
          //while (X != EOF)
          //if(status == 0){para comparar o status
          //contReprovadas++}
          //else
          //printf todas as reprovadas
        
        break;
        case 3:
          //função de ler e printar o arquivo (while != EOF)
          //deveria puxar do arquivo
        break;
      }
  }//Imprime as monografias cadastradas (aprovadas, reprovadas e todas)

void printaOrientadores(dadosOrientador orientadores[])
  {
    for(int i = 0; i < cont_orientadores; i++)
      {
        printf("\nNOME DO ORIENTADOR: %s", orientadores[i].nome);
        printf("\nEMAIL: %s", orientadores[i].email);
        printf("\nTITULAÇÃO: %s", orientadores[i].titulacao);
        printf("\nTELEFONE: %s", orientadores[i].telefone);
        printf("\nCURRICULO LATTES: %s", orientadores[i].lattes);
        printf("\nID DO ORIENTADOR: %i", orientadores[i].id);
        printf("\n\n");
      }
  }//Imprime a lista de todos os orientadores cadastrados

void printaAlunos(dadosAluno alunos[])
  {
     for(int i = 0; i < cont_alunos; i++)
      {
        printf("\nNOME DO ALUNO: %s", alunos[i].nome);
        printf("\nEMAIL: %s", alunos[i].email);
        printf("\nTELEFONE: %s", alunos[i].telefone);
        printf("\nMATRICULA SUAP: %s", alunos[i].matricula);
        printf("\nENDEREÇO: %s", alunos[i].endereco);
        printf("\nID DO ALUNO: %i", alunos[i].id);
        printf("\n\n");
      }
  }//Imprime a lista de todos os alunos cadastrados

int verificaQtdCadastros(int cont)
  {
  if (cont+1 >= MAX)
   {
    return 0; //Incapaz de realizar cadastro devido ao tamanho excedido do vetor de cadastros do contador utilizado como parâmetro
   }
  else
   {
    return 1; //Ainda há possibilidades de cadastros
   }
  }//Verifica se é possível ou não inserir novo cadastro

void inicializa_ids()
  {
  for (int i = 0; i<MAX*2; i++)
    {
    IDs[i] = 0;
    
    }
  }//Inicializa a base de ids do programa

int gerador_id ()
 {
  srand(time(NULL));//Inicializa a semente do gerador de números aleatórios
  int codigo_id = rand() % 9000 + 1000;//Gera um número aleatório entre 1000 e 9999 para servir como ID
  
  for (int i = 0; i<MAX*2; i++)
  {
    if (IDs[i] == codigo_id)
    {//Verificação se ID já existe
      codigo_id = rand() % 9000 + 1000; //Gera novamente outro ID
      i = 0;//Reinicia o loop para verificar novamente
  
    }
  }
   return codigo_id;
 }//Gera id aleatório

void adiciona_id(int novo_id)
 {
  for (int i = 0; i<MAX*2; i++)
  {
    if (IDs[i] == 0)
    {
      IDs[i] = novo_id;
      return;
      
    }
  }
 }//Acrescenta novo id a base de ids

int buscaAluno_id(dadosAluno alunos[], int idProcurado)
 {
  for (int i = 0; i < cont_alunos; i++)
    {
      if(alunos[i].id == idProcurado)
      {
        return i;
      }
    }
      return -1;
 }//Realiza busca de aluno por ID

int buscaOrientador_id(dadosOrientador orientadores[], int idProcurado)
 {
  for (int i = 0; i < cont_orientadores ; i++)
  {
    if(orientadores[i].id == idProcurado)
    {
      return i; //Retorna posição do vetor em que o orientador está
    }
  }
  return -1;
 }//Realiza busca de orientador por ID

void adiciona_outro_orientador(dadosMonografia *monografias, dadosOrientador orientadores[])
{
  printf("ainda em fase de construcao rsrs");
}//Adição de outros orientadores para monografia

void escolha_orientador(dadosMonografia *monografias, dadosOrientador orientadores[])
{
  int input_id;
  
  while (1){
    printf("LISTA DE ORIENTADORES CADASTRADOS:\n");
    printaOrientadores(orientadores); //Exibe lista de orientadores
    printf("\nEscolha um orientador digitando seu ID ou digite 1 para cadastrar um novo no sistema:\n");
    scanf("%i",&input_id);

    if (input_id != 1){
      int busca = buscaOrientador_id(orientadores, input_id);//Busca por ID da lista:
      if (busca != -1)
      {//ID encontrado
        int outro_orientador;
        printf("ORIENTADOR ESCOLHIDO: %s\n", orientadores[busca].nome);
        monografias[cont_monografias].idOrientador = orientadores[busca].id;
        break;
        
      }else
      {//ID não encontrado
      limpaTela();
      funcaoMenu();
      }   
      
    }
  }
}//Escolha de orientador responsável por uma monografia

void escolha_aluno(dadosMonografia *monografias, dadosAluno alunos[])
{
  int input_id;

  while(1){
    printf("LISTA DE ALUNOS CADASTRADOS:\n");
    printaAlunos(alunos);//Exibe lista de alunos
    printf("\n---------------------------------------\n");
    printf("\nEscolha um aluno digitando seu ID ou digite 1 para cadastrar um novo no sistema:\n");
    scanf("%i",&input_id);

    if (input_id != 1){
      int busca = buscaAluno_id(alunos, input_id);
      if (busca != -1)
      {//ID encontrado
        printf("ALUNO ESCOLHIDO: %s\n", alunos[busca].nome);
        monografias[cont_monografias].idAluno = alunos[busca].id;
        break;
        
      }
      else
      {//ID não encontrado
           limpaTela();
           funcaoMenu();
      }  
    }
  }
}//Escolha de aluno responsável por uma monografia

int verifica_data(int dia, int mes, int ano)
{
  if ((dia >= 0 || dia <= 31) || (mes >= 0 || mes <= 12) || (ano >= 2020))
  {
    return 1;//Data válida
    
  }
  return 0;//Data inválida
}//Verifica se as datas inseridas são válidas

void cadastroMonografias(dadosMonografia *monografias, dadosOrientador orientadores[], dadosAluno alunos[])
{
  int resultado = verificaQtdCadastros(cont_monografias); 
  
  if (resultado == 0){//verificação:
    printf("Incapaz de realizar novos cadastros! Quantidade máxima excedida.\n");
    
  }else{
    //Verificação se há um aluno e um orientador cadastrado (mínimo)
    if (cont_orientadores == 0){
      limpaTela();
      printf("\nÉ NECESSARIO PRIMEIRAMENTE CADASTRAR UM ORIENTADOR!");
      
    }else if (cont_alunos == 0){
      limpaTela();
      printf("\nÉ NECESSÁRIO PRIMEIRAMENTE CADASTRAR UM ALUNO!");
          
    }else{
      //Inserção de dados:
      int dia, mes, ano;
      
      escolha_orientador(monografias, orientadores);//Escolha de orientador
      escolha_aluno(monografias, alunos);//Escolha de aluno

      while(1){
        printf("Digite o dia da apresentação da monografia:\n");
        scanf("%i",&dia);

        printf("Digite o mês da apresentação da monografia:\n");
        scanf("%i",&mes);

        printf("Digite o ano da apresentação da monografia\n");
        scanf("%i",&ano);

        if (verifica_data(dia, mes, ano) == 1)
        {
          monografias[cont_alunos].dataApresentacao.dia = dia;
          monografias[cont_alunos].dataApresentacao.mes = mes;
          monografias[cont_alunos].dataApresentacao.ano = ano;
          
          break;
          
        }else
        {
          printf("DATAS INVÁLIDAS! VERIFIQUE O ERRO E TENTE NOVAMENTE:\n");
          printf("\n");
          
        } 
      }
      printf("Digite o título da monografia:\n");
      getchar();
      fgets(monografias[cont_monografias].titulo, 100, stdin);

      while(1){
        int status;
        printf("Digite o status da monografia:\n0 - REPROVADA\n1 - APROVADA\n");
        scanf("%i",&status);

        if (status == 0 || status == 1){
          monografias[cont_monografias].status = status;
          break;
          
        }else{
          printf("RESPOSTA INVÁLIDA! TENTE NOVAMENTE:\n");
          printf("\n");
          
        }
        cont_monografias++;
        //adiciona_membros_banca();
      }
    
     }
 
    }

  }//Cadastro de monografias no sistema

void salvaDados_arquivo(dadosOrientador *orientadores, dadosAluno *alunos, dadosMonografia *monografias) 
{
    FILE *arquivo = fopen("dados.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo!\n");
        sleep(2);
        return;
    }
int verificar_duplicacao(dadosOrientador *orientadores, int num_orientadores, dadosAluno *alunos, int num_alunos, dadosMonografia *monografias, int num_monografias, int id_orientador, int id_aluno);
    fprintf(arquivo, "ORIENTADORES\n");
    for (int i = 0; i < cont_orientadores; i++) {
        fprintf(arquivo, "ID: %d\n", orientadores[i].id);
        fprintf(arquivo, "Nome: %s\n", orientadores[i].nome);
        fprintf(arquivo, "E-mail: %s\n", orientadores[i].email);
        fprintf(arquivo, "Titulação: %s\n", orientadores[i].titulacao);
        fprintf(arquivo, "Telefone: %s\n", orientadores[i].telefone);
        fprintf(arquivo, "Link do Currículo: %s\n", orientadores[i].lattes);
    }

    fprintf(arquivo, "ALUNOS\n");
    for (int i = 0; i < cont_alunos; i++) 
    {
        fprintf(arquivo, "ID: %d\n", alunos[i].id);
        fprintf(arquivo, "Nome: %s\n", alunos[i].nome);
        fprintf(arquivo, "E-mail: %s\n", alunos[i].email);
        fprintf(arquivo, "Matrícula do SUAP: %s\n", alunos[i].matricula);
        fprintf(arquivo, "Telefone: %s\n", alunos[i].telefone);
        fprintf(arquivo, "Endereço completo: %s\n", alunos[i].endereco);
    }

    fprintf(arquivo, "MONOGRAFIAS\n");
    for (int i = 0; i < cont_monografias; i++) 
    {
        fprintf(arquivo, "Numero da Monografia: %d\n", cont_monografias);
        fprintf(arquivo, "Título de monografia: %s\n", monografias[i].titulo);
        fprintf(arquivo, "Data de apresentação: %d/%d/%d\n", monografias[i].dataApresentacao.dia,
               monografias[i].dataApresentacao.mes,
               monografias[i].dataApresentacao.ano);
        fprintf(arquivo, "ID do orientador principal: %d\n", monografias[i].idOrientador);
        fprintf(arquivo, "ID do aluno: %d\n", monografias[i].idAluno);
        fprintf(arquivo, "Outros orientadores: %d, %d\n", monografias[i].id_outrosOrientadores[0],
               monografias[i].id_outrosOrientadores[1]);
        fprintf(arquivo, "Status: %d\n", monografias[i].status);
        for (int j = 0; j < 5; j++) 
        {
        fprintf(arquivo, "Membro da banca examinadora %d: %s\n", j + 1, monografias[i].examinadores[j]);
        }
    }

    fclose(arquivo);

    printf("Dados salvos no arquivo 'dados.txt' com sucesso!\n");
    sleep(2);
}

void carregaDados_arquivo(dadosOrientador *orientadores,  dadosAluno *alunos, dadosMonografia *monografias) 
{
    FILE *arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        sleep(2);
        return;
    }

    char buffer[100];
    int secao = 0;

    while (fgets(buffer, 100, arquivo) != NULL) {
        strtok(buffer, "\n");

        if (strcmp(buffer, "ORIENTADORES") == 0) {
            secao = 1;
            continue;
        } else if (strcmp(buffer, "ALUNOS") == 0) {
            secao = 2;
            continue;
        } else if (strcmp(buffer, "MONOGRAFIAS") == 0) {
            secao = 3;
            continue;
        }

        if (secao == 1) {
            if (strncmp(buffer, "ID: ", 4) == 0) {
                orientadores[cont_orientadores].id = atoi(buffer + 4);
            } else if (strncmp(buffer, "Nome: ", 6) == 0) {
                strcpy(orientadores[cont_orientadores].nome, buffer + 6);
            } else if (strncmp(buffer, "E-mail: ", 8) == 0) {
                strcpy(orientadores[cont_orientadores].email, buffer + 8);
            } else if (strncmp(buffer, "Titulação: ", 11) == 0) {
                strcpy(orientadores[cont_orientadores].titulacao, buffer + 11);
            } else if (strncmp(buffer, "Telefone: ", 10) == 0) {
                strcpy(orientadores[cont_orientadores].telefone, buffer + 10);
            } else if (strncmp(buffer, "Link do Currículo: ", 19) == 0) {
                strcpy(orientadores[cont_orientadores].lattes, buffer + 19);
                cont_orientadores++;
            }
        } else if (secao == 2) {
            if (strncmp(buffer, "ID: ", 4) == 0) {
                alunos[cont_alunos].id = atoi(buffer + 4);
            } else if (strncmp(buffer, "Nome: ", 6) == 0) {
                strcpy(alunos[cont_alunos].nome, buffer + 6);
            } else if (strncmp(buffer, "E-mail: ", 8) == 0) {
                strcpy(alunos[cont_alunos].email, buffer + 8);
            } else if (strncmp(buffer, "Matrícula do SUAP: ", 19) == 0) {
                alunos[cont_alunos].matricula;
            } else if (strncmp(buffer, "Telefone: ", 10) == 0) {
                strcpy(alunos[cont_alunos].telefone, buffer + 10);
            } else if (strncmp(buffer, "Endereço completo: ", 19) == 0) {
                strcpy(alunos[cont_alunos].endereco, buffer + 19);
                cont_alunos++;
            }
        } else if (secao == 3) {
             if (strncmp(buffer, "Título de monografia: ", 22) == 0) {
                strcpy(monografias[cont_monografias].titulo, buffer + 22);
            } else if (strncmp(buffer, "Data de apresentação: ", 22) == 0) {
                sscanf(buffer + 22,
                       "%d/%d/%d",
                       &monografias[cont_monografias].dataApresentacao.dia,
                       &monografias[cont_monografias].dataApresentacao.mes,
                       &monografias[cont_monografias].dataApresentacao.ano);
            } else if (strncmp(buffer, "ID do orientador principal: ", 28) == 0) {
                monografias[cont_monografias].idOrientador = atoi(buffer +                                                                    28);
            } else if (strncmp(buffer, "ID do aluno: ", 13) == 0) {
                monografias[cont_monografias].idAluno = atoi(buffer + 13);
            } else if (strncmp(buffer, "Outros orientadores: ", 21) == 0) {
                sscanf(buffer + 21,
                       "%d, %d",
                       &monografias[cont_monografias].id_outrosOrientadores[0],
                       &monografias[cont_monografias].id_outrosOrientadores[1]);
            } else if (strncmp(buffer, "Status: ", 8) == 0) {
                strcpy(monografias[cont_monografias].status, buffer + 8);
            } else if (strncmp(buffer, "Membro da banca examinadora ", 28) == 0) {
                int membro = buffer[28] - '1';
                strcpy(monografias[cont_monografias].examinadores[membro].nomemembroBanca,
                       buffer + 31);
            } else if (strcmp(buffer, "-------------------------------------") == 0) {
                cont_monografias++;
            }
        }
    }

    fclose(arquivo);

    printf("Dados carregados do arquivo 'dados.txt' com sucesso!\n");
    sleep(2);
}

int main(void)
{
dadosOrientador orientadores[MAX];
dadosAluno alunos[MAX];
dadosMonografia monografias[MAX];
 
printf("Esse sistema experimental se propõe a ser um sistema de cadastro e monitoria de monografias, orientadores e orientandos.");
printf("\nAcesse um das opções do nosso menu: \n");
printf("\n\n");
 funcaoMenu();
  return 0;
}
