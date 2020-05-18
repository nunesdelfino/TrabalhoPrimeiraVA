#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include "Agenda.h"
#include "Menu.h"
#include <string.h>

void ExcluirMatricula(Contato *PonteiroContato){
	int Matricula;

	printf("Digite a matricula do aluno a ser excluido: ");
	scanf("%i", &Matricula);
	if(PonteiroContato->Matricula == Matricula){
		PonteiroContato = PonteiroContato->ProxAgenda;
		printf("Aluno removido com sucesso!\n");
	} else{  

		Contato *Auxiliar;
		Contato *Anterior;

		Anterior = NULL;
		Auxiliar = PonteiroContato;

		while (Auxiliar != NULL && Auxiliar->Matricula != Matricula) {

			Anterior = Auxiliar;
			Auxiliar = Auxiliar->ProxAgenda;

		}

		if(Auxiliar != NULL){
			Anterior->ProxAgenda = Auxiliar->ProxAgenda;
			free(Auxiliar);
			printf("Aluno removido com sucesso!\n");
		}
	}
}

void ExcluirNome(Contato *PonteiroContato){
	char Nome[40];

	printf("Digite o nome do aluno a ser removido: ");
	setbuf(stdin, NULL);
	scanf("%[^\n]s", &Nome);

	if(strcmp(PonteiroContato->Nome,Nome) == 0){
		PonteiroContato = PonteiroContato->ProxAgenda;
		printf("Aluno removido com sucesso!\n");
	} else{  

		Contato *Auxiliar;
		Contato *Anterior;

		Anterior = NULL;
		Auxiliar = PonteiroContato;

		while (Auxiliar != NULL && strcmp(Auxiliar->Nome,Nome) != 0) {

			Anterior = Auxiliar;
			Auxiliar = Auxiliar->ProxAgenda;

		}

		if(Auxiliar != NULL){
			Anterior->ProxAgenda = Auxiliar->ProxAgenda;
			free(Auxiliar);
			printf("Aluno removido com sucesso!\n");
		}
	}
}

void ExcluirEmail(Contato *PonteiroContato){
	char Email[40];

	printf("Digite o email do aluno a ser removido: ");
	setbuf(stdin, NULL);
	scanf("%[^\n]s", &Email);

	if(strcmp(PonteiroContato->Email,Email) == 0){
		PonteiroContato = PonteiroContato->ProxAgenda;
		printf("Aluno removido com sucesso!\n");
	} else{  

		Contato *Auxiliar;
		Contato *Anterior;

		Anterior = NULL;
		Auxiliar = PonteiroContato;

		while (Auxiliar != NULL && strcmp(Auxiliar->Email,Email) != 0) {

			Anterior = Auxiliar;
			Auxiliar = Auxiliar->ProxAgenda;

		}

		if(Auxiliar != NULL){
			Anterior->ProxAgenda = Auxiliar->ProxAgenda;
			free(Auxiliar);
			printf("Aluno removido com sucesso!\n");
		}
	}
}

void ExcluirAluno(Contato *PonteiroContato){
	if(PonteiroContato != NULL){
		int Opcao;
		do{
			MenuExcluir(&Opcao);
			switch (Opcao){
			case 0:
				printf("Voltando ao menu anterior...\n");
				break;
			case 1:
				ExcluirMatricula(PonteiroContato);
				break;
			case 2:
			  	ExcluirNome(PonteiroContato);
				break;
			case 3:
			  	ExcluirEmail(PonteiroContato);
				break;
			default:
			printf("Opcão inválida! Redigite!\n");
			break;
		}

		} while (Opcao != 0);
	} else {
		printf("A lista está vazia!\n");
	}
}

void Imprimir(Contato *PonteiroContato){

	struct Telefone *AuxiliarTele;
	struct Disciplina *AuxiliarDisc;

	AuxiliarTele = PonteiroContato->telefone_do_aluno;
	AuxiliarDisc = PonteiroContato->disciplina_do_aluno;

	printf("\n\nMatricula: %i\n", PonteiroContato->Matricula);
  	printf("Nome: %s\n", PonteiroContato->Nome);

	printf("Telefone: ");
	while (AuxiliarTele != NULL) {
		printf("%s == ", AuxiliarTele->telefoneAluno);
		AuxiliarTele = AuxiliarTele->ProxTelefone;
	}

	printf("\nEmail: %s\n", PonteiroContato->Email);
	printf("Curso: %s\n", PonteiroContato->Curso);

	printf("Disciplina: ");
	while (AuxiliarDisc != NULL) {
		printf("%s == ", AuxiliarDisc->disciplinaAluno);
		AuxiliarDisc = AuxiliarDisc->ProxDisciplina;
	}
}

