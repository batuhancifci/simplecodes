#include <cstdlib>
#include <iostream>
#include <string.h>

#define dosya "rehber.txt"
/*
Telefon rehberi uygulamasý
taslak hali


Ana Menü
Kayýt Ekleme
Kayýt Silme (alt menüsü var)
Sýralama
Düzenleme
Çýkýþ 
Kayýt Sýfýrlama 

Silme menüsü
Ýsme göre silme
Soyisme göre silme
Numaraya göre silme
Kayýt numarasýna göre silme
*/


void AnaMenu();
void KayitSilme();

void KayitEkleme();
void KayitSiralama();
void Cikis();
void KayitSifirlama();
//void KayitDuzenleme();

void SilmeIsim();
void SilmeSoyisim();
void SilmeNumara();
void SilmeKayitNo();


using namespace std;

int main(int argc, char *argv[])
{
        FILE *fptr;
    if ( (fptr=fopen(dosya,"r")) =='\0')
    {
        cout<<"\n\n\t\tDosyaniz bulunamadi";
        cout<<"\n\n\t\tYeniden Olusturuluyor...\n";
        fptr=fopen (dosya, "w");
        system ("PAUSE");    
    }
    
    fclose(fptr);
    AnaMenu(); 
    system ("PAUSE");
    return EXIT_SUCCESS;
}

void AnaMenu(){
    int tercih;
    system ("CLS");
    cout<<"\t\t\t\tTELEFON REHBERI"<<endl;
    cout<<"\n\t\t\tANA MENU"<<endl;
    cout<<"\t\t1- Kayit Ekleme"<<endl;
    cout<<"\t\t2- Kayit Silme"<<endl;
    cout<<"\t\t3- Kayit Sýralama"<<endl;
    cout<<"\t\t4- Kayit Düzenleme"<<endl;
    cout<<"\t\t5- CIKIS"<<endl;
    cout<<"\t\t6- Kayit Bilgilerni Sifirlama"<<endl;
    
    cout<<"\n\t\t\tTercihiniz: ";
    cin>>tercih;
    
    switch (tercih){
        case 1:
            KayitEkleme();
            break;
        case 2:
            KayitSilme();
            break;
        case 3:
            KayitSiralama();
            break;
  /*      case 4:
            KayitDuzenleme();
            break;
 */     case 5:
            Cikis();
            break;
        case 6:
            KayitSifirlama();
            break;
        default:
            cout<<"Hatali Giris Yaptiniz"<<endl;
            system ("PAUSE");
            AnaMenu();
            break;    
    }
}

void KayitEkleme(){
    char isim[0], soyisim[0], numara1[0], numara2[0], numara3[0], fax[0], eposta[0], webAdres[0], adres[50];
    system ("CLS");
    cout<<"\t\tTELEFON REHBERI"<<endl;
    cout<<"\n\t\tKAYIT EKLEME"<<endl;
    cout<<"\n\t\tGiris bilgilerinizde Bosluk Karakteri Kullanmayiniz!"<<endl;
    cout<<"\n\t\tIsim: ";
    cin>>isim;
    cout<<"\n\t\tSoyisim: ";
    cin>>soyisim;
    cout<<"\n\t\t1. Numara: ";
    cin>>numara1;
    cout<<"\n\t\t2. Numara: ";
    cin>>numara2;
    cout<<"\n\t\t3. Numara: ";
    cin>>numara3;
    cout<<"\n\t\tFax: ";
    cin>>fax;
    cout<<"\n\t\tE-posta: ";
    cin>>eposta;
    cout<<"\n\t\tWeb Adres: ";
    cin>>webAdres;
    cout<<"\n\t\tAdres: ";
    cin>>adres;
    int kayit_no=1;
    FILE *fptr;
    if ( (fptr=fopen(dosya,"r+")) =='\0'){
        cout<<"\n\n\t\tDosya Acilamadi!!";
        system ("PAUSE");
        AnaMenu();
    }else{
        char okunan1[0], okunan2[0], okunan3[0], okunan4[0], okunan5[0], okunan6[0], okunan7[0], okunan8[0], okunan9[0];
        fseek (fptr,0,0);
        while (!feof(fptr)){
            fscanf(fptr,"%s %s %s %s %s %s %s %s %s\n",okunan1, okunan2, okunan3, okunan4, okunan5, okunan6, okunan7, okunan8, okunan9);
            if ( strlen(okunan1)!=0 ){
                kayit_no++;
            }
        }
        cout<<"\n\n\t\tKayýt No: "<<kayit_no;
        fseek (fptr,0,2);
        fprintf (fptr,"%d %s %s %s %s %s %s %s %s %s\n",kayit_no, isim, soyisim, numara1, numara1, numara3, fax, eposta, webAdres, adres);
        fclose (fptr);
        cout<<"\n\n\t\tKaydiniz Basariyla Eklenmistir!\n\n";
        system ("PAUSE");
        AnaMenu();
    }
}

