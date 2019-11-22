#include <stdio.h>
#include "command.c"
#include "mesinkatainput.c"
#include "queue.c"
#include "loadsave.c"
#include "peta.h"
#include "arraydin.c"
#include "listlinier.c"
#include "graph.c"

extern Queue GQueue[2];
Stack S;
Peta P;
int curPlayer, enemyPlayer;

boolean loseState (int player, arrBan AB){
    // KAMUS LOKAL
        int i, count;
    // ALGORITMA
        count = 0;
        for(i=1; i<=Neff(AB); i++){
            if(kepemilikan(B)==player){
                count+=1;
            }
        }

        if(count==0){
            return true;
        }
        else{
            return false;
        }
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

void printBuildings(int player){
    // KAMUS LOKAL
        address P;
    // ALGORITMA
        P = First(GLIST[player-1]);
        while(P!=Nil){
            if(jenis(B)=='C'){
                printf("Castle ");
                printf(lok(B));
                printf(" ");
                printf(pasukan(B));
                printf(" ");
                printf("lv. ");
                printf(level(B));
            }
            else if(jenis(B)=='T'){
                printf("Tower ");
                printf(lok(B));
                printf(" ");
                printf(pasukan(B));
                printf(" ");
                printf("lv. ");
                printf(level(B));
            }
            if(jenis(B)=='F'){
                printf("Fort ");
                printf(lok(B));
                printf(" ");
                printf(pasukan(B));
                printf(" ");
                printf("lv. ");
                printf(level(B));
            }
            if(jenis(B)=='V'){
                printf("Village ");
                printf(lok(B));
                printf(" ");
                printf(pasukan(B));
                printf(" ");
                printf("lv. ");
                printf(level(B));
            }
        }
}

void changeTurn(int *curPlayer, int *enemyPlayer){
    // KAMUS LOKAL
    // ALGORITMA
        if(curPlayer%2==1){
            *curPlayer=2;
            *enemyPlayer=1;
            printf("Player 2\n");
        }
        else if(curPlayer%2==0){
            *curPlayer=1;
            *enemyPlayer=2;
            printf("Player 1\n");
        }
}

int main()
{
    // KAMUS
        int choicePenyerang, choiceDiserang, choicePasukan, choiceLevelUp;
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
        CreatePlayerQueue(*Qs1,10); // queue skill player 1
        CreatePlayerQueue(*Qs2,10); // queue skill player 2
    }
    
    else if(mulai==2){
        LoadExistingConfig(...);
        ReadBangunan(...);
        ReadFlags(...);
        ReadGraf(...);
    }

    while(!loseState(curPlayer,AB)){
        do
        {
            IsiPeta(*P, arrayBangunan);
            DisplayPeta(P);
            // nambah jumlah pasukan tiap bangunan untuk curplayer
            printBuildings(curPlayer,B);
            printf("Skill Available: ");
            if(curPlayer%2!=0){
                availableSkill(Qskill1);
            }
            else{
                availableSkill(Qskill2);
            }
            inputCommand();
            switch(check){
                case 1:
                    List Lattack; // list bangunan yang bisa di-attack
                    Lattack = MakeListEdge(G,choicePenyerang);
                    address P = First(GLIST[curPlayer-1]); // list kepemilikan player
                    while(P!=Nil){
                        if(SearchList(Lattack,Info(P))){
                            DelP(&Lattack,Info(P));
                        }
                        P = Next(P);
                    }

                    printf("Daftar bangunan: \n");
                    printBuildings(curPlayer-1);
                    printf("Bangunan yang digunakan untuk menyerang: ");
                    scanf("%d",&choicePenyerang);
                    printBuildings(enemyPlayer-1);
                    printf("Bangunan yang diserang: ");
                    scanf("%d",&choiceDiserang);
                    printf("Jumlah pasukan: ");
                    scanf("%d",&choicePasukan);
                    ATTACK(Lattack, choiceDiserang, choicePenyerang, choicePasukan, curPlayer);
                    //apa perlu dicopy?
                    break; 
                case 2:
                    printBuildings(curPlayer-1);
                    printf("Bangunan yang akan di-level up: ");
                    scanf("%d",&choiceLevelUp);
                    LEVEL_UP(choiceLevelUp, curPlayer);
                    break;
                case 3:
                    if(curPlayer==1){
                        SKILL(*F,*GQueue[curPlayer-1],curPlayer);
                    }
                    else if(curPlayer==2){
                        SKILL(*F,*GQueue[curPlayer-1],curPlayer);
                    }
                    break;
                case 4:
                    UNDO(*S);
                    break;
                case 5:
                    SaveConfig(...);
                    break;
                case 6:
                    MOVE(...);
                case 7:
                    EXIT();
            }
        }while(check!=8);

        if(check==8){
            END_TURN(*F, *GQueue[1], *GQueue[2], curPlayer);
            // isExtraTurn aktif, maka gausah changeTurn
            changeTurn(*curPlayer);
        }
    }

    if(loseState(curPlayer,AB)){
        if(curPlayer==1){
            printf("Player 1 loses! Try again next time!");
        }
        else{
            printf("Player 2 loses! Try again next time!");
        }
    }

    return 0;
}