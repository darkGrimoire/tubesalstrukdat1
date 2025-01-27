/* include files */
#include "../boolean.h"
#include "../queue/queue.h"
#include "../stackt/stackt.h"
#include "../bangunan/bangunan.h"
#include "../listlinier/listlinier.h"
#include "../command/command.h"
#include <stdlib.h>

Queue GQUEUE[2];

/********** KONSTRUKTOR **********/
/*** Flags ***/
void CreateFlag(FLAGS* F){
/* I.S F sembarang */
/* F.S F terisi dengan default values untuk Type Data FLAGS */
    /* KAMUS */
    /* ALGORITMA */
    (*F).shieldF = false;
    (*F).shieldCD = -1;
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
void CreatePlayerQueue(Queue* Q, int Max){
/* I.S Q sembarang */
/* F.S Q terisi dengan "UI" */
    /* KAMUS */
    /* ALGORITMA */
    CreateEmptyQ(Q,Max);
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
    return F.shieldCD;
}
/*** Player ***/
// void GetSkill(Queue Q, Kata* S)
// /* I.S Q terdefinisi, S sembarang */
// /* F.S Q masih sama, S terisi dengan skill di queue terdepan */
// {
//     // /* KAMUS */
//     // int N;
//     // /* ALGORITMA */
//     // N = InfoHead(Q);
//     // IntToSkill(N,S);
// }

// void IntToSkilltype(int N, Kata* S)
// /* I.S N terdefinisi, S sembarang */
// /* F.S N di convert menjadi char skilltype S */
// {
//     /* KAMUS */
//     /* ALGORITMA */
//     // switch(N){
//     //     case 1:
//     //         (*S).TabKata[0] = "I"; (*S).TabKata[1] = "U"; (*S).Length = 2;
//     //         break;
//     //     case 2:
//     //         (*S).TabKata[0] = "S"; (*S).Length = 1;
//     //         break;
//     //     case 3:
//     //         (*S).TabKata[0] = "E"; (*S).TabKata[1] = "T"; (*S).Length = 2;
//     //         break;
//     //     case 4:
//     //         (*S).TabKata[0] = "A"; (*S).TabKata[1] = "U"; (*S).Length = 2;
//     //         break;
//     //     case 5:
//     //         (*S).TabKata[0] = "C"; (*S).TabKata[1] = "H"; (*S).Length = 2;
//     //         break;
//     //     case 6:
//     //         (*S).TabKata[0] = "I"; (*S).TabKata[1] = "R"; (*S).Length = 2;
//     //         break;
//     //     case 7:
//     //         (*S).TabKata[0] = "B"; (*S).Length = 1;
//     //         break;
//     // }
// }
/********** SKILLS **********/
void InstantUpgrade(int curP)
/* I.S B terdefinisi */
/* F.S setiap LISTBANGUNAN dalam B naik 1 level */
{
    /* KAMUS */
    address P;

    /* ALGORITMA */
    P = First(GLIST[curP-1]);
    while (P != NilL){
        int pas = pasukan(bangunan(arrBan, Info(P)));
        LevelUp(&(bangunan(arrBan, Info(P))));
        setpasukan(&bangunan(arrBan, Info(P)), pas);
        P = Next(P);
    }
}
void InstantReinforcement(int curP)
/* I.S B terdefinisi */
/* F.S setiap LISTBANGUNAN dalam B mendapatkan tambahan 5 pasukan */
{
    /* KAMUS */
    address P;

    /* ALGORITMA */
    P = First(GLIST[curP-1]);
    while (P != NilL){
        IncreasePasukan(&(bangunan(arrBan, Info(P))), 5);
        P = Next(P);
    }
}
void Barrage(int curP)
/* I.S B terdefinisi */
/* F.S setiap LISTBANGUNAN dalam B berkurang sebanyak 10 pasukan */
{
    /* KAMUS */
    address P;

    /* ALGORITMA */
    int enemyP = (curP == 1) ? 2 : 1;
    P = First(GLIST[enemyP-1]);
    while (P != NilL){
        DecreasePasukan(&(bangunan(arrBan, Info(P))), 10);
        P = Next(P);
    }
}

void Shield_ON(FLAGS* F)
/* I.S B dan F terdefinisi, shieldCD != 0 */
/* F.S jika Shield belum aktif: aktifkan pertahanan semua LISTBANGUNAN dan atur shieldCD = 2. */
/*     jika Shield sudah aktif: atur shieldCD = 2 */
{
    /* KAMUS */
    /* ALGORITMA */
    if (GetSFlag(*F)){
        SetShieldCD(F, 2);
    }else{
        SetSFlag(F, true); printf("abc");
        SetShieldCD(F, 2);
    }
}
void Shield_OFF(FLAGS* F)
/* I.S B dan F terdefinisi, shieldCD == 0 */
/* F.S Flip shieldF, Matikan pertahanan B kecuali LISTBANGUNAN yang defaultnya sudah ada pertahanan */
{
    /* KAMUS */
    /* ALGORITMA */
    SetSFlag(F, false);
    SetShieldCD(F, -1);
}
void AttackUp(FLAGS* F)
/* I.S F terdefinisi */
/* F.S attackUpF == true */
{
    /* KAMUS */
    /* ALGORITMA */
    SetAUFlag(F, true);
}
void CriticalHit(FLAGS* F)
/* I.S F terdefinisi */
/* F.S criticalHitF == true */
{
    /* KAMUS */
    /* ALGORITMA */
    SetCHFlag(F, true);
}
void ExtraTurn(FLAGS* F)
/* I.S F terdefinisi */
/* F.S extraTurnF == true */
{
    /* KAMUS */
    /* ALGORITMA */
    SetETFlag(F, true);
}

/********** SKILL GENERATOR **********/
void GenerateS(int curP)
// Prekondisi: abis ATTACK berhasil
{
    /* KAMUS */
    boolean condPass;
    address P;
    int enemyP;
    /* ALGORITMA */
    enemyP = (curP == 1) ? 2 : 1;
    // Validasi
    if (!IsFullQ(GQUEUE[enemyP-1])){
        condPass = NbElmtList(GLIST[enemyP-1])==2;
        if (condPass) {AddQ(&GQUEUE[enemyP-1], 2);}; 
    }
}
void GenerateET(int curP)
// Prekondisi: berhasil rebut Fort enemyP
{
    /* KAMUS */
    boolean condPass;
    int enemyP;
    /* ALGORITMA */
    enemyP = (curP == 1) ? 2 : 1;
    // Validasi
    if (!IsFullQ(GQUEUE[enemyP-1])){
        condPass = true;
        if (condPass) {AddQ(&GQUEUE[enemyP-1], 3);}; 
    }
}
void GenerateAU(int curP)
// Prekondisi: baru saja menyerang tower
{
    /* KAMUS */
    boolean condPass;
    address P;
    int enemyP, count;
    /* ALGORITMA */
    enemyP = (curP == 1) ? 2 : 1;
    // Validasi
    if (!IsFullQ(GQUEUE[curP-1])){
        count = 0;
        P = First(GLIST[enemyP-1]);
        while (P!=NilL){
            if (jenis(bangunan(arrBan, Info(P))) == 'T'){
                count++;
            }
            P = Next(P);
        }
        condPass = count==3;
        if (condPass) {AddQ(&GQUEUE[curP-1], 4);}; 
    }
}
void GenerateCH(int curP)
// Prekondisi: abis ExtraTurn
{
    /* KAMUS */
    boolean condPass;
    address P;
    int enemyP;
    /* ALGORITMA */
    enemyP = (curP == 1) ? 2 : 1;
    // Validasi
    if (!IsFullQ(GQUEUE[enemyP-1])){
        condPass = GetCHFlag(GFLAGS[curP-1]);
        if (condPass) {AddQ(&GQUEUE[enemyP-1], 5);}; 
    }
}
void GenerateIR(int curP)
// Prekondisi: END_TURN
{
    /* KAMUS */
    boolean condPass;
    address P;
    /* ALGORITMA */
    // Validasi
    if (!IsFullQ(GQUEUE[curP-1])){
        condPass = true;
        P = First(GLIST[curP-1]);
        while (P!=NilL && condPass){
            if (level(bangunan(arrBan, Info(P))) < 4){
                condPass = false;
            }
            P = Next(P);
        }
        if (condPass) {AddQ(&GQUEUE[curP-1], 6);}; 
    }
}
void GenerateB(int curP)
// Prekondisi: Abis ATTACK.
{
    /* KAMUS */
    boolean condPass;
    address P;
    int enemyP;
    /* ALGORITMA */
    enemyP = (curP == 1) ? 2 : 1;
    // Validasi
    if (!IsFullQ(GQUEUE[enemyP-1])){
        condPass = NbElmtList(GLIST[curP-1])==10;
        if (condPass) {AddQ(&GQUEUE[enemyP-1], 7);}; 
    }
}

/********** COMMANDS **********/

void ATTACK(List L, int targetBchoice, int myBchoice, int myPas, int curP)
/* I.S B dan F terdefinisi */
/* F.S B sesuai perhitungan Attack, F berubah sesuai dengan skill yang sedang aktif */
{
    /* KAMUS */
    // P1 is the attacker, P2 is the target
    int targetPas, calcPas, checkPas, restPas, P1, P2, targetBint, myBint;
    BANGUNAN targetB, myB;
    address P;
    infolist X;
    boolean isGenerateS;
    /* ALGORITMA */
    /* PREPARATION */
    // Checks who's the attacker and the target
    P1 = curP;
    P2 = (curP == 1) ? 2 : 1; //Asumsi P2/target adalah Player
    isGenerateS = NbElmtList(GLIST[P2-1])==3;
    P = First(L);
    while (targetBchoice>1){P = Next(P); targetBchoice--;}
    targetBint = Info(P);
    if (SearchList(GLIST[P2-1],Info(P))==NilL){
        P2 = 0; //Target bukanlah Player
    }
    // Prepare targetPas and targetB
    targetB = bangunan(arrBan, Info(P));
    if (P2==0){
        targetPas = pasawal(targetB);
    }else{
        targetPas = pasukan(targetB);
    }
    // Prepare myB
    P = First(GLIST[P1-1]);
    while (myBchoice>1){P = Next(P); myBchoice--;}
    myBint = Info(P);
    myB = bangunan(arrBan, Info(P));
    /* MEKANISME ATTACK */
    // checkPas = cuman berbeda dgn myPas di criticalhit
    // calcPas = jumlah pasukan yg di decrease di musuh
    // restPas = myPas - targetPas
    // DEFAULT:
    checkPas = myPas; 
    calcPas = checkPas;
    restPas = calcPas-targetPas;
    
    // attacker punya attackup/criticalhit, shield/pertahanan diabaikan
    if (GetCHFlag(GFLAGS[P1-1])){
        checkPas = myPas*2;
        calcPas = checkPas;
        restPas = (calcPas-targetPas)/2;
        SetCHFlag(&GFLAGS[P1-1],false);
    }else if (GetAUFlag(GFLAGS[P1-1])){
        // checkPas = myPas;
        // calcPas = checkPas;
        // restPas = calcPas-targetPas;
    }
    // Mekanisme bangunan memiliki defense atau shield musuh on
    else if (IsTherePertahanan(targetB) || GetSFlag(GFLAGS[P2-1])){
        checkPas = (3*checkPas)/4;
        calcPas = checkPas;
        restPas = calcPas-targetPas;
    }
    // Mekanisme ordinary attack 
    if (checkPas < targetPas){
        if (P2!=0){
            DecreasePasukan(&bangunan(arrBan, targetBint), calcPas);
            DecreasePasukan(&bangunan(arrBan, myBint), myPas);
        }
        printf("Bangunan gagal direbut.\n");
    } else if (checkPas >= targetPas){
        // SetKepemilikan(&bangunan(arrBan, targetBint),P1);
        kepemilikan(bangunan(arrBan, targetBint)) = P1;
        // setpasukan(&bangunan(arrBan, targetBint), restPas);
        resetlevel(&bangunan(arrBan, targetBint));
        pasukan(bangunan(arrBan, targetBint)) = restPas;
        // DecreasePasukan(&bangunan(arrBan, myBint),myPas);
        pasukan(bangunan(arrBan, myBint)) -= myPas;
        if (P2 != 0){DelP(&GLIST[P2-1], targetBint);}
        InsVLast(&GLIST[P1-1], targetBint);
        printf("Bangunan menjadi milikmu!\n");
        // Skill Generator: S, ET
        if (isGenerateS){GenerateS(curP);}
        if (jenis(targetB) == 'F' && P2 != 0){
            GenerateET(curP);
        }
    }
    // Skill Generator: B, AU
    GenerateB(curP);
    if (jenis(targetB) == 'T' && P2!=0){
        GenerateAU(curP);
    }
    // Update Stack for Undo
    UpdateSTACK();
}
void LEVEL_UP(int choice, int curP)
/* I.S F terdefinisi */
/* F.S B yang terpilih akan level up jika memenuhi kriteria level up */
{
    /* KAMUS */
    address P;
    List L;
    /* ALGORITMA */
    CreateList(&L);
    P = First(GLIST[curP-1]);
    while (choice>1){P = Next(P); choice--;}
    if (CanLevelUp(bangunan(arrBan, Info(P)))){
        LevelUp(&bangunan(arrBan, Info(P)));
        printf("Level ");
        if (jenis(bangunan(arrBan, Info(P)))=='C'){printf("Castle");}
        else if (jenis(bangunan(arrBan, Info(P)))=='T'){printf("Tower");}
        else if (jenis(bangunan(arrBan, Info(P)))=='F'){printf("Fort");}
        else if (jenis(bangunan(arrBan, Info(P)))=='V'){printf("Village");}
        printf("-mu meningkat menjadi %d!\n",level(bangunan(arrBan, Info(P))));
        // Update Stack for Undo
        UpdateSTACK();
    }else{
        printf("Bangunan ");
        if (jenis(bangunan(arrBan, Info(P)))=='C'){printf("Castle");}
        else if (jenis(bangunan(arrBan, Info(P)))=='T'){printf("Tower");}
        else if (jenis(bangunan(arrBan, Info(P)))=='F'){printf("Fort");}
        else if (jenis(bangunan(arrBan, Info(P)))=='V'){printf("Village");}
        printf(" tidak dapat di level up!\n");
    }
}
void SKILL(FLAGS* F, Queue* Q, int curP)
/* I.S B dan F terdefinisi */
/* F.S Del Skill yang ada di Queue, lalu gunakan skillnya */
{
    /* KAMUS */
    infotype X;
    /* ALGORITMA */
    DelQ(Q,&X);
    switch(X){
        case 1:
            InstantUpgrade(curP);
            break;
        case 2:
            Shield_ON(F);
            break;
        case 3:
            ExtraTurn(F);
            // Skill Generator: CH
            GenerateCH(curP);
            break;
        case 4:
            AttackUp(F);
            break;
        case 5:
            CriticalHit(F);
            break;
        case 6:
            InstantReinforcement(curP);
            break;
        case 7:
            Barrage(curP);
            break;
    }
    CreateStack(&S);
}

void UpdateSTACK()
{
    /* KAMUS */
    stackinfotype X;
    /* ALGORITMA */
    X.Q1 = GQUEUE[0]; 
    X.Q2 = GQUEUE[1];
    X.F1[0] = GetSFlag(GFLAGS[0]);
    X.F1[1] = GetShieldCD(GFLAGS[0]);
    X.F1[2] = GetAUFlag(GFLAGS[0]);
    X.F1[3] = GetCHFlag(GFLAGS[0]);
    X.F1[4] = GetETFlag(GFLAGS[0]);
    X.F1[5] = GetWFlag(GFLAGS[0]);
    X.F2[0] = GetSFlag(GFLAGS[1]);
    X.F2[1] = GetShieldCD(GFLAGS[1]);
    X.F2[2] = GetAUFlag(GFLAGS[1]);
    X.F2[3] = GetCHFlag(GFLAGS[1]);
    X.F2[4] = GetETFlag(GFLAGS[1]);
    X.F2[5] = GetWFlag(GFLAGS[1]);
    CopyList(GLIST[0],&X.L1); 
    CopyList(GLIST[1],&X.L2); 
    CopyTab(arrBan, &X.arrBan2);
    Push(&S, X);
}

void UNDO()
/* Yang bisa di-undo: ATTACK, LEVEL_UP, MOVE */
/* Stack bakal di-reset tiap: END_TURN, SKILL */
{
    /* KAMUS */
    stackinfotype X;
    /* ALGORITMA */ //printf("FLAGS: %d %d %d %d %d %d\n", GetSFlag(GFLAGS[0]), GetShieldCD(GFLAGS[0]), GetAUFlag(GFLAGS[0]), GetCHFlag(GFLAGS[0]), GetETFlag(GFLAGS[0]), GetWFlag(GFLAGS[0]));
    if (Top(S)>1){
        Pop(&S, &X); Pop(&S, &X);
        GQUEUE[0] = X.Q1;
        GQUEUE[1] = X.Q2;
        SetSFlag(&GFLAGS[0], X.F1[0]);
        SetShieldCD(&GFLAGS[0], X.F1[1]);
        SetAUFlag(&GFLAGS[0], X.F1[2]);
        SetCHFlag(&GFLAGS[0], X.F1[3]);
        SetETFlag(&GFLAGS[0], X.F1[4]);
        SetWFlag(&GFLAGS[0], X.F1[5]);
        SetSFlag(&GFLAGS[1], X.F2[0]);
        SetShieldCD(&GFLAGS[1], X.F2[1]);
        SetAUFlag(&GFLAGS[1], X.F2[2]);
        SetCHFlag(&GFLAGS[1], X.F2[3]);
        SetETFlag(&GFLAGS[1], X.F2[4]);
        SetWFlag(&GFLAGS[1], X.F2[5]);
        CopyList(X.L1,&GLIST[0]); 
        CopyList(X.L2,&GLIST[1]); 
        CopyTab(X.arrBan2, &arrBan);
    }
    else {
        printf("Tidak dapat undo\n");
    }
}
void END_TURN(FLAGS* F, int curP)
/* I.S F terdefinisi */
/* F.S Validasi kondisi game, mengubah turn dan shieldCD */
{
    /* KAMUS */
    // Q1 is the currentplayer, Q2 is the enemy
    boolean isGetIR;
    address P;

    /* ALGORITMA */
    if (GetSFlag(*F)){
        SetShieldCD(F,GetShieldCD(*F)-1);
        if (GetShieldCD(*F)==0){
            Shield_OFF(F);
        }
    }
    if (GetAUFlag(*F)){FlipAUFlag(F);}
    if (GetCHFlag(*F)){FlipCHFlag(F);}
    // Skill Generator: IR
    GenerateIR(curP);
    tambahpasukanauto(&GLIST[curP-1]);
    CreateStack(&S);
}

void MOVE(List L,int curBchoice, int targetBchoice, int jumPas, int curP)
/* I.S curP terdefinisi 1/2, curB dan targetB terdefinisi bagian dari GLIST[curP-1] */
/* F.S Memindahkan pasukan dari curB ke targetB */
{
    /* KAMUS */
    BANGUNAN *curB, *targetB;
    int curBint, targetBint;
    address P;
    /* ALGORITMA */
    // Find bangunan
    P = First(L);
    while (targetBchoice>1){P = Next(P); targetBchoice--;}
    targetB = &bangunan(arrBan, Info(P)); targetBint = Info(P);
    P = First(GLIST[curP-1]);
    while (curBchoice>1){P = Next(P); curBchoice--;}
    curB = &bangunan(arrBan, Info(P)); curBint = Info(P);

    // Move Pasukan
    jumPas = (jumPas+pasukan(*curB)-abs(jumPas-pasukan(*curB)))/2;
    IncreasePasukan(&bangunan(arrBan, targetBint), jumPas);
    // pasukan(bangunan(arrBan, targetBint)) += jumPas;
    DecreasePasukan(&bangunan(arrBan, curBint), jumPas); 
    // pasukan(bangunan(arrBan, curBint)) -= jumPas; printf("%d,%d", curBint,pasukan(bangunan(arrBan, curBint)));

    // Update Stack for Undo
    UpdateSTACK();
}

void EXIT()
/* Memanggil System Exit Call */
{
    /* KAMUS */
    /* ALGORITMA */
    exit(0);
}