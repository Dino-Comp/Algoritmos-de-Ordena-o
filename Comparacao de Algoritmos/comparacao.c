/*LAURA AGUIAR MARTINHO
21952064
*/


/*
OBSERVACOES:

as variaveis de contagem e acumulacao estao declaradas para cada metodo de ordenacao
sendo, trocaB, comparaB variaveis de contagem de troca e comparacao para o Bubble sort,
trocaH, comparaH para heap, trocaM para Merge, assim sucesivamente

as variaveis de acumulacao e media, tambem seguem o padrao, sendo "Tr, Tp" abrviaçoes 
para troca e tempo, sendo usadas, por exemplo, em variaveis como somaTrQ que seria o acumulo
da soma das trocas do quick, mediaTpB, seria media tempo do bubble, somaCB seria 
soma de comparacoes para Bubble, mediaTrH media trocas heap, etc.

inteiros i sempre declaram índices
n ou tam declaram tamanho

as funcoes (metodo de ordenacao)JaOrd / (metodo de ordenacao)Inv eram os resultados pra vetores
ordenados e inversamente ordenados, como pedido.

array ou v sao vetores; 

*/





#include <stdio.h>
#include<stdlib.h>
#include<time.h>
/***************************************BUBBLE SORT**********************************/

//implementacao bubble
int trocaB, comparaB;


void BubbleSort(int array[], int n){
  trocaB=0; comparaB=0;
  for (int i = 0 ; i < n - 1; i++){
 
    for (int j = 0 ; j < n - i - 1; j++){
      comparaB++;
        if (array[j] > array[j+1]){
         trocaB++;
         int swap   = array[j];
          array[j]   = array[j+1];
          array[j+1] = swap; // swap é um aux
       
        }
     }comparaB++;
  }
}
   
void bubbleJaOrd(){
 
  int v[1000], i;
    
  for(i=0; i<1000; i++){
    v[i]= i; 
  }
  int n = sizeof(v)/sizeof(v[0]);
   clock_t tempo = clock();
  BubbleSort(v, n);
  tempo = clock()-tempo;
    double tempoOrdB=((double)(tempo)/(CLOCKS_PER_SEC / 1000));
  printf("\n\t\t\t\t\tComparacoes:%d\n\t\t\t\t\tTrocas:%d\n\t\t\t\t\tTempo:%f", comparaB,trocaB, tempoOrdB);

}

void bubbleInv(){

    int v[1000], i;
    
  for(i=0; i<1000; i++){
    v[i]= 1000-i-1; 
  }
  int n = sizeof(v)/sizeof(v[0]);
   clock_t tempo = clock();
  BubbleSort(v,n);
  tempo = clock()-tempo;
    double tempoInvB=((double)(tempo)/(CLOCKS_PER_SEC / 1000));
  printf("\n\t\t\t\t\tComparacoes:%d\n\t\t\t\t\tTrocas:%d\n\t\t\t\t\tTempo:%f", comparaB,trocaB, tempoInvB);


}

void exBubble(){
  int v[1000], i;
    
  for(i=0; i<1000; i++){
    v[i]= rand()% 999*100; 
  }
  int n = sizeof(v)/sizeof(v[0]);
  printf("Vetor Desordenado:\n");for (int i = 0; i < n; ++i){printf("%d ", v[i]);}
  BubbleSort(v, n);
  printf("\nVetor Ordenado:\n");for (int i = 0; i < n; ++i){printf("%d ", v[i]);}
}
//funcao gera resultados
int somaCB=0, somaTrB=0; double somaTpB=0;
void mediasBubble(){
  int gera; double tempoRB; int mediaCB, mediaTrB; double mediaTpB;
  
  for(gera=0; gera<40;gera++){
    int v[1000], i;
      
    for(i=0; i<1000; i++){
    
      v[i]= rand()% 999*100; 
    }
    int n = sizeof(v)/sizeof(v[0]);
    //printf("Vetor Desordenado:\n");for (int i = 0; i < n; ++i){printf("%d\n", v[i]);}
    clock_t tempo = clock();
    BubbleSort(v, n);
    tempo = clock()-tempo;
    //printf("Vetor Ordenado:\n");for (int i = 0; i < n; ++i){printf("%d\n", v[i]);}
    double tempoRB=((double)(tempo)/(CLOCKS_PER_SEC / 1000));
    somaTpB+=tempoRB; somaCB+=comparaB; somaTrB+=trocaB; 
  }
  // somaCB+=comparaB; somaTrB+=trocaB; 
  mediaCB= somaCB/40; mediaTrB=somaTrB/40; mediaTpB=somaTpB/40;
  printf("\n\t\t\t\t\tMedia Comparacoes:%d\n\t\t\t\t\tMedia trocas:%d\n\t\t\t\t\tMedia tempo:%f", mediaCB,mediaTrB, mediaTpB);
}

