/* File : driver_saveload.c */
/* Driver untuk modul save dan load */

#include "lib/saveload.h"
#include "lib/listlinier.h"
#include "lib/command.h"
#include <string.h>
#include <stdlib.h>

int main() {
    TabInt T;
    Graph G;
    Peta P;
    List L;
    FLAGS F1, F2;
    FILE * src;
    Queue Q1, Q2;
    char line[100];
    int i, j;
    const char* FileName;
    /* Untuk LoadNewConfig */
    FileName = "newconfig.txt";
    LoadNewConfig(&T, &G, &P, FileName);
    printf("%d %d\n", NBrsEff(P), NKolEff(P));
    printf("%d\n", Neff(T));
    for (i = 1; i <= Neff(T); i++) {
        printf("%c %d %d\n", jenis(bangunan(T, i)), (int) Absis(lok(bangunan(T, i))), (int) Ordinat(lok(bangunan(T, i))));
    }
    L = MakeListEdge(G, 9);
    PrintInfo(L);
    /* Untuk SaveConfig */
    FileName = "savedat.txt";
    SaveConfig(T, G, P, F1, F2, Q1, Q2, FileName);
    src = fopen(FileName, "rt");
    fgets(line, 100, src);
    printf("%s", line);
    while (!feof(src)) {
        fgets(line, 100, src);
        printf("%s", line);
    }
    fclose(src);
    /* Untuk LoadExistingConfig */
    FileName = "savedat.txt";
    LoadExistingConfig(&T, &G, &P, &F1, &F2, &Q1, &Q2, FileName);
    printf("%d %d\n", NBrsEff(P), NKolEff(P));
    printf("%d\n", Neff(T));
    for (i = 1; i <= Neff(T); i++) {
        printf("%c %d %d %d %d %d %d %d %d\n", jenis(bangunan(T, i)), (int) Absis(lok(bangunan(T, i))), (int) Ordinat(lok(bangunan(T, i))), kepemilikan(bangunan(T, i)), level(bangunan(T, i)), tambahpas(bangunan(T, i)), maks(bangunan(T, i)), pasawal(bangunan(T, i)), pasukan(bangunan(T, i)));
    }
    L = MakeListEdge(G, 9);
    PrintInfo(L);
    if (GetSFlag(F1)) {
        printf("true ");
    }
    else {
        printf("false ");
    }
    printf("%d ", GetShieldCD(F1));
    if (GetAUFlag(F1)) {
        printf("true ");
    }
    else {
        printf("false ");
    }
    if (GetCHFlag(F1)) {
        printf("true ");
    }
    else {
        printf("false ");
    }
    if (GetETFlag(F1)) {
        printf("true ");
    }
    else {
        printf("false ");
    }
    if (GetWFlag(F1)) {
        printf("true\n");
    }
    else {
        printf("false\n");
    }
    if (GetSFlag(F2)) {
        printf("true ");
    }
    else {
        printf("false ");
    }
    printf("%d ", GetShieldCD(F1));
    if (GetAUFlag(F2)) {
        printf("true ");
    }
    else {
        printf("false ");
    }
    if (GetCHFlag(F2)) {
        printf("true ");
    }
    else {
        printf("false ");
    }
    if (GetETFlag(F2)) {
        printf("true ");
    }
    else {
        printf("false ");
    }
    if (GetWFlag(F2)) {
        printf("true\n");
    }
    else {
        printf("false\n");
    }
    for (i = Head(Q1); i < NBElmtQ(Q1) + Head(Q1); i++) {
		if (i > MaxElQ(Q1)) {
			j = i - MaxElQ(Q1);
		}
		else {
			j = i;
		}
		fprintf(src, "%d ", (Q1).T[j]);
		if (j == NBElmtQ(Q1) + Head(Q1) - 1) {
			fprintf(src, "\n");
		}
	}
	for (i = Head(Q2); i < NBElmtQ(Q2) + Head(Q2); i++) {
		if (i > MaxElQ(Q2)) {
			j = i - MaxElQ(Q2);
		}
		else {
			j = i;
		}
		fprintf(src, "%d ", (Q2).T[j]);
		if (j == NBElmtQ(Q2) + Head(Q2) - 1) {
			fprintf(src, "\n");
		}
	}
    return 0;
}
