#include <stdio.h>
#include "command.h"
#include "mesinkatainput.c"
#include "queue.h"
#include "loadsave.h"
#include "peta.h"

Queue Qplayer, Qskill1, Qskill2;
str check,mulai;
Stack S;
Peta P;
int turn;

void gameOn()
{
    // KAMUS LOKAL
        int choiceBangunan, choicePasukan, choiceLevelUp;
    // ALGORITMA
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
            DelQ(*Qplayer,*X);
            AddQ(*Qplayer,turn);
        }
}


int main()
{
    // KAMUS
    // ALGORITMA
    printf("Selamat datang di Avatar World War!");
    printf("Mode game: ");
    printf("1. New Game");
    printf("2. Load Game");

    inputStart();
    if(mulai==1){
        CreateEmptyQ(Qplayer);
        AddQ(*Qplayer,1); // queue player
        AddQ(*Qplayer,2); // queue player
        turn = 1;
        // nambah jumlah pasukan tiap bangunan
        CreatePlayerQueue(*Qs1); // queue skill player 1
        CreatePlayerQueue(*Qs2); // queue skill player 2
        // show player
        DisplayPeta(P);
        // show bangunan
        // show skill
        gameOn();
    }
    
    else if(mulai==2){
        LoadExistingConfig(...);
        ReadBangunan(...);
        ReadFlags(...);
        ReadGraf(...);
        gameOn();
    }

    return 0;
}