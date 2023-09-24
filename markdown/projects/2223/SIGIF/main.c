#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct  {
    int id;
    char fabricante_e_modelo[50];
    float horas_de_voo_iniciais;
    char esquad[10];
} Aeronave;

typedef struct {
    Aeronave aeronaves[100];
    int num_aeronaves;
} ListaAeronaves;

typedef struct {
    Voo voos[100];
    int num_voos;
} ListaVoos;

void imprimir_aeronave(Aeronave* aeronave) {
    printf("ID: %d\n", aeronave->id);
    printf("Fabricante e modelo: %s\n", aeronave->fabricante_e_modelo);
    printf("Horas de voo iniciais: %.2f\n", aeronave->horas_de_voo_iniciais);
}

typedef struct  {
    int id_aeronave;
    char data[11];
    int duracao_minutos;
} Voo;

void imprimir_voo(Voo* voo) {
    printf("ID da aeronave: %d\n", voo->id_aeronave);
    printf("Data: %s\n", voo->data);
    printf("Duracao em minutos: %d\n", voo->duracao_minutos);
}

int ler_voos(const char* nome_arquivo, Voo voos[], int tamanho_maximo) {
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        return 0;
    }

    int num_voos_lidos = 0;
    char linha[100];
    while (num_voos_lidos < tamanho_maximo && fgets(linha, 100, arquivo) != NULL) {
        if (sscanf(linha, "%10s %d %d", voos[num_voos_lidos].data, &voos[num_voos_lidos].id_aeronave, &voos[num_voos_lidos].duracao_minutos) == 3) {
            num_voos_lidos++;
        }
    }

    fclose(arquivo);
    return num_voos_lidos;
}

int ler_aeronaves(const char* nome_arquivo, Aeronave aeronaves[], int tamanho_maximo) {
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        return 0;
    }

    int num_aeronaves_lidas = 0;
    while (num_aeronaves_lidas < tamanho_maximo) {
        int id;
        int capacidade;
        char modelo[50];
        float horas_de_voo_iniciais;
        int num_lidos = fscanf(arquivo, "%d %d %49s %f", &id, &capacidade, modelo, &horas_de_voo_iniciais);
        if (num_lidos != 4) {
            break;
        }
        Aeronave aeronave = {id, modelo, horas_de_voo_iniciais};
        aeronaves[num_aeronaves_lidas] = aeronave;
        num_aeronaves_lidas++;
    }

    fclose(arquivo);
    return num_aeronaves_lidas;
}

void imprimir_voos_entre_datas(char data_inicial[], char data_final[], Voo voos[], int num_voos) {
    printf("Voos entre %s e %s:\n", data_inicial, data_final);
    for (int i = 0; i < num_voos; i++) {
        if (strcmp(voos[i].data, data_inicial) >= 0 && strcmp(voos[i].data, data_final) <= 0) {
            imprimir_voo(&voos[i]);
        }
    }
}



void imprimir_top_5_aeronaves_com_mais_horas_de_voo(ListaAeronaves* lista_aeronaves) {
    // Copy the number of aeronaves in the list to a variable
    int num_aeronaves = lista_aeronaves->num_aeronaves;
    // Create an array of indices to the aeronaves
    int indices[num_aeronaves];
    for (int i = 0; i < num_aeronaves; i++) {
        indices[i] = i;
    }
    // Sort the indices in descending order based on total flight hours
    for (int i = 0; i < num_aeronaves - 1; i++) {
        for (int j = i + 1; j < num_aeronaves; j++) {
            // Calculate the total flight hours for each aeronave
            float horas_de_voo_i = lista_aeronaves->aeronaves[indices[i]].horas_de_voo_iniciais + calcular_horas_de_voo_aeronave(&lista_aeronaves->aeronaves[indices[i]]);
            float horas_de_voo_j = lista_aeronaves->aeronaves[indices[j]].horas_de_voo_iniciais + calcular_horas_de_voo_aeronave(&lista_aeronaves->aeronaves[indices[j]]);
            // Swap the indices if the j-th aeronave has more flight hours than the i-th aeronave
            if (horas_de_voo_j > horas_de_voo_i) {
                int temp = indices[i];
                indices[i] = indices[j];
                indices[j] = temp;
            }
        }
    }
    // Print the top 5 aeronaves with the most flight hours
    printf("Top 5 Aeronaves com mais horas de voo:\n");
    for (int i = 0; i < min(5, num_aeronaves); i++) {
        // Calculate the total flight hours for the current aeronave
        float horas_de_voo = lista_aeronaves->aeronaves[indices[i]].horas_de_voo_iniciais + calcular_horas_de_voo_aeronave(&lista_aeronaves->aeronaves[indices[i]]);
        // Print the aeronave information to the console
        printf("%d. %s (ID: %d) - %.2f horas de voo\n", i+1, lista_aeronaves->aeronaves[indices[i]].fabricante_e_modelo, lista_aeronaves->aeronaves[indices[i]].id, horas_de_voo);
    }
}

void imprimir_histograma_horas_de_voo_por_ano(ListaVoos* lista_voos, int ano_inicial, int ano_final) {
    // Create an array to store the total flight hours for each year
    float horas_de_voo_por_ano[ano_final - ano_inicial + 1];
    for (int i = 0; i < ano_final - ano_inicial + 1; i++) {
        horas_de_voo_por_ano[i] = 0;
    }
    // Iterate through each voo in the list and add its flight hours to the corresponding year
    for (int i = 0; i < lista_voos->num_voos; i++) {
        int ano = lista_voos->voos[i].data.ano;
        if (ano >= ano_inicial && ano <= ano_final) {
            horas_de_voo_por_ano[ano - ano_inicial] += lista_voos->voos[i].horas_de_voo;
        }
    }
    // Print the histogram to the console
    printf("Histograma das horas de voo de toda a Forca Aerea, por ano:\n");
    for (int i = 0; i < ano_final - ano_inicial + 1; i++) {
        printf("%d: ", i + ano_inicial);
        for (int j = 0; j < horas_de_voo_por_ano[i] / 4; j++) {
            printf("####");
        }
        for (int j = 0; j < horas_de_voo_por_ano[i] % 4; j++) {
            printf("#");
        }
        printf("\n");
    }
}

int main() {
    Aeronave aeronave = {1, "Boeing 737-800", 0.0};
    Voo voo = {1, "2020-01-01", 120};

    imprimir_aeronave(&aeronave);
    imprimir_voo(&voo);

    return 0;
}

