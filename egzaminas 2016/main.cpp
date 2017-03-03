#include <iostream>
#include <fstream>
using namespace std;


int rastimax(int kupriniuSkaicius)
{   int kuprinesGramais;
    int maxx=0;
    ifstream duom("C:\\Users\\MT\\Desktop\\INFORMATIKA\\egzaminas 2016\\u1.txt");
    duom>>kupriniuSkaicius;
    for(int i=0; i<kupriniuSkaicius; i++)
    {
        duom>>kuprinesGramais;
      //  cout<<kuprinesGramais<<" ";

        if(maxx<kuprinesGramais)
        {
            maxx=kuprinesGramais;
        }

    }
    duom.close();
    cout<<maxx;
    return maxx;
}

void raskmazesne(int didziausiaKuprine, int kupriniuSkaicius)
{   int kuprinesGramais, kiek=0,du=2;

    ifstream duom("C:\\Users\\MT\\Desktop\\INFORMATIKA\\egzaminas 2016\\u1.txt");
    duom>>kupriniuSkaicius;
    for(int i=0; i<kupriniuSkaicius; i++)
    {
        duom>>kuprinesGramais;

        int S=du*kuprinesGramais;
        if(didziausiaKuprine>=S)
        {

            kiek++;
        }

    }
    cout<<" "<<kiek;
    duom.close();
}



int main()
{   int kuprines,sunkiausiaKuprine;
    ifstream duom("C:\\Users\\MT\\Desktop\\INFORMATIKA\\egzaminas 2016\\u1.txt");
    duom>>kuprines;
    duom.close();
    sunkiausiaKuprine=rastimax(kuprines);
    raskmazesne(sunkiausiaKuprine,kuprines);
    return 0;
}
