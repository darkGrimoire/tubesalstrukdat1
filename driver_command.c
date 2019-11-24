/* Driver Command ehe */
/* By Fawwis */

#include "lib\boolean.h"
#include "lib\command.h"
#include <stdlib.h>
#include <stdio.h>

/* GLOBAL VARIABLES */
Queue GQUEUE[2];
FLAGS GFLAGS[2];
List GLIST[2];
TabInt arrBan;
Stack S;

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

void printStat(){
    printFlags(GFLAGS[0]); printFlags(GFLAGS[1]);
    printf("Lists: "); PrintInfo(GLIST[0]); PrintInfo(GLIST[1]); printf("\n");
    printf("Head(Q): "); printf("%d ",headOfQueue(GQUEUE[0])); printf("%d\n",headOfQueue(GQUEUE[1]));
    printBuildings(GLIST[0]); printf("\n");printBuildings(GLIST[1]);
}

int main(){
    // Generate FLAGS
    CreateFlag(&GFLAGS[0]); 
    CreateFlag(&GFLAGS[1]); SetAUFlag(&GFLAGS[0], true);
    // Generate Bangunan
    MakeEmpty(&arrBan, 100);
    BANGUNAN B[6];
    B[0] = SetBangunan(1, 'C', MakePOINT(1,2));
    B[1] = SetBangunan(1, 'T', MakePOINT(3,4));
    B[2] = SetBangunan(1, 'F', MakePOINT(5,6));
    B[3] = SetBangunan(2, 'C', MakePOINT(7,8));
    B[4] = SetBangunan(2, 'T', MakePOINT(9,10));
    B[5] = SetBangunan(2, 'F', MakePOINT(11,12)); 
    for (int i=0; i<6;i++){
        arrBan.TI[i] = B[i];
    }
    arrBan.Neff = 6; 
    // Generate List Kepemilikan Bangunan
    CreateList(&GLIST[0]); CreateList(&GLIST[1]);
    InsVLast(&GLIST[0], 0); InsVLast(&GLIST[0], 1); InsVLast(&GLIST[0], 2);
    InsVLast(&GLIST[1], 3); InsVLast(&GLIST[1], 4); InsVLast(&GLIST[1], 5);
    // Generate Skill Queue
    CreatePlayerQueue(&GQUEUE[0], 10);
    CreatePlayerQueue(&GQUEUE[1], 10); 
    // Generate Stack
    CreateStack(&S); 
    UpdateSTACK();
    // Print kondisi awal
    printStat();
    // Testing: Attack
    ATTACK(GLIST[1],2,3,40,1);
    printStat();
    

    return 0;
}