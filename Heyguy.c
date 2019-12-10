#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <conio.h>
#include "funcoesheyguy.h"
int main()
{
	
	setlocale(LC_ALL,""); //add acentuação
	cabecalho();
	texto();
	char espaco;
	printf("\n| PRESSIONE A TECLA ENTER PARA CONTINUAR |");
	scanf("%c", &espaco);
	
	if(espaco= 32) {
		system("Cls");
	}
	
	struct jogadores *jogadores;	// Ponteiro para alocação dinamica; 
	
	int qtde, z, numjogador = 1; 	  
	printf("Digite a quantidade de jogadores: ");                                //quantidade de jogadores;
	scanf("%d", &qtde);
	jogadores = (struct jogadores*) malloc (qtde*sizeof(struct jogadores)); // separando memoria para todos os jogadores;
	
  for(z = 0; z < qtde; z++) // Estrutura do jogo para cada jogador;
  {
  	int aux = qtde - 1; // aux vai servir para não repetir o ultimo printf na vez do ultimo jogador.
  	jogadores[z].pontuacao = 0;
  	jogadores[z].highscore = 0;
	flush_in();
	
   printf("Digite seu nome : ");
   gets(jogadores[z].nomes);
   
   printf("\nControle o jogo usando as teclas \n'a' - esquerda\n'd'- direita\nCaso pressione outra tecla, o Superman repetirá o último movimento!");
   printf("npressione ENTER para confirmar a escolha à cada movimento.\n");
   printf("NÃO encoste nas K(riptonitas).\nENTER - Ok\n\n");
   	getchar();
   system("cls"); // limpa a tela para não printar várias vezes o array
system("color bC");

char matriz[20][10]= { {'K',' ','K','R','I','P','T','O',' ','K'}, // ESTRUTURA DO JOGO
					 {'K',' ',' ',' ',' ',' ',' ',' ',' ','K'},
					 {'K',' ',' ',' ',' ',' ',' ',' ',' ','K'},
					 {'K',' ',' ',' ',' ',' ',' ',' ',' ','K'},
					 {'K',' ',' ',' ',' ',' ',' ',' ',' ','K'},
					 {'K',' ',' ',' ',' ',' ',' ',' ',' ','K'},
					 {'K',' ',' ',' ',' ',' ',' ',' ',' ','K'},
					 {'K',' ',' ',' ',' ',' ',' ',' ',' ','K'},
					 {'K',' ',' ',' ',' ',' ',' ',' ',' ','K'},
					 {'K',' ',' ',' ',' ',' ',' ',' ',' ','K'},
					 {'K',' ',' ',' ',' ',' ',' ',' ',' ','K'},
					 {'K',' ',' ',' ',' ',' ',' ',' ',' ','K'},
					 {'K',' ',' ',' ',' ',' ',' ',' ',' ','K'},
					 {'K',' ',' ',' ',' ',' ',' ',' ',' ','K'},
					 {'K',' ',' ',' ',' ',' ',' ',' ',' ','K'},
					 {'K',' ',' ',' ',' ',' ',' ',' ',' ','K'},
					 {'K',' ',' ',' ',' ',' ',' ',' ',' ','K'},
					 {'K',' ',' ',' ',' ',' ',' ',' ',' ','K'},
					 {'K',' ',' ',' ',' ',' ',' ',' ',' ','K'},
					 {'K',' ',' ',' ',' ','S',' ',' ',' ','K'}
					};
int i = 5, j = 19, k, l;
int x, y;

for(k = 0; k < 20; k++) // Imprime o formato do jogo
{
	for(l = 0; l < 10; l++){
		printf("%c", matriz[k][l]);
	}
	printf("\n");
}
char tecla;
int gameover = 0; // VARIAVEIS PARA O FUNCIONAMENTO DO JOGO
tecla = getchar(); // SEMPRE QUER TIVER TECLA = GETCHAR(), É PARA O ANDAMENTO DO JOGO
if(tecla != 'a' && tecla != 'b' && gameover == 0){ // TENTANDO CORRIGIR ERRO(ESSE DEU CERTO, EU ACHO)
	flush_in();
	printf("Comando inválido! Tente novamente.");
	tecla = getchar();
}

while(gameover != 1){

if(tecla == 'a'){
	for(i, j;  ; i--, j-- ) // for para avançar o jogo à esquerda
	{
				x = j + 1;
				y = i + 1;
				system("cls"); // limpa a tela para não printar várias vezes o array
		Sleep(100);
		
matriz[j][i] = 'S'; // faz o S "andar"
matriz[x][y] = ' '; // matriz[x][y] apaga o rastro de 'S' do caminho

jogadores[z].pontuacao = jogadores[z].pontuacao + 1;
jogadores[z].highscore = jogadores[z].highscore + jogadores[z].pontuacao; // TENTANDO CRIAR O HIGHSCORE

if(matriz[j][0] == 'S' || matriz[j][9] == 'S'){ // FUNÇÃO GAMEOVER(QUANDO BATE NO S)
	printf("GAME OVER\n");
	gameover = 1;
	break;
}
if(matriz[0][i] == 'S'){ // FUNÇÃO WIN
	printf("Parabéns! o Superman chegou à Kripton graças aos seus esforços!\n");
	gameover = 1;
	break;
}
for(k = 0; k < 20; k++)
{
	for(l = 0; l < 10; l++)
	{
		printf("%c", matriz[k][l]); // printa a matriz
	}
	printf("\n");
}

tecla = getchar(); 
if(tecla == 'd')
	break;


} 
}
if(tecla == 'd'){
	for(i, j; ; i++, j--){ // AVANÇA O 'S' PARA DIREITA
		x = j + 1;
		y = i - 1; // X E Y TEM O PAPEL DE "IMPRIMIR ESPAÇOS ONDE O 'S' ESTAVA"
	 system("cls"); 
		Sleep(100); 
		
matriz[j][i] = 'S';
matriz[x][y] = ' '; // X E Y TEM O PAPEL DE IMPRIMIR ESPAÇOS ONDE O 'S' ESTAVA
jogadores[z].pontuacao = jogadores[z].pontuacao + 1;
jogadores[z].highscore = jogadores[z].highscore + jogadores[z].pontuacao; // TENTANDO CRIAR HIGHSCORE

if(matriz[j][0] == 'S' || matriz[j][9] == 'S'){ // FUNÇÃO GAMEOVER
	printf("GAME OVER\n");
	gameover = 1;
	break;
}
if(matriz[0][i] == 'S'){
	printf("Parabéns! o Superman chegou à Kripton graças aos seus esforços!\n"); // FUNÇÃO WIN
	gameover = 1;
	break;
}
for(k = 0; k < 20; k++)
{
	for(l = 0; l < 10; l++)
	{
		printf("%c", matriz[k][l]); 
	}
	printf("\n");
 
} 
	tecla = getchar(); 
	if(tecla == 'a')
	break;

}
}
}
printf("Jogador: %s - > Número: %d - > pontuação: %d\n",jogadores[z].nomes, numjogador, jogadores[z].pontuacao ); // Imprime a pontuação do jogador atual;
   
   if(z < aux)
   printf("Digite enter para recomeçar o jogo.\n"); // Se ainda houverem jogadores, aparece a mensagem.
   
   numjogador++; // ATUALIZA O NUMERO DE JOGADOR
}
}
  
