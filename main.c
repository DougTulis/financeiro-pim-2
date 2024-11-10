#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int idVenda;
    int idProd;
    char nomeProd[50];
    int qtdVendida;
    float precoTotal;
    int dia, mes, ano;
} venda;   // feito pra representa a venda (vinicius)

#define maximoDeVendas 10000
venda vendas[maximoDeVendas];
int totalVendas = 0; // tamanho do array de struct venda
void carregarArquivoVendas();
float calculoDeReceita();

int main() {
     carregarArquivoVendas();
    int opcao;
    printf("\n=== MENU DO FINANCEIRO ===\n");
    printf("1. Ver Receita Total\n");
    printf("2. Exibir Resumo de Receitas\n");
    printf("0. Sair\n");
    printf("Escolha uma op��o: ");
    scanf("%d", &opcao);

    switch(opcao) {
    case 1: {
        float totalReceita = calculoDeReceita(); // total vai recebe o calculo total receita vinda da funcao que realiza toda a soma
        printf("Receita Total: R$ %.2f\n", totalReceita);
        break;
    }
    case 2:
        // exibirResumoReceitas(); em manutencao
        break;
    case 0:
        printf("Saindo do sistema financeiro...\n");
        break;
    default:
        printf("Op��o invalida...");
        system("pause");
    }

    return 0;
}

void carregarArquivoVendas () { // aqui eu vou precisar de uma funcao void quer carregue o arquivo contendo as informacoes da venda.
    FILE *arquivo = fopen("E:\\Linguagem_C\\financeiro-pim-2\\bin\\Debug\\Vendas.txt", "r"); // vo acessa pra ler o arquivo de vendas
    if (arquivo == NULL) {
        printf("Arquivo n�o encontrado."); // programacao defensiva
        totalVendas = 0; // comecando com 0 pra comecar a percorrer na leitura
        while (fscanf(arquivo, "%d,%d,%49[^,],%d,%f,%d,%d,%d",
                      &vendas[totalVendas].idVenda,
                      &vendas[totalVendas].idProd,
                      vendas[totalVendas].nomeProd,
                      &vendas[totalVendas].qtdVendida,
                      &vendas[totalVendas].precoTotal,
                      &vendas[totalVendas].dia,
                      &vendas[totalVendas].mes,
                      &vendas[totalVendas].ano) == 8) {
            totalVendas++;
        }
        fclose(arquivo);
    }
}

   float calculoDeReceita() {
    float receita = 0;
    for (int i = 0; i < totalVendas; i++) {
        receita += vendas[i].precoTotal;
    }
    return receita;
}
