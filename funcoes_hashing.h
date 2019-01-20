/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hashing.h
 * Author: flavio
 *
 * Created on 15 de Janeiro de 2019, 23:34
 */

#ifndef HASHING_H
#define HASHING_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

int chave_divisao(int chave, int TABLE_SIZE);
int chave_multiplicacao(int chave, int TABLE_SIZE);
int chave_dobra(int chave, int TABLE_SIZE);
int valor_string(char * str);

#endif /* HASHING_H */

