/* File : queue.c */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib\queue.h"

/* ********* Prototype ********* */
boolean IsEmptyQ (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    if ((Head(Q) == Nil) && (Tail(Q) == Nil))
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

boolean IsFullQ (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    if (NBElmtQ(Q) == MaxElQ(Q))
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

int NBElmtQ (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    if (IsEmptyQ(Q) == true)
    {
        return 0;
    }
    else if (Head(Q) > Tail(Q))
    {
        return (MaxElQ(Q) - Head(Q) + Tail(Q) + 1);
    }
    else
    {
        return(Tail(Q) - Head(Q) + 1);
    }
}

/* *** Kreator *** */
void CreateEmptyQ (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    (*Q).T = (infotype *) malloc ((Max + 1) * sizeof(infotype));
    if ((*Q).T != NULL)
    {
        MaxElQ(*Q) = Max;
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
    else
    {
        MaxElQ(*Q) = 0;
    }
    
}

/* *** Destruktor *** */
void DeAlokasiQ(Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
    MaxElQ(*Q) = 0;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void AddQ (Queue * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
{
    if (IsEmptyQ(*Q) == true)
    {
        Head(*Q) = 1;
        Tail(*Q) = 1;
        InfoHead(*Q) = X;
    }
    else
    {
        if (Tail(*Q) == MaxElQ(*Q))
        {
            Tail(*Q) = 1;
        }
        else
        {
            Tail(*Q) = Tail(*Q) + 1;
        } 
    }
    InfoTail(*Q) = X;   
}
void DelQ (Queue * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
{
    *X = InfoHead(*Q);
    if(NBElmtQ(*Q) == 1)
    {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
    else
    {
        if (Head(*Q) == MaxElQ(*Q))
        {
            Head(*Q) = 1;
        }
        else
        {
            Head(*Q) = Head(*Q) + 1;
        }   
    }
}

int headOfQueue (Queue Q)
{
    // KAMUS LOKAL
    // ALGORITMA
        return InfoHead(Q);
}