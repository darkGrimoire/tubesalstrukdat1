/* File: mesinkata.c */
/* Implementasi Mesin Kata */

#include "../mesinload/mesinload.h"
#include "../mesinkar/mesinkarfile.h"
#include "../boolean.h"
#include <stdio.h>

LoadDat CLData;
boolean EndLData;

void IgnoreBlankData()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
{
	while (CCf == BLANK) {
		ADVFILE();
	}
}

void STARTDATA()
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
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
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
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
    int sum, x;
    // ALGORITMA
    CLData.Index = 'X';
	CLData.Value = 0;
    while ((CCf != MARK) && (CCf != BLANK)) {
		if (CCf == 'C' || CCf == 'T' || CCf == 'F' || CCf == 'V'){
			CLData.Index = CCf;
			CLData.Value = -999;
			ADVFILE();
		}
		else {
			sum = 0;
			while ((CCf != MARK) && (CCf != BLANK) && !EOPf) {
				if (CCf == '0') {
					x = 0;
				}
				else if (CCf == '1') {
					x = 1;
				}
				else if (CCf == '2') {
					x = 2;
				}
				else if (CCf == '3') {
					x = 3;
				}
				else if (CCf == '4') {
					x = 4;
				}
				else if (CCf == '5') {
					x = 5;
				}
				else if (CCf == '6') {
					x = 6;
				}
				else if (CCf == '7') {
					x = 7;
				}
				else if (CCf == '8') {
					x = 8;
				}
				else if (CCf == '9') {
					x = 9;
				}
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
