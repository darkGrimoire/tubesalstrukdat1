#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "bangunan.h"
#include "point.h"

// /*Selektor */
// #define kepemilikan(B) (B).kepemilikan
// #define pasukan(B) (B).pasukan
// #define level(B) (B).level
// #define tambahpas(B) (B).A
// #define maks(B) (B).M
// #define pasawal(B) (B).U
// #define lok(B) (B).lok
// #define jenis(B) (B).jenis

void MakeBangunan(BANGUNAN *B, int kepemilikan, int pasukan, int a, int m, int u, int level, int X, int Y, char jenis){
    POINT p;
    p = MakePOINT(X,Y);
    lok(*B) = p;
    kepemilikan(*B) = kepemilikan;
    pasukan(*B) = pasukan;
    level(*B)= level;
    tambahpas(*B)= a;
    maks(*B) = m ;
    pasawal(*B) = u;
    jenis(*B) = jenis;
}
BANGUNAN SetBangunan(int kepemilikan, char jenis, point lokasi, boolean flag){
    BANGUNAN B;
    if (flag){
        level(B) = 1;
        kepemilikan(B) = kepemilikan;
        if (jenis == 'C') MakeCastle(&B);
        else if (jenis == 'T') MakeTower(&B);
        else if (jenis == 'F') MakeFort(&B);
        else if (jenis == 'V') MakeVillage(&B);
        lok(B) = lokasi;
        return B;
    }
}
void MakeCastle (BANGUNAN *B, boolean flag){
    if (flag){
    jenis(*B) = 'C'
    SetMaxPasukan(B,jenis(*B));
    pasawal(*B) = 40;
    pasukan(*B) = 40;
    tambahpas(*B)=10;
    }
}
void MakeTower (BANGUNAN *B, boolean flag){
    if (flag){
    jenis(*B) = 'T'
    SetMaxPasukan(B,jenis(*B));
    pasawal(*B) = 30;
    pasukan(*B) = 30;
    tambahpas(*B)=5;
    }
}
void MakeFort (BANGUNAN *B, boolean flag){
    if (flag){
    jenis(*B) = 'C'
    SetMaxPasukan(B,jenis(*B));
    pasawal(*B) = 80;
    pasukan(*B) = 80;
    tambahpas(*B)=10;
    }
}
void MakeVillage (BANGUNAN *B, boolean flag){
    if (flag){
    jenis(*B) = 'C'
    SetMaxPasukan(B,jenis(*B));
    pasawal(*B) = 20;
    pasukan(*B) = 20;
    tambahpas(*B)=5;
    }
}
void SetMaxPasukan (BANGUNAN *B, char jenis, boolean flag){
    if (flag){
    if (jenis(*B) == 'C') maks(*B) = 40+((Level(*B)-1)*20);
    else if (jenis(*B) == 'T') maks(*B) = 20+((Level(*B)-1)*10);
    else if (jenis(*B) == 'F') maks(*B) = 20+((Level(*B)-1)*20);
    else maks(*B) = 20+((Level(*B)-1)*10);}
}
void SetKepemilikan (BANGUNAN *B, int kepemilikan, boolean flag){
    kepemilikan(*B) = kepemilikan;
}
boolean IsKepemilikan (BANGUNAN B, int kepemilikan, boolean flag){
    if (kepemilikan(B) == kepemilikan) return true;
    else return false;
}
void IncreasePasukan(BANGUNAN *B, int pasukan,boolean flag){
    if (flag){
        pasukan(*B)+= pasukan;
    }
}
boolean CanLevelUp(BANGUNAN B){
    return ((level(B)<4)&&(pasukan(B)>=maks(B)));
}

void LevelUp(BANGUNAN *B, boolean flag){
    int q,w,e,r;
    if (flag && CanLevelUp){
        if(jenis(*B)=='C'){
            pasukan(*B) = pasukan(*B) - maks(*B)/2;
            q = tambahpas(*B);
            q+=5;
            tambahpas(*B)+=q;
            pasukan(*B)+=tambahpas(*B);
            level(*B)+=1;
            SetMaxPasukan(B,jenis(*B));
        }
        else if (jenis(*B)=='T'){
            pasukan(*B) = pasukan(*B) - maks(*B)/2;
            w = tambahpas(*B);
            if(level(*B)==1){ 
                w+=5;
                tambahpas(*B)+=w;}
            else {
                w+=10;
                tambahpas(*B)+=w;}
            pasukan(*B)+=tambahpas(*B);
            level(*B)+=1;
            SetMaxPasukan(B,jenis(*B));
        }
        else if (jenis(*B)=='F'){
            pasukan(*B) = pasukan(*B) - maks(*B)/2;
            e = tambahpas(*B);
            e+=10;
            tambahpas(*B)+=e;
            pasukan(*B)+=tambahpas(*B);
            level(*B)+=1;
            SetMaxPasukan(B,jenis(*B));
        }
        else{ //jenis(*B)=='V'
            pasukan(*B) = pasukan(*B) - maks(*B)/2;
            r = tambahpas(*B);
            r+=5;
            tambahpas(*B)+=r;
            pasukan(*B)+=tambahpas(*B);
            level(*B)+=1;
            SetMaxPasukan(B,jenis(*B));
        }
    }
}
boolean IsTherePertahanan (BANGUNAN B){
    if (Jenis(B) == 'F') {
        if (Level(B) >= 3) return true;
        else return false;
    }
    else if (Jenis(B) == 'T') return true;
    else return false;
}
void delPasukan(BANGUNAN *B, boolean flag){
    int selisih;
    if (flag){
        if (pasukan(*B)>maks(*B)){
            selisih = pasukan(*B)-maks(*B);
            pasukan(*B) -=selisih;
        }
    }
}