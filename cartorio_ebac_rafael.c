#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o (caracteres especiais (acentos))
#include <string.h> //biblioteca de reconhecimento de strings

int registrar() //definindo fun��es que ser�o chamadas ao decorrer do programa (cadastro de usuario)
{
	setlocale(LC_ALL, "Portuguese"); //localiza��o de linguagem
	setlocale (LC_ALL, "Portuguese_Brasil.1252"); //localiza��o de linguagem
	
	//in�cio da cria��es das vari�veis
	char arquivo[15]; //criando vari�vel para abertura e altera��o de arquivo de registro e 
	char cpf[15]; //criando vari�vel para ser utilizada em string (mesmo que CPF sejam n�meros, s�o varios caracteres)
	char nome[20]; //criando vari�vel para ser utilizada em string
	char sobrenome[40]; //o n�mero entre colchetes representa a quantidade m�xima de caracteres que a string vai processar.
	char cargo[40];
	//final da cria��o das vari�veis
	
	
	//coletando informa��es para registro
	printf("\n ---____---___--__---  REGISTRAR NOMES  ---__--___---____---\n\n\n\n");
	
	printf("\n ---{ Digite o CPF a ser cadastrado: ");
	scanf("%s",cpf); //%s para escanear "string"
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores da string cpf para a string arquivo
	
	FILE *dados; //FILE = comando para acessar a fun��o na biblioteca, *dados � o nome que eu dei para o par�metro que ser� chamado por futuros comandos
	dados = fopen(arquivo, "w"); //cria um arquivo no banco de dados (nesse caso na pasta do sistema do cart�rio) (w = write)
	fprintf(dados," __CPF: "); //ap�s criar o arquivo com o comando anteriror, salva o " CPF: " no arquivo
	fclose(dados); //fecha o arquivo
	dados = fopen(arquivo, "a");
	fprintf(dados,cpf); //ap�s abrir para atualiza��o o arquivo com o comando anteriror, salva o "cpf" registrado pelo scanf logo acima
	fclose(dados);
	dados = fopen(arquivo, "a");
	fprintf(dados,"   __NOME: "); //conforme o comando anterior, salva uma "automaticamente" o que est� entre "" ap�s o ultimo dado, nesse caso, ap�s o cpf inserido pelo usu�rio
	fclose(dados);
	
	system("cls"); //comando que limpa a tela ap�s uma fun��o ser completa
	printf("\n ---____---___--__---  REGISTRAR NOMES  ---__--___---____---\n\n\n\n");
	
	printf("\n ---{ Digite o nome: ");
	scanf("%s",nome);
	dados = fopen(arquivo, "a"); // se guiando pela variavel arquivo, abre um arquivo real com base no cpf com "a" para atualizar o arquivo
	fprintf(dados,nome); //atualiza conforme o comando anterior, salvando o "nome" registrado pelo scanf logo acima
	fclose(dados);
	dados = fopen(arquivo, "a");
	fprintf(dados," ");
	fclose(dados);
	
	system("cls");
	printf("\n ---____---___--__---  REGISTRAR NOMES  ---__--___---____---\n\n\n\n");
	
	printf("\n ---{ Digite o sobrenome: ");
	scanf("%s",sobrenome);
	dados = fopen(arquivo, "a");
	fprintf(dados,sobrenome);
	fclose(dados);
	dados = fopen(arquivo, "a");
	fprintf(dados,"   __CARGO: ");
	fclose(dados);
	
	system("cls");
	printf("\n ---____---___--__---  REGISTRAR NOMES  ---__--___---____---\n\n\n\n");
	
	printf("\n ---{ Digite o cargo: ");
	scanf("%s",cargo);
	dados = fopen(arquivo, "a");
	fprintf(dados,cargo);
	fclose(dados);
	
	system("cls");
	printf("\n ---____---___--__---  REGISTRAR NOMES  ---__--___---____---\n\n\n\n");
	printf("          ---{ Registro armazenado com sucesso }---\n\n\n\n\n");
	system("pause"); //comando que pausa o sistema para o usu�rio ler, prossegue clicando em qualquer tecla
}

