/****************************************************************************
**                          SAKARYA ÜNÝVERSÝTESÝ
**                  BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**                      BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**                        PROGRAMLAMAYA GÝRÝÞ DERSÝ
**
**                  ÖDEV NUMARASI   : 1
**                  ÖÐRENCÝ ADI     : ZEYNEP ULUDAÐ
**                  ÖÐRENCÝ NUMARASI: B241210029
**                  DERS GRUBU      : 1-A
****************************************************************************/


#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

struct Ogrenci {
    string adiSoyadi;
    int yasi;
    long long telefonu;
    string sehir;
    string dersAdi;
    int odev1_not, odev2_not, proje_not, vize_not, final_not;

    string basariNotu;
    double toplamNotu;

    double YiliciHesapla(double odev1Yuzde, double odev2Yuzde, double projeYuzde, double vizeYuzde) { // yilici agirliklari hesaplaniyor.
        return odev1_not * odev1Yuzde +
            odev2_not * odev2Yuzde +
            proje_not * projeYuzde +
            vize_not * vizeYuzde;
    }

    void BasariNotu(double yilici, double finalYuzde) { // yiliici agirligina finali de ekleyip basarinotu hesaplaniyor.
        double finalNotu = final_not * finalYuzde;
        toplamNotu = yilici + finalNotu;

        string harf;
        if (toplamNotu >= 90) harf = "AA";
        else if (toplamNotu >= 85) harf = "BA";
        else if (toplamNotu >= 80) harf = "BB";
        else if (toplamNotu >= 75) harf = "CB";
        else if (toplamNotu >= 65) harf = "CC";
        else if (toplamNotu >= 58) harf = "DC";
        else if (toplamNotu >= 50) harf = "DD";
        else if (toplamNotu >= 40) harf = "FD";
        else harf = "FF";

        basariNotu = to_string((int)toplamNotu) + " " + harf; // ornegin "65 CC"
    }
};

int main() {
    srand(time(NULL));

    Ogrenci ogrenciler[100]; // yuz ogrencilik bir sinif olusturuluyor

    string isimler[30] = {
        "Ahmet","Mehmet","Ayse","Fatma","Emre","Elif","Can","Deniz","Murat","Cem",
        "Ece","Ali","Hakan","Selin","Zeynep","Burak","Ersin","Seda","Baris","Mina",
        "Omer","Derya","Yusuf","Melis","Tuna","Sinem","Kaan","Hande","Onur","Irem"
    };

    string soyisimler[30] = {
        "Yilmaz","Kaya","Demir","Celik","Sahin","Erdem","Yalcin","Ozkan","Tas","Duman",
        "Aktepe","Gungor","Karaca","Sezer","Uzun","Kurt","Ari","Tan","Ergin","Basar",
        "Ozdemir","Arslan","Kaplan","Yildirim","Polat","Acar","Gokce","Kilic","Soylu","Bostan"
    };

    string sehirler[10] = { "Sakarya","Kocaeli","Istanbul","Ankara","Izmir","Trabzon","Bursa","Samsun","Antalya","Eskisehir" };

    for (int i = 0; i < 100; i++) {

        bool tekrarVar;
        string yeniAdiSoyadi;

        do {
            tekrarVar = false;
            int isimIndex = rand() % 30;
            int soyisimIndex = rand() % 30;
            yeniAdiSoyadi = isimler[isimIndex] + " " + soyisimler[soyisimIndex];

            for (int j = 0; j < i; j++) {
                if (ogrenciler[j].adiSoyadi == yeniAdiSoyadi) { // ayni isim soyisimden iki ogrenci olmamasi kontrolu
                    tekrarVar = true;
                    break;
                }
            }

        } while (tekrarVar);

        ogrenciler[i].adiSoyadi = yeniAdiSoyadi; // ogrencilere isim soyisim ataniyor

        long long telefon;
        do {
            tekrarVar = false;
            telefon = 5000000000LL + rand() % 1000000000LL;

            for (int j = 0; j < i; j++) {
                if (ogrenciler[j].telefonu == telefon) { // ayni telefon numarasindan iki tane olmamasi kontrolu
                    tekrarVar = true;
                    break;
                }
            }
        } while (tekrarVar);

        ogrenciler[i].telefonu = telefon;

        ogrenciler[i].yasi = 18 + rand() % 8;
        ogrenciler[i].sehir = sehirler[rand() % 10];
        ogrenciler[i].dersAdi = "Programlamaya Giris";

        ogrenciler[i].odev1_not = rand() % 101;
        ogrenciler[i].odev2_not = rand() % 101;
        ogrenciler[i].proje_not = rand() % 101;
        ogrenciler[i].vize_not = rand() % 101;
        ogrenciler[i].final_not = rand() % 101;

        double yilici = ogrenciler[i].YiliciHesapla(0.10, 0.10, 0.30, 0.50);
        ogrenciler[i].BasariNotu(yilici, 0.40);
    }

    double toplam = 0;
    for (int i = 0; i < 100; i++)
        toplam += ogrenciler[i].toplamNotu;

    double ortalama = toplam / 100;

    double varyans = 0;
    for (int i = 0; i < 100; i++)
        varyans += pow(ogrenciler[i].toplamNotu - ortalama, 2);

    double stdSapma = sqrt(varyans / 100);

    int harfSay[9] = { 0 }; // AA, BA, BB, CB, CC, DC, DD, FD, FF olmak uzere 9 tane
    for (int i = 0; i < 100; i++) {
        string b = ogrenciler[i].basariNotu;
        if (b.size() >= 2) { // son iki karakterdeki harf kodunu alacak
            string h = b.substr(b.size() - 2);
            if (h == "AA") harfSay[0]++;
            else if (h == "BA") harfSay[1]++;
            else if (h == "BB") harfSay[2]++;
            else if (h == "CB") harfSay[3]++;
            else if (h == "CC") harfSay[4]++;
            else if (h == "DC") harfSay[5]++;
            else if (h == "DD") harfSay[6]++;
            else if (h == "FD") harfSay[7]++;
            else if (h == "FF") harfSay[8]++;
        }
    }

    string harfler[9] = { "AA","BA","BB","CB","CC","DC","DD","FD","FF" };

    cout << "-------------- PROGRAMLAMAYA GIRIS --------------" << endl;

    cout << "Sinif ortalamasi: " << ortalama << endl;
    cout << "Standart Sapma: " << stdSapma << endl;

    cout << "Harf Notu Yuzdelik Oranlari: " << endl;
    for (int i = 0; i < 9; i++) {
        cout << harfler[i] << " : " << harfSay[i] << "%" << endl;
    }

    return 0;
}