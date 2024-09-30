#include <stdio.h>
#include <string.h>
#include "funcoes.h"

void mostrarMenu() {
    printf("\n--- Menu do Sistema ---\n");
    printf("1 - Adicionar aluno\n");
    printf("2 - Listar todos os alunos\n");
    printf("3 - Excluir aluno\n");
    printf("4 - Atualizar nome de aluno\n");
    printf("5 - Restaurar backup\n");
    printf("6 - Buscar aluno por nome\n");
    printf("7 - Contar alunos por gênero\n");
    printf("8 - Ordenar alunos\n");
    printf("9 - Excluir alunos por gênero\n");
    printf("10 - Contar total de alunos\n");
    printf("11 - Gerar relatório completo\n");
    printf("12 - Buscar aluno por parte do nome\n");
    printf("13 - Exportar dados para CSV\n");
    printf("14 - Alterar gênero de aluno\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
}

void boasVindas() {
    printf("\n****************************\n");
    printf("** Bem-vindo ao projeto! **\n");
    printf("****************************\n\n");
}

void exibirMensagemFinal(char nome[], int contador) {
    printf("\n****************************\n");
    printf("Olá, %s! Você é o aluno número %d.\n", nome, contador);
    printf("****************************\n\n");
}

int lerOpcao() {
    int opcao;
    if (scanf("%d", &opcao) != 1) {
        while (getchar() != '\n'); 
        return -1; 
    }
    return opcao;
}

void capturarNome(char nome[]) {
	do {
		printf("Digite seu nome (mínimo 2 caracteres): ");
		scanf("%49s", nome);  // Protegendo buffer overflow
	} while (strlen(nome) < 2);
}

int contadorAlunos() {
    FILE *arquivo = fopen("alunos.txt", "r");
    char linha[100];
    int contador = 0;
    
    if (arquivo == NULL) {
        return 0;
    }
    
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        contador++;
    }
    fclose(arquivo);
    return contador;
}


void capturarGenero(char genero[]) {
    printf("Digite o gênero do aluno (Masculino/Feminino): ");
    scanf("%s", genero);
}

void salvarAlunoNoArquivo(char nome[], char genero[], int contador) {
    FILE *arquivo = fopen("alunos.txt", "a");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para gravação");
        return;
    }
    if (fprintf(arquivo, "Aluno %d: %s (%s)\n", contador, nome, genero) < 0) {
        perror("Erro ao escrever no arquivo");
    }
    fclose(arquivo);
}

void lerAlunosDoArquivo() {
    FILE *arquivo = fopen("alunos.txt", "r");
    
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para leitura");
        return;
    }
    
    char linha[100];
    
    printf("\nAlunos cadastrados:\n");
    
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }
    
    if (fclose(arquivo) != 0) {
        perror("Erro ao fechar o arquivo");
    }
}

void excluirAlunoDoArquivo(char nome[]) {
	FILE *arquivo = fopen("alunos.txt", "r");
	FILE *temp = fopen("temp.txt", "w");
	char linha[100];
	int encontrado = 0;
	if (arquivo == NULL || temp == NULL) {
		perror("Erro ao abrir arquivo");
		return;
	}
	while (fgets(linha, sizeof(linha), arquivo) != NULL) {
		if (strstr(linha, nome) == NULL) {
			fputs(linha, temp);
		} else {
			encontrado = 1;
		}
	}
	
	fclose(arquivo);
	fclose(temp);
	remove("alunos.txt");
	rename("temp.txt", "alunos.txt");
	if (encontrado) {
		printf("Aluno %s removido com sucesso.\n", nome);
	} else {
		printf("Aluno %s não encontrado.\n", nome);
	}
}

