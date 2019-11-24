/* File: mesinkata.c */
/* Implementasi Mesin Kata */

#include "lib\mesinkatainput.h"
#include <stdio.h>
#include <ctype.h>
#include "lib\pcolor.h"

// Kata CKata;
int CAngka, mulai, check;
boolean EndKata, EndAngka;


void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while ((CC == BLANK) && (CC != MARK))
    {
        ADV();
    }  
}

void STARTKATA()
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
    START();
    IgnoreBlank();
    if (CC == MARK)
    {
        EndKata = true;
    }
    else
    {
        EndKata = false;
        SalinKata();
    } 
}

void STARTANGKA(){
    // KAMUS LOKAL
    // ALGORITMA
        START();
        IgnoreBlank();
        if(CC==MARK){
            EndAngka = true;
        }
        else{
            EndAngka = false;
            SalinAngka();
        }
}

void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
    IgnoreBlank();
    if (CC == MARK)
    {
        EndKata = true;
    }
    else
    {
        SalinKata();
        IgnoreBlank();
    }
}

void ADVANGKA(){
    // KAMUS LOKAL
    // ALGORITMA
        IgnoreBlank();
        if(CC==MARK){
            EndAngka = true;
        }
        else{
            SalinAngka();
            IgnoreBlank();
        }
}

void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    // KAMUS LOKAL
    int i = 0;

    // ALGORITMA
    while((CC != MARK) && (i < NMax))
    {
        i = i+1;
        CKata.TabKata[i] = CC;
        ADV();
    }
    CKata.Length = i;
}

void SalinAngka(){
    // KAMUS LOKAL
        int CCconv;
    // ALGORITMA
        while((CC!=BLANK) && (CC!=MARK)){
            CCconv = (int) CC - 48;
            CAngka = CAngka*10;
            CAngka = CAngka + CCconv;
            ADV();
        }
}

int convertToInteger(Kata K)
{
    // KAMUS LOKAL
        int i, sum;
    // ALGORITMA
        sum=0;
        for(i=1; i<=K.Length; i++){
            sum+=tolower(K.TabKata[i])-'0';
        }
        return sum;
}

boolean matchString(Kata K1, Kata K2)
{
    if(convertToInteger(K1)==convertToInteger(K2)){
        return true;
    }
    else{
        return false;
    }
}

void inputStart() 
{
    // KAMUS LOKAL
        boolean found;
        Kata KataNEWGAME;
        KataNEWGAME.TabKata[1] = 'N';
        KataNEWGAME.TabKata[2] = 'E';
        KataNEWGAME.TabKata[3] = 'W';
        KataNEWGAME.TabKata[4] = ' ';
        KataNEWGAME.TabKata[5] = 'G';
        KataNEWGAME.TabKata[6] = 'A';
        KataNEWGAME.TabKata[7] = 'M';
        KataNEWGAME.TabKata[8] = 'E';
        KataNEWGAME.Length = 8;

        Kata KataLOADGAME;
        KataLOADGAME.TabKata[1] = 'L';
        KataLOADGAME.TabKata[2] = 'O';
        KataLOADGAME.TabKata[3] = 'A';
        KataLOADGAME.TabKata[4] = 'D';
        KataLOADGAME.TabKata[5] = ' ';
        KataLOADGAME.TabKata[6] = 'G';
        KataLOADGAME.TabKata[7] = 'A';
        KataLOADGAME.TabKata[8] = 'M';
        KataLOADGAME.TabKata[9] = 'E';
        KataLOADGAME.Length = 9;

    // ALGORITMA
        found = false;
        mulai = 0;
        do{
            printf("Masukkan pilihan mode: ");
            STARTKATA();
            if(matchString(CKata,KataNEWGAME)){
                found=true;
                mulai=1;
            }
            else if(matchString(CKata,KataLOADGAME)){
                found=true;
                mulai=2;
            }
        }while((!found) && (mulai!=0));
}

