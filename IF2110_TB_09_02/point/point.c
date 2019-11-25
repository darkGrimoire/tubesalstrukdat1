#include "../point/point.h"
#include <math.h>
#include <stdio.h>
#include "../boolean.h"
#define PI 3.14159265359

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y)
/* Membentuk sebuah POINT dari komponen-komponennya */
{POINT P;
    Absis(P) = X;
    Ordinat(P) = Y;
    return P;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT (POINT * P)
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
{
    float X,Y;
    scanf("%f %f", &X, &Y);
    *P = MakePOINT(X,Y);
}


void TulisPOINT (POINT P)
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */

/* *** Kelompok operasi relasional terhadap POINT *** */
{   printf("(%.2f,%.2f)", Absis(P),Ordinat(P) );


}
boolean EQPoint (POINT P1, POINT P2)
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
{if ( (Absis(P1)==Absis(P2)) && (Ordinat(P1)==Ordinat(P2)) ){
    return true;
}
else {
    return false;
} 
}


boolean NEQPoint (POINT P1, POINT P2)
/* Mengirimkan true jika P1 tidak sama dengan P2 */
{
if (EQPoint(P1,P2) == true){
    return false;
}
else
{
    return true;
}
}
/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P)
/* Menghasilkan true jika P adalah titik origin */
{if ( (Absis(P) == 0) && (Ordinat(P) == 0) )
    {
        return true;
    }
    else{
        return false;
    }
}
boolean IsOnSbX (POINT P)
/* Menghasilkan true jika P terletak Pada sumbu X */
{
    return (Ordinat(P)==0);
}
boolean IsOnSbY (POINT P)
/* Menghasilkan true jika P terletak pada sumbu Y */
{
    return (Absis(P)==0);
}
int Kuadran (POINT P)
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
{if ((IsOrigin(P) == false) && (IsOnSbX(P) == false) && (IsOnSbY(P) == false)){
    if (Absis(P) > 0)
            {
                if (Ordinat(P) > 0){
                    return 1;
                }
                else{
                    return 4;
                }
            }
            else 
            {
                if (Ordinat(P) > 0){
                    return 2;
                }
                else{
                    return 3;
                }
            }   

}
else
{
    return 0;
}

}
