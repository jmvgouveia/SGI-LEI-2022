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


#include "bd.h"
/////////////////////////////////////////////////////

void nomeUC(int codUc) {

    // - Função para procurar o nome da Unidade curricular e nome do Docente

    FILE *bd_uc = fopen("uc.bin", "rb");

    checkfile(bd_uc); // -> verifica o ficheiro

    t_uCurricular uCurricular;

    while (1) {
        size_t result = fread(&uCurricular, sizeof(t_uCurricular), 1, bd_uc);

        if (result == 0)
            break;


        int numAluno_aux;

        numAluno_aux = uCurricular.codigo_uCurricular;

        if (numAluno_aux == codUc) {

            printf("\nNome UC: %s", uCurricular.nome_uc);
            printf("\nDocente: %s", uCurricular.nomeDocente);

        }
    }
    fclose(bd_uc);
    fseek(stdin, 0, SEEK_END);

}

int quantECTSuc(int codUc) {

    // - Função para devolve o numero de ECTS de uma Unidade Curricular

    int ects = 0;

    FILE *bd_uc = fopen("uc.bin", "rb");

    checkfile(bd_uc);

    t_uCurricular uCurricular;

    while (1) {
        size_t result = fread(&uCurricular, sizeof(t_uCurricular), 1, bd_uc);

        if (result == 0)
            break;

        int numAluno_aux;

        numAluno_aux = uCurricular.codigo_uCurricular;

        if (numAluno_aux == codUc) {

            ects = uCurricular.ECTS;

        }
    }
    fclose(bd_uc);
    fseek(stdin, 0, SEEK_END);

    return ects;
}

int areaUC(int codUc) {

    // - Função para devolve a Area Cientifica da Unidade Curricular

    char area[10];

    FILE *bd_uc = fopen("uc.bin", "rb");

    checkfile(bd_uc);

    t_uCurricular uCurricular;

    while (1) {
        size_t result = fread(&uCurricular, sizeof(t_uCurricular), 1, bd_uc);

        if (result == 0)
            break;

        int numAluno_aux;

        numAluno_aux = uCurricular.codigo_uCurricular;

        if (numAluno_aux == codUc) {

            strcpy(area, uCurricular.areaCientifica);

        }
    }
    fclose(bd_uc);
    fseek(stdin, 0, SEEK_END);

    // devolve um inteiro consoante a area

    if (strcmp(area, "I") == 0) {
        return 1;
    } else if (strcmp(area, "M") == 0) {
        return 2;
    } else if (strcmp(area, "F") == 0) {
        return 3;
    }
    return 0;
}

void nomeAluno(int numeroAluno) {

    // - Função para devolve o nome do aluno, atráves do Numero do Aluno

    FILE *bd_aluno = fopen("aluno.bin", "rb");
    checkfile(bd_aluno);

    t_aluno aluno;

    while (1) {
        size_t result = fread(&aluno, sizeof(t_aluno), 1, bd_aluno);

        if (result == 0)
            break;


        int numAluno_aux;

        numAluno_aux = aluno.numero_aluno;

        if (numAluno_aux == numeroAluno) {

            printf("\nNome do Aluno: %s", aluno.nome);
        }
    }
    fclose(bd_aluno);
    fseek(stdin, 0, SEEK_END);

}

///////////////////////// - ALUNO - ////////////////////////////

int existeAluno(FILE *bd_aluno, int id_aluno) {

    //Verifica se existe aluno na BD

    rewind(bd_aluno);

    t_aluno aluno;

    while (1) {
        size_t result = fread(&aluno, sizeof(t_aluno), 1, bd_aluno);

        if (result == 0)
            break;

        if (aluno.numero_aluno == id_aluno)
            return 1;
    }
    return 0;
}

t_aluno *obterAluno(FILE *bd_aluno, int id_aluno) {

    //Procura na BD pelo Aluno

    rewind(bd_aluno);

    t_aluno *aluno;

    aluno = (t_aluno *) malloc(sizeof(t_aluno));

    while (1) {

        size_t result = fread(aluno, sizeof(t_aluno), 1, bd_aluno);

        if (result == 0) {
            free(aluno);
            return NULL;
        }

        if (aluno->numero_aluno == id_aluno)
            break;
    }
    return aluno;
}

void atualizarAluno(FILE *bd_aluno, t_aluno *arqp_atualizar) {

    //Atualiza os dados do aluno na BD

    rewind(bd_aluno);

    t_aluno aluno1;
    while (1) {

        size_t result = fread(&aluno1, sizeof(t_aluno), 1, bd_aluno);

        if (result == 0)
            break;

        if (aluno1.id == arqp_atualizar->id) {
            fseek(bd_aluno, (long int) -sizeof(t_aluno), SEEK_CUR);
            fwrite(arqp_atualizar, sizeof(t_aluno), 1, bd_aluno);
            break;
        }
    }
}

void registarAluno() {

    //Funcção para criar novo Aluno

    FILE *bd_aluno = fopen("aluno.bin", "a+b");

    checkfile(bd_aluno);

    int cont_bytes = 0;  // -> variavel para contar

    fseek(bd_aluno, 0, SEEK_END); // -> procura no ficheiro
    cont_bytes = ftell(bd_aluno);

    t_aluno aluno;

    // caso seja 0 é o primeiro registo, caso nao seja, adiciona ao ultimo 1

    if (cont_bytes == 0) {
        aluno.id = 1;
    } else {
        t_aluno ultimo_aluno;

        fseek(bd_aluno, cont_bytes - sizeof(t_aluno), SEEK_SET);

        fread(&ultimo_aluno, sizeof(t_aluno), 1, bd_aluno);

        aluno.id = ultimo_aluno.id + 1;
    }


    printf("\nIntroduza o nome do aluno: ");
    gets(aluno.nome);

    // validação de input e verifica se o numero de aluno já existe na BD

    while (1) {
        printf("\nIntroduza o numero do aluno: ");
        fflush(stdin);
        if (scanf("%d", &aluno.numero_aluno) != 1) {
            printf("(Introduza apenas numeros)\n");
        } else if (existeAluno(bd_aluno, aluno.numero_aluno) == 1) {
            printf("Numero de Aluno ja existe!");
        } else {
            break;
        }
    }

    fflush(stdin); // -> limpa o Buffer do teclado

    printf("\nIntroduza o pais do aluno: ");
    gets(aluno.pais);

    // Validação do Input, aceitando apenas M ou m e T ou t
    while (1) {

        printf("\nIntroduza a modalidade de pagamento (T = Total ou M = Mensal): ");
        gets(aluno.modalidadedePagamento);
        if (strcmp(aluno.modalidadedePagamento, "T") == 0 || strcmp(aluno.modalidadedePagamento, "M") == 0 ||
            strcmp(aluno.modalidadedePagamento, "t") == 0 || strcmp(aluno.modalidadedePagamento, "m") == 0)
            break;

    }

    // Validação caso seja pagamento em mensalidades, pergunta em quantas

    if ((strcmp(aluno.modalidadedePagamento, "M") == 0) || (strcmp(aluno.modalidadedePagamento, "m") == 0)) {

        while (1) {

            printf("\nIntroduza o numero de prestacoes (Min:2 - Max:10): ");
            scanf("%d", &aluno.numPrestacoes);
            if (checknumPrestacoes(aluno.numPrestacoes) == 0)
                break;

        }

        fflush(stdin);
    } else {
        aluno.numPrestacoes = 1;
    }


    fseek(stdin, 0, SEEK_END);
    fseek(bd_aluno, 0, SEEK_END);
    fwrite(&aluno, sizeof(t_aluno), 1, bd_aluno);

    fclose(bd_aluno);

    printf("\n%s, com o numero, \"%d\", foi registado com sucesso!\n", aluno.nome, aluno.numero_aluno);
    printf("\nPressione <Enter> para continuar...");
    scanf("%*c");

    fseek(stdin, 0, SEEK_END);
}

