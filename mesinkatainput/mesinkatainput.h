/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../boolean.h"
#include "../mesinkar/mesinkarinput.h"

#define NMax 50
#define BLANK ' '

typedef struct {
  char TabKata[NMax+1]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
    int Length;
} Kata;

/* State Mesin Kata */
extern boolean EndKata;
extern Kata CKata;
extern int check,mulai, CAngka;

void IgnoreBlank();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTKATA();
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void STARTANGKA();
/* I.S. : CC sembarang
   F.S. : EndAngka = true, dan CC = MARK;
          atau EndAngka = false, CAngka adalah angka yang sudah diakuisisi,
          CC angka pertama sesudah angka terakhir bilangan */

void ADVKATA();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void ADVANGKA();
/* I.S. : CC adalah angka pertama bilangan yang akan diakuisisi
   F.S. : CAngka adalah angka terakhir yang sudah diakuisisi,
          CC adalah angka pertama dari bilangan berikutnya, mungkin MARK
          Jika CC = MARK, EndAngka = true.
  Proses : Akuisisi bilangan menggunakan procedure SalinAngka */

void SalinKata();
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void SalinAngka();
/* Mengakuisisi bilangan, menyimpan dalam CAngka
  I.S. : CC adalah angka pertama dari bilangan
  F.S. : CAngka berisi angka yang sudah diakuisisi;
         CC = MARK;
         CC adalah angka sesudah angka terakhir yang diakuisis.
         Jika panjang bilangan melebihi NMax, maka sisa bilangan "dipotong" */

int convertToInteger(Kata K);

boolean matchString(Kata K1, Kata K2);
/* Menyocokkan dua kata */

void inputStart();

void inputCommand();

#endif