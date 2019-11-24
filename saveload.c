/* File : saveload.c */
/* Implementasi dari modul saveload.h */

#include "lib/peta.h"       
#include "lib/bangunan.h"
#include "lib/arraydin.h"    
#include "lib/graph.h"       
#include "lib/point.h"      
#include "lib/boolean.h"    
#include "lib/command.h"
#include "lib/mesinkar.h"
#include "lib/mesinload.h"
#include "lib/saveload.h"
#include <stdio.h>
#include <stdlib.h>

static FILE * src;
static FILE * src2;

void ReadGraf(Graph* G, int JmlhBang)
/* I.S. : G kosong */
/* F.S. : G diisi dengan graf yang merepresentasikan hubungan antar bangunan */
{   /* Kamus lokal */
    int i, j;
    char line[100];
    addrNode P;
    /* Algoritma */
    CreateGraph(1, G);
    for (i = 2; i <= JmlhBang; i++) {
        P = AllocNode(i);
        InsertNode(G, i, P);
    }
    for (i = 1; i <= JmlhBang; i++) {
        fgets(line, 100, src);
        src2 = fopen("pitakar.txt", "wt");
        fprintf(src2, "%s", line);
        fclose(src2);
        STARTDATA();
        for (j = 1; j <= JmlhBang; j++) {
            if (CLData.Value == 1) {
                InsertEdge(G, i, j);
            }
            ADVDATA();
        }
    }
    
}

void ReadFLAGS(FLAGS *F)
/* I.S. : F kosong */
/* F.S. : F diisi dengan kondisi "pertarungan" saat program di-save */
{   /* Kamus lokal */
    char line[100];
    boolean sF, aUF, cHF, eTF, wF;
    int sCD;
    /* Algoritma */
    fgets(line, 100, src);
    src2 = fopen("pitakar.txt", "wt");
    fprintf(src2, "%s", line);
    fclose(src2);
    STARTDATA();
    if (CLData.Value == 0) {
        sF = false;
    }
    else {
        sF = true;
    }
    ADVDATA();
    sCD = CLData.Value;
    ADVDATA();
    if (CLData.Value == 0) {
        aUF = false;
    }
    else {
        aUF = true;
    }
    ADVDATA();
    if (CLData.Value == 0) {
        cHF = false;
    }
    else {
        cHF = true;
    }
    ADVDATA();
    if (CLData.Value == 0) {
        eTF = false;
    }
    else {
        eTF = true;
    }
    ADVDATA();
    if (CLData.Value == 0) {
        wF = false;
    }
    else {
        wF = true;
    }
    SetFlag(F, sF, sCD, aUF, cHF, eTF, wF);
}

void ReadQueue(Queue *Q)
/* I.S. : Q kosong */
/* F.S. : Q diisi dengan antrian skill saat program di-save */
{   /* Kamus lokal */
	char line[100];
    /* Algoritma */
    CreateEmptyQ(Q, 10);
    fgets(line, 100, src);
    src2 = fopen("pitakar.txt", "wt");
    fprintf(src2, "%s", line);
    fclose(src2);
    STARTDATA();
    AddQ(Q, CLData.Value);
    ADVDATA();
    while (!EndLData) {
		AddQ(Q, CLData.Value);
		ADVDATA();
	}
}

/* ***** MENULIS KE DALAM FILE ***** */

void WriteBangunan(TabInt T)
/* I.S. : A tidak kosong */
/* F.S. : Bangunan-bangunan dalam A dituliskan ke dalam file */
{   /* Kamus lokal */
    int jmlhbang, i;
    /* Algoritma */
    jmlhbang = Neff(T);
    for (i = 1; i <= jmlhbang; i++) {
        fprintf(src, "%c %d %d %d %d %d %d %d %d\n", jenis(bangunan(T, i)), (int) Absis(lok(bangunan(T, i))), (int) Ordinat(lok(bangunan(T, i))), kepemilikan(bangunan(T, i)), level(bangunan(T, i)), tambahpas(bangunan(T, i)), maks(bangunan(T, i)), pasawal(bangunan(T, i)), pasukan(bangunan(T, i)));
    }
}

