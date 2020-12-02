//
// Created by jypark on 12/2/20.
//

#include "header.h"

void insertion_sort(int list[], int n)
{
    int i, j, key;
    for (i = 1; i<n; i++) {
        key = list[i];
        for (j = i - 1; j >= 0 && list[j]>key; j--)
            list[j + 1] = list[j];
        list[j + 1] = key;
    }
}
//void main(){
//    int size = 100;
//    int list[size];
//    srand(time(NULL));
//    for(int i=0; i<size; i++)
//        list[i] = rand() % 200;
//    insertion_sort(list, size);
//    for(int i=0; i<size; i++) {
//        if(i%10==0) printf("\n");
//        printf("%d ", list[i]);
//    }
//}