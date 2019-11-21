#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "bangunan.h"

void MakeBangunan(BANGUNAN *B, int kepemilikan, int pasukan, int level, POINT lok, char jenis){

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
    pasukan = 40;}
}
void MakeTower (BANGUNAN *B, boolean flag){
    if (flag){
    jenis(*B) = 'T'
    SetMaxPasukan(B,jenis(*B));
    pasawal(*B) = 30;
    pasukan = 30;}
}
void MakeFort (BANGUNAN *B, boolean flag){
    if (flag){
    jenis(*B) = 'C'
    SetMaxPasukan(B,jenis(*B));
    pasawal(*B) = 80;
    pasukan = 80;}
}
void MakeVillage (BANGUNAN *B, boolean flag){
    if (flag){
    jenis(*B) = 'C'
    SetMaxPasukan(B,jenis(*B));
    pasawal(*B) = 20;
    pasukan = 20;}
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
void IncreasePasukan(BANGUNAN *B, char jenis, int pasukan){


}
void LevelUp(BANGUNAN *B){

}
boolean IsTherePertahanan (BANGUNAN B){
    
}