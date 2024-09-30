#ifndef FUNCOES_H
#define FUNCOES_H

void boasVindas();
void mostrarMenu();
void capturarNome(char nome[]);
int contadorAlunos();
void exibirMensagemFinal(char nome[], int contador);
void salvarAlunoNoArquivo(char nome[], int contador);
void lerAlunosDoArquivo();
void excluirAlunoDoArquivo(char nome[]);
void atualizarAlunoNoArquivo(char nomeAntigo[], char nomeNovo[]);

#endif
