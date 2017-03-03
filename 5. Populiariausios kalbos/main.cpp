#include <iostream>
#include <fstream>
using namespace std;

struct prograkalbe
{
    string kalbosPavadinimas;
    int populiari10;
    int populiari11;
};
void skaitymas(prograkalbe M[], int &kalbuSkaicius)
{
    char simboliai[22];

    ifstream duom("C:\\Users\\MT\\Desktop\\INFORMATIKA\\5. Populiariausios kalbos\\Duomenys.txt");
    duom>>kalbuSkaicius;
    duom.ignore(80,'\n');

    for(int i=0; i<kalbuSkaicius; i++)
    {
     duom.get(simboliai,22);
     M[i].kalbosPavadinimas=simboliai;
     duom>>M[i].populiari11;
     duom>>M[i].populiari10;
     duom.ignore(80,'\n');
     cout<<M[i].kalbosPavadinimas<<" ";
     cout<<M[i].populiari11<<" ";
     cout<<M[i].populiari10<<endl;
    }




}

int main()
{
    int n;
    prograkalbe masyvas[100];

    skaitymas(masyvas,n);

    return 0;
}
