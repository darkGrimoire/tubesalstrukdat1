#include <stdio.h>
#include "lib/boolean.h"
#include "lib/bangunan.h"
#include "lib/listlinier.h"
#include "lib/point.h"
#include "lib/arraydin.h"

void PrintBangunan(BANGUNAN B){
    printf("\n");
    printf("Jenis bangunan: %c\n", jenis(B));
    printf("Kepemilikan: %d\n", kepemilikan(B));
    printf("Level bangunan: %d\n", level(B));
    printf("Jumlah pasukan: %d\n", pasukan(B));
    printf("Nilai penambahan pasukan: %d\n", tambahpas(B));
    printf("Maksimum penambahan pasukan: %d\n", maks(B));
    printf("Jumlah pasukan awal: %d\n", pasawal(B));
    TulisPOINT(lok(B));
    printf("\n");
    }

TabInt arrBan;
List GLIST[2];
int main(){
    TabInt t1;
    List L1,L2;
    BANGUNAN B, C0, C1, C2, T0, T1, T2, F0, F1, F2, V0, V1, V2;
    POINT P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12;
    address P,Q;

 // Membentuk koordinat lokasi untuk bangunan
    P1 = MakePOINT(1,2);
    P2 = MakePOINT(2,3);
    P3 = MakePOINT(3,4);
    P4 = MakePOINT(4,5);
    P5 = MakePOINT(5,6);
    P6 = MakePOINT(6,7);
    P7 = MakePOINT(7,8);
    P8 = MakePOINT(8,9);
    P9 = MakePOINT(9,10);
    P10 = MakePOINT(10,11);
    P11 = MakePOINT(11,12);
    P12 = MakePOINT(12,13);

    // Mengkonstruksi bangunan untuk tiap pemilik dan tiap jenis
    C0 = SetBangunan(0, 'C', P1);
    C1 = SetBangunan(1, 'C', P2);
    T0 = SetBangunan(0, 'T', P4);
    T1 = SetBangunan(1, 'T', P5);
    F0 = SetBangunan(0, 'F', P7);
    F1 = SetBangunan(1, 'F', P8);
    V0 = SetBangunan(0, 'V', P10);
    V1 = SetBangunan(1, 'V', P11);

    CreateList(&L1);
    CreateList(&L2);
    
    MakeEmpty(&t1,1000);
    
    AddAsLastEl(&t1,&C0);
    AddAsLastEl(&t1,&T0);
    AddAsLastEl(&t1,&V0);
    AddAsLastEl(&t1,&C1);
    AddAsLastEl(&t1,&T1);
    AddAsLastEl(&t1,&V1);
    AddAsLastEl(&t1,&F1);
    AddAsLastEl(&t1,&F0);

    for (int i =1;i<=Neff(t1);i++){
        if (kepemilikan(bangunan(t1,i))==1) InsVLast(&L1,i);
        else InsVLast(&L2,i);
    }
    P = First(L1);
    Q = First(L2);
    printf("List Bangunan Pemain 1 : \n");
    while((P)!=NilL){
        PrintBangunan(bangunan(t1,Info(P)));
        P=Next(P);
    }
    printf("\nList Bangunan Pemain 2 : \n");
    while((Q)!=NilL){
        PrintBangunan(bangunan(t1,Info(Q)));
        Q=Next(Q);
    }
    return 0;
}