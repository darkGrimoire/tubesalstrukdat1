
#include "../boolean.h"
#include "../bangunan/bangunan.h"
#include "../point/point.h"
#include <stdio.h>
#include "../arraydin/arraydin.h"
#include "../listlinier/listlinier.h"
TabInt arrBan;
List GLIST[2];

void PrintBangunan(BANGUNAN B){
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

int main(){
    TabInt t1,t2;
    int maxel;
    BANGUNAN B, C0, C1, C2, T0, T1, T2, F0, F1, F2, V0, V1, V2;
    POINT P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12;

    // ALGORITMA
    
    // Sembarang Bangunan
    MakeBangunan(&B, 1, 30, 10, 20, 15, 1, 3, 8, 'S');
    printf("Terbentuk sembarang bangunan B!\n");
    PrintBangunan(B);

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
    printf("Terbentuk Castle 0!\n");
    PrintBangunan(C0);
    printf("\n");

    C1 = SetBangunan(1, 'C', P2);
    printf("Terbentuk Castle 1!\n");
    PrintBangunan(C1);
    printf("\n");

    C2 = SetBangunan(2, 'C', P3);
    printf("Terbentuk Castle 2!\n");
    PrintBangunan(C2);
    printf("\n");

    T0 = SetBangunan(0, 'T', P4);
    printf("Terbentuk Tower 0!\n");
    PrintBangunan(T0);
    printf("\n");

    T1 = SetBangunan(1, 'T', P5);
    printf("Terbentuk Tower 1!\n");
    PrintBangunan(T1);
    printf("\n");

    T2 = SetBangunan(2, 'T', P6);
    printf("Terbentuk Tower 2!\n");
    PrintBangunan(T2);
    printf("\n");

    F0 = SetBangunan(0, 'F', P7);
    printf("Terbentuk Fort 0!\n");
    PrintBangunan(F0);
    printf("\n");

    F1 = SetBangunan(1, 'F', P8);
    printf("Terbentuk Fort 1!\n");
    PrintBangunan(F1);
    printf("\n");

    F2 = SetBangunan(2, 'F', P9);
    printf("Terbentuk Fort 2!\n");
    PrintBangunan(F2);
    printf("\n");

    V0 = SetBangunan(0, 'V', P10);
    printf("Terbentuk Village 0!\n");
    PrintBangunan(V0);
    printf("\n");

    V1 = SetBangunan(1, 'V', P11);
    printf("Terbentuk Village 1!\n");
    PrintBangunan(V1);
    printf("\n");

    V2 = SetBangunan(2, 'V', P12);
    printf("Terbentuk Village 2!\n");
    PrintBangunan(V2);
    printf("\n");

    scanf ("maxel %d", &maxel);
    MakeEmpty(&t1,maxel);
    MakeEmpty(&t2,maxel);
    AddAsLastEl(&t1,&C0);
    AddAsLastEl(&t1,&T0);
    AddAsLastEl(&t1,&V0);
    AddAsLastEl(&t1,&C1);
    AddAsLastEl(&t1,&T1);
    AddAsLastEl(&t1,&V1);
    AddAsLastEl(&t1,&C2);
    AddAsLastEl(&t1,&T2);
    AddAsLastEl(&t1,&V2);

    CopyTab(t1,&t2);
    printf("tab pertama\n");
    for (int i=GetFirstIdx(t1); i<=Neff(t1); i++){
        PrintBangunan(bangunan(t1,i));
        printf("\n bangunan ke-%d \n",i);
    }
    printf("tab kedua\n");
    for (int j=GetFirstIdx(t2); j<=Neff(t2); j++){
        PrintBangunan(bangunan(t2,j));
        printf("\n bangunan ke-%d \n",j);
    }
    
    return 0;
}