#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "consultas.h"

// procura consulta pelo id
int buscarPorId(Consulta *vetor, int total, int id){
    int i;

    for (i = 0; i < total; i++){
        if (vetor[i].id == id){
            return i;
        }
    }
    return -1;
}
// valida formato de data
int validarData(char data[]){
    if (strlen(data) != 10){
        return 0;
    }
    if (data[2] != '/' || data[5] != '/'){
        return 0;
    }
    return 1;
}
// valida formato de hora
int validarHora(char hora[]){

    if (strlen(hora) != 5){
        return 0;
    }
    if (hora[2] != ':'){
        return 0;
    }
    return 1;
}
// valida se o nome tem apenas letras e espaços
int validarNome(char nome[]){
    int i;

    for (i = 0; nome[i] != '\0'; i++){
        if ((nome[i] < 'A' || nome[i] > 'Z') && (nome[i] < 'a' || nome[i] > 'z') && nome[i] != ' '){
            return 0;
        }
    }
    return 1;
}
// valida se tem apenas numeros
int validarnumero(char numero[]){
    int i;
    
    for (i = 0; numero[i] != '\0'; i++){
        if (numero[i] < '0' || numero[i] > '9'){
            return 0;
        }
    }
    return 1;
}
// converte hora para minutos
int horaParaMinutos(char hora[]){

    int h, m;
    sscanf(hora, "%d:%d", &h, &m);

    return h * 60 + m;
}

// inserir nova consulta
void inserirConsulta(Consulta **vetor, int *total, int *capacidade){

    Consulta nova;

    // aumenta vetor se precisar
    if (*total == *capacidade){

        *capacidade = *capacidade + 10;
        *vetor = realloc(*vetor, (*capacidade) * sizeof(Consulta));
    }
    
    // cadastrar consultorio
    while (1){

    printf("Informe o numero do Consultorio da consulta: ");
    scanf("%d", &nova.id);

    if (buscarPorId(*vetor, *total, nova.id) != -1){
        printf("Consultorio ja ocupado. Digite outro.\n");
    } 
    else{
        break;
    }
    }
    
    // nome paciente
    while (1){

        printf("Nome Paciente: ");
        scanf(" %[^\n]", nova.paciente);

        if (validarNome(nova.paciente)){
            break;
        } else{
            printf("Nome invalido. Use apenas letras e espacos.\n");
        }
    }
    
    // nome medico
    while (1){

        printf("Nome Medico responsavel: ");
        scanf(" %[^\n]", nova.medico);

        if (validarNome(nova.medico)){
            break;
        } else{
            printf("Nome invalido. Use apenas letras e espacos.\n");
        }
    }
    
    // estado paciente
    while (1){

        printf("Estado Paciente:\n");
        printf("1 - Verde\n");
        printf("2 - Amarelo\n");
        printf("3 - Vermelho\n");
        printf("Opcao: ");
        scanf("%s", nova.estado);

        if (validarnumero(nova.estado)){
            break;
        } else{
            printf("Opcao invalida.\n");
        }
    }
    
    // valida data
    while (1){

        printf("Data (dd/mm/aaaa): ");
        scanf("%s", nova.data);

        if (validarData(nova.data)){
            break;
        } else{
            printf("Data invalida.\n");
        }
    }
    
    // valida hora inicio
    while (1){

        printf("Hora inicio (hh:mm): ");
        scanf("%s", nova.horaInicio);

        if (validarHora(nova.horaInicio)){
            break;
        }else{
            printf("Hora invalida.\n");
        }
    }

    // valida hora fim
    while (1){

        printf("Hora fim (hh:mm): ");
        scanf("%s", nova.horaFim);

        if (!validarHora(nova.horaFim)){
            printf("Hora invalida.\n");
            continue;
        } if (horaParaMinutos(nova.horaFim) <= horaParaMinutos(nova.horaInicio)){
            printf("Hora fim deve ser maior que inicio.\n");
        } else{
            break;
        }
    }

    // salva no vetor
    (*vetor)[*total] = nova;
    (*total)++;

    printf("\nConsulta cadastrada com sucesso!\n");
    printf("\n--- Dados da Consulta ---\n");
    printf("Consultorio: %d | Paciente: %s | Medico: %s | Estado: %s | Data: %s | Hora inicio: %s | Hora fim: %s\n", nova.id, nova.paciente, nova.medico, nova.estado, nova.data, nova.horaInicio, nova.horaFim);
}
// listar consultas
void listarConsultas(Consulta *vetor, int total)
{
    int i;

    if (total == 0){
        printf("Nenhuma consulta cadastrada.\n");
        return;
    }
    for (i = 0; i < total; i++){
        printf("----- Consultas Castradas -----\n");
        printf("\nConsulta %d | Consultorio: %d | Paciente: %s | Medico: %s | Estado: %s | Data: %s | Hora inicio: %s | Hora fim: %s\n", i + 1, vetor[i].id, vetor[i].paciente, vetor[i].medico, vetor[i].estado, vetor[i].data, vetor[i].horaInicio, vetor[i].horaFim);
    }
}