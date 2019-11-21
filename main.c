#include <stdio.h>
#include "command.h"
#include "mesinkatainput.c"
#include "queue.c"
#include "loadsave.h"
#include "peta.h"
#include "arraydin.c"

Queue Qskill1, Qskill2;
Stack S;
Peta P;
int curPlayer, enemyPlayer;

boolean loseState (int player, arrayBANGUNAN LB){
    // KAMUS LOKAL
        int i, count;
    // ALGORITMA
        count = 0;
        for(i=1; i<=Neff(B); i++){
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

void printBuildings (int player, BANGUNAN B ){
    // KAMUS LOKAL
        int i;
    // ALGORITMA
        printf("Daftar bangunan: ");
        for(i=1; i<=Neff(B), i++){
            if(kepemilikan(B)==player){
                if(jenis(B)=='C'){
                    printf("Castle ");
                }
                else if(jenis(B)=='T'){
                    printf("Tower ");
                }
                else if(jenis(B)=='F'){
                    printf("Fort ");
                }
                else if(jenis(B)=='V'){
                    printf("Vilage ");
                }
                printf(lok(B));
                printf(pasukan(B));
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
        int choiceBangunan, choicePasukan, choiceLevelUp;
        int haveAttack;
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

    haveAttack = 0;

    while(!loseState){
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
                    // mengecek apakah player telah pernah attack dalam giliran tersebut 
                    if(haveAttack==0){
                        printBuildings(enemyPlayer,B);
                        printf("Bangunan yang diserang: ");
                        scanf("%d",&choiceBangunan);
                        printf("Jumlah pasukan: ");
                        scanf("%d",&choicePasukan);
                        ATTACK(...);
                        haveAttack = 1;
                    }
                    else{
                        printf("Anda telah menggunakan command ini sebelumnya!");
                    }
                    break; 
                case 2:
                    printBuildings(enemyPlayer,B);
                    printf("Bangunan yang akan di-level up: ");
                    scanf("%d",&choiceLevelUp);
                    LEVEL_UP(...);
                    break;
                case 3:
                    SKILL(...);
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
            END_TURN(*F);
            // isExtraTurn aktif, maka gausah changeTurn
            changeTurn(*curPlayer);
        }
    }

    if(loseState){
        if(curPlayer==1){
            printf("Player 1 loses! Try again next time!");
        }
        else{
            printf("Player 2 loses! Try again next time!");
        }
    }

    return 0;
}