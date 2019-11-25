// Driver ADT Matriks

#include "../boolean.h"
#include "../matriks/matriks.h"

int main(){
    // KAMUS
    MATRIKS M1, M2, M3;

    // ALGORITMA
    MakeMATRIKS(10,10,&M1);
    printf("Terbentuk matriks 1 dengan baris %d dan kolom %d\n", NBrsEff(M1), NKolEff(M1));
    MakeMATRIKS(10,10,&M2);
    printf("Terbentuk matriks 2 dengan baris %d dan kolom %d\n", NBrsEff(M2), NKolEff(M2));
    MakeMATRIKS(5,3,&M3);
    printf("Terbentuk matriks 3 dengan baris %d dan kolom %d\n", NBrsEff(M3), NKolEff(M3));

    printf("Masukkan elemen matriks 1:\n");
    BacaMATRIKS(&M1, 10,10);
    printf("Terbaca komputer:\n");
    TulisMATRIKS(M1);
    printf("\n");

    printf("Masukkan elemen matriks 2:\n");
    BacaMATRIKS(&M2, 10,10);
    printf("Terbaca komputer:\n");
    TulisMATRIKS(M2);
    printf("\n");

    printf("Masukkan elemen matriks 3:\n");
    BacaMATRIKS(&M3, 5,3);
    printf("Terbaca komputer:\n");
    TulisMATRIKS(M3);
    printf("\n");

    if (EQMatriks(M1,M2))
    {
        printf("M1 dan M2 sama\n");
    }
    else
    {
        printf("M1 dan M2 tidak sama\n");
    }
    
    if (NEQMatriks(M1,M3))
    {
        printf("M1 dan M3 tidak sama\n");
    }
    else
    {
        printf("Harusnya M1 dan M3 tidak sama\n");
    }
    
    if (EQSizeMatriks(M1,M2))
    {
        printf("M1 dan M2 memiliki ukuran yang sama\n");
    }
    
    if (!IsBujurSangkar(M3))
    {
        printf("M3 bukan bujur sangkar\n");
    }
    
    if (!IsSimetri(M3))
    {
        printf("M3 tidak simetri\n");
    }
    
    if (IsMatriksValid(M1))
    {
        printf("Matriks M1 valid\n");
    }
    Transpose(&M2);
    printf("M2 sudah di transpose\n");
    TulisMATRIKS(M2);
    return 0;
}