// Driver queue

#include "lib/queue.h"
#include <stdio.h>

void PrintQ (Queue Q)
{

}

int main(){
    // KAMUS
    Queue Q1;
    int X;
    // ALGORITMA
    CreateEmptyQ(&Q1, 5);
    printf("Q1 terbentuk dengan maxel 5\n");
    
    // Head di 1
    printf("HEAD DI 1\n");
    //menambah ketika kosong
    printf("menambah ketika kosong\n");
    AddQ(&Q1,2);
    printf("%d\n", headOfQueue(Q1));
    printf("%d\n", InfoTail(Q1));
    // menambah ketika sudah terisi
    printf("menambah ketika terisi\n");
    AddQ(&Q1,3);
    printf("%d\n", headOfQueue(Q1));
    printf("%d\n", InfoTail(Q1));
    printf("Banyak element Q1: %d\n", NBElmtQ(Q1));

    //menghapus head
    printf("menghapus head\n");
    DelQ(&Q1, &X);
    printf("%d\n", headOfQueue(Q1));
    printf("%d\n", InfoTail(Q1));

    // Head di 2
    printf("HEAD DI 2\n");

    //menambah tail masih di tabel setelah head
    printf("menambah tail di tabel setelah head\n");
    AddQ(&Q1,4);
    printf("%d\n", InfoTail(Q1));
    AddQ(&Q1,8);
    printf("%d\n", InfoTail(Q1));
    AddQ(&Q1,7);
    printf("%d\n", InfoTail(Q1));

    //menambah tail di tabel ke 1
    printf("menambah tail di tabel ke 1\n");
    AddQ(&Q1,9);
    printf("%d\n", InfoTail(Q1));
    printf("%d\n", InfoHead(Q1));

    // menghapus head
    printf("menghapus head\n");
    DelQ(&Q1, &X);
    printf("%d\n", InfoTail(Q1));
    printf("%d\n", InfoHead(Q1));

    // menambah taail di tabel sebelum head
    printf("menambah tail di tabel sebelum head\n");
    AddQ(&Q1, 7);
    printf("%d\n", InfoTail(Q1));
    printf("%d\n", InfoHead(Q1));

    return 0;
}