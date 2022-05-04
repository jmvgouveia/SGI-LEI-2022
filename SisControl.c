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

#include "SisControl.h"

int checknumPrestacoes(int numero) {

    if (numero < 2 || numero > 10) {
        printf("(Introduza um valor Valido, valor entre 2 e 10)\n");
        return 1;
    } else {
        return 0;
    }
}

void checkfile(FILE *file) {

    if (file == NULL) {
        printf("\nFalha ao abrir o ficheiro!\n");
        return;//exit(1);
    }


}

int verificar_str(char str[]) {
    int len_str = strlen(str);

    for (int i = 0; i < len_str; i++) {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }
    return 1;
}

int check123(char str[], int nums) {


    if (nums == 3){
        if (strcmp(str, "1") == 0 || strcmp(str, "2") == 0 || strcmp(str, "3") == 0) {
            return 0;
        }

    }else if (nums ==2){

        if (strcmp(str, "1") == 0 || strcmp(str, "2") == 0 ) {
            return 0;
        }
    }


    return 1;

}

int checkAreaCi(char str[]) {


        if (strcmp(str, "I") == 0 || strcmp(str, "M") == 0 || strcmp(str, "F") == 0) {
            return 0;
        }
    return 1;

}

void calcpropinaporEcts() {

    int ects = 0;
    int ano = 0;
    char pais[MAX];
    float propina;
    float valorects;
    float valorectsinsc;
    char modalidadepagamento[2];

    printf("\nIntroduza o Numero de ECTS:");
    scanf("%d", &ects);
    printf("Introduza o Ano:");
    scanf("%d", &ano);
    fflush(stdin);
    printf("Introduza o Pais :");
    gets(pais);

    printf("Introduza a modalidade de pagamento (T = Total ou M = Mensalidade): ");
    gets(modalidadepagamento);


    if (ano == 1) {
        if (ects > 60) {
            printf("Nao e permitido ter mais do que 60 ECTS no %d", ano);
        } else {

            if (strcmp(pais, "PT") == 0 || strcmp(pais, "Portugal") == 0) {

                if (strcmp(modalidadepagamento, "T") == 0) {

                    valorects = 15 * ects;
                    propina = valorects + 80;
                    valorects = 15 * ects;
                    printf("\n-------| Info Pagamento |-------");
                    printf("\n\nValor de inscricao: 80 euros");
                    printf("\nValor das ECTS: %.2f euros", valorects);
                    printf("\n\nValor Total da propina: %.2f euros\n", propina);

                } else {
                    valorects = (15 * ects) / 10;
                    valorectsinsc = (15 * ects) / 10 + 80;
                    propina = (valorects * 9) + valorectsinsc;
                    printf("\n-------| Info Pagamento |-------");
                    printf("\n\nValor de inscricao: 80 euros");
                    printf("\nValor da 1 Mensalidade: %.2f", valorectsinsc);
                    printf("\nValor das restantes Mensalidade: %.2f", valorects);
                    printf("\n\nValor Total da propina: %.2f euros\n", propina);

                }


            } else {
                valorects = 18 * ects;
                propina = valorects + 96;
                printf("\n-------| Info Pagamento |-------");
                printf("\n\nValor de inscricao: 96 euros");
                printf("\nValor das ECTS: %.2f euros", valorects);
                printf("\n\nValor Total da propina: %.2f euros\n", propina);

            }
        }

    } else {
        if (ects > 84) {
            printf("Nao e permitido ter mais do que 84 ECTS no %d", ano);
        } else {
            if (strcmp(pais, "PT") == 0 || strcmp(pais, "Portugal") == 0) {
                valorects = 15 * ects;
                //propina = valorects + 80;
                printf("\n-------| Info Pagamento |-------");
                printf("\n\nNumero de ECTS: %d", ects);
                printf("\n\nValor Total da propina: %.2f euros", valorects);

            } else {
                valorects = 18 * ects;
                printf("\n-------| Info Pagamento |-------");
                printf("\n\nNumero de ECTS: %d", ects);
                printf("\n\nValor Total da propina: %.2f euros", valorects);
            }

        }

    }


    printf("\nPressione <Enter> para continuar...");
    scanf("%*c");

}

