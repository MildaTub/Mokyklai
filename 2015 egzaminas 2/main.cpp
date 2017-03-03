#include <iostream>
#include <fstream>
using namespace std;

struct aviuDNR
{
    string aviesVardas;
    char dnrFragmentas[6];
    int sutapimoKoeficientas;

};
void skaityk(aviuDNR aviuMasyvas[])
{   int aviuSkaicius, fragmentoIlgis,tiriamojiAvis;

    ifstream duom("C:\\Users\\MT\\Desktop\\INFORMATIKA\\2015 egzaminas 2\\u1.txt");

    duom>>aviuSkaicius;
    duom>>fragmentoIlgis;  //DUOMENU NUSKAITYMAS IS FAILO
    duom>>tiriamojiAvis;

    for(int i=0; i<4; i+=2)
    {
        for(int j=0; j<2;j++)
    {
        duom>>aviuMasyvas[i].aviesVardas;
        cout<<aviuMasyvas[i].aviesVardas<<" ";

    }

    }
}

//void ieskokKoeficiento(aviuDNR avys[])


int main()
{
    aviuDNR masyvas[100];

    //ieskokKoeficiento(masyvas);
    skaityk(masyvas);

    return 0;
}
