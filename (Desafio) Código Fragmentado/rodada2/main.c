#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main() {
    char nome[50], novoNome[50], genero[20], parteNome[50], novoGenero[20];
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
                if (validarNome(nome)) {
                    capturarGenero(genero);
                    contador = contadorAlunos();
                    exibirMensagemFinal(nome, contador);
                    salvarAlunoNoArquivo(nome, genero, contador);
                    registrarLog("Atualização", novoNome);
                }
                break;
            case 2:
                lerAlunosDoArquivo();
                break;
            case 3:
                if (verificarSenha()) {
                    printf("Digite o nome do aluno a ser excluído: ");
                    scanf("%s", nome);
                    excluirAlunoDoArquivo(nome);
                }
                break;
            case 4:
                printf("Digite o nome do aluno a ser atualizado: ");
                scanf("%49s", nome); 
                printf("Digite o novo nome: ");
                scanf("%49s", novoNome);  
                atualizarAlunoNoArquivo(nome, novoNome);
                registrarLog("Atualização", nome);
                break;
            case 5:
                restaurarBackup();
                break;
            case 6:
                printf("Digite o nome do aluno para pesquisar: ");
                scanf("%s", nome);
                if (pesquisarAluno(nome)) {
                    printf("Aluno %s encontrado.\n", nome);
                } else {
                    printf("Aluno %s não encontrado.\n", nome);
                }
                break;
            case 7:
                contarAlunosPorGenero();
                break;
            case 8:
                ordenarAlunos();
                break;
            case 9:
                printf("Digite o gênero dos alunos a serem excluídos: ");
                scanf("%s", genero);
                excluirAlunosPorGenero(genero);
                limparArquivoSeVazio();
                break;
            case 10: 
                contador = contarTotalAlunos();
                printf("Total de alunos registrados: %d\n",
                contador);
                break;
            case 11:
                gerarRelatorioCompleto();
                break;
            case 12:
                printf("Digite parte do nome para buscar: ");
                scanf("%s", parteNome);
                buscarAlunoPorParteNome(parteNome);
                break;
            case 13:
                exportarParaCSV();
                break;
            case 14:
                printf("Digite o nome do aluno: ");
                scanf("%s", nome);
                printf("Digite o novo gênero: ");
                scanf("%s", novoGenero);
                alterarGeneroAluno(nome, novoGenero);
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
