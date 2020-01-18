/*22.Leia o nome completo de uma pessoa (nome /  nome do meio  / sobrenome) de uma vez só.
Em seguida, exiba cada uma das palavras do nome em linhas diferentes.
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main(){
	setlocale(LC_ALL, "");
	char nome[50];
	int i, j;
	printf("Digite seu nome: ");
	gets(nome);
	for(i = 49; i >= 0; i--){
		if(nome[i - 1] == ' ' || i == 0){
		for(j = i; j <= 49, nome[j] != ' '; j++){
			if(nome[j] != ' ' && nome[j] >= 'A' && nome[j] <= 'Z' || nome[j] >= 'a' && nome[j] <= 'z')
				printf("%c", nome[j]);
	}
		}
		if(nome[i] == ' ')
	printf("\n");
	}
}





#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
main()
{
setlocale(LC_ALL, "");
int num , parimpar, base, expoente, aux, aux2, aux3, ano, nota1, nota2, nota3, media, fatorial, fibonacci;
int i, j;
	do{
		printf("Escolha uma opção : \n");
		printf("1 - Diz se o número é par ou ímpar.\n2 - Realiza uma potenciação\n3 - Realiza uma radiciação\n");
		printf("4- Informa se o ano digitado é bissexto.\n5 - Calcula a média ponderada do aluno\n6 - Calcula a média do aluno, informando se foi aprovado\n");
		printf("7 - Lê e calcula o fatorial de um número\n8 - Lê um número e informa se é primo ou não\n9 - Calcula a sequência de fibonacci.\n");	
		scanf("%d", &num);
		switch(num){
			case 0: 
				printf("Adeus!\n");
				break;
			case 1:
				printf("Digite um número para saber se é par ou ímpar : ");
				scanf("%d", &parimpar);
				if(parimpar % 2 == 0)
					printf("O número é par.\n\n");
				else
					printf("O número é ímpar.\n\n");
				break;
			case 2:
				aux = 1;
				printf("Digite 2 números para a potenciação, o primeiro é a base e o segundo o expoente: ");
				scanf("%d", &base);
				scanf("%d", &expoente);
				for(i = 1; i <= expoente; i++)
					aux = aux * base;
				printf("O resultado foi %d.\n\n", aux);
				break;
			case 3:
				printf("Digite 2 números para a radiciação, o primeiro é o radicando e o segundo, o índice: ");
				scanf("%d", &base);
				scanf("%d", &expoente);
				for(i = 1; ; i++){
					aux = 1;
					for(j = 1; j <= expoente; j++){
						aux = aux*i;
					}
					if(aux == base)
						  break;
					}
					printf("O resultado da radiciação é: %d\n\n", i);
					break;
			case 4: 
				printf("Digite um ano para saber se o mesmo é bissexto: ");
				scanf("%d", &ano);
				if(ano % 4 == 0 && ano % 100 != 0 )
					printf("O ano é bissexto.\n\n");
				else
					printf("O ano não é bissexto.\n\n");
				break;
			case 5:
				printf("Desculpe, não lembro qual era a ponderação.");
				break;
			case 6:
				printf("Digite suas 3 notas(0 - 100): ");
				scanf("%d%d%d", &nota1, &nota2, &nota3);
				if(nota1 > 100 || nota1 < 0 || nota2 > 100 || nota2 < 0 || nota3 > 100 || nota3 < 0){
					printf("Nota(s) inválida(s)\n\n");
					break;
				}
				media = (nota1+nota2+nota3) / 3;
				if(media >= 70)
					printf("O aluno foi aprovado. ");
				else if(media < 70 && media >= 40)
					printf("O aluno fará a prova final. ");
				else if(media < 40)
					printf("O aluno reprovou. ");
				printf("Sua média foi: %d\n\n", media);
				break;
			case 7:
				aux = 1;
				printf("Digite um número para saber seu resultado fatorial: ");
				scanf("%d", &fatorial);
				while(fatorial > 1){
					aux = aux * fatorial;
					fatorial--;
				}
				printf("O resultado fatorial é %d.\n\n", aux);
				break;
			case 8:
				aux = 0;
				printf("Digite um número para saber se o mesmo é primo: ");
				scanf("%d", &num);
				for(i = num - 1; i > 1; i--){
					if(num % i == 0){
						aux = 1;
						break;
					}
				}
				if(aux == 1)
					printf("O número não é primo.\n\n");
				else
					printf("O número é primo.\n\n");
				break;
				
				case 9:
					aux = 1;
					aux2 = 0;
					aux3 = 0;
				printf("Digite um número que represente a quantidade de elementos da sequência de fibonacci: ");
				scanf("%d", &fibonacci);
				for(i = 1; i < fibonacci; i++){
					printf("%d, ", aux);
					aux3 = aux2;
					aux2 = aux;
					aux = aux + aux3;
				}
				printf("%d.\n\n", aux);	
				break;
	}
}while(num != 0);
}
