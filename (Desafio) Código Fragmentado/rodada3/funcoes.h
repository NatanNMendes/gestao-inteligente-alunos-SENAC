#ifndef FUNCOES_H
#define FUNCOES_H

void boasVindas();
void capturarNome(char nome[]);
void capturarGenero(char genero[]);
int validarNome(char nome[]);
void exibirMensagemFinal(char nome[], int contador);
void salvarAlunoNoArquivo(char nome[], char genero[], int contador);
void excluirAlunoDoArquivo(char nome[]);
void atualizarAlunoNoArquivo(char nomeAntigo[], char nomeNovo[]);
void listarAlunos();
int contadorAlunos();
void buscarAlunoPorParteNome(char parte[]);
void exportarParaCSV();
void alterarGeneroAluno(char nome[], char novoGenero[]);
void gerarRelatorioCompleto();
int verificarSenha();
void mostrarMenuMelhorado();
int lerOpcao();
void registrarLog(char operacao[], char nome[]);
int login(char username[], char password[]);
void gerarRelatorioEstatistico();
void realizarBackup();
void restaurarBackup();
int verificarNivelPermissao(char usuario[]);
int validarSenhaForte(char senha[]);
void gerarRelatorioPorData(char data[]);
void registrarLogErro(char erro[]);
void realizarBackupIncremental();
void enviarRelatorioPorEmail(char email[], char conteudo[]);
void exportarParaJSON();
void exportarParaXML();
void gerarRelatorioAlunosInativos();
void enviarNotificacoesAutomaticas();
void definirIdioma(int opcao);
void exibirMensagemBoasVindas();
void exibirEstatisticas();
char* buscarAlunoCache(int id);
void registrarAuditoria(char usuario[], char acao[]);
void logout();
void gerarRelatorioFinal();
int pesquisarAluno(char nome[]);
void contarAlunosPorGenero();
void ordenarAlunos();
void excluirAlunosPorGenero(char genero[]);
void limparArquivoSeVazio();
int contarTotalAlunos();

#endif
