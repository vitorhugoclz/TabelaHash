/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: vitor
 *
 * Created on 20 de Janeiro de 2019, 21:44
 */

#include <stdio.h>
#include <stdlib.h>
//#include <limits.h>

#include "tabela_hash.h"
#define MAX 1000
/*
 * 
 */
int main() {
    hash * ha = cria_hash(MAX);

    /*estudante * e = cria_estudante("Flavio Barbieri\0", 125);
    insere_hash_end_aberto(ha, e);

    e = cria_estudante("Joao das Couves\0", 1125);
    insere_hash_end_aberto(ha, e);

    char * a = busca_hash_end_aberto(ha, 125);
    if (a != NULL)
            printf("%s\n", a);
    else
            printf("Aluno nao encontrado.\n");

    a = busca_hash_end_aberto(ha, 1125);
    if (a != NULL)
            printf("%s\n", a);
    else
            printf("Aluno nao encontrado.");

    libera_hash(ha);
        
    estudante * inicio = NULL;*/
    estudante * e;
    char  nome[30], * n;   
    int matricula, opcao, flag;
    do {
        printf("---------------\n");
        printf("| [0] Inserir |\n");
        printf("| [1] Busca   |\n");
        printf("| [2] Remover |\n");
        printf("| [3] Sair    |\n");
        printf("---------------\n");
        scanf(" %d", &opcao);
        switch (opcao) {
            case 0:
                printf("Digite a matricula: ");
                scanf(" %d", &matricula);
                printf("Digite o nome: ");
                scanf(" %s", nome);
                e = cria_estudante(nome, matricula);
                flag = insere_hash_enc_separado(ha, e);
                if (flag == 1)
                    printf("Cadastro inserido com sucesso\n");
                else
                    printf("Cadastro não foi inserido\n");
                break;
            case 1:
                printf("Digite a matricula: ");
                scanf(" %d", &matricula);
                n = busca_hash_enc_separado(ha, matricula);
                if (n)
                    printf("Estudante: %s encontrado\n", n);
                else
                    printf("Estudante com essa matricula não foi encontrado\n");
                break;
            case 2:
                printf("Digite a matricula: ");
                scanf(" %d", &matricula);
                e = remove_hash_enc_separado(ha, matricula);
                if(e != NULL)
                {
                    printf("Aluno encontrado:\n");
                    printf("Nome: %s\tMatricula: %d\n", e->nome, e->matricula);
                    free(e);
                }
                else
                    printf("Não foi encontrado\n");             
                break;
            default:break;
        }
    } while (opcao != 3);
    libera_hash(ha);
    return 0;
}

