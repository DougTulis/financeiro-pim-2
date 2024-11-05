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
    Venda venda[maximoDeVendas]
    int totalVendas = 0; // tamanho do array de struct venda

int main() {
printf("===MENU DO FINANCEIRO===\n");
    return 0;
}


    void carregarArquivoVendas () { // aqui eu vou precisar de uma funcao void quer carregue o arquivo contendo as informacoes da venda.
        FILE arquivo* = fopen("C:\Users\dotul\Projetos em C\Financeiro\bin\Debug\Vendas.txt", "r"); // vo acessa pra ler o arquivo de vendas
        if (arquivo == NULL) {
            printf("Arquivo não encontrado.") // programacao defensiva
         totalVendas = 0; // comecando com 0 pra comecar a percorrer na leitura
         while (fscanf(arquivo, "%d,%d,%49[^,],%d,%f,%d,%d,%d",
                  &vendas[totalVendas].idVenda,
                  &vendas[totalVendas].idProd,
                  vendas[totalVendas].nomeProd,
                  &vendas[totalVendas].qtdVendida,
                  &vendas[totalVendas].precoTotal,
                  &vendas[totalVendas].dia,
                  &vendas[totalVendas].mes,
                  &vendas[totalVendas].ano) == 7) {
        totalVendas++;
    }
        }

    }