void InserirTelefone(struct Telefone **PonteiroTelefone){

    struct Telefone *NovoTelefone = NULL;
    NovoTelefone = (struct Telefone *) malloc(sizeof(struct Telefone));

    printf("Telefone: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]s", NovoTelefone->telefoneAluno);

    if(*PonteiroTelefone == NULL){
		NovoTelefone->ProxTelefone = NULL;
		*PonteiroTelefone = NovoTelefone;
	} else {
		NovoTelefone->ProxTelefone = *PonteiroTelefone;
		*PonteiroTelefone = NovoTelefone;
	}
}

void InserirDisciplina(struct Disciplina **PonteiroDisciplina){

    struct Disciplina *NovaDisciplina = NULL;
    NovaDisciplina = (struct Disciplina *) malloc(sizeof(struct Disciplina));

    printf("Disciplina: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]s", NovaDisciplina->disciplinaAluno);

    if(*PonteiroDisciplina == NULL){
		NovaDisciplina->ProxDisciplina = NULL;
		*PonteiroDisciplina = NovaDisciplina;
	} else {
		NovaDisciplina->ProxDisciplina = *PonteiroDisciplina;
		*PonteiroDisciplina = NovaDisciplina;
	}
}

void Inserir(Contato **PonteiroContato){

  struct Telefone *PonteiroTelefone = NULL;
	struct Disciplina *PonteiroDisciplina = NULL;

	char Escolha = 'S';

	Contato *NovoContato;
	Contato *Auxiliar;

	NovoContato = (Contato *) malloc(sizeof(Contato));
	Auxiliar = (Contato *) malloc(sizeof(Contato));

	printf("Matricula: ");
	scanf("%i", &NovoContato->Matricula);

    printf("Nome: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]s", &NovoContato->Nome);

	for(int i = 0; i < 1; i++){
		InserirTelefone(&PonteiroTelefone);
		NovoContato->telefone_do_aluno = PonteiroTelefone;

		printf("Deseja inserir outro telefone? [S - sim]: ");
		setbuf(stdin, NULL);
		scanf("%s",&Escolha);

		if(Escolha == 's' || Escolha == 'S')
			i--;
	}

    printf("Email: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]s", NovoContato->Email);

    printf("Curso: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]s", NovoContato->Curso);

	for(int i = 0; i < 1; i++){
		InserirDisciplina(&PonteiroDisciplina);
		NovoContato->disciplina_do_aluno = PonteiroDisciplina;

		printf("Deseja inserir outra disciplina? [S - sim]: ");
		setbuf(stdin, NULL);
		scanf("%s",&Escolha);

		if(Escolha == 's' || Escolha == 'S')
			i--;
	}

	if(*PonteiroContato == NULL){
		*PonteiroContato = NovoContato;
	} else {
		Auxiliar = *PonteiroContato;
		while (Auxiliar->ProxAgenda != NULL) {
			Auxiliar = Auxiliar->ProxAgenda;
		}
		Auxiliar->ProxAgenda = NovoContato;
	}
}

void BuscarMatricula(Contato *PonteiroContato){
	Contato *AuxiliarContato = PonteiroContato->ProxAgenda;
	int Buscar;

	printf("Digite a matricula a ser buscada: ");
	scanf("%i", &Buscar);

	int Confere = 0;
	if(AuxiliarContato != NULL){
		while(AuxiliarContato != NULL){
			if(AuxiliarContato->Matricula == Buscar){
				Imprimir(AuxiliarContato);
				Confere++;
			}
			AuxiliarContato = AuxiliarContato->ProxAgenda;
		}
		if(AuxiliarContato == NULL && Confere == 0){
			printf("Matricula não encontrada!\n");
		}
	} else {
		printf("Lista vazia!\n");
	}
}

