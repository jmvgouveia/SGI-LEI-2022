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

#include "Interface.h"

char menu_notas() {

    system(limpa);
    char res[2];

    printf("\n---------------------| Menu Notas |---------------------\n");
    printf("\n1 - Lancar Notas\n");
    printf("2 - Lista Nota\n");
    printf("3 - Eliminar Nota\n");
    printf("9 - Voltar ao menu principal\n");
    printf("0 - Sair do programa\n");
    printf("\nIntroduza a sua opcao: ");
    scanf("%s", res);
    system(limpa);

    fseek(stdin, 0, SEEK_END);

    return res[0];
}

void resposta_menu_notas() {

    char res;

    res = menu_notas();

    while (res != 0) {
        switch (res) {
            case '0': {
                printf("\n\nFim do programa\n");
                exit(0);
            }
            case '1': {
                res=0;
                printf("\n---------------------| Lancar Avaliacao |---------------------\n");
                lancarAvaliacao();

                break;
            }
            case '2': {
                res=0;
                printf("\n---------------------| Lista de Avaliacoes |---------------------\n");
                listaNotas();

                break;
            }
            case '3': {
                res=0;
                printf("\n---------------------| Eliminar Nota |---------------------\n");
                eliminarNota();
                break;
            }
            case '9': {
                res=0;
                mainmenu();
                break;
            }

            default: {
                printf("\nOpcao invalida! Pressione <Enter> para continuar...");
                scanf("%*c");
                fseek(stdin, 0, SEEK_END);
                mainmenu(); // volta ao menu principal
            }
        }
    }

}

char menu_docente() {

    system(limpa);
    char resp[2];

    printf("\n---------------------| Menu Docente |---------------------\n");
    printf("\n1 - Lista de docentes\n");
    printf("2 - Lista de unidades curriculares de um professor\n");
    printf("9 - Voltar ao menu principal\n");
    printf("0 - Sair do programa\n");
    printf("\nIntroduza a sua opcao: ");
    scanf("%s", resp);
    system(limpa);
    fseek(stdin, 0, SEEK_END);

    return resp[0];
}

void resposta_menu_docente() {

    char resp;

    resp = menu_docente();

    while (resp != 0) {
        switch (resp) {
            case '0': {
                printf("\n\nFim do programa\n");
                exit(0);
            }
            case '1': {
                printf("\n---------------------| Lista de Docentes |---------------------\n");
                listaDocentes();
                resp=0;
                break;
            }
            case '2': {
                printf("\n---------------------| Unidades Curriculares do Docente |---------------------\n");
                ucsdoDocente();
                resp=0;
                break;
            }

            case '9': {
                resp=0;
                mainmenu();
                break;
            }

            default: {
                printf("\nOpcao invalida! Pressione <Enter> para continuar...");
                scanf("%*c");
                fseek(stdin, 0, SEEK_END);
                mainmenu(); // volta ao menu principal
            }
        }
    }

}

char menu_pagamentos() {
    system(limpa);
    char respo[2];

    printf("\n---------------------| Menu Pagamentos |---------------------\n");
    printf("\n1 - Calcular pagamento \n");
    printf("2 - Calcular propina do aluno \n");
    printf("9 - Voltar ao menu principal\n");
    printf("0 - Sair do programa\n");
    printf("\nIntroduza a sua opcao: ");
    scanf("%s", respo);
    system(limpa);
    fseek(stdin, 0, SEEK_END);
    return respo[0];
}

void resposta_menu_pagamentos() {


    char respo;

    respo =   menu_pagamentos();;

    while (respo != 0) {
        switch (respo) {

            case '0': {
                printf("\n\nFim do programa\n");
                exit(0);

            }
            case '1': {
               printf("\n---------------------| Calcular Propinas por ECTS |---------------------\n");
               calcpropinaporEcts();
               respo=0;
               break;
            }
            case '2': {
                printf("\n---------------------| Calcular Propinas do Aluno |---------------------\n");
                calcpropinadoAluno();
                respo=0;
                break;
            }

            case '9': {
                respo=0;
                mainmenu();
                break;
            }
            default: {
                printf("\nOpcao invalida! Pressione <Enter> para continuar...");
                scanf("%*c");
                fseek(stdin, 0, SEEK_END);
                mainmenu(); // volta ao menu principal
            }
        }
    }


}

