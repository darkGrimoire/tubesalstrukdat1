#ifndef BANGUNAN_H
#define BANGUNAN_H

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "array.h"

typedef struct
{
  int kepemilikan;//'1' untuk player 1, '2' untuk player 2, '0' tidak dimiliki siapa siapa
  int pasukan;//jumlah pasukan
  int level;//level bangunan
  int A;//nilai penambahan pasukan
  int M;//Maksimum penambahan pasukan
  int U;//pasukan awal
  POINT lok//lokasi bangunan
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

void MakeBangunan(BANGUNAN *B, int kepemilikan, int pasukan, int level, POINT lok, char jenis);
BANGUNAN SetBangunan(jenis j, int kepemilikan, boolean flag);
void MakeCastle (BANGUNAN *B, boolean flag);
void MakeTower (BANGUNAN *B, boolean flag);
void MakeFort (BANGUNAN *B, boolean flag);
void MakeVillage (BANGUNAN *B, boolean flag);
void SetMaxPasukan (BANGUNAN *B, char jenis, boolean flag);
void SetKepemilikan (BANGUNAN *B, int kepemilikan, boolean flag);
boolean IsKepemilikan (BANGUNAN B, int kepemilikan, boolean flag);
void IncreasePasukan(BANGUNAN *B, jenis j, int pasukan);
void LevelUp(BANGUNAN *B);
boolean IsTherePertahanan (BANGUNAN B);

#endif