void BuscarNome(Contato *PonteiroContato){
	Contato *AuxiliarContato = PonteiroContato->ProxAgenda;
	char Buscar[40];

	printf("Digite o nome a ser buscado: ");
	setbuf(stdin, NULL);
	scanf("%[^\n]s", &Buscar);

	int Confere = 0;
	if(AuxiliarContato != NULL){
		while(AuxiliarContato != NULL){
			if(strcmp(AuxiliarContato->Nome, Buscar) == 0){
				Imprimir(AuxiliarContato);
				Confere++;
			}
			AuxiliarContato = AuxiliarContato->ProxAgenda;
		}
		if(AuxiliarContato == NULL && Confere == 0){
			printf("Nome não encontrado!\n");
		}
	} else {
		printf("Lista vazia!\n");
	}
}

void BuscarEmail(Contato *PonteiroContato){
	Contato *AuxiliarContato = PonteiroContato->ProxAgenda;
	char Buscar[40];

	printf("Digite o email a ser buscado: ");
	setbuf(stdin, NULL);
	scanf("%[^\n]s", &Buscar);

	int Confere = 0;
	if(AuxiliarContato != NULL){
		while(AuxiliarContato != NULL){
			if(strcmp(AuxiliarContato->Email, Buscar) == 0){
				Imprimir(AuxiliarContato);
				Confere++;
			}
			AuxiliarContato = AuxiliarContato->ProxAgenda;
		}
		if(AuxiliarContato == NULL && Confere == 0){
			printf("Email não encontrado!\n");
		}
	} else {
		printf("Lista vazia!\n");
	}
}

void BuscarCurso(Contato *PonteiroContato){
	Contato *AuxiliarContato = PonteiroContato->ProxAgenda;
	char Buscar[40];

	printf("Digite o curso a ser buscado: ");
	setbuf(stdin, NULL);
	scanf("%[^\n]s", &Buscar);

	int Confere = 0;
	if(AuxiliarContato != NULL){
		while(AuxiliarContato != NULL){
			if(strcmp(AuxiliarContato->Curso, Buscar) == 0){
				Imprimir(AuxiliarContato);
				Confere++;
			}
			AuxiliarContato = AuxiliarContato->ProxAgenda;
		}
		if(AuxiliarContato == NULL && Confere == 0){
			printf("Curso não encontrado!\n");
		}
	} else {
		printf("Lista vazia!\n");
	}
}

void Buscar(Contato *PonteiroContato){
	if (PonteiroContato != NULL){
		int Opcao;

		do{
			MenuBuscar(&Opcao);
			switch (Opcao){
			case 0:
				printf("Voltando ao menu anterior...\n");
				break;
			case 1:
				BuscarMatricula(PonteiroContato);
				break;
			case 2:
			  	BuscarNome(PonteiroContato);
				break;
			case 3:
			  	BuscarEmail(PonteiroContato);
				break;
			case 4:
				BuscarCurso(PonteiroContato);
				break;
			default:
			printf("Opcão inválida! Redigite!\n");
			break;
		}

		} while (Opcao != 0);

	} else {
		printf("A lista está vazia!\n");
	}
}

void ContarAlunos(Contato *PonteiroContatos){
	int Elementos = 0;
	Contato *AuxiliarContato = PonteiroContatos->ProxAgenda;
	if(AuxiliarContato != NULL){
		while (AuxiliarContato != NULL) {
			Elementos++;
			AuxiliarContato = AuxiliarContato->ProxAgenda;
		}
		printf("A lista tem %i alunos inseridos\n", Elementos);
	} else {
		printf("A lista está vazia!\n");
	}
}

void ImprimirAlunos(Contato *PonteiroContatos){
	Contato *AuxiliarContato = PonteiroContatos->ProxAgenda;
	if(AuxiliarContato != NULL){
		while (AuxiliarContato != NULL) {
			Imprimir(AuxiliarContato);
			AuxiliarContato = AuxiliarContato->ProxAgenda;
		}
	} else {
		printf("A lista está vazia!\n");
	}
}

