#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAKS 50 // deklarasi konstanta

// deklarasi tipe data struct
struct data_tanggal
{
    int tanggal;
    int bulan;
    int tahun;
};
struct Keuangan
{
    char kategori[MAKS];
    char jumlah[MAKS];
    char keterangan[MAKS];
    struct data_tanggal tanggal_transaksi;
};

// fungsi untuk menghitung saldo uang sekarang
float saldoUangSekarang(int jumlah_transaksi, struct Keuangan Catat[100])
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

// fungsi untuk menghitung total pendapatan
float totalPendapatan(int jumlah_transaksi, struct Keuangan Catat[100])
{
    float total_pendapatan = 0.0;
    for (int i = 0; i < jumlah_transaksi; i++)
    {
        if (strcmp(Catat[i].kategori, "Pendapatan") == 0) //
        {
            total_pendapatan += atof(Catat[i].jumlah);
        }
    }
    return total_pendapatan;
}

// fungsi untuk menghitung total pendapatan
float totalPengeluaran(int jumlah_transaksi, struct Keuangan Catat[100])
{
    float total_pengeluaran = 0.0;
    for (int i = 0; i < jumlah_transaksi; i++)
    {
        if (strcmp(Catat[i].kategori, "Pengeluaran") == 0)
        {
            total_pengeluaran += atof(Catat[i].jumlah);
        }
    }
    return total_pengeluaran;
}

int main()
{
    struct Keuangan Catat[100];
    int pilihan, jumlah_transaksi = 0;
    int inputKategori, saldo;
    while (1)
    {
        printf("\n-----PROJECT MANAJEMEN KEUANGAN-----\n");
        printf("\n1. Mencatat Pemasukan/Pengeluaran");
        printf("\n2. Menampilkan Riwayat Transaksi");
        printf("\n3. Total Semua Pendapatan");
        printf("\n4. Total Semua Pengeluaran");
        printf("\n5. Saldo Uang Sekarang");
        printf("\n6. Berhenti mencatat transaksi");
        printf("\nMasukkan input:");
        scanf("%d", &pilihan);
        if (pilihan == 1) // Mencatat pemasukan/pengeluaran
        {
            printf("\nMasukkan Tanggal(DD/MM/YYYY)\t: ");
            scanf("%d/%d/%d", &Catat[jumlah_transaksi].tanggal_transaksi.tanggal,
                  &Catat[jumlah_transaksi].tanggal_transaksi.bulan,
                  &Catat[jumlah_transaksi].tanggal_transaksi.tahun);
            getchar();
            printf("Kategori:");
            printf("\n1. Pendapatan");
            printf("\n2. Pengeluaran");
            printf("\nMasukkan kategori(1/2)\t\t: ");
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
            printf("Jumlah(Rp)\t\t\t: ");
            scanf("%[^\n]%*c", Catat[jumlah_transaksi].jumlah);
            printf("Masukkan Keterangan\t\t: ");
            scanf("%[^\n]%*c", Catat[jumlah_transaksi].keterangan);
            jumlah_transaksi++;
        }
        else if (pilihan == 2) // Menampilkan Riwayat Transaksi
        {
            if (jumlah_transaksi == 0)
            {
                printf(" ---------------------------------------------------------------- ");
                printf("\n| Belum ada pencatatan transaksi pendapatan maupun pengeluaran |\n");
                printf(" ---------------------------------------------------------------- ");
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
                    printf("\nJumlah(Rp)\t: %s", Catat[j].jumlah);
                    printf("\nKeterangan\t: %s", Catat[j].keterangan);
                    printf("\n-----------------------------\n");
                }
            }
        }
        else if (pilihan == 3) // Menghitung Total Pendapatan
        {
            printf(" ----------------------------- ");
            printf("\n| Total Pendapatan = Rp %.2f |\n", totalPendapatan(jumlah_transaksi, Catat));
            printf(" ----------------------------- ");
        }
        else if (pilihan == 4) // Menghitung Total Pengeluaran
        {
            printf(" ----------------------------- ");
            printf("\n| Total Pengeluaran = Rp %.2f |\n", totalPengeluaran(jumlah_transaksi, Catat));
        }
        else if (pilihan == 5) // Menghitung Saldo Uang Sekarang
        {
            if (jumlah_transaksi == 0)
            {
                printf(" -------------------------- ");
                printf("\n| Saldo Uang Sekarang = Rp 0 |\n");
                printf(" -------------------------- ");
            }
            else
            {
                printf(" ---------------------- ");
                printf("\n| Saldo Uang Sekarang = Rp %.2f |\n", saldoUangSekarang(jumlah_transaksi, Catat));
            }
        }
        else if (pilihan == 6) // Menghentikan pencatatan transaksi
        {
            break;
        }
        else // Jika input selain 1-6
        {
            printf("Input Tidak Valid!!!");
            break;
        }
    }
    return 0;
}