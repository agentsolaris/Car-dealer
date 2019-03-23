#include "MINI.h"
class MICA : public AUTOMOBIL
{
    int cutie_manuala; ///0-AUTOMATA, 1-MANUALA
public:
    MICA(string M=" ",int an_f=0,float litr=0.0,float lung=0.0,int cut_man=0,float price=-1.0):AUTOMOBIL(M,an_f,litr,lung,price),cutie_manuala(cut_man)
    {
        cutie_manuala=1;
    }
    MICA(MICA& mi):AUTOMOBIL(mi),cutie_manuala(mi.cutie_manuala){}
    ~MICA()
    {
        cutie_manuala=0;
    }
    string tip () {return "MICA";}
    MICA& operator= (MICA& mc);
    //void citire(ifstream& in);
    void citire(istream& in);
    void afisare(ostream& out);
    int check()
    {
		AUTOMOBIL::check();
        if(lungime<3.81 || lungime>4.1) return 4;
        return 0;
    }
    ///FRIEND
    friend ifstream& operator>> (ifstream&in, MICA& a);
    friend istream& operator>> (istream&in, MICA& a);
    friend ostream& operator<< (ostream&out, MICA& a);
};

MICA& MICA::operator= (MICA& mc)
{
    AUTOMOBIL::operator=(mc);
    cutie_manuala=mc.cutie_manuala;
}


void MICA::citire (istream& in)
{
    cout<<"\nSe citesc date pentru Masina MICA:\nNumele: ";
	AUTOMOBIL::citire();
    cout<<"Cutie de viteza: 1.MANUALA | 2. AUTOMATA\n";
    string trac;
    in>>trac;
    trac=UPPER(trac);
    if(trac=="1" || trac=="MANUALA") cutie_manuala=1;
    else if(trac=="0" || trac=="AUTOMATA") cutie_manuala=0;
string n;
getline(in,n);
}

void MICA::afisare (ostream& out)
{
    if(Marca!= " ")
        {
		AUTOMOBIL::afisare();
        if(cutie_manuala) out<<" | Cutie viteze: MANUALA";
        else out<<" | Cutie viteze: AUTOMATA";
        out<<"\n| Tip: Mica";
        }
}


ifstream& operator>> (ifstream&in, MICA& mi)
{
    mi.citire(in);
    return in;
}

istream& operator>> (istream&in, MICA& mi)
{
    mi.citire(in);
    return in;
}
ostream& operator<< (ostream&out, MICA& mi)
{
    mi.afisare(out);
    return out;
}