void listaAluno() {

    // Lista todos os registos do alunos

    FILE *bd_aluno = fopen("aluno.bin", "rb");

    checkfile(bd_aluno);

    int encontrou_aluno = 0;
    t_aluno aluno;

    while (1) {
        size_t result = fread(&aluno, sizeof(t_aluno), 1, bd_aluno);

        if (result == 0)
            break;

        encontrou_aluno = 1;
        printf("\n-----------| ALUNO: %d |-----------\n\n", aluno.numero_aluno);
        printf("Nome do Aluno: %s\n", aluno.nome);
        printf("Pais do Aluno: %s\n", aluno.pais);
        printf("Modalidade de Pagamento: %s\n", aluno.modalidadedePagamento);
        if (strcmp(aluno.modalidadedePagamento, "M") == 0) {
            printf("Numero de Mensalidades: %d\n", aluno.numPrestacoes);
        }


    }

    if (encontrou_aluno == 0)
        printf("\nNao existe alunos registados.\n");

    fclose(bd_aluno);

    printf("\nPressione <Enter> para continuar...");
    scanf("%*c");

    fseek(stdin, 0, SEEK_END);
}

void editarAluno() {

    // Função para editar os dados dos alunos, excluindo o numero do aluno uma vez que é a chave para as relações.

    char str_id_aluno1[10];
    int id_aluno1;

    FILE *bd_aluno1 = fopen("aluno.bin", "rb+");

    checkfile(bd_aluno1);

    printf("\nIntroduza o numero do aluno: ");
    scanf("%s", str_id_aluno1);

    fflush(stdin);

    fseek(stdin, 0, SEEK_END);

    // Funcao para verificar as string e converter a string para Inteiro.

    if (verificar_str(str_id_aluno1) == 1) {

        sscanf(str_id_aluno1, "%d", &id_aluno1);

        if (existeAluno(bd_aluno1, id_aluno1)) { // Verifica se existe o aluno

            if (verificar_str(str_id_aluno1) == 1) {

                sscanf(str_id_aluno1, "%d", &id_aluno1);

                t_aluno *aluno1 = obterAluno(bd_aluno1, id_aluno1); // vai buscar os dados


                if (aluno1 != NULL) {

                    // atualiza os dados com os novos dados inseridos:

                    printf("\n-------| Atualizar Dados |-------");
                    printf("\nIntroduza o nome: ");
                    gets(aluno1->nome);

                    fflush(stdin);

                    printf("\nIntroduza o pais: ");
                    gets(aluno1->pais);

                    // validação do input da modalidade de pagamento.
                    while (1)  {

                        printf("\nIntroduza a modalidade de pagamento (T = Total ou M = Mensal): ");
                        gets(aluno1->modalidadedePagamento);
                        if (strcmp(aluno1->modalidadedePagamento, "T") == 0 ||
                            strcmp(aluno1->modalidadedePagamento, "M") == 0 ||
                            strcmp(aluno1->modalidadedePagamento, "t") == 0 ||
                            strcmp(aluno1->modalidadedePagamento, "m") == 0)
                            break;

                    }

                    if ((strcmp(aluno1->modalidadedePagamento, "M") == 0) ||
                        (strcmp(aluno1->modalidadedePagamento, "m") == 0)) {

                        while (1) {
                            fflush(stdin);
                            printf("\nIntroduza o numero de prestacoes (Min:2 - Max:10): ");
                            scanf("%d", &aluno1->numPrestacoes);
                            if (checknumPrestacoes(aluno1->numPrestacoes) == 0)
                                break;

                        }

                    }
                    fflush(stdin);
                    atualizarAluno(bd_aluno1, aluno1);

                    free(aluno1);

                    printf("\nAluno: %d atualizado com sucesso!\n", id_aluno1);
                }


            } else {
                printf("\nO ID so pode conter numeros!\n");
            }


        } else {
            printf("\nNao existe aluno com o numero \"%d\".\n", id_aluno1);
        }
    } else {
        printf("\nO ID so pode conter numeros!\n");

    }


    fclose(bd_aluno1);

    printf("\nPressione <Enter> para continuar...");
    scanf("%*c");

    fseek(stdin, 0, SEEK_END);

}

void pesquisarAluno() {

    // função de pesquisar pelo num do aluno

    int numAluno;
    int encontrouAluno = 0;

    FILE *bd_aluno = fopen("aluno.bin", "rb");

    checkfile(bd_aluno);

    while (1) {
        fflush(stdin);
        printf("\nIntroduza o numero do aluno: ");
        if (scanf("%d", &numAluno) != 1) {
            printf("\n(Introduza apenas numeros)");
        } else {
            break;
        }
    }
    fflush(stdin);

    t_aluno aluno;

    while (1) {
        size_t result = fread(&aluno, sizeof(t_aluno), 1, bd_aluno);  /******/

        if (result == 0)
            break;


        int numAluno_aux;

        numAluno_aux = aluno.numero_aluno;

        if (numAluno_aux == numAluno) {
            printf("\nNome do aluno: %s\n", aluno.nome);
            printf("Numero do aluno: %d\n", aluno.numero_aluno);
            printf("Pais do aluno: %s\n", aluno.pais);
            printf("Modalidade de Pagamento (T = Total ou M = Mensal): %s\n", aluno.modalidadedePagamento);

            if ((strcmp(aluno.modalidadedePagamento, "M") == 0) || (strcmp(aluno.modalidadedePagamento, "m") == 0))
                printf("Numero de Mensalidades: %d\n\n", aluno.numPrestacoes);


            encontrouAluno = 1;
        }
    }

    if (encontrouAluno == 0)
        printf("Nenhum aluno encontrado.\n\n");

    fclose(bd_aluno);
    printf("Pressione <Enter> para continuar...");
    scanf("%*c");

    fseek(stdin, 0, SEEK_END);
}

