/* File: mesinkata.c */
/* Implementasi Mesin Kata */

#include "mesinload.h"
#include "mesinkar.h"
#include "boolean.h"
#include <stdio.h>

LoadDat CLData;
boolean EndLData;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
{
	while (CC == BLANK) {
		ADV();
	}
}

void STARTDATA()
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
    START();
    IgnoreBlank();
    if (CC == MARK)
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
    IgnoreBlank();
    if (CC == MARK)
    {
        EndLData = true;
    }
    else
    {
		EndLData = false;
        SalinData();
        IgnoreBlank();
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
    while ((CC != MARK) && (CC != BLANK)) {
		if (CC == 'C' || CC == 'T' || CC == 'F' || CC == 'V'){
			CLData.Index = CC;
			CLData.Value = -999;
			ADV();
		}
		else {
			sum = 0;
			while ((CC != MARK) && (CC != BLANK)) {
				x = CC - '0';
				ADV();
				if (CC == BLANK || CC == MARK) {
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
