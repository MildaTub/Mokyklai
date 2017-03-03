#include <iostream>
#include <fstream>
using namespace std;

void suskaiciuokSlyvas(int mergaiciuSlyvos[20])
{
    int mokiniai[20];

    ifstream duom("C:\\Users\\MT\\Desktop\\INFORMATIKA\\2015 egzaminas 1\\u1.txt");
    for(int i=0; i<10; i++)
    {
        duom>>mergaiciuSlyvos[i];
        cout<<mergaiciuSlyvos[i]<<" ";

    }
    cout<<endl;
    for(int i=0; i<10; i++)
    {
        mokiniai[i]=mergaiciuSlyvos[i];
        cout<<mokiniai[i]<<" ";
    }

    for(int i=10; i<20; i++)
    {
        mokiniai[i]=0;
        cout<<mokiniai[i]<<" ";
    }
    for(int i=0; i<10; i++)
    {   int perdavimoSkaicius;
        perdavimoSkaicius=10-mergaiciuSlyvos[i];
        for(int j=0; j<perdavimoSkaicius; j++)
        {
            mokiniai[i+j+1]+=1;

        }

    }
    cout<<endl;
for(int i=0; i<20; i++)
{
    cout<<mokiniai[i]<<" ";
}

}

int main()
{
    int mergaites[20];
    suskaiciuokSlyvas(mergaites);



    return 0;
}
