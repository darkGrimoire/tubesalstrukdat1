// Implementasi peta.h

#include "lib/matriks.h"
#include "lib/boolean.h"
#include <stdio.h>
#include "lib/pcolor.h"
#include "lib/peta.h"
#include "lib/arraydin.h"
#include "lib/point.h"

/* ==== PROTOTIPE PRIMITIF ==== */

/* Konstruktor */
void CreatePeta (int NB, int NK, Peta *P)
// Membentuk peta baru dengan baris sebanyak NB dan kolom sebanyak NK
// border peta ( indeks 0,i; nb+1,i; j,0; nk+1,0) diisi '*'
// I.S. NB dan NK valid
// F.S. Terbentuk peta P kosong sesuai definisi
{
    if (IsPetaValid(NB, NK))
    {
        MakeMATRIKS(NB, NK, P);
        printf("Anda berada di medan perang seluas %d x %d\n", NB, NK);
    }
    else
    {
        printf("%s", "Baris dan kolom tidak sesuai spesifikasi\n");
    }
    
}

/* Selektor */
// Selektor disamakan dengan type MATRIKS

/* Fungsi-Fungsi Validasi */

boolean IsPetaValid(int NB, int NK)
// Mengecek banyak baris dan kolom yang dimasukkan pengguna sesuai spesifikasi
// minimal 10x10, maksimal 20x30
{
    if ((NB >= 10) && (NB <= 20) && (NK >= 10) && (NK <= 30))
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

void IsiPeta(Peta *P, TabInt arrBan)
// Mengisi matriks peta dengan bangunan pada array bangunan sesuai dengan lokasinya
// I.S. Peta Kosong
// F.S. Peta diisi sesuai isi array bangunan
/* Keterangan: castle 0 = C, castle 1 = c, castle 2 = p
               tower 0 = T, tower 1 = t, tower 2 = q
               fort 0 = F, fort 1 = f, fort 2 = r
               village 0 = V, village 1 = v, village 2 = s */
{
    int x,y;
    char b;
    for (int i = 1; i <= Neff(arrBan); i++)
    {
        x = Absis(lok(bangunan(arrBan,i))); // mengambil indeks baris bangunan
        y = Ordinat(lok(bangunan(arrBan,i)));
        b = jenis(bangunan(arrBan,i));
        TulisPOINT(lok(bangunan(arrBan,i))); // !!!
        printf("%c\n", b); // !!!
        switch (b)
        {
            case 'C':
                if (kepemilikan(bangunan(arrBan,i)) == 0)
                {
                    ElmtMatriks(*P,y,x) = b;
                }
                else if (kepemilikan(bangunan(arrBan,i)) == 2)
                {
                    ElmtMatriks(*P,y,x) = 'c';
                }
                else
                {
                    ElmtMatriks(*P,y,x) = 'p';
                }
                break;
            case 'T':
                if (kepemilikan(bangunan(arrBan,i)) == 0)
                {
                    ElmtMatriks(*P,y,x) = b;
                }
                else if (kepemilikan(bangunan(arrBan,i)) == 2)
                {
                    ElmtMatriks(*P,y,x) = 't';
                }
                else
                {
                    ElmtMatriks(*P,y,x) = 'q';
                }
                break;
            case 'F':
                if (kepemilikan(bangunan(arrBan,i)) == 0)
                {
                    ElmtMatriks(*P,y,x) = b;
                }
                else if (kepemilikan(bangunan(arrBan,i)) == 2)
                {
                    ElmtMatriks(*P,y,x) = 'f';
                }
                else
                {
                    ElmtMatriks(*P,y,x) = 'r';
                }
                break;
            case 'V':
                if (kepemilikan(bangunan(arrBan,i)) == 0)
                {
                    ElmtMatriks(*P,y,x) = b;
                }
                else if (kepemilikan(bangunan(arrBan,i)) == 2)
                {
                    ElmtMatriks(*P,y,x) = 'v';
                }
                else
                {
                    ElmtMatriks(*P,y,x) = 's';
                }
                break;
            default:
                break;
        }
    }
}
/* Fungsi Display */
void DisplayPeta (Peta P)
// Mencetak peta ke layar
// I.S. Peta tidak kosong
// F.S. Peta dicetak ke layar dengan warna sesuai kepemilikan bangunan
// Putih untuk bangunan tanpa kepemilikan, merah untuk player 1, kuning untuk player 2
{
    // mencetak border atas
    for (int i = 0; i <= GetLastIdxKol(P)+1; i++)
    {
        printf("%c", '*');
    }
    printf("\n");
    // mencetak isi peta dengan border * di kanan dan kiri
    for (int i = GetFirstIdxBrs(P); i <= GetLastIdxBrs(P); i++)
    {
        for (int j = GetFirstIdxKol(P)-1; j <= GetLastIdxKol(P)+1; j++)
        {
            if (j == GetFirstIdxKol(P)-1) // border kiri
            {
                printf("%c", '*');
            }
            else if (j == GetLastIdxKol(P)+1) // border kanan
            {
                printf("%c\n", '*');
            }
            else // isi matriks
            {
                switch (ElmtMatriks(P,i,j))
                {
                case 'c':
                    print_red('C');
                    break;
                case 'p':
                    print_green('C');
                    break;
                case 't':
                    print_red('T');
                    break;
                case 'q':
                    print_green('T');
                    break;
                case 'f':
                    print_red('F');
                    break;
                case 'r':
                    print_green('F');
                    break;
                case 'v':
                    print_red('F');
                    break;
                case 's':
                    print_green('F');
                    break;
                default:
                    printf("%c ", ElmtMatriks(P,i,j));
                    break;
                }
            }
        }
    }
    // mencetak border bawah
    for (int i = 0; i <= GetLastIdxKol(P)+1; i++)
    {
        printf("%c", '*');
    }
    printf("\n");
}