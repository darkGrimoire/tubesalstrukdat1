/* File : driver_point.c */
/* Driver untuk ADT Point */

#include "lib/point.h"
#include <stdio.h>

int main() {
    float x1, x2, y1, y2, dist;
    POINT P1, P2;
    /* Make Point */
    x1 = (float) 3;
    y1 = (float) 4;
    P1 = MakePOINT(x1, y1);
    TulisPOINT(P1);
    printf("\n");
    /* Baca Point */
    BacaPOINT(&P2);
    TulisPOINT(P2);
    printf("\n");
    /* EQPoint */
    if (EQPoint(P1, P2)) {
        printf("Kedua point sama\n");
    }
    else {
        printf("Kedua point tidak sama\n");
    }
    /* NEQPoint */
    if (NEQPoint(P1, P2)) {
        printf("Kedua point tidak sama\n");
    }
    else {
        printf("Kedua point sama\n");
    }
    BacaPOINT(&P2);
    if (IsOrigin(P2)) {
        printf("P2 ada di titik pusat\n");
    }
    else {
        printf("P2 tidak di titik pusat\n");
    }
    if (IsOnSbX(P2)) {
        printf("P2 di sumbu X\n");
    }
    else {
        printf("P2 tidak di sumbu X\n");
    }
    if (IsOnSbY(P2)) {
        printf("P2 di sumbu Y\n");
    }
    else {
        printf("P2 tidak di sumbu Y\n");
    }
    printf("P2 berada di kuadran %d\n", Kuadran(P2));
    P1 = NextX(P2);
    TulisPOINT(P2);
    printf("\n");
    TulisPOINT(P1);
    printf("\n");
    P1 = NextY(P2);
    TulisPOINT(P2);
    printf("\n");
    TulisPOINT(P1);
    printf("\n");
    P1 = PlusDelta(P2, (float) 5, (float) 5);
    TulisPOINT(P2);
    printf("\n");
    TulisPOINT(P1);
    printf("\n");
    P1 = MirrorOf(P2, 1);
    TulisPOINT(P2);
    printf("\n");
    TulisPOINT(P1);
    printf("\n");
    dist = Jarak0(P1);
    printf("Jarak P1 ke titik pusat adalah %.2f\n", dist);
    printf("Jarang antara P1 dan P2 adalah %.2f\n", Panjang(P1, P2));
    Geser(&P2, (float) 1, (float) 1);
    TulisPOINT(P2);
    printf("\n");
    GeserKeSbX(&P2);
    TulisPOINT(P2);
    printf("\n");
    GeserKeSbY(&P2);
    TulisPOINT(P2);
    printf("\n");
    Mirror(&P1, 1);
    TulisPOINT(P1);
    printf("\n");
    Putar(&P1, 90);
    TulisPOINT(P1);
    printf("\n");
    return 0;
}