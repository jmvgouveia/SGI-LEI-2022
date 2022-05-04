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

#ifndef EFOLIOA_SISCONTROL_H
#define EFOLIOA_SISCONTROL_H

#include "main.h"

int verificar_str(char str[]);

int check123(char str[], int nums);

int checkAreaCi(char str[]);

void calcpropina();

void calcpropinadoAluno();

void calcpropinaporEcts();

void checkfile(FILE *file);

int checknumPrestacoes (int numero);

void calcectsparaterminar();

void validarapenasNumeros();

int existeMatricula (FILE *bd_matricula, int id_aluno, int codUc);

void manual();

void notasfinais();

#endif //EFOLIOA_SISCONTROL_H
