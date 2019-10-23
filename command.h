/* ********** PLAYER & COMMANDS DEFINITION ********** */

#ifndef COMMAND_H
#define COMMAND_H

/* include files */
#include "boolean.h"
#include "queue.h"
#include "stackt.h"

/* definitions */
#define maxQueue 1000
#define maxSkillName 5
#define skillUndef "None"

/* types */
typedef char skilltype[maxSkillName];
typedef struct {
    boolean shieldF;
    int shieldCD;
    boolean attackUpF;
    boolean criticalHitF;
    boolean extraTurnF;
    boolean winF;
} FLAGS;


/********** KONSTRUKTOR **********/
/*** Flags ***/
void CreateFlags(FLAGS* F);
/* I.S F sembarang */
/* F.S F terisi dengan default values untuk Type Data FLAGS */
/*** Player ***/
void CreatePlayerQueue(Queue* Q);
/* I.S Q sembarang */
/* F.S Q terisi dengan "UI" */

/********** SELEKTOR **********/
/*** Flags ***/
void SetSFlag(FLAGS* F, boolean B);
/* I.S F terdefinisi */
/* F.S F.shieldF terisi value B */
void SetAUFlag(FLAGS* F, boolean B);
/* I.S F terdefinisi */
/* F.S F.attackUpF terisi value B */
void SetCHFlag(FLAGS* F, boolean B);
/* I.S F terdefinisi */
/* F.S F.criticalHitF terisi value B */
void SetETFlag(FLAGS* F, boolean B);
/* I.S F terdefinisi */
/* F.S F.extraTurnF terisi value B */
void SetWFlag(FLAGS* F, boolean B);
/* I.S F terdefinisi */
/* F.S F.winF terisi value B */
void SetShieldCD(FLAGS* F, int N);
/* I.S F terdefinisi */
/* F.S F.shieldCD terisi value N */
void FlipSFlag(FLAGS* F, boolean B);
/* I.S F terdefinisi */
/* F.S F.shieldF terisi value B */
void FlipAUFlag(FLAGS* F, boolean B);
/* I.S F terdefinisi */
/* F.S F.attackUpF terisi value B */
void FlipCHFlag(FLAGS* F, boolean B);
/* I.S F terdefinisi */
/* F.S F.criticalHitF terisi value B */
void FlipETFlag(FLAGS* F, boolean B);
/* I.S F terdefinisi */
/* F.S F.extraTurnF terisi value B */
void FlipWFlag(FLAGS* F, boolean B);
/* I.S F terdefinisi */
/* F.S F.winF terisi value B */
/*** Player ***/
/* Utk sementara langsung pakai yg dari Queue aja */

/********** GETTER **********/
/*** Flags ***/
boolean GetSFlag(FLAGS* F);
/* Mengambil value dari F.shieldF */
boolean GetAUFlag(FLAGS* F);
/* Mengambil value dari F.attackUpF */
boolean GetCHFlag(FLAGS* F);
/* Mengambil value dari F.criticalHitF */
boolean GetETFlag(FLAGS* F);
/* Mengambil value dari F.extraTurnF */
boolean GetWFlag(FLAGS* F);
/* Mengambil value dari F.winF */
int GetShieldCD(FLAGS* F);
/* Mengambil value dari F.shieldCD */
/*** Player ***/
void GetSkill(Queue* Q, skilltype S);
/* I.S Q terdefinisi, S sembarang */
/* F.S Q masih sama, S terisi dengan skill di queue terdepan */

/********** SKILLS **********/
void InstantUpgrade(BANGUNAN_TYPE B);
/* I.S B terdefinisi */
/* F.S setiap bangunan dalam B naik 1 level */
void InstantReinforcement(BANGUNAN_TYPE B);
/* I.S B terdefinisi */
/* F.S setiap bangunan dalam B mendapatkan tambahan 5 pasukan */
void Barrage(BANGUNAN_TYPE B);
/* I.S B terdefinisi */
/* F.S setiap bangunan dalam B berkurang sebanyak 10 pasukan */
void Shield_ON(BANGUNAN_TYPE B, FLAGS* F);
/* I.S B dan F terdefinisi, shieldCD != 0 */
/* F.S jika Shield belum aktif: aktifkan pertahanan semua bangunan dan atur shieldCD = 2. */
/*     jika Shield sudah aktif: atur shieldCD = 2 */
void Shield_OFF(BANGUNAN_TYPE B, FLAGS* F);
/* I.S B dan F terdefinisi, shieldCD == 0 */
/* F.S Flip shieldF, Matikan pertahanan B kecuali bangunan yang defaultnya sudah ada pertahanan */
void AttackUp(FLAGS* F);
/* I.S F terdefinisi */
/* F.S attackUpF == true */
void CriticalHit(FLAGS* F);
/* I.S F terdefinisi */
/* F.S criticalHitF == true */
void ExtraTurn(FLAGS* F);
/* I.S F terdefinisi */
/* F.S extraTurnF == true */

/********** COMMANDS **********/
void ATTACK(BANGUNAN_TYPE B, FLAGS* F);
/* I.S B dan F terdefinisi */
/* F.S B sesuai perhitungan Attack, F berubah sesuai dengan skill yang sedang aktif */
void LEVEL_UP(BANGUNAN_TYPE B);
/* I.S F terdefinisi */
/* F.S B yang terpilih akan level up jika memenuhi kriteria level up */
void SKILL(FLAGS* F, BANGUNAN_TYPE B);
/* I.S B dan F terdefinisi */
/* F.S Del Skill yang ada di Queue, lalu gunakan skillnya */
void UNDO(Stack* S);
/* MASIH BELOM KEBAYANG ANJAY */
void END_TURN(FLAGS* F);
/* I.S F terdefinisi */
/* F.S Validasi kondisi game, mengubah turn dan shieldCD */
void EXIT();
/* Memanggil System Exit Call */

#endif