void calcpropina(int ects, int ano, char pais[], char modalidadepagamento[], int numPrestacoes) {

    float propina;
    float valorects;
    float inscricao;
    float mensalidade;

    if (ano == 1) {
        if (ects > 60) {
            printf("Nao e permitido ter mais do que 60 ECTS no %d", ano);
        } else {

            if (strcmp(pais, "PT") == 0 || strcmp(pais, "Portugal") == 0) {

                if (strcmp(modalidadepagamento, "T") == 0) {

                    inscricao = 80;
                    valorects = 15 * ects;
                    propina = valorects + inscricao;
                    printf("\n-------| Info Pagamento |-------");
                    printf("\nModalidade de Pagamento (T = Total ou M = Mensal): %s", modalidadepagamento);
                    printf("\n\nValor de inscricao: %.2f euros", inscricao);
                    printf("\nValor das ECTS: %.2f euros", valorects);
                    printf("\n\nValor Total da propina: %.2f euros\n", propina);

                } else {

                    valorects = (15 * ects);
                    mensalidade = valorects / numPrestacoes;
                    inscricao = 80;
                    propina = valorects + inscricao;
                    printf("\n-------| Info Pagamento |-------");
                    printf("\nModalidade de Pagamento (T = Total ou M = Mensal): %s", modalidadepagamento);
                    printf("\nNumero de Mensalidades: %d", numPrestacoes);
                    printf("\n\nValor de inscricao: %.2f euros", inscricao);
                    printf("\nValor da 1 Mensalidade: %.2f", mensalidade + inscricao);
                    printf("\nValor das restantes Mensalidade: %.2f", mensalidade);
                    printf("\n\nValor Total da propina: %.2f euros\n", propina);

                }


            } else {

                if (strcmp(modalidadepagamento, "T") == 0) {

                    inscricao = 96;
                    valorects = 18 * ects;
                    propina = valorects + inscricao;
                    printf("\n-------| Info Pagamento |-------");
                    printf("\nModalidade de Pagamento (T = Total ou M = Mensal): %s", modalidadepagamento);
                    printf("\n\nValor de inscricao: %.2f euros", inscricao);
                    printf("\nValor das ECTS: %.2f euros", valorects);
                    printf("\n\nValor Total da propina: %.2f euros\n", propina);

                } else {

                    valorects = (18 * ects);
                    mensalidade = valorects / numPrestacoes;
                    inscricao = 96;
                    propina = valorects + inscricao;
                    printf("\n-------| Info Pagamento |-------");
                    printf("\nModalidade de Pagamento (T = Total ou M = Mensal): %s", modalidadepagamento);
                    printf("\nNumero de Mensalidades: %d", numPrestacoes);
                    printf("\n\nValor de inscricao: %.2f euros", inscricao);
                    printf("\nValor da 1 Mensalidade: %.2f", mensalidade + inscricao);
                    printf("\nValor das restantes Mensalidade: %.2f", mensalidade);
                    printf("\n\nValor Total da propina: %.2f euros\n", propina);


                }
            }
        }

    } else {
        if (ects > 84) {
            printf("Nao e permitido ter mais do que 84 ECTS no %d", ano);
        } else {

            if (strcmp(pais, "PT") == 0 || strcmp(pais, "Portugal") == 0) {

                if (strcmp(modalidadepagamento, "T") == 0) {
                    valorects = 15 * ects;
                    printf("\n-------| Info Pagamento |-------");
                    printf("\n\nNumero de ECTS: %d", ects);
                    printf("\n\nValor Total da propina: %.2f euros", valorects);
                } else {
                    valorects = 15 * ects;
                    mensalidade = valorects / numPrestacoes;
                    printf("\n-------| Info Pagamento |-------");
                    printf("\n\nNumero de Mensalidades: %d", numPrestacoes);
                    printf("\n\nValor da Mensalidade: %.2f", mensalidade);
                    printf("\n\nValor Total da propina: %.2f euros", valorects);

                }
            } else {
                if (strcmp(modalidadepagamento, "T") == 0) {
                    valorects = 18 * ects;
                    printf("\n-------| Info Pagamento |-------");
                    printf("\n\nNumero de ECTS: %d", ects);
                    printf("\n\nValor Total da propina: %.2f euros", valorects);
                } else {
                    valorects = 18 * ects;
                    mensalidade = valorects / numPrestacoes;
                    printf("\n-------| Info Pagamento |-------");
                    printf("\n\nNumero de Mensalidades: %d", numPrestacoes);
                    printf("\n\nValor da Mensalidade: %.2f", mensalidade);
                    printf("\n\nValor Total da propina: %.2f euros", valorects);

                }
            }

        }

    }

}

