#include <stdio.h>
#include <string.h>
#include "funcoes.h"

int main() {
    char usuario[50], senha[50];
    char data[20];
    int idioma;

    printf("Selecione o idioma:\n1. Português\n2. Inglês\n");
    scanf("%d", &idioma);
    definirIdioma(idioma);
    exibirMensagemBoasVindas();
    exibirEstatisticas();

    char *aluno = buscarAlunoCache(101);
    printf("Aluno encontrado: %s\n", aluno);

    registrarAuditoria("admin", "Buscou aluno");

    printf("Digite o nome de usuário: ");
    scanf("%s", usuario);

    do {
        printf("Digite a senha: ");
        scanf("%s", senha);
    } while (!validarSenhaForte(senha));

    if (!login(usuario, senha)) {
        registrarLogErro("Tentativa de login falhou");
        printf("Acesso negado.\n");
        return 0;
    }

    char email[50] = "admin@exemplo.com";
    char conteudo[200] = "Relatório de alunos cadastrados.";
    enviarRelatorioPorEmail(email, conteudo);

    printf("Digite a data (DD/MM/AAAA): ");
    scanf("%s", data);
    gerarRelatorioPorData(data);

    int opcao, contador;

    char nome[50], genero[20], novoNome[50], parteNome[50], novoGenero[20];

    do {
        mostrarMenuMelhorado();
        opcao = lerOpcao();

        if (opcao == -1) {
            printf("Entrada inválida! Por favor, insira um número.\n");
            continue;
        }

        if (opcao == 3 && verificarNivelPermissao(usuario) == 0) {
            printf("Permissão negada. Apenas administradores podem excluir dados.\n");
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
                    registrarLog("Adição", nome);
                }
                break;
            case 2:
                listarAlunos();
                registrarLog("Listagem de alunos", "N/A");
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
                scanf("%s", nome);
                printf("Digite o novo nome: ");
                scanf("%s", novoNome);
                atualizarAlunoNoArquivo(nome, novoNome);
                registrarLog("Atualização", nome);
                break;
            case 5:
                printf("Digite o gênero dos alunos a serem excluídos: ");
                scanf("%s", genero);
                excluirAlunosPorGenero(genero);
                limparArquivoSeVazio();
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
                contador = contarTotalAlunos();
                printf("Total de alunos registrados: %d\n", contador);
                break;
            case 10:
                gerarRelatorioCompleto();
                break;
            case 11:
                printf("Digite parte do nome para buscar: ");
                scanf("%s", parteNome);
                buscarAlunoPorParteNome(parteNome);
                break;
            case 12:
                exportarParaCSV();
                break;
            case 13:
                printf("Digite o nome do aluno: ");
                scanf("%s", nome);
                printf("Digite o novo gênero: ");
                scanf("%s", novoGenero);
                alterarGeneroAluno(nome, novoGenero);
                break;
            case 15:
                gerarRelatorioEstatistico();
                break;
            case 16:
                restaurarBackup();
                registrarLog("Restauração", "N/A");
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    gerarRelatorioAlunosInativos();

    enviarNotificacoesAutomaticas();

    exportarParaJSON();
    exportarParaXML();

    realizarBackup();
    realizarBackupIncremental();

    logout();

    gerarRelatorioFinal();

    return 0;
}
