\\exercicio prog geom
#include <stdio.h>
int pot(int base, int expoente){
	int i;
	int aux = 1;
	for(i = 1; i <= expoente; i++)
	{
		aux = aux * base;
	}
	return aux;
}
float VAL(float valor, int anos, float taxa){
	int i;
	float aux;
	float aux2 = 0;
	for(i = 1; i<= anos; i++)
	{
		aux = pot(1+taxa, i);
		aux2 = aux2 + (valor/aux);
	}
	return aux2;
}
main()
{
	float valor, taxa;
	int anos;
	printf("Digite o valor e a taxa\n");
	scanf("%f%f", &valor, &taxa);
	printf("\nAgora, digite o tempo em anos.\n");
	scanf("%d", &anos);
	float x = VAL(valor, anos, taxa);
	printf("%f", x);
}
