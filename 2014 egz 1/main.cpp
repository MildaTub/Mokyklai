#include <iostream>
#include <fstream>
using namespace std;

struct konkursas
{
    int skyriuBalsai[10];
    int direktoriausBalsai[3];
    int suma=0;

};
//SKAITYMAS
void skaityk(konkursas M[],int &skyriuSkaicius)
{
    ifstream duom("C:\\Users\\MT\\Desktop\\INFORMATIKA\\2014 egz 1\\U1.txt");
    duom>>skyriuSkaicius;
    duom.ignore(80,'\n');

    if(duom.is_open())
    {
        for(int i=0; i<skyriuSkaicius; i++)
        {
            for(int j=0; j<skyriuSkaicius-3; j++)
            {
                duom>>M[i].skyriuBalsai[j];
                cout<<M[i].skyriuBalsai[j]<<" ";


            }
            cout<<endl;
            duom.ignore(80,'\n');
        }
    }
    else cout<<"failas neatidarytas";

    for(int i=5; i<skyriuSkaicius; i++)
    {
        for(int j=0; j<3; j++)
        {
            duom>>M[i].direktoriausBalsai[j];
            cout<<M[i].direktoriausBalsai[j]<<" ";
        }
        duom.ignore(80,'\n');
    }
    cout<<endl<<endl;
}
//SKAICIAVIMAS
void sumuokBalus(konkursas M[], int skyriuSkaicius)
{
    for(int i=0; i<skyriuSkaicius; i++)
    {
        for(int j=0; j<3; j++)
        {
            M[1].suma+=M[i].skyriuBalsai[j];
            cout<<M[1].suma<<" ";

        }
        cout<<endl;

    }








}

int main()
{   int n;
    konkursas masyvas[100];

    skaityk(masyvas,n);
    sumuokBalus(masyvas,n);
    return 0;
}
