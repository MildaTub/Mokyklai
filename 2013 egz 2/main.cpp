#include <iostream>
#include <fstream>
using namespace std;

struct lietuva
{
    string miestas;
    string apskritis;
    int zmoniuSkaicius;

};
void skaitymas(lietuva M[])
{
    int miestuSkaicius;

    ifstream duom("C:\\Users\\MT\\Desktop\\INFORMATIKA\\2013 egz 2\\u1.txt");
    duom>>miestuSkaicius;
    duom.ignore(80,'\n');

    char simboliai[13];
    for(int i=0; i<miestuSkaicius; i++)
    {
        duom.get(simboliai,13);
        M[i].miestas=simboliai;
        duom>>M[i].apskritis>>M[i].zmoniuSkaicius;
        cout<<M[i].miestas<<" "<<M[i].apskritis<<" "<<M[i].zmoniuSkaicius<<endl;
        duom.ignore(80,'\n');
    }

}

int main()
{   lietuva masyvas[100];
    skaitymas(masyvas);
    return 0;
}
