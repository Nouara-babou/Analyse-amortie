
#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int capacity; 	/*la capacité du tableau, c'est-à-dire sa taille réelle, Le tableau sera agrandi seulement quand sa taille aura atteint la capacité du tableau*/
    int size;  //la taille du tableau, c'est-à-dire le nombre d'éléments contientle tableau 
    int *tab; // on pointe vers un tableau tab
} Heap;


Heap*createHeap();
int HeapCapacity(Heap *heap);
int HeapSize(Heap *heap);
int enfant_gauche(int i);
int enfant_droit(int i);
int parent(int i);
void entasserVersHaut(Heap *heap);
int extraire_min(Heap *heap);
void entasser(Heap *heap, int i);
char pushNode(Heap *heap, int value);
void freeHeap(Heap *heap);