void calcpropinadoAluno() {


    int ects = 0;
    char pais[MAX];
    int numAluno;

    int encontrouECTS = 0;
    int encontrouALUNO = 0;
    char modalidade[10];
    int numPrestacoes;


    FILE *bd_matriculas = fopen("matriculas.bin", "rb");
    checkfile(bd_matriculas);
    FILE *bd_aluno = fopen("aluno.bin", "rb");
    checkfile(bd_aluno);

    t_matricula matricula;
    t_aluno aluno;


    while (1) {
        printf("\nIntroduza o numero do aluno: ");
        fflush(stdin);
        if (scanf("%d", &aluno.numero_aluno) != 1) {
            printf("(Introduza apenas numeros)\n");
        } else if (existeAluno(bd_aluno, aluno.numero_aluno) == 1) {
            numAluno=aluno.numero_aluno;
            break;
        } else {

        }
    }
    fflush(stdin);


   /* printf("\nIntroduza o numero do aluno: ");
    scanf("%d", &numAluno);
    fflush(stdin);*/



    while (1) {
        size_t resultaluno = fread(&aluno, sizeof(t_aluno), 1, bd_aluno);

        if (resultaluno == 0)
            break;


        int numAluno1_aux;

        numAluno1_aux = aluno.numero_aluno;

        if (numAluno1_aux == aluno.numero_aluno) {
            strcpy(pais, aluno.pais);
            strcpy(modalidade, aluno.modalidadedePagamento);
            numPrestacoes = aluno.numPrestacoes;
            encontrouALUNO = 1;
        }

    }

    while (1) {
        size_t result = fread(&matricula, sizeof(t_matricula), 1, bd_matriculas);

        if (result == 0)
            break;


        int numAluno_aux;

        numAluno_aux = matricula.numero_aluno;

        if (numAluno_aux == aluno.numero_aluno) {
            ects = ects + quantECTSuc(matricula.codigo_uCurricular);
            encontrouECTS = 1;
        }

    }
    printf("EcTS: %d",ects);
    printf("modalidade: %s",modalidade);
    printf("numPrestacoes: %d",numPrestacoes);
    //printf("EcTS: %d",ects);

    calcpropina(ects, 1, pais, modalidade, numPrestacoes);


   // printf("Total de ECTS: %d, Pais: %s, Modalidade:%s\n\n", ects, pais, modalidade);


    if (encontrouALUNO == 0 || encontrouECTS == 0){
        printf("Nenhuma matricula registada para o aluno: %d.\n\n", numAluno);}

    fclose(bd_matriculas);
    printf("Pressione <Enter> para continuar...");
    scanf("%*c");

    fseek(stdin, 0, SEEK_END);


}

void calcectsparaterminar() {


    int ects_I = 0;
    int ects_M = 0;
    int ects_F = 0;
    int numAluno;

    float media;
    int contanota = 0;

    int encontrouECTS = 0;


    FILE *bd_matriculas = fopen("matriculas.bin", "rb");
    checkfile(bd_matriculas);
    FILE *bd_notas = fopen("avaliacao.bin", "rb");
    checkfile(bd_notas);

    t_matricula matricula;

    t_notas notas;

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
    while (1) {
        size_t result = fread(&matricula, sizeof(t_matricula), 1, bd_matriculas);
        size_t result1 = fread(&notas, sizeof(t_notas), 1, bd_notas);

        if (result == 0 || result1 == 0)
            break;


        int numAluno_aux;
        float notamin = 9.5;

        numAluno_aux = matricula.numero_aluno;

        if (numAluno_aux == numAluno) {
            if (notas.nota > notamin) {

                contanota++;
                media = media + notas.nota;

                if (areaUC(matricula.codigo_uCurricular) == 1) {
                    ects_I = ects_I + quantECTSuc(matricula.codigo_uCurricular);
                } else if (areaUC(matricula.codigo_uCurricular) == 2) {
                    ects_M = ects_M + quantECTSuc(matricula.codigo_uCurricular);
                } else if (areaUC(matricula.codigo_uCurricular) == 3) {
                    ects_F = ects_F + quantECTSuc(matricula.codigo_uCurricular);
                }
            }
            encontrouECTS = 1;


        }
    }

    int Tects = ects_M + ects_F + ects_I;

    if (Tects == 180) {
        media = media / contanota;
        printf("\nParabens, terminou o curso com uma media de: %.2f\n\n", media);

    } else if (encontrouECTS != 0) {
        nomeAluno(matricula.numero_aluno);
        printf("\nTotal de ECTS concluidos: %d.\n\n", Tects);
        printf("Area de Informatica: %d.\n", ects_I);
        printf("Area de Matematica: %d.\n", ects_M);
        printf("Area de Fisica: %d.\n\n", ects_F);
        printf("\n-----------| Para concluir o Curso |-------------\n");
        printf("\nFalta um total de %d ECTS na Area de Informatica.\n", 150 - ects_I);
        printf("Falta um total de %d ECTS na Area de Matematica.\n", 20 - ects_M);
        printf("Falta um total de %d ECTS na Area de Fisica.\n\n", 10 - ects_F);
        printf("Para concluir o curso falta um total de %d ECTS\n\n", 180 - Tects);
    }

    if (encontrouECTS == 0)
        printf("Nenhuma matricula registada para o aluno: %d.\n\n", numAluno);

    fclose(bd_matriculas);
    printf("Pressione <Enter> para continuar...");
    scanf("%*c");

    fseek(stdin, 0, SEEK_END);


}

