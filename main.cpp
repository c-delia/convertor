#include <iostream>
#include <fstream>
#include <cstring>
#define dmax 15

using namespace std;

struct transforma
{
    int unit1, unit2;
    long double valoare;
};

ifstream fin("unitati.in");

long double transfLungime[dmax][dmax];
long double transfArie[dmax][dmax];
long double transfVolum[dmax][dmax];
long double transfTimp[dmax][dmax];
long double transfViteza[dmax][dmax];
long double transfTemperatura[dmax][dmax];
long double transfMasa[dmax][dmax];
long double transfEnergie[dmax][dmax];
long double transfPresiune[dmax][dmax];
long double transfDensitate[dmax][dmax];
long double transfConsum[dmax][dmax];

int Meniu();

void initializareLungime();
void initializareArie();
void initializareVolum();
void initializareTimp();
void initializareViteza();
void initializareTemperatura();
void initializareMasa();
void initializareEnergie();
void initializarePresiune();
void initializareDensitate();
void initializareConsum();

transforma Lungime();
transforma Arie();
transforma Volum();
transforma Timp();
transforma Viteza();
transforma Temperatura();
transforma Masa();
transforma Energie();
transforma Presiune();
transforma Densitate();
transforma Consum();

void initializeazaUnitati();

int main()
{
    transforma transf;
    int comanda;
    long double rezultat;
    initializeazaUnitati();
    comanda=Meniu();
    while(comanda)
    {
        if(comanda==1)
        {
            transf=Lungime();
            rezultat=transf.valoare*transfLungime[transf.unit1][transf.unit2];
            cout<<"********************"<<'\n';
            cout<<"Rezultatul este: "<<rezultat<<'\n';
            cout<<"********************"<<'\n';
        }
        if(comanda==2)
        {
            transf=Arie();
            rezultat=transf.valoare*transfArie[transf.unit1][transf.unit2];
            cout<<"********************"<<'\n';
            cout<<"Rezultatul este: "<<rezultat<<'\n';
            cout<<"********************"<<'\n';
        }
        if(comanda==3)
        {
            transf=Volum();
            rezultat=transf.valoare*transfVolum[transf.unit1][transf.unit2];
            cout<<"********************"<<'\n';
            cout<<"Rezultatul este: "<<rezultat<<'\n';
            cout<<"********************"<<'\n';
        }
        if(comanda==4)
        {
            transf=Timp();
            rezultat=transf.valoare*transfTimp[transf.unit1][transf.unit2];
            cout<<"********************"<<'\n';
            cout<<"Rezultatul este: "<<rezultat<<'\n';
            cout<<"********************"<<'\n';
        }
        if(comanda==5)
        {
            transf=Viteza();
            rezultat=transf.valoare*transfViteza[transf.unit1][transf.unit2];
            cout<<"********************"<<'\n';
            cout<<"Rezultatul este: "<<rezultat<<'\n';
            cout<<"********************"<<'\n';
        }
        if(comanda==6)
        {
            transf=Temperatura();
            if(transf.unit1==transf.unit2)
                rezultat=transf.valoare*transfTemperatura[transf.unit1][transf.unit2];
            if(transf.unit1==1)
            {
                if(transf.unit2==2)
                    rezultat=transf.valoare*1.8+32;
                if(transf.unit2==3)
                    rezultat=transf.valoare+273.15;
            }
            if(transf.unit1==2)
            {
                if(transf.unit2==1)
                    rezultat=(transf.valoare-32)/1.8;
                if(transf.unit2==3)
                    rezultat=(transf.valoare+459.67)*5/9;
            }
            if(transf.unit1==3)
            {
                if(transf.unit2==1)
                    rezultat=transf.valoare-273.15;
                if(transf.unit2==2)
                    rezultat=transf.valoare*9/5-459.67;
            }
            cout<<"********************"<<'\n';
            cout<<"Rezultatul este: "<<rezultat<<'\n';
            cout<<"********************"<<'\n';
        }
        if(comanda==7)
        {
            transf=Masa();
            rezultat=transf.valoare*transfMasa[transf.unit1][transf.unit2];
            cout<<"********************"<<'\n';
            cout<<"Rezultatul este: "<<rezultat<<'\n';
            cout<<"********************"<<'\n';
        }
        if(comanda==8)
        {
            transf=Energie();
            rezultat=transf.valoare*transfEnergie[transf.unit1][transf.unit2];
            cout<<"********************"<<'\n';
            cout<<"Rezultatul este: "<<rezultat<<'\n';
            cout<<"********************"<<'\n';
        }
        if(comanda==9)
        {
            transf=Presiune();
            rezultat=transf.valoare*transfPresiune[transf.unit1][transf.unit2];
            cout<<"********************"<<'\n';
            cout<<"Rezultatul este: "<<rezultat<<'\n';
            cout<<"********************"<<'\n';
        }
        if(comanda==10)
        {
            transf=Densitate();
            rezultat=transf.valoare*transfDensitate[transf.unit1][transf.unit2];
            cout<<"********************"<<'\n';
            cout<<"Rezultatul este: "<<rezultat<<'\n';
            cout<<"********************"<<'\n';
        }
        if(comanda==11)
        {
            transf=Consum();
            rezultat=transf.valoare*transfConsum[transf.unit1][transf.unit2];
            cout<<"********************"<<'\n';
            cout<<"Rezultatul este: "<<rezultat<<'\n';
            cout<<"********************"<<'\n';
        }
        comanda=Meniu();
    }

    return 0;
}