void eliminarAluno() {

    //Função para eliminar o registo do aluno na BD

    char str_id_aluno[10];
    int id_aluno;


    printf("\nIntroduza o numero do aluno: ");
    scanf("%s", str_id_aluno);

    fseek(stdin, 0, SEEK_END);

    if (verificar_str(str_id_aluno) == 1) {

        sscanf(str_id_aluno, "%d", &id_aluno);

        FILE *bd_aluno = fopen("aluno.bin", "rb");

        checkfile(bd_aluno);

        if (existeAluno(bd_aluno, id_aluno) == 1) { // verifica se existe o ficheiro
            char nome_aluno[MAX];

            FILE *arq_temp = fopen("temp_aluno.bin", "a+b"); // criar um ficheiro temporario

            if (arq_temp == NULL) {
                printf("\nFalha ao criar o ficheiro temporario!\n");
                fclose(bd_aluno);
                exit(1);
            }
            rewind(bd_aluno);

            t_aluno aluno;
            while (1) {

                size_t result = fread(&aluno, sizeof(t_aluno), 1, bd_aluno);

                if (result == 0)
                    break;

                if (aluno.numero_aluno != id_aluno) {
                    fwrite(&aluno, sizeof(t_aluno), 1, arq_temp); // escreve no ficheiro temporario
                } else
                    strcpy(nome_aluno, aluno.nome);
            }

            fclose(bd_aluno);
            fclose(arq_temp);

            if (remove("aluno.bin") != 0)
                printf("\nErro ao eliminar o ficheiro \"aluno.bin\"\n");
            else {
                int r = rename("temp_aluno.bin", "aluno.bin");
                if (r != 0) {
                    printf("\nErro ao eliminar o ficheiro!\n");

                } else
                    printf("\nAluno: \"%s\" removido com sucesso!\n", nome_aluno);
            }
        } else {
            fclose(bd_aluno);
            printf("\nNao existe nenhum aluno com o numero: \"%d\".\n", id_aluno);
        }
    } else
        printf("\nO ID so pode conter numeros!\n");

    printf("\nPressione <Enter> para continuar...");
    scanf("%*c");
    fseek(stdin, 0, SEEK_END);
}

void notasdoAluno() {

    // função para listar as notas do aluno

    int numAluno;

    int encontrouNota = 0;

    FILE *bd_notas = fopen("avaliacao.bin", "rb");

    checkfile(bd_notas);

    // validação do input

    while (1) {
        printf("\nIntroduza o numero do aluno: ");
        fflush(stdin);
        if (scanf("%d", &numAluno) != 1) {
            printf("(Introduza apenas numeros)\n");
        } else {
            break;
        }
    }

    t_notas notas2;

    while (1) {
        size_t result = fread(&notas2, sizeof(t_notas), 1, bd_notas);

        if (result == 0)
            break;


        int numAluno_aux;

        numAluno_aux = notas2.numero_aluno;

        if (numAluno_aux == numAluno) {

            printf("\nCodigo da UC: %d\n", notas2.codigo_uCurricular);
            printf("Nota: %.2f\n", notas2.nota);
            encontrouNota = 1;
        }
    }

    if (encontrouNota == 0)
        printf("\nNenhuma nota registada para o aluno: %d.\n\n", numAluno);

    fflush(stdin);
    fclose(bd_notas);
    printf("Pressione <Enter> para continuar...");
    scanf("%*c");

    fseek(stdin, 0, SEEK_END);

}

void ucsdoAluno() {

    // função para listar Unidades curriculares do aluno

    int numAluno;

    int encontrouNota = 0;

    FILE *bd_matriculas = fopen("matriculas.bin", "rb");

    checkfile(bd_matriculas);

    while (1) {
        printf("\nIntroduza o numero do aluno: ");
        fflush(stdin);
        if (scanf("%d", &numAluno) != 1) {
            printf("(Introduza apenas numeros)\n");
        } else {
            break;
        }
    }
    fflush(stdin);
    t_matricula matricula;


    while (1) {
        size_t result = fread(&matricula, sizeof(t_matricula), 1, bd_matriculas);

        if (result == 0)
            break;


        int numAluno_aux;

        numAluno_aux = matricula.numero_aluno;

        if ((numAluno_aux == numAluno) && (strcmp(matricula.estado, "Matriculado") == 0)) {
            printf("\n----------| Matriculado |----------");
            nomeAluno(numAluno);
            nomeUC(matricula.codigo_uCurricular);
            printf("\nCodigo da UC: %d\n", matricula.codigo_uCurricular);
            printf("Ano letivo: %s\n\n", matricula.anolectivo);
            encontrouNota = 1;
        }
    }
    if (encontrouNota == 0)
        printf("Nenhuma matricula registada para o aluno: %d.\n\n", numAluno);

    fclose(bd_matriculas);
    printf("Pressione <Enter> para continuar...");
    scanf("%*c");

    fseek(stdin, 0, SEEK_END);

}


/////////////////// - UNIDADES CURRICULARES - ///////////////////

int existeUcurricular(FILE *bd_uCurricular, int id_uCurricular) {

    rewind(bd_uCurricular);

    t_uCurricular uCurricular;

    while (1) {
        size_t result = fread(&uCurricular, sizeof(t_uCurricular), 1, bd_uCurricular);

        if (result == 0)
            break;

        if (uCurricular.codigo_uCurricular == id_uCurricular)
            return 1;
    }
    return 0;
}

t_uCurricular *obterUcurricular(FILE *bd_uCurricular, int id_uCurricular) {

    rewind(bd_uCurricular);

    t_uCurricular *uCurricular;

    uCurricular = (t_uCurricular *) malloc(sizeof(t_uCurricular));

    while (1) {

        size_t result = fread(uCurricular, sizeof(t_uCurricular), 1, bd_uCurricular);

        if (result == 0) {
            free(uCurricular);
            return NULL;
        }

        if (uCurricular->codigo_uCurricular == id_uCurricular)
            break;
    }
    return uCurricular;
}

void atualizarUcurricular(FILE *bd_uCurricular, t_uCurricular *arqp_atualizar) {
    rewind(bd_uCurricular);

    t_uCurricular uCurricular;
    while (1) {

        size_t result = fread(&uCurricular, sizeof(t_uCurricular), 1, bd_uCurricular);

        if (result == 0)
            break;

        if (uCurricular.id == arqp_atualizar->id) {
            fseek(bd_uCurricular, (long int) -sizeof(t_uCurricular), SEEK_CUR);
            fwrite(arqp_atualizar, sizeof(t_uCurricular), 1, bd_uCurricular);
            break;
        }
    }
}

