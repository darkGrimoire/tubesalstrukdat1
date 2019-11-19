#include <stdio.h>
#include "pcolor.c"
#include "mesinkata.c"
#include "queue.c"
#include "command.h"

int main(){
    printf("Selamat datang di Avatar World War!");
    printf("Pilih mode game:");
    printf("1. New Game");
    printf("2. Load Game");

    // nerima input start pake mesin kata 

    str inputStart, inputCommand;
    Queue Qplayer;
    Stack S;
    int choiceBangunan,choicePasukan,choiceLevelUp;
    
    if(input==New Game){
        // baca config peta
        CreateEmptyQ(Qplayer);
        AddQ(*Qplayer,1);
        AddQ(*Qplayer,2);
        //bikin counter buat turn
        //nambah jumlah pasukan tiap bangunan
        //show player
        //show map
        //show bangunan
        //show skill

        // baca input command
        while(inputCommand!=END_TURN){
            if(inputCommand==ATTACK){
                //show bangunan
                printf("Bangunan yang diserang: ");
                scanf("%d",&choiceBangunan);
                printf("Jumlah pasukan: ");
                scanf("%d",&choicePasukan);
                ATTACK(...);
            }
            else if(inputCommand==LEVEL_UP){
                //show bangunan
                printf("Bangunan yang akan di-level up: ");
                scanf("%d",&choiceLevelUp);
                LEVEL_UP(...);
            }
            else if(inputCommand==SKILL{
                SKILL(...);
            }
            else if(inputCommand==UNDO){
                UNDO(*S);
            }
            else if(inputCommand==SAVE){
                SaveConfig(...);
            }
            else if(inputCommand==EXIT){
                EXIT();
            }
        }
    }

    else{ // load game
        LoadExistingConfig(....);
        ReadBangunan(...);
        ReadFlags(...);
        ReadGraf(...);
    }

    return 0;
}