char menu_matricula() {
    system(limpa);
    char respos[2];

    printf("\n---------------------| Menu Matriculas |---------------------\n");
    printf("\n1 - Matricular aluno\n");
    printf("2 - Editar matricula\n");
    printf("3 - Anular matricula\n");
    printf("4 - Pesquisar matricula\n");
    printf("5 - Lista de matriculas\n");
    printf("6 - Lista de Anulacoes\n");
    printf("9 - Voltar ao menu principal\n");
    printf("0 - Sair do programa\n");
    printf("\nIntroduza a sua opcao: ");
    scanf("%s", respos);
    system(limpa);
    fseek(stdin, 0, SEEK_END);
    return respos[0];
}

void resposta_menu_matricula() {


    char respos;

    respos =  menu_matricula();

    while (respos != 0) {
        switch (respos) {

            case '0': {
                printf("\n\nFim do programa\n");
                exit(0);
                break;
            }
            case '1': {
                printf("\n---------------------| Matricular Aluno |---------------------\n");
                matricularAluno();
                respos=0;
                break;
            }
            case '2': {
                printf("\n---------------------| Editar Matricula |---------------------\n");
                editarMatricula();
                respos=0;
                break;
            }
            case '3': {
                printf("\n---------------------| Anular Matricula |---------------------\n");
                anularMatricula();
                respos=0;
                break;
            }
            case '4': {
                printf("\n---------------------| Pesquisar Matricula do Aluno |---------------------\n");
                ucsdoAluno();
                respos=0;
                break;
            }
            case '5': {
                printf("\n---------------------| Lista de Matriculas |---------------------\n");
                listaMatriculas();
                respos=0;
                break;
            }
            case '6': {
                printf("\n---------------------| Lista de Matriculas Anuladas |---------------------\n");
                listaMatriculasAnuladas();
                respos=0;
                break;
            }

            case '7': {

                respos=0;
                break;
            }
            case '9': {
                respos=0;
                mainmenu();
                break;

            }
            default: {
                printf("\nOpcao invalida! Pressione <Enter> para continuar...");
                scanf("%*c");
                fseek(stdin, 0, SEEK_END);
                mainmenu(); // volta ao menu principal
            }
        }
    }


}

char menu_ucs() {
    system(limpa);
    char respost[2];

    printf("\n---------------------| Menu Unidades Curriculares |---------------------\n");
    printf("\n1 - Nova unidade curricular\n");
    printf("2 - Editar unidade curricular\n");
    printf("3 - Eliminar unidade curricular\n");
    printf("4 - Pesquisar unidade curricular\n");
    printf("5 - Lista de unidades curriculares\n");
    printf("7 - Lista de unidades curriculares de um professor\n");
    printf("9 - Voltar ao menu principal\n");
    printf("0 - Sair do programa\n");
    printf("\nIntroduza a sua opcao: ");
    scanf("%s", respost);
    system(limpa);
    fseek(stdin, 0, SEEK_END);
    return respost[0];
}

void resposta_menu_ucs() {


    char respost;

    respost = menu_ucs();

    while (respost != 0) {
        switch (respost) {
            case '0': {
                printf("\n\nFim do programa\n");
                exit(0);
            }
            case '1': {
                printf("\n---------------------| Registar UC |---------------------\n");
                registarUC();
                respost=0;
                break;
            }
            case '2': {
                printf("\n---------------------| Editar UC |---------------------\n");
               editarUcurricular();
               respost=0;
                break;
            }
            case '3': {
                printf("\n---------------------| Eliminar UC |---------------------\n");
               eliminarUcurricular();
               respost=0;
                break;
            }
            case '4': {
                printf("\n---------------------| Pesquisar UC |---------------------\n");
                pesquisarUcurricular();
                respost=0;
                break;
            }
            case '5': {
                printf("\n---------------------| Lista das UC |---------------------\n");
                listaUcurricular();
                respost=0;
                break;
            }
            case '9': {
                respost=0;
                mainmenu();
                break;
            }

            default: {
                printf("\nOpcao invalida! Pressione <Enter> para continuar...");
                scanf("%*c");
                fseek(stdin, 0, SEEK_END);
                mainmenu(); // volta ao menu principal
            }
        }
    }

}

