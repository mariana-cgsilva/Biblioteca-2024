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
    char nomeexemplares[10][100];
};

void CadastrarLivro(struct Livro veclivro[], int &qtd)
{
    if (qtd>100)
    {
        cout<<"Quantidade Excedida!!!";
    }
   
    else
    {
        cout<<"Digite o titulo do livro: ";
        cin.ignore();
        cin.getline(veclivro[qtd].titulo,100);
        cout<<"Digite o autor do livro: ";
        cin.getline(veclivro[qtd].autor,100);
        cout<<"Digite o numero de paginas: ";
        cin>>veclivro[qtd].numpaginas;
        cout<<"Digite o ano de publicação: ";
        cin>>veclivro[qtd].anopublicacao;
        cout<<"Digite o ID do livro: ";
        cin>>veclivro[qtd].idlivro;
        cout<<"Digite a quantidade do livro: ";
        cin>>veclivro[qtd].quantidade;
       
        qtd++;    
    }
}

void PrintLivros(struct Livro veclivro[], int i){
   
    cout<<"Titulo do livro: "<<veclivro[i].titulo <<endl;
    cout<<"Autor: "<<veclivro[i].autor <<endl;
    cout<<"Número de páginas: "<<veclivro[i].numpaginas <<endl;
    cout<<"Ano de publicação: "<<veclivro[i].anopublicacao <<endl;
    cout<<"ID do livro: "<<veclivro[i].idlivro <<endl;
    cout<<"Quantidade do livro: "<<veclivro[i].quantidade <<endl;
}

void ConsultarLivro(struct Livro veclivro[], int qtd)
{
    int opcao;
    cout<<"Consultar Livros:"<<endl;
    cout<<"1. Listar todos os livros cadastrados\n";
    cout<<"2. Buscar livro usando o ID\n";
    cout<<"3. Buscar livro por titulo\n";
    cout<<"Opção: ";
    cin>>opcao;
   
    if (opcao==1)
    {
        PrintLivros(veclivro,qtd);
    }
   
    else if (opcao==2)
    {
        int idbuscar;
        cout<<"Digite o ID do livro que deseja buscar: ";
        cin>>idbuscar;
        bool encontrado=false;
       
        for (int i=0; i<qtd; i++)
        {
            if (idbuscar==veclivro[i].idlivro)
            {  
                encontrado=true;
                cout<<"Livro encontrado!"<<endl;
                cout<<"Titulo do livro: "<<veclivro[i].titulo <<endl;
                cout<<"Autor: "<<veclivro[i].autor <<endl;
                cout<<"Número de páginas: "<<veclivro[i].numpaginas <<endl;
                cout<<"Ano de publicação: "<<veclivro[i].anopublicacao <<endl;
                cout<<"ID do livro: "<<veclivro[i].idlivro <<endl;
                cout<<"Quantidade do livro: "<<veclivro[i].quantidade <<endl;
            }
        }
           
        if(!encontrado)
        {
            cout<<"Esse ID não foi encontrado!!!";
        }

    }
   
    else if (opcao==3)
    {
        char titulobuscar[100];
        cout<<"Digite o titulo do livro que deseja buscar: ";
        cin.ignore();
        cin.getline(titulobuscar,100);
        
        for (int i=0; i<qtd; i++)
        {
            if (strcmp(veclivro[i].titulo, titulobuscar)==0)
            {
                cout<<"Livro encontrado!"<<endl;
                cout<<"Titulo do livro: "<<veclivro[i].titulo <<endl;
                cout<<"Autor: "<<veclivro[i].autor <<endl;
                cout<<"Número de páginas: "<<veclivro[i].numpaginas <<endl;
                cout<<"Ano de publicação: "<<veclivro[i].anopublicacao <<endl;
                cout<<"ID do livro: "<<veclivro[i].idlivro <<endl;
                cout<<"Quantidade do livro: "<<veclivro[i].quantidade <<endl;               
            }
           
            else
            {
                cout<<"Esse titulo não foi encontrado!!!";
            }
        }
    }
}

void EmprestimoLivro(struct Livro veclivro[], int &qtd)
{
    for (int i=0; i<qtd; i++)
    {
       if
    }
}

void DevolucaoLivro(struct Livro veclivro[], int &qtd)
{
    char nome[100];
    cout<<"Digite seu nome: ";
    cin.ignore();
    cin.getline(nome,100);
    
    for (int i=0; i<10; i++) 
    {
        if (strcmp(veclivro[i].nomeexemplares[i], nome) == 0) 
        {
            for (int j=i; j<9; j++) 
            { 
                strcpy(veclivro[i].nomeexemplares[j], veclivro[i].nomeexemplares[j + 1]);
            }
            veclivro[i].nomeexemplares[9][0] = '\0';
            
            char titulodevol[100];
            cout<<"Digite o titulo do livro que quer devolver: ";
            cin.ignore();
            cin.getline(titulodevol,100);
            
            for(int i=0; i<qtd; i++)
            {
                if(strcmp(veclivro[i].titulo, titulodevol) == 0)
                {
                    veclivro[i].quantidade += 1;
                    cout<<veclivro[i].titulo<<" devolvido com sucesso!\n";
                }
                else
                {
                    cout<<"Título não encontrado!!!\n";
                    break;
                }
            }
            
        } 
        else
        {
            cout<<"Nome não encontrado!!!\n";
            break;
        }
    }
}

int main()
{
    int maxlivro=100;
    struct Livro veclivro[maxlivro];
    int qtd=0;
   
    int opcao=0;
   
    while(opcao != 6)
    {
        cout<<"---------------------------"<<endl;
        cout<<"1. Cadastrar Livro"<<endl;
        cout<<"2. Consultar Livro"<<endl;
        cout<<"3. Emprestimo de Livro"<<endl;
        cout<<"4. Devolução de Livro"<<endl;
        cout<<"5. Remocao de Livro"<<endl;
        cout<<"6. Sair"<<endl;
        cout<<"---------------------------"<<endl;
        cout<<"Digite uma opcao: ";
        cin>>opcao;
        switch(opcao){
            case 1:
                CadastrarLivro(veclivro,qtd);
                break;
            case 2:
                ConsultarLivro(veclivro,qtd);
                break;
            case 3:
                EmprestimoLivro(veclivro,qtd);
                break;
            case 4:
                DevolucaoLivro(veclivro,qtd);
                break;
            case 5:
                break;
            case 6:
                cout<<"Programa finalizado.";
                break;
            default:
                cout<<"Número inválido.";
                break;
        }
    }
    return 0;
}
