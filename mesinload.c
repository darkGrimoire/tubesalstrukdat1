/* File: mesinkata.c */
/* Implementasi Mesin Kata */

#include "lib\mesinload.h"
#include "lib\mesinkarfile.h"
#include "lib\boolean.h"
#include <stdio.h>

LoadDat CLData;
boolean EndLData;

void IgnoreBlankData()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CCf sembarang
   F.S. : CCf ≠ BLANK atau CCf = MARK */
{
	while (CCf == BLANK) {
		ADVFILE();
	}
}

void STARTDATA()
/* I.S. : CCf sembarang
   F.S. : EndKata = true, dan CCf = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CCf karakter pertama sesudah karakter terakhir kata */
{
    STARTFILE();
    IgnoreBlankData();
    if (CCf == MARK)
    {
        EndLData = true;
    }
    else
    {
        EndLData = false;
        SalinData();
    } 
}

void ADVDATA()
/* I.S. : CCf adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CCf adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CCf = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
    IgnoreBlankData();
    if (CCf == MARK)
    {
        EndLData = true;
    }
    else
    {
		EndLData = false;
        SalinData();
        IgnoreBlankData();
    }
}

void SalinData()
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
    int sum, x;
    // ALGORITMA
    while ((CCf != MARK) && (CCf != BLANK)) {
		if (CCf == 'C' || CCf == 'T' || CCf == 'F' || CCf == 'V'){
			CLData.Index = CCf;
			CLData.Value = -999;
			ADVFILE();
		}
		else {
			sum = 0;
			while ((CCf != MARK) && (CCf != BLANK)) {
				x = CCf - '0';
				ADVFILE();
				if (CCf == BLANK || CCf == MARK) {
					sum = sum + x;
				}
				else {
					sum = (sum + x) * 10;
				}
			}
			CLData.Index = 'N';
			CLData.Value = sum;
		}
	}
}
