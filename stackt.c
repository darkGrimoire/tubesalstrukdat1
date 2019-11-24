/* File : stackt.c */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */

#include "lib\stackt.h"
#include <stdio.h>

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateStack (Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxElS */
/* jadi indeksnya antara 1.. MaxElS+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */
{
    Top(*S) = NilS;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack (Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    if (Top(S) == NilS)
    {
        return true;
    }
    else
    {
        return false;
    }    
}

boolean IsFullStack (Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    if (Top(S) == MaxElS)
    {
        return true;
    }
    else
    {
        return false;
    }   
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, stackinfotype X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    Top(*S) += 1;
    InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, stackinfotype* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    *X = InfoTop(*S);
    Top(*S) -= 1;
}