void inputCommand()
{
    // KAMUS LOKAL
        int i;
        Kata KataATTACK;
        KataATTACK.TabKata[1] = 'A';
        KataATTACK.TabKata[2] = 'T';
        KataATTACK.TabKata[3] = 'T';
        KataATTACK.TabKata[4] = 'A';
        KataATTACK.TabKata[5] = 'C';
        KataATTACK.TabKata[6] = 'K';
        KataATTACK.Length = 6;

        Kata KataLEVELUP;
        KataLEVELUP.TabKata[1] = 'L';
        KataLEVELUP.TabKata[2] = 'E';
        KataLEVELUP.TabKata[3] = 'V';
        KataLEVELUP.TabKata[4] = 'E';
        KataLEVELUP.TabKata[5] = 'L';
        KataLEVELUP.TabKata[6] = '_';
        KataLEVELUP.TabKata[7] = 'U';
        KataLEVELUP.TabKata[8] = 'P';
        KataLEVELUP.Length = 8;

        Kata KataSKILL;
        KataSKILL.TabKata[1] = 'S';
        KataSKILL.TabKata[2] = 'K';
        KataSKILL.TabKata[3] = 'I';
        KataSKILL.TabKata[4] = 'L';
        KataSKILL.TabKata[5] = 'L';
        KataSKILL.Length = 5;

        Kata KataUNDO;
        KataUNDO.TabKata[1] = 'U';
        KataUNDO.TabKata[2] = 'N';
        KataUNDO.TabKata[3] = 'D';
        KataUNDO.TabKata[4] = 'O';
        KataUNDO.Length = 4;

        Kata KataSAVE;
        KataSAVE.TabKata[1] = 'S';
        KataSAVE.TabKata[2] = 'A';
        KataSAVE.TabKata[3] = 'V';
        KataSAVE.TabKata[4] = 'E';
        KataSAVE.Length = 4;

        Kata KataMOVE;
        KataMOVE.TabKata[1] = 'M';
        KataMOVE.TabKata[2] = 'O';
        KataMOVE.TabKata[3] = 'V';
        KataMOVE.TabKata[4] = 'E';

        Kata KataEXIT;
        KataEXIT.TabKata[1] = 'E';
        KataEXIT.TabKata[2] = 'X';
        KataEXIT.TabKata[3] = 'I';
        KataEXIT.TabKata[4] = 'T';
        KataEXIT.Length = 4;

        Kata KataENDTURN;
        KataENDTURN.TabKata[1] = 'E';
        KataENDTURN.TabKata[2] = 'N';
        KataENDTURN.TabKata[3] = 'D';
        KataENDTURN.TabKata[4] = '_';
        KataENDTURN.TabKata[5] = 'T';
        KataENDTURN.TabKata[6] = 'U';
        KataENDTURN.TabKata[7] = 'R';
        KataENDTURN.TabKata[8] = 'N';
        KataENDTURN.Length = 8;
    // ALGORITMA
        check = 0;
        do{
            printf("Command yang tersedia: ");
            printf("%s", MAGENTA);
            printf("ATTACK - LEVEL_UP - SKILL - UNDO - SAVE - END_TURN - EXIT");
            printf("%s", NORMAL);
            printf("\n");
            printf("ENTER COMMAND: ");
            STARTKATA();
            if(matchString(CKata,KataATTACK)){
                check=1;
            }
            else if(matchString(CKata,KataLEVELUP)){
                check=2;
            }
            else if(matchString(CKata,KataSKILL)){
                check=3;
            }
            else if(matchString(CKata,KataUNDO)){
                check=4;
            }
            else if(matchString(CKata,KataSAVE)){
                check=5;
            }
            else if(matchString(CKata,KataMOVE)){
                check=6;
            }
            else if(matchString(CKata,KataEXIT)){
                check=7;
            }
            else if(matchString(CKata,KataENDTURN)){
                check=8;
            }
        }while(check==0);
}