#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordenacao.h"

void imprime (int vetor[], int tamanho)
{
    int i;

    for (i = 0; i <= (tamanho - 1); i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return;
}

int *gera (int vetor[], int tamanho)
{
    for (int i = 0; i <= (tamanho - 1); i++)
    {
        vetor[i] = (rand() %50);
    }

    return vetor;
}

int *cres (int vetor[], int tamanho)
{
    for (int i = 0; i <= (tamanho - 1); i++)
    {
        vetor[i] = i;
    }

    return vetor;
}

int *dec (int vetor[], int tamanho)
{
    for (int i = 0; i <= tamanho; i++)
    {
        vetor[i] = -i;
    }

    return vetor;
}

int main() 
{
    srand(0);

    char nome[MAX_CHAR];
    int numComp;

    int tamVetor;
    int imp;

    printf("Qual o tamanho do vetor?\n");
    scanf("%d", &tamVetor);

    int* vetor = (int*)malloc(tamVetor * sizeof(int));
    if (vetor == NULL) {
        printf("Falha fatal. Impossível alocar memoria.");
        return 1;
    }

    getNome(nome);
    printf("Trabalho de %s\n", nome);
    printf("GRR %u\n", getGRR());

    printf ("Deseja imprimir o vetor? 0 - nao, 1 - sim\n");
    scanf ("%d", &imp);

    printf("\n");

    printf ("--------------------------XXX--------------------------\n");
    printf ("                    VETOR ALEATORIO:\n");
    printf ("--------------------------XXX--------------------------\n");
    printf ("\n");
    printf ("\n");
    printf ("\n");


    
    vetor = gera(vetor, tamVetor);

    if (imp)
    {
        printf("O vetor desordenado eh:\n");
        imprime(vetor, tamVetor);
    }
    
    numComp = mergeSort(vetor, tamVetor);
    if (imp)
    {
        printf("O vetor ordenado pelo MERGESORT eh:\n");
        imprime(vetor, tamVetor);
    }

    printf("NumComp MERGESORT: %d\n", numComp);
    

    printf("\n");
    printf("\n");
    


    
    vetor = gera(vetor, tamVetor);

    if (imp)
    {
        printf("O vetor desordenado eh:\n");
        imprime(vetor, tamVetor);
    }
    
    numComp = quickSort(vetor, tamVetor);
    if (imp)
    {
        printf("O vetor ordenado pelo QUICKSORT eh:\n");
        imprime(vetor, tamVetor);
    }

    printf("NumComp QUICKSORT: %d\n", numComp);
    

    printf("\n");
    printf("\n");


    
    vetor = gera(vetor, tamVetor);

    if (imp)
    {
        printf("O vetor desordenado eh:\n");
        imprime(vetor, tamVetor);
    }
    
    numComp = heapSort(vetor, tamVetor);
    if (imp)
    {
        printf("O vetor ordenado pelo HEAPSORT eh:\n");
        imprime(vetor, tamVetor);
    }

    printf("NumComp HEAPSORT: %d\n", numComp);
    

    printf("\n");
    printf("\n");
    

    
    
    vetor = gera(vetor, tamVetor);

    if (imp)
    {
        printf("O vetor desordenado eh:\n");
        imprime(vetor, tamVetor);
    }
    
    numComp = mergeSortSR(vetor, tamVetor);
    if (imp)
    {
        printf("O vetor ordenado pelo MERGESORT SEM RECURSAO eh:\n");
        imprime(vetor, tamVetor);
    }

    printf("NumComp MERGESORT sem recursao: %d\n", numComp);
    

    printf("\n");
    printf("\n");
    



    
    vetor = gera(vetor, tamVetor);

    if (imp)
    {
        printf("O vetor desordenado eh:\n");
        imprime(vetor, tamVetor);
    }
    
    numComp = quickSortSR(vetor, tamVetor);
    if (imp)
    {
        printf("O vetor ordenado pelo QUICKSORT SEM RECURSAO eh:\n");
        imprime(vetor, tamVetor);
    }

    printf("NumComp QUICKSORT sem recursao: %d\n", numComp);
    

    printf("\n");
    printf("\n");



    
    vetor = gera(vetor, tamVetor);

    if (imp)
    {
        printf("O vetor desordenado eh:\n");
        imprime(vetor, tamVetor);
    }
    
    numComp = heapSortSR(vetor, tamVetor);
    if (imp)
    {
        printf("O vetor ordenado pelo QUICKSORT SEM RECURSAO eh:\n");
        imprime(vetor, tamVetor);
    }

    printf("NumComp HEAPSORT sem recursao: %d\n", numComp);
    
    
    printf("\n");
    printf("\n");

    printf ("--------------------------XXX--------------------------\n");
    printf ("             VETOR CRESCENTE E DECRESCENTE:\n");
    printf ("--------------------------XXX--------------------------\n");
    printf ("\n");
    printf ("\n");
    printf ("\n");
    

    
    vetor = cres(vetor, tamVetor);
    
    if (imp)
    {
        printf("O vetor crescente eh:\n");
        imprime(vetor, tamVetor);
    }

    numComp = mergeSort(vetor, tamVetor);

    if (imp)
    {
        printf("O vetor ordenado pelo MERGESORT eh:\n");
        imprime(vetor, tamVetor);
    }

    printf("NumComp MERGESORT: %d\n", numComp);

    vetor = dec(vetor, tamVetor);
    if (imp)
    {
        printf("O vetor decrescente eh:\n");
        imprime(vetor, tamVetor);
    }

    numComp = mergeSort(vetor, tamVetor);

    if (imp)
    {
        printf("O vetor ordenado pelo MERGESORT eh:\n");
        imprime(vetor, tamVetor);
    }
    
    printf("NumComp MERGESORT: %d\n", numComp);
    printf("\n");
    printf("\n");



    vetor = cres(vetor, tamVetor);
    
    if (imp)
    {
        printf("O vetor crescente eh:\n");
        imprime(vetor, tamVetor);
    }

    numComp = quickSort(vetor, tamVetor);

    if (imp)
    {
        printf("O vetor ordenado pelo QUICKSORT eh:\n");
        imprime(vetor, tamVetor);
    }

    printf("NumComp QUICKSORT: %d\n", numComp);

    vetor = dec(vetor, tamVetor);
    if (imp)
    {
        printf("O vetor decrescente eh:\n");
        imprime(vetor, tamVetor);
    }

    numComp = quickSort(vetor, tamVetor);

    if (imp)
    {
        printf("O vetor ordenado pelo QUICKSORT eh:\n");
        imprime(vetor, tamVetor);
    }
    
    printf("NumComp QUICKSORT: %d\n", numComp);
    printf("\n");
    printf("\n");



    vetor = cres(vetor, tamVetor);
    
    if (imp)
    {
        printf("O vetor crescente eh:\n");
        imprime(vetor, tamVetor);
    }

    numComp = heapSort(vetor, tamVetor);

    if (imp)
    {
        printf("O vetor ordenado pelo HEAPSORT eh:\n");
        imprime(vetor, tamVetor);
    }

    printf("NumComp HEAPSORT: %d\n", numComp);

    vetor = dec(vetor, tamVetor);
    if (imp)
    {
        printf("O vetor decrescente eh:\n");
        imprime(vetor, tamVetor);
    }

    numComp = heapSort(vetor, tamVetor);

    if (imp)
    {
        printf("O vetor ordenado pelo HEAPSORT eh:\n");
        imprime(vetor, tamVetor);
    }
    
    printf("NumComp HEAPSORT: %d\n", numComp);
    printf("\n");
    printf("\n");
    





    
    vetor = cres(vetor, tamVetor);
    
    if (imp)
    {
        printf("O vetor crescente eh:\n");
        imprime(vetor, tamVetor);
    }

    numComp = mergeSortSR(vetor, tamVetor);

    if (imp)
    {
        printf("O vetor ordenado pelo MERGESORT sem recursao eh:\n");
        imprime(vetor, tamVetor);
    }

    printf("NumComp MERGESORT sem recursao: %d\n", numComp);

    vetor = dec(vetor, tamVetor);
    if (imp)
    {
        printf("O vetor decrescente eh:\n");
        imprime(vetor, tamVetor);
    }

    numComp = mergeSortSR(vetor, tamVetor);

    if (imp)
    {
        printf("O vetor ordenado pelo MERGESORT sem recursao eh:\n");
        imprime(vetor, tamVetor);
    }
    
    printf("NumComp MERGESORT sem recursao: %d\n", numComp);
    printf("\n");
    printf("\n");
    


    
    vetor = cres(vetor, tamVetor);
    
    if (imp)
    {
        printf("O vetor crescente eh:\n");
        imprime(vetor, tamVetor);
    }

    numComp = quickSortSR(vetor, tamVetor);

    if (imp)
    {
        printf("O vetor ordenado pelo QUICKSORT sem recursao eh:\n");
        imprime(vetor, tamVetor);
    }

    printf("NumComp QUICKSORT sem recursao: %d\n", numComp);

    vetor = dec(vetor, tamVetor);
    if (imp)
    {
        printf("O vetor decrescente eh:\n");
        imprime(vetor, tamVetor);
    }

    numComp = quickSortSR(vetor, tamVetor);

    if (imp)
    {
        printf("O vetor ordenado pelo QUICKSORT sem recursao eh:\n");
        imprime(vetor, tamVetor);
    }
    
    printf("NumComp QUICKSORT sem recursao: %d\n", numComp);
    printf("\n");
    printf("\n");



    vetor = cres(vetor, tamVetor);
    
    if (imp)
    {
        printf("O vetor crescente eh:\n");
        imprime(vetor, tamVetor);
    }

    numComp = heapSortSR(vetor, tamVetor);

    if (imp)
    {
        printf("O vetor ordenado pelo HEAPSORT sem recursao eh:\n");
        imprime(vetor, tamVetor);
    }

    printf("NumComp HEAPSORT sem recursao: %d\n", numComp);

    vetor = dec(vetor, tamVetor);
    if (imp)
    {
        printf("O vetor decrescente eh:\n");
        imprime(vetor, tamVetor);
    }

    numComp = heapSortSR(vetor, tamVetor);

    if (imp)
    {
        printf("O vetor ordenado pelo HEAPSORT sem recursao eh:\n");
        imprime(vetor, tamVetor);
    }
    
    printf("NumComp HEAPSORT sem recursao: %d\n", numComp);
    printf("\n");
    printf("\n");
    

    free(vetor);

    return 0;
}