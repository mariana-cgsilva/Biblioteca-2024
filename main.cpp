/*
Integrantes do grupo:
1. EDUARDA LUIZA PINHEIRO NEPOMUCENO 
2. GEOVANA DA SILVA BARBOSA - 24015889
3. MARIANA COSTA GONÇALVES DA SILVA - 24018699
4. SOFIA DE ABREU GUIMARÃES - 24013553
*/

#include <iostream>
#include <cstring>
#include <limits>
using namespace std;

// Estrutura para representar um livro
struct Livro {
    char titulo[100];
    char autor[100];
    int numpaginas;
    int anopublicacao;
    int idlivro;
    int quantidade;
    int emprestimo; // Número de exemplares emprestados
    char nomeexemplares[100][100]; // Nomes das pessoas que pegaram o livro emprestado
};

// Função para cadastrar um novo livro
void CadastrarLivro(struct Livro veclivro[], int &qtd) {
    // Verifica se o limite de livros foi atingido
    if (qtd >= 100) {
        cout << "\n----- Quantidade Excedida -----\n";
        return;
    }

    cout << "\n----- Cadastrar Livro -----\n";
    
    // Entrada do título do livro e verificação de campo vazio
    cout << "Digite o título do livro: ";
    cin.ignore();
    cin.getline(veclivro[qtd].titulo, 100);
    while (strlen(veclivro[qtd].titulo) == 0) {
        cout << "Erro: O título não pode ser vazio! Digite novamente: ";
        cin.getline(veclivro[qtd].titulo, 100);
    }

    // Entrada do autor do livro e verificação de campo vazio
    cout << "Digite o autor do livro: ";
    cin.getline(veclivro[qtd].autor, 100);
    while (strlen(veclivro[qtd].autor) == 0) {
        cout << "Erro: O autor não pode ser vazio! Digite novamente: ";
        cin.getline(veclivro[qtd].autor, 100);
    }

    // Entrada e validação do número de páginas (limite 1 a 10000)
    cout << "Digite o número de páginas: ";
    while (!(cin >> veclivro[qtd].numpaginas) || veclivro[qtd].numpaginas <= 0 || veclivro[qtd].numpaginas > 10000) {
        cout << "Erro: Digite um número válido para páginas (1 a 10000)!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Entrada e validação do ano de publicação (entre 1000 e 2024)
    cout << "Digite o ano de publicação (entre 1000 e 2024): ";
    while (!(cin >> veclivro[qtd].anopublicacao) || veclivro[qtd].anopublicacao < 1000 || veclivro[qtd].anopublicacao > 2024) {
        cout << "Erro: Digite um ano de publicação válido (entre 1000 e 2024)!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Entrada do ID do livro e verificação de unicidade
    int tempId;
    cout << "Digite o ID do livro: ";
    while (true) {
        while (!(cin >> tempId) || tempId <= 0) {
            cout << "Erro: Digite um ID válido!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Verifica se o ID já existe
        bool idExistente = false;
        for (int i = 0; i < qtd; i++) {
            if (veclivro[i].idlivro == tempId) {
                idExistente = true;
                cout << "Erro: Esse ID já está em uso! Digite um ID único.\n";
                break;
            }
        }

        if (!idExistente) {
            veclivro[qtd].idlivro = tempId;
            break;
        }
    }

    // Entrada e validação da quantidade de exemplares (entre 1 e 1000)
    cout << "Digite a quantidade do livro (máximo 1000): ";
    while (!(cin >> veclivro[qtd].quantidade) || veclivro[qtd].quantidade < 1 || veclivro[qtd].quantidade > 1000) {
        cout << "Erro: Digite uma quantidade válida (entre 1 e 1000)!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Inicializa a quantidade de empréstimos e incrementa o contador de livros cadastrados
    veclivro[qtd].emprestimo = 0;
    qtd++;
    cout << "Livro cadastrado com sucesso!\n";
}

// Função para exibir as informações de um livro
void PrintLivros(struct Livro veclivro[], int i) {
    cout << "\n----- Livro " << i + 1 << " -----\n";
    cout << "Título do livro: " << veclivro[i].titulo << endl;
    cout << "Autor: " << veclivro[i].autor << endl;
    cout << "Número de páginas: " << veclivro[i].numpaginas << endl;
    cout << "Ano de publicação: " << veclivro[i].anopublicacao << endl;
    cout << "ID do livro: " << veclivro[i].idlivro << endl;
    cout << "Quantidade do livro: " << veclivro[i].quantidade << endl;

    // Exibe a lista de pessoas que pegaram o livro emprestado
    if (veclivro[i].emprestimo > 0) {
        cout << "Emprestado a: ";
        for (int j = 0; j < veclivro[i].emprestimo; j++) {
            cout << veclivro[i].nomeexemplares[j];
            if (veclivro[i].emprestimo - 1 > j) {
                cout << ", ";
            }
        }
        cout << endl;
    }

    cout << "-------------------------\n";
}

// Função para consultar um livro pelo ID ou título ou listar todos os livros
void ConsultarLivro(struct Livro veclivro[], int qtd) {
    if (qtd == 0) {
        cout << "----- Nenhum livro cadastrado para consulta. -----\n";
        return;
    }

    int opcao;
    cout << "\n----- Consultar Livros -----\n";
    cout << "1. Listar todos os livros cadastrados\n";
    cout << "2. Buscar livro usando o ID\n";
    cout << "3. Buscar livro por título\n";
    cout << "Opção: ";
    while (!(cin >> opcao) || opcao < 1 || opcao > 3) {
        cout << "Erro: Escolha uma opção válida (1-3)!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Lista todos os livros
    if (opcao == 1) {
        for (int i = 0; i < qtd; i++) {
            PrintLivros(veclivro, i);
        }
    } else if (opcao == 2) { // Busca por ID
        int idbuscar;
        cout << "Digite o ID do livro que deseja buscar: ";
        while (!(cin >> idbuscar)) {
            cout << "Erro: Digite um ID válido!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        bool encontrado = false;
        for (int i = 0; i < qtd; i++) {
            if (veclivro[i].idlivro == idbuscar) {
                encontrado = true;
                PrintLivros(veclivro, i);
                break;
            }
        }

        if (!encontrado) {
            cout << "----- Esse ID não foi encontrado! -----\n";
        }
    } else if (opcao == 3) { // Busca por título
        char titulobuscar[100];
        cout << "Digite o título do livro que deseja buscar: ";
        cin.ignore();
        cin.getline(titulobuscar, 100);

        bool encontrado = false;
        for (int i = 0; i < qtd; i++) {
            if (strcmp(veclivro[i].titulo, titulobuscar) == 0) {
                encontrado = true;
                PrintLivros(veclivro, i);
                break;
            }
        }

        if (!encontrado) {
            cout << "----- Esse título não foi encontrado! -----\n";
        }
    }
}

// Função para realizar o empréstimo de um livro
void EmprestimoLivro(struct Livro veclivro[], int qtd) {
    if (qtd == 0) {
        cout << "----- Nenhum livro cadastrado para empréstimo. -----\n";
        return;
    }

    char nome[100];
    int idbuscar;

    cout << "\n----- Empréstimo de Livro -----\n";
    cout << "Digite seu nome: ";
    cin.ignore();
    cin.getline(nome, 100);
    while (strlen(nome) == 0) {
        cout << "Erro: O nome não pode ser vazio! Digite novamente: ";
        cin.getline(nome, 100);
    }

    cout << "Digite o ID do livro que deseja emprestar: ";
    while (!(cin >> idbuscar)) {
        cout << "Erro: Digite um ID válido!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Busca o livro pelo ID e verifica a disponibilidade
    for (int i = 0; i < qtd; i++) {
        if (veclivro[i].idlivro == idbuscar) {
            for (int j = 0; j < veclivro[i].emprestimo; j++) {
                if (strcmp(veclivro[i].nomeexemplares[j], nome) == 0) {
                    cout << "Você já pegou esse livro emprestado e não pode pegar outro exemplar.\n";
                    return;
                }
            }

            if (veclivro[i].quantidade > 0) {
                strcpy(veclivro[i].nomeexemplares[veclivro[i].emprestimo], nome);
                veclivro[i].quantidade--;
                veclivro[i].emprestimo++;
                cout << "Livro '" << veclivro[i].titulo << "' emprestado com sucesso para " << nome << endl;
            } else {
                cout << "----- Nenhum exemplar disponível. -----\n";
            }
            return;
        }
    }

    cout << "----- Livro não encontrado. -----\n";
}

// Função para realizar a devolução de um livro emprestado
void DevolucaoLivro(struct Livro veclivro[], int qtd) {
    if (qtd == 0) {
        cout << "----- Nenhum livro cadastrado para devolução. -----\n";
        return;
    }

    char nome[100];
    int iddevol;

    cout << "\n----- Devolução de Livro -----\n";
    cout << "Digite seu nome: ";
    cin.ignore();
    cin.getline(nome, 100);

    cout << "Digite o ID do livro que deseja devolver: ";
    while (!(cin >> iddevol)) {
        cout << "Erro: Digite um ID válido!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    bool encontrado = false;
    for (int i = 0; i < qtd; i++) {
        if (veclivro[i].idlivro == iddevol) {
            encontrado = true;
            for (int j = 0; j < veclivro[i].emprestimo; j++) {
                if (strcmp(veclivro[i].nomeexemplares[j], nome) == 0) {
                    strcpy(veclivro[i].nomeexemplares[j], "");
                    veclivro[i].quantidade++;
                    cout << "Livro '" << veclivro[i].titulo << "' devolvido com sucesso.\n";
                    return;
                }
            }
            cout << "----- Erro: Seu nome não consta na lista de empréstimo para o livro '" << veclivro[i].titulo << "'. -----\n";
            return;
        }
    }

    if (!encontrado) {
        cout << "----- Livro não encontrado. -----\n";
    }
}

// Função para remover um livro do sistema
void RemocaoLivro(struct Livro veclivro[], int &qtd) {
    if (qtd == 0) {
        cout << "----- Não há livros cadastrados para remover. -----\n";
        return;
    }

    int idremover;
    cout << "Digite o ID do livro que deseja remover: ";
    while (!(cin >> idremover)) {
        cout << "Erro: Digite um ID válido!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    bool encontrado = false;
    for (int i = 0; i < qtd; i++) {
        if (veclivro[i].idlivro == idremover) {
            encontrado = true;

            // Remove o livro e ajusta a lista
            for (int j = i; j < qtd - 1; j++) {
                veclivro[j] = veclivro[j + 1];
            }
            qtd--;
            cout << "----- Livro removido com sucesso. -----\n";
            break;
        }
    }

    if (!encontrado) {
        cout << "----- ID do livro não encontrado. -----\n";
    }
}

// Função principal que exibe o menu e chama as funções de acordo com a escolha do usuário
int main() {
    int maxlivro = 100;
    struct Livro veclivro[maxlivro];
    int qtd = 0;

    int opcao = 0;

    while (opcao != 6) {
        cout << "\n----- Sistema de Gerenciamento de Livros -----\n";
        cout << "1. Cadastrar Livro\n";
        cout << "2. Consultar Livro\n";
        cout << "3. Empréstimo de Livro\n";
        cout << "4. Devolução de Livro\n";
        cout << "5. Remoção de Livro\n";
        cout << "6. Sair\n";
        cout << "Digite uma opção: ";
        while (!(cin >> opcao) || opcao < 1 || opcao > 6) {
            cout << "Erro: Escolha uma opção válida (1-6)!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (opcao) {
            case 1:
                CadastrarLivro(veclivro, qtd);
                break;
            case 2:
                ConsultarLivro(veclivro, qtd);
                break;
            case 3:
                EmprestimoLivro(veclivro, qtd);
                break;
            case 4:
                DevolucaoLivro(veclivro, qtd);
                break;
            case 5:
                RemocaoLivro(veclivro, qtd);
                break;
            case 6:
                cout << "----- Saindo do sistema... -----\n";
                break;
            default:
                cout << "----- Opção inválida! -----\n";
                break;
        }
    }

    return 0;
}