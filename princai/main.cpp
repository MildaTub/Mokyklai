#include <iostream>
#include <fstream>
using namespace std;

struct princai //STRUKTUROS APSKELBIMAS
{
    string princoVardas; //KINTAMASIS SAUGOTI PRINCO VARDO REIKSMEI
    int princoUgis; //KINTAMASIS SAUGOTI PRINCO UGIO REIKSMEI


};
void nuskaitymas(princai M[],int &princuKiekis) //ATIDARYMO IS FAILO FUNKCIJA
{

    ifstream duom("C:\\Users\\MT\\Desktop\\INFORMATIKA\\princai\\princas.txt"); //NUORODA I FAILO VIETA
    duom>>princuKiekis; //PAIMAMA PIRMA REIKSME IS FAILO T.Y PRINCU KIEKIS

    duom.ignore(80,'\n'); //SKIRTA, TAM, KAD NEBUTU GALIMA PAIMTI SEKANCIU DUOMENU
    char simboliai[26]; //APSISKELBIAME SIMBOLIU MASYVA

    for(int i=0;i<princuKiekis; i++) //CIKLO SALYGA
    {
        duom>>M[i].princoUgis; //IS DUOMENU FAILO IRASOME REIKSMES I SUKURTA MASYVA
        duom.get(simboliai,26); //IS DUOMENU FAILO GAUNAMI VISI ESANTYS SIMBOLIAI
        M[i].princoVardas=simboliai; //PRILYGINAME PRINCO VARO REIKSMES SIMBOLIU MASYVUI

        cout<<M[i].princoUgis<<M[i].princoVardas; //ISVEDAME I EKRANA GAUTUS REZULTATUS
        duom.ignore(80,'\n'); //IGNORUOJAME NEREIKALINGUS DUOMENIS
        cout<<endl;
    }

}
void rikiavimas(princai M[],int princuSkaicius)
{
    for(int i=0; i<princuSkaicius; i++)
    {
        for(int j=0; j<princuSkaicius-1; j++)
        {
            if(M[j].princoUgis>M[j+1].princoUgis)
            {
                princai laikinas;
                laikinas=M[j];
                M[j]=M[j+1];
                M[j+1]=laikinas;

            }

        }
        cout<<M[i].princoUgis<<" ";
    }

    cout<<endl<<M[4-1].princoVardas<<" <laimejo";

}
void irasymas(princai M[])
{
    ofstream rezult("C:\\Users\\MT\\Desktop\\INFORMATIKA\\princai\\rez.txt");
    rezult<<M[3].princoVardas<<" nugaletojas";

}
int main()
{   int princuSkaicius;
    princai masyvas[10];

    nuskaitymas(masyvas,princuSkaicius);
    rikiavimas(masyvas,princuSkaicius);
    irasymas(masyvas);
    return 0;
}
