#include <stdio.h>
#include <string.h>
#include <stdlib.h> //digunakan dalam stdlib.h memiliki fungsi atof

#define MAKS 50 // digunakan untuk membuat konstanta/macro

/*Penggunaan tipe data struct dilakukan agar dapat menyimpan banyak data
    dengan tipe data berbeda*/
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
    struct data_tanggal tanggal_transaksi; // digunakan struct dalam struct sehingga memungkinkan mengakses anggota dari struct data_tanggal
};

float saldoUangSekarang(int jumlah_transaksi, struct Keuangan Catat[100]) // fungsi yang akan menghitung saldo uang sekarang
{
    float saldo = 0.0; // deklarasi variabel yang akan menampung nilai return dgn inisialisasi awal  0
    for (int i = 0; i < jumlah_transaksi; i++)
    {
        float jumlah = atof(Catat[i].jumlah);             // atof() disini gunakan untuk mengonversi string menjadi nilai floating-point (desimal) karena kan awalnya dideklarasi pakai char jumlah
        if (strcmp(Catat[i].kategori, "Pendapatan") == 0) // strcmp itu untung membandingkan string. nah kalau misalnya string dalam catat[i].kategori sama dengan pendapatan maka nanti bakal mengembalikan nilai 0 kalau stringnya sama.
        {
            saldo += jumlah; // disini saldo akan menampung nilai dari saldo + jumlah
        }
        else if (strcmp(Catat[i].kategori, "Pengeluaran") == 0) // ini kalau misalnya string dalam catat[i].kategori sama dengan pengeluaran maka nanti bakal mengembalikan nilai 0 kalau stringnya sama. dan memproses saldo = saldo +jumlah
        {
            saldo -= jumlah;
        }
    }
    return saldo;
}

