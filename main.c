#include <stdio.h>
#include "lib\command.h"
#include "lib\mesinkatainput.h"
#include "lib\queue.h"
#include "lib\saveload.h"
#include "lib\peta.h"
#include "lib\arraydin.h"
#include "lib\listlinier.h"
#include "lib\graph.h"
#include "lib\bangunan.h"
#include "lib\stackt.h"
#include "lib\point.h"

extern Queue GQUEUE[2];
Stack S;
Peta P;
Graph G;
FLAGS F;
TabInt arrBan;
BANGUNAN B;
char a;
int curPlayer, enemyPlayer, check, mulai, CAngka;

boolean loseState (int player){
    // KAMUS LOKAL
        int i, count;
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
}

void printBuildings(List L){ // pake list L parameternya
    // KAMUS LOKAL
        address P;
    // ALGORITMA
        P = First(L);
        while(P!=NilL){
            if(jenis(B(arrBan,Info(P))) == 'C'){
                printf("Castle ");
                TulisPOINT(lok(B(arrBan,Info(P))));
                printf(" ");
                printf("%d",pasukan(B(arrBan,Info(P))));
                printf(" ");
                printf("lv. ");
                printf("%d",level(B(arrBan,Info(P))));
            }
            else if(jenis(B(arrBan,Info(P))) == 'T'){
                printf("Tower ");
                TulisPOINT(lok(B(arrBan,Info(P))));
                printf(" ");
                printf("%d",pasukan(B(arrBan,Info(P))));
                printf(" ");
                printf("lv. ");
                printf("%d",level(B(arrBan,Info(P))));
            }
            else if(jenis(B(arrBan,Info(P))) == 'F'){
                printf("Fort ");
                TulisPOINT(lok(B(arrBan,Info(P))));
                printf(" ");
                printf("%d",pasukan(B(arrBan,Info(P))));
                printf(" ");
                printf("lv. ");
                printf("%d",level(B(arrBan,Info(P))));
            }
            else if(jenis(B(arrBan,Info(P))) == 'V'){
                printf("Village ");
                TulisPOINT(lok(B(arrBan,Info(P))));
                printf(" ");
                printf("%d",pasukan(B(arrBan,Info(P))));
                printf(" ");
                printf("lv. ");
                printf("%d",level(B(arrBan,Info(P))));
            }
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
    printf("Welcome to Avatar World War!");
    printf("Select Mode: ");
    printf("1. New Game");
    printf("2. Load Game");

    inputStart();
    if(mulai==1){
        curPlayer = 1;
        if(curPlayer%2!=0){
            printf("Player 1");
        }
        else{
            printf("Player 2");
        }
        CreatePlayerQueue(&GQUEUE[0],10); // queue skill player 1
        CreatePlayerQueue(&GQUEUE[1],10); // queue skill player 2
    }
    
    else if(mulai==2){
        LoadExistingConfig(&arrBan, &G, &P, &GFLAGS[1], &GFLAGS[2], &GQUEUE[2], &a);
    }

    while(!loseState(curPlayer)){
        List LAttackFlag;
        //copy list kepemilikan ke list baru
        CopyList(GLIST[curPlayer-1],LAttackFlag);

        List Lattack; // list bangunan yang bisa di-attack
        Lattack = MakeListEdge(G,choicePenyerang);
        do
        {
            F = GFLAGS[curPlayer-1];
            IsiPeta(&P, arrayBan);
            DisplayPeta(P);
            // nambah jumlah pasukan tiap bangunan untuk curplayer -> tambahpasukan
            printBuildings(GLIST[curPlayer-1]);
            printf("Skill Available: ");
            availableSkill(GQUEUE[curPlayer-1]);
            inputCommand();
            switch(check){
                case 1:
                    address P = First(GLIST[curPlayer-1]); // list kepemilikan player
                    while(P!=Nil){
                        if(SearchList(Lattack,Info(P))!=Nil){
                            DelP(&Lattack,Info(P));
                        }
                        P = Next(P);
                    }

                    printf("Daftar bangunan: \n");
                    printBuildings(GLIST[curPlayer-1]);
                    printf("Bangunan yang digunakan untuk menyerang: ");
                    STARTANGKA();
                    choicePenyerang = CAngka;
                    printBuildings(GLIST[enemyPlayer-1]);
                    printf("Bangunan yang diserang: "); 
                    STARTANGKA();
                    choiceDiserang = CAngka;
                    printf("Jumlah pasukan: ");
                    STARTANGKA();
                    choicePasukan = CAngka;
                    ATTACK(Lattack, choiceDiserang, choicePenyerang, choicePasukan, curPlayer);
                    DelP(&LAttackFlag,choicePenyerang);
                    break; 
                case 2:
                    printBuildings(GLIST[curPlayer-1]);
                    printf("Bangunan yang akan di-level up: ");
                    STARTANGKA();
                    choiceLevelUp = CAngka;
                    LEVEL_UP(choiceLevelUp, curPlayer);
                    break;
                case 3:
                    SKILL(&F,&GQUEUE[curPlayer-1],curPlayer);
                    break;
                case 4:
                    UNDO(&S);
                    break;
                case 5:
                    SaveConfig(arrBan, G, P, GFLAGS[1], GFLAGS[2], &GQUEUE[2], &a);
                    break;
                case 6:
                    printf("Daftar bangunan: \n");
                    printBuildings(GLIST[curPlayer-1]);
                    printf("Pilih bangunan: ");
                    STARTANGKA();
                    choiceMove = CAngka;
                    printf("Daftar bangunan terdekat: ");
                    printBuildings(Lattack);
                    printf("Bangunan yang akan menerima: ");
                    STARTANGKA();
                    choiceMoveTo = CAngka;
                    printf("Jumlah pasukan: ");
                    STARTANGKA();
                    choicePasukan = CAngka;
                    MOVE(choiceMove,choiceMoveTo,choicePasukan,curPlayer);
                case 7:
                    EXIT();
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