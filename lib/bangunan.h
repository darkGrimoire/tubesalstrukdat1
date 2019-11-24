#ifndef BANGUNAN_H
#define BANGUNAN_H

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "point.h"

typedef struct
{
  int kepemilikan;//'1' untuk player 1, '2' untuk player 2, '0' untuk sistem
  int pasukan;//jumlah pasukan
  int level;//level bangunan
  int A;//nilai penambahan pasukan
  int M;//Maksimum penambahan pasukan
  int U;//pasukan awal
  POINT lok;//lokasi bangunan
  char jenis;//jenis bangunan 'C'=CASTLE 'T'=TOWER 'F'=FORT 'V'=VILLAGE
} BANGUNAN;

// Definisi bangunan terdapat di spesifikasi

/*Selektor */
#define kepemilikan(B) (B).kepemilikan
#define pasukan(B) (B).pasukan
#define level(B) (B).level
#define tambahpas(B) (B).A
#define maks(B) (B).M
#define pasawal(B) (B).U
#define lok(B) (B).lok
#define jenis(B) (B).jenis

/* ***** Konstruktor ***** */
void MakeBangunan(BANGUNAN *B, int kepemilikan, int pasukan, int a, int m, int u, int level, int X, int Y, char jenis);
// I.S. Sembarang
// F.S. Terbentuk bangunan B dengan kepemilikan, pasukan, nilai penambahan pasukan a, maksimal penambahan pasukan m, jumlah pasukan awal u, dan jenis
BANGUNAN SetBangunan(int kepemilikan, char jenis, POINT lokasi);
// Mengembalikan bangunan dengan kepemilikan, jenis, dan lokasi sesuai parameter
void MakeCastle (BANGUNAN *B);
// I.S. Sembarang
// F.S. B terbentuk menjadi Castle sesuai definisi
void MakeTower (BANGUNAN *B);
// I.S. Sembarang
// F.S. B terbentuk menjadi Tower sesuai definisi
void MakeFort (BANGUNAN *B);
// I.S. Sembarang
// F.S. B terbentuk menjadi Fort sesuai definisi
void MakeVillage (BANGUNAN *B);
// I.S. Sembarang
// F.S. B terbentuk menjadi Village sesuai definisi

/* ***** Setter ***** */
void SetMaxPasukan (BANGUNAN *B);
// I.S. B terdefinisi
// F.S. B memiliki jumlah maksimal penambahan pasukan sesuai level dan definisi bangunan
void SetKepemilikan (BANGUNAN *B, int kepemilikan);
// I.S. B terdefinisi
// F.S. B memiliki kepemilikan sesuai parameter
boolean IsKepemilikan (BANGUNAN B, int kepemilikan);
// Mengembalikan True jika bangunan B memiliki kepemilikan sesuai parameter
void IncreasePasukan(BANGUNAN *B, int pasukan);
// I.S. B terdefinisi
// F.S. Jumlah pasukan B bertambah sebanyak pasukan
boolean CanLevelUp(BANGUNAN B);
// Mengembalikan True jika level bangunan masih dibawah level 4 dan jumlah pasukan lebih besar dari jumlah maksimal penambahan pasukan B
void LevelUp(BANGUNAN *B);
// I.S. B terdefinisi
// F.S. Level B naik sesuai dengan kondisi B
boolean IsTherePertahanan (BANGUNAN B);
// Mengembalikan True jika kondisi pertahanan B sesuai dengan definisi dan spesifikasi
boolean validTambahA(BANGUNAN B);
// Mengembalikan True jika jumlah pasukan B kurang dari jumlah maksimum penambahan pasukan yang terdefinisi
/*void delPasukan(BANGUNAN *B);*/
void DecreasePasukan(BANGUNAN *B, int pasukan);
// I.S. B terdefinisi
// F.S. Pasukan B berkurang sebanyak pasukan
void setpasukan(BANGUNAN *B,int pasukan);
// I.S. B terdefinisi
// F.S. Jumlah pasukan B menjadi sebanyak pasukan
void resetlevel(BANGUNAN *B);
// I.S. B terdefinisi
// F.S. Level B menjadi level 1 dengan spesifikasi sesuai jenis bangunan

void tambahpasukan (BANGUNAN *B);//auto tiap turn nambah pasukannya

#endif