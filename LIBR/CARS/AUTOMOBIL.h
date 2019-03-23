#include "../de_inclus.h"

class AUTOMOBIL
{
protected:
    string Marca;
    int an_fabr;
    float litraj;
    float lungime;
    float pret;
public:
    AUTOMOBIL(string M=" ",int an_f=0,float litr=0.0,float lung=0.0,float price=-1.0):Marca(M),an_fabr(an_f),litraj(litr),lungime(lung),pret(price){}
    AUTOMOBIL(AUTOMOBIL& A):AUTOMOBIL(A.Marca,A.an_fabr,A.litraj,A.lungime,A.pret){}
    ~AUTOMOBIL();
    AUTOMOBIL& operator=(AUTOMOBIL& A);
    bool operator<(AUTOMOBIL& A) {return (pret<A.pret);}
    bool operator>(AUTOMOBIL& A) {return (pret>A.pret);}
    virtual string tip () {return "AUTOMOBIL";}
    virtual void citire (istream& in);
    virtual void afisare (ostream& out);
    virtual int check()
    {
        if(an_fabr>2018) return 1;
        if(pret<0) return 2;
        if(Marca==" ") return 3;
        return 0;
    }
    friend string UPPER (string str);
    friend ifstream& operator>> (ifstream&in, AUTOMOBIL& a);
    friend istream& operator>> (istream&in, AUTOMOBIL& a);
    friend ostream& operator<< (ostream&out, AUTOMOBIL& a);
};

AUTOMOBIL& AUTOMOBIL::operator=(AUTOMOBIL& A)
{
    Marca=A.Marca;
    an_fabr=A.an_fabr;
    litraj=A.litraj;
    lungime=A.lungime;
    pret=A.pret;
    return *this;
}


void AUTOMOBIL::citire (istream& in)
{
    getline(in,Marca);
    cout<<"Anul fabricatiei | Capacitate rezervor | Lungimea masinii (cu enter)\n";    in>>an_fabr>>litraj>>lungime;
    cout<<"PRETUL: ";
    in>>pret;
string n;
getline(in,n);
}

void AUTOMOBIL::afisare (ostream& out)
{
    if(Marca!= " ")
        {
        out<<"Marca : "<<Marca<<" | Anul: "<<an_fabr<<" | Lungime: "<<lungime<<"m | Litraj:  "<<litraj<<" L";
        out<<"\n| PRET: "<<pret<<" EURO\n\n";
        }

}

AUTOMOBIL::~AUTOMOBIL()
{
    Marca.clear();
}


istream& operator>> (istream&in, AUTOMOBIL& a)
{
    a.citire(in);
    return in;
}

ifstream& operator>> (ifstream&in, AUTOMOBIL& a)
{
    a.citire(in);
    return in;
}

ostream& operator<< (ostream&out, AUTOMOBIL& a)
{
    a.afisare(out);
    return out;
}

string UPPER (string str)
{
    for(int i=0;i<str.size();i++)
        str[i]=toupper(str[i]);
    return str;
}
