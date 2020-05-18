// Elabore uma programa em C para implementar uma Agenda Eletrônica dos alunos da UEG.
// Serão armazenados os seguintes dados de cada aluno:
    // Matricula
    // Nome
    // Telefone
    // E-mail
    // Curso
    // Disciplinas
    // Outros que acharem necessários.
// A Agenda deverá ser implementada através de uma Lista Encadeada.
// Como um aluno pode ter vários telefones e disciplinas
// estes campos também devem ser implementados como uma Lista cada.
// Colocar todas as funções de manipulação da lista:
    // criar -> OK
    // incluir  -> OK
    // excluir -> OK
    // buscar -> OK
    // listar -> OK
// Trabalhar através de menu.

#include <stdio.h>
#include <stdlib.h>
#include "Agenda.h"
#include "Funcoes.h"
#include "Menu.h"

int main(){
    Contato *PonteiroAgenda;
    Contato *AuxiliarContato = NULL;

    PonteiroAgenda = (Contato *) malloc(sizeof(Contato));
    
    int Opcao;

    do{
      if(PonteiroAgenda != NULL){
        AuxiliarContato = PonteiroAgenda;
      }

      Menu(&Opcao);

      switch (Opcao) {
        case 0:
          printf("Saindo...\n");
          break;
        case 1:
          Inserir(&PonteiroAgenda);
          break;
        case 2:
          ExcluirAluno(PonteiroAgenda);
          break;
        case 3:
          Buscar(AuxiliarContato);
          break;
        case 4:
          ImprimirAlunos(AuxiliarContato);
          break;
        case 5:
          EditarAluno(AuxiliarContato);
          break;
        case 6:
          ContarAlunos(AuxiliarContato);
          break;
        default:
          printf("Opcão inválida! Redigite!\n");
          break;
      }
    } while (Opcao != 0);

}
