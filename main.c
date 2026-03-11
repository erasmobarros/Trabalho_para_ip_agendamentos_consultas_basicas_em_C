#include <stdio.h>
#include <stdlib.h>
#include "consultas.h"

int main(){

    Consulta *consultas;

    int capacidade = 10;
    int total = 0;
    int opcao;

    // alocação inicial
    consultas = (Consulta*) malloc(capacidade * sizeof(Consulta));

    if(consultas == NULL){
        printf("Erro de memoria.\n");
        return 1;
    }

    do{

        printf("\n==== SISTEMA DE CONSULTAS UFAPE====\n");
        printf("1 - Inserir consulta\n");
        printf("2 - Listar consultas\n");
        printf("0 - Sair\n");
        printf("Opcao: ");

        scanf("%d", &opcao);
        

        switch(opcao){

            case 1:
                inserirConsulta(&consultas, &total, &capacidade);
            break;

            case 2:
                listarConsultas(consultas, total);
            break;

            case 0:
                printf("Saindo.\n");
            break;

            default:
                printf("Opcao invalida\n");
        }

    }while(opcao != 0);

    free(consultas);

    return 0;
}