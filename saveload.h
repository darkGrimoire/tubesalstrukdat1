/* Definisi Save dan Load File */

#ifndef SAVELOAD_H
#define SAVELOAD_H

/* File yang (mungkin) dipake utk bagian ini */

#include "peta.h"       /* Kemungkinan Besar */
#include "arrbang.h"    /* Belum fix */
#include "graf.h"       /* Belum fix */
#include "point.h"      /* Mungkin nggak, kalo di peta udh ada */
#include "boolean.h"    /* Pasti */
#include "command.h"    /* Mungkin butuh */

/* ********** PERINTAH-PERINTAH UTAMA ********** */

void LoadNewConfig(ArrBang *A, Graf *G, Peta *P);
/* I.S. : A, G, P kosong */
/* F.S. : A, G, dan P terisi sesuai konfigurasi dari file eksternal */

void SaveConfig(ArrBang A, Graf G, Peta P, FLAGS F);
/* I.S. : A, G, P, F terdefinisi, tidak kosong */
/* F.S. : File eksternal diisi dengan konfigurasi berdasarkan A, G, F, P */
/* Format penulisan : Ukuran peta, Jumlah Bangunan, Daftar Bangunan (meliputi Huruf (Simbol), Lokasi (X Y), Kepemilikan, Level, Kelengkapan Bangunan (A, M, P, U)), Flags, dan Graf */

void LoadExistingConfig(ArrBang *A, Graf *G, Peta *P, FLAGS *F);
/* I.S. : A, G, P, F bebas, bisa kosong */
/* F.S. : A, G, P, F diisi sesuai dengan konfigurrrasi dari file eksternal */

/* ********** PRIMITIF SAMPINGAN  ********** */
/* ***** MEMBACA DARI FILE ***** */

void ReadBangunan(ArrBang *A, int JmlhBang);
/* I.S. : A kosong */
/* F.S. : A diisi dengan bangunan yang terdapat di dalam file sejumlah JmlhBang */

void ReadGraf(Graf *G, int JmlhBang);
/* I.S. : G kosong */
/* F.S. : G diisi dengan graf yang merepresentasikan hubungan antar bangunan */

void ReadFlags(FLAGS *F);
/* I.S. : F kosong */
/* F.S. : F diisi dengan kondisi "pertarungan" saat program di-save */

/* ***** MENULIS KE DALAM FILE ***** */

void WriteBangunan(ArrBang A);
/* I.S. : A tidak kosong */
/* F.S. : Bangunan-bangunan dalam A dituliskan ke dalam file */

void WriteFLAGS(FLAGS F);
/* I.S. : F tidak kosong */
/* F.S. : Kondisi dalam F ditulis ke dalam file */

void WriteGraf(Graf G);
/* I.S. : G tidak kosong */
/* F.S. : Isi G ditulis ke dalam file */

#endif