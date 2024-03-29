#include <stdio.h>

void sezarSifrele(char metin[], int kaydirma) {
    int i = 0;

    while (metin[i] != '\0') {
        //küçük harfi şifreleme
        if (metin[i] >= 'a' && metin[i] <= 'z') {
            metin[i] = 'a' + (metin[i] - 'a' + kaydirma) % 26; 
        }
        // Büyük harfi şifreleme
        else if (metin[i] >= 'A' && metin[i] <= 'Z') {
            metin[i] = 'A' + (metin[i] - 'A' + kaydirma) % 26;
        }
        //sayıları şifreleme
        else if(metin[i]>='0'&&metin[i]<='9') {
            metin[i]='0'+(metin[i]-'0'+kaydirma)%10;
        }
        i++;
    }
}

void sezarCoz(char sifreli[], int kaydir) {
    int j=0;

    while(sifreli[j]!='\0') {
        //küçük harfin şifresini çözme
        if(sifreli[j]>='a'&&sifreli[j]<='z') {
            sifreli[j]='z'+(sifreli[j]-'z'-kaydir)%26;
        }
        //büyük harfin şifresini çözme
        else if(sifreli[j]>='A'&&sifreli[j]<='Z') {
            sifreli[j]='Z'+(sifreli[j]-'Z'-kaydir)%26;
        }
        //sayıların şifresini çözme
        else if(sifreli[j]>='0'&&sifreli[j]<='9') {
            sifreli[j]='9'+(sifreli[j]-'9'-kaydir)%10;
        }
        
        j++;
    }
}

int main() {
    char metin[100];
    int kaydirma;
    char dosyaAdi[50];

    

    // Kullanıcıdan dosya adını alma
    printf("Dosya adini girin: ");
    scanf("%s", dosyaAdi);

    // Kullanıcı uyarısı
    printf("\n------------------------------------------------------");
    printf("\nNOT: Metin yalnizca dogal sayi ve harflerden olusmalidir!\n");
    printf("-------------------------------------------------------\n\n");

    // Kullanıcıdan metni ve kaydırma miktarı alma
    printf("Sifrelemek istediginiz metni giriniz--> ");
    scanf("%s", metin);
    printf("Sifre kaydirma miktarini giriniz--> ");
    scanf("%d", &kaydirma);

    // Dosyayı açma
    FILE *dosya = fopen(dosyaAdi, "w");
    if (dosya == NULL) {
        printf("Dosya acilamadi!\n");
        return 1;
    }
    
    // Şifreleyecek fonksiyonu çağırma ve dosyaya yazma
    sezarSifrele(metin, kaydirma);
    fprintf(dosya, "Sifrelenmis metin: %s\n", metin);

    //Şifre çözecek fonksiyonu çağırma ve dosyaya yazma
    sezarCoz(metin,kaydirma);
    fprintf(dosya, "Sifresi cozulmus metin: %s",metin);

    // Dosyayı kapatma
    fclose(dosya);

    printf("Sifrelenmis ve sifresi cozulmus metin dosyaya yazildi.\n");

    return 0;
}