void WriteFLAGS(FLAGS F)
/* I.S. : F tidak kosong */
/* F.S. : Kondisi dalam F ditulis ke dalam file */
{   /* Kamus lokal */
    int sF, aUF, cHF, eTF, wF;
    /* Algoritma */
    if (GetSFlag(F)) {
        sF = 1;
    }
    else {
        sF = 0;
    }
    if (GetAUFlag(F)) {
        aUF = 1;
    }
    else {
        aUF = 0;
    }
    if (GetCHFlag(F)) {
        cHF = 1;
    }
    else {
        cHF = 0;
    }
    if (GetETFlag(F)) {
        eTF = 1;
    }
    else {
        eTF = 0;
    }
    if (GetWFlag(F)) {
        wF = 1;
    }
    else {
        wF = 0;
    }
    fprintf(src, "%d %d %d %d %d %d\n", sF, GetShieldCD(F), aUF, cHF, eTF, wF);
}

void WriteGraf(Graph G, int JmlhBang)
/* I.S. : G tidak kosong */
/* F.S. : Isi G ditulis ke dalam file */
{   /* Kamus lokal */
    int i, j;
    /* Algoritma */
    for (i = 1; i <= JmlhBang; i++) {
        for (j = 1; j <= JmlhBang; j++) {
            if (i != JmlhBang) {
                if (SearchEdge(G, i, j) == Nil) {
                    fprintf(src, "%d ", 0);
                }
                else {
                    fprintf(src, "%d ", 1);
                }
            }
            else {
                if (SearchEdge(G, i, j) == Nil) {
                    fprintf(src, "%d\n", 0);
                }
                else {
                    fprintf(src, "%d\n", 1);
                }
            }
        }
    }
}

void WriteQueue(Queue Q)
/* I.S. : Q tidak kosong */
/* F.S. : Isi dari Q ditulis ke dalam file */
{	/* Kamus lokal */
	int i, j;
	/* Algoritma */
	for (i = Head(Q); i < NBElmtQ(Q) + Head(Q); i++) {
		if (i > MaxElQ(Q)) {
			j = i - MaxElQ(Q);
		}
		else {
			j = i;
		}
		fprintf(src, "%d ", (Q).T[j]);
		if (j == NBElmtQ(Q) + Head(Q) - 1) {
			fprintf(src, "\n");
		}
	}
}

/* ********** PERINTAH-PERINTAH UTAMA ********** */

void LoadNewConfig(TabInt *T, Graph* G, Peta *P, const char *FileName)
/* I.S. : A, G, P kosong */
/* F.S. : A, G, dan P terisi sesuai konfigurasi dari file eksternal */
{   /* Kamus lokal */
    char line[100];
    int jmlhbang;
    /* Algoritma */
    /* Ambil nilai X */
    src = fopen(FileName, "rt");
    fgets(line, 100, src);
    src2 = fopen("pitakar.txt", "wt");
    fprintf(src2, "%s", line);
    fclose(src2);
    STARTDATA();
    NBrsEff(*P) = CLData.Value;
    ADVDATA();
    NKolEff(*P) = CLData.Value;
    fgets(line, 100, src);
    src2 = fopen("pitakar.txt", "wt");
    fprintf(src2, "%s", line);
    fclose(src2);
    STARTDATA();
    jmlhbang = CLData.Value;
    ReadBangunanOld(T, jmlhbang);
    ReadGraf(G, jmlhbang);
    fclose(src);
}

void SaveConfig(TabInt T, Graph G, Peta P, FLAGS F1, FLAGS F2, Queue Q1, Queue Q2, const char *FileName)
/* I.S. : A, G, P, F terdefinisi, tidak kosong */
/* F.S. : File eksternal diisi dengan konfigurasi berdasarkan A, G, F, P */
/* Format penulisan : Ukuran peta, Jumlah Bangunan, Daftar Bangunan (meliputi Huruf (Simbol), Lokasi (X Y), Kepemilikan, Level, Kelengkapan Bangunan (A, M, P, U)), Flags, dan Graf */
{   /* Kamus lokal */
    /* Algoritma */
    src = fopen(FileName, "wt");
    fprintf(src, "%d %d\n", NBrsEff(P), NKolEff(P));
    fprintf(src, "%d\n", Neff(T));
    WriteBangunan(T);
    WriteGraf(G, Neff(T));
    WriteFLAGS(F1);
    WriteFLAGS(F2);
    WriteQueue(Q1);
    WriteQueue(Q2);
    fclose(src);
}