char menu_aluno() {
    system(limpa);
    char resposta[2];

    printf("\n---------------------| Menu Aluno |---------------------\n");
    printf("\n1 - Novo aluno\n");
    printf("2 - Editar aluno\n");
    printf("3 - Eliminar aluno\n");
    printf("4 - Pesquisar aluno\n");
    printf("5 - Lista de alunos\n");
    printf("6 - Lista de UCs do Aluno\n");
    printf("7 - Notas do Aluno\n");
    printf("8 - Contagem de ECTS\n");
    printf("9 - Voltar ao menu principal\n");
    printf("0 - Sair do programa\n");
    printf("\nIntroduza a sua opcao: ");
    scanf("%s", resposta);
    system(limpa);

    fseek(stdin, 0, SEEK_END);

    return resposta[0];
}

void resposta_menu_aluno() {

    char resposta;

    resposta = menu_aluno();

    while (resposta != 0) {

        switch (resposta) {

            case '0': {
                printf("\n\nFim do programa\n");
                exit(0);
                            }
            case '1': {
                printf("\n---------------------| Registar Aluno |---------------------\n");
                registarAluno();
                resposta=0;
                break;
            }
            case '2': {
                printf("\n---------------------| Editar Aluno |---------------------\n");
                editarAluno();
                resposta=0;
                break;
            }
            case '3': {
                printf("\n---------------------| Eliminar Aluno |---------------------\n");
                eliminarAluno();
                resposta=0;
                break;
            }
            case '4': {
                printf("\n---------------------| Pesquisar Aluno |---------------------\n");
                pesquisarAluno();
                resposta=0;

                break;
            }
            case '5': {
                printf("\n---------------------| Lista dos Aluno |---------------------\n");
                listaAluno();
                resposta=0;
                break;
            }
            case '6': {
                printf("\n---------------------| Lista de UCs do Aluno |---------------------\n");
                ucsdoAluno();
                resposta=0;
                break;
            }
            case '7': {
                printf("\n---------------------| Notas do Aluno |---------------------\n");
                notasdoAluno();
                resposta=0;
                break;
            }case '8': {
                printf("\n---------------------| ECTS do Aluno |---------------------\n");
                calcectsparaterminar();
                resposta=0;
                break;
            }
            case '9': {
                resposta=0;
                mainmenu();
                break;
            }
            default: {
                printf("\nOpcao invalida! Pressione <Enter> para continuar...");
                scanf("%*c");
                fseek(stdin, 0, SEEK_END);
                mainmenu(); // volta ao menu principal
            }

        }

    }

}

void mainmenu(){

    char resposta;

    printf("\n---------------------| Menu Principal |---------------------");
    printf("\n\n1 - Aluno\n");
    printf("2 - Matriculas\n");
    printf("3 - Pagamentos\n");
    printf("4 - Unidades Curriculares\n");
    printf("5 - Docentes\n");
    printf("6 - Notas\n");
    printf("7 - Manual\n");
    printf("8 - Notas Finais\n");
    printf("0 - Sair do programa\n");
    printf("\nIntroduza a sua opcao: ");
    scanf("%c", &resposta);
    system(limpa);

    while (resposta != 0) {
        switch (resposta) {
            case '0': {
                printf("\n\nFim do programa\n");
                exit(0);
            }
            case '1': {
                resposta_menu_aluno();
                break;
            }
            case '2': {
                resposta_menu_matricula();
                break;
            }
            case '3': {
                resposta_menu_pagamentos();
                break;
            }
            case '4': {
                resposta_menu_ucs();
                break;
            }
            case '5': {
                resposta_menu_docente();
                break;
            }
            case '6': {
                resposta_menu_notas();
                break;
            }
            case '7': {
               manual();
               break;
            }
            case '8': {
                notasfinais();
                break;
            }

            default: {
                printf("\nOpcao invalida! Pressione <Enter> para continuar...");
                scanf("%*c");
                fseek(stdin, 0, SEEK_END);
                mainmenu();
            }
        }
    }

    printf("\n***** - Fim do programa - *****\n\n");

}