void registarUC() {

    FILE *bd_uc = fopen("uc.bin", "a+b");

    checkfile(bd_uc);

    int cont_bytes = 0;

    fseek(bd_uc, 0, SEEK_END);
    cont_bytes = ftell(bd_uc);

    t_uCurricular uc;

    if (cont_bytes == 0) {
        uc.id = 1;
    } else {
        t_uCurricular ultima_uc;

        fseek(bd_uc, cont_bytes - sizeof(t_uCurricular), SEEK_SET);

        fread(&ultima_uc, sizeof(t_uCurricular), 1, bd_uc);

        uc.id = ultima_uc.id + 1;
    }


    while (1) {
        printf("\nIntroduza o codigo da UC: ");
        fflush(stdin);
        if (scanf("%d", &uc.codigo_uCurricular) != 1) {
            printf("(Introduza apenas numeros)\n");
        } else if (existeUcurricular(bd_uc, uc.codigo_uCurricular) == 1) {
            printf("O codigo de UC ja existe!");
        } else {
            break;
        }
    }
    fflush(stdin);


    printf("\nIntroduza o nome da UC: ");
    gets(uc.nome_uc);

    while (1) {
        printf("\nIntroduza o Ano em que se realiza a UC (1,2,3): ");
        if (check123(gets(uc.ano), 3) == 0) {
            break;
        } else { printf("\nIntroduza um valor valido: 1,2 ou 3!\n"); }
    }

    while (1) {
        printf("\nIntroduza o Semestre em que se realiza a UC (1, 2): ");
        if (check123(gets(uc.semestre), 2) == 0) {
            break;
        } else { printf("\nIntroduza um valor valido: 1 ou 2!\n"); }
    }


    while (1) {
        printf("\nIntroduza o numero de ECTS: ");
        fflush(stdin);
        if (scanf("%d", &uc.ECTS) != 1) {
            printf("(Introduza apenas numeros)\n");
        } else {
            break;
        }
    }


    fflush(stdin);


    while (1) {
        printf("\nIntroduza a Area Cientifica da UC (I = Informatica, M = Matematica, F = Fisica): ");
        if (checkAreaCi(gets(uc.areaCientifica)) == 0) {
            break;
        } else { printf("\nIntroduza um valor valido (I = Informatica, M = Matematica, F = Fisica)\n"); }
    }


    printf("\nIntroduza o nome do docente:");
    gets(uc.nomeDocente);

    fseek(stdin, 0, SEEK_END);
    fseek(bd_uc, 0, SEEK_END);
    fwrite(&uc, sizeof(t_uCurricular), 1, bd_uc);

    fclose(bd_uc);

    printf("A UC: %s, com o ID:, %d e o Codigo UC: %d, lecionada no %s ano e no %s semestre, com o docente: %s, foi registada com sucesso!\n",
           uc.nome_uc, uc.id, uc.codigo_uCurricular, uc.ano, uc.semestre, uc.nomeDocente);
    printf("\nPressione <Enter> para continuar...");
    scanf("%*c");

    fseek(stdin, 0, SEEK_END);
}

void listaUcurricular() {
    FILE *bd_uCurricular = fopen("uc.bin", "rb");

    checkfile(bd_uCurricular);

    int encontrou_uc = 0;
    t_uCurricular uCurricular;

    while (1) {

        size_t result = fread(&uCurricular, sizeof(t_uCurricular), 1, bd_uCurricular);

        if (result == 0)
            break;

        encontrou_uc = 1;
        printf("\n-----------| UNIDADE CURRICULAR |-----------\n");

        printf("\nUnidade Curricular: %s", uCurricular.nome_uc);
        printf("\nCodigo UC: %d", uCurricular.codigo_uCurricular);
        printf("\nAno UC: %s", uCurricular.ano);
        printf("\nSemestre UC: %s", uCurricular.semestre);
        printf("\nArea Cientifica: %s", uCurricular.areaCientifica);
        printf("\nECTS: %d", uCurricular.ECTS);
        printf("\nDocente: %s\n\n", uCurricular.nomeDocente);
    }

    if (encontrou_uc == 0)
        printf("\nNao existe nenhuma UC registada.\n");


    fclose(bd_uCurricular);

    printf("\n\nPressione <Enter> para continuar...");
    scanf("%*c");

    fseek(stdin, 0, SEEK_END);
}

void editarUcurricular() {

    char str_id_uc[10];
    int id_uc;

    FILE *bd_uc = fopen("uc.bin", "rb+");

    checkfile(bd_uc);

    printf("\nIntroduza o codigo da Unidade Curricular: ");
    scanf("%s", str_id_uc);

    fflush(stdin);

    fseek(stdin, 0, SEEK_END);

    if (verificar_str(str_id_uc) == 1) {

        sscanf(str_id_uc, "%d", &id_uc);

        if (existeUcurricular(bd_uc, id_uc)) {


            if (verificar_str(str_id_uc) == 1) {


                sscanf(str_id_uc, "%d", &id_uc);

                t_uCurricular *uc = obterUcurricular(bd_uc, id_uc);

                if (uc != NULL) {

                    printf("\n-------| Atualizar Dados da Unidade Curricular |-------");
                    printf("\nIntroduza o nome: ");
                    gets(uc->nome_uc);

                    fflush(stdin);

                    while (1) {
                        printf("\nIntroduza o Ano em que se realiza a UC (1,2,3): ");
                        if (check123(gets(uc->ano), 3) == 0) {
                            break;
                        } else { printf("\nIntroduza um valor valido: 1,2 ou 3!\n"); }
                    }

                    while (1) {
                        printf("\nIntroduza o Semestre em que se realiza a UC (1, 2): ");
                        if (check123(gets(uc->semestre), 2) == 0) {
                            break;
                        } else { printf("\nIntroduza um valor valido: 1 ou 2!\n"); }
                    }


                    while (1) {
                        printf("\nIntroduza o numero de ECTS: ");
                        fflush(stdin);
                        if (scanf("%d", &uc->ECTS) != 1) {
                            printf("(Introduza apenas numeros)\n");
                        } else {
                            break;
                        }
                    }


                    fflush(stdin);


                    while (1) {
                        printf("\nIntroduza a Area Cientifica da UC (I = Informatica, M = Matematica, F = Fisica): ");
                        if (checkAreaCi(gets(uc->areaCientifica)) == 0) {
                            break;
                        } else {
                            printf("\nIntroduza um valor valido (I = Informatica, M = Matematica, F = Fisica)\n");
                        }
                    }


                    printf("\nIntroduza o nome do docente:");
                    gets(uc->nomeDocente);

                    fflush(stdin);
                    atualizarUcurricular(bd_uc, uc);
                    free(uc);
                    printf("\nUnidade Curricular: %d atualizada com sucesso!\n", id_uc);
                }

            } else {
                fflush(stdin);
                printf("\nO ID so pode conter numeros!\n");
            }


        } else {
            fflush(stdin);
            printf("\nNao nenhuma UC com o codigo: \"%d\".\n", id_uc);
        }
    } else {
        fflush(stdin);
        printf("\nO ID so pode conter numeros!\n");

    }
    fflush(stdin);
    fclose(bd_uc);
    printf("\nPressione <Enter> para continuar...");
    scanf("%*c");

    fseek(stdin, 0, SEEK_END);

}