int consultar() //fun��o de consulta
{
	setlocale(LC_ALL, "Portuguese"); //localiza��o de linguagem
	setlocale (LC_ALL, "Portuguese_Brasil.1252"); //localiza��o de linguagem
	
	//cria��o de vari�veis
	char cpf[15]; 
	char conteudo[200];
	
	//coletando e analisando cpf para consulta
	printf("\n ---____---___--__---  CONSULTAR NOMES  ---__--___---____---\n\n\n\n");
	printf("\n ---{ Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	system("cls");
	FILE *dados; //referindo o arquivo
	dados = fopen(cpf,"r"); //abrindo arquivo referente a dados em modo leitura
	
	while(fgets(conteudo, 200, dados) != NULL) //puxando o conte�do do arquivo enquanto ele for != de nulo, at� que acabem as informa��es com uma maxima de 200 caracteres
	{
		printf("\n ---____---___--__---  CONSULTAR NOMES  ---__--___---____---\n\n\n\n");
		printf("\t      ---{ Informa��es registradas }---\n\n\n");
		printf("%s", conteudo); //entregando oconte�do do arquivo ao usu�rio
		printf("\n\n\n\n\n\n\n");
	}
	
	if(dados == NULL) //para quando o CPF for digitado errado
	{
		printf("\n ---____---___--__---  CONSULTAR NOMES  ---__--___---____---\n\n\n\n");
		printf("\t\t---{ CPF n�o registrado }---\n\n\n\n\n");
	}
	system("pause");
	fclose(dados);
}

int deletar() //fun��o de deletar
{
	setlocale(LC_ALL, "Portuguese");
	setlocale (LC_ALL, "Portuguese_Brasil.1252");// localiza��o de linguagem
	
	char cpf[15]; //vari�vel para localizar o arquivo que ser� deletado
	
	//fun��o irrelevante para o siste, mas que com a pr�xima cria um senso maior de necessidade de aten��o ao CPF digitado
	printf("\n ---____---___--__---  DELETAR NOMES  ---__--___---____---\n\n\n\n");
	printf("\n ---{ Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	system("cls");
	
	//coletando dados para realmente deletar o CPF solicitado
	printf("\n ---____---___--__---  DELETAR NOMES  ---__--___---____---\n\n\n\n");
	printf("\n ---{ Digite novamente para confirmar: ");
	scanf("%s",cpf);
	system("cls");
	
	FILE *dados; //referindo o arquivo com base no CPF coletado
	dados = fopen(cpf,"r"); //aprindo arquivo apenas para leitura
	fclose(dados);
	
	if(dados != NULL)
	{
		remove(cpf); //fun��o para deletar do banco de dados o arquivo de mesmo nome do CPF lido pela fun��o scanf acima
		
		printf("\n ---____---___--__---  DELETAR NOMES  ---__--___---____---\n\n\n\n");
		printf("\n\t ---{ Registro deletado com sucesso }---\n\n\n\n");
		system("pause");
	}
	
	if(dados == NULL) //para o caso do CPF ter sido digitado errado
	{
		printf("\n ---____---___--__---  DELETAR NOMES  ---__--___---____---\n\n\n\n");
		printf("\n\t ---{ Registro n�o encontrado }---\n\n\n\n");
		system("pause");
	}
}

int main() //fun��o principal
{
	
	int opcao=0; //definindo nome e valor da vari�vel de decis�o (numero inteiro)
	int laco=1; //sistema de repeti��o de processos
	
	for(laco=1;laco==1;) //nesse caso o loop acontecer� infinitamente, pois com "laco=1;" defino seu valor, enquanto que, com "laco==1;", digo que sempre que o valor for 1 ele deve se repitir ap�s o fim das instru��es
	                    //Existem diversos exemplos, mas por ex: for(laco=0;laco=1;) ou for(laco=30;laco=1;) ou for(laco=1;laco!=1;) o loop nunca aconteceria porque as informa��es s�o divergentes
	                   //for(laco=1;laco!=5;) � outro exemplo onde o loop aconteceria infinitamente, por�m se
	                  //for(laco=0;laco!=5;laco++) o loop aconteceria 5 vezes, pois eu defino "laco=0" e depois digo que se ele "laco!=5" ele deve acontecer, mas depois da ultimia instru��o, o break;, laco++ faz com que "laco=0" se torne "laco=1" e isso continua ocorrendo at� "laco=5", nesse momento "laco n�o � !=5", ent�o ele n�o executa o loop ou suas instru��es e vai para a fun��o seguinte.
	{
		system("cls");
		setlocale(LC_ALL, "Portuguese"); //comando para setar que os caracteres especiais usados ser�o os do portugu�s
		setlocale (LC_ALL, "Portuguese_Brasil.1252"); 
	
		printf("\n ]]]____]]]___]]__---  CART�RIO DA EBAC  ---__[[___[[[____[[["); //in�cio do menu
		printf("\n                    ----______________----\n\n\n\n"); // "\n = avan�ar uma linha"
		printf("\t ---{ Escolha a op��o desejada do menu }--- \n\n\n"); // "\t = espa�o inicial"
		printf("\t 1. Registrar nomes \n\n");
		printf("\t 2. Consultar nomes \n\n");
		printf("\t 3. Deletar nomes \n\n");
		printf("\t 4. Sair do sistema \n\n\n\n");
		printf("\t ---{ Escolher op��o: ");
		
		scanf("%d", &opcao);
		
		system("cls"); //limpeza de tela p�s escolha do usu�rio
		
		switch(opcao)
		{
			case 1:
			registrar(); //chamando fun��o diretamente ao inv�s de executar processos dentro da fun��o principal
			break;
				
			case 2:
			consultar();
			break;
				
			case 3:
			deletar();
			break;
				
			case 4:
			printf("\n\n          ---{ Obrigado por utilizar o sistema }---\n\n\n\n\n");
			return 0;
			break;
				
			default:
			printf("\n ---____---___--__---  OP��O INV�LIDA  ---__--___---____---\n\n\n\n");
			system("pause");
			break;
		}
		
		printf("\n\n Software desenvolvido por Rafael G. Ribeiro em 14/07/2023");
	}
}