void atualizarAlunoNoArquivo(char nomeAntigo[], char nomeNovo[]) {
    if (!pesquisarAluno(nomeAntigo)) {
        printf("Aluno %s não encontrado para atualizar.\n", nomeAntigo);
        return;
    }
    FILE *arquivo = fopen("alunos.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    char linha[100];
    int encontrado = 0;
    if (arquivo == NULL || temp == NULL) {
        perror("Erro ao abrir arquivo");
        return;
    }
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (strstr(linha, nomeAntigo) != NULL) {
        fprintf(temp, "Aluno %d: %s\n", contadorAlunos(), nomeNovo);
        encontrado = 1;
        } else {
            fputs(linha, temp);
        }
    }
    fclose(arquivo);
    fclose(temp);
    remove("alunos.txt");
    rename("temp.txt", "alunos.txt");
    if (encontrado) {
        printf("Aluno %s atualizado com sucesso.\n", nomeAntigo);
    }
}

void criarBackup() {
    FILE *arquivo = fopen("alunos.txt", "r");
    FILE *backup = fopen("backup_alunos.txt", "w");
    char linha[100];
    if (arquivo == NULL || backup == NULL) {
        perror("Erro ao criar o backup");
        return;
    }
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        fputs(linha, backup);
    }
    fclose(arquivo);
    fclose(backup);
    printf("Backup criado com sucesso.\n");
}

void restaurarBackup() {
    FILE *backup = fopen("backup_alunos.txt", "r");
    FILE *arquivo = fopen("alunos.txt", "w");
    char linha[100];
    if (backup == NULL || arquivo == NULL) {
        perror("Erro ao restaurar o backup");
        return;
    }
    while (fgets(linha, sizeof(linha), backup) != NULL) {
        fputs(linha, arquivo);
    }
    fclose(backup);
    fclose(arquivo);
    printf("Backup restaurado com sucesso.\n");
}

int pesquisarAluno(char nome[]) {
    FILE *arquivo = fopen("alunos.txt", "r");
    char linha[100];
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 0;
    }
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (strstr(linha, nome) != NULL) {
            fclose(arquivo);
            return 1;
        }
    }
    fclose(arquivo);
    return 0;
}

void contarAlunosPorGenero() {
    FILE *arquivo = fopen("alunos.txt", "r");
    char linha[100];
    int masc = 0, fem = 0;
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (strstr(linha, "Masculino") != NULL) {
            masc++;
        } else if (strstr(linha, "Feminino") != NULL) {
            fem++;
        }
    }
    fclose(arquivo);
    printf("Alunos masculinos: %d\n", masc);
    printf("Alunas femininas: %d\n", fem);
}

void ordenarAlunos() {
    FILE *arquivo = fopen("alunos.txt", "r");
    char alunos[100][100];
    char linha[100];
    int i = 0, j;

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        strcpy(alunos[i], linha);
        i++;
    }
    fclose(arquivo);

    for (int k = 0; k < i - 1; k++) {
        for (int l = k + 1; l < i; l++) {
            if (strcmp(alunos[k], alunos[l]) > 0) {
                char temp[100];
                strcpy(temp, alunos[k]);
                strcpy(alunos[k], alunos[l]);
                strcpy(alunos[l], temp);
            }
        }
    }

    FILE *temp = fopen("temp.txt", "w");
    printf("\nAlunos ordenados:\n");
    for (j = 0; j < i; j++) {
        printf("%s", alunos[j]);
        fprintf(temp, "%s", alunos[j]);
    }
    fclose(temp);
    remove("alunos.txt");
    rename("temp.txt", "alunos.txt");
}

int validarNome(char nome[]) {
    if (strlen(nome) == 0) {
    printf("Nome não pode estar vazio. Tente novamente.\n");
        return 0;
    }
    return 1;
}

void excluirAlunosPorGenero(char genero[]) {
    FILE *arquivo = fopen("alunos.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    char linha[100];
    if (arquivo == NULL || temp == NULL) {
        perror("Erro ao abrir arquivo");
        return;
    }
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (strstr(linha, genero) == NULL) {
            fputs(linha, temp);
        }
    }
    fclose(arquivo);
    fclose(temp);
    remove("alunos.txt");
    rename("temp.txt", "alunos.txt");
    printf("Alunos do gênero %s excluídos com sucesso.\n", genero);
}

