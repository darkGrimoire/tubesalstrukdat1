/* Definisi Save dan Load File */

#ifndef SAVELOAD_H
#define SAVELOAD_H

/* File yang (mungkin) dipake utk bagian ini */

#include "../peta/peta.h"       
#include "../arraydin/arraydin.h"
#include "../graph/graph.h"        
#include "../boolean.h"  
#include "../command/command.h"  
#include "../queue/queue.h"
#include "../listlinier/listlinier.h"

/* ********** PRIMITIF SAMPINGAN  ********** */
/* ***** MEMBACA DARI FILE ***** */

void ReadBangunanOld(TabInt *T, int JmlhBang);
/* I.S. : A kosong */
/* F.S. : A diisi dengan bangunan yang terdapat di dalam file sejumlah JmlhBang */

void ReadBangunanNew(TabInt *T, int JmlhBang);
/* I.S. : A kosong */
/* F.S. : A diisi dengan bangunan yang terdapat di dalam file sejumlah JmlhBang */

void ReadGraf(Graph* G, int JmlhBang);
/* I.S. : G kosong */
/* F.S. : G diisi dengan graf yang merepresentasikan hubungan antar bangunan */

void ReadFLAGS(FLAGS *F);
/* I.S. : F kosong */
/* F.S. : F diisi dengan kondisi "pertarungan" saat program di-save */

void ReadQueue(Queue *Q);
/* I.S. : S kosong */
/* F.S. : S diisi dengan kondisi "pertarungan" saat program di-save */

/* ***** MENULIS KE DALAM FILE ***** */

void WriteBangunan(TabInt T);
/* I.S. : A tidak kosong */
/* F.S. : Bangunan-bangunan dalam A dituliskan ke dalam file */

void WriteFLAGS(FLAGS F);
/* I.S. : F tidak kosong */
/* F.S. : Kondisi dalam F ditulis ke dalam file */

void WriteGraf(Graph G, int JmlhBang);
/* I.S. : G tidak kosong */
/* F.S. : Isi G ditulis ke dalam file */

void WriteQueue(Queue Q);
/* I.S. : F tidak kosong */
/* F.S. : Kondisi dalam F ditulis ke dalam file */

/* ********** PERINTAH-PERINTAH UTAMA ********** */

void LoadNewConfig(TabInt *T, Graph* G, Peta *P, List *L1, List *L2, const char *FileName);
/* I.S. : A, G, P kosong */
/* F.S. : A, G, dan P terisi sesuai konfigurasi dari file eksternal */

void SaveConfig(TabInt T, Graph G, Peta P, FLAGS F1, FLAGS F2, Queue Q1, Queue Q2, const char *FileName);
/* I.S. : A, G, P, F terdefinisi, tidak kosong */
/* F.S. : File eksternal diisi dengan konfigurasi berdasarkan A, G, F, P */
/* Format penulisan : Ukuran peta, Jumlah Bangunan, Daftar Bangunan (meliputi Huruf (Simbol), Lokasi (X Y), Kepemilikan, Level, Kelengkapan Bangunan (A, M, P, U)), Flags, dan Graf */

void LoadExistingConfig(TabInt *T, Graph* G, Peta *P, FLAGS *F1, FLAGS *F2, Queue *Q1, Queue *Q2, List *L1, List *L2, const char *FileName);
/* I.S. : A, G, P, F bebas, bisa kosong */
/* F.S. : A, G, P, F diisi sesuai dengan konfigurrrasi dari file eksternal */

#endif
