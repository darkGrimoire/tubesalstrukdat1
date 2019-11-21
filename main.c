#include <stdio.h>
#include "command.h"
#include "mesinkatainput.c"
#include "queue.c"
#include "loadsave.h"
#include "peta.h"

Queue Qplayer, Qskill1, Qskill2;
str check,mulai;
Stack S;
Peta P;
int turn;

void changeTurn(int * turn){
    // KAMUS LOKAL
    // ALGORITMA
        if(turn%2==1){
            *turn=2;
        }
        else if(turn%2==0){
            *turn=1;
        }
}

int main()
{
    // KAMUS
        int choiceBangunan, choicePasukan, choiceLevelUp;
    // ALGORITMA
    printf("Selamat datang di Avatar World War!");
    printf("Mode game: ");
    printf("1. New Game");
    printf("2. Load Game");

    inputStart();
    if(mulai==1){
        turn = 1;
        // nambah jumlah pasukan tiap bangunan
        CreatePlayerQueue(*Qs1); // queue skill player 1
        CreatePlayerQueue(*Qs2); // queue skill player 2
        // show player
        DisplayPeta(P);
        // show bangunan
        // show skill
    }
    
    else if(mulai==2){
        LoadExistingConfig(...);
        ReadBangunan(...);
        ReadFlags(...);
        ReadGraf(...);
    }

    do
    {
        inputCommand();
        switch(check){
            case 1:
                // show bangunan
                printf("Bangunan yang diserang: ");
                scanf("%d",&choiceBangunan);
                printf("Jumlah pasukan: ");
                scanf("%d",&choicePasukan);
                ATTACK(...);
                break; 
            case 2:
                // show bangunan
                printf("Bangunan yang akan di-level up: ");
                scanf("%d",%choiceLevelUp);
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
                EXIT();
        }
    }while(check!=7);

    if(check==7){
        END_TURN(*F);
        changeTurn(turn);
    }

    return 0;
}