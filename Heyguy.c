#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <conio.h>
#include "funcoesheyguy.h"
int main()
{
char espaco, tecla;
int qtde, auxqtde, numjogador = 1;
int gameover;
int x_atual, y_atual, x_anterior, y_anterior;
int k, l, z; // variáveis para percorrer for
struct jogadores *jogadores;	// Ponteiro para alocação dinamica; 	
	
	setlocale(LC_ALL,""); //add acentuação
	cabecalho();
	texto();
	printf("\n| PRESSIONE A TECLA ENTER PARA CONTINUAR |");
	scanf("%c", &espaco);
	
	if(espaco= 32) {
		system("Cls");
	}
		  
	printf("Digite a quantidade de jogadores: ");                                //quantidade de jogadores;
	scanf("%d", &qtde);
	jogadores = (struct jogadores*) malloc (qtde*sizeof(struct jogadores)); // separando memoria para todos os jogadores;
	
  for(z = 0; z < qtde; z++) // Estrutura do jogo para cada jogador;
  {
  	char matriz[20][10] = { {'K','K','R','I','P','T','O','N',' ','K'}, // ESTRUTURA DO JOGO
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
  	x_atual = 5, y_atual = 19;
  	gameover = 0; 
	auxqtde = qtde - 1; // aux vai servir para não repetir o ultimo printf na vez do ultimo jogador.
	jogadores[z].pontuacao = 0;
	jogadores[z].highscore = 0;
	flush_in();
	
    printf("Digite seu nome : ");
    gets(jogadores[z].nomes);
   
    printf("\nControle o jogo usando as teclas \n'a' - esquerda\n'd'- direita\nCaso pressione outra tecla, o Superman repetirá o último movimento!");
    printf("\npressione ENTER para confirmar a escolha à cada movimento.\n");
    printf("NÃO encoste nas K(riptonitas).\nENTER - Ok\n\n");
	getchar();
    system("cls"); // limpa a tela para não printar várias vezes o array
	system("color bC");

	for(k = 0; k < 20; k++) // Imprime o formato do jogo
	{
		for(l = 0; l < 10; l++){
		printf("%c", matriz[k][l]);
		}
		printf("\n");
	}
	tecla = getchar(); // SEMPRE QUER TIVER TECLA = GETCHAR(), É PARA O ANDAMENTO DO JOGO
	while(tecla != 'a' && tecla != 'd')// TENTANDO CORRIGIR ERRO
	{
		flush_in();
		printf("Comando inválido! Tente novamente.");
		tecla = getchar();
	}
	
	while(gameover != 1){

		if(tecla == 'a'){
		for(x_atual, y_atual;  ; x_atual--, y_atual-- ) // for para avançar o jogo à esquerda
		{
			y_anterior = y_atual + 1;
			x_anterior = x_atual + 1;
			system("cls"); // limpa a tela para não printar várias vezes o array
			Sleep(100);
		
			matriz[y_atual][x_atual] = 'S'; // faz o S "andar"
			matriz[y_anterior][x_anterior] = ' '; // matriz[x][y] apaga o rastro de 'S' do caminho

			jogadores[z].pontuacao = jogadores[z].pontuacao + 1;
			jogadores[z].highscore = jogadores[z].highscore + jogadores[z].pontuacao; // TENTANDO CRIAR O HIGHSCORE

			if(matriz[y_atual][0] == 'S' || matriz[y_atual][9] == 'S') // FUNÇÃO GAMEOVER(QUANDO BATE NO S)
			{
				printf("GAME OVER\n");
				gameover = 1;
				break;
			}
			if(matriz[0][x_atual] == 'S')
			{ // FUNÇÃO WIN
				printf("Parabéns! o Superman chegou à Kripton graças aos seus esforços!\n");
				gameover = 1;
				break;
			}
			for(k = 0; k < 20; k++){
				for(l = 0; l < 10; l++){
					printf("%c", matriz[k][l]); // printa a matriz
				}
				printf("\n");
			}

			tecla = getchar();
			if(tecla == 'd')
				break;
		}
}

		if(tecla == 'd')
		{
	
			for(x_atual, y_atual; ; x_atual++, y_atual--)
			{ // AVANÇA O 'S' PARA DIREITA
				y_anterior = y_atual + 1;
				x_anterior = x_atual - 1; // X E Y TEM O PAPEL DE "IMPRIMIR ESPAÇOS ONDE O 'S' ESTAVA"
				system("cls"); 
				Sleep(100); 
		
				matriz[y_atual][x_atual] = 'S';
				matriz[y_anterior][x_anterior] = ' '; // X E Y TEM O PAPEL DE IMPRIMIR ESPAÇOS ONDE O 'S' ESTAVA
				jogadores[z].pontuacao = jogadores[z].pontuacao + 1;
				jogadores[z].highscore = jogadores[z].highscore + jogadores[z].pontuacao; // TENTANDO CRIAR HIGHSCORE

				if(matriz[y_atual][0] == 'S' || matriz[y_atual][9] == 'S')// FUNÇÃO GAMEOVER
				{ 
					printf("GAME OVER\n");
					gameover = 1;
					break;
				}
				if(matriz[0][x_atual] == 'S')// FUNÇÃO WIN
				{ 
					printf("Parabéns! o Superman chegou à Kripton graças aos seus esforços!\n"); 
					gameover = 1;
					break;
				}
			
				for(k = 0; k < 20; k++)
				{
					for(l = 0; l < 10; l++)
						printf("%c", matriz[k][l]); 
				
					printf("\n");
 
				}	 
				tecla = getchar();
				if(tecla == 'a')
					break;

															}
		}
					}
	 printf("Jogador: %s - > Número: %d - > pontuação: %d\n",jogadores[z].nomes, numjogador, jogadores[z].pontuacao ); // Imprime a pontuação do jogador atual;
   
   	 if(z < auxqtde)
   	 printf("Digite enter para recomeçar o jogo.\n"); // Se ainda houverem jogadores, aparece a mensagem.
   
   	 numjogador++; // ATUALIZA O NUMERO DE JOGADOR
	}
	free(jogadores);
}