// ini mirip ji penjelasannya kayak yang fungsi sebelumnya
float totalPendapatan(int jumlah_transaksi, struct Keuangan Catat[100])
{
    float total_pendapatan = 0.0; // variabel yang akan menampung total pendapatan
    for (int i = 0; i < jumlah_transaksi; i++)
    {
        if (strcmp(Catat[i].kategori, "Pendapatan") == 0) //
        {
            total_pendapatan += atof(Catat[i].jumlah);
        }
    }
    return total_pendapatan;
}
// ini juga mirip ji penjelasannya kayak yang fungsi sebelumnya
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
    struct Keuangan Catat[100];        // dideklarasikan sebuah array yang bisa menampung 100 elemen yang bertipe struct Keuangan
    int pilihan, jumlah_transaksi = 0; // deklarasi variabel pilihan yang nanti minta input dari user dan juga jumlah_transaksi yang sudah dianalisasi = 0
    int inputKategori, saldo;          // deklarasi inputKategori sehingga memungkinkan memperoleh input dari user nantinya, deklarasi saldo untuk menampung stotal saldo yang dimiliki
    while (1)                          // menggunakan while agar program terus berjalan dan menampilkan menu kepada pengguna untuk pilih opsi karena kalau tidak pakai while, maka program hanya akan selesai setelah satu instruksi dilakukan
    {
        printf("\n-----PROJECT MANAJEMEN KEUANGAN-----\n");
        printf("\n1. Mencatat Pemasukan/Pengeluaran");
        printf("\n2. Menampilkan Riwayat Transaksi");
        printf("\n3. Total Semua Pendapatan");
        printf("\n4. Total Semua Pengeluaran");
        printf("\n5. Saldo Uang Sekarang");
        printf("\n6. Berhenti mencatat transaksi");
        printf("\nMasukkan input:");
        scanf("%d", &pilihan); // disini nanti minta input dari user, mau lakukan apa
        if (pilihan == 1)      // kalau pilih 1, berarti nanti akan mencatat pemasukan/pengerluaran
        {
            printf("\nMasukkan Tanggal(DD/MM/YYYY)\t: ");
            scanf("%d/%d/%d", &Catat[jumlah_transaksi].tanggal_transaksi.tanggal,
                  &Catat[jumlah_transaksi].tanggal_transaksi.bulan,
                  &Catat[jumlah_transaksi].tanggal_transaksi.tahun);
            /* disini nanti akan memasukkan/menyimpan nilai ke dalam array 'CATAT' bertipe 'struct keuangan' dengan elemen sebanyak 'jumlah_transaksi'
                dengan anggota 'tanggal_transaksi.tanggal', 'tanggal_transaksi.bulan' dan 'tanggal_transaksi.tahun'*/
            getchar(); /*kemudian menggunakan getchar() agar apabila terdapat karakter new line (enter) yang tersisa dalam input buffer maka kita bisa mebaca dan menghapusnya sebelum input berikutnya sehingga tidak diabaikan dan tidak mempengaruhi pembacaan input selanjutnya.
            Karena pada dasarnya fungsi getchar itu untuk membaca satu karakter dari input buffer. Buffer itu kek memori yang digunakan untuk menyimpan data sementara  */
            printf("Kategori:");
            printf("\n1. Pendapatan");
            printf("\n2. Pengeluaran");
            printf("\nMasukkan kategori(1/2)\t\t: ");
            scanf("%d", &inputKategori);
            getchar();
            if (inputKategori == 1) // kalau misalnya user pilih 1, maka nanti "Pendapatan" akan disalin kedalam Catat[jumlah_transaksi]. kategori dengan menggunakan strcpy
            {
                strcpy(Catat[jumlah_transaksi].kategori, "Pendapatan");
            }
            else if (inputKategori == 2) // kalau misalnya user pilih 1, maka nanti "Pengeluaran" akan disalin kedalam Catat[jumlah_transaksi]. kategori dengan menggunakan strcpy
            {
                strcpy(Catat[jumlah_transaksi].kategori, "Pengeluaran");
            }
            printf("Masukkan Keterangan\t\t: ");
            scanf("%[^\n]%*c", Catat[jumlah_transaksi].keterangan); // pakai %[^\n]%*c sebagai format untuk memasukkan string yang mengandung spasi atau karekter khusus lainnya selain newline dan juga setelah scanf tidak dibuthkan lagi getchar karena udah ada format %*c yang digunakan untuk abaikan newline
            printf("Jumlah(Rp)\t\t\t: ");
            scanf("%[^\n]%*c", Catat[jumlah_transaksi].jumlah);
            jumlah_transaksi++;
        }
        else if (pilihan == 2)
        {
            if (jumlah_transaksi == 0) // kalau nanti belum masukkan transaksi apapun, nanti bakal menampilkan ini
            {
                printf(" ---------------------------------------------------------------- ");
                printf("\n| Belum ada pencatatan transaksi pendapatan maupun pengeluaran |\n");
                printf(" ---------------------------------------------------------------- ");
            }
            else
            {
                for (int j = 0; j < jumlah_transaksi; j++) // ini untuk menampilkan semua catatan transaksi yang sudah di masukkan
                {
                    printf("\nTransaksi %d", j + 1);
                    printf("\nTanggal\t\t: %d/%d/%d", Catat[j].tanggal_transaksi.tanggal,
                           Catat[j].tanggal_transaksi.bulan,
                           Catat[j].tanggal_transaksi.tahun);
                    printf("\nKategori\t: %s", Catat[j].kategori);
                    printf("\nKeterangan\t: %s", Catat[j].keterangan);
                    printf("\nJumlah(Rp)\t: %s", Catat[j].jumlah);
                    printf("\n-----------------------------\n");
                }
            }
        }
        else if (pilihan == 3)
        {
            printf(" ----------------------------- ");
            printf("\n| Total Pendapatan = Rp %.2f |\n", totalPendapatan(jumlah_transaksi, Catat)); // ini akan menampung return dari fungsi yang dipanggil yaitu  totalPendapatan
            printf(" ----------------------------- ");
        }
        else if (pilihan == 4)
        {
            printf(" ----------------------------- ");
            printf("\n| Total Pengeluaran = Rp %.2f |\n", totalPengeluaran(jumlah_transaksi, Catat)); // ini akan menampung return dari fungsi yang dipanggil yaitu  totalPengeluaran
            printf(" ----------------------------- ");
        }
        else if (pilihan == 5)
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
                printf("\n| Saldo Uang Sekarang = Rp %.2f |\n", saldoUangSekarang(jumlah_transaksi, Catat)); // ini akan menampung return dari fungsi yang dipanggil yaitu  saldoUangSekarang
                printf(" ---------------------- ");
            }
        }
        else if (pilihan == 6) // ini kalau ingin berhenti mencatat transaksi
        {
            break;
        }
        else // ini kalau yang na input selain 1-6
        {
            printf("Input Tidak Valid!!!");
            break;
        }
    }
    return 0;
}