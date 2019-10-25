/* File: arraydinpos.c */
/* Nama: Faris Rizki Ekananda*/
/* NIM: 13518125 */
/* Tanggal: 12 September 2019 */
/* BODY ADT ArrayPos (implisit) Dinamik*/

#include <stdlib.h>
#include <stdio.h>
#include "arraydinpos.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeArray(TabInt *T, int maxel){
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */
/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */
  /* KAMUS */
  int i;
  /* ALGORITMA */
  TI(*T) = (int *) malloc((maxel+1) * sizeof(int));
  MaxEl(*T) = maxel;
  for (i=1;i<=MaxEl(*T);i++){
    Elmt(*T,i) = ValUndef;
  }
}

void DealokasiArray(TabInt *T){
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; NbElmt(T)=0 */
  /* KAMUS */
  /* ALGORITMA */
  free(TI(*T));
  MaxEl(*T) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmtArray(TabInt T){
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
  /* KAMUS */
  int i,count;
  /* ALGORITMA */
  i=IdxMin;
  while ((Elmt(T,i) != ValUndef) && i<MaxEl(T)){
    i++;
  }
  if (Elmt(T,i) == ValUndef){
    return i-1;
  }else{
    return i;
  }
}

/* *** Daya tampung container *** */
int MaxElement(TabInt T){
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
  /* KAMUS */
  /* ALGORITMA */
  return MaxEl(T);
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdxArr(TabInt T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
  /* KAMUS */
  /* ALGORITMA */
  return IdxMin;
}

IdxType GetLastIdxArr(TabInt T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
  /* KAMUS */
  /* ALGORITMA */
  return NbElmtArray(T);
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValidArr(TabInt T, IdxType i){
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
  /* KAMUS */
  /* ALGORITMA */
  return ((i>=IdxMin) && (i<=MaxElement(T)));
}

boolean IsIdxEffArr(TabInt T, IdxType i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
  /* KAMUS */
  /* ALGORITMA */
  return ((i>=GetFirstIdxArr(T)) && (i<=GetLastIdxArr(T)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyArr(TabInt T){
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
  /* KAMUS */
  int i;
  /* ALGORITMA */
  i = IdxMin;
  if (Elmt(T,i) == ValUndef){
    return true;
  }else{
    return false;
  }
}

/* *** Test tabel penuh *** */
boolean IsFullArr(TabInt T){
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
  /* KAMUS */
  int i;
  /* ALGORITMA */
  i = MaxEl(T);
  if (Elmt(T,i) != ValUndef){
    return true;
  }else{
    return false;
  }
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsiArr(TabInt *T){
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
  /* KAMUS */
  int N;
  ElType elemen;
  IdxType i;
  /* ALGORITMA */
  do{
    scanf("%d",&N);
  }while((N<0) || (N>MaxElement(*T)));
  if (N>0){
    for (i=IdxMin;i<=N;i++){
      scanf("%d", &elemen);
      Elmt(*T,i) = elemen;
    }
  }
}

void TulisIsiTab(TabInt T){
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
  /* KAMUS */
  IdxType i;
  /* ALGORITMA */
  if (IsEmptyArr(T)){
    printf("[]");
  }else{
    printf("[");
    for (i=IdxMin;i<NbElmtArray(T);i++){
      printf("%d,", Elmt(T,i));
    }
    printf("%d]", Elmt(T,NbElmtArray(T)));
  }
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus){
/* Prekondisi : T1 dan T2 memiliki NbElmt sama dan tidak kosong */
/*              Jika plus=false, tidak ada elemen T1-T2 yang menghasilkan nilai <= 0 */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
  /* KAMUS */
  IdxType i;
  TabInt T;
  /* ALGORITMA */
  MakeEmpty(&T,MaxElement(T1));
  for (i=IdxMin;i<=NbElmtArray(T1);i++){
    if (plus){Elmt(T,i) = Elmt(T1,i) + Elmt(T2,i);}
    else {Elmt(T,i) = Elmt(T1,i) - Elmt(T2,i);}
  }
  return T;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQTab(TabInt T1, TabInt T2){
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika NbElmt T1 = T2 dan semua elemennya sama */
  /* KAMUS */
  boolean flag;
  IdxType i;
  /* ALGORITMA */
  i = IdxMin;
  flag = true;
  if (NbElmtArray(T1) != NbElmtArray(T2)){
    flag = false;
  }else{
    while ((i<=NbElmtArray(T1)) && (flag)){
      if (Elmt(T1,i) != Elmt(T2,i)){
        flag = false;
      }
      i++;
    }
  }
  return flag;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1Tab(TabInt T, ElType X){
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
  /* KAMUS */
  IdxType i;
  /* ALGORITMA */
  i = IdxMin;
  if (IsEmptyArr(T)){
    return IdxUndef;
  }else{
    while ((Elmt(T,i) != X) && (i<NbElmtArray(T))){
      i++;
    }
    if (Elmt(T,i) == X){
      return i;
    }else{
      return IdxUndef;
    }
  }
}

boolean SearchBTab(TabInt T, ElType X){
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */
  /* KAMUS */
  IdxType i;
  boolean Found;
  /* ALGORITMA */
  i = IdxMin;
  Found = false;
  if (IsEmptyArr(T)){
    return Found;
  }else{
    while ((i<=NbElmtArray(T)) && (!Found)){
      if (Elmt(T,i) == X){
        Found = true;
      }
      i++;
    }
    return Found;
  }
}

/* ********** NILAI EKSTREM ********** */
void MaxMinTab(TabInt T, ElType *Max, ElType *Min){
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
  /* KAMUS */
  IdxType i;
  ElType maxEl, minEl;
  /* ALGORITMA */
  maxEl = Elmt(T,IdxMin); minEl = Elmt(T,IdxMin);
  for (i=IdxMin+1;i<=NbElmtArray(T);i++){
    if (Elmt(T,i) > maxEl){
      maxEl = Elmt(T,i);
    }
    else if (Elmt(T,i) < minEl){
      minEl = Elmt(T,i);
    }
  }
  *Max = maxEl;
  *Min = minEl;
}

/* ********** OPERASI LAIN ********** */
void CopyTab(TabInt Tin, TabInt *Tout){
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, NbElmt dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */
  /* KAMUS */
  IdxType i;
  /* ALGORITMA */
  MakeEmpty(Tout,MaxEl(Tin));
  for (i=IdxMin;i<=NbElmtArray(Tin);i++){
    Elmt(*Tout,i) = Elmt(Tin,i);
  }
}

ElType SumTab(TabInt T){
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
  /* KAMUS */
  IdxType i;
  ElType sum;
  /* ALGORITMA */
  sum = 0;
  for (i=IdxMin;i<=NbElmtArray(T);i++){
    sum += Elmt(T,i);
  }
  return sum;
}

int CountXTab(TabInt T, ElType X){
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
  /* KAMUS */
  IdxType i;
  int counter;
  /* ALGORITMA */
  /* ALGORITMA */
  counter = 0;
  for (i=IdxMin;i<=NbElmtArray(T);i++){
    if(Elmt(T,i) == X){counter++;}
  }
  return counter;
}

boolean IsAllGenap(TabInt T){
/* Menghailkan true jika semua elemen T genap. T boleh kosong */
  /* KAMUS */
  IdxType i;
  boolean genap;
  /* ALGORITMA */
  i = IdxMin;
  genap = true;
  if (IsEmptyArr(T)){
    return !genap;
  }else{
    while ((i<=NbElmtArray(T)) && (genap)){
      if (Elmt(T,i) % 2 == 1){
        genap = false;
      }
      i++;
    }
    return genap;
  }
}

/* ********** SORTING ********** */
void SortTab(TabInt *T, boolean asc){
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */
  /* KAMUS */
  IdxType i,j,iMin,Pass;
  ElType Temp;
  /* ALGORITMA */
  if (!IsEmptyArr(*T)){
    if (asc){
      for(Pass=IdxMin+1;Pass<=NbElmtArray(*T);Pass++){
        Temp=Elmt(*T,Pass);
        i=Pass-1;
        while ((Temp<Elmt(*T,i)) && (i>IdxMin)){
          Elmt(*T,i+1) = Elmt(*T,i);
          i--;
        }
        if (Temp>=Elmt(*T,i)){
          Elmt(*T,i+1) = Temp;
        }else{
          Elmt(*T,i+1) = Elmt(*T,i);
          Elmt(*T,i) = Temp;
        }
      }
    }else{
      for (i=NbElmtArray(*T);i>=IdxMin;--i){
        iMin = IdxMin;
        for (j=IdxMin;j<=i;++j){
          if (Elmt(*T,j) < Elmt(*T,iMin)){
            iMin = j;
          }
        }
        Temp = Elmt(*T,i);
        Elmt(*T,i) = Elmt(*T,iMin);
        Elmt(*T,iMin) = Temp;
      }
    }
  }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastTab(TabInt *T, ElType X){
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
  /* KAMUS */
  /* ALGORITMA */
  if (NbElmtArray(*T)<MaxElement(*T)){Elmt(*T,NbElmtArray(*T)+1) = X;}
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastTab(TabInt *T, ElType *X){
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
  /* KAMUS */
  /* ALGORITMA */
  *X = Elmt(*T,NbElmtArray(*T));
  Elmt(*T,NbElmtArray(*T)) = ValUndef;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabInt *T, int num){
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */
  /* KAMUS */
  /* ALGORITMA */
  MaxEl(*T) += num;
  TI(*T) = (int *)realloc(TI(*T), MaxElement(*T) * sizeof(int));
}

void ShrinkTab(TabInt *T, int num){
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan NbElmt < MaxEl - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */
  /* KAMUS */
  /* ALGORITMA */
  MaxEl(*T) -= num;
  TI(*T) = (int *)realloc(TI(*T), MaxElement(*T) * sizeof(int));
}

void CompactTab(TabInt *T){
/* Proses : Mengurangi max element sehingga NbElmt = MaxEl */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxEl = NbElmt */
  /* KAMUS */
  /* ALGORITMA */
  MaxEl(*T) = NbElmtArray(*T);
  TI(*T) = (int *)realloc(TI(*T), (MaxElement(*T)+1) * sizeof(int));
}