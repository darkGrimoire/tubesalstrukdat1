/* File: mesinkata.c */
/* Implementasi Mesin Kata */

#include "../mesinkatafile/mesinkatafile.h"
#include <stdio.h>

Kata CKataf;
boolean EndKataf;

void IgnoreBlankFile()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CCf sembarang
   F.S. : CCf ≠ BLANK atau CCf = MARK */
{
    while ((CCf == BLANK) && (CCf != MARK))
    {
        ADVFILE();
    }  
}

void STARTKATAFILE()
/* I.S. : CCf sembarang
   F.S. : EndKata = true, dan CCf = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CCf karakter pertama sesudah karakter terakhir kata */
{
    STARTFILE();
    IgnoreBlankFile();
    if (CCf == MARK)
    {
        EndKataf = true;
    }
    else
    {
        EndKataf = false;
        SalinKataFile();
    } 
}

void ADVKATAFILE()
/* I.S. : CCf adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CCf adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CCf = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
    IgnoreBlankFile();
    if (CCf == MARK)
    {
        EndKataf = true;
    }
    else
    {
        SalinKataFile();
        IgnoreBlankFile();
    }
}

void SalinKataFile()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CCf adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CCf = BLANK atau CCf = MARK;
          CCf adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CCf sembarang
   F.S. : CCf ≠ BLANK atau CCf = MARK */
{
    // KAMUS LOKAL
    int i = 0;

    // ALGORITMA
    while((CCf != BLANK) && (CCf != MARK) && (i < NMax))
    {
        i = i+1;
        CKataf.TabKata[i] = CCf;
        ADVFILE();
    }
    CKataf.Length = i;
}
