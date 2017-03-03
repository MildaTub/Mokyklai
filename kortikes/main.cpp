#include <iostream>
#include <fstream>
using namespace std;


void skaityk(int M[], int &kortikes)
{
    ifstream duom("C:\\Users\\MT\\Desktop\\INFORMATIKA\\kortikes\\uzduotis.txt");
    duom>>kortikes;
    kortikes*=2;
    for(int i=0; i<kortikes; i+=2)
    {
        duom>>M[i];
        duom>>M[i+1];
        cout<<M[i]<<" "<<M[i+1]<<" ";
        cout<<endl;
    }

cout<<kortikes<<" ";
}

void skaiciuok (int M[], int kortikes)
{   cout<<endl;
    int lyginiai[100];
    int nelyginiai[100];
    int suma=0;
    int summa=0;
    int kiekl=0, kiekn=0;
    cout<<endl;
    for(int i=0; i<kortikes; i+=2)
    {
        if(M[i]%2 ==0)
        {   lyginiai[i]=M[i]*M[i+1];
            suma+=lyginiai[i];
        }
        else
        {   nelyginiai[i]=M[i]*M[i+1];
            summa+=nelyginiai[i];

        }
    }
    cout<<endl;
    for(int i=0; i<kortikes; i+=2)
    {
        if(M[i+1] % 2 ==0)
        {
            cout<<M[i+1]<<" ";
            kiekl+=M[i+1];
        }
        else
        {
            kiekn+=M[i+1];
        }
    }
    cout<<endl;
    cout<<suma<<" "<<summa<<endl;
    cout<<kiekl<<" "<<kiekn<<" ";
}

int main()
{   int masyvas[100];
    int korteles;
    skaityk(masyvas,korteles);
    skaiciuok(masyvas,korteles);

    return 0;
}