void pesquisarUcurricular() {

    int codUC;

    int encontouuCurricular = 0;

    FILE *bd_uCurricular = fopen("uc.bin", "rb");

    checkfile(bd_uCurricular);


    while (1) {
        printf("\nIntroduza o codigo da Unidade Curricular: ");
        fflush(stdin);
        if (scanf("%d", &codUC) != 1) {
            printf("(Introduza apenas numeros)\n");
        } else {
            break;
        }
    }


    t_uCurricular uCurricular;

    while (1) {
        size_t result = fread(&uCurricular, sizeof(t_uCurricular), 1, bd_uCurricular);

        if (result == 0)
            break;

        if (codUC == uCurricular.codigo_uCurricular) {
            printf("\n----------| Resultado da Pesquisa |----------\n");
            printf("ID da UC: %d\n", uCurricular.id);
            printf("Codigo da UC: %d\n", uCurricular.codigo_uCurricular);
            printf("Nome da UC: %s\n", uCurricular.nome_uc);
            printf("Ano da UC: %s\n", uCurricular.ano);
            printf("Semestre da UC: %s\n", uCurricular.semestre);
            printf("Area Cientifica da UC: %s\n", uCurricular.areaCientifica);
            printf("ECTS: %d\n", uCurricular.ECTS);
            printf("Docente da UC: %s\n\n", uCurricular.nomeDocente);
            fflush(stdin);
            encontouuCurricular = 1;
        }
    }

    if (encontouuCurricular == 0) {
        fflush(stdin);
        printf("\nNenhuma UC encontrada.\n\n");
    }

    fclose(bd_uCurricular);
    printf("Pressione <Enter> para continuar...");
    scanf("%*c");

    fseek(stdin, 0, SEEK_END);
}

void eliminarUcurricular() {

    char str_id_uCurricular[10];
    int id_uCurricular;

    printf("\nIntroduza o codigo da Unidade Curricular: ");
    scanf("%10s%*c", str_id_uCurricular);

    fseek(stdin, 0, SEEK_END);

    if (verificar_str(str_id_uCurricular) == 1) {

        sscanf(str_id_uCurricular, "%d", &id_uCurricular);

        FILE *bd_uCurricular = fopen("uc.bin", "rb");

        if (bd_uCurricular == NULL) {
            printf("\nFalha ao abrir arquivo(s)!\n");
            exit(1);
        }

        if (existeUcurricular(bd_uCurricular, id_uCurricular) == 1) {
            char nome_uCurricular[MAX];
            FILE *arq_temp = fopen("temp_uc.bin", "a+b");
            if (arq_temp == NULL) {
                printf("\nFalha ao criar arquivo temporario!\n");
                fclose(bd_uCurricular);
                exit(1);
            }
            rewind(bd_uCurricular);

            t_uCurricular uCurricular;
            while (1) {

                size_t result = fread(&uCurricular, sizeof(t_uCurricular), 1, bd_uCurricular);

                if (result == 0)
                    break;

                if (uCurricular.codigo_uCurricular != id_uCurricular) {
                    fwrite(&uCurricular, sizeof(t_uCurricular), 1, arq_temp);
                } else
                    strcpy(nome_uCurricular, uCurricular.nome_uc);
            }

            fclose(bd_uCurricular);
            fclose(arq_temp);

            if (remove("uc.bin") != 0)
                printf("\nErro ao Eliminar o ficheiro \"aluno.bin\"\n");
            else {
                int r = rename("temp_uc.bin", "uc.bin");
                if (r != 0) {
                    printf("\nNao tem permissao para alterar o nome do ficheiro!\n");
                    printf("Feche o programa e o arquivo \"temp_uc.bin.bin\" e altere o nome manualmente para \"uc.bin\"\n");
                } else
                    printf("\nUnidade Curricular: \"%s\" removida com sucesso!\n", nome_uCurricular);
            }
        } else {
            fclose(bd_uCurricular);
            printf("\nNao existe UC com o ID \"%d\".\n", id_uCurricular);
        }
    } else
        printf("\nO ID so pode conter numeros!\n");

    printf("\nPressione <Enter> para continuar...");
    scanf("%*c");
    fseek(stdin, 0, SEEK_END);
}


/////////////////// - DOCENTES - ///////////////////

void listaDocentes() {
    FILE *bd_uCurricular = fopen("uc.bin", "rb");


    if (bd_uCurricular == NULL) {
        printf("\nFalha ao abrir o ficheiro ou ");
        printf("Nenhuma UC registada.\n");
        printf("\nPressione <Enter> para continuar...");
        scanf("%*c");

        fseek(stdin, 0, SEEK_END);
        return;
    }

    int encontrou_uc = 0;
    t_uCurricular uCurricular;

    while (1) {

        size_t result = fread(&uCurricular, sizeof(t_uCurricular), 1, bd_uCurricular);

        if (result == 0)
            break;

        encontrou_uc = 1;
        printf("\n-----------| Lista Docentes |-----------\n");
        printf("\nDocente: %s", uCurricular.nomeDocente);
        printf("\nLeciona: %s, Ano: %s, Semestre: %s\n", uCurricular.nome_uc, uCurricular.ano, uCurricular.semestre);

    }

    if (encontrou_uc == 0)
        printf("\nNao existe nenhuma docente registado.\n");


    fclose(bd_uCurricular);

    printf("\n\nPressione <Enter> para continuar...");
    scanf("%*c");

    fseek(stdin, 0, SEEK_END);
}

void ucsdoDocente() {

    char nome[MAX];

    int encontouuCurricular = 0;

    FILE *bd_uCurricular = fopen("uc.bin", "rb");

    if (bd_uCurricular == NULL) {
        printf("\nFalha ao abrir o ficheiro!\n");
        exit(1);
    }

    printf("\nDigite o nome do docente: ");
    gets(nome);

    //printf("\nUC  com o nome \"%s\":\n\n", nome);

    t_uCurricular uCurricular;
    while (1) {
        size_t result = fread(&uCurricular, sizeof(t_uCurricular), 1, bd_uCurricular);

        if (result == 0)
            break;

        char nome_aux[MAX];
        strcpy(nome_aux, uCurricular.nomeDocente);

        if (strcmp(strupr(nome_aux), strupr(nome)) == 0) {
            printf("\n----------| Resultado da Pesquisa |----------\n");
            // printf("ID da UC: %d\n", uCurricular.id);
            printf("Codigo da UC: %d\n", uCurricular.codigo_uCurricular);
            printf("Nome da UC: %s\n", uCurricular.nome_uc);
            printf("Ano da UC: %s\n", uCurricular.ano);
            printf("Semestre da UC: %s\n", uCurricular.semestre);
            printf("Area Cientifica da UC: %s\n\n", uCurricular.areaCientifica);
            printf("ECTS: %d\n\n", uCurricular.ECTS);

            encontouuCurricular = 1;
        }
    }

    if (encontouuCurricular == 0)
        printf("Nenhuma UC do docente %s encontrada.\n\n", nome);

    fclose(bd_uCurricular);
    printf("Pressione <Enter> para continuar...");
    scanf("%*c");

    fseek(stdin, 0, SEEK_END);
}


