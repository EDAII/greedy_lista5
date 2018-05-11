#include <stdio.h>
#include <stdlib.h>
#define ITENS 5


typedef struct atividade{
    int inicio;
    int fim;
}atividade;

void printMaxAtividades(atividade arr[ITENS]);
void quickSort(atividade vector[ITENS], int inicio, int n);
void printAtividades(atividade arr[ITENS]);

int main(){
    atividade arr[ITENS] = {{4, 7}, {4, 8}, {7, 9}, {10, 13}, {1, 2}};
    puts("=====Interval Scheduling=====");
    printAtividades(arr);
    printMaxAtividades(arr);
    return 0;
}

void printAtividades(atividade arr[ITENS]){
    int i;
    puts("Atividades: ");
    for(i = 0; i < ITENS; i++){
        printf("(%d, %d) ", arr[i].inicio, arr[i].fim);
    }
    puts("");
}

void printMaxAtividades(atividade arr[ITENS]){

    quickSort(arr, 0, ITENS-1);
    puts("\nAtividades selecionadas: ");

    int i = 0;
    printf("(%d, %d) ", arr[i].inicio, arr[i].fim);

    for (int j = 1; j < ITENS; j++){
      if (arr[j].inicio >= arr[i].fim){
          printf("(%d, %d) ", arr[j].inicio, arr[j].fim);
          i = j;
      }
    }
    puts("\n");
}

void quickSort(atividade vetor[ITENS], int inicio, int fim){

   int pivo, i, j, meio;
   atividade aux;

   i = inicio;
   j = fim;

   meio = (int) ((i + j) / 2);
   pivo = vetor[meio].fim;

   do{
      while (vetor[i].fim < pivo) i = i + 1;
      while (vetor[j].fim > pivo) j = j - 1;

      if(i <= j){
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);

   if(inicio < j) quickSort(vetor, inicio, j);
   if(i < fim) quickSort(vetor, i, fim);

}
