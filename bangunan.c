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
BANGUNAN SetBangunan(int kepemilikan, char jenis, POINT lokasi){
    BANGUNAN B;
        level(B) = 1;
        kepemilikan(B) = kepemilikan;
        if (jenis == 'C') MakeCastle(&B);
        else if (jenis == 'T') MakeTower(&B);
        else if (jenis == 'F') MakeFort(&B);
        else if (jenis == 'V') MakeVillage(&B);
        lok(B) = lokasi;
        return B;
}
void MakeCastle (BANGUNAN *B){
    jenis(*B) = 'C';
    SetMaxPasukan(B);
    pasawal(*B) = 40;
    pasukan(*B) = 40;
    tambahpas(*B)=10;
}
void MakeTower (BANGUNAN *B){
    jenis(*B) = 'T';
    SetMaxPasukan(B);
    pasawal(*B) = 30;
    pasukan(*B) = 30;
    tambahpas(*B)=5;
}
void MakeFort (BANGUNAN *B){
    jenis(*B) = 'F';
    SetMaxPasukan(B);
    pasawal(*B) = 80;
    pasukan(*B) = 80;
    tambahpas(*B)=10;
}
void MakeVillage (BANGUNAN *B){
    jenis(*B) = 'V';
    SetMaxPasukan(B);
    pasawal(*B) = 20;
    pasukan(*B) = 20;
    tambahpas(*B)=5;
}
void SetMaxPasukan (BANGUNAN *B){
    if (jenis(*B) == 'C') maks(*B) = 40+((level(*B)-1)*20);
    else if (jenis(*B) == 'T') maks(*B) = 20+((level(*B)-1)*10);
    else if (jenis(*B) == 'F') maks(*B) = 20+((level(*B)-1)*20);
    else maks(*B) = 20+((level(*B)-1)*10);
}
void SetKepemilikan (BANGUNAN *B, int kepemilikan){
    kepemilikan(*B) = kepemilikan;
}
boolean IsKepemilikan (BANGUNAN B, int kepemilikan){
    if (kepemilikan(B) == kepemilikan) return true;
    else return false;
}
void IncreasePasukan(BANGUNAN *B, int pasukan){
        pasukan(*B)+= pasukan;
}
boolean CanLevelUp(BANGUNAN B){
    return ((level(B)<4)&&(pasukan(B)>=maks(B)));
}
void LevelUp(BANGUNAN *B){
    int q,w,e,r;
    if (CanLevelUp(*B)){
        if(jenis(*B)=='C'){
            pasukan(*B) = pasukan(*B) - maks(*B)/2;
            q = tambahpas(*B);
            q+=5;
            tambahpas(*B)+=q;
            level(*B)+=1;
            SetMaxPasukan(B);
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
            level(*B)+=1;
            SetMaxPasukan(B);
        }
        else if (jenis(*B)=='F'){
            pasukan(*B) = pasukan(*B) - maks(*B)/2;
            e = tambahpas(*B);
            e+=10;
            tambahpas(*B)+=e;
            level(*B)+=1;
            SetMaxPasukan(B);
        }
        else{ //jenis(*B)=='V'
            pasukan(*B) = pasukan(*B) - maks(*B)/2;
            r = tambahpas(*B);
            r+=5;
            tambahpas(*B)+=r;
            level(*B)+=1;
            SetMaxPasukan(B);
        }
    }
}
boolean IsTherePertahanan (BANGUNAN B){
    if (jenis(B) == 'F') {
        if (level(B) >= 3) return true;
        else return false;
    }
    else if (jenis(B) == 'T') return true;
    else return false;
}
boolean validTambahA(BANGUNAN B){
    if (pasukan(B)>=maks(B)) return false;
    else return true;
}

void DecreasePasukan(BANGUNAN *B, int kurang){
    int jumlah;
    jumlah = pasukan(*B)-kurang;
    if (jumlah>0) pasukan(*B)=jumlah;
    else pasukan(*B)=0;
}

void setpasukan(BANGUNAN *B,int pasukan){
    if (pasukan<maks(*B)){
        pasukan(*B) = pasukan;
    }
    else printf("jumlah pasukan terlalu besar");
}

void resetlevel(BANGUNAN *B){
    level(*B)=1;
    if (jenis(*B) == 'C') MakeCastle(*&B);
    else if (jenis(*B) == 'T') MakeTower(*&B);
    else if (jenis(*B) == 'F') MakeFort(*&B);
    else if (jenis(*B) == 'V') MakeVillage(*&B);
}

void tambahpasukanauto(BANGUNAN *B){
    int temp;
    if (validTambahA(*B)){
        pasukan(*B)+=tambahpas(*B);
        if (pasukan(*B)>maks(*B)){
            temp = pasukan(*B)-maks(*B);
            pasukan(*B) -=temp;
        }
    }
}