void manual(){

    printf("\nBem vindo ao Sistema de Gestao de Inscricoes - UAB (LEI) 2022\n");
    printf("|----------------| 2003777 - Jorge Gouveia |----------------|\n\n");
    printf("|----------------------| MANUAL  |-----------------------|\n\n");
    printf("|----------------| Normas de Utilizacao |----------------|\n\n");
    printf("1 - Criar a entidade Aluno\n");
    printf("2 - Criar a entidade da Unidade Curricular\n");
    printf("3 - Matricular o Aluno nas Unidades Curriculares\n");
    printf("4 - Lancar Avaliacao\n\n");
    printf("|----------------| Requesitos eFolio-A |----------------|\n\n");
    printf("Incluir nas Unidades Curriculares, I, M, F\n\n");
    printf("Calcular ETCS: \n");
    printf("-> 1 - Menu Aluno \n");
    printf("-> -> 8 - Contagem de ECTS \n");
    printf("(nota: so faz contagem caso o aluno tenha sido aprovato na uc matriculado)\n\n");
    printf("Calcular pagamento: \n");
    printf("-> 3 - Menu Pagamento \n");
    printf("-> -> 1 - Calcular pagamento \n");
    printf("(nota: introduz manualmente os ECTS e Ano para calcular propinas)\n\n");
    printf("-> -> 2 - Calcular propina do aluno \n");
    printf("(nota: calcula automaticamente de acordo com a matricula do aluno)\n\n");
    printf("Listas disponiveis: \n");
    printf("-> Lista de alunos \n");
    printf("-> Lista de UCs do Aluno \n");
    printf("-> Lista de matriculas \n");
    printf("-> Lista de Anulacoes \n");
    printf("-> Lista de unidades curriculares \n");
    printf("-> Lista de docentes \n");
    printf("-> Lista de unidades curriculares de um professor \n");
    printf("-> Lista Nota\n\n");
    printf("Pesquisas disponiveis: \n");
    printf("-> Pesquisar aluno \n");
    printf("-> Notas do Aluno \n");
    printf("-> Pesquisar matricula \n");
    printf("-> Pesquisar unidade curricular \n");
    printf("-> Pesquisar unidade curricular \n");











    fflush(stdin);
    printf("\nPressione <Enter> para comecar a utilizar...");
    scanf("%*c");
    system(limpa);
    mainmenu();
}

void notasfinais(){


printf("21178 - LABORATORIO DE PROGRAMACAO - 2022");
printf("\n");
printf("       __                         ______                       _\n");
printf("      / /___  _________ ____     / ____/___  __  ___   _____  (_)___ _\n");
printf(" __  / / __ \\/ ___/ __ `/ _ \\   / / __/ __ \\/ / / / | / / _ \\/ / __ `/\n");
printf("/ /_/ / /_/ / /  / /_/ /  __/  / /_/ / /_/ / /_/ /| |/ /  __/ / /_/ /\n");
printf("\\____/\\____/_/   \\__, /\\___/   \\____/\\____/\\__,_/ |___/\\___/_/\\__,_/\n");
printf("                /____/\n");
printf("\n\n");

printf("2003777 - Jorge Gouveia\n");



printf("|----------------------| Notas Finais |-----------------------|\n\n");
printf("Apenas foi comentado o codigo referente ao aluno, uma vez que o mesmo e identico\n");
printf("em toda a sua estrutura. Tentei nos menus de atualizar ser possivel atualizar em toda\n");
printf("as suas referencias para manter a integridade dos dados, mas tive dificuldade em conseguir\n");
printf("a alteracao em todas as suas referencias, entao optei por ser possivel aterar os dados todos\n");
printf("com a excepcao das chaves (codigo uc e numero de aluno).\n");

fflush(stdin);
printf("\nPressione <Enter> para comecar a utilizar...");
scanf("%*c");
system(limpa);
mainmenu();

}

//////////////////////////////////////////////////////////////////////////////////

