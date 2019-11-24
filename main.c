#include <stdio.h>
#include <unistd.h>
#include "lib\mesinkatainput.h"
#include "lib\command.h"
#include "lib\queue.h"
#include "lib\bangunan.h"
#include "lib\saveload.h"
#include "lib\peta.h"
#include "lib\arraydin.h"
#include "lib\listlinier.h"
#include "lib\graph.h"
#include "lib\stackt.h"
#include "lib\point.h"

extern Queue GQUEUE[2];
Stack S;
Peta P;
Graph G;
FLAGS F, GFLAGS[2];
List GLIST[2];
TabInt arrBan;
const char* a;
const char* b;
char* c;
char tabkata[10];
Kata CKata;
int curPlayer, enemyPlayer;

boolean loseState (int player){
    // KAMUS LOKAL
        int i;
    // ALGORITMA
        return (NbElmtList(GLIST[curPlayer-1])==0);
}

void availableSkill (Queue Q) {
    // KAMUS LOKAL
        int skill;
    // ALGORITMA
        skill = headOfQueue(Q);
        if(skill==1){
            printf("Instant Upgrade");
        }
        else if(skill==2){
            printf("Shield");
        }
        else if(skill==3){
            printf("Extra Turn");
        }
        else if(skill==4){
            printf("Attack Up");
        }
        else if(skill==5){
            printf("Critical Hit");
        }
        else if(skill==6){
            printf("Instant Reinforcement");
        }
        else if(skill==7){
            printf("Barrage");
        }
        printf("\n");
}

void printBuildings(List L){ // pake list L parameternya
    // KAMUS LOKAL
        address A;
        int i;
    // ALGORITMA
        A = First(L);
        i=1;
        while(A!=NilL){
            printf("%d. ",i);
            if(jenis(bangunan(arrBan,Info(A))) == 'C'){
                printf("Castle ");
                TulisPOINT(lok(bangunan(arrBan,Info(A))));
                printf(" ");
                printf("%d",pasukan(bangunan(arrBan,Info(A))));
                printf(" ");
                printf("lv. ");
                printf("%d",level(bangunan(arrBan,Info(A))));
            }
            else if(jenis(bangunan(arrBan,Info(A))) == 'T'){
                printf("Tower ");
                TulisPOINT(lok(bangunan(arrBan,Info(A))));
                printf(" ");
                printf("%d",pasukan(bangunan(arrBan,Info(A))));
                printf(" ");
                printf("lv. ");
                printf("%d",level(bangunan(arrBan,Info(A))));
            }
            else if(jenis(bangunan(arrBan,Info(A))) == 'F'){
                printf("Fort ");
                TulisPOINT(lok(bangunan(arrBan,Info(A))));
                printf(" ");
                printf("%d",pasukan(bangunan(arrBan,Info(A))));
                printf(" ");
                printf("lv. ");
                printf("%d",level(bangunan(arrBan,Info(A))));
            }
            else if(jenis(bangunan(arrBan,Info(A))) == 'V'){
                printf("Village ");
                TulisPOINT(lok(bangunan(arrBan,Info(A))));
                printf(" ");
                printf("%d",pasukan(bangunan(arrBan,Info(A))));
                printf(" ");
                printf("lv. ");
                printf("%d",level(bangunan(arrBan,Info(A))));
            }
            printf("\n");
            i+=1;
            A = Next(A);
        }
}

void changeTurn(int *curPlayer, int *enemyPlayer){
    // KAMUS LOKAL
    // ALGORITMA
        if(*curPlayer%2==1){
            *curPlayer=2;
            *enemyPlayer=1;
            printf("Player 2\n");
        }
        else if(*curPlayer%2==0){
            *curPlayer=1;
            *enemyPlayer=2;
            printf("Player 1\n");
        }
}

