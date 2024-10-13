#include <iostream>
#include <cstring>
using namespace std;

struct Livro
{
    char titulo[100];
    char autor[100];
    int numpaginas;
    int anopublicacao;
    int idlivro;
    int quantidade;
    int emprestimo;
    char nomeexemplares[100][100];
};

void CadastrarLivro(struct Livro veclivro[], int &qtd)
{
    if (qtd >= 100)
    {
        cout << "\n----- Quantidade Excedida -----\n";
        return;
    }

    cout << "\n----- Cadastrar Livro -----\n";
    cout << "Digite o título do livro: ";
    cin.ignore();
    cin.getline(veclivro[qtd].titulo, 100);
    cout << "Digite o autor do livro: ";
    cin.getline(veclivro[qtd].autor, 100);
    cout << "Digite o número de páginas: ";
    cin >> veclivro[qtd].numpaginas;
    cout << "Digite o ano de publicação: ";
    cin >> veclivro[qtd].anopublicacao;
    cout << "Digite o ID do livro: ";
    cin >> veclivro[qtd].idlivro;
    cout << "Digite a quantidade do livro: ";
    cin >> veclivro[qtd].quantidade;

    veclivro[qtd].emprestimo = 0;
    qtd++;
    cout << "Livro cadastrado com sucesso!\n";
}

void PrintLivros(struct Livro veclivro[], int i)
{
    cout << "\n----- Livro " << i + 1 << " -----\n";
    cout << "Título do livro: " << veclivro[i].titulo << endl;
    cout << "Autor: " << veclivro[i].autor << endl;
    cout << "Número de páginas: " << veclivro[i].numpaginas << endl;
    cout << "Ano de publicação: " << veclivro[i].anopublicacao << endl;
    cout << "ID do livro: " << veclivro[i].idlivro << endl;
    cout << "Quantidade do livro: " << veclivro[i].quantidade << endl;

    if (veclivro[i].emprestimo > 0)
    {
        cout << "Emprestado a: ";
        for (int j = 0; j < veclivro[i].emprestimo; j++)
        {
            cout << veclivro[i].nomeexemplares[j];
            if (veclivro[i].emprestimo - 1 > j)
            {
                cout << ", ";
            }
        }
        cout << endl;
    }

    cout << "-------------------------\n";
}

void ConsultarLivro(struct Livro veclivro[], int qtd)
{
    int opcao;
    cout << "\n----- Consultar Livros -----\n";
    cout << "1. Listar todos os livros cadastrados\n";
    cout << "2. Buscar livro usando o ID\n";
    cout << "3. Buscar livro por título\n";
    cout << "Opção: ";
    cin >> opcao;

    if (opcao == 1)
    {
        for (int i = 0; i < qtd; i++)
        {
            PrintLivros(veclivro, i);
        }
    }
    else if (opcao == 2)
    {
        int idbuscar;
        cout << "Digite o ID do livro que deseja buscar: ";
        cin >> idbuscar;
        bool encontrado = false;

        for (int i = 0; i < qtd; i++)
        {
            if (idbuscar == veclivro[i].idlivro)
            {
                encontrado = true;
                PrintLivros(veclivro, i);
                break;
            }
        }

        if (!encontrado)
        {
            cout << "----- Esse ID não foi encontrado! -----\n";
        }
    }
    else if (opcao == 3)
    {
        char titulobuscar[100];
        cout << "Digite o título do livro que deseja buscar: ";
        cin.ignore();
        cin.getline(titulobuscar, 100);

        bool encontrado = false;
        for (int i = 0; i < qtd; i++)
        {
            if (strcmp(veclivro[i].titulo, titulobuscar) == 0)
            {
                encontrado = true;
                PrintLivros(veclivro, i);
                break;
            }
        }

        if (!encontrado)
        {
            cout << "----- Esse título não foi encontrado! -----\n";
        }
    }
}

void EmprestimoLivro(struct Livro veclivro[], int qtd)
{
    char nome[100];
    int idbuscar;

    cout << "\n----- Empréstimo de Livro -----\n";
    cout << "Digite seu nome: ";
    cin.ignore();
    cin.getline(nome, 100);

    cout << "Digite o ID do livro que deseja emprestar: ";
    cin >> idbuscar;

    for (int i = 0; i < qtd; i++)
    {
        if (veclivro[i].idlivro == idbuscar)
        {
            for (int j = 0; j < veclivro[i].emprestimo; j++)
            {
                if (strcmp(veclivro[i].nomeexemplares[j], nome) == 0)
                {
                    cout << "Você já pegou esse livro emprestado e não pode pegar outro exemplar.\n";
                    return;
                }
            }

            if (veclivro[i].quantidade > 0)
            {
                strcpy(veclivro[i].nomeexemplares[veclivro[i].emprestimo], nome);
                veclivro[i].quantidade--;
                veclivro[i].emprestimo++;
                cout << "Livro '" << veclivro[i].titulo << "' emprestado com sucesso para " << nome << endl;
            }
            else
            {
                cout << "----- Nenhum exemplar disponível. -----\n";
            }
            return;
        }
    }

    cout << "----- Livro não encontrado. -----\n";
}

void DevolucaoLivro(struct Livro veclivro[], int qtd)
{
    char nome[100];
    int iddevol;

    cout << "\n----- Devolução de Livro -----\n";
    cout << "Digite seu nome: ";
    cin.ignore();
    cin.getline(nome, 100);

    cout << "Digite o ID do livro que deseja devolver: ";
    cin >> iddevol;

    for (int i = 0; i < qtd; i++)
    {
        if (veclivro[i].idlivro == iddevol)
        {
            for (int j = 0; j < 10; j++)
            {
                if (strcmp(veclivro[i].nomeexemplares[j], nome) == 0)
                {
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

    cout << "----- Livro não encontrado. -----\n";
}

void RemocaoLivro(struct Livro veclivro[], int &qtd)
{
    if (qtd == 0)
    {
        cout << "----- Não há livros cadastrados para remover. -----\n";
        return;
    }

    int idremover;
    cout << "Digite o ID do livro que deseja remover: ";
    cin >> idremover;

    bool encontrado = false;
    for (int i = 0; i < qtd; i++)
    {
        if (veclivro[i].idlivro == idremover)
        {
            encontrado = true;

            for (int j = i; j < qtd - 1; j++)
            {
                veclivro[j] = veclivro[j + 1];
            }
            qtd--;
            cout << "----- Livro removido com sucesso. -----\n";
            break;
        }
    }

    if (!encontrado)
    {
        cout << "----- ID do livro não encontrado. -----\n";
    }
}

int main()
{
    int maxlivro = 100;
    struct Livro veclivro[maxlivro];
    int qtd = 0;

    int opcao = 0;

    while (opcao != 6)
    {
        cout << "\n----- Sistema de Gerenciamento de Livros -----\n";
        cout << "1. Cadastrar Livro\n";
        cout << "2. Consultar Livro\n";
        cout << "3. Empréstimo de Livro\n";
        cout << "4. Devolução de Livro\n";
        cout << "5. Remoção de Livro\n";
        cout << "6. Sair\n";
        cout << "Digite uma opção: ";
        cin >> opcao;

        switch (opcao)
        {
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
