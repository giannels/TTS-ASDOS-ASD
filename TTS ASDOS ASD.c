#include <stdio.h>
#include <conio.h>
#include <windows.h>


int i = 0;
int index_kamar = 0;
int vip = 5;
int login_ = 0;

struct data_login {
    char id[100];
    char pw[100];
} data_login[100];

struct kamar {
    char nama[100];
    int hari;
} kamar[100];

int main()
{
    int pilihan1, pilihan2;
    if(login_ == 0){
    pilihan1 = regist();
    switch(pilihan1){
        case 1: regtistrasi();
                break;
        case 2: login();
                login_ = 1;
                break;
        }
    }
    pilihan2 = reservasi();
    switch(pilihan2){
        case 1: VIP();
                break;
    }
}

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void panah(int posisiMenu, int posisiPanah){
    if (posisiMenu == posisiPanah)
        printf("==>");
    else
        printf("   ");
}

int reservasi(){
    system("cls");
    int posisi = 1;
    int keyPressed = 0;
    while (keyPressed != 27){
        gotoxy(20,0);
        printf("|=====================|");
        gotoxy(20,1);
        printf("|   Reservasi Kamar   |");
        gotoxy(20,3);
        printf("|=====================|");
        gotoxy(20,5);
        panah(1, posisi);
        printf("1. VIP");
        gotoxy(20,7);
        panah(2, posisi);
        printf("2. Double Bed");
        gotoxy(20,9);
        panah(3, posisi);
        printf("3. Single Bed");
        gotoxy(20,11);
        panah(4, posisi);
        printf("4. Kembali Ke Menu");


        keyPressed = getch();

        if (keyPressed == 72)
        {
            posisi--;
        }
        else if (keyPressed == 80)
        {
            posisi++;
        }
        else if (keyPressed == 13)
        {
            return posisi;
        }
        if (posisi < 1)
        {
            posisi = 4;
        }
        else if (posisi > 4)
        {
            posisi = 1;
        }

    }

}

int regist(){
    system("cls");
    int posisi= 1;
    int keyPressed = 0;
    while (keyPressed != 27){
        gotoxy(20,1);
        printf("=====================");
        gotoxy(20,3);
        printf("   Register & Login  ");
        gotoxy(20,5);
        printf("=====================");
        gotoxy(20,7);
        panah(1, posisi);
        printf("1. Register");
        gotoxy(20,9);
        panah(2, posisi);
        printf("2. Login");
        gotoxy(20,11);
        printf("=====================");

        keyPressed = getch();
        if (keyPressed == 72){
            posisi--;
        } else if (keyPressed == 80) {
            posisi++;
        } else if(keyPressed == 13){
            return posisi;
        }
        if(posisi < 1) {
            posisi = 2;
        } else if(posisi > 2) {
            posisi = 1;
        }
    }
}

void regtistrasi(){
    system("cls");
    printf("Masukan ID Anda :");
    scanf("%s", &data_login[i].id);
    printf("Masukan Password Anda :");
    scanf("%s", &data_login[i].pw);
    i++;
    main();
}

int login(){
    system("cls");
    char id[100];
    char pw[100];
    printf("Masukan ID Anda :");
    scanf("%s", &id);
    printf("Masukan Password Anda :");
    scanf("%s", &pw);
        for(int j = 0; j < i; j++){
            if(strcmp(pw,data_login[j].pw)== 0 &&strcmp(id,data_login[j].id)== 0){
                system("cls");
                printf("Berasil Login");
                Sleep(1000);
                return 0;
            }
        }
    system("cls");
    printf("ID & Password Salah!");
    Sleep(1000);
    return main();
}

int VIP(){
    system("cls");
    int j;
    char menu;
    printf("Sisa Kamar : %i", vip);
    printf("\nJumlah Pesan Kamar :");
    scanf("%i", &j);
        if (j>vip) {
            printf("Jumlah Kamar Sisa %i", vip);
            Sleep(1000);
            printf("\nTekan y Untuk Kembali Ke Reservasi\n");
            printf("Tekan n Untuk Kembali Ke Pemesanan");
            menu = getch();
                if(menu == 'y') {
                    return main();
                } else if(menu == 'n') {
                    return VIP();
                } else {
                    printf("\nInputan Tidak Valid!");
                }

        } else {
            for(int n = 0; n < j; n++){
                system("cls");
                printf("Masukan Nama :");
                scanf("%s", &kamar[index_kamar].nama);
                printf("Menginap Selama :");
                scanf("%i", &kamar[index_kamar].hari);
                vip--;
                index_kamar++;

            }
        }

}
