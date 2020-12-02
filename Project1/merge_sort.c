//
// Created by jypark on 12/2/20.
//

#include "header.h"

void merge(int list[], int left, int mid, int right)
{
    int i, j, k, l;
    i = left;  j = mid + 1;  k = left;


    while (i <= mid && j <= right) {
        if (list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }
    if (i>mid)
        for (l = j; l <= right; l++)
            sorted[k++] = list[l];
    else
        for (l = i; l <= mid; l++)
            sorted[k++] = list[l];
    for (l = left; l <= right; l++)
        list[l] = sorted[l];
}
void merge_sort(int list[], int left, int right)
{
    int mid;
    if (left<right) {
        mid = (left + right) / 2;
        merge_sort(list, left, mid);
        merge_sort(list, mid + 1, right);
        merge(list, left, mid, right);
    }
}
//void main(){
//    int size = 10;
//    int list[size];
//    srand(time(NULL));
//    for(int i=0; i<size; i++)
//        list[i] = rand() % 200;
//    for(int i=0; i<size; i++) {
//        if(i%10==0) printf("\n");
//        printf("%d ", list[i]);
//    }
//    merge_sort(list, 0, size-1);
//    for(int i=0; i<size; i++) {
//        if(i%10==0) printf("\n");
//        printf("%d ", list[i]);
//    }
//}