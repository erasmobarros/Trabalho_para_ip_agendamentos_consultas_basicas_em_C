#ifndef CONSULTAS_H
#define CONSULTAS_H

#define TAM 50

typedef struct {
    int id;
    char paciente[TAM];
    char medico[TAM];
    char estado [10];
    char data[11];
    char horaInicio[6];
    char horaFim[6];
    char numero[TAM];
} Consulta;

int buscarPorId(Consulta *vetor, int total, int id);

void inserirConsulta(Consulta **vetor, int *total, int *capacidade);
void listarConsultas(Consulta *vetor, int total);
int validarData(char data[]);
int validarHora(char hora[]);

#endif