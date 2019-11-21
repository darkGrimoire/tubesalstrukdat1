/* include files */
#include "boolean.h"
#include "queue.h"
#include "stackt.h"
#include "mesinkata.h"
#include "bangunan.h"
#include "lib\command.h"

/********** KONSTRUKTOR **********/
/*** Flags ***/
void CreateFlag(FLAGS* F){
/* I.S F sembarang */
/* F.S F terisi dengan default values untuk Type Data FLAGS */
    /* KAMUS */
    /* ALGORITMA */
    (*F).shieldF = false;
    (*F).shieldCD = 0;
    (*F).attackUpF = false;
    (*F).criticalHitF = false;
    (*F).extraTurnF = false;
    (*F).winF = false;
}

void SetFlag(FLAGS* F, boolean SF, int CD, boolean AU, boolean CH, boolean ET, boolean WF)
/* I.S F sembarang */
/* F.S F terisi dengan values dari parameter */
{
    /* KAMUS */
    /* ALGORITMA */
    (*F).shieldF = SF;
    (*F).shieldCD = CD;
    (*F).attackUpF = AU;
    (*F).criticalHitF = CH;
    (*F).extraTurnF = ET;
    (*F).winF = WF;
}

/*** Player ***/
void CreatePlayerQueue(Queue* Q){
/* I.S Q sembarang */
/* F.S Q terisi dengan "UI" */
    /* KAMUS */
    /* ALGORITMA */
    CreateEmptyQ(Q,10);
    AddQ(Q,1);
}

/********** SELEKTOR **********/
/*** Flags ***/
void SetSFlag(FLAGS* F, boolean B){
/* I.S F terdefinisi */
/* F.S F.shieldF terisi value B */
    /* KAMUS */
    /* ALGORITMA */
    (*F).shieldF = B;
}

void SetAUFlag(FLAGS* F, boolean B)
/* I.S F terdefinisi */
/* F.S F.attackUpF terisi value B */
{
    /* KAMUS */
    /* ALGORITMA */
    (*F).attackUpF = B;
}
void SetCHFlag(FLAGS* F, boolean B)
/* I.S F terdefinisi */
/* F.S F.criticalHitF terisi value B */
{
    /* KAMUS */
    /* ALGORITMA */
    (*F).criticalHitF = B;
}
void SetETFlag(FLAGS* F, boolean B)
/* I.S F terdefinisi */
/* F.S F.extraTurnF terisi value B */
{
    /* KAMUS */
    /* ALGORITMA */
    (*F).extraTurnF = B;
}
void SetWFlag(FLAGS* F, boolean B)
/* I.S F terdefinisi */
/* F.S F.winF terisi value B */
{
    /* KAMUS */
    /* ALGORITMA */
    (*F).winF = B;
}
void SetShieldCD(FLAGS* F, int N)
/* I.S F terdefinisi */
/* F.S F.shieldCD terisi value N */
{
    /* KAMUS */
    /* ALGORITMA */
    (*F).shieldCD = N;
}
void FlipSFlag(FLAGS* F)
/* I.S F terdefinisi */
/* F.S F.shieldF terisi value B */
{
    /* KAMUS */
    /* ALGORITMA */
    (*F).shieldF = !(*F).shieldF;
}
void FlipAUFlag(FLAGS* F)
/* I.S F terdefinisi */
/* F.S F.attackUpF terisi value B */
{
    /* KAMUS */
    /* ALGORITMA */
    (*F).attackUpF = !(*F).attackUpF;
}
void FlipCHFlag(FLAGS* F)
/* I.S F terdefinisi */
/* F.S F.criticalHitF terisi value B */
{
    /* KAMUS */
    /* ALGORITMA */
    (*F).criticalHitF = !(*F).criticalHitF;
}
void FlipETFlag(FLAGS* F)
/* I.S F terdefinisi */
/* F.S F.extraTurnF terisi value B */
{
    /* KAMUS */
    /* ALGORITMA */
    (*F).extraTurnF = !(*F).extraTurnF;
}
void FlipWFlag(FLAGS* F)
/* I.S F terdefinisi */
/* F.S F.winF terisi value B */
{
    /* KAMUS */
    /* ALGORITMA */
    (*F).shieldF = !(*F).shieldF ;
}
/*** Player ***/
/* Utk sementara langsung pakai yg dari Queue aja */

/********** GETTER **********/
/*** Flags ***/
boolean GetSFlag(FLAGS F)
/* Mengambil value dari F.shieldF */
{
    /* KAMUS */
    /* ALGORITMA */
    return F.shieldF;
}
boolean GetAUFlag(FLAGS F)
/* Mengambil value dari F.attackUpF */
{
    /* KAMUS */
    /* ALGORITMA */
    return F.attackUpF;
}
boolean GetCHFlag(FLAGS F)
/* Mengambil value dari F.criticalHitF */
{
    /* KAMUS */
    /* ALGORITMA */
    return F.criticalHitF;
}
boolean GetETFlag(FLAGS F)
/* Mengambil value dari F.extraTurnF */
{
    /* KAMUS */
    /* ALGORITMA */
    return F.extraTurnF;
}
boolean GetWFlag(FLAGS F)
/* Mengambil value dari F.winF */
{
    /* KAMUS */
    /* ALGORITMA */
    return F.winF;
}
int GetShieldCD(FLAGS F)
/* Mengambil value dari F.shieldCD */
{
    /* KAMUS */
    /* ALGORITMA */
    return F.winF;
}
/*** Player ***/
void GetSkill(Queue Q, Kata* S)
/* I.S Q terdefinisi, S sembarang */
/* F.S Q masih sama, S terisi dengan skill di queue terdepan */
{
    /* KAMUS */
    int N;
    /* ALGORITMA */
    N = InfoHead(Q);
    IntToSkill(N,S);
}