/*********************************************MERGE SORT************************************/
int comparaM=0, trocaM=0;
void merge(int vetor[], int inicio, int meio, int fim) ;

void mergeSort(int vetor[], int inicio, int fim){
    if (inicio < fim) {
        int m = inicio + (fim - inicio) / 2;
        mergeSort(vetor, inicio, m);
        mergeSort(vetor, m + 1, fim);
        merge(vetor, inicio, m, fim);
    }
}

void merge(int vetor[], int inicio, int meio, int fim) {
  int i, j, k; int n1 = meio - inicio + 1;  int n2 = fim - meio;
  int L[n1], R[n2];
  for (i = 0; i < n1; i++)
    L[i] = vetor[inicio + i];
  for (j = 0; j < n2; j++)
    R[j] = vetor[meio + 1 + j];
  i = 0;  j = 0; k = inicio;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      vetor[k] = L[i];
      i++;
        trocaM++;
    }
    else {
      vetor[k] = R[j];
      j++;
    
    }
    comparaM++;
    k++;
  }
  while (i < n1) {
    vetor[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    vetor[k] = R[j];
    j++;
    k++;
  }
}



void mergeJaOrd(){
  trocaM=0; comparaM=0;
  //ordenado
  int v[1000], i;
    
  for(i=0; i<1000; i++){
    v[i]= i; 
  }
  int n = sizeof(v)/sizeof(v[0]);
   clock_t tempo = clock();

  mergeSort(v,0, n);
  tempo = clock()-tempo;
    double tempoRM=((double)(tempo)/(CLOCKS_PER_SEC / 1000));
  printf("\n\t\t\t\t\tComparacoes:%d\n\t\t\t\t\tTrocas:%d\n\t\t\t\t\tTempo:%f", comparaM,trocaM, tempoRM);

  

}

void mergeInv(){
  trocaM=0; comparaM=0;
    int v[1000], i;
    
  for(i=0; i<1000; i++){
    v[i]= 1000-1-i; 
  }
  int n = sizeof(v)/sizeof(v[0]);
   clock_t tempo = clock();
  mergeSort(v,0, 999);
  tempo = clock()-tempo;
    double tempoRM=((double)(tempo)/(CLOCKS_PER_SEC / 1000));
  printf("\n\t\t\t\t\tComparacoes:%d\n\t\t\t\t\tTrocas:%d\n\t\t\t\t\tTempo:%f", comparaM,trocaM, tempoRM);


}

void exMerge(){
  int v[1000], i;
    
  for(i=0; i<1000; i++){
    v[i]= rand()% 999*100; 
  }
  int n = sizeof(v)/sizeof(v[0]);
  printf("Vetor Desordenado:\n");for (int i = 0; i < n; ++i){printf("%d ", v[i]);}
  mergeSort(v,0, 999);
  printf("\nVetor Ordenado:\n");for (int i = 0; i < n; ++i){printf("%d ", v[i]);}
}
//funcao gera resultados
int somaCM=0, somaTrM=0; double somaTpM=0;
void mediasMerge(){
  int gera; double tempoRM; int mediaCM, mediaTrM; double mediaTpM;
   for(gera=0; gera<40;gera++){
    int v[1000], i;
      
    for(i=0; i<1000; i++){
      v[i]= rand()% 999*100; 
    }
    int n = sizeof(v)/sizeof(v[0]);
     clock_t tempo = clock();
    mergeSort(v,0, 999);
    tempo = clock()-tempo;
    double tempoRM=((double)(tempo)/(CLOCKS_PER_SEC / 1000));
    somaTpM+=tempoRM;
  }
  somaCM+=comparaM; somaTrM+=trocaM; 
  mediaCM= somaCM/40; mediaTrM=somaTrM/40; mediaTpM=somaTpM/40;
  printf("\n\t\t\t\t\tMedia Comparacoes:%d\n\t\t\t\t\tMedia trocas:%d\n\t\t\t\t\tMedia tempo:%f", mediaCM,mediaTrM, mediaTpM);
}

