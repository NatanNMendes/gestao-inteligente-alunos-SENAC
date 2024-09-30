#include <stdio.h>
#include <string.h>
#include "funcoes.h"

void mostrarMenu() {
    printf("\n============================\n");
    printf(" MENU PRINCIPAL \n");
    printf("============================\n");
    printf("1 - Cadastrar novo aluno\n");
    printf("2 - Listar alunos\n");
    printf("3 - Excluir aluno\n");
    printf("4 - Atualizar aluno\n");
    printf("0 - Sair\n");
    printf("============================\n");
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


void salvarAlunoNoArquivo(char nome[], int contador) {

    FILE *arquivo = fopen("alunos.txt", "a");
    
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para gravação");
        return;
    }
    
    if (fprintf(arquivo, "Aluno %d: %s\n", contador, nome) < 0) {
        perror("Erro ao escrever no arquivo");
    }
    
    if (fclose(arquivo) != 0) {
        perror("Erro ao fechar o arquivo");
    }
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
            fprintf(temp, "Aluno: %s\n", nomeNovo);
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
        printf("Aluno %s atualizado com sucesso para %s.\n", nomeAntigo, nomeNovo);
    } else {
        printf("Aluno %s não encontrado.\n", nomeAntigo);
    }
}
