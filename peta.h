// Header ADT Peta

#ifndef peta_H
#define peta_H

#include "matriks.h"
#include "boolean.h"
#include <stdio.h>
#include "pcolor.h"

typedef MATRIKS Peta;

/* ==== PROTOTIPE PRIMITIF ==== */

/* Konstruktor */
void CreatePeta (int NB, int NK, Peta *P);
// Membentuk peta baru dengan baris sebanyak NB dan kolom sebanyak NK
// I.S. NB dan NK valid
// F.S. Terbentuk peta P kosong sesuai definisi

/* Selektor */
// Selektor disamakan dengan type MATRIKS

/* Fungsi-Fungsi Validasi */

boolean IsPetaValid(int NB, int NK);
// Mengecek banyak baris dan kolom yang dimasukkan pengguna sesuai spesifikasi
// minimal 10x10, maksimal 20x30

/* Fungsi Display */

void DisplayPeta (Peta P);
// Mencetak peta ke layar

#endif