void IntToSkilltype(int N, Kata* S)
/* I.S N terdefinisi, S sembarang */
/* F.S N di convert menjadi char skilltype S */
{
    /* KAMUS */
    /* ALGORITMA */
    switch(N){
        case 1:
            (*S).TabKata[0] = "I"; (*S).TabKata[1] = "U"; (*S).Length = 2;
            break;
        case 2:
            (*S).TabKata[0] = "S"; (*S).Length = 1;
            break;
        case 3:
            (*S).TabKata[0] = "E"; (*S).TabKata[1] = "T"; (*S).Length = 2;
            break;
        case 4:
            (*S).TabKata[0] = "A"; (*S).TabKata[1] = "U"; (*S).Length = 2;
            break;
        case 5:
            (*S).TabKata[0] = "C"; (*S).TabKata[1] = "H"; (*S).Length = 2;
            break;
        case 6:
            (*S).TabKata[0] = "I"; (*S).TabKata[1] = "R"; (*S).Length = 2;
            break;
        case 7:
            (*S).TabKata[0] = "B"; (*S).Length = 1;
            break;
    }
}
/********** SKILLS **********/
void InstantUpgrade(int playerID, LISTBANGUNAN B)
/* I.S B terdefinisi */
/* F.S setiap LISTBANGUNAN dalam B naik 1 level */
{
    /* KAMUS */
    /* ALGORITMA */
    
}
void InstantReinforcement(LISTBANGUNAN B)
/* I.S B terdefinisi */
/* F.S setiap LISTBANGUNAN dalam B mendapatkan tambahan 5 pasukan */
{
    /* KAMUS */
    /* ALGORITMA */
}
void Barrage(LISTBANGUNAN B)
/* I.S B terdefinisi */
/* F.S setiap LISTBANGUNAN dalam B berkurang sebanyak 10 pasukan */
{
    /* KAMUS */
    /* ALGORITMA */
}
void Shield_ON(LISTBANGUNAN B, FLAGS* F)
/* I.S B dan F terdefinisi, shieldCD != 0 */
/* F.S jika Shield belum aktif: aktifkan pertahanan semua LISTBANGUNAN dan atur shieldCD = 2. */
/*     jika Shield sudah aktif: atur shieldCD = 2 */
{
    /* KAMUS */
    /* ALGORITMA */
}
void Shield_OFF(LISTBANGUNAN B, FLAGS* F)
/* I.S B dan F terdefinisi, shieldCD == 0 */
/* F.S Flip shieldF, Matikan pertahanan B kecuali LISTBANGUNAN yang defaultnya sudah ada pertahanan */
{
    /* KAMUS */
    /* ALGORITMA */
}
void AttackUp(FLAGS* F)
/* I.S F terdefinisi */
/* F.S attackUpF == true */
{
    /* KAMUS */
    /* ALGORITMA */
}
void CriticalHit(FLAGS* F)
/* I.S F terdefinisi */
/* F.S criticalHitF == true */
{
    /* KAMUS */
    /* ALGORITMA */
}
void ExtraTurn(FLAGS* F)
/* I.S F terdefinisi */
/* F.S extraTurnF == true */
{
    /* KAMUS */
    /* ALGORITMA */
}

/********** COMMANDS **********/
void ATTACK(LISTBANGUNAN B, FLAGS* F)
/* I.S B dan F terdefinisi */
/* F.S B sesuai perhitungan Attack, F berubah sesuai dengan skill yang sedang aktif */
{
    /* KAMUS */
    /* ALGORITMA */
}
void LEVEL_UP(LISTBANGUNAN B)
/* I.S F terdefinisi */
/* F.S B yang terpilih akan level up jika memenuhi kriteria level up */
{
    /* KAMUS */
    /* ALGORITMA */
}
void SKILL(FLAGS* F, LISTBANGUNAN B)
/* I.S B dan F terdefinisi */
/* F.S Del Skill yang ada di Queue, lalu gunakan skillnya */
{
    /* KAMUS */
    /* ALGORITMA */
}
void UNDO(Stack* S)
/* MASIH BELOM KEBAYANG ANJAY */
{
    /* KAMUS */
    /* ALGORITMA */
}
void END_TURN(FLAGS* F)
/* I.S F terdefinisi */
/* F.S Validasi kondisi game, mengubah turn dan shieldCD */
{
    /* KAMUS */
    /* ALGORITMA */
}
void EXIT()
/* Memanggil System Exit Call */
{
    /* KAMUS */
    /* ALGORITMA */
}