int Meniu()
{
    int comanda;
    cout<<"0->Iesi din program"<<'\n';
    cout<<"1->Lungime"<<'\n';
    cout<<"2->Arie"<<'\n';
    cout<<"3->Volum"<<'\n';
    cout<<"4->Timp"<<'\n';
    cout<<"5->Viteza"<<'\n';
    cout<<"6->Temperatura"<<'\n';
    cout<<"7->Masa"<<'\n';
    cout<<"8->Energie"<<'\n';
    cout<<"9->Presiune"<<'\n';
    cout<<"10->Densitate"<<'\n';
    cout<<"11->Consum combustibil"<<'\n';
    cout<<"Alege comanda: ";
    cin>>comanda;
    return comanda;
}

void initializareLungime()
{
    int i, j;
    for(i=1; i<=7; i++)
        for(j=1; j<=7; j++)
            fin>>transfLungime[i][j];
}
void initializareArie()
{
    int i, j;
    for(i=1; i<=9; i++)
        for(j=1; j<=9; j++)
            fin>>transfArie[i][j];
}
void initializareVolum()
{
    int i, j;
    for(i=1; i<=9; i++)
        for(j=1; j<=9; j++)
            fin>>transfVolum[i][j];
}
void initializareTimp()
{
    int i, j;
    for(i=1; i<=10; i++)
        for(j=1; j<=10; j++)
            fin>>transfTimp[i][j];
}
void initializareViteza()
{
    int i, j;
    for(i=1; i<=3; i++)
        for(j=1; j<=3; j++)
            fin>>transfViteza[i][j];
}
void initializareTemperatura()
{
    int i, j;
    for(i=1; i<=3; i++)
        for(j=1; j<=3; j++)
            fin>>transfTemperatura[i][j];
}
void initializareMasa()
{
    int i, j;
    for(i=1; i<=5; i++)
        for(j=1; j<=5; j++)
            fin>>transfMasa[i][j];
}
void initializareEnergie()
{
    int i, j;
    for(i=1; i<=6; i++)
        for(j=1; j<=6; j++)
            fin>>transfEnergie[i][j];
}
void initializarePresiune()
{
    int i, j;
    for(i=1; i<=4; i++)
        for(j=1; j<=4; j++)
            fin>>transfPresiune[i][j];
}
void initializareDensitate()
{
    int i, j;
    for(i=1; i<=10; i++)
        for(j=1; j<=10; j++)
            fin>>transfDensitate[i][j];
}
void initializareConsum()
{
    int i, j;
    for(i=1; i<=3; i++)
        for(j=1; j<=3; j++)
            fin>>transfConsum[i][j];
}


