/*créer et initialiser la structure CreateHeap, elle nous retournera un pointeur initialisé sur une structure Heap. */
#include <stdlib.h>
#include <stdio.h>
#include "DynamiqueHeap.h"
#define TRUE 1
#define FALSE 0
Heap*createHeap()
{
    Heap *heap = malloc(sizeof(Heap));
    if(!heap) return NULL;
    heap->tab = malloc(32*sizeof(int));   /* Prévoir l'échec de malloc */
     heap->capacity =32;
    heap->size = 0;
    return heap;
}
//Cette fonction permet de réallouer un bloc de mémoire dans le tas (le heap en anglais). Cela veut dire que si l'espace mémoire libre qui suit le bloc à réallouer est suffisament grand, le bloc de mémoire est simplement agrandi. Par contre si l'espace libre n'est pas suffisant, un nouveau bloc de mémoire sera alloué, le contenu de la zone d'origine recopié dans la nouvelle zone et le bloc mémoire d'origine sera libéré automatiquement


/*void HeapRealloc(Heap *heap)
{
    int new_size = 2*(heap->capacity);
    heap->tab = realloc(heap->tab, new_size*sizeof(int));                                    //  Prévoir l'échec de realloc 
    heap->capacity = new_size;
    printf("voila la nouvelle taille du tableau : %d",new_size);
    printf("\n");
}*/
void HeapRealloc(Heap *heap)
{
    int new_size=20*(heap->capacity);
    heap->tab = realloc(heap->tab, new_size*sizeof(int));                                    //  Prévoir l'échec de realloc 
    heap->capacity = new_size;
    //printf("voila la nouvelle taille du tableau : %d",new_size);
    //printf("\n");
} 


/*void HeapRealloc(Heap *heap)
{
    int new_size = 2*(heap->capacity);
    heap->tab = realloc(heap->tab, new_size*sizeof(int));                                    //  Prévoir l'échec de realloc 
    heap->capacity = new_size;
    printf("bravo tu as reussi a élargir le tas");
    printf("\n");
}


void HeapRealloc(Heap *heap)
{
    int new_size = 1.52*(heap->capacity);
    heap->tab = realloc(heap->tab, new_size*sizeof(int));                                    //  Prévoir l'échec de realloc 
    heap->capacity = new_size;
    //printf("bravo tu as reussi a élargir le tas");
    //printf("\n");
}
void HeapRealloc(Heap *heap)
{
    int new_size = 3*(heap->capacity);
    heap->tab = realloc(heap->tab, new_size*sizeof(int));                                    //  Prévoir l'échec de realloc 
    heap->capacity = new_size;
    //printf("bravo tu as reussi a élargir le tas");
    //printf("\n");
}
void HeapRealloc(Heap *heap)
{
    int new_size = 1.8*(heap->capacity);
    heap->tab = realloc(heap->tab, new_size*sizeof(int));                                    //  Prévoir l'échec de realloc 
    heap->capacity = new_size;
    printf("bravo tu as reussi a élargir le tas");
    printf("\n");
}void HeapRealloc(Heap *heap)
{
    int new_size = 3*(heap->capacity);
    heap->tab = realloc(heap->tab, new_size*sizeof(int));                                    //  Prévoir l'échec de realloc 
    heap->capacity = new_size;
    printf("bravo tu as reussi a élargir le tas");
    printf("\n");
}*/

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

/***************************************************************************/

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

char extraire_min(Heap *heap)
{    char memory_reduction = FALSE;
     if (heap!=NULL && heap->size>0){
		if (Heap_do_we_need_to_reduce_capacity(heap)){
			memory_reduction = TRUE;
			Heap_reduce_capacity(heap);
		}
     	 //int min = heap->tab[0];
     	heap->tab[0] = heap->tab[heap->size-1];
     	heap->size = heap->size-1;
    	entasser(heap, 0);
        entasser(heap, 0);
        //printf(" le min extrait  egal %d",min);
        //printf("\n");
     }
  return memory_reduction;
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
{    char memory_allocation = FALSE;
    if (heap!=NULL){
		if( heap_do_we_need_to_enlarge_capacity(heap)){
			memory_allocation = TRUE;
			HeapRealloc(heap);
		}
   
    	heap->tab[heap->size] = value;
    	entasserVersHaut(heap);
    	heap->size++;
	//printf("vous avez elargi la capacité du tableau");
     }
	
  return memory_allocation; 
}

char heap_do_we_need_to_enlarge_capacity(Heap * heap){
	return (heap->size == heap->capacity)? TRUE: FALSE;
}

void freeHeap(Heap *heap)
{
    free(heap->tab);
    free(heap);
}

void Heap_reduce_capacity(Heap * heap){
	heap->capacity /= 2;
	heap->tab = (int *)  realloc(heap->tab, sizeof(int) * heap->capacity);
}
char Heap_do_we_need_to_reduce_capacity(Heap * heap){
	return ( heap->size <= heap->capacity/4 && heap->size >4 )? TRUE: FALSE;
}

