/////////////////// - NOTAS - ///////////////////

int existeNota(FILE *bd_notas, int id_aluno, int codUC) {

    rewind(bd_notas);

    t_notas notas;

    while (1) {
        size_t result = fread(&notas, sizeof(t_notas), 1, bd_notas);

        if (result == 0)
            break;

        if ((notas.numero_aluno == id_aluno) && (notas.codigo_uCurricular == codUC))
            return 1;
    }
    return 0;
}

t_notas *obterNota(FILE *bd_aluno, int id_aluno) {

    rewind(bd_aluno);

    t_notas *notas;

    notas = (t_notas *) malloc(sizeof(t_notas));

    while (1) {

        size_t result = fread(notas, sizeof(t_notas), 1, bd_aluno);

        if (result == 0) {
            free(notas);
            return NULL;
        }

        if (notas->numero_aluno == id_aluno)
            break;
    }
    return notas;
}

void atualizarNOta(FILE *bd_aluno, t_aluno *arqp_atualizar) {
    rewind(bd_aluno);

    t_aluno aluno1;
    while (1) {

        size_t result = fread(&aluno1, sizeof(t_aluno), 1, bd_aluno);

        if (result == 0)
            break;

        if (aluno1.id == arqp_atualizar->id) {
            fseek(bd_aluno, sizeof(t_aluno), SEEK_CUR);
            fwrite(arqp_atualizar, sizeof(t_aluno), 1, bd_aluno);
            break;
        }
    }
}

void listaNotas() {
    FILE *bd_notas = fopen("avaliacao.bin", "rb");

    if (bd_notas == NULL) {
        printf("\nErro ao tentar abrir o ficheiro!");
        printf("\nPressione <Enter> para continuar...");
        scanf("%*c");

        fseek(stdin, 0, SEEK_END);
        return;
    }

    int encontrou_notas = 0;
    t_notas notas;

    while (1) {
        size_t result = fread(&notas, sizeof(t_notas), 1, bd_notas);

        if (result == 0)
            break;

        encontrou_notas = 1;

        printf("\nNum do Aluno: %d\n", notas.numero_aluno);
        printf("Codigo da UC: %d\n", notas.codigo_uCurricular);
        printf("Nota: %.2f\n", notas.nota);


    }

    if (encontrou_notas == 0)
        printf("\nNao existe notas lancadas.\n");

    fclose(bd_notas);

    printf("\nPressione <Enter> para continuar...");
    scanf("%*c");
    fseek(stdin, 0, SEEK_END);
    fflush(stdin);
}

void lancarAvaliacao() {

    FILE *bd_avaliacao = fopen("avaliacao.bin", "a+b");
    FILE *bd_matricula = fopen("matriculas.bin", "a+b");

    checkfile(bd_avaliacao);
    checkfile(bd_matricula);

    int cont_bytes = 0;

    fseek(bd_avaliacao, 0, SEEK_END);
    cont_bytes = ftell(bd_avaliacao);

    t_notas avaliacao;

    if (cont_bytes == 0) {
        avaliacao.id = 1;
    } else {
        t_notas ultima_avaliacao;

        fseek(bd_avaliacao, cont_bytes - sizeof(t_notas), SEEK_SET);

        fread(&ultima_avaliacao, sizeof(t_notas), 1, bd_avaliacao);

        avaliacao.id = ultima_avaliacao.id + 1;

    }


    printf("\nIntroduza o Numero do Aluno: ");
    scanf("%d", &avaliacao.numero_aluno);
    printf("\nIntroduza o codigo da UC: ");
    scanf("%d", &avaliacao.codigo_uCurricular);

    if ((existeMatricula(bd_matricula, avaliacao.numero_aluno, avaliacao.codigo_uCurricular) == 1)) {
        printf("\nIntroduza a Nota: ");
        scanf("%f", &avaliacao.nota);

        fflush(stdin);

        fseek(stdin, 0, SEEK_END);
        fseek(bd_avaliacao, 0, SEEK_END);
        fwrite(&avaliacao, sizeof(t_notas), 1, bd_avaliacao);

        printf("Foi registada a nota de: %.2f do aluno n: %d, na UC:%d\n", avaliacao.nota, avaliacao.numero_aluno,
               avaliacao.codigo_uCurricular);


    } else {

        printf("\nO aluno %d nao esta matriculado na UC: %d\n", avaliacao.numero_aluno, avaliacao.codigo_uCurricular);

    }

    fclose(bd_avaliacao);
    fclose(bd_matricula);
    fflush(stdin);
    printf("\nPressione <Enter> para continuar...");
    scanf("%*c");

    fseek(stdin, 0, SEEK_END);


}

void eliminarNota() {

    char str_id_aluno[10];
    char str_id_uc[10];
    int id_aluno;
    int id_uc;


    printf("\nIntroduza o numero do aluno: ");
    scanf("%s", str_id_aluno);

    printf("\nIntroduza o Codigo da UC: ");
    scanf("%s", str_id_uc);

    fseek(stdin, 0, SEEK_END);

    if ((verificar_str(str_id_aluno) == 1) || (verificar_str(str_id_uc) == 1)) {

        sscanf(str_id_aluno, "%d", &id_aluno);
        sscanf(str_id_uc, "%d", &id_uc);

        FILE *bd_avaliacao = fopen("avaliacao.bin", "rb");

        checkfile(bd_avaliacao);

        if (existeNota(bd_avaliacao, id_aluno, id_uc) == 1) {
   //         char nome_aluno[MAX];
            FILE *arq_temp = fopen("temp_avaliacao.bin", "a+b");

            if (arq_temp == NULL) {
                printf("\nFalha ao criar o ficheiro temporario!\n");
                fclose(bd_avaliacao);
                exit(1);
            }
            rewind(bd_avaliacao);

            t_notas notas;
            while (1) {

                size_t result = fread(&notas, sizeof(t_notas), 1, bd_avaliacao);

                if (result == 0)
                    break;

                if ((notas.numero_aluno != id_aluno) && (notas.codigo_uCurricular != id_uc)) {
                    fwrite(&notas, sizeof(t_notas), 1, arq_temp);
                }
            }
            //else{                    strcpy(nome_aluno, notas);            }

            fclose(bd_avaliacao);
            fclose(arq_temp);

            if (remove("avaliacao.bin") != 0)
                printf("\nErro ao eliminar o ficheiro \"avaliacao.bin\"\n");
            else {

                int r = rename("temp_avaliacao.bin", "avaliacao.bin");
                if (r != 0) {
                    printf("\nErro ao eliminar o ficheiro!\n");

                } else {
                    printf("\nNota removida com sucesso!\n");
                }

                    fclose(bd_avaliacao);
                    printf("\nNao existe nehuma nota lançada aluno com o numero: \"%d\".\n", id_aluno);

            }
        } else {
            printf("\nO ID so pode conter numeros!\n");
        }}

        printf("\nPressione <Enter> para continuar...");
        scanf("%*c");
        fseek(stdin, 0, SEEK_END);
    }


