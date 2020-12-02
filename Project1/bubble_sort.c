//
// Created by jypark on 12/2/20.
//

#include "header.h"
void bubble_sort(int list[], int n)
{
    int i, j, temp;
    for (i = n - 1; i>0; i--) {
        for (j = 0; j<i; j++)
            /* ŸÕµÚÀÇ ·¹ÄÚµåžŠ ºñ±³ÇÑ ÈÄ ±³ÃŒ */
            if (list[j]>list[j + 1])
                SWAP(list[j], list[j + 1], temp);
    }
}
//void main(){
//    int size = 100;
//    int list[size];
//    srand(time(NULL));
//    for(int i=0; i<size; i++)
//        list[i] = rand() % 200;
//    bubble_sort(list, size);
//    for(int i=0; i<size; i++) {
//        if(i%10==0) printf("\n");
//        printf("%d ", list[i]);
//    }
//}