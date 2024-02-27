#include <stdio.h>
#include <string.h>

typedef struct {
  int id;
  char cidade[50];
  char nome[50];
} Estudante;

int read_file(char *filename, int n, Estudante estudantes[n]) {
  FILE *fp;
  int n_read = 0;

  fp = fopen(filename, "rb");
  if (fp == NULL) {
    printf("Error opening file %s\n", filename);
    return -1;
  }

  n_read = fread(estudantes, sizeof(Estudante), n, fp);

  fclose(fp);
  return n_read;
}

void write_city(char *city, int n, Estudante estudantes[n]) {
  FILE *fp;
  char filename[50];
  int n_written = 0;

  sprintf(filename, "%s.txt", city);
  fp = fopen(filename, "w");
  if (fp == NULL) {
    printf("Error opening file %s\n", filename);
    return;
  }

  for (int i = 0; i < n; i++) {
    if (strcmp(estudantes[i].cidade, city) == 0) {
      n_written += fprintf(fp, "%d %s\n", estudantes[i].id, estudantes[i].nome);
    }
  }

  fclose(fp);
  printf("Wrote %d students to file %s\n", n_written, filename);
}


int main() {
  int n_estudantes = 200;
  Estudante estudantes[n_estudantes];

    char cidades[5][50] = {
    "Lisboa",
    "Porto",
    "Coimbra",
    "Braga",
    "Funchal"
  };

  int n_read = read_file("estudantes.bd", n_estudantes, estudantes);
  printf("read %d Estudante\n", n_read);
  if (n_read == -1) {
    return -1;
  }

 // print para debug
  for (int i=0; i<n_read; i++) {
    printf("---estudante %d ---\n", i);
    printf("%d %s %s\n", estudantes[i].id, estudantes[i].cidade, estudantes[i].nome);
  }

for (int i = 0; i < 5; i++) {
    write_city(cidades[i], n_estudantes, estudantes);
}
  return 0;
}