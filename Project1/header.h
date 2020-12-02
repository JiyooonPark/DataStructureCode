#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ELEMENT 200

#define MAX_SIZE 10
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int sorted[10];
int list[MAX_SIZE];
int n;

//bubble_sort.c
void bubble_sort(int list[], int n);

//insertion_sort.c
void insertion_sort(int list[], int n);

//selection_sort.c
void selection_sort(int list[], int n);

//shell_sort.c
inc_insertion_sort(int list[], int first, int last, int gap);
void shell_sort(int list[], int n) ;

//merge_sort.c
void merge(int list[], int left, int mid, int right);
void merge_sort(int list[], int left, int right);

//quick_sort.c
int partition(int list[], int left, int right);
void quick_sort(int list[], int left, int right);

//heap_sort.c

//HeapType* create();
//void init(HeapType* h);
//void insert_max_heap(HeapType* h, element item);
//element delete_max_heap(HeapType* h);
//void heap_sort(element a[], int n);

//radix_sort.c
void radix_sort(int list[], int n);



