
#include <stdio.h>
#include <stdlib.h>


int bakiye = 0;
char ad[50];
char soyad[50];
int ekleme = 0;
int durumNo, ogrenciDurumu = 0;

void kayit() {
    

    printf("Lutfen adinizi giriniz: ");
    scanf("%s", ad);

    printf("Lutfen soyadinizi giriniz: ");
    scanf("%s", soyad);
}

void bakiyeYukle() {
    printf("Mevcut bakiyeniz: %d TL\n", bakiye);
    printf("Lutfen yuklemek istediginiz degeri giriniz: ");
    scanf("%d", &ekleme);

    bakiye += ekleme;

    printf("Yeni bakiyeniz: %d TL\n", bakiye);
}

void durumGuncelleme() {
    printf("Ogrenci iseniz 1, sivil iseniz 2, emekli iseniz 3 tusuna basiniz: ");
    scanf("%d", &durumNo);

    switch (durumNo) {
    case 1:
        printf("Universitede ogrenci iseniz 1, degil iseniz 0 tusuna basiniz: ");
        scanf("%d", &ogrenciDurumu);

        if (ogrenciDurumu == 1)
            printf("Universitede ogrencisiniz ve odemeniz gereken ucret 6 TL'dir\n");
        else
            printf("Universitede ogrenci degilsiniz ve odemeniz gereken ucret 6 TL'dir\n");
        break;
    case 2:
        printf("Sivilsiniz ve odemeniz gereken ucret 10 TL'dir\n");
        break;
    case 3:
        printf("Emeklisiniz ve ucret odemenize gerek yok\n");
        break;
    default:
        printf("Yanlis bir deger girdiniz\n");
        break;
    }
}

void bilgileriGoster() {
    printf("Adiniz: %s\nSoyadiniz: %s\nDurumunuz:\n(1=OGRENCI\n2=SIVIL\n3=EMEKLI) %d\nMevcut Bakiyeniz: %d TL\n", ad, soyad, ogrenciDurumu, bakiye);
}

int main() {
    while (1) {
        int secim = 0;

        printf("\nLutfen bir secim yapiniz:\n");
        printf("1. Kayit yapmak icin\n");
        printf("2. Bakiye yuklemek icin\n");
        printf("3. Durum guncellemek icin\n");
        printf("4. Mevcut bilgileri gormek icin\n");
        printf("Seciminizi giriniz: ");
        scanf("%d", &secim);

        switch (secim) {
        case 1:
            printf("Kayit olma islemini sectiniz\n");
            kayit();
            break;
        case 2:
            printf("Bakiye yukleme islemini sectiniz\n");
            bakiyeYukle();
            break;
        case 3:
            printf("Durum guncelleme islemini sectiniz\n");
            durumGuncelleme();
            break;
        case 4:
            printf("Mevcut bilgileri gorme islemini sectiniz\n");
            bilgileriGoster();
            break;
        default:
            printf("Gecersiz bir sayi sectiniz\n");
            break;
        }
    }

    return 0;
}

