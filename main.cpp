#include <iostream>
#include <algorithm>
using namespace std;

struct data
{
    char car;
    int nb;
    string code;
};

struct calcul
{
    int pr;
    string car;
};

string supp(string T, char ca)
{
    T.erase(remove(T.begin(),T.end(),ca),T.end());
    return T;
}

void frequency(data tab[],string T)
{
    int f, g=0;
    while(T.length()>0)
    {
        f=1;
        for(int i=1 ; i<T.length() ;i++)
        {

        if(T[i]==T[0])
        {
            f=f+1;
        }
    }
    tab[g].car=T[0];
    tab[g].nb=f;
    T=supp(T,T[0]);
    g=g+1;
}
}

void triData(data tab[], int ta)
{
    data g;
    for(int i=0;i<ta-1;i++)
    {
        for(int j=i+1;j<ta;j++)
        {
            if(tab[i].nb<tab[j].nb)
            {
                g=tab[j];
                tab[j]=tab[i];
                tab[i]=g;
            }
            if(tab[i].nb==tab[j].nb&&tab[i].car>tab[j].car)
            {
                g=tab[j];
                tab[j]=tab[i];
                tab[i]=g;
            }
        }
    }
}

void Tri_cal(calcul T[],int n)
{
calcul temp;
    for(int i=0;i<n-1;i++)
    {
            if(T[i].pr<T[n-1].pr)
            {
                temp=T[i];
                T[i]=T[n-1];
                T[n-1]=temp;
            }

            }
        }





void huffman(data tab[],int n)
{
    calcul *T;
    T=new calcul[n];
    for(int i=0;i<n;i++)

{
    T[i].car=tab[i].car;
    T[i].pr=tab[i].nb;
}
     int N=n;
     while(N>1)
{
    string Tc=T[N-1].car;
    int s=Tc.length();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<s;j++)
        {
            if (tab[i].car==Tc[j])
            {
                tab[i].code='1'+tab[i].code;
            }
        }
    }
        Tc=T[N-2].car;
        s=Tc.length();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<s;j++)
            {
                if(tab[i].car==Tc[j])
                {
                    tab[i].code='0'+tab[i].code;
                }
            }
        }
                T[N-2].car=T[N-1].car+T[N-2].car;
                T[N-2].pr=T[N-1].pr+T[N-2].pr;
                N=N-1;
                Tri_cal(T,N);
            }
        }





int main()
{
    string T,T1;
    getline(cin,T);
    supp(T,' ');
    int ta=0;
    T1=T;
    while(T1.length()>0)
    {
        ta=ta+1;
        T1=supp(T1,T1[0]);
    }
    data tab[ta];
    frequency(tab,T);
    triData(tab,ta);
    huffman(tab,ta);

    for(int i=0;i<ta;i++)
        cout<<tab[i].car<<" = "<<tab[i].nb<<"="<<tab[i].code<<endl;
    return 0;
}