/************************************HEAP SORT***********************************/
//funcao auxiliar troca elementos
void trocar(int *a, int *b){
  int aux = *a;
  *a = *b;
  *b = aux;
}
//funcao heapify
int comparaH=0, trocaH=0;// contadores trocas e comparacoes 
void heapify(int v[], int n, int i) {
  int pai = i;
  int esq = 2 * i + 1;
  int dir = 2 * i + 2;

  if (esq < n && v[esq] > v[pai]){
    comparaH++;
    pai = esq;
  }  
  if (dir < n && v[dir] > v[pai]){
    comparaH++;
    pai = dir;
  }
  if (pai != i){
    trocaH++;
    trocar(&v[i], &v[pai]);
    heapify(v, n, pai);
  }
}
//funcao heapsort
void heapSort(int v[], int n){
  for(int i = n / 2 - 1; i >= 0; i--){
    heapify(v, n, i);
  }
  for(int i = n - 1; i >= 0; i--){
    trocaH++;
    trocar(&v[0], &v[i]);
    heapify(v, i, 0);
  }
}

void HeapJaOrd(){
  int v[1000], i;
    
  for(i=0; i<1000; i++){
    v[i]= i; 
  }
  int n = sizeof(v)/sizeof(v[0]);
   clock_t tempo = clock();
  heapSort(v, n);
  tempo = clock()-tempo;
    double tempoRH=((double)(tempo)/(CLOCKS_PER_SEC / 1000));
  printf("\n\t\t\t\t\tComparacoes:%d\n\t\t\t\t\tTrocas:%d\n\t\t\t\t\tTempo:%f", comparaH,trocaH, tempoRH);

}

void heapInv(){
    int v[1000], i;
    
  for(i=0; i<1000; i++){
    v[i]= 1000-1-i; 
  }
  int n = sizeof(v)/sizeof(v[0]);
   clock_t tempo = clock();
  heapSort(v,n);
  tempo = clock()-tempo;
    double tempoRH=((double)(tempo)/(CLOCKS_PER_SEC / 1000));
  printf("\n\t\t\t\t\tComparacoes:%d\n\t\t\t\t\tTrocas:%d\n\t\t\t\t\tTempo:%f", comparaH,trocaH, tempoRH);


}

//funcao para mostrar se ordenou
void exHeap(){
  int v[1000], i;
    
  for(i=0; i<1000; i++){
    v[i]= rand()% 999*100; 
  }
  int n = sizeof(v)/sizeof(v[0]);
  printf("Vetor Desordenado:\n");for (int i = 0; i < n; ++i){printf("%d ", v[i]);}
  heapSort(v, n);
  printf("\nVetor Ordenado:\n");for (int i = 0; i < n; ++i){printf("%d ", v[i]);}
}
//funcao gera resultados
int somaCH=0, somaTrH=0; double somaTpH=0;
void mediasHeap(){
  int gera; double tempoRH; int mediaCH, mediaTrH; double mediaTpH;
 
  for(gera=0; gera<40;gera++){
    int v[1000], i;
      
    for(i=0; i<1000; i++){
      v[i]= rand()% 999*100; 
    }
    int n = sizeof(v)/sizeof(v[0]);
    //printf("Vetor Desordenado:\n");for (int i = 0; i < n; ++i){printf("%d\n", v[i]);}
     clock_t tempo = clock();
    heapSort(v, n);
    tempo = clock()-tempo;
    //printf("Vetor Ordenado:\n");for (int i = 0; i < n; ++i){printf("%d\n", v[i]);}
    double tempoRH=((double)(tempo)/(CLOCKS_PER_SEC / 1000));
    somaTpH+=tempoRH;
  }
  somaCH+=comparaH; somaTrH+=trocaH; 
  mediaCH= somaCH/40; mediaTrH=somaTrH/40; mediaTpH=somaTpH/40;
  printf("\n\t\t\t\t\tMedia Comparacoes:%d\n\t\t\t\t\tMedia trocas:%d\n\t\t\t\t\tMedia tempo:%f", mediaCH,mediaTrH, mediaTpH);
}
/***************************************QUICKSORT SORT**********************************/
int trocaQ=0, comparaQ=0;


int partition (int v[], int low, int high) 
{ 
    int pivot = v[high];     
    int i = (low - 1);  
  
    for (int j = low; j <= high- 1; j++) 
    {  comparaQ++;
        if (v[j] <= pivot) 
        {  trocaQ++;
            i++;    
            trocar(&v[i], &v[j]); 
        } 
    } trocaQ++;
    trocar(&v[i + 1], &v[high]); 
    return (i + 1); 
}
void quicksort(int v[], int low, int high) 
{ 
    if (low < high) 
    {comparaQ++;
        int pi = partition(v, low, high); 
  
        quicksort(v, low, pi - 1); 
        quicksort(v, pi + 1, high); 
    } 
} 
  

