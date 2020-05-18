

#ifndef AGENDA_H
#define AGENDA_H

typedef struct Agenda {
	int Matricula;
  char Nome[40];
  char Email[40];
  char Curso[40];
  struct Disciplina *disciplina_do_aluno;
  struct Telefone *telefone_do_aluno;
	struct Agenda *ProxAgenda;
} Contato;

struct Telefone {
  char telefoneAluno[20];
  struct Telefone *ProxTelefone;
};

struct Disciplina {
  char disciplinaAluno[40];
  struct Disciplina *ProxDisciplina;
};

#endif