void limparArquivoSeVazio() {
    FILE *arquivo = fopen("alunos.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    fseek(arquivo, 0, SEEK_END);
    if (ftell(arquivo) == 0) { 
        fclose(arquivo);
        remove("alunos.txt");
        printf("Arquivo 'alunos.txt' removido, pois está vazio.\n");
    } else {
        fclose(arquivo);
    }
}

int contarTotalAlunos() {
    FILE *arquivo = fopen("alunos.txt", "r");
    char linha[100];
    int contador = 0;
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 0;
    }
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        contador++;
    }
    fclose(arquivo);
    return contador;
}

int verificarBackup() {
    FILE *backup = fopen("backup_alunos.txt", "r");
    if (backup != NULL) {
        fclose(backup);
        return 1; 
    }
    return 0; 
}

void registrarLog(char acao[], char detalhes[]) {
    FILE *log = fopen("log_sistema.txt", "a");
    if (log == NULL) {
        perror("Erro ao abrir o log");
        return;
    }
    fprintf(log, "Ação: %s - Detalhes: %s\n", acao, detalhes);
    fclose(log);
}

void gerarRelatorioCompleto() {
    FILE *arquivo = fopen("alunos.txt", "r");
    FILE *relatorio = fopen("relatorio_completo.txt", "w");
    char linha[100];
    if (arquivo == NULL || relatorio == NULL) {
        perror("Erro ao abrir arquivo");
        return;
    }
    fprintf(relatorio, "Relatório Completo dos Alunos\n\n");
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        fputs(linha, relatorio);
    }
    fclose(arquivo);
    fclose(relatorio);
    printf("Relatório completo gerado com sucesso!\n");
}

void buscarAlunoPorParteNome(char parte[]) {
    FILE *arquivo = fopen("alunos.txt", "r");
    char linha[100];
    int encontrou = 0;
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    printf("Resultados da busca:\n");
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (strstr(linha, parte) != NULL) {
            printf("%s", linha);
            encontrou = 1;
        }
    }
    if (!encontrou) {
        printf("Nenhum aluno encontrado com a parte '%s' no nome.\n", parte);
    }
    fclose(arquivo);
}

void exportarParaCSV() {
    FILE *arquivo = fopen("alunos.txt", "r");
    FILE *csv = fopen("alunos_exportados.csv", "w");
    char linha[100];
    if (arquivo == NULL || csv == NULL) {
        perror("Erro ao abrir arquivo");
        return;
    }
    fprintf(csv, "Nome, Gênero\n");
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char nome[50], genero[20];
        sscanf(linha, "%[^,], %s", nome, genero);
        fprintf(csv, "%s, %s\n", nome, genero);
    }
    fclose(arquivo);
    fclose(csv);
    printf("Dados exportados para alunos_exportados.csv com sucesso!\n");
}

void alterarGeneroAluno(char nome[], char novoGenero[]) {
    FILE *arquivo = fopen("alunos.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    char linha[100];
    int alterado = 0;
    if (arquivo == NULL || temp == NULL) {
        perror("Erro ao abrir arquivo");
        return;
    }
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char nomeAluno[50], genero[20];
        sscanf(linha, "%[^,], %s", nomeAluno, genero);
        if (strcmp(nomeAluno, nome) == 0) {
            fprintf(temp, "%s, %s\n", nomeAluno, novoGenero);
        alterado = 1;
        } else {
            fputs(linha, temp);
        }
    }
    fclose(arquivo);
    fclose(temp);
    remove("alunos.txt");
    rename("temp.txt", "alunos.txt");
    if (alterado) {
        printf("Gênero do aluno '%s' alterado para '%s'.\n",
        nome, novoGenero);
    } else {
        printf("Aluno '%s' não encontrado.\n", nome);
    }
}

int verificarSenha() {
    char senha[20];
    printf("Digite a senha de administrador: ");
    scanf("%s", senha);
    if (strcmp(senha, "admin123") == 0) {
        return 1;
    } else {
        printf("Senha incorreta! Acesso negado.\n");
        return 0;
    }
}