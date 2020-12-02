#include "header.h"
//
// Created by jypark on 12/2/20.
//
inc_insertion_sort(int list[], int first, int last, int gap)
{
    int i, j, key;
    for (i = first + gap; i <= last; i = i + gap) {
        key = list[i];
        for (j = i - gap; j >= first && key<list[j]; j = j - gap)
            list[j + gap] = list[j];
        list[j + gap] = key;
    }
}
//
void shell_sort(int list[], int n)   // n = size
{
    int i, gap;
    for (gap = n / 2; gap>0; gap = gap / 2) {
        if ((gap % 2) == 0) gap++;
        for (i = 0; i<gap; i++)		// ºÎºÐ ž®œºÆ®ÀÇ °³ŒöŽÂ gap
            inc_insertion_sort(list, i, n - 1, gap);
    }
}
//void main(){
//    int size = 100;
//    int list[size];
//    srand(time(NULL));
//    for(int i=0; i<size; i++)
//        list[i] = rand() % 200;
//    shell_sort(list, size);
//    for(int i=0; i<size; i++) {
//        if(i%10==0) printf("\n");
//        printf("%d ", list[i]);
//    }
//}