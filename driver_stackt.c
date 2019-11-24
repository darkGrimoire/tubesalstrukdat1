/* File : driver_stackt.c */
/* Driver dari ADT Stack */

#include "lib/bangunan.h"
#include "lib/listlinier.h"
#include "lib/queue.h"
#include "lib/arraydin.h"
#include "lib/stackt.h"
#include "lib/command.h"
#include "lib/point.h"
#include "lib/listlinier.h"
#include <stdio.h>

void printFlags(FLAGS F){
    printf("FLAGS: %d %d %d %d %d %d\n", GetSFlag(F), GetShieldCD(F), GetAUFlag(F), GetCHFlag(F), GetETFlag(F), GetWFlag(F));
}

void printBuildings(List L){ // pake list L parameternya
    // KAMUS LOKAL
        address P;
    // ALGORITMA
        P = First(L);
        while(P!=NilL){
            if(jenis(bangunan(arrBan,Info(P))) == 'C'){
                printf("Castle ");
                TulisPOINT(lok(bangunan(arrBan,Info(P))));
                printf(" ");
                printf("%d",pasukan(bangunan(arrBan,Info(P))));
                printf(" ");
                printf("lv. ");
                printf("%d",level(bangunan(arrBan,Info(P))));
            }
            else if(jenis(bangunan(arrBan,Info(P))) == 'T'){
                printf("Tower ");
                TulisPOINT(lok(bangunan(arrBan,Info(P))));
                printf(" ");
                printf("%d",pasukan(bangunan(arrBan,Info(P))));
                printf(" ");
                printf("lv. ");
                printf("%d",level(bangunan(arrBan,Info(P))));
            }
            else if(jenis(bangunan(arrBan,Info(P))) == 'F'){
                printf("Fort ");
                TulisPOINT(lok(bangunan(arrBan,Info(P))));
                printf(" ");
                printf("%d",pasukan(bangunan(arrBan,Info(P))));
                printf(" ");
                printf("lv. ");
                printf("%d",level(bangunan(arrBan,Info(P))));
            }
            else if(jenis(bangunan(arrBan,Info(P))) == 'V'){
                printf("Village ");
                TulisPOINT(lok(bangunan(arrBan,Info(P))));
                printf(" ");
                printf("%d",pasukan(bangunan(arrBan,Info(P))));
                printf(" ");
                printf("lv. ");
                printf("%d",level(bangunan(arrBan,Info(P))));
            }
        printf(" | ");
        P = Next(P);
        }
}

void printAll(stackinfotype SIT) {
    printf("<----------- OVERALL SITUATION ---------->\n");
    printf("Skill yang bisa dipakai Player 1 :\n");
    printf("%d\n", headOfQueue((SIT).Q1));
    printf("Skill yang bisa dipakai Player 2 :\n");
    printf("%d\n", headOfQueue((SIT).Q2));
    printf("Flags Player 1 :\n");
    printFlags(*(SIT).GF[0]);
    printf("Flags Player 2 :\n");
    printFlags(*(SIT).GF[1]);
    printf("Isi List Player 1 :\n");
    printBuildings((SIT).L1);
    printf("\n");
    printf("Isi List Player 2 :\n");
    printBuildings((SIT).L2);
    printf("\n");
}

int main() {
    List L11, L22;
    stackinfotype SIT1, SIT2, SIT3, SIT;
    Queue Q11, Q22;
    Stack S;
    TabInt T;
    BANGUNAN B1, B2, B3, B4, B5, B6;
    FLAGS *F1, *F2;
    MakeBangunan(&B1, 1, 20, 10, 10, 10, 1, 3, 4, 'C');
    AddAsLastEl(&T, &B1);
    MakeBangunan(&B2, 1, 20, 10, 10, 10, 1, 3, 4, 'T');
    AddAsLastEl(&T, &B2);
    MakeBangunan(&B3, 1, 20, 10, 10, 10, 1, 3, 4, 'V');
    AddAsLastEl(&T, &B3);
    MakeBangunan(&B4, 2, 20, 10, 10, 10, 1, 3, 4, 'C');
    AddAsLastEl(&T, &B4);
    MakeBangunan(&B5, 2, 20, 10, 10, 10, 1, 3, 4, 'T');
    AddAsLastEl(&T, &B5);
    MakeBangunan(&B1, 2, 20, 10, 10, 10, 1, 3, 4, 'V');
    AddAsLastEl(&T, &B6);
    ListBPemilik();
    CreateEmptyQ(&Q11, 3);
    CreateEmptyQ(&Q22, 3);
    AddQ(&Q11, 1);
    AddQ(&Q11, 2);
    AddQ(&Q11, 3);
    AddQ(&Q22, 1);
    AddQ(&Q22, 2);
    AddQ(&Q22, 3);
    CreateFlag(F1);
    CreateFlag(F2);
    SetFlag(F1, 1, 2, 1, 1, 1, 1);
    SetFlag(F2, 1, 2, 1, 1, 1, 1);
    CreateStack(&S);
    if (IsEmptyStack(S)) {
        printf("Stack kosong\n");
    }
    else {
        printf("Stack tidak tidak kosong\n");
    }
    if (IsFullStack(S)) {
        printf("Stack penuh\n");
    }
    else {
        printf("Stack tidak penuh\n");
    }
    (SIT1).Q1 = Q11;
    (SIT1).Q2 = Q22;
    (SIT1).L1 = L11;
    (SIT1).L2 = L22;
    (SIT1).GF[0] = F1;
    (SIT1).GF[1] = F2;
    (SIT1).arrBan = T;
    Push(&S, SIT1);
    (SIT2).Q1 = Q11;
    (SIT2).Q2 = Q22;
    (SIT2).L1 = L11;
    (SIT2).L2 = L22;
    (SIT2).GF[0] = F1;
    (SIT2).GF[1] = F2;
    (SIT2).arrBan = T;
    Push(&S, SIT2);
    (SIT3).Q1 = Q11;
    (SIT3).Q2 = Q22;
    (SIT3).L1 = L11;
    (SIT3).L2 = L22;
    (SIT3).GF[0] = F1;
    (SIT3).GF[1] = F2;
    (SIT3).arrBan = T;
    Push(&S, SIT3);
    Pop(&S, &SIT);
    printAll(SIT);
    Pop(&S, &SIT);
    printAll(SIT);
    Pop(&S, &SIT);
    printAll(SIT);
    return 0;
}