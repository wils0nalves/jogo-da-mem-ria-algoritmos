#include <stdio.h> //entrada e saida de dados
#include <stdlib.h> //para a matem�tica no c�digo
#include <locale.h> //para aceitar o portugues ou qualquer outra lingua com acentos e pontua��es
#include <windows.h> /*para ter algumas compatibilidades com o windows com alguns comandos como a resolu��o da tela e o sleep,srand*/
#include <conio.h> //para usar o geth

int main(void){	
	
	int i = 0, j = 0, acertos = 0, r;
	char c,nome[2][10];
	int numeros[5];
	int numeros2[10];
	int respostas[5];
	int respostas2[10];
	int dificuldade;
	
	system("color F0"); // cor do programa (letra preta e fundo branco)
	
	system("mode con:cols=80 lines=20"); //resolu��o da tela
	
	printf("Digite seu nome para iniciar o jogo: ");
	scanf("%s",&nome);
	
	system("cls");
	
	printf("%s o jogo tem duas dificuldades a NORMAL e a DIF�CIL\n",nome); //para printar o nome do jogador
	printf("\ndigite 1 para a NORMAL e 2 para DIFICIL: ");
	scanf("%d",&dificuldade); //para selecionar dificuldade
	
	system("cls"); //apagar linhas anteriores
	
	if(dificuldade == 1){ 
		
	do{ //inicio da repeticao no caso o var R
	acertos = 0; //para que os acertos n�o buguem e some mais caso o jogo se repita
	setlocale(LC_ALL, "Portuguese"); //para o programa mudar sua linguagem e entender a acentua��o em PT-BR
	
	SetConsoleTitle("VT - Jogo da memoria "); //titulo do programa no topo
	
	srand(time(NULL)); //semente para gerar n�meros aleatorios do rel�gio do pc
	
	printf ("5 n�meros aleat�rios ser�o gerados entre 1 e 30.\n\n");
	printf ("decore os n�meros exibidos em 5 segundos e depois escreva-os na\nordem em que foram exibidos.\n\n");
	printf ("Vamos l� %s Pressione ENTER para iniciar",nome);
	
	do{
		c = getch(); //getch para comparar e ver se o enter foi pressionado no caso o 13 � o enter em binario
	}while (c != 13); //13 e o numero binario correspondente ao botao enter
	
	for (i = 0; i < 5; i++){
		numeros[i] = (rand() % 30)+1; //para randomizar os 30 numeros pois est� na dificuldade f�cil
	}
	
	
	
	j=5; //contador
	
	do{
		system ("cls"); // para apagar as linhas anteriores mais uma vez
		printf ("Decore os n�meros abaixo em %d\n\n\n", j);
		j--; // contador no agora negativo para contar de 5 para o 0 at� o tempo acabe e o player memorize os n�meros
		for (i = 0; i < 5; i++){ 
			printf ("%d\t", numeros[i]); //mostrando os n�meros para digitar 
		}
		Sleep (1000); /*o sleep serve para parar o programa em determinado tempo,aqui s� coloquei 1000 para parar em 1 seg junto com a var j e voltar pro loop*/
		 
	}while (j>0); //para executar as linhas acima at� que chegue ao valor 0 e passe para a proxima parte 
	
	system ("cls");
	printf ("Agora digite os n�meros que foram exibidos\n\n");
	
	for (i = 0; i < 5; i++){ //mais uma vez 5 n�meros por�m agora � pro usu�rio digitar 
		printf ("\t%d� n�mero: ", i+1);
		scanf ("%d", &respostas[i]);
		for(j = 0; j < 5; j++)
		{
		
		if (respostas[i] == numeros[j]){
			acertos++; /*para contar os acertos,se os acertos aqui forem igual a 5 que � o vinculado valor ao for. ele vai adicionando mais um a variavel acerto
			para mais tarde mostrar se o usu�rio venceu o game ou caso n�o acerte todos os n�meros vai ser mostrado a quantidade de acertos*/
		}}
	}
	
	if (acertos == 5){ //se o player acertar os 5 n�meros ele receber� essa mensagem de vit�ria
		printf ("\n\nMuito Bem! voc� acertou todos os n�meros!!. Veja os n�meros exibidos:\n\n\t");
		for (i = 0;i < 5; i++){ //for para printar os n�meros que foram digitados pelo player
				printf ("|%d� %d|\t",i+1,numeros[i]);
		}
	}
	else //caso erre algum digito (ou acertar alguns)
	{
		printf ("\n\nQue pena! voc� errou. Veja os n�mero exibidos:\n\n\t");
		for (i = 0; i < 5; i++){
			printf ("|%d� %d|\t",i+1,numeros[i]);
		}
		printf("\n\n VOC� ACERTOU %d N�MEROS",acertos); //para printar os acertos do jogador
	}
	printf ("\n\n");
	printf("Digite 1 para re-iniciar e 0 para parar o jogo: ");
	scanf("%d",&r); //se receber 1 o programa re inicia
	system("cls");
}
while(r == 1);
}

	if(dificuldade == 2) //para selecionar dificuldade,se a dificuldade for igual a 2 a dificuldade ser� DIFICIL
	{
		do{

     acertos = 0;	
	setlocale(LC_ALL, "Portuguese");
	
	SetConsoleTitle("Jogo da memoria simples"); //titulo do programa no topo
	
	srand(time(NULL)); //para gerar numeros aleatorios
	
	printf ("10 n�meros aleat�rios ser�o gerados entre 1 e 100.\n\n");
	printf ("decore os n�meros exibidos em 15 segundos e depois escreva-os na\nordem em que foram exibidos.\n\n");
	printf ("Vamos l� %s Pressione ENTER para iniciar",nome);
	
	do{
		c = getch(); //para comprar o enter
	}while (c != 13); //13 e o numero binario correspondente ao botao enter
	
   	for (i = 0; i < 10; i++)
        {
		numeros2[i] = (rand() % 30)+i; //para randomizar os 30 numeros pois est� na dificuldade f�cil
         }
	
	j=15; //contador agora ser�o 15 segundos
	
	do{
          
		system ("cls");
			
		printf ("Decore os numeros abaixo em %d\n\n\n", j);
		j--; //contador da var j PARA FAZER A CONTAGEM EM NEGATIVO
		for (i = 0; i < 10; i++){
			printf ("%d\t", numeros2[i]);
		}
		Sleep (1000); //Para terminar o programa em 1000 segungos no caso agora para gerar a semente para o contador
	}while (j > 0); //quando o contador chegar a 0 fa�a
	
	system ("cls");
	printf ("Agora digite os n�meros que foram exibidos\n\n");
	
	for (i = 0; i < 10; i++)
    { //para guardar os 10 n�meros no scanf da var respostas
		
        printf ("\t%d� n�mero: ", i+1);
		
		scanf ("%d", &respostas2[i]);
		for(j = 0; j < 10; j++)
		{
		if (respostas2[i] == numeros2[j])
		{
		acertos++; //contar acertos
		}}
	}
	
	if (acertos == 10){
		printf ("\n\nPARAB�NS! %s todos os n�meros foram acertados na maior dificuldade!!. Veja os n�meros exibidos:\n\n\t",nome);
		for (i = 0; i < 10; i++){
				printf ("|%d� %d|\t",i+1,numeros2[i]);
		}
	}
			else //caso erre algum digito (ou acertar alguns)
	{
		printf ("\n\nQue pena! voc� errou. Veja os n�mero exibidos:\n\n\t");
		for (i = 0; i < 10; i++){
			printf ("|%d� %d|\t",i+1,numeros2[i]);
		}
		printf("\n\n VOC� ACERTOU %d N�MEROS",acertos); //para printar os acertos do jogador
	}
	
	printf ("\n\n");
	printf("Digite 1 para re-iniciar e 0 para parar o jogo: ");
	scanf("%d",&r);
	system("cls");
}
while(r == 1);
	}
	
	system ("pause");
	return 0;
}


/* wilson yuri barreto tinoco alves
algoritmos
professora alessandra fonseca
1� semestre
matricula: 600801759 N1 
*/
