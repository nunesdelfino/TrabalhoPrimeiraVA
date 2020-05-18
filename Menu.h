#include <stdio.h>
#include <stdlib.h>

#ifndef MENU_H
#define MENU_H

void Menu(int *Opcao){

    printf("\n\n#################### MENU ####################\n");
    printf("1 - Criar aluno\n");
    printf("2 - Excluir Aluno\n");
    printf("3 - Buscar\n");
    printf("4 - Imprimir Lista de Alunos\n");
    printf("5 - Atualizar Dados do Aluno\n");
    printf("6 - Mostrar total de alunos cadastrados\n");
    printf("\n");
    printf("0 - Sair\n");
    printf("\n");
    printf("Digite a opção desejada: ");
    scanf("%i", &*Opcao);

}

void MenuEditar(int *Opcao){

    printf("\n\n#################### MENU EDITAR ####################\n");
    printf("1 - Editar Matricula do Aluno\n");
    printf("2 - Editar Nome do Aluno\n");
    printf("3 - Editar Email do Aluno\n");
    printf("4 - Editar Curso do Aluno\n");
    printf("5 - Editar Disciplina do Aluno\n");
    printf("6 - Editar Telefone do Aluno\n");
    printf("7 - Adicionar uma Disciplina a um Aluno\n");
    printf("8 - Adicionar um Telefone a um Aluno\n");
    printf("\n");
    printf("0 - Sair\n");
    printf("\n");
    printf("Digite a opção desejada: ");
    scanf("%i", &*Opcao);

}

void MenuExcluir(int *Opcao){

    printf("\n\n#################### MENU EXCLUIR ####################\n");
    printf("1 - Excluir pela Matricula do Aluno\n");
    printf("2 - Excluir pelo Nome do Aluno\n");
    printf("3 - Excluir pelo Email do Aluno\n");
    printf("\n");
    printf("0 - Sair\n");
    printf("\n");
    printf("Digite a opção desejada: ");
    scanf("%i", &*Opcao);

}

void MenuBuscar(int *Opcao){

    printf("\n\n#################### MENU BUSCAR ####################\n");
    printf("1 - Buscar pela Matricula do Aluno\n");
    printf("2 - Buscar pelo Nome do Aluno\n");
    printf("3 - Buscar pelo Email do Aluno\n");
    printf("4 - Buscar pelo Curso\n");
    printf("\n");
    printf("0 - Sair\n");
    printf("\n");
    printf("Digite a opção desejada: ");
    scanf("%i", &*Opcao);
}

#endif