void KayitSilme(){
    int tercih;
    system ("CLS");
    cout<<"\t\tTELEFON REHBERI"<<endl;
    cout<<"\n\t\tSILME MENUSU"<<endl;
    cout<<"\t\t1- Isme Gore Silme"<<endl;
    cout<<"\t\t2- Soyisme Gore Silme"<<endl;
    cout<<"\t\t3- Numaraya Gore Silme"<<endl;
    cout<<"\t\t4- Kayit Numarasina Gore Silme"<<endl;
    cout<<"\t\t5- Ana Menuye Donus"<<endl;
    cout<<"\t\t6- CIKIS"<<endl;
    
    cout<<"\n\t\t\tTercihiniz: ";
    cin>>tercih;
    switch (tercih){
        case 1:
            SilmeIsim();
            break;
        case 2:
            SilmeSoyisim();
            break;
        case 3:
            SilmeNumara();
            break;
        case 4:
            SilmeKayitNo();
            break;
        case 5:
            AnaMenu();
            break;
        case 6:
            Cikis();
            break;
        default:
            cout<<"Hatali Giris Yaptiniz"<<endl;
            system ("PAUSE");
            KayitSilme();
            break;       
    }
}

void SilmeIsim(){
    char isim[0];
    system ("CLS");
   
    cout<<"\t\tTELEFON REHBERI"<<endl;
    cout<<"\n\t\tISME GORE KAYIT SILME"<<endl;
    cout<<"\n\t\tGiris bilgilerinizde Bosluk Karakteri Kullanmayiniz!"<<endl;
    cout<<"\n\t\tIsim: ";
    cin>>isim;
    FILE *fptr;
    bool isKayit=true;
    if ( (fptr=fopen(dosya,"r+")) =='\0'){
        cout<<"\n\n\t\tDosya Acilamadi!!";
        system ("PAUSE");
        AnaMenu();
    }else{
        char okunan1[0], okunan2[0], okunan3[0], okunan4[0];
        fseek (fptr,0,0);
        while (!feof(fptr)){
            fscanf (fptr,"%s %s %s %s\n",okunan1,okunan2,okunan3,okunan4);
            if( (!strcmp(isim,okunan2)) && (strcmp(okunan1,"#")) ){
                cout<<"Kayit Numarasi   : "<<okunan1<<endl;
                cout<<"Isim             : "<<okunan2<<endl;
                cout<<"Soyisim          : "<<okunan3<<endl;
                cout<<"Telefon Numarasý : "<<okunan4<<endl;
                cout<<"-----------------"<<endl;
                isKayit=false;
            }
        }
        if (isKayit){
            cout<<"\n\n\t\tAradiginiz isme dair kayit bilgisi bulunamamistir\n";
            cout<<"\n\n\t\tLutfen arama kelimenizde bosluk karakteri kullanmayiniz\n\n";
            fclose(fptr);
            system ("PAUSE");
            SilmeIsim();
        }else{
            char kayit_no[0];
            cout<<"\n\n\t\tSilmek istediginiz kaydin numarasini girin: ";
            cin>>kayit_no;
            fseek(fptr,0,0);
            while (!feof(fptr)){
                fscanf (fptr,"%s %s %s %s\n",okunan1,okunan2,okunan3,okunan4);
                if ( !strcmp(kayit_no,okunan1) ){
                    int n;
                    n=strlen(okunan4)+strlen(okunan3)+strlen(okunan2)+strlen(okunan1)+5;
                    fseek(fptr,-n,1);
                    switch (strlen (okunan1)){
                        case 1:
                            fprintf (fptr,"#");
                            break;
                        case 2:
                            fprintf (fptr,"# ");
                            break;
                        case 3:
                            fprintf (fptr,"#  ");
                            break;
                        case 4:
                            fprintf (fptr,"#   ");
                            break;
                    }
                    break;
                }
            }
            fclose (fptr);
            system ("PAUSE");
            AnaMenu();    
        }
    }   
}
void SilmeSoyisim(){
    char isim[0];
    system ("CLS");
   
    cout<<"\t\tTELEFON REHBERI"<<endl;
    cout<<"\n\t\tSOYISME GORE KAYIT SILME"<<endl;
    cout<<"\n\t\tGiris bilgilerinizde Bosluk Karakteri Kullanmayiniz!"<<endl;
    cout<<"\n\t\tSoyisim: ";
    cin>>isim;
    FILE *fptr;
    bool isKayit=true;
    if ( (fptr=fopen(dosya,"r+")) =='\0'){
        cout<<"\n\n\t\tDosya Acilamadi!!";
        system ("PAUSE");
        AnaMenu();
    }else{
        char okunan1[0], okunan2[0], okunan3[0], okunan4[0];
        fseek (fptr,0,0);
        while (!feof(fptr)){
            fscanf (fptr,"%s %s %s %s\n",okunan1,okunan2,okunan3,okunan4);
            if( (!strcmp(isim,okunan3)) && (strcmp(okunan1,"#")) ){
                cout<<"Kayit Numarasi   : "<<okunan1<<endl;
                cout<<"Isim             : "<<okunan2<<endl;
                cout<<"Soyisim          : "<<okunan3<<endl;
                cout<<"Telefon Numarasý : "<<okunan4<<endl;
                cout<<"-----------------"<<endl;
                isKayit=false;
            }
        }
        if (isKayit){
            cout<<"\n\n\t\tAradiginiz soyisme dair kayit bilgisi bulunamamistir\n";
            cout<<"\n\n\t\tLutfen arama kelimenizde bosluk karakteri kullanmayiniz\n\n";
            fclose(fptr);
            system ("PAUSE");
            SilmeSoyisim();
        }else{
            char kayit_no[0];
            cout<<"\n\n\t\tSilmek istediginiz kaydin numarasini girin: ";
            cin>>kayit_no;
            fseek(fptr,0,0);
            while (!feof(fptr)){
                fscanf (fptr,"%s %s %s %s\n",okunan1,okunan2,okunan3,okunan4);
                if ( !strcmp(kayit_no,okunan1) ){
                    int n;
                    n=strlen(okunan4)+strlen(okunan3)+strlen(okunan2)+strlen(okunan1)+5;
                    fseek(fptr,-n,1);
                    switch (strlen (okunan1)){
                        case 1:
                            fprintf (fptr,"#");
                            break;
                        case 2:
                            fprintf (fptr,"# ");
                            break;
                        case 3:
                            fprintf (fptr,"#  ");
                            break;
                        case 4:
                            fprintf (fptr,"#   ");
                            break;
                    }
                    break;
                }
            }
            fclose (fptr);
            system ("PAUSE");
            AnaMenu();    
        }
    } 
}
void SilmeNumara(){
    char isim[0];
    system ("CLS");
   
    cout<<"\t\tTELEFON REHBERI"<<endl;
    cout<<"\n\t\tNUMARAYA GORE KAYIT SILME"<<endl;
    cout<<"\n\t\tGiris bilgilerinizde Bosluk Karakteri Kullanmayiniz!"<<endl;
    cout<<"\n\t\tNumara: ";
    cin>>isim;
    FILE *fptr;
    bool isKayit=true;
    if ( (fptr=fopen(dosya,"r+")) =='\0'){
        cout<<"\n\n\t\tDosya Acilamadi!!";
        system ("PAUSE");
        AnaMenu();
    }else{
        char okunan1[0], okunan2[0], okunan3[0], okunan4[0];
        fseek (fptr,0,0);
        while (!feof(fptr)){
            fscanf (fptr,"%s %s %s %s\n",okunan1,okunan2,okunan3,okunan4);
            if( (!strcmp(isim,okunan4)) && (strcmp(okunan1,"#")) ){
                cout<<"Kayit Numarasi   : "<<okunan1<<endl;
                cout<<"Isim             : "<<okunan2<<endl;
                cout<<"Soyisim          : "<<okunan3<<endl;
                cout<<"Telefon Numarasý : "<<okunan4<<endl;
                cout<<"-----------------"<<endl;
                isKayit=false;
            }
        }
        if (isKayit){
            cout<<"\n\n\t\tAradiginiz numaraya dair kayit bilgisi bulunamamistir\n";
            cout<<"\n\n\t\tLutfen arama kelimenizde bosluk karakteri kullanmayiniz\n\n";
            fclose(fptr);
            system ("PAUSE");
            SilmeNumara();
        }else{
            char kayit_no[0];
            cout<<"\n\n\t\tSilmek istediginiz kaydin numarasini girin: ";
            cin>>kayit_no;
            fseek(fptr,0,0);
            while (!feof(fptr)){
                fscanf (fptr,"%s %s %s %s\n",okunan1,okunan2,okunan3,okunan4);
                if ( !strcmp(kayit_no,okunan1) ){
                    int n;
                    n=strlen(okunan4)+strlen(okunan3)+strlen(okunan2)+strlen(okunan1)+5;
                    fseek(fptr,-n,1);
                    switch (strlen (okunan1)){
                        case 1:
                            fprintf (fptr,"#");
                            break;
                        case 2:
                            fprintf (fptr,"# ");
                            break;
                        case 3:
                            fprintf (fptr,"#  ");
                            break;
                        case 4:
                            fprintf (fptr,"#   ");
                            break;
                    }
                    break;
                }
            }
            fclose (fptr);
            system ("PAUSE");
            AnaMenu();    
        }
    }    
}
void SilmeKayitNo(){
    char isim[0];
    system ("CLS");
   
    cout<<"\t\tTELEFON REHBERI"<<endl;
    cout<<"\n\t\tKAYIT NUMARASINA GORE KAYIT SILME"<<endl;
    cout<<"\n\t\tGiris bilgilerinizde Bosluk Karakteri Kullanmayiniz!"<<endl;
    cout<<"\n\t\tKayit Numarasi: ";
    cin>>isim;
    FILE *fptr;
    bool isKayit=true;
    if ( (fptr=fopen(dosya,"r+")) =='\0'){
        cout<<"\n\n\t\tDosya Acilamadi!!";
        system ("PAUSE");
        AnaMenu();
    }else{
        char okunan1[0], okunan2[0], okunan3[0], okunan4[0];
        fseek (fptr,0,0);
        while (!feof(fptr)){
            fscanf (fptr,"%s %s %s %s\n",okunan1,okunan2,okunan3,okunan4);
            if( (!strcmp(isim,okunan1)) && (strcmp(okunan1,"#")) ){
                cout<<"Kayit Numarasi   : "<<okunan1<<endl;
                cout<<"Isim             : "<<okunan2<<endl;
                cout<<"Soyisim          : "<<okunan3<<endl;
                cout<<"Telefon Numarasý : "<<okunan4<<endl;
                cout<<"-----------------"<<endl;
                isKayit=false;
            }
        }
        if (isKayit){
            cout<<"\n\n\t\tAradiginiz kayit numarasina dair kayit bilgisi bulunamamistir\n";
            cout<<"\n\n\t\tLutfen arama kelimenizde bosluk karakteri kullanmayiniz\n\n";
            fclose(fptr);
            system ("PAUSE");
            SilmeKayitNo();
        }else{
            char tercih;
            cout<<"\n\n\t\t: Silmek icin 'e' harfine basiniz: ";
            cin>>tercih;
            if (tercih=='e'){
                fseek(fptr,0,0);
                while (!feof(fptr)){
                    fscanf (fptr,"%s %s %s %s\n",okunan1,okunan2,okunan3,okunan4);
                 if ( !strcmp(isim,okunan1) ){
                        int n;
                        n=strlen(okunan4)+strlen(okunan3)+strlen(okunan2)+strlen(okunan1)+5;
                        fseek(fptr,-n,1);
                        switch (strlen (okunan1)){
                            case 1:
                                fprintf (fptr,"#");
                                break;
                            case 2:
                                fprintf (fptr,"# ");
                                break;
                            case 3:
                                fprintf (fptr,"#  ");
                                break;
                            case 4:
                                fprintf (fptr,"#   ");
                                break;
                        }
                        break;
                    }
                }
            }
            fclose (fptr);
            system ("PAUSE");
            AnaMenu();    
        }
    }
}

