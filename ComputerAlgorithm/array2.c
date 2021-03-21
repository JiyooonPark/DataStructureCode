////
//// Created by jypark on 3/21/21.
////
//#include <stdio.h>
//#include <stdlib.h>
//
//void buildList(int A[], int n){
//
//    for(int r=0; r < n; r++){
//        A[r] = r+1;
//    }
//}
//int printList(int A[], int n){
//    for(int i=0; i<n; i++){
//        printf("%d ",A[i]);
//    }
//    printf("\n");
//}
//int* removeElem(int A[], int n, int pos){
////    printf("removing \n");
//    int* temp = malloc(sizeof(int)*(n-1));
//
//    for(int i=pos; i<n-1; i++){
//        A[i] = A[i+1];
//    }
//    for(int i=0; i<n-1; i++){
//        temp[i] = A[i];
//    }
////    printList(temp, n-1);
//    return temp;
//}
//int runSimulation(int* A, int n, int k){
//    int r = 0;
//    while(n>1){
//        printf("%d: ",n);
//        printList(A,n);
//        r = (r+k)%n;
//        A = removeElem(A, n, r);
//        n = n-1;
//    }
//    return A[0];
//}
//int candle(int * A,int n, int k){
//    buildList(A, n);
//    printList(A, n);
//    return runSimulation(A, n, k);
////    return 1;
//}
//int main() {
//    int *A = malloc(sizeof(int)*7);
//    printList(A,7);
//    printf("%d",candle(A,7,3));
//}
//
