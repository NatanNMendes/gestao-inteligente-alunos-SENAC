#ifndef FUNCOES_H
#define FUNCOES_H

int lerOpcao();
void boasVindas();
void mostrarMenu();
void capturarNome(char nome[]);
int contadorAlunos();
void exibirMensagemFinal(char nome[], int contador);
void capturarGenero(char genero[]);
void salvarAlunoNoArquivo(char nome[], char genero[], int contador);
void lerAlunosDoArquivo();
void excluirAlunoDoArquivo(char nome[]);
void atualizarAlunoNoArquivo(char nomeAntigo[], char nomeNovo[]);
void criarBackup();
void restaurarBackup();
int pesquisarAluno(char nome[]);
void contarAlunosPorGenero();
void ordenarAlunos();
int validarNome(char nome[]);
void excluirAlunosPorGenero(char genero[]);
void limparArquivoSeVazio();
int contarTotalAlunos();
int verificarBackup();
void registrarLog(char acao[], char detalhes[]);
void gerarRelatorioCompleto();
void buscarAlunoPorParteNome(char parte[]);
void exportarParaCSV();
void alterarGeneroAluno(char nome[], char novoGenero[]);
int verificarSenha();

#endif