int main()
{
    // KAMUS
        int choicePenyerang, choiceDiserang, choicePasukan, choiceLevelUp, choiceMove, choiceMoveTo;
    // ALGORITMA
    printf("Welcome to Avatar World War!\n");
    printf("Select Mode: \n");
    printf("1. New Game\n");
    printf("2. Load Game\n");

    inputStart();
    if(mulai==1){
        printf("Masukkan file konfigurasi: ");
        STARTKATA();
        for(int i=1;i<=CKata.Length;i++){tabkata[i-1]=CKata.TabKata[i];}
        c = tabkata;
        LoadNewConfig(&arrBan,&G,&P,&GLIST[0],&GLIST[1],c);
        curPlayer = 1;
        if(curPlayer%2!=0){
            printf("Player 1's turn\n");
        }
        else{
            printf("Player 2's turn\n");
        }
        CreatePlayerQueue(&GQUEUE[0],10); // queue skill player 1
        CreatePlayerQueue(&GQUEUE[1],10); // queue skill player 2
    }
    
    else if(mulai==2){
        do{
            printf("Masukkan nama file yang ingin di-load: ");
            STARTKATA();
            b = CKata.TabKata;
            if(access(b, F_OK)!=-1){
                LoadExistingConfig(&arrBan, &G, &P, &GFLAGS[0], &GFLAGS[1], &GQUEUE[0], &GQUEUE[1], &GLIST[0], &GLIST[1], b);
            }
        }while(access(b, F_OK)==-1);
    }

    while(!loseState(curPlayer)){
        List LAttackFlag;
        //copy list kepemilikan ke list baru
        // Update Stack for Undo
        UpdateSTACK();
        CopyList(GLIST[curPlayer-1], &LAttackFlag); //PrintInfo(GLIST[0]);

        do
        {
            F = GFLAGS[curPlayer-1];
            IsiPeta(&P, arrBan);
            DisplayPeta(P);
            printBuildings(GLIST[curPlayer-1]);
            printf("\n");
            printf("Skill Available: ");
            availableSkill(GQUEUE[curPlayer-1]);
            inputCommand();
            switch(check){
                case 1: {
                    if (!IsEmptyList(LAttackFlag))
                    {printf("Daftar bangunan: \n");
                    printBuildings(LAttackFlag);
                    printf("Bangunan yang digunakan untuk menyerang: ");
                    STARTANGKA();
                    choicePenyerang = CAngka;
                    while(choicePenyerang>NbElmtList(LAttackFlag) || choicePenyerang<=0){
                        printf("Input tidak valid. Bangunan yang digunakan untuk menyerang: ");
                        STARTANGKA();
                        choicePenyerang = CAngka;
                    }
                    address P = First(LAttackFlag); int target = choicePenyerang;
                    while (target>1){P = Next(P); target--;}
                    int myBPas = pasukan(bangunan(arrBan, Info(P)));
                    List Lattack = MakeListEdge(G,Info(P));
                    address Q = First(GLIST[curPlayer-1]); // list kepemilikan player
                    while(Q!=NilL){
                        if(SearchList(Lattack,Info(Q))!=NilL){
                            DelP(&Lattack,Info(Q));
                        }
                        Q = Next(Q);
                    }
                    printBuildings(Lattack);
                    printf("Bangunan yang diserang: "); 
                    STARTANGKA(); 
                    choiceDiserang = CAngka;
                    while(choiceDiserang>NbElmtList(Lattack) || choiceDiserang<=0){
                        printf("Input tidak valid. Bangunan yang diserang: ");
                        STARTANGKA();
                        choiceDiserang = CAngka;
                    }
                    printf("Jumlah pasukan: ");
                    STARTANGKA();
                    choicePasukan = CAngka;
                    while(choicePasukan>myBPas || choicePasukan<0){
                        printf("Input tidak valid. Jumlah pasukan: ");
                        STARTANGKA();
                        choicePasukan = CAngka;
                    }
                    ATTACK(Lattack, choiceDiserang, choicePenyerang, choicePasukan, curPlayer);
                    printf("\n");
                    DelP(&LAttackFlag,choicePenyerang);
                }
                else{
                    printf("Anda tidak memiliki bangunan yang dapat digunakan untuk menyerang!\n\n");
                }}
                    break; 
                case 2: {
                    printBuildings(GLIST[curPlayer-1]);
                    printf("Bangunan yang akan di-level up: ");
                    STARTANGKA();
                    choiceLevelUp = CAngka;
                    LEVEL_UP(choiceLevelUp, curPlayer);
                }
                    break;
                case 3: {
                    SKILL(&F,&GQUEUE[curPlayer-1],curPlayer);
                }
                    break;
                case 4: {
                    UNDO();
                }
                    break;
                case 5: {
                    do{
                        printf("Masukkan nama file: ");
                        STARTKATA();
                        a = CKata.TabKata;
                        if(access(a, F_OK)!=-1){
                            SaveConfig(arrBan, G, P, GFLAGS[0], GFLAGS[1], GQUEUE[0], GQUEUE[1], a);
                        }
                    }while(access(a, F_OK)==-1);
                }
                    break;
                case 6: {
                    printf("Daftar bangunan: \n");
                    printBuildings(GLIST[curPlayer-1]);
                    printf("Pilih bangunan: ");
                    STARTANGKA();
                    choiceMove = CAngka;
                    address P = First(GLIST[curPlayer-1]); int target = choiceMove;
                    while (target>1){P = Next(P); target--;}
                    int myBPas = pasukan(bangunan(arrBan, Info(P))); int myB = Info(P);
                    if(myBPas==0){
                        printf("Anda tidak memiliki pasukan di bangunan tersebut!\n\n");
                    }
                    else
                    {
                        printf("Daftar bangunan terdekat: \n");
                        List Lmove = MakeListEdge(G,myB);
                        address Q = First(Lmove); 
                        while(Q!=NilL){
                            if(SearchList(GLIST[curPlayer-1],Info(Q))==NilL){
                                DelP(&Lmove,Info(Q));
                            }
                            Q = Next(Q);
                        }
                        printBuildings(Lmove);
                        if(!IsEmptyList(Lmove)){
                            printf("Bangunan yang akan menerima: ");
                            STARTANGKA();
                            choiceMoveTo = CAngka;
                            while(choiceMoveTo>NbElmtList(Lmove) || choiceMoveTo<=0){
                                printf("Input tidak valid. Bangunan yang akan menerima: ");
                                STARTANGKA();
                                choiceMoveTo = CAngka;
                            }
                            printf("Jumlah pasukan: ");
                            STARTANGKA();
                            choicePasukan = CAngka;
                            while(choicePasukan>myBPas || choicePasukan<=0){
                                printf("Input tidak valid. Jumlah masukan: ");
                                STARTANGKA();
                                choicePasukan = CAngka;
                            }
                            MOVE(choiceMove,choiceMoveTo,choicePasukan,curPlayer);
                        }
                        else{
                            printf("Anda tidak memiliki bangunan di dekat bangunan tersebut!\n\n");
                        }
                    }     
                }
                    break;
                case 7: {
                    EXIT();
                }
                    break;
            }
        }while(check!=8);

        if(check==8){
            END_TURN(&F, curPlayer);
            if(!GetETFlag(F)){
                changeTurn(&curPlayer, &enemyPlayer);
            }
            else{
                FlipETFlag(&F);
            }
        }
    }

    if(loseState(curPlayer)){
        if(curPlayer==1){
            printf("Player 1 loses! Try again next time!");
        }
        else{
            printf("Player 2 loses! Try again next time!");
        }
    }

    return 0;
}