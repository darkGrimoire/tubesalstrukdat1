// Implementasi peta.h

#include "matriks.h"
#include "boolean.h"
#include <stdio.h>
#include "pcolor.h"
#include "peta.h"

/* ==== PROTOTIPE PRIMITIF ==== */

/* Konstruktor */
void CreatePeta (int NB, int NK, Peta *P)
// Membentuk peta baru dengan baris sebanyak NB dan kolom sebanyak NK
// border peta ( indeks 0,i; nb+1,i; j,0; nk+1,0) diisi '*'
// I.S. NB dan NK valid
// F.S. Terbentuk peta P kosong sesuai definisi
{
    if (IsPetaValid(NB, NK))
    {
        MakeMATRIKS(NB, NK, P);\
        // mengisi border dengan *
        // atas bawah
        for (int j = 0; j <= GetLastIdxKol(*P)+1; j++)
        {
            ElmtMatriks(*P, 0, j) = '*';
            ElmtMatriks(*P, GetLastIdxBrs(*P)+1 , j) = '*';
        }

        // kiri kanan
        for (int i = GetFirstIdxBrs(*P); i <= GetLastIdxBrs(*P)+1; i++)
        {
            ElmtMatriks(*P, i , 0) = '*';
            ElmtMatriks(*P, i , GetLastIdxKol(*P)+1) = '*';
        }
    }
    else
    {
        printf("%s", "Baris dan kolom tidak sesuai spesifikasi");
    }
    
}

/* Selektor */
// Selektor disamakan dengan type MATRIKS

/* Fungsi-Fungsi Validasi */

boolean IsPetaValid(int NB, int NK)
// Mengecek banyak baris dan kolom yang dimasukkan pengguna sesuai spesifikasi
// minimal 10x10, maksimal 20x30
{
    if ((NB >= 10) && (NB <= 20) && (NK >= 10) && (NK <= 30))
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

void IsiPeta(Peta *P, /*type array bangunan */);
// Mengisi matriks peta dengan bangunan pada array bangunan sesuai dengan lokasinya

/* Fungsi Display */

void DisplayPeta (Peta P);
// Mencetak peta ke layar
// I.S. Peta tidak kosong
// F.S. Peta dicetak ke layar dengan warna sesuai kepemilikan bangunan