transforma Lungime()
{
    transforma x;
    cout<<"1->Milimetri"<<'\n';
    cout<<"2->Centimetri"<<'\n';
    cout<<"3->Metri"<<'\n';
    cout<<"4->Kilometri"<<'\n';
    cout<<"5->Mile"<<'\n';
    cout<<"6->Feet"<<'\n';
    cout<<"7->Inch"<<'\n';
    cout<<"Din: "; cin>>x.unit1;
    cout<<"In: "; cin>>x.unit2;
    cout<<"Valoare: "; cin>>x.valoare;
    return x;
}
transforma Arie()
{
    transforma x;

    cout<<"1->Milimetri Patrati"<<'\n';
    cout<<"2->Centimetri patrati"<<'\n';
    cout<<"3->Metri Patrati"<<'\n';
    cout<<"4->Kilometri patrati"<<'\n';
    cout<<"5->Ari"<<'\n';
    cout<<"6->Acri"<<'\n';
    cout<<"7->Hectare"<<'\n';
    cout<<"8->Feet^2"<<'\n';
    cout<<"9->Inch patrati"<<'\n';
    cout<<"Din:"; cin>>x.unit1;
    cout<<"In:"; cin>>x.unit2;
    cout<<"Valoare: "; cin>>x.valoare;
    return x;
}
transforma Volum()
{
    transforma x;
    cout<<"1->Mililitri"<<'\n';
    cout<<"2->Centilitri"<<'\n';
    cout<<"3->Litri"<<'\n';
    cout<<"4->Centimetri cubi"<<'\n';
    cout<<"5->Metri cubi"<<'\n';
    cout<<"6->Galon"<<'\n';
    cout<<"7->Inch cubi"<<'\n';
    cout<<"8->Feet^3"<<'\n';
    cout<<"9->Yard^3"<<'\n';
    cout<<"Din:"; cin>>x.unit1;
    cout<<"In:"; cin>>x.unit2;
    cout<<"Valoare: "; cin>>x.valoare;
    return x;
}
transforma Timp()
{
    transforma x;
    cout<<"1->Picosecunda"<<'\n';
    cout<<"2->Nanosecunda"<<'\n';
    cout<<"3->Milisecunda"<<'\n';
    cout<<"4->Secunda"<<'\n';
    cout<<"5->Minut"<<'\n';
    cout<<"6->Ora"<<'\n';
    cout<<"7->Zile"<<'\n';
    cout<<"8->Saptamani"<<'\n';
    cout<<"9->Luni"<<'\n';
    cout<<"10->Ani"<<'\n';
    cout<<"Din:"; cin>>x.unit1;
    cout<<"In:"; cin>>x.unit2;
    cout<<"Valoare: "; cin>>x.valoare;
    return x;
}
transforma Viteza()
{
    transforma x;
    cout<<"1->Km/h"<<'\n';
    cout<<"2->M/h"<<'\n';
    cout<<"3->m/s"<<'\n';
    cout<<"Din:"; cin>>x.unit1;
    cout<<"In:"; cin>>x.unit2;
    cout<<"Valoare: "; cin>>x.valoare;
    return x;
}
transforma Temperatura()
{
    transforma x;
    cout<<"1->Grade Celsius"<<'\n';
    cout<<"2->Grade Farenheit"<<'\n';
    cout<<"3->Kelvin"<<'\n';
    cout<<"Din:"; cin>>x.unit1;
    cout<<"In:"; cin>>x.unit2;
    cout<<"Valoare: "; cin>>x.valoare;
    return x;
}
transforma Masa()
{
    transforma x;
    cout<<"1->Miligrame"<<'\n';
    cout<<"2->Grame"<<'\n';
    cout<<"3->Kilograme"<<'\n';
    cout<<"4->Pound"<<'\n';
    cout<<"5->Tone"<<'\n';
    cout<<"Din:"; cin>>x.unit1;
    cout<<"In:"; cin>>x.unit2;
    cout<<"Valoare: "; cin>>x.valoare;
    return x;
}
transforma Energie()
{
    transforma x;
    cout<<"1->Calorii"<<'\n';
    cout<<"2->Kilocalorii"<<'\n';
    cout<<"3->Jouli"<<'\n';
    cout<<"4->KiloJouli"<<'\n';
    cout<<"5->Watt"<<'\n';
    cout<<"6->KiloWatt"<<'\n';
    cout<<"Din:"; cin>>x.unit1;
    cout<<"In:"; cin>>x.unit2;
    cout<<"Valoare: "; cin>>x.valoare;
    return x;
}
transforma Presiune()
{
    transforma x;
    cout<<"1->Atmosfere"<<'\n';
    cout<<"2->Bari"<<'\n';
    cout<<"3->mmHg"<<'\n';
    cout<<"4->Psi"<<'\n';
    cout<<"Din:"; cin>>x.unit1;
    cout<<"In:"; cin>>x.unit2;
    cout<<"Valoare: "; cin>>x.valoare;
    return x;
}
transforma Densitate()
{
    transforma x;
    cout<<"1->mg/cm^3"<<'\n';
    cout<<"2->mg/l"<<'\n';
    cout<<"3->g/mm^3"<<'\n';
    cout<<"4->g/cm^3"<<'\n';
    cout<<"5->g/m^3"<<'\n';
    cout<<"6->g/l"<<'\n';
    cout<<"7->kg/cm^3"<<'\n';
    cout<<"8->kg/l"<<'\n';
    cout<<"9->kg/m^3"<<'\n';
    cout<<"10->t/m^3"<<'\n';
    cout<<"Din:"; cin>>x.unit1;
    cout<<"In:"; cin>>x.unit2;
    cout<<"Valoare: "; cin>>x.valoare;
    return x;
}
transforma Consum()
{
    transforma x;
    cout<<"1->Litri la 100 km"<<'\n';
    cout<<"2->Mile la galon"<<'\n';
    cout<<"3->Kilometri la litru"<<'\n';
    cout<<"Din:"; cin>>x.unit1;
    cout<<"In:"; cin>>x.unit2;
    cout<<"Valoare: "; cin>>x.valoare;
    return x;
}

void initializeazaUnitati()
{
    initializareLungime();
    initializareArie();
    initializareVolum();
    initializareTimp();
    initializareViteza();
    initializareTemperatura();
    initializareMasa();
    initializareEnergie();
    initializarePresiune();
    initializareDensitate();
    initializareConsum();
}
