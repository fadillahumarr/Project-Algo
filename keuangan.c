#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAKS 50

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

float menghitungUang(int jumlah_transaksi, struct Keuangan Catat[100])
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
    struct Keuangan Catat[100];
    int i, pilihan, jumlah_transaksi = 0;
    char masukan[MAKS];
    int inputKategori, saldo, jumlah;
    while (1)
    {
        printf("\n1. Mencatat Pemasukan/Pengeluaran");
        printf("\n2. Menampilkan Riwayat Transaksi");
        printf("\n3. Total Semua Pendapatan");
        printf("\n4. Total Semua Pengeluaran");
        printf("\n5. Saldo Uang Sekarang");
        printf("\n6. Berhenti pencatatan transaksi");
        printf("\nMasukkan input:");
        scanf("%d", &pilihan);
        if (pilihan == 1)
        {
            printf("\nMasukkan Tanggal(DD/MM/YYYY)\t: ");
            scanf("%d/%d/%d", &Catat[jumlah_transaksi].tanggal_transaksi.tanggal,
                  &Catat[jumlah_transaksi].tanggal_transaksi.bulan,
                  &Catat[jumlah_transaksi].tanggal_transaksi.tahun);
            getchar();
            printf("Kategori:");
            printf("\n1. Pendapatan");
            printf("\n2. Pengeluaran");
            printf("\nMasukkan kategori(1/2)\t\tz: ");
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
            printf("Masukkan Keterangan\t\t: ");
            scanf("%[^\n]%*c", Catat[jumlah_transaksi].keterangan);
            printf("Jumlah(Rp)\t\t\t: ");
            scanf("%[^\n]%*c", Catat[jumlah_transaksi].jumlah);
            jumlah_transaksi++;
        }
        else if (pilihan == 2)
        {
            if (jumlah_transaksi == 0)
            {
                printf(" ----------------------------------------------------- ");
                printf("\n| Belum ada pencatatan transaksi pendapatan maupun pengeluaran |\n");
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
                    printf("\nKategori\t: %s", Catat[j].kategori);
                    printf("\nKeterangan\t: %s", Catat[j].keterangan);
                    printf("\nJumlah(Rp)\t: %s", Catat[j].jumlah);
                    printf("\n-------------------------\n");
                }
            }
        }
        else if (pilihan == 3)
        {
            float total_pendapatan = 0.0;
            for (int i = 0; i < jumlah_transaksi; i++)
            {
                if (strcmp(Catat[i].kategori, "Pendapatan") == 0)
                {
                    float jumlah = atof(Catat[i].jumlah);
                    total_pendapatan += jumlah;
                }
            }
            printf("\nTotal Pendapatan = %.2f", total_pendapatan);
        }
        else if (pilihan == 4)
        {
            float total_pengeluaran = 0.0;
            for (int i = 0; i < jumlah_transaksi; i++)
            {
                if (strcmp(Catat[i].kategori, "Pengeluaran") == 0)
                {
                    float jumlah = atof(Catat[i].jumlah);
                    total_pengeluaran += jumlah;
                }
            }
            printf("\nTotal Pengeluaran = %.2f", total_pengeluaran);
        }
        else if (pilihan == 5)
        {
            if (jumlah_transaksi == 0)
            {
                printf(" --------------------- ");
                printf("\n| Saldo Uang Sekarang = Rp 0 |\n");
                printf(" --------------------- ");
            }
            else
            {
                float saldo = menghitungUang(jumlah_transaksi, Catat);
                printf(" ---------------------- ");
                printf("\n| Saldo Uang Sekarang = %.2f |\n", saldo);
                printf(" ---------------------- ");
            }
        }
        else if (pilihan == 6)
        {
            break;
        }
        else
        {
            printf("Input Tidak Valid!!!");
            break;
        }
    }
    return 0;
}