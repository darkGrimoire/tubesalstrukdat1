/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infolist adalah integer */
#include "../listlinier/listlinier.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "../boolean.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyList (List L)
/* Mengirim true jika list kosong */
{
    if (First(L) == NilL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    First(*L) = NilL;
}

/****************** Manajemen Memori ******************/
address AlokasiList (infolist X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=NilL */
/* Jika alokasi gagal, mengirimkan NilL */
{
    // KAMUS LOKAL
    address P;

    // ALGORITMA
    P = (address) malloc (sizeof(ElmtList));
    if (P!=NilL)
    {
        Info(P) = X;
        Next(P) = NilL;
        return P;
    }
    else
    {
        return NilL;
    }
}

void DealokasiList (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address SearchList (List L, infolist X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan NilL */
{
    // KAMUS LOKAL    
    address P;

    // ALGORITMA
    P = First(L);
    while ((Next(P) != NilL) && (Info(P) != X))
    {
        P = Next(P);
    }

    if (Next(P) == NilL)
    {
        if (Info(P) == X)
        {
            return P;
        }
        else
        {
            return NilL;
        }  
    }
    else
    {
        return P;
    }  
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infolist X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    // KAMUS LOKAL
    address P;

    // ALGORITMA
    P = AlokasiList(X);
    if (P != NilL)
    {
        InsertFirst(L, P);
    }
}

void InsVLast (List *L, infolist X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    // KAMUS LOKAL
    address P;

    // ALGORITMA
    P = AlokasiList(X); 
    if (P != NilL)
    {
        InsertLast(L, P);
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infolist *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    // KAMUS LOKAL
    address P;

    // ALGORITMA
    P = First(*L);
    *X = Info(P);
    First(*L) = Next(First(*L));
    Next(P) = NilL;
    DealokasiList(&P);
}

void DelVLast (List *L, infolist *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    // KAMUS LOKAL
    address P;

    // ALGORITMA
    DelLast(L, &P);
    *X = Info(P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    Next(P) = First(*L);
    First(*L) = P;
}
void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    // KAMUS LOKAL
    
    // ALGORITMA
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    // KAMUS LOKAL
    address temp;

    // ALGORITMA
    temp = First(*L);
    if (temp == NilL)
    {
        InsertFirst(L, P);
    }
    else
    {
        while (Next(temp) != NilL)
        {
            temp = Next(temp);
        }
        InsertAfter(L, P, temp);
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    *P = First(*L);
    First(*L) = Next(First(*L));
}

void DelP (List *L, infolist X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    // KAMUS LOKAL
    address temp, prec;

    // ALGORITMA
    temp = SearchList(*L, X);
    prec = First(*L);

    if (temp != NilL)
    {
        if (prec == temp)
        {
            DelFirst(L, &temp);
        }
        else
        {
            while(Next(prec) != temp)
            {
                prec = Next(prec);
            }
            Next(prec) = Next(temp);
            temp = NilL;
            DealokasiList(&temp);
        }  
    }
}

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
    // KAMUS LOKAl
    address prec;

    // ALGORITMA
    prec = First(*L);
    if (Next(prec) == NilL)
    {
        DelFirst(L, P);
    }
    else
    {
        while (Next(Next(prec)) !=  NilL)
        {
            prec = Next(prec);
        }
        DelAfter(L, P, prec);
    }    
}

void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
    Next(*Pdel) = NilL;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    // KAMUS LOKAL
    address P = First(L);

    // ALGORITMA
    if (IsEmptyList(L))
    {
        printf("%s","[]");
    }
    else
    {
        printf("%s","[");
        while(Next(P) != NilL)
        {
            printf("%d%s", Info(P),",");
            P = Next(P);
        }
        printf("%d%s", Info(P), "]");
    }
}

int NbElmtList (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    // KAMUS LOKAL
    address P;
    int count = 0;
    
    // ALGORITMA
    P = First(L);
    while (P != NilL)
    {
        count += 1;
        P = Next(P);
    }
    return count;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infolist MaxList (List L)
/* Mengirimkan nilai Info(P) yang maksimum */
{
    //KAMUS
    infolist a;
    address P = First(L);
    
    //ALGORITMA
    a = Info(P);
    while(Next(P)!=NilL)
    {
        if (a < Info(Next(P)))
        {
            a = Info(Next(P));
        }
        P = Next(P);
    }
    
    return a;
}

/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    // KAMUS LOKAL
    address last;
    // ALGORITMA
    if(IsEmptyList(*L1)){
        First(*L3) = First(*L2);
        First(*L2) = NilL;
    }
    else
    {
        First(*L3) = First(*L1);
        last = First(*L3);
        while (Next(last) != NilL)
        {
            last = Next(last);
        }
        Next(last) = First(*L2);
        First(*L1) = NilL;
        First(*L2) = NilL;
    }
    
}


void CopyList (List L1, List *L2){
/* I.S. L1 terdefinisi 
   F.S. L2 berisi salinan semua elemen L1 */
    // KAMUS LOKAL
        address P,L,temp;
    // ALGORITMA
        P = First(L1);
        CreateList(L2);
        while(P!=NilL){
            InsVLast(L2, Info(P));
            P=Next(P);
        }
}
