#include <iostream>
#include <fstream>
#include<time.h>
using namespace std;
void suformuokData(int valandos, int minutes);
//STRUKTURA
struct studentai
{
    string marsrutoPavadinimas;
    int valandos[100];
    int minutes[100];
    int konvertuotiMinutem[100];
    int laikoSkirtumas[100];
    int galutinesValandos;
    int galutinesMinutes;
};

//SKAITYMAS
void skaityk(studentai M[],int &marsrutuSkaicius)
{
    ifstream duom("C:\\Users\\MT\\Desktop\\INFORMATIKA\\1.Studentai\\Duomenys.txt");
    duom>>marsrutuSkaicius;

    for(int i=0; i<marsrutuSkaicius; i++)
    {
        duom>>M[i].marsrutoPavadinimas;
        cout<<M[i].marsrutoPavadinimas<<" ";

        for(int j=0; j<marsrutuSkaicius-1; j++)
        {
            duom>>M[i].valandos[j]>>M[i].minutes[j];
            suformuokData(M[i].valandos[j], M[i].minutes[j]);
        }

        cout<<endl;
    }
        cout<<endl<<endl;


}

//SKAICIAVIMO METODAS

void skaiciuok(studentai M[], int marsrutuSkaicius)
{
    for(int i=0; i<marsrutuSkaicius; i++)
    {
        for(int j=0; j<marsrutuSkaicius-1; j++)
        {
           M[i].konvertuotiMinutem[j]=(M[i].valandos[j]*60)+M[i].minutes[j];

           M[i].laikoSkirtumas[j]=M[i].konvertuotiMinutem[1]-M[i].konvertuotiMinutem[0];

           M[i].galutinesValandos=M[i].laikoSkirtumas[j]/60;
           M[i].galutinesMinutes=M[i].laikoSkirtumas[j]-(60*M[i].galutinesValandos);

        }
        cout<<M[i].galutinesValandos<<" "<<M[i].galutinesMinutes<<endl;
    }
}

//REZULTATU RASYMAS I FAILA
void rezultatai(studentai M[], int marsrutuSkaicius)
{
    ofstream rez("C:\\Users\\MT\\Desktop\\INFORMATIKA\\1.Studentai\\Rezultatai.txt");

    for(int i=0; i<marsrutuSkaicius; i++)
    {
        rez<<M[i].marsrutoPavadinimas<<" ";
        rez<<M[i].galutinesValandos<<" "<<M[i].galutinesMinutes<<endl;

    }

}

void suformuokData(int valandos, int minutes){
    if(valandos>=10){
        cout<<valandos<<" ";
    }
    else{
        string valanduLaikas = "0" + valandos;
        cout<<valanduLaikas<<" ";
    }
    if(minutes>=10){
        cout<<minutes<<" ";
    }
    else{
        string minuciuLaikas = "0" + minutes;
        cout<<minuciuLaikas<<" ";
    }
    cout<<endl;
}

//MAINAS
int main()
{   int n;
    //suformuokData();
    studentai masyvas[100];
    skaityk(masyvas,n);
    skaiciuok(masyvas,n);
    rezultatai(masyvas,n);
    return 0;
}
