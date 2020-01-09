#include <stdio.h>
#include <stdlib.h>
#include "StatiqueHeap.h"
#define FALSE 0

Heap*createHeap()
{
    Heap *heap = malloc(sizeof(Heap));
    if(!heap) return NULL;
    heap->tab = malloc(80000*sizeof(int));   /* Prévoir l'échec de malloc */
    heap->capacity = 80000;
    heap->size = 0;
    return heap;
}


int HeapCapacity(Heap *heap)
{   
   if( heap==NULL){
	heap->capacity =-1;
   } 
   return  heap->capacity ;
   
}

int HeapSize(Heap *heap)
{   
   if( heap==NULL){
	heap->size = 0;
   } 
   return  heap->size;
   
}

int enfant_gauche(int i)
{
    int b = 2*i + 1;
    return b;
}

int enfant_droit(int i)
{
    int b = 2*i + 2;
    return b;
}

int parent(int i)
{
    int b = i / 2; //  return  b=i>>1;
    return b;
}

void entasserVersHaut(Heap *heap)
{
    int pos = heap->size ; // l indice ou on a ajouter notre element
    while (heap->tab[pos] < heap->tab[parent(pos)] && pos > 0)
    {
        int tmp = heap->tab[parent(pos)];
        heap->tab[parent(pos)] = heap->tab[pos];
        heap->tab[pos] = tmp;
        pos = parent(pos);
    }
}


int extraire_min(Heap *heap)
{
    int min = heap->tab[0];
    heap->tab[0] = heap->tab[heap->size -1];
    heap->size = heap->size-1;
    entasser(heap, 0);
    return min;
}

void entasser(Heap *heap, int i)
{
    int min;
    // g c est l indice de fils gauche
    int g = enfant_gauche(i);
    // g c est l indice de fils droit
    int d = enfant_droit(i);
    if (g < heap->size && heap->tab[g] < heap->tab[i])
    {
        min = g;
    }
    else
    {
        min = i;
    }

    if (d < heap->size && heap->tab[d] < heap->tab[i])
    {
        min = d;
    }
    if (min != i)
    {

        int tmp = heap->tab[i];
        heap->tab[i] = heap->tab[min];
        heap->tab[min] = tmp;
        entasser(heap, min);
    }
}

/***************************************************************************/
char pushNode(Heap *heap, int value)
{
    char memory_allocation = FALSE; 
    if(heap->size < heap->capacity){
    	heap->tab[heap->size] = value;
    	entasserVersHaut(heap);
   	heap->size++;
	
       } else { printf("le tableau est plein vous ne pouvez pas inserer");
      }
     
 return memory_allocation;   
}

void freeHeap(Heap *heap)
{
    free(heap->tab);
    free(heap);
}






















