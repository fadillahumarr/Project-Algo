/*Buatlah sebuah program dengan spesifikasi sebagai berikut
Anda membutuhkan sebuah database okontak yang terdiri dari data
1. Nama
2. Alamat
3. No. telpon
4. Alamat email
Anda membutuhkan program agar dapat menambahkan kontak baru hingga sebanyak 100 kontak. Program yang dibuat
harus dapat digunakan pula untuk melihat daftar kontak. Untuk itu, program
harus menampilkan menu apa yang diinginkan oleh pengguna
a. Menambah kontak baru
b. Menampilkan kontak baru*/

#include <stdio.h>
#include <string.h>

struct kontak
{
    char nama[100];
    char alamat[100];
    char no_telpon[100];
    char alamat_email[100];
};

int main()
{
    printf("DAFTAR KONTAK\n");
    struct kontak mahasiswa[100];
    int jawaban, jumlah = 0;
    char input[100];
    int i;
    while (1)
    {
        printf("1. Menampilkan Kontak \n");
        printf("2. Menambahkan kontak baru\n");
        printf("3. Berhenti input\n\n");
        printf("Lo mau ngapain: ");
        scanf("%d", &jawaban);

        if (jawaban == 1)
        {
            if (jumlah == 0)
            {
                printf("_____________________\n\tGak ada daftar kontak\n\n");
            }
            else
            {
                printf("\nMenampilkan Kontak\n------------------");
                for (i = 0; i < jumlah; i++)
                {
                    printf("\nKontak #%d", i + 1);
                    printf("\nNama :%s ", mahasiswa[i].nama);
                    printf("\nAlamat: %s", mahasiswa[i].alamat);
                    printf("\nNo.Telpon :%s", mahasiswa[i].no_telpon);
                    printf("\nAlamat Email :%s\n", mahasiswa[i].alamat_email);
                }
            }
        }
        else if (jawaban == 2)
        {
            scanf("%c");
            printf("\n Tambahkan kontak\n");
            printf("\nMasukkan nama:");
            scanf("%[^\n]%*c", &input);
            strcpy(mahasiswa[jumlah].nama, input);

            printf("\nMasukkan alamat:");
            scanf("%[^\n]%*c", &input);
            strcpy(mahasiswa[jumlah].alamat, input);

            printf("\nMasukkan no telpon:");
            scanf("%[^\n]%*c", &input);
            strcpy(mahasiswa[jumlah].no_telpon, input);

            printf("\nMasukkan alamat email:");
            scanf("%[^\n]%*c", &input);
            strcpy(mahasiswa[jumlah].alamat_email, input);
            jumlah++;
        }
        else if (jawaban == 3)
        {
            break;
        }
    }
    return 0;
}
