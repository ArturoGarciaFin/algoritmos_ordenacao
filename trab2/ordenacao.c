#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.h"
#include <string.h>

void getNome(char nome[]) {
    //substitua por seu nome
    strncpy(nome, "Arturo Garcia Fin", MAX_CHAR);
    // adicionada terminação manual para caso de overflow
    nome[MAX_CHAR - 1] = '\0';
}

// a função a seguir deve retornar o seu número de GRR
uint32_t getGRR() {return 20235588;}



//definicao de um nodo, usado na pilha
struct nodo
{
    int chave;
    struct nodo *prox;
};

//definicao da pilha
struct pilha
{
    struct nodo *ini;
    int tamanho;
};

//funcao para criar pilha
struct pilha *cria_pilha ()
{
    struct pilha *p = (struct pilha *)malloc(1 * sizeof(struct pilha));
    if (p == NULL)
    {
        printf ("Falha fatal. Impossível alocar memória");
        return NULL;
    }

    p->ini = NULL;
    p->tamanho = 0;

    return p;
}

//desaloca a pilha e faz ela receber null
void destroi_pilha (struct pilha **pilha)
{
    struct nodo *aux;

    while ((*pilha)->ini != NULL)
    {
        aux = (*pilha)->ini;
        (*pilha)->ini = (*pilha)->ini->prox;
        free(aux);
    }

    free(*pilha);
    (*pilha) = NULL;

    return;
}

//empilha, recebe 1 se funcionou, 0 se falhou
int empilha (struct pilha *pilha, int dado)
{
    struct nodo *novo = (struct nodo *)malloc(1 * sizeof(struct nodo));
    if (novo == NULL)
    {
        printf ("Falha fatal. Impossível alocar memória");
        return 0;
    }

    novo->chave = dado;
    novo->prox = pilha->ini;

    pilha->ini = novo;
    (pilha->tamanho)++;

    return 1;
}

//desempilha, retorna valor desempilhado
int desempilha (struct pilha *pilha)
{
    struct nodo *aux;
    int dado;

    if (pilha->tamanho == 0)
        return 0;

    dado = pilha->ini->chave;

    aux = pilha->ini;
    pilha->ini = pilha->ini->prox;
    (pilha->tamanho)--;

    free(aux);
    aux = NULL;

    return dado;
}



//funcao troca
void swap (int *a, int *b)
{
    int aux;

    aux = *a;
    *a = *b;
    *b = aux;
}

//funcao auxiliar de copia de vetor
void copiar (int v[], int a, int b, int u[]) 
{
    for (int i = 0; i <= b - a; i++) 
        v[a + i] = u[i];
}

//funcao merge para o algoritmo recursivo
int merge (int vetor[], int a, int m, int b, int *numComp)
{
    if (a >= b)
        return 0;

    int tam = b - a + 1;
    int *v2 = (int *)malloc(tam * sizeof(int));
    if (v2 == NULL)
    {
        printf("Falha fatal. Impossível alocar memória");
        return 0;
    }

    int q;
    int k = 0;
    int i = a;
    int j = m + 1;

    while (k <= b - a)
    {
        (*numComp)++;
        if (j > b || (i <= m && vetor[i] <= vetor[j]))
        {
            q = i;
            i++;
        }
        else
        {
            q = j;
            j++;
        }

        v2[k] = vetor[q];
        k++;
    }

    copiar(vetor, a, b, v2);

    free(v2);
    v2 = NULL;

    return *numComp;
}

/*funcao auxiliar merge para o mergesort sem recursao, adaptada de
  Sryheni, Said. Non-Recursive MergeSort. Baeldung CS, 2023*/

void mergeSR(int vetor[], int esqa, int dira, int esqb, int dirb, int *numComp)
{
    int tam = dirb - esqa + 1;

    int *v2 = (int *)malloc(tam * sizeof(int));
    if (v2 == NULL)
    {
        printf("Falha fatal. Impossível alocar memória");
        return;
    }

    int i = 0;
    int esquerda = esqa;
    int direita = esqb;

    while (esquerda <= dira && direita <= dirb)
    {
        (*numComp)++;
        if (vetor[esquerda] <= vetor[direita])
        {
            v2[i++] = vetor[esquerda++];
        }
        else
        {
            v2[i++] = vetor[direita++];
        }
    }

    while (esquerda <= dira)
    {
        v2[i++] = vetor[esquerda++];
    }

    while (direita <= dirb)
    {
        v2[i++] = vetor[direita++];
    }

    for (i = 0; i < tam; i++)
    {
        vetor[esqa + i] = v2[i];
    }

    free(v2);
}

//funcao para particionar vetor
int particiona (int vetor[], int a, int b, int *numComp)
{
    int x, m, i;

    x = vetor[b];
    m = a;

    for (i = a; i <= b; i++)
    {
        (*numComp)++;
        if (vetor[i] < x)
        {
            swap(&vetor[m], &vetor[i]);
            m++;
        }
    }

    swap(&vetor[m], &vetor[b]); //coloca o pivo na posicao correta

    return m;
}

//funcao auxiliar para construir uma maxheap recursiva
void maxHeapifyRec (int vetor[], int no, int tam, int *numComp)
{
    int m, l, r;

    m = no;
    l = 2 * no + 1;
    r = 2 * no + 2;

    if (l < tam)
    {
        (*numComp)++;
        if (vetor[l] > vetor[m])
            m = l;
    }

    if (r < tam)
    {
        (*numComp)++;
        if (vetor[r] > vetor[m])
            m = r;
    }

    if (m != no)
    {
        swap (&vetor[no], &vetor[m]);
        maxHeapifyRec (vetor, m, tam, numComp);
    }
}

