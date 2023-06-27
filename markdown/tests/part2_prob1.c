#include <stdio.h>
#include <string.h>
#define MAX_STRINGS 100

char *nomes_proprios[] = {
    "Maria", "Joao", "Ana", "Pedro", "Carla", "Jose",
    "Margarida", "Miguel", "Sofia", "Ricardo"
};

char *apelidos[] = {
    "Silva", "Santos", "Rodrigues", "Costa", "Oliveira",
    "Martins", "Ferreira", "Pereira", "Carvalho", "Marques"
};

void create_full_names(int n_strings, char * nomes_proprios[10],
    char * apelidos[10], char nomes_completos[n_strings][MAX_STRINGS]) {
    for (int i = 0; i < n_strings; i++) {
        strcpy(nomes_completos[i], nomes_proprios[i]);
        strcat(nomes_completos[i], " ");
        strcat(nomes_completos[i], apelidos[10 - i - 1]);
    }
}

int main() {
    int n = 5;
    char nomes_completos[n][MAX_STRINGS];
    create_full_names(n, nomes_proprios, apelidos, nomes_completos);
    for (int i = 0; i < n; i++)
        printf("%s\n", nomes_completos[i]);
    return 0;
}