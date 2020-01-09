// une structure qui contiendra un pointeur sur le tableau de données

typedef struct
{
    int capacity; 	/*la capacité du tableau, c'est-à-dire sa taille réelle, Le tableau sera agrandi seulement quand sa taille aura atteint la capacité du tableau*/
    int size;  //la taille du tableau, c'est-à-dire le nombre d'éléments contientle tableau 
    int *tab; // on pointe vers un tableau tab
} Heap;


Heap* createHeap();
char heap_do_we_need_to_enlarge_capacity(Heap * heap);
void HeapRealloc(Heap *heap);
int HeapCapacity(Heap *heap);
int HeapSize(Heap *heap);
char pushNode(Heap *heap, int value);
int enfant_gauche(int i);
int enfant_droit(int i);
int parent(int i);
void entasserVersHaut(Heap *heap);
char extraire_min(Heap *heap);
void entasser(Heap *heap, int i);
void freeHeap(Heap *heap);
void Heap_reduce_capacity(Heap * heap);
char Heap_do_we_need_to_reduce_capacity(Heap * heap);

