/* File : graph.h */
/* ADT graph */

#ifndef graph_H
#define graph_H

#include "boolean.h"
#include "listlinier.h"

#define Nil NULL

typedef adrNode *Node;
typedef adrSuccNode *SuccNode;
typedef struct{
    int Id;
    int NPred;
    adrSuccNode Trail;
    adrNode Next;  
} Node;
typedef struct{
    adrNode Succ;
    adrSuccNode Next;
} SuccNode;
typedef struct 
{
    adrNode First;
} Graph;

/* Selektor */
#define First(G) ((G).First)
#define Id(Pn) (Pn)->Id
#define NPred(Pn) Pn->NPred
#define Trail(Pn) Pn->Trail
#define Next(Pn) Pn->Next
#define Succ(Pt) Pt->Succ
#define Next(Pt) Pt->Next

/* Konstruktor */
void CreateGraph (int X, Graph G);
/* I.S. Sembarang */
/* F.S. Terbantuk graf dengan satu simpul Id=X */

/* Manajemen memori */
adrNode AllocNode (int X);
/* Mengembalikan address hasil alokasi simpul X */
/* Jika alokasi berhasil, maka address tidak Nil. */ 
/* Menghasilkan P, maka Id(P)=X, Npred(P)=0, Trail(P)=Nil,dan Next(P)=Nil.*/

void DeallocNode (adrNode P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */

adrSuccNode AllocSuccNode (adrNode Pn);
/* Mengembalikan address hasil alokasi Pn */
/* Jika alokasi berhasil, maka address tidak Nil. */
/* Menghasilkan Pt, maka Succ(Pt) = Pn, dan Next(Pt)=Nil */

void DeallocSuccNode (adrSuccNode P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */

/* Fungsi/prosedur lain */
adrNode SearchNode (Graph G, int X);
/* Mengembalikan address simpul dengan Id=X jika simpul ada pada graf, Nil jika belum */

List MakeListEdge (Graph G, adrNode P);
/* Membuat list yang berisi keterkaitan antaredge */

void InsertNode (Graph G, int X, adrNode Pn);
/* Menambahkan simpul X ke dalam graf jika alokasi X berhasil */
/* I.S. G terdefinisi, X terdefinisi dan belum ada pada G */
/* F.S. Jika alokasi berhasil, X menjadi elemen terakhir G, Pn berisi address simpul X.
Jika alokasi gagal, G tetap, Pn berisi Nil */

void InsertEdge (Graph G, int prec, int succ);
/* Menambahkan busur dari prec menuju succ ke dalam G } */
/* I.S. G, prec, succ terdefinisi. */
/* F.S. Jika belum ada edge di G, maka menambahkan edge ke G. Jika simpul prec/succ belum ada pada G, tambahkan simpul tersebut dahulu. J
ika sudah ada busur (prec,succ) di G, maka G tetap. */

#endif