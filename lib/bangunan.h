#ifndef BANGUNAN_H
#define BANGUNAN_H

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "point.h"

typedef struct
{
  int kepemilikan;//'1' untuk player 1, '2' untuk player 2, '0' tidak dimiliki siapa siapa
  int pasukan;//jumlah pasukan
  int level;//level bangunan
  int A;//nilai penambahan pasukan
  int M;//Maksimum penambahan pasukan
  int U;//pasukan awal
  POINT lok;//lokasi bangunan
  char jenis;//jenis bangunan 'C'=CASTLE 'T'=TOWER 'F'=FORT 'V'=VILLAGE
} BANGUNAN;

/*Selektor */
#define kepemilikan(B) (B).kepemilikan
#define pasukan(B) (B).pasukan
#define level(B) (B).level
#define tambahpas(B) (B).A
#define maks(B) (B).M
#define pasawal(B) (B).U
#define lok(B) (B).lok
#define jenis(B) (B).jenis

void MakeBangunan(BANGUNAN *B, int kepemilikan, int pasukan, int a, int m, int u, int level, int X, int Y, char jenis);
BANGUNAN SetBangunan(int kepemilikan, char jenis, POINT lokasi);
void MakeCastle (BANGUNAN *B);
void MakeTower (BANGUNAN *B);
void MakeFort (BANGUNAN *B);
void MakeVillage (BANGUNAN *B);
void SetMaxPasukan (BANGUNAN *B);
void SetKepemilikan (BANGUNAN *B, int kepemilikan);
boolean IsKepemilikan (BANGUNAN B, int kepemilikan);
void IncreasePasukan(BANGUNAN *B, int pasukan);
boolean CanLevelUp(BANGUNAN B);
void LevelUp(BANGUNAN *B);
boolean IsTherePertahanan (BANGUNAN B);
boolean validTambahA(BANGUNAN B);
void delPasukan(BANGUNAN *B);
void DecreasePasukan(BANGUNAN *B, int pasukan);
void setpasukan(BANGUNAN *B,int pasukan);
void resetlevel(BANGUNAN *B);
void tambahpasukan (BANGUNAN *B);//auto tiap turn nambah pasukannya

#endif