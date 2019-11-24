#include "../boolean.h"
#include <stdio.h>
#include "../arraydin/arraydin.h"
#include <stdlib.h>
#include "../bangunan/bangunan.h"
/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxel)
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */
{
    MaxEl(*T) = maxel;
    TI(*T) = (BANGUNAN *) malloc ((maxel+1) *sizeof(BANGUNAN));
    Neff(*T) = 0;    
}

void Dealokasi(TabInt *T)
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
{
    free(TI(*T));
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int Nbbangunan(TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
{
    return Neff(T);
}
int MaxElement(TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
    return MaxEl(T);
}
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
    return IdxMin;
}

IdxType GetLastIdx(TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
    return Neff(T);
}

// * ********** Test Indeks yang valid ********** */
// boolean IsIdxValid(TabInt T, IdxType i)
// /* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
// /* yaitu antara indeks yang terdefinisi utk container*/
// {
//     return ((i >= IdxMin) && (i <=MaxEl(T)));
// }
// boolean IsIdxEff(TabInt T, IdxType i)
// /* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
// /* yaitu antara FirstIdx(T)..LastIdx(T) */
// {
//     return ((i >= GetFirstIdx(T))&&(i <= GetLastIdx(T)));
// }

// /* ********** TEST KOSONG/PENUH ********** */
// /* *** Test tabel kosong *** */
// boolean IsEmpty(TabInt T)
// /* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
// {
//     return(Neff(T) == 0);
// }
// /* *** Test tabel penuh *** */
// boolean IsFull(TabInt T)
// /* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
// {
//     return (Neff(T)==MaxEl(T));
// }

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
// void BacaIsi(TabInt *T)
// /* I.S. T sembarang dan sudah dialokasikan sebelumnya */
// /* F.S. Tabel T terdefinisi */
// /* Proses : membaca banyaknya elemen T dan mengisi nilainya */
// /* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
// /*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
// /*    Jika N tidak valid, tidak diberikan pesan kesalahan */
// /* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
//       IdxMin satu per satu diakhiri enter */
// /*    Jika N = 0; hanya terbentuk T kosong */
// {
//     int N,i,isi;

//     do {
//         scanf("%d",&N);
//     }
//     while (!((N>=0) && (N <= MaxEl(*T))));    
//     if (N==0){
//         MakeEmpty(&*T,MaxEl(*T));
//     }
//     else{
//         Neff(*T) = N;
//         for (i=IdxMin;(i<= N);i++){
//         scanf("%d\n",&isi);
//         bangunan(*T,i) = isi;
//     }
//     }
// }
// void TulisIsiTab(TabInt T)
// /* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
//    antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
//    di tengah, atau di belakang, termasuk spasi dan enter */
// /* I.S. T boleh kosong */
// /* F.S. Jika T tidak kosong: [e1,e2,...,en] */
// /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
// /* Jika tabel kosong : menulis [] */
// {
//     if (IsEmpty(T)){
//         printf("[]");
//     }
//     else{
//         printf("[");
//         for (int i=IdxMin;(i < Neff(T));i++){
//             printf("%d,",bangunan(T,i));
//         }
//         printf("%d]",bangunan(T,Neff(T)));
//     }
// }

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
// TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus)
// /* Prekondisi : T1 dan T2 memiliki Neff sama dan tidak kosong */
// /* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
// /* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
// {
//     TabInt tab;
//     MakeEmpty(&tab,MaxEl(T1));
//     if (plus){
//     for (int i=GetFirstIdx(T1);(i<=Neff(T1));i++){
//         bangunan(tab,i) = bangunan(T1,i) + bangunan(T2,i);
//     }
//     Neff(tab) = Neff(T1);
//     return tab;
//     }
//     else{
//     for (int i=GetFirstIdx(T1);(i<=Neff(T1));i++){
//         bangunan(tab,i) = bangunan(T1,i) - bangunan(T2,i);
//     }
//     Neff(tab) = Neff(T1);
//     return tab;
//     }
// }
/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
// boolean IsEQ(TabInt T1, TabInt T2)
// /* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */
// {
//     boolean answer;
//     answer = true;
//     if (Neff(T1) != Neff(T2)){//         answer = false;
//     }
//     else{
//         for (int i = GetFirstIdx(T1);(i<= Neff(T1));i++){
//             if (bangunan(T1,i) != bangunan(T2,i)) {
//                 answer = false;
//                 break;
//             }
//         }
//     }
//     return answer;
// }

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
// IdxType Search1(TabInt T, ElType X)
// /* Search apakah ada elemen tabel T yang bernilai X */
// /* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
// /* Jika tidak ada, mengirimkan IdxUndef */
// /* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
// /* Skema Searching yang digunakan bebas */
// {
//     int answer;
//     answer = IdxUndef;
//     for (int i=IdxMin;(i<= Neff(T));i++){
//             if (bangunan(T,i) == X){
//                 /* if X is found */
//                 answer = i;
//                 break;
//             }
//         }
//     return answer;
// }
// boolean SearchB(TabInt T, ElType X)
// /* Search apakah ada elemen tabel T yang bernilai X */
// /* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
// /* Skema searching yang digunakan bebas */
// {
//     boolean found = false;

//     for (int i=IdxMin;(i<= Neff(T));i++){
//             if (bangunan(T,i) == X){
//                 found = true;
//                 break;
//             }
//         }

//     return found;
// }
/* ********** NILAI EKSTREM ********** */
// void MaxMin(TabInt T, ElType *Max, ElType *Min)
// /* I.S. Tabel T tidak kosong */
// /* F.S. Max berisi nilai maksimum T;
//         Min berisi nilai minimum T */
// {
//     int i;
//     *Max = -32600;
//     *Min = 32600;
//     for (i = IdxMin; (i <= Neff(T)); i++){
// 			if (bangunan(T,i) > *Max) {
// 				*Max = bangunan(T,i);
// 			}
// 			if (bangunan(T,i) < *Min) {
// 				*Min = bangunan(T,i);
// 			}
//     }

// }

/* ********** OPERASI LAIN ********** */
void CopyTab(TabInt Tin, TabInt *Tout){
    MakeEmpty(Tout,MaxEl(Tin));
    Neff(*Tout) = Neff(Tin);
    for (int i=GetFirstIdx(Tin); (i<=Neff(Tin)); i++){
        bangunan(*Tout,i) = bangunan(Tin,i);
    }
}
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */
// {
//     MakeEmpty(Tout,MaxEl(Tin));
//     Neff(*Tout) = Neff(Tin);
//     for (int i=GetFirstIdx(Tin); (i<=Neff(Tin)); i++){
//         bangunan(*Tout,i) = bangunan(Tin,i);
//     }
// }
// ElType SumTab(TabInt T)
// /* Menghasilkan hasil penjumlahan semua elemen T */
// /* Jika T kosong menghasilkan 0 */
// {
//     int i,answer;
//     answer = 0;
//     if (IsEmpty(T)){
//         return answer;
//     }
//     else
//         for (i = GetFirstIdx(T);(i<=Neff(T)); i++ ){
//             answer = answer + bangunan(T,i);
//         }
//         return answer;
// }

// int CountX(TabInt T, ElType X)
// /* Menghasilkan berapa banyak kemunculan X di T */
// /* Jika T kosong menghasilkan 0 */
// {
//     int count = 0;
// 	if (IsEmpty(T)){
//         return count;
//     }
//     else{
// 	for (int i = IdxMin; i <= Neff(T) ; i++){
// 		if (bangunan(T,i) == X){
// 			count ++;
// 		}
// 	}
// 	return count;
//     }
// }
// boolean IsAllGenap(TabInt T)
// /* Menghailkan true jika semua elemen T genap. T boleh kosong */
// {
// 	int i;
//     boolean answer;
//     answer = true;
//     if (IsEmpty(T)){
//         answer = false;
//         return answer;
//     }
//     else{
// 	for (i = IdxMin; i <= Neff(T) ; i++){
// 		if ((bangunan(T,i) % 2) != 0){
//             answer = false;
// 		}
// 	}
// 	return answer;
//     }
// }
// /* ********** SORTING ********** */
// void Sort(TabInt *T, boolean asc)
// /* I.S. T boleh kosong */
// /* F.S. Jika asc = true, T terurut membesar */
// /*      Jika asc = false, T terurut mengecil */
// /* Proses : Mengurutkan T dengan salah satu algoritma sorting,
//    algoritma bebas */
// {   int i, x, j,temp;
//     if (asc){
        
//         if (Neff(*T) > 1){
//         for (i = IdxMin+1; (i <= Neff(*T)); i++){
//            x = bangunan(*T,i);
//            j = i-1;
//            while ((j >= IdxMin) && (bangunan(*T,j) > x))
//            {
//                bangunan(*T,j+1) = bangunan(*T,j);
//                j = j-1;
//            }
//            bangunan(*T,j+1) = x;
//             }
//         }
//     }
//     else{
//         if (!(IsEmpty(*T))){
//         for (i = IdxMin; (i <= (Neff(*T)-1)); i++){
//             x = i;
//             for (j = i+1; j <= Neff(*T); j++){
//               if ((bangunan(*T,j)) > (bangunan(*T,x))){
//                    x = j;
//                    }
//             }
//             temp = bangunan(*T,x);
//             bangunan(*T,x) = bangunan(*T, i);
//             bangunan(*T, i) = temp;
//         }
//         }
//     }
// }

// /* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
// /* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(TabInt *T, BANGUNAN *B)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
    bangunan(*T,(GetLastIdx(*T)+1)) = *B;
    Neff(*T)+=1;
}
// /* ********** MENGHAPUS ELEMEN ********** */
// void DelLastEl(TabInt *T, ElType *X)
// /* Proses : Menghapus elemen terakhir tabel */
// /* I.S. Tabel tidak kosong */
// /* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
// /*      Banyaknya elemen tabel berkurang satu */
// /*      Tabel T mungkin menjadi kosong */
// {
//     *X = bangunan(*T,GetLastIdx(*T));
//     Neff(*T)-=1;
// }

// /* ********* MENGUBAH UKURAN ARRAY ********* */
// void GrowTab(TabInt *T, int num)
// /* Proses : Menambahkan max element sebanyak num */
// /* I.S. Tabel sudah terdefinisi */
// /* F.S. Ukuran tabel bertambah sebanyak num */
// {
//     MaxEl(*T)= MaxEl(*T)+num;
//     TI(*T)= realloc (TI(*T),(MaxEl(*T)+num)*sizeof(ElType));  
// }

// void ShrinkTab(TabInt *T, int num)
// /* Proses : Mengurangi max element sebanyak num */
// /* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
// /* F.S. Ukuran tabel berkurang sebanyak num. */
// {
    
//     MaxEl(*T)-=num;
//     if (MaxEl(*T) < Neff(*T)){
//         Neff(*T)=MaxEl(*T);
//     }
// }

// void CompactTab(TabInt *T)
// /* Proses : Mengurangi max element sehingga Neff = MaxEl */
// /* I.S. Tabel tidak kosong */
// /* F.S. Ukuran MaxEl = Neff */
// {
//     MaxEl(*T)=Neff(*T);
// }