void LoadExistingConfig(TabInt *T, Graph* G, Peta *P, FLAGS *F1, FLAGS *F2, Queue *Q1, Queue *Q2, const char *FileName)
/* I.S. : A, G, P, F bebas, bisa kosong */
/* F.S. : A, G, P, F diisi sesuai dengan konfigurrrasi dari file eksternal */
{   /* Kamus lokal */
    char line[100];
    int jmlhbang;
    /* Algoritma */
    src = fopen(FileName, "rt");
    fgets(line, 100, src);
    src2 = fopen("pitakar.txt", "wt");
    fprintf(src2, "%s", line);
    fclose(src2);
    STARTDATA();
    NBrsEff(*P) = CLData.Value;
    ADVDATA();
    NKolEff(*P) = CLData.Value;
    fgets(line, 100, src);
    src2 = fopen("pitakar.txt", "wt");
    fprintf(src2, "%s", line);
    fclose(src2);
    STARTDATA();
    jmlhbang = CLData.Value;
    Neff(*T) = jmlhbang;
    ReadBangunanNew(T, jmlhbang);
    ReadGraf(G, jmlhbang);
    ReadFLAGS(F1);
    ReadFLAGS(F2);
    ReadQueue(Q1);
    ReadQueue(Q2);
    fclose(src);
}

/* ********** PRIMITIF SAMPINGAN  ********** */
/* ***** MEMBACA DARI FILE ***** */

void ReadBangunanOld(TabInt *T, int JmlhBang)
/* I.S. : A kosong */
/* F.S. : A diisi dengan bangunan yang terdapat di dalam file sejumlah JmlhBang */
{   /* Kamus lokal */
    int i, x, y, kep;
    char line[100];
    char jns;
    BANGUNAN B;
    POINT P;
    /* Algoritma */
    MakeEmpty(T, JmlhBang);
    for (i = 1; i <= JmlhBang; i++) {
        fgets(line, 100, src);
        src2 = fopen("pitakar.txt", "wt");
        fprintf(src2, "%s", line);
        fclose(src2);
        STARTDATA();
        jns = CLData.Index;
        ADVDATA();
        x = CLData.Value;
        ADVDATA();
        y = CLData.Value;
        P = MakePOINT(x, y);
        if (i == 1) {
            kep = 1;
        }
        else if (i == 2) {
            kep = 2;
        }
        else {
            kep = 0;
        }
        B = SetBangunan(kep, jns, P);
        AddAsLastEl(T, &B);
    }
}

void ReadBangunanNew(TabInt *T, int JmlhBang)
/* I.S. : A kosong */
/* F.S. : A diisi dengan bangunan yang terdapat di dalam file sejumlah JmlhBang */
{   /* Algoritma */
    int i, x, y, kep, lvl, psk, a, m, u;
    char line[100];
    char jns;
    BANGUNAN B;
    /* Kamus lokal */
    MakeEmpty(T, JmlhBang);
    for (i = 1; i <= JmlhBang; i++) {
        fgets(line, 100, src);
        src2 = fopen("pitakar.txt", "wt");
        fprintf(src2, "%s", line);
        fclose(src2);
        STARTDATA();
        jns = CLData.Index;
        ADVDATA();
        x = CLData.Value;
        ADVDATA();
        y = CLData.Value;
        ADVDATA();
        kep = CLData.Value;
        ADVDATA();
        lvl = CLData.Value;
        ADVDATA();
        a = CLData.Value;
        ADVDATA();
        m = CLData.Value;
        ADVDATA();
        u = CLData.Value;
        ADVDATA();
        psk = CLData.Value;
        MakeBangunan(&B, kep, psk, a, m, u, lvl, x, y, jns);
        AddAsLastEl(T, &B);
    }
}
