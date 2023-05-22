#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAKS 100

struct data_tanggal
{
    int tanggal;
    int bulan;
    int tahun;
};
struct Keuangan
{
    struct data_tanggal tanggal_transaksi;
    char kategori[MAKS];
    char jumlah[MAKS];
    char keterangan[MAKS];
};

float Menghitung_Uang(int jumlah_transaksi, struct Keuangan Catat[MAKS])
{
    float saldo = 0.0;
    for (int i = 0; i < jumlah_transaksi; i++)
    {
        float jumlah = atof(Catat[i].jumlah);
        if (strcmp(Catat[i].kategori, "Pendapatan") == 0)
        {
            saldo += jumlah;
        }
        else if (strcmp(Catat[i].kategori, "Pengeluaran") == 0)
        {
            saldo -= jumlah;
        }
    }
    return saldo;
}

int main()
{
    struct Keuangan Catat[MAKS];
    int i, tanggapan, jumlah_transaksi = 0;
    char masukan[MAKS];
    int inputKategori;
    while (1)
    {
        printf("\n1. Jumlah Uang ");
        printf("\n2. Mencatat Pemasukan/Pengeluaran");
        printf("\n3. Menampilkan Riwayat Transaksi");
        printf("\nMasukkan input:");
        scanf("%d", &tanggapan);
        if (tanggapan == 1)
        {
            if (jumlah_transaksi == 0)
            {
                printf(" ------------------------- ");
                printf("\n| Jumlah Uang = Rp 0 |\n");
                printf(" ------------------------- ");
            }
            else
            {
                float saldo = Menghitung_Uang(jumlah_transaksi, Catat);
                printf(" ------------------------- ");
                printf("\n| Jumlah Uang = %.2f |\n", saldo);
                printf(" ------------------------- ");
            }
        }
        else if (tanggapan == 2)
        {
            printf("\nMasukkan Tanggal\t: ");
            scanf("%d/%d/%d", &Catat[jumlah_transaksi].tanggal_transaksi.tanggal,
                  &Catat[jumlah_transaksi].tanggal_transaksi.bulan,
                  &Catat[jumlah_transaksi].tanggal_transaksi.tahun);
            getchar();
            printf("Masukkan Keterangan\t: ");
            scanf("%[^\n]%*c", Catat[jumlah_transaksi].keterangan);
            printf("Kategori\t\t:");
            printf("\n1. Pendapatan");
            printf("\n2. Pengeluaran");
            printf("\nMasukkan kategori(1/2)\t: ");
            scanf("%d", &inputKategori);
            getchar();
            if (inputKategori == 1)
            {
                strcpy(Catat[jumlah_transaksi].kategori, "Pendapatan");
            }
            else if (inputKategori == 2)
            {
                strcpy(Catat[jumlah_transaksi].kategori, "Pengeluaran");
            }
            // scanf("%[^\n]%*c", Catat[jumlah_transaksi].kategori);
            printf("Jumlah(Rp)\t\t: ");
            scanf("%[^\n]%*c", Catat[jumlah_transaksi].jumlah);
            jumlah_transaksi++;
        }
        else if (tanggapan == 3)
        {
            if (jumlah_transaksi == 0)
            {
                printf(" ----------------------------------------------------- ");
                printf("\n| Belum ada transaksi pendapatan maupun pengeluaran |\n");
                printf(" ----------------------------------------------------- ");
            }
            else
            {
                for (int j = 0; j < jumlah_transaksi; j++)
                {
                    printf("\nTransaksi %d", j + 1);
                    printf("\nTanggal\t\t: %d/%d/%d", Catat[j].tanggal_transaksi.tanggal,
                           Catat[j].tanggal_transaksi.bulan,
                           Catat[j].tanggal_transaksi.tahun);
                    printf("\nKeterangan\t: %s", Catat[j].keterangan);
                    printf("\nKategori\t: %s", Catat[j].kategori);
                    printf("\nJumlah(Rp)\t: %s", Catat[j].jumlah);
                    printf("\n-------------------------\n");
                }
            }
        }
        else
        {
            break;
        }
    }
    return 0;
}