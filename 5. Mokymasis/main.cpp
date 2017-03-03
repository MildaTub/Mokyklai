#include <iostream>
#include <fstream>
using namespace std;
void skaityk(int M[], int &mokiniuSkaicius)
{

    ifstream duom("C:\\Users\\MT\\Desktop\\INFORMATIKA\\5. Mokymasis\\Duomenys.txt");
    duom>>mokiniuSkaicius;
    int duomenuSkaicius = mokiniuSkaicius*3;
    for(int i=0; i<duomenuSkaicius; i++)
    {
        duom>>M[i];

        cout<<M[i]<<" ";

        //cout<<endl;
            //duom.ignore(80,'/n');
    }
    cout<<endl;
    int counter = 0;
    for(int i=0; i<duomenuSkaicius; i++)
    {
        counter++;
        cout<<M[i]<<" ";
        if(counter==3){
            cout<<endl;
            counter=0;
        }
        //cout<<endl;
            //duom.ignore(80,'/n');
    }

    cout<<endl;
}

void skaiciuok(int M[],int mokimosiDienos)
{
    cout<<endl;
    for(int i=0; i<mokimosiDienos; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout<<M[i];
        }
        cout<<endl;
    }


}

int main()
{
    int masyvas[100],n;
    skaityk(masyvas,n);
    skaiciuok(masyvas,n);

    return 0;
}
