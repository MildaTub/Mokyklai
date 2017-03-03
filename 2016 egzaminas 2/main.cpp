#include <iostream>
#include <fstream>
using namespace std;

struct VytautoPratimai
{
    string pratimas;
    int pratimuAtlikta=0;
};

void rikiuokPratimus(int kiekPratimu,VytautoPratimai M[])
{
    VytautoPratimai sumos[3];
    sumos[0].pratimas="atsilenkimai";
    sumos[1].pratimas="atsispaudimai";
    sumos[2].pratimas="prisitraukimai";
    for(int i=0; i<kiekPratimu; i++)
    {
        if(M[i].pratimas==sumos[0].pratimas)
        {
            sumos[0].pratimuAtlikta+=M[i].pratimuAtlikta;

        }
        if(M[i].pratimas==sumos[1].pratimas)
        {
            sumos[1].pratimuAtlikta+=M[i].pratimuAtlikta;

        }
        if(M[i].pratimas==sumos[2].pratimas)
        {
            sumos[2].pratimuAtlikta+=M[i].pratimuAtlikta;

        }

    }
    for(int i=0; i<kiekPratimu; i++)
    {
        for(int j=0; j<kiekPratimu-1; j++)
        {
            if(sumos[j].pratimuAtlikta<sumos[j+1].pratimuAtlikta)
            {
                int laikinas=sumos[j].pratimuAtlikta;
                sumos[j].pratimuAtlikta=sumos[j+1].pratimuAtlikta;
                sumos[j+1].pratimuAtlikta=laikinas;

                string laikinas1=sumos[j].pratimas;
                sumos[j].pratimas=sumos[j+1].pratimas;
                sumos[j+1].pratimas=laikinas1;

            }
        }

    }
cout<<sumos[0].pratimas<<" "<<sumos[0].pratimuAtlikta<<" ";
cout<<sumos[1].pratimas<<" "<<sumos[1].pratimuAtlikta<<" ";
cout<<sumos[2].pratimas<<" "<<sumos[2].pratimuAtlikta<<" ";


}

int main()
{
    int pratimuUzrasymas;
    VytautoPratimai masyvas[100];

    ifstream duom("C:\\Users\\MT\\Desktop\\INFORMATIKA\\2016 egzaminas 2\\u1.txt");
    duom>>pratimuUzrasymas;


    for(int i=0; i<pratimuUzrasymas; i++)
    {

            duom>>masyvas[i].pratimas;
           // cout<<masyvas[i].pratimas<<endl;

            duom>>masyvas[i].pratimuAtlikta;
            //cout<<masyvas[i].pratimuAtlikta<<endl;



    }

    duom.close();

    rikiuokPratimus(pratimuUzrasymas,masyvas);




    return 0;
}
