#include <iostream>
#include <fstream>
using namespace std;

struct imones
{
    string imonesPavadinimas;
    int koordinateX;
    int koordinateY;

};

skaityk(imones M[],int &imoniuKiekis,int &kilometruLimitas)
{

    ifstream duom("C:\\Users\\MT\\Desktop\\INFORMATIKA\\2013 egz 1\\u1.txt");
    duom>>imoniuKiekis>>kilometruLimitas;

    char simboliai[11];
    duom.ignore(80,'\n');

    for(int i=0; i<imoniuKiekis; i++)
    {
        duom.get(simboliai,11);
        M[i].imonesPavadinimas=simboliai;
        duom>>M[i].koordinateX>>M[i].koordinateY;
        cout<<M[i].imonesPavadinimas<<" "<<M[i].koordinateX<<" "<<M[i].koordinateY<<endl;
        duom.ignore(80,'\n');
    }


}
void skaiciuok(imones M[], int imoniuKiekis, int kilometruLimitas)
{   int nuvaziuotasAtstumas;
    string kelinta;
    int kelintas=0;
    int skirtumas=kilometruLimitas;
    for(int i=0; i<imoniuKiekis; i++)
    {

        if(M[i].koordinateX>0)
        {
            skirtumas-=M[i].koordinateX*2;
        }

        else if(M[i].koordinateY>0)
        {
            skirtumas-=M[i].koordinateY*2;
        }

        else if(M[i].koordinateX<0)
        {
            skirtumas-=M[i].koordinateY*(-2);
        }
        else if(M[i].koordinateY>0)
        {
            skirtumas-=M[i].koordinateY*(-2);
        }

        if(skirtumas<0)
        {
            break;

        }
        kelintas=i-1;

    }

nuvaziuotasAtstumas=kilometruLimitas-skirtumas;
kelinta=M[kelintas-1].imonesPavadinimas;
cout<<nuvaziuotasAtstumas<<" "<<kelintas<<kelinta;

}
int main()
{   int n,m;
    imones masyvas[100];
    skaityk(masyvas,n,m);
    skaiciuok(masyvas,n,m);
    return 0;
}
