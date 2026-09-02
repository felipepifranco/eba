#include <stdio.h>
#include <stdlib.h>

char* pega_flag(){
  FILE* file = fopen("flag.txt", "r");
  if (file == NULL){
    printf("Erro ao abrir o arquivo!\n");
    return NULL;
  }

  char* buffer = (char*)malloc(128 * sizeof(char));
  if (buffer == NULL){
    fclose(file);
    return NULL; // Falha na alocação de memória
  }

  // Lê até 127 caracteres da primeira linha e salva no buffer
  if (fgets(buffer, 60, file) == NULL){
    free(buffer); // Libera a memória se a leitura falhar (ex: arquivo vazio)
    fclose(file);
    return NULL;
  }

  // Fecha o arquivo para evitar vazamento de recursos (file descriptors)
  fclose(file);
  
  return buffer;
}