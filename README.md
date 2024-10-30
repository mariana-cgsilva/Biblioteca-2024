# Biblioteca-2024

# **Sistema de Gerenciamento de Biblioteca**

## **Linguagem**
O projeto foi implementado em **linguagem C**, com exceção das operações de **strings** e **entrada/saída de dados**, que utilizam as funções `std::cin` e `std::cout`.

## **Objetivo**
Este projeto visa aplicar os conceitos ensinados em sala de aula, como **comandos, funções e structs**, no desenvolvimento de um sistema de gerenciamento de biblioteca. O projeto é realizado em **grupos de até 5 alunos**, com foco na **simulação básica do funcionamento de uma biblioteca**.

## **Descrição**
O sistema é um programa **interativo em console** que permite o **cadastro, busca, empréstimo e devolução de livros**. Ele organiza as informações dos livros e dos usuários utilizando `structs` e oferece funcionalidades essenciais para o gerenciamento de uma biblioteca, com uma interface simples e funcional.

## **Requisitos Mínimos**

1. **Cadastro de livros**: 
   - O sistema deve permitir o cadastro de novos livros com as seguintes informações:
     - **Título**
     - **Autor**
     - **Número de páginas**
     - **Ano de publicação**
     - **Código único (ID)**
     - **Quantidade disponível (estoque)**
     - **Nomes das pessoas que emprestaram exemplares**

2. **Consulta de livros**: 
   - Deve ser possível **listar todos os livros cadastrados** ou **buscar um livro específico** pelo **código (ID)** ou **título**.

3. **Empréstimo de livros**: 
   - O sistema permite que um livro seja emprestado e atualiza a quantidade disponível. 
   - Caso a quantidade chegue a zero, o livro não poderá ser emprestado novamente até ser devolvido. 
   - O nome da pessoa que emprestou o livro deverá constar na lista do `struct Livro`.

4. **Devolução de livros**: 
   - Após a devolução, a quantidade disponível do livro deverá ser atualizada, e o nome da pessoa que está devolvendo deverá ser removido da lista do `struct Livro`.

5. **Remoção de livros**: 
   - Deve ser possível remover um livro do cadastro do sistema.

6. **Menu interativo**: 
   - Implementar um **menu no terminal** que permita ao usuário navegar entre as opções de **cadastro, consulta, empréstimo, devolução e remoção de livros**.

## **Estrutura e Funcionalidades**
Este sistema foi desenvolvido para proporcionar uma **experiência completa de gerenciamento de biblioteca diretamente no terminal**, com uma interface interativa que permite ao usuário navegar facilmente entre as principais funcionalidades.