void EditarMatricula(Contato *PonteiroContato){
	Contato *AuxiliarContato = PonteiroContato;
	int Matricula, Confere = 0;

	printf("Digite a matricula a ser editada: ");
	scanf("%i", &Matricula);

	while (AuxiliarContato != NULL){
		if(AuxiliarContato->Matricula == Matricula){
			printf("Digite a nova matricula: ");
			scanf("%i", &AuxiliarContato->Matricula);

			printf("Alteração realizada com sucesso!");
			Confere++;
		}
		AuxiliarContato = AuxiliarContato->ProxAgenda;
	}
	if(AuxiliarContato == NULL && Confere == 0){
			printf("Matricula não encontrada!\n");
	}
}

void EditarNome(Contato *PonteiroContato){
	Contato *AuxiliarContato = PonteiroContato;
	int Confere = 0, Matricula;

	printf("Digite a matricula do aluno a editar o nome: ");
	scanf("%i", &Matricula);

	while (AuxiliarContato != NULL){
		if(AuxiliarContato->Matricula == Matricula){
			printf("Digite o novo nome: ");
			setbuf(stdin, NULL);
			scanf("%[^\n]s", &AuxiliarContato->Nome);

			printf("Alteração realizada com sucesso!");
			Confere++;
		}
		AuxiliarContato = AuxiliarContato->ProxAgenda;
	}
	if(AuxiliarContato == NULL && Confere == 0){
			printf("Matricula não encontrada!\n");
	}
}

void EditarEmail(Contato *PonteiroContato){
	Contato *AuxiliarContato = PonteiroContato;
	int Confere = 0, Matricula;

	printf("Digite a matricula do aluno a editar o email: ");
	scanf("%i", &Matricula);

	while (AuxiliarContato != NULL){
		if(AuxiliarContato->Matricula == Matricula){
			printf("Digite o novo email: ");
			setbuf(stdin, NULL);
			scanf("%[^\n]s", &AuxiliarContato->Email);

			printf("Alteração realizada com sucesso!");
			Confere++;
		}
		AuxiliarContato = AuxiliarContato->ProxAgenda;
	}
	if(AuxiliarContato == NULL && Confere == 0){
			printf("Matricula não encontrada!\n");
	}
}

void EditarCurso(Contato *PonteiroContato){
	Contato *AuxiliarContato = PonteiroContato;
	int Confere = 0, Matricula;

	printf("Digite a matricula do aluno a editar o curso: ");
	scanf("%i", &Matricula);

	while (AuxiliarContato != NULL){
		if(AuxiliarContato->Matricula == Matricula){
			printf("Digite o novo curso: ");
			setbuf(stdin, NULL);
			scanf("%[^\n]s", &AuxiliarContato->Curso);

			printf("Alteração realizada com sucesso!");
			Confere++;
		}
		AuxiliarContato = AuxiliarContato->ProxAgenda;
	}
	if(AuxiliarContato == NULL && Confere == 0){
			printf("Matricula não encontrada!\n");
	}
}

void EditarDisciplina(Contato *PonteiroContato){
	Contato *AuxiliarContato = PonteiroContato;
	int Confere = 0, Matricula;

	struct Disciplina *NovaDisciplina = NULL;
    NovaDisciplina = (struct Disciplina *) malloc(sizeof(struct Disciplina));

	printf("Digite a matricula do aluno a editar a disciplina: ");
	scanf("%i", &Matricula);

	while (AuxiliarContato != NULL){
		if(AuxiliarContato->Matricula == Matricula){
			printf("Digite a nova disciplina: ");
    		setbuf(stdin, NULL);
    		scanf("%[^\n]s", NovaDisciplina->disciplinaAluno);

			NovaDisciplina->ProxDisciplina = NULL;
			AuxiliarContato->disciplina_do_aluno = NovaDisciplina;

			printf("Alteração realizada com sucesso!");
			Confere++;
		}
		AuxiliarContato = AuxiliarContato->ProxAgenda;
	}
	if(AuxiliarContato == NULL && Confere == 0){
			printf("Matricula não encontrada!\n");
	}
}

