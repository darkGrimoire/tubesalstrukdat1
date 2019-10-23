/* File ADT Matriks */
/* Nama : Hansel Grady Daniel Thamrin */
/* NIM : 13518140 */
/* Tanggal : 14 September 2019 */
/* Deskripsi : inplementasi fungsi prosedur header ADT Matriks */

#include <stdio.h>
#include "matriks.h"

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
			Elmt(*M, i, j) = 0;
		}
	}
}

/* *** Selektor *** */
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define Elmt(M,i,j) (M).Mem[(i)][(j)]

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j)
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
boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{	/* Kamus lokal */
	/* Algoritma */
	return (i >= GetFirstIdxBrs(M) && i <= GetLastIdxBrs(M) && j >= GetFirstIdxKol(M) && j <= GetLastIdxKol(M));
}

ElType GetElmtDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{	/* Kamus lokal */
	/* Algoritma */
	return Elmt(M, i, i);
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
			Elmt(*MHsl, i, j) = Elmt(MIn, i, j);
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
			scanf("%d", &Elmt(*M, i, j));
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
			printf("%d", Elmt(M, i, j));
			if (j == GetLastIdxKol(M) && i < GetLastIdxBrs(M)) {
				printf("\n");
			}
			if (j < GetLastIdxKol(M)) {
				printf(" ");
			}
		}
	}
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */
{	/* Kamus lokal */
	MATRIKS M3;
	indeks i, j;
	/* Algoritma */
	MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &M3);
	for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++) {
		for (j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++) {
			Elmt(M3, i, j) = Elmt(M1, i, j) + Elmt(M2, i, j);
		}
	}
	return M3;
}
MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */
{	/* Kamus lokal */
	MATRIKS M3;
	indeks i, j;
	/* Algoritma */
	MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &M3);
	for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++) {
		for (j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++) {
			Elmt(M3, i, j) = Elmt(M1, i, j) - Elmt(M2, i, j);
		}
	}
	return M3;
}
MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
{	/* Kamus lokal */
	MATRIKS M3;
	indeks i, j, k;
	/* Algoritma */
	MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &M3);
	for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++) {
		for (j = GetFirstIdxKol(M2); j <= GetLastIdxKol(M2); j++) {
			for (k = GetFirstIdxKol(M1); k <= GetLastIdxKol(M1); k++) {
				Elmt(M3, i, j) = Elmt(M3, i, j) + (Elmt(M1, i, k) * Elmt(M2, k, j));
			}
		}
	}
	return M3;
}
MATRIKS KaliKons (MATRIKS M, ElType X)
/* Mengirim hasil perkalian setiap elemen M dengan X */
{	/* Kamus lokal */
	MATRIKS M3;
	indeks i, j;
	/* Algoritma */
	MakeMATRIKS(NBrsEff(M), NKolEff(M), &M3);
	for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
		for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
			Elmt(M3, i, j) = Elmt(M, i, j) * X;
		}
	}
	return M3;
}
void PKaliKons (MATRIKS * M, ElType K)
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
{	/* Kamus lokal */
	indeks i, j;
	/* Algoritma */
	for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++) {
		for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++) {
			Elmt(*M, i, j) = Elmt(*M, i, j) * K;
		}
	}
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2)
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
				state = Elmt(M1, i, j) == Elmt(M2, i, j);
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
boolean NEQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{	/* Kamus lokal */
	/* Algoritma */
	return (!EQ(M1, M2));
}
boolean EQSize (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{	/* Kamus lokal */
	/* Algoritma */
	return (NBrsEff(M1) == NBrsEff(M2) && NKolEff(M1) == NKolEff(M2));
}

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M)
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
				state = Elmt(M, i, j) == Elmt(M, j, i);
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
boolean IsSatuan (MATRIKS M)
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
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
				state = (i != j && Elmt(M, i, j) == 0) || (i == j && Elmt(M, i, j) == 1);
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
boolean IsSparse (MATRIKS M)
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi:
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
{	/* Kamus lokal */
	indeks i, j;
	int count;
	/* Algoritma */
	count = 0;
	for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
		for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
			if (Elmt(M, i, j) != 0) {
				count = count + 1;
			}
		}
	}
	return 20 * count <= NBElmt(M);
}
MATRIKS Inverse1 (MATRIKS M)
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{	/* Kamus lokal */
	/* Algoritma */
	return KaliKons(M, -1);
}
float Determinan (MATRIKS M)
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
{	/* Kamus lokal */
	float det;
	indeks i, j, k;
	int sign;
	MATRIKS Mcad;
	/* Algoritma */
	if (NBElmt(M) == 1) {
		return Elmt(M, GetFirstIdxBrs(M), GetLastIdxBrs(M));
	}
	else {
		det = 0;
		sign = 1;
		for (i = GetFirstIdxKol(M); i <= GetLastIdxKol(M); i++) {
			MakeMATRIKS(NBrsEff(M)-1, NKolEff(M)-1, &Mcad);
			for (j = GetFirstIdxBrs(M); j <= GetLastIdxBrs(M); j++) {
				for (k = GetFirstIdxKol(M); k <= GetLastIdxKol(M); k++) {
					if (i > k) {
						Elmt(Mcad, j-1, k) = Elmt(M, j, k);
					}
					else if (i < k) {
						Elmt(Mcad, j-1, k-1) = Elmt(M, j, k);
					}
				}
			}
			det = det + sign * Elmt(M, GetFirstIdxBrs(M), i) * Determinan(Mcad);
			sign = -1 * sign;
		}
		return det;
	}
}
void PInverse1 (MATRIKS * M)
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{	/* Kamus lokal */
	/* Algoritma */
	*M = KaliKons(*M, -1);
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
			Elmt(Maja, j, i) = Elmt(*M, i, j);
		}
	}
	CopyMATRIKS(Maja, M);
}
