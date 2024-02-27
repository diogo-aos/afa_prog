#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* * * * * * * * * * * * * * * * * * * * * * * *
    * ESTRUTURAS *
* * * * * * * * * * * * * * * * * * * * * * * */


// struct para Aeronave
typedef struct {
    char fabricante[20];
    int n_cauda;
    int ano_fabrico;
} Aeronave;

// linked list node of type Aeronave
typedef struct node {
    Aeronave aeronave;
    struct node *next;
} Node;

// function to print a Aeronave pointer
void printAeronave(Aeronave *aeronave) {
    printf("Aeronave: %s, %d, %d\n", aeronave->fabricante, aeronave->n_cauda, aeronave->ano_fabrico);
}



/* * * * * * * * * * * * * * * * * * * * * * * *
    * MOCK DATA *
* * * * * * * * * * * * * * * * * * * * * * * */

// array of 20 aircraft makers
char *fabricantes[] = {
    "Boeing",
    "Airbus",
    "Embraer",
    "Bombardier",
    "Cessna",
    "Dassault",
    "Gulfstream",
    "Pilatus",
    "Beechcraft",
    "Lockheed",
    "Saab",
    "Sukhoi",
    "Antonov",
    "Tupolev",
    "Ilyushin",
    "Yakovlev",
    "Aero",
    "Fokker",
    "McDonnell Douglas",
    "Lockheed Martin",
};



// function createAeronaves receives an unsigned int n and returns a pointer to an array of n Aeronaves
Aeronave *createAeronaves(unsigned int n) {
    Aeronave *aeronaves = malloc(n * sizeof(Aeronave));
    for (int i = 0; i < n; i++) {
        int rand_fabricante = rand() % 20;
        strcpy(aeronaves[i].fabricante, fabricantes[rand_fabricante]);
        aeronaves[i].n_cauda = 1000 + i;
        aeronaves[i].ano_fabrico = 1990 + rand() % 30;
    }
    return aeronaves;
}


/* * * * * * * * * * * * * * * * * * * * * * * *
    * LISTA LIGADA *
* * * * * * * * * * * * * * * * * * * * * * * */

// function to add estudante to list
void addAeronave(Node **head, Aeronave aeronave) {
    Node *new_node = malloc(sizeof(Node));
    new_node->aeronave = aeronave;
    new_node->next = *head;
    *head = new_node;
}


// function to print a linked list of Estudante
void printAeronaves(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printAeronave(&current->aeronave);
        current = current->next;
    }
}


int main(){
    // podes alterar este valor para testar com arrays de tamanhos diferentes
    int n_aeronaves = 10;

    // receber array de Aeronaves aleatórios, com a função createAeronaves
    Aeronave *aeronaves = createAeronaves(n_aeronaves);
    

    // criar lista ligada
    Node *head = NULL;
    

    // adicionar todos os Aeronave do array à lista ligada
    for (int i = 0; i < n_aeronaves; i++) {
        addAeronave(&head, aeronaves[i]);
    }
    

    // libertar array de Aeronave da memória
    free(aeronaves);


    // escrever na consola todos os Aeronave da lista ligada
    printAeronaves(head);

    // eliminar da lista ligada todos os Aeronave com ano de fabrico superior a 1990
    //     para cada Aeronave removido, escrever na consola "removida aeronave com número de cauda <n_cauda> do fabricante <fabricante>"

    Node *current = head;
    Node *previous = NULL;
    while (current != NULL) {
        if (current->aeronave.ano_fabrico > 2000) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            printf("removida aeronave com número de cauda %d do fabricante %s\n", current->aeronave.n_cauda, current->aeronave.fabricante);
            free(current);
        } else {
            previous = current;
        }
        current = current->next;
    }


    // imprimir novamente a lista ligada com as aeronaves sobrantes
    printAeronaves(head);


}