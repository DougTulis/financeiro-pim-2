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

int main() {
    int opcao;
    printf("===MENU DO FINANCEIRO===\n");
      printf("\n=== Menu Financeiro ===\n");
        printf("1. Registrar Receita\n");
        printf("2. Ver Receita Total\n");
        printf("3. Exibir Resumo de Receitas\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

         switch(opcao) {
            case 1:
                int id, quantidade;  // registrando uma receita
                float valorTotal;
                char nomeProduto[50];
                printf("ID do produto: ");
                scanf("%d", &id);
                printf("Nome do prduto: ");
                scanf("%s", nomeProduto);
                printf("Quantidade vendida: ");
                scanf("%d", &quantidade);
                printf("valor Total da Venda:");
                scanf("%f", &valorTotal);
                // registrarReceita(id,nomeProduto,  quantidade, valorTotal); (funcao em manutencao)
            break ;
            case 2:
            case 3:
            case 4:
         }

    return 0;
}



void carregarArquivoVendas () { // aqui eu vou precisar de uma funcao void quer carregue o arquivo contendo as informacoes da venda.
    FILE *arquivo = fopen("E:\\Linguagem_C\\financeiro-pim-2\\bin\\Debug\\Vendas.txt", "r"); // vo acessa pra ler o arquivo de vendas
    if (arquivo == NULL) {
        printf("Arquivo não encontrado."); // programacao defensiva
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

    float CalculoDeReceita() {
        float receita;

        for (int i = 0 ; i < totalVendas ; i ++) {
            receita += vendas[i].precoTotal;
            printf("DOUGLASS");
        }
        return receita;
    }

}
