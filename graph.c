/* File : graph.c */
/* Implementasi dari graph.h */

#include <stdio.h>
#include <stdlib.h>
#include "lib\graph.h"

/* Konstruktor */
void CreateGraph (int X, Graph* G){
/* I.S. Sembarang */
/* F.S. Terbentuk graf dengan satu simpul Id=X */
    // KAMUS LOKAL
    // ALGORITMA
        FirstG(*G) = AllocNode(X);
}

/* Manajemen memori */
addrNode AllocNode (int X){
/* Mengembalikan address hasil alokasi simpul X */
/* Jika alokasi berhasil, maka address tidak Nil. */ 
/* Menghasilkan P, maka Id(P)=X, Npred(P)=0, Trail(P)=Nil,dan Next(P)=Nil.*/
    // KAMUS LOKAL
        addrNode P;
    // ALGORITMA
        P = (addrNode) malloc (sizeof(Node));
        if(P!=Nil){
            Id(P) = X;
            NPred(P) = 0;
            Trail(P) = Nil;
            NextN(P) = Nil;
            return P;
        }
        else{
            return Nil;
        }
}

addrSuccNode AllocSuccNode (addrNode Pn){
/* Mengembalikan address hasil alokasi Pn */
/* Jika alokasi berhasil, maka address tidak Nil. */
/* Menghasilkan Pt, maka Succ(Pt) = Pn, dan Next(Pt)=Nil */
    // KAMUS LOKAL
        addrSuccNode Pt;
    // ALGORITMA
        Pt = (addrSuccNode) malloc (sizeof(SuccNode));
        if(Pt!=Nil){
            Succ(Pt) = Pn;
            NextT(Pt) = Nil;
            return Pt;
        }
        else{
            return Nil;
        }
}

/* Fungsi/prosedur lain */
addrNode SearchNode (Graph G, int X){
/* Mengembalikan address simpul dengan Id=X jika simpul ada pada graf, Nil jika belum */
    // KAMUS LOKAL
        addrNode N;
    // ALGORITMA
        N = FirstG(G);
        while((N!=Nil) && (Id(N)!=X)){
            N = NextN(N);
        }
        return N;
}

addrSuccNode SearchEdge (Graph G, int prec, int succ){
/* Mengembalikan address trailer yang menyimpan info edge jika edge ada pada graf, Nil jika belum */
    // KAMUS LOKAL
        addrNode P;
        addrSuccNode Q;
    // ALGORITMA
        P = SearchNode(G,prec);
        if(P!=Nil){
            Q = Trail(P);
            if (Q==Nil){
                return Q;
            }
            while(Id(Succ(Q))!=succ && NextT(Q)!=Nil){
                Q = NextT(Q);
            }
            if (Id(Succ(Q))==succ){
                return Q;
            }else{
                return Nil;
            }
        }
        else{
            return Nil;
        }
}

List MakeListEdge (Graph G, int X){
/* Membuat list yang berisi keterkaitan antarsimpul */
    // KAMUS LOKAL
        List L;
        addrNode Pnode;
        addrSuccNode Ptrail;
    // ALGORITMA
        Pnode = SearchNode(G,X);
        Ptrail = Trail(Pnode); 
        CreateList(&L);
        while (Ptrail != Nil){
            InsVLast(&L,Id(Succ(Ptrail)));
            Ptrail = NextT(Ptrail);
        }
        return L;
}

void InsertNode (Graph* G, int X, addrNode* Pn){
/* Menambahkan simpul X ke dalam graf jika alokasi X berhasil */
/* I.S. G terdefinisi, X terdefinisi dan belum ada pada G */
/* F.S. Jika alokasi berhasil, X menjadi elemen terakhir G, Pn berisi address simpul X.
Jika alokasi gagal, G tetap, Pn berisi Nil */
    // KAMUS LOKAL
        addrNode P,Q;
    // ALGORITMA
        *Pn = AllocNode(X);
        Q = Nil;
        if(*Pn!=Nil){
            P = FirstG(*G);
            while(Id(P)<X && NextN(P)!=Nil){
                Q=P;
                P=NextN(P);
            }
            if(Id(P)>X){
                NextN(Q)=*Pn;
                NextN(*Pn)=P;
            }
            else{
                NextN(P)=*Pn;
                NextN(*Pn)=Nil;
            }
        }
}

void InsertEdge (Graph* G, int prec, int succ){
/* Menambahkan busur dari prec menuju succ ke dalam G } */
/* I.S. G, prec, succ terdefinisi. */
/* F.S. Jika belum ada edge di G, maka menambahkan edge ke G. Jika simpul prec/succ belum ada pada G, tambahkan simpul tersebut dahulu.
Jika sudah ada busur (prec,succ) di G, maka G tetap. */
    // KAMUS LOKAL
        addrNode Pprec, Psucc;
        addrSuccNode Ptrail;
    // ALGORITMA
        Pprec = SearchNode(*G,prec);
        Psucc = SearchNode(*G,succ);
        if(Pprec==Nil){
            InsertNode(G,prec,&Pprec);
        }
        if(Psucc==Nil){
            InsertNode(G,succ,&Psucc);
        }
        
        if(SearchEdge(*G,prec,succ)==Nil){
            Ptrail = Trail(Pprec);
            if(Ptrail==Nil){
                Trail(Pprec) = AllocSuccNode(Psucc);
            }
            else{
                while(NextT(Ptrail)!=Nil){
                    Ptrail = NextT(Ptrail);
                }
                NextT(Ptrail)=AllocSuccNode(Psucc);
                NPred(Psucc)+=1;
            }
        }
}