void EditarTelefone(Contato *PonteiroContato){
	Contato *AuxiliarContato = PonteiroContato;
	int Confere = 0, Matricula;

	struct Telefone *NovoTelefone = NULL;
    NovoTelefone = (struct Telefone *) malloc(sizeof(struct Telefone));

	printf("Digite a matricula do aluno a editar o telefone: ");
	scanf("%i", &Matricula);

	while (AuxiliarContato != NULL){
		if(AuxiliarContato->Matricula == Matricula){
			printf("Digite o novo telefone: ");
    		setbuf(stdin, NULL);
    		scanf("%[^\n]s", NovoTelefone->telefoneAluno);

			NovoTelefone->ProxTelefone = NULL;
			AuxiliarContato->telefone_do_aluno = NovoTelefone;

			printf("Alteração realizada com sucesso!");
			Confere++;
		}
		AuxiliarContato = AuxiliarContato->ProxAgenda;
	}
	if(AuxiliarContato == NULL && Confere == 0){
			printf("Matricula não encontrada!\n");
	}
}

void AdicionarTelefone(Contato *PonteiroContato){
	Contato *AuxiliarContato = PonteiroContato;
	int Confere = 0, Matricula;

	struct Telefone *NovoTelefone = NULL;
    NovoTelefone = (struct Telefone *) malloc(sizeof(struct Telefone));

	printf("Digite a matricula do aluno a adicionar um telefone: ");
	scanf("%i", &Matricula);

	while (AuxiliarContato != NULL){
		if(AuxiliarContato->Matricula == Matricula){
			printf("Digite o novo telefone: ");
    		setbuf(stdin, NULL);
    		scanf("%[^\n]s", NovoTelefone->telefoneAluno);

			NovoTelefone->ProxTelefone = NULL;
			AuxiliarContato->telefone_do_aluno->ProxTelefone = NovoTelefone;

			printf("Alteração realizada com sucesso!");
			Confere++;
		}
		AuxiliarContato = AuxiliarContato->ProxAgenda;
	}
	if(AuxiliarContato == NULL && Confere == 0){
			printf("Matricula não encontrada!\n");
	}
}

void AdicionarDisciplina(Contato *PonteiroContato){
	Contato *AuxiliarContato = PonteiroContato;
	int Confere = 0, Matricula;

	struct Disciplina *NovaDisciplina = NULL;
    NovaDisciplina = (struct Disciplina *) malloc(sizeof(struct Disciplina));

	printf("Digite a matricula do aluno a adicionar uma disciplina: ");
	scanf("%i", &Matricula);

	while (AuxiliarContato != NULL){
		if(AuxiliarContato->Matricula == Matricula){
			printf("Digite a nova disciplina: ");
    		setbuf(stdin, NULL);
    		scanf("%[^\n]s", NovaDisciplina->disciplinaAluno);

			NovaDisciplina->ProxDisciplina = NULL;
			AuxiliarContato->disciplina_do_aluno->ProxDisciplina = NovaDisciplina;

			printf("Alteração realizada com sucesso!");
			Confere++;
		}
		AuxiliarContato = AuxiliarContato->ProxAgenda;
	}
	if(AuxiliarContato == NULL && Confere == 0){
			printf("Matricula não encontrada!\n");
	}
}

void EditarAluno(Contato *PonteiroContato){
	Contato *Auxiliar = PonteiroContato->ProxAgenda;
	if(Auxiliar != NULL){
		int Opcao;
		do{
			MenuEditar(&Opcao);
			switch (Opcao){
			case 0:
				printf("Voltando ao menu anterior...\n");
				break;
			case 1:
				EditarMatricula(Auxiliar);
				break;
			case 2:
			  	EditarNome(Auxiliar);
				break;
			case 3:
			  	EditarEmail(Auxiliar);
				break;
			case 4:
			  	EditarCurso(Auxiliar);
				break;
			case 5:
			  	EditarDisciplina(Auxiliar);
				break;
			case 6:
			  	EditarTelefone(Auxiliar);
				break;
			case 7:
				AdicionarDisciplina(Auxiliar);
				break;
			case 8:
				AdicionarTelefone(Auxiliar);
				break;
			default:
			printf("Opcão inválida! Redigite!\n");
			break;
		}

		} while (Opcao != 0);
	} else {
		printf("A lista está vazia!\n");
	}
}

#endif