/////////////////// - Matriculas - ///////////////////

t_matricula *obterMatricula(FILE *bd_matricula, int id_aluno, int codUc) {

        rewind(bd_matricula);

        t_matricula *matricula;

        matricula = (t_matricula *) malloc(sizeof(t_matricula));

        while (1) {

            size_t result = fread(matricula, sizeof(t_matricula), 1, bd_matricula);

            if (result == 0) {
                free(matricula);
                return NULL;
            }

            if (matricula->numero_aluno == id_aluno && matricula->codigo_uCurricular == codUc)
                break;
        }
        return matricula;
    }

void atualizarMatricula(FILE *bd_matricula, t_matricula *arqp_atualizar) {
        rewind(bd_matricula);

        t_matricula matricula;
        while (1) {

            size_t result = fread(&matricula, sizeof(t_matricula), 1, bd_matricula);

            if (result == 0)
                break;

            if ((matricula.numero_aluno == arqp_atualizar->numero_aluno) &&
                (matricula.codigo_uCurricular == arqp_atualizar->codigo_uCurricular)) {
                fseek(bd_matricula, (long int) -sizeof(t_matricula), SEEK_CUR);
                fwrite(arqp_atualizar, sizeof(t_matricula), 1, bd_matricula);
                break;
            }
        }
    }

int existeMatricula(FILE *bd_matricula, int id_aluno, int codUc) {

        rewind(bd_matricula);

        t_matricula matricula;

        while (1) {
            size_t result = fread(&matricula, sizeof(t_matricula), 1, bd_matricula);

            if (result == 0)
                break;

            if (matricula.numero_aluno == id_aluno && matricula.codigo_uCurricular == codUc)
                return 1;
        }
        return 0;
    }

void matricularAluno() {

        FILE *bd_matricula = fopen("matriculas.bin", "a+b");
        FILE *bd_aluno = fopen("aluno.bin", "a+b");
        FILE *bd_uc = fopen("uc.bin", "a+b");

        checkfile(bd_matricula);
        checkfile(bd_aluno);
        checkfile(bd_uc);

        int cont_bytes = 0;

        fseek(bd_matricula, 0, SEEK_END);
        cont_bytes = ftell(bd_matricula);

        t_matricula matricula;

        if (cont_bytes == 0) {
            matricula.id = 1;
        } else {
            t_matricula ultima_matricula;

            fseek(bd_matricula, cont_bytes - sizeof(t_notas), SEEK_SET);

            fread(&ultima_matricula, sizeof(t_notas), 1, bd_matricula);

            matricula.id = ultima_matricula.id + 1;
        }

        char voltar;

        while (1) {
            fflush(stdin);
            printf("\nIntroduza o numero do aluno: ");
            if (scanf("%d", &matricula.numero_aluno) != 1) {
                printf("\n(Erro! Introduza apenas numeros)");
                fflush(stdin);
                printf("\n\nintroduza <c> para continuar ou <s> para regressar ao menu anterior...\n");
                scanf("%s", &voltar);
                fflush(stdin);
                if (strcmp(&voltar, "s") == 0) {
                    return;
                }
            } else {
                if (existeAluno(bd_aluno, matricula.numero_aluno) == 1) {
                    break;
                } else {
                    printf("\nO aluno com o n: %d, nao esta registado!\n", matricula.numero_aluno);
                    fflush(stdin);
                    printf("\nPressione <Enter> para voltar ao menu anterior...");
                    scanf("%*c");
                    return;
                }

            }
        }

        char voltar1;
        while (1) {
            fflush(stdin);
            printf("\nIntroduza o codigo da UC: ");
            if (scanf("%d", &matricula.codigo_uCurricular) != 1) {
                printf("\n(Erro! Introduza apenas numeros)");
                fflush(stdin);
                printf("\n\nintroduza <c> para continuar ou <s> para regressar ao menu anterior...\n");
                scanf("%s", &voltar1);
                fflush(stdin);
                if (strcmp(&voltar1, "s") == 0) {
                    return;
                }
            } else {
                if (existeUcurricular(bd_uc, matricula.codigo_uCurricular) == 1) {
                    break;
                } else {
                    printf("\nA UC com o n: %d, nao esta registada!\n", matricula.numero_aluno);
                    fflush(stdin);
                    printf("\nPressione <Enter> para voltar ao menu anterior...");
                    scanf("%*c");
                    return;
                }

            }
        }
        fflush(stdin);
        printf("\nIntroduza o ano letivo: ");
        gets(matricula.anolectivo);

        strcpy(matricula.estado, "Matriculado");

        fseek(stdin, 0, SEEK_END);
        fseek(bd_matricula, 0, SEEK_END);
        fwrite(&matricula, sizeof(t_matricula), 1, bd_matricula);

        fclose(bd_matricula);
        fclose(bd_aluno);
        fclose(bd_uc);


        printf("O aluno n:%d,foi matriculado com sucesso na UC:%d no ano letivo: %s\n", matricula.numero_aluno,
               matricula.codigo_uCurricular, matricula.anolectivo);
        printf("\nPressione <Enter> para continuar...");
        scanf("%*c");

        fseek(stdin, 0, SEEK_END);
    }

void listaMatriculas() {
        FILE *bd_matriculas = fopen("matriculas.bin", "rb");

        checkfile(bd_matriculas);


        int encontrou_matricula = 0;
        t_matricula matricula;

        while (1) {
            size_t result = fread(&matricula, sizeof(t_matricula), 1, bd_matriculas);

            if (result == 0)
                break;


            if (strcmp(matricula.estado, "Matriculado") == 0) {
                printf("\n----------| Matriculas |----------");
                nomeAluno(matricula.numero_aluno);
                printf("\nNum Aluno: %d", matricula.numero_aluno);
                nomeUC(matricula.codigo_uCurricular);
                printf("\nCodigo da UC: %d\n", matricula.codigo_uCurricular);
                printf("Ano letivo: %s\n", matricula.anolectivo);
                printf("Estado: %s\n\n", matricula.estado);
                encontrou_matricula = 1;
            }

        }

        if (encontrou_matricula == 0)
            printf("\nNao existe matriculas registadas.\n");

        fclose(bd_matriculas);

        printf("\nPressione <Enter> para continuar...");
        scanf("%*c");

        fseek(stdin, 0, SEEK_END);
    }