void QuickJaOrd(){
  trocaQ=0; comparaQ=0;
  int v[1000], i;  

  for(i=0; i<1000; i++){
    v[i]= i; 
  }
  int n = sizeof(v)/sizeof(v[0]);
   clock_t tempo = clock();
  quicksort(v, 0, n-1);
  tempo = clock()-tempo;
    double tempoOrdB=((double)(tempo)/(CLOCKS_PER_SEC / 1000));
  printf("\n\t\t\t\t\tComparacoes:%d\n\t\t\t\t\tTrocas:%d\n\t\t\t\t\tTempo:%f", comparaQ,trocaQ, tempoOrdB);

}

void quickInv(){
  trocaQ=0; comparaQ=0;  
    int v[1000], i;  
    
  for(i=0; i<1000; i++){
    v[i]= 1000-1-i; 
  }
  int n = sizeof(v)/sizeof(v[0]);
   clock_t tempo = clock();
  quicksort(v,0,n-1);
  tempo = clock()-tempo;
    double tempoInvB=((double)(tempo)/(CLOCKS_PER_SEC / 1000));
  printf("\n\t\t\t\t\tComparacoes:%d\n\t\t\t\t\tTrocas:%d\n\t\t\t\t\tTempo:%f", comparaQ,trocaQ, tempoInvB);


}

//funcao gera resultados
int somaCQ=0, somaTrQ=0; double somaTpQ=0;
void mediasQuick(){
  int gera; double tempoRQ; int mediaCQ, mediaTrQ; double mediaTpQ;
  
  for(gera=0; gera<40;gera++){
    int v[1000], i;
      trocaQ=0; comparaQ=0;
    for(i=0; i<1000; i++){
      v[i]= rand()% 999*100; 
    }
    int n = sizeof(v)/sizeof(v[0]);

    clock_t tempo = clock();
    quicksort(v,0, n-1);
    tempo = clock()-tempo;
 
    double tempoRQ=((double)(tempo)/(CLOCKS_PER_SEC / 1000));
    somaTpQ+=tempoRQ; somaCQ+=comparaQ; somaTrQ+=trocaQ; 
  }

  mediaCQ= somaCQ/40; mediaTrQ=somaTrQ/40; mediaTpQ=somaTpQ/40;
  printf("\n\t\t\t\t\tMedia Comparacoes:%d\n\t\t\t\t\tMedia trocas:%d\n\t\t\t\t\tMedia tempo:%f", mediaCQ,mediaTrQ, mediaTpQ);
}

int main(){
  srand((unsigned)time(NULL));  
  //exBubble();
printf("\n----------------------------------------------------");
  printf("\n\t\t\t\t\t>>40 VETORES DESORDENADOS");
  mediasBubble();
  printf("\n\n->BUBBLESORT:");
  printf("\t\t>>VETOR ORDENADO");
  bubbleJaOrd();
  printf("\n\n\t\t\t\t\t>>VETOR INVERSAMENTE ORDENADO");
  bubbleInv();

  printf("\n----------------------------------------------------");
  

  
  printf("\n\t\t\t\t\t>>40 VETORES DESORDENADOS");
  mediasHeap();
  printf("\n\n->HEAPSORT:");
  printf("\t\t\t>>VETOR ORDENADO");
  HeapJaOrd();
  printf("\n\n\t\t\t\t\t>>VETOR INVERSAMENTE ORDENADO");
  heapInv();
  printf("\n----------------------------------------------------");
  
  printf("\n\t\t\t\t\t>>40 VETORES DESORDENADOS");
  mediasQuick();
  printf("\n\n->QUICKSORT:");
  printf("\t\t>>VETOR ORDENADO");
  QuickJaOrd();
  printf("\n\n\t\t\t\t\t>>VETOR INVERSAMENTE ORDENADO");
  quickInv();
  printf("\n----------------------------------------------------");
  printf("\n\t\t\t\t\t>>40 VETORES DESORDENADOS");
  mediasMerge();
  printf("\n\n->MERGESORT:");
  printf("\t\t>>VETOR ORDENADO");
  mergeJaOrd();
  printf("\n\n\t\t\t\t\t>>VETOR INVERSAMENTE ORDENADO");
  mergeInv();
  printf("\n----------------------------------------------------");
  return 0;
}
