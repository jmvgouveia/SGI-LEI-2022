/*
21178 - LABORATÓRIO DE PROGRAMAÇÃO - 2022

       __                         ______                       _
      / /___  _________ ____     / ____/___  __  ___   _____  (_)___ _
 __  / / __ \/ ___/ __ `/ _ \   / / __/ __ \/ / / / | / / _ \/ / __ `/
/ /_/ / /_/ / /  / /_/ /  __/  / /_/ / /_/ / /_/ /| |/ /  __/ / /_/ /
\____/\____/_/   \__, /\___/   \____/\____/\__,_/ |___/\___/_/\__,_/
                /____/

2003777 - Jorge Gouveia
------------------------------------------------------------------*/

#ifndef TESTE_BD_H
#define TESTE_BD_H

#include "main.h"

#define MAX 100

int quantECTSuc(int codUc);
int areaUC(int codUc);
void nomeAluno(int numeroAluno);
void nomeUC(int codUc);

/** ------------------------------- UNIDADES CURRICULARES -------------------------------- **/

typedef struct uCurricular
{
    int id;
    char nome_uc[MAX];
    int codigo_uCurricular;
    char ano[3];
    char semestre[5];
    int ECTS;
    char areaCientifica[3];
    char nomeDocente[MAX];


} t_uCurricular;

/** --- FUNÇÕES UNIDADES CURRICULARES --- **/
t_uCurricular *obterUcurricular(FILE *bd_uCurricular, int id_uCurricular);
int existeUcurricular(FILE *bd_uCurricular, int id_uCurricular);
void atualizarUcurricular(FILE *bd_uCurricular, t_uCurricular *arqd_atualizar);
void registarUcurricular();
void listaUcurricular();
void editarUcurricular();
void pesquisarUcurricular();
void eliminarUcurricular();
void registarUC();
void listaDocentes();
void ucsdoDocente();

/** ------------------------------- FIM UC -------------------------------------- **/


/** ------------------------------ ALUNO ---------------------------------- **/

typedef struct aluno{
    int id;
    int numero_aluno;
    char nome[MAX];
    char pais[MAX];
    char modalidadedePagamento[10];
    int numPrestacoes;


} t_aluno;


/** --- FUNÇÕES ALUNO --- **/
t_aluno *obterAluno(FILE *bd_aluno, int id_aluno);
t_aluno *verifica_aluno(FILE *bd_aluno, int id_aluno);
void atualizarAluno(FILE *bd_aluno, t_aluno *arqp_atualizar);
int existeAluno(FILE *bd_aluno, int id_aluno);
void atualizar_aluno(FILE *bd_aluno, t_aluno *arqp_atualizar);
void registarAluno();
void listaAluno();
void editarAluno();
void pesquisarAluno();
void eliminarAluno();
void notasdoAluno();

/** ------------------------------- FIM ALUNO -------------------------------------**/


/** ------------------------------- MATRICULA -----------------------------------**/

typedef struct matricula{
    int id;
    int numero_aluno;
    int codigo_uCurricular;
    char anolectivo[10];
    char estado[15];



} t_matricula;

/** --- FUNÇÕES MATRICULA --- **/
t_matricula *obter_matricula(FILE *bd_matricula, int id_matricula);
int existe_matricula(FILE *bd_matricula, int id_matricula);
void atualizarMatricula(FILE *bd_matricula, t_matricula *arqp_atualizar);


void matricularAluno();
void ucsdoAluno();
void listaMatriculas();
void editarMatricula();
void anularMatricula();
void listaMatriculasAnuladas();



/*void editarnumalunoMatriculaexistente(int numAluno, int NovoNum);
int existeMatriculaaluno(FILE *bd_matricula, int id_aluno);
void atualizarMatriculaAluno(FILE *bd_matricula, t_matricula *arqp_atualizar);
t_matricula *obterMatriculaAluno(FILE *bd_matricula, int id_aluno); */



/** ------------------------------- FIM MATRICULA -------------------------------**/


/** ------------------------------- PROFESSOR ------------------------------------**/

typedef struct professor{
    int id;
    char nome[MAX];

} t_professor;

/** --- FUNÇÕES PROFESSOR --- **/
t_professor *obter_professor(FILE *bd_aluno, int id_aluno);
int existe_professor(FILE *bp_professor, int id_professor);
void atualizar_professor(FILE *bp_professor, t_professor *arqp_atualizar);
void registarProfessor();
void listaProfessor();

/** ------------------------------- FIM PROFESSOR --------------------------------**/


/** ------------------------------- NOTAS ----------------------------------------**/

typedef struct notas{
    int id;
    int codigo_uCurricular;
    int numero_aluno;
    float nota;

} t_notas;

/** --- FUNÇÕES NOTAS --- **/
t_matricula *obterMatricula(FILE *bd_matricula, int id_aluno, int codUc);
t_notas *obterNota(FILE *bd_aluno, int id_aluno);
void atualizarNOta(FILE *bd_aluno, t_aluno *arqp_atualizar);
int existeNota(FILE *bd_notas, int id_aluno, int codUC);
void eliminarNota();
void lancarNotas();
void listaNotas();
void lancarAvaliacao();

/** ------------------------------- FIM NOTAS --------------------------------**/

#endif //TESTE_BD_H