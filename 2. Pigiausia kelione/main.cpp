#include <iostream>
#include <fstream>
using namespace std;

struct kelione
{
    string degalinesPavadinimas;
    double benzinoKaina, dujuKaina;
};



void skaityk(kelione M[],double &imaBenzino, double &imaDyzelio, double &atstumas, double &degaliniuSkaicius)
{
    ifstream duom("C:\\Users\\MT\\Desktop\\INFORMATIKA\\2. Pigiausia kelione\\Duomenys.txt");
    duom>>imaBenzino>>imaDyzelio>>atstumas>>degaliniuSkaicius;

    for(int i=0; i<degaliniuSkaicius;i++)
    {
        duom>>M[i].degalinesPavadinimas>>M[i].benzinoKaina>>M[i].dujuKaina;
        cout<<M[i].degalinesPavadinimas<<" "<<M[i].benzinoKaina<<" "<<M[i].dujuKaina<<endl;
    }
cout<<endl;

}
double skaiciuok(kelione M[],double imaBenzino, double imaDyzelio, double atstumas, double degaliniuSkaicius,int kelintasBenzino[],
                 int kelintasDuju[],double &pigiausiasBenzinas,double &pigiausiasDyzelis, int &kiekBenz, int &kiekDyz)
{    pigiausiasBenzinas=0;
    pigiausiasDyzelis=0;
    double     islaidos=0;

    for(int i=0; i<degaliniuSkaicius; i++)
    {
        if(M[0].benzinoKaina>=M[i].benzinoKaina)
        {
        pigiausiasBenzinas=M[i].benzinoKaina;
        kelintasBenzino[kiekBenz]=i;
        kiekBenz++;
        }
        if(M[0].dujuKaina>=M[i].dujuKaina)
        {
            pigiausiasDyzelis=M[i].dujuKaina;
            kelintasDuju[kiekDyz]=i;
        }
    }


    for(int i = 0; i<kiekBenz; i++){
        cout<<M[kelintasBenzino[i]].degalinesPavadinimas<<" "<<pigiausiasBenzinas<<endl;
    }
    for(int i = 0; i<kiekDyz; i++){
        cout<<M[kelintasDuju[i]].degalinesPavadinimas<<" "<<pigiausiasDyzelis<<endl;
    }
    islaidos=(atstumas/100/2)*imaBenzino*pigiausiasBenzinas+(atstumas/100/2)*pigiausiasDyzelis*imaDyzelio;
    cout<<" "<<islaidos;
    return islaidos;
}
void irasyk(kelione M[],  double degaliniuSkaicius,int kelintasBenzino,int kelintasDuju,double islaidos,double pigben,double pigduj )
{
    ofstream rez("C:\\Users\\MT\\Desktop\\INFORMATIKA\\2. Pigiausia kelione\\Rezultatai.txt");
    rez<<islaidos<<endl;
    rez<<M[kelintasBenzino].degalinesPavadinimas<<" "<<pigben;
    rez<<" "<<M[kelintasDuju].degalinesPavadinimas<<" "<<pigduj;


}
int main()
{
    kelione masyvas[100];
    double b,d,m,n,isleido,pb,pd;
    int kiekBenzino=0, kiekDyzelio =0;
    int benzino[100],dyzelio[100];
    skaityk(masyvas,b,d,m,n);
    isleido=skaiciuok(masyvas,b,d,m,n,benzino,dyzelio,pb,pd,kiekBenzino,kiekDyzelio);
    //irasyk(masyvas,n,benzino,dyzelio,isleido,pb,pd);


    return 0;
}
