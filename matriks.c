/* Deskripsi : inplementasi fungsi prosedur header ADT Matriks */

#include <stdio.h>
#include "lib\matriks.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{   /* Kamus lokal */
	indeks i, j;
    /* Algoritma */
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;

    for (i = BrsMin; i <= NB; i++) {
		for (j = KolMin; j <= NK; j++) {
			ElmtMatriks(*M, i, j) = ' ';
		}
	}
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxMatriksValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{	/* Kamus lokal */
	/* Algoritma */
	return (i >= BrsMin && i <= BrsMax && j >= KolMin && j <= KolMax);
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{	/* Kamus lokal */
	/* Algoritma */
	return BrsMin;
}
indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{	/* Kamus lokal */
	/* Algoritma */
	return KolMin;
}
indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{	/* Kamus lokal */
	/* Algoritma */
	return NBrsEff(M);
}
indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{	/* Kamus lokal */
	/* Algoritma */
	return NKolEff(M);
}
boolean IsIdxMatriksEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{	/* Kamus lokal */
	/* Algoritma */
	return (i >= GetFirstIdxBrs(M) && i <= GetLastIdxBrs(M) && j >= GetFirstIdxKol(M) && j <= GetLastIdxKol(M));
}

ElType GetElmtDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{	/* Kamus lokal */
	/* Algoritma */
	return ElmtMatriks(M, i, i);
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{	/* Kamus lokal */
	indeks i, j;
	/* Algoritma */
	MakeMATRIKS(NBrsEff(MIn), NKolEff(MIn), &(*MHsl));
	for (i = GetFirstIdxBrs(MIn); i <= GetLastIdxBrs(MIn); i++) {
		for (j = GetFirstIdxKol(MIn); j <= GetLastIdxKol(MIn); j++) {
			ElmtMatriks(*MHsl, i, j) = ElmtMatriks(MIn, i, j);
		}
	}
}

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
{	/* Kamus lokal */
	indeks i, j;
	/* Algoritma */
	MakeMATRIKS(NB, NK, &(*M));
	for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++) {
		for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++) {
			scanf("%d", &ElmtMatriks(*M, i, j));
		}
	}
}
void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{	/* Kamus lokal */
	indeks i, j;
	/* Algoritma */
	for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
		for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
			printf("%c", ElmtMatriks(M, i, j));
			if (j == GetLastIdxKol(M) && i < GetLastIdxBrs(M)) {
				printf("\n");
			}
			if (j < GetLastIdxKol(M)) {
				printf(" ");
			}
		}
	}
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQMatriks (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
{	/* Kamus lokal */ 
	indeks i, j;
	boolean state;
	/* Algoritma */
	if (NBrsEff(M1) == NBrsEff(M2) && NKolEff(M1) == NKolEff(M2)) {
		state = true;
		i = GetFirstIdxBrs(M1);
		state = true;
		while (state == true && i <= GetLastIdxBrs(M1)) {
			j = GetFirstIdxKol(M1);
			while (state == true && j <= GetLastIdxKol(M1)) {
				state = (ElmtMatriks(M1, i, j) == ElmtMatriks(M2, i, j));
				j = j + 1;
			}
			i = i + 1;
		}
		return state;
	}
	else {
		return false;
	}
}
boolean NEQMatriks (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{	/* Kamus lokal */
	/* Algoritma */
	return (!EQMatriks(M1, M2));
}
boolean EQSizeMatriks (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{	/* Kamus lokal */
	/* Algoritma */
	return (NBrsEff(M1) == NBrsEff(M2) && NKolEff(M1) == NKolEff(M2));
}

/* ********** Operasi lain ********** */
int NBElmtMatriks (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{	/* Kamus lokal */
	/* Algoritma */
	return (NBrsEff(M) * NKolEff(M));
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M)
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
{	/* Kamus lokal */
	/* Algoritma */
	return (NBrsEff(M) == NKolEff(M));
}
boolean IsSimetri (MATRIKS M)
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M)
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
{	/* Kamus lokal */
	indeks i, j;
	boolean state;
	/* Algoritma */
	if (IsBujurSangkar(M)) {
		state = true;
		i = GetFirstIdxBrs(M);
		while (state == true && i <= GetLastIdxBrs(M)) {
			j = GetFirstIdxKol(M);
			while (state == true && j <= GetLastIdxKol(M)) {
				state = ElmtMatriks(M, i, j) == ElmtMatriks(M, j, i);
				j = j + 1;
			}
			i = i + 1;
		}
		return state;
	}
	else {
		return false;
	}
}

boolean IsMatriksValid (MATRIKS M)
/* Mengirimkan true jika banyak masing-masing baris dan kolom lebih dari sama dengan 10 dan
    kurang dari sama dengan 20 */
{
	if ((GetFirstIdxBrs(M) >= 10) && (GetLastIdxBrs(M) <= 20) && (GetFirstIdxKol(M) >= 10) && (GetLastIdxKol(M) <= 20))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Transpose (MATRIKS * M)
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
{	/* Kamus lokal */
	indeks i, j;
	MATRIKS Maja;
	/* Algoritma */
	MakeMATRIKS(NKolEff(*M), NBrsEff(*M), &Maja);
	for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++) {
		for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++) {
			ElmtMatriks(Maja, j, i) = ElmtMatriks(*M, i, j);
		}
	}
	CopyMATRIKS(Maja, M);
}
