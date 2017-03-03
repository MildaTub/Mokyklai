#include <iostream>
#include <fstream>
using namespace std;

//STRUKTURA
struct mokiniai
{
    string mokinioVardas;
    int korteles[10];
    int suma=0;
};

//SKAITYMAS IS FAILO
void atidaryk(mokiniai M[],int &mokiniuSkaicius, int &korteliuSkaicius)
{
    char simboliai[15];

    ifstream duom("C:\\Users\\MT\\Desktop\\INFORMATIKA\\4. darbsciausi mokiniai\\Duomenys.txt");
    duom>>mokiniuSkaicius>>korteliuSkaicius;
    duom.ignore(80,'\n');

    for(int i=0; i<mokiniuSkaicius; i++)
    {
        duom>>M[i].mokinioVardas;
        cout<<M[i].mokinioVardas<<" ";

        for(int j=0; j<korteliuSkaicius; j++)
        {
            duom>>M[i].korteles[j];
            cout<<M[i].korteles[j]<<" ";
        }

        cout<<endl;
    }

    cout<<endl;
}

//RIKIAVIMAS PAGAL ABECELE
void rikiuok(mokiniai M[], int mokiniuSkaicius, int korteliuKiekis)
{
    for(int i=0; i<mokiniuSkaicius; i++)
    {
        for(int j=0; j<mokiniuSkaicius-1; j++)
        {
            if(M[j].mokinioVardas>M[j+1].mokinioVardas)
            {
                mokiniai laikinas;
                laikinas=M[j];
                M[j]=M[j+1];
                M[j+1]=laikinas;

            }

        }

    }

    for(int i=0; i<mokiniuSkaicius; i++)
    {
        cout<<M[i].mokinioVardas<<" ";
        for(int j=0; j<korteliuKiekis; j++)
        {
            cout<<M[i].korteles[j]<<" ";

        }
        cout<<endl;
    }

    cout<<endl;
}

void sumuok(mokiniai M[], int mokiniuSkaicius, int korteliuSkaicius)
{   int suma;

    for(int i=0; i<mokiniuSkaicius; i++)
    {
        for(int j=0; j<korteliuSkaicius; j++)
        {
            M[i].suma+=M[i].korteles[j];

        }
        cout<<M[i].mokinioVardas<<" "<<M[i].suma<<endl;
    }

}

//REZULTATU ISVEDIMIAS
void rezultatai(mokiniai M[], int mokiniuSkaicius, int korteliuKiekis)
{
    ofstream rezult("C:\\Users\\MT\\Desktop\\INFORMATIKA\\4. darbsciausi mokiniai\\Rezultatai.txt");
    for(int i=0; i<mokiniuSkaicius; i++)
    {
        rezult<<M[i].mokinioVardas<<" ";
        for(int j=0; j<korteliuKiekis; j++)
        {
            rezult<<M[i].korteles[j]<<" ";

        }
        rezult<<endl;
    }

    rezult<<endl;
    for(int i=0; i<mokiniuSkaicius; i++)
    {
        rezult<<M[i].mokinioVardas<<" "<<M[i].suma<<endl;
    }
}

int main()
{
    mokiniai masyvas[100];
    int n,k,suma;

    atidaryk(masyvas,n,k);
    rikiuok(masyvas,n,k);
    sumuok(masyvas,n,k);
    rezultatai(masyvas,n,k);
    return 0;
}
