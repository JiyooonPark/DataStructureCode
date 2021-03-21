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
//int runSimulation(int A[], int n, int k){
//    int r = 0;
//    int i=0;
//    while(n > 1){
////        printf("%d: ",n);
////        printList(A,7);
//        i = 0;
////        printf("r: %d\n",r);
//        while(i < k) {
////            printf("i: %d\n",i);
//            r = (r + 1) % 7;
////            printf("r: %d\n",r);
//            if (A[r] != 0) {
//                i = i + 1;
//            }
//        }
//        A[r] = 0;
//        n = n-1;
//        while(A[r] == 0){
//            r = (r+1) % 7;
//        }
////        printf("r: %d\n",r);
//    }
//    return A[r];
//}
//int candle(int A[],int n, int k){
//    buildList(A, n);
//    return runSimulation(A, n, k);
//}
//int main() {
//    int A[7];
//    printf("the candle is %d",candle(A,7,3));
//}
//
//
