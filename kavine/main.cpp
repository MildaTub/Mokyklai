#include <iostream>
#include <fstream>

using namespace std;

//STRUKTURA

struct kavine
{
    string kavinesPavadinimas;
    int patiekaloKaina;
};

//NUSKAITYMAS

void skaitymas(kavine M[], int &patiekaluKiekis)
{
    setlocale(LC_ALL, "Lithuanian");

    ifstream duom("C:\\Users\\MT\\Desktop\\INFORMATIKA\\kavine\\kava.txt"); //NEPAMIRSKIT PAKEISTI ADRESO
    duom>>patiekaluKiekis;
    duom.ignore(80,'\n');

    char simboliai[24]; //DARIAU PAGAL KITUS DUOMENIS (PAKEISKIT I 17 SIMBOLIU)

    for(int i=0; i<patiekaluKiekis; i++)
    {
        duom.get(simboliai,24); //PATIKRINKITE SIMBOLIUS, NES DARIAU PAGAL KITA TEXTINI FAILA
        M[i].kavinesPavadinimas=simboliai;
        duom>>M[i].patiekaloKaina;
        duom.ignore(80,'\n');
    }

    for(int i=0; i<patiekaluKiekis; i++)
    {
        cout<<M[i].kavinesPavadinimas<<" "<<M[i].patiekaloKaina<<endl;
    }
    cout<<endl;
}

//RIKIAVIMAS PAGAL KAINA

void rikiavimas(kavine M[],int prekiuSkaicius)
{
    kavine laikinas;
    cout<<"SURIKIUOTA: "<<endl;

    for(int i=0; i<prekiuSkaicius; i++)
    {
        for(int j=0; j<prekiuSkaicius-1; j++)
        {
            if(M[j].patiekaloKaina<M[j+1].patiekaloKaina)
            {
                laikinas=M[j];
                M[j]=M[j+1];
                M[j+1]=laikinas;
            }

        }

    }

    for(int i=0; i<prekiuSkaicius; i++)
    {
        cout<<M[i].kavinesPavadinimas<<" "<<M[i].patiekaloKaina<<endl;
    }

    cout<<endl;
}

//IESKOMA BENDRA PATIEKALU KAIMA (SUMA)

int sumavimas(kavine M[],int patiekaluSkaicius)
{
    int sudetis=0;
    for(int i=0; i<patiekaluSkaicius; i++)
    {
        sudetis+=M[i].patiekaloKaina;
    }
    cout<<"suma: "<<sudetis;
    return sudetis;
}

//ISVEDAMI REZULTATAI

void rezultatai(kavine M[], int patiekaluSkaicius, int sudetis)
{
    ofstream rez("C:\\Users\\MT\\Desktop\\INFORMATIKA\\kavine\\rezultatai.txt"); //NEPAMIRSKIT PAKEISTI ADRESO
    for(int i=0; i<patiekaluSkaicius; i++)
    {
        rez<<M[i].kavinesPavadinimas<<" "<<M[i].patiekaloKaina<<endl;

    }
    rez<<"suma: "<<sudetis;
}

//MAINAS

int main()
{
    kavine masyvas[100];
    int n,suma;

    skaitymas(masyvas,n);
    rikiavimas(masyvas,n);
    suma=sumavimas(masyvas,n);
    rezultatai(masyvas,n,suma);

    return 0;
}
