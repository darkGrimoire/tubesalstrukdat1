// Driver peta

#include "peta.h"
#include "bangunan.h"
#include "arraydin.h"

int main(){
    // KAMUS
    BANGUNAN C0, C1, C2, T0, T1, T2, F0, F1, F2, V0, V1, V2;
    TabInt arrBan;
    Peta P;
    // ALGORITMA
    
    // inisialisasi peta
    CreatePeta(9, 9, &P); // peta tidak valid 1
    CreatePeta(30, 40, &P); // peta tidak valid 2
    CreatePeta(10, 4, &P); // peta tidak valid 3
    CreatePeta(10, 31, &P); // peta tidak valid 4
    CreatePeta(4, 30, &P); // peta tidak valid 5
    CreatePeta(30, 30, &P); // peta tidak valid 6
    CreatePeta(15, 15, &P); // peta 15x15 terbentuk;
    TulisMATRIKS(P);
    printf("\n");
    // inisialisasi bangunan
    MakeCastle(&C0);
    SetKepemilikan(&C0, 0);
    Absis(lok(C0)) = 3;
    Ordinat(lok(C0)) = 1;
    printf("Make C0!\n");

    MakeCastle(&C1);
    SetKepemilikan(&C1, 1);
    Absis(lok(C1)) = 13;
    Ordinat(lok(C1)) = 5;
    printf("Make C1!\n");

    MakeCastle(&C2);
    SetKepemilikan(&C2, 2);
    Absis(lok(C2)) = 10;
    Ordinat(lok(C2)) = 10;
    printf("Make C2!\n");

    MakeTower(&T0);
    SetKepemilikan(&T0, 0);
    Absis(lok(T0)) = 9;
    Ordinat(lok(T0)) = 14;
    printf("Make T0!\n");

    MakeTower(&T1);
    SetKepemilikan(&T1, 1);
    Absis(lok(T1)) = 12;
    Ordinat(lok(T1)) = 7;
    printf("Make T1!\n");

    MakeTower(&T2);
    SetKepemilikan(&T2, 2);
    Absis(lok(T2)) = 8;
    Ordinat(lok(T2)) = 6;
    printf("Make T2!\n");

    MakeFort(&F0);
    SetKepemilikan(&F0, 0);
    Absis(lok(F0)) = 7;
    Ordinat(lok(F0)) = 2;
    printf("Make F0!\n");

    MakeFort(&F1);
    SetKepemilikan(&F1, 1);
    Absis(lok(F1)) = 5;
    Ordinat(lok(F1)) = 11;
    printf("Make F1!\n");

    MakeFort(&F2);
    SetKepemilikan(&F2, 2);
    Absis(lok(F2)) = 4;
    Ordinat(lok(F2)) = 15;
    printf("Make F2!\n");

    MakeVillage(&V0);
    SetKepemilikan(&V0, 0);
    Absis(lok(V0)) = 15;
    Ordinat(lok(V0)) = 4;
    printf("Make V0!\n");

    MakeVillage(&V1);
    SetKepemilikan(&V1, 1);
    Absis(lok(V1)) = 2;
    Ordinat(lok(V1)) = 4;
    printf("Make V1!\n");

    MakeVillage(&V2);
    SetKepemilikan(&V2, 2);
    Absis(lok(V2)) = 7;
    Ordinat(lok(V2)) = 6;
    printf("Make V2!\n");

    // membuat array bangunan
    MakeEmpty(&arrBan, 20);
    printf("Array Bangunan initiated\n");
    AddAsLastEl(&arrBan, &C0);
    printf("Added C0\n");
    AddAsLastEl(&arrBan, &C1);
    printf("Added C1\n");
    AddAsLastEl(&arrBan, &C2);
    printf("Added C2\n");
    AddAsLastEl(&arrBan, &T0);
    printf("Added T0\n");
    AddAsLastEl(&arrBan, &T1);
    printf("Added T1\n");
    AddAsLastEl(&arrBan, &T2);
    printf("Added T2\n");
    AddAsLastEl(&arrBan, &F0);
    printf("Added F0\n");
    AddAsLastEl(&arrBan, &F1);
    printf("Added F1\n");
    AddAsLastEl(&arrBan, &F2);
    printf("Added F2\n");
    AddAsLastEl(&arrBan, &V0);
    printf("Added V0\n");
    AddAsLastEl(&arrBan, &V1);
    printf("Added V1\n");
    AddAsLastEl(&arrBan, &V2);
    printf("Added V2\n");

    // mengisi peta
    IsiPeta(&P, arrBan);
    printf("Peta terisi\n");

    // mencetak peta
    DisplayPeta(P);
    return 0;
}