void editarMatricula() {

        char str_id_uc[10];
        char str_id_aluno[10];
        int id_uc;
        int id_aluno;

        FILE *bd_matricula = fopen("matriculas.bin", "rb+");

        checkfile(bd_matricula);

        printf("\nIntroduza o numero de aluno: ");
        scanf("%s", str_id_aluno);

        printf("\nIntroduza o codigo da Unidade Curricular: ");
        scanf("%s", str_id_uc);


        fflush(stdin);

        fseek(stdin, 0, SEEK_END);

        if ((verificar_str(str_id_uc) == 1) && (verificar_str(str_id_aluno) == 1)) {

            sscanf(str_id_uc, "%d", &id_uc);
            sscanf(str_id_aluno, "%d", &id_aluno);

            if (existeMatricula(bd_matricula, id_aluno, id_uc)) {


                if (verificar_str(str_id_uc) == 1) {


                    sscanf(str_id_uc, "%d", &id_uc);

                    t_matricula *matricula = obterMatricula(bd_matricula, id_aluno, id_uc);

                    if (matricula != NULL) {

                        printf("\n-------| Atualizar Matricula |-------");

                        while (1) {
                            printf("\nIntroduza o Numero de Aluno: ");
                            if (scanf("%d", &matricula->numero_aluno) != 1) {
                                printf("(Introduza apenas numeros)\n");
                                fflush(stdin);
                            } else {
                                break;
                            }
                        }
                        fflush(stdin);

                        while (1) {
                            printf("\nIntroduza o codigo da Unidade Curricular: ");
                            if (scanf("%d", &matricula->codigo_uCurricular) != 1) {
                                printf("(Introduza apenas numeros)\n");
                                fflush(stdin);
                            } else {
                                break;
                            }
                        }
                        fflush(stdin);

                        printf("\nIntroduza o Ano letivo: ");
                        scanf("%s", matricula->anolectivo);
                        fflush(stdin);

                        atualizarMatricula(bd_matricula, matricula);
                        free(matricula);
                        printf("\nMatricula atualizada com sucesso!\n");
                    }

                } else {
                    fflush(stdin);
                    printf("\nO ID so pode conter numeros!\n");
                }


            } else {
                fflush(stdin);
                printf("\nO aluno n: %d nao tem nenhuma matricula na UC: %d.\n", id_aluno, id_uc);
            }
        } else {
            fflush(stdin);
            printf("\nO ID so pode conter numeros!\n");

        }
        fflush(stdin);
        fclose(bd_matricula);
        printf("\nPressione <Enter> para continuar...");
        scanf("%*c");

        fseek(stdin, 0, SEEK_END);

    }

void anularMatricula() {

        char str_id_uc[10];
        char str_id_aluno[10];
        int id_uc;
        int id_aluno;

        FILE *bd_matricula = fopen("matriculas.bin", "rb+");

        checkfile(bd_matricula);

        printf("\nIntroduza o numero de aluno: ");
        scanf("%s", str_id_aluno);

        printf("\nIntroduza o codigo da Unidade Curricular: ");
        scanf("%s", str_id_uc);


        fflush(stdin);

        fseek(stdin, 0, SEEK_END);

        if ((verificar_str(str_id_uc) == 1) && (verificar_str(str_id_aluno) == 1)) {

            sscanf(str_id_uc, "%d", &id_uc);
            sscanf(str_id_aluno, "%d", &id_aluno);

            if (existeMatricula(bd_matricula, id_aluno, id_uc)) {


                if (verificar_str(str_id_uc) == 1) {


                    sscanf(str_id_uc, "%d", &id_uc);

                    t_matricula *matricula = obterMatricula(bd_matricula, id_aluno, id_uc);

                    if (matricula != NULL) {

                        printf("\n-------| Anular Matricula a UC |-------");

                        /*  while (1) {
                              printf("\nIntroduza o Numero de Aluno: ");
                              if (scanf("%d", &matricula->numero_aluno) != 1) {
                                  printf("(Introduza apenas numeros)\n");
                                  fflush(stdin);
                              } else {
                                  break;
                              }
                          }
                          fflush(stdin);

                          while (1) {
                              printf("\nIntroduza o codigo da Unidade Curricular: ");
                              if (scanf("%d", &matricula->codigo_uCurricular) != 1) {
                                  printf("(Introduza apenas numeros)\n");
                                  fflush(stdin);
                              } else {
                                  break;
                              }
                          }
                          fflush(stdin);*/

                        strcpy(matricula->estado, "Anulado");

                        atualizarMatricula(bd_matricula, matricula);
                        free(matricula);
                        printf("\nMatricula atualizada com sucesso!\n");
                    }

                } else {
                    fflush(stdin);
                    printf("\nO ID so pode conter numeros!\n");
                }


            } else {
                fflush(stdin);
                printf("\nO aluno n: %d nao tem nenhuma matricula na UC: %d.\n", id_aluno, id_uc);
            }
        } else {
            fflush(stdin);
            printf("\nO ID so pode conter numeros!\n");

        }
        fflush(stdin);
        fclose(bd_matricula);
        printf("\nPressione <Enter> para continuar...");
        scanf("%*c");

        fseek(stdin, 0, SEEK_END);

    }

void listaMatriculasAnuladas() {

        FILE *bd_matriculas = fopen("matriculas.bin", "rb");

        checkfile(bd_matriculas);

        int encontrou_matricula = 0;
        t_matricula matricula;

        while (1) {
            size_t result = fread(&matricula, sizeof(t_matricula), 1, bd_matriculas);

            if (result == 0)
                break;

            if (strcmp(matricula.estado, "Anulado") == 0) {
                printf("----------| Matricula Anuladas |----------");
                nomeAluno(matricula.numero_aluno);
                nomeUC(matricula.codigo_uCurricular);
                printf("\nCodigo da UC: %d\n", matricula.codigo_uCurricular);
                printf("Ano letivo: %s\n\n", matricula.anolectivo);

            }

            encontrou_matricula = 1;

        }

        if (encontrou_matricula == 0)
            printf("\nNão existe matriculas anuladas.\n");

        fclose(bd_matriculas);

        printf("\nPressione <Enter> para continuar...");
        scanf("%*c");

        fseek(stdin, 0, SEEK_END);
    }