//constroi uma maxheap recursivamente
int buildMaxHeapRec (int vetor[], int tam, int *numComp)
{
    int i;

    for (i = (tam / 2) - 1; i >= 0; i--)
        maxHeapifyRec (vetor, i, tam, numComp);

    return *numComp;
}

//funcao auxiliar para construir maxheap sem recursao
void maxHeapifySR (int vetor[], int no, int tam, int *numComp)
{
    int m, l, r;

    m = no;
    l = 2 * no + 1;
    r = 2 * no + 2;

    while (l < tam || r < tam)
    {
        if (l < tam)
        {
            (*numComp)++;
            if (vetor[l] > vetor[m])
                m = l;
        }

        if (r < tam)
        {
            (*numComp)++;
            if (vetor[r] > vetor[m])
                m = r;
        }

        if (m != no)
        {
            swap (&vetor[no], &vetor[m]);
            no = m;
            l = 2 * no + 1;
            r = 2 * no + 2;
        }
        else
            break;
    }
}

//funcao para construir maxheap
int buildMaxHeapSR (int vetor[], int tam, int *numComp)
{
    int i;

    for (i = (tam / 2) - 1; i >= 0; i--)
        maxHeapifySR (vetor, i, tam, numComp);

    return *numComp;
}

//funcao auxiliar mergesort recursivo
int wrapperMergeSortRec (int vetor[], int a, int b, int *numComp) 
{
    if (a >= b)
        return 0;

    int m = (a + b) / 2;

    wrapperMergeSortRec(vetor, a, m, numComp);
    wrapperMergeSortRec(vetor, m + 1, b, numComp);

    merge(vetor, a, m, b, numComp);

    return *numComp;
}

//funcao auxiliar quicksort recursivo
int wrapperQuickSortRec (int vetor[], int a, int b, int *numComp)
{
    if (a >= b)
        return 0;

    int m = particiona(vetor, a, b, numComp);

    wrapperQuickSortRec(vetor, a, m - 1, numComp);
    wrapperQuickSortRec(vetor, m + 1, b, numComp);

    return *numComp;
}

/*funcao auxiliar mergesort sem recursao, adaptada de Sedgewick, R.
  e Wayne, K. Algorithms Part 1. 4a ed, 2014. e de Sryheni, Said.
  Non-Recursive MergeSort. Baeldung CS, 2023*/

int wrapperMergeSortSR(int vetor[], int a, int b, int *numComp)
{
    int tam = b - a + 1;
    int esqa, esqb, dira, dirb;

    for (int i = 1; i < tam; i *= 2)
    {
        for (int j = 0; j < tam - i; j += 2 * i)
        {
            esqa = j;
            dira = j + i - 1;
            esqb = j + i;
            if ((j + 2 * i - 1) < tam)
                dirb = j + 2 * i - 1;
            else
                dirb = tam - 1;

            mergeSR(vetor, esqa, dira, esqb, dirb, numComp);
        }
    }

    return *numComp;
}

int wrapperQuickSortSR (int vetor[], int a, int b, struct pilha *p, int *numComp)
{
    int m;

    empilha (p, a);
    empilha (p, b);

    while (p->tamanho != 0)
    {
        b = desempilha (p);
        a = desempilha (p);

        if (a < b)
        {
            m = particiona (vetor, a, b, numComp);
            empilha (p, a);
            empilha (p, m - 1);
            empilha (p, m + 1);
            empilha (p, b);
        }
    }

    return *numComp;
}

uint64_t mergeSort(int vetor[], size_t tam) 
{
    int numComp = 0;

    return wrapperMergeSortRec(vetor, 0, tam - 1, &numComp);
}

uint64_t quickSort(int vetor[], size_t tam) 
{
    int numComp = 0;

    return wrapperQuickSortRec(vetor, 0, tam - 1, &numComp);
}

uint64_t heapSort(int vetor[], size_t tam)
{
    int i, numComp;

    numComp = 0;
    buildMaxHeapRec (vetor, tam, &numComp);

    for (i = tam - 1; i > 0; i--)
    {
        swap (&vetor[0], &vetor[i]);
        maxHeapifyRec (vetor, 0, i, &numComp);
    }

    return numComp;
}


uint64_t mergeSortSR(int vetor[], size_t tam)
{
    int numComp = 0;

    numComp = wrapperMergeSortSR (vetor, 0, tam - 1, &numComp);

    return numComp;
}

uint64_t quickSortSR(int vetor[], size_t tam)
{
    struct pilha *p;
    int numComp = 0;

    p = cria_pilha ();

    wrapperQuickSortSR (vetor, 0, tam - 1, p, &numComp);

    destroi_pilha (&p);

    return numComp;
}

uint64_t heapSortSR(int vetor[], size_t tam)
{
    int i, numComp;

    numComp = 0;

    buildMaxHeapSR (vetor, tam, &numComp);

    for (i = tam - 1; i > 0; i--)
    {
        swap (&vetor[0], &vetor[i]);
        maxHeapifySR (vetor, 0, i, &numComp);
    }

    return numComp;
}