void KayitSiralama(){
    FILE *fptr;
    system ("CLS");
    char kayit[0], isim[0], soyisim[0], numara1[0], numara2[0], numara3[0], fax[0], eposta[0], webAdres[0], adres[50];
    cout<<"\t\tTELEFON REHBERI"<<endl;
    cout<<"\n\t\tKAYIT LISTESI"<<endl;
    if ( (fptr=fopen (dosya, "r"))=='\0' ){
        cout<<"\n\n\t\tDosya Acilamadi!\n";
        system ("PAUSE");
        AnaMenu();    
    }else{
        fseek (fptr,0,0);
        cout<<"\n\n";
        while (!feof(fptr)){
            fscanf (fptr, "%s %s %s %s %s %s %s %s %s %s \n",kayit, isim, soyisim, numara1, numara2, numara3, fax, eposta, webAdres, adres);
            if (strcmp(kayit,"#")){
                cout<<"Kayit Numarasi      : "<<kayit<<endl;
                cout<<"Isim                : "<<isim<<endl;
                cout<<"Soyisim             : "<<soyisim<<endl;
                cout<<"1. Telefon Numarasi : "<<numara1<<endl;
                cout<<"2. Telefon Numarasi : "<<numara2<<endl;
                cout<<"3. Telefon Numarasi : "<<numara3<<endl;
                cout<<"Fax                 : "<<fax<<endl;
                cout<<"E-posta             : "<<eposta<<endl;
                cout<<"Web Adres           : "<<webAdres<<endl;
                cout<<"Adres               : "<<adres<<endl;
                cout<<"-----------"<<endl;
            }
        }
        system ("PAUSE");
        AnaMenu();
    }
}

