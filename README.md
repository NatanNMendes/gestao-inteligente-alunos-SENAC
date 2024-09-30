# Projeto Sistema de Cadastro de Alunos

Este projeto foi desenvolvido em três rodadas como parte de um desafio. O sistema é capaz de gerenciar o cadastro de alunos, realizar backup dos dados, gerar relatórios, entre outras funcionalidades. As rodadas introduziram progressivamente novas funcionalidades e melhorias no código.

## Funcionalidades Gerais:
- **Cadastro de Alunos**: O sistema permite adicionar, excluir, atualizar e listar alunos.
- **Backup e Restauração**: Implementação de backup automático e restauração dos dados.
- **Relatórios e Estatísticas**: Geração de relatórios detalhados e gráficos simulados em ASCII, além de exportação de dados para CSV, JSON e XML.
- **Logs e Auditoria**: Logs detalhados de ações e auditoria das atividades do sistema.
- **Segurança e Permissões**: Autenticação de múltiplos usuários, com controle de permissões diferenciadas.
- **Interface Amigável**: Menus interativos, com suporte a múltiplos idiomas (Português e Inglês).

## Rodada 1 - Implementação Básica do Sistema de Cadastro de Alunos

A primeira rodada focou na criação do sistema básico de cadastro de alunos, com funcionalidades simples e modularização do código para facilitar futuras expansões.

### Funcionalidades Implementadas:
1. **Mensagem de Boas-vindas**: Exibe uma saudação ao iniciar o sistema.
2. **Cadastro de Alunos**: Permite ao usuário cadastrar o nome de um aluno.
3. **Contador de Alunos**: O sistema conta quantos alunos já foram cadastrados.
4. **Exibição de Nome**: Exibe o nome e o número do aluno cadastrado.
5. **Armazenamento em Arquivo**: Os dados são armazenados no arquivo `alunos.txt`, garantindo persistência.
6. **Modularização do Código**: O código foi dividido em funções separadas para captura de nome, exibição de mensagem e outras operações.

## Rodada 2 - Funcionalidades Avançadas e Modularização

A segunda rodada trouxe melhorias no código, como a implementação de backup automático, validações, pesquisa de alunos e exportação de dados.

### Funcionalidades Implementadas:
1. **Backup e Restauração**: Antes de excluir um aluno, o sistema faz um backup dos dados no arquivo `backup_alunos.txt`. A função de restauração permite recuperar os dados salvos.
2. **Pesquisa de Alunos**: O sistema permite buscar alunos pelo nome completo ou por parte do nome.
3. **Exclusão e Atualização de Alunos**: O usuário pode excluir ou atualizar os dados de um aluno.
4. **Exportação de Dados**: Os dados dos alunos podem ser exportados para um arquivo CSV.
5. **Contagem por Gênero**: O sistema permite registrar o gênero do aluno (masculino ou feminino) e exibe relatórios sobre a distribuição de gênero.
6. **Controle de Erros**: Implementação de validações para evitar entradas inválidas e garantir que os arquivos sejam manipulados corretamente.

## Rodada 3 - Segurança, Relatórios e Funcionalidades Extras

A terceira e última rodada do desafio focou em melhorias de segurança, adição de relatórios detalhados e auditoria das ações dos usuários.

### Funcionalidades Implementadas:
1. **Sistema de Login e Permissões**: Adicionada autenticação de usuários com permissões diferenciadas. Apenas administradores podem realizar certas ações, como excluir alunos.
2. **Logs e Auditoria**: Registro detalhado das ações dos usuários, como adição, exclusão e atualização de alunos, além de logs de erros.
3. **Backup Incremental**: Implementação de um backup incremental, que salva apenas as alterações realizadas desde o último backup.
4. **Exportação em JSON e XML**: Os dados dos alunos podem ser exportados para os formatos JSON e XML, além do CSV.
5. **Relatórios Estatísticos**: Geração de relatórios detalhados sobre a distribuição de alunos por gênero, incluindo gráficos simulados em ASCII.
6. **Interface Melhorada**: Suporte a múltiplos idiomas (Português e Inglês) e uma interface mais amigável.
7. **Notificações Automáticas**: Envio de notificações automáticas (simulado no código) aos alunos cadastrados.

## Requisitos do Sistema:
- Compilador C (GCC, Dev-C++, ou similar).
- Sistema Operacional: Multiplataforma (Windows, Linux, etc.).
