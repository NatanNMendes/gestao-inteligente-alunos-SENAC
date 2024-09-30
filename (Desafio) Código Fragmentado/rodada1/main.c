#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main() {
    char nome[50], novoNome[50];
    int opcao, contador;

    do {
        mostrarMenu();
        opcao = lerOpcao();
        
        if (opcao == -1) { 
            printf("Entrada inválida! Por favor, insira um número.\n");
            continue;
        }

        switch (opcao) {
            case 1:
                boasVindas();
                capturarNome(nome);
                contador = contadorAlunos();
                exibirMensagemFinal(nome, contador);
                salvarAlunoNoArquivo(nome, contador); 
                break;
            case 2:
                lerAlunosDoArquivo();
                break;
            case 3:
                printf("Digite o nome do aluno a ser excluído: ");
                scanf("%49s", nome);  // Protegendo buffer overflow
                excluirAlunoDoArquivo(nome); 
                break;
            case 4:
                printf("Digite o nome do aluno a ser atualizado: ");
                scanf("%49s", nome);  // Protegendo buffer overflow
                printf("Digite o novo nome: ");
                scanf("%49s", novoNome);  // Protegendo buffer overflow
                atualizarAlunoNoArquivo(nome, novoNome); 
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