void Cikis(){

    char tercih;
    system ("CLS");
    cout<<"\n\n\t\tEmin misiniz ? (e/h):";
    cin>>tercih;
    
    if (tercih=='e'||tercih=='E'){
        system ("CLS");
        cout<<"\n\n\t\tGule Gule!\n";
    }else if (tercih=='h'||tercih=='H')
        AnaMenu();
    else{
        cout<<"\n\n\t\tHatali Giris Yaptiniz!\n";
        system ("PAUSE");
        Cikis();
    }  
}

void KayitSifirlama(){
    char tercih;
    system ("CLS");
    cout<<"\n\n\t\tEmin misiniz ? (e/h):";
    cin>>tercih;
    
    if (tercih=='e'||tercih=='E'){
        system ("CLS");
        FILE *fptr;
        if ((fptr=fopen (dosya,"w")) != '\0' ){
            cout<<"\n\n\t\tDosyaniz Yeniden Olusturuldu!\n";    
            fclose(fptr);
        }else{
            cout<<"\n\n\t\tHata Olustu!\n";    
        }
        system ("PAUSE");
        AnaMenu();
    }else if (tercih=='h'||tercih=='H')
        AnaMenu();
    else{
        cout<<"\n\n\t\tHatali Giris Yaptiniz!\n";
        system ("PAUSE");
        KayitSifirlama();
    }
}  
