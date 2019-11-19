// USO DE PONTEIRO E UNION
#include <stdio.h>
#include <string.h>
union un_inscricao // UNION ( ECONOMIZA MEMORIA )
{
	char cpf[12];
	char cnpj[15];
}; // MEMORIA : 15 BYTES.
void adicionaCPF(union un_inscricao *param){ // FUNCAO COM PONTEIRO PARA INSERIR UM VALOR EM CNPJ
	strcpy(param->cnpj, "0987654321"); // O PONTEIRO PARAM APONTA APENAS PARA A VARIAVEL DENTRO DA FUNCAO.
	printf("CNPJ : %s\n", param->cnpj);
}
int main()
{
	union un_inscricao inscricao; // DECLARAÇÃO DE VARIAVEL COM TIPO UNION_INSCRICAO (15 BYTES)
	strcpy(inscricao.cpf, "0123456789");
	printf("CPF: %s\n", inscricao.cpf);
	adicionaCPF(&inscricao); // CHAMANDO A FUNCAO, COLOCANDO COMO PARAMETRO O ENDEREÇO DA VARIAVEL INSCRICAO.
	printf("CPF: %s\n", inscricao.cpf);
}
