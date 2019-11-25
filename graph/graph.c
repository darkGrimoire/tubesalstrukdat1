/* File : graph.c */
/* Implementasi dari graph.h */

#include <stdio.h>
#include <stdlib.h>
#include "../graph/graph.h"

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
/* Jika alokasi berhasil, maka address tidak NilG. */ 
/* Menghasilkan P, maka Id(P)=X, Npred(P)=0, Trail(P)=NilG,dan Next(P)=NilG.*/
    // KAMUS LOKAL
        addrNode P;
    // ALGORITMA
        P = (addrNode) malloc (sizeof(Node));
        if(P!=NilG){
            Id(P) = X;
            NPred(P) = 0;
            Trail(P) = NilG;
            NextN(P) = NilG;
            return P;
        }
        else{
            return NilG;
        }
}

addrSuccNode AllocSuccNode (addrNode Pn){
/* Mengembalikan address hasil alokasi Pn */
/* Jika alokasi berhasil, maka address tidak NilG. */
/* Menghasilkan Pt, maka Succ(Pt) = Pn, dan Next(Pt)=NilG */
    // KAMUS LOKAL
        addrSuccNode Pt;
    // ALGORITMA
        Pt = (addrSuccNode) malloc (sizeof(SuccNode));
        if(Pt!=NilG){
            Succ(Pt) = Pn;
            NextT(Pt) = NilG;
            return Pt;
        }
        else{
            return NilG;
        }
}

/* Fungsi/prosedur lain */
addrNode SearchNode (Graph G, int X){
/* Mengembalikan address simpul dengan Id=X jika simpul ada pada graf, NilG jika belum */
    // KAMUS LOKAL
        addrNode N;
    // ALGORITMA
        N = FirstG(G);
        while((N!=NilG) && (Id(N)!=X)){
            N = NextN(N);
        }
        return N;
}

addrSuccNode SearchEdge (Graph G, int prec, int succ){
/* Mengembalikan address trailer yang menyimpan info edge jika edge ada pada graf, NilG jika belum */
    // KAMUS LOKAL
        addrNode P;
        addrSuccNode Q;
    // ALGORITMA
        P = SearchNode(G,prec);
        if(P!=NilG){
            Q = Trail(P);
            if (Q==NilG){
                return Q;
            }
            while(Id(Succ(Q))!=succ && NextT(Q)!=NilG){
                Q = NextT(Q);
            }
            if (Id(Succ(Q))==succ){
                return Q;
            }else{
                return NilG;
            }
        }
        else{
            return NilG;
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
        while (Ptrail != NilG){
            InsVLast(&L,Id(Succ(Ptrail)));
            Ptrail = NextT(Ptrail);
        }
        return L;
}

void InsertNode (Graph* G, int X, addrNode* Pn){
/* Menambahkan simpul X ke dalam graf jika alokasi X berhasil */
/* I.S. G terdefinisi, X terdefinisi dan belum ada pada G */
/* F.S. Jika alokasi berhasil, X menjadi elemen terakhir G, Pn berisi address simpul X.
Jika alokasi gagal, G tetap, Pn berisi NilG */
    // KAMUS LOKAL
        addrNode P,Q;
    // ALGORITMA
        *Pn = AllocNode(X);
        Q = NilG;
        if(*Pn!=NilG){
            P = FirstG(*G);
            while(Id(P)<X && NextN(P)!=NilG){
                Q=P;
                P=NextN(P);
            }
            if(Id(P)>X){
                NextN(Q)=*Pn;
                NextN(*Pn)=P;
            }
            else{
                NextN(P)=*Pn;
                NextN(*Pn)=NilG;
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
        if(Pprec==NilG){
            InsertNode(G,prec,&Pprec);
        }
        if(Psucc==NilG){
            InsertNode(G,succ,&Psucc);
        }
        
        if(SearchEdge(*G,prec,succ)==NilG){
            Ptrail = Trail(Pprec);
            if(Ptrail==NilG){
                Trail(Pprec) = AllocSuccNode(Psucc);
            }
            else{
                while(NextT(Ptrail)!=NilG){
                    Ptrail = NextT(Ptrail);
                }
                NextT(Ptrail)=AllocSuccNode(Psucc);
                NPred(Psucc)+=1;
            }
        }
}