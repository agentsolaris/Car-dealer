#include "COMPACTA.h"

class MONOVOLUME : public AUTOMOBIL
{
protected:
    int deschidere_usi;///1-OBISNUITE 2-PIVOTARE 3-CULISANTA
public:
    MONOVOLUME(string M=" ",int an_f=0,float litr=0.0,float lung=0.0,int desch_usi=0,float price=-1.0):AUTOMOBIL(M,an_f,litr,lung,price),deschidere_usi(desch_usi)
    {}
    MONOVOLUME(MONOVOLUME& mo):AUTOMOBIL(mo),deschidere_usi(mo.deschidere_usi){}
    ~MONOVOLUME(){}
    virtual string tip () {return "MONOVOLUM";}
    MONOVOLUME& operator= (MONOVOLUME& mv);
    virtual void citire(istream& in){}
    virtual void afisare(ostream& out){}
    ///FRIEND
    friend istream& operator>> (istream&in, MONOVOLUME& mv);
    friend ostream& operator<< (ostream&out, MONOVOLUME& mv);
};

class MONOV_NOU: public MONOVOLUME
{
    float discount_inteprinderi;
public:
    MONOV_NOU(string M=" ",int an_f=0,float litr=0.0,float lung=0.0,int desch_usi=0,float disc=0.0,float price=-1.0):MONOVOLUME(M,an_f,litr,lung,desch_usi,price),discount_inteprinderi(disc)
    {}
    MONOV_NOU(MONOV_NOU& mvn):MONOVOLUME(mvn),discount_inteprinderi(mvn.discount_inteprinderi){}
    ~MONOV_NOU(){}
    int check()
    {
        if(an_fabr>2018) return 1;
        if(pret<0) return 2;
        if(Marca==" ") return 3;
        if(lungime>4) return 4;
        if(discount_inteprinderi<0 || discount_inteprinderi>=100) return 5;
        return 0;
    }
    string tip () {return "MONOVOLUM NOU";}
    MONOV_NOU& operator= (MONOV_NOU& mvn);
    ///FRIEND
    void citire(ifstream& in);
    void citire(istream& in);
    void afisare(ostream& out);
    friend ifstream& operator>> (ifstream&in, MONOV_NOU& mv_n);
    friend istream& operator>> (istream&in, MONOV_NOU& mv_n);
    friend ostream& operator<< (ostream&out, MONOV_NOU& mv_n);
};

class MONOV_SH: public MONOVOLUME
{
    float discout_vechime;
public:
    MONOV_SH(string M=" ",int an_f=0,float litr=0.0,float lung=0.0,int desch_usi=0,float price=-1.0):MONOVOLUME(M,an_f, litr,lung,desch_usi,price)
    {
        discout_vechime=2018-an_fabr;
    }
    MONOV_SH(MONOV_SH& mvsh):MONOVOLUME(mvsh),discout_vechime(mvsh.discout_vechime){}
    ~MONOV_SH(){}
    int check()
    {
		AUTOMOBIL::check();
        if(lungime>4) return 4;
        if(discout_vechime<0 || discout_vechime>=100) return 5;
        return 0;
    }
    string tip () {return "MONOVOLUM SECOND-HAND";}
    MONOV_SH& operator= (MONOV_SH& mvsh);
    void citire(ifstream& in);
    void citire(istream& in);
    void afisare(ostream& out);
    ///FRIEND
    friend ifstream& operator>> (ifstream&in, MONOV_SH& mv_sh);
    friend istream& operator>> (istream&in, MONOV_SH& mv_sh);
    friend ostream& operator<< (ostream&out, MONOV_SH& mv_sh);
};


MONOVOLUME& MONOVOLUME::operator= (MONOVOLUME& mv)
{
    AUTOMOBIL::operator=(mv);
    deschidere_usi=mv.deschidere_usi;
    return *this;
}

MONOV_NOU& MONOV_NOU::operator= (MONOV_NOU& mvn)
{
    MONOVOLUME::operator=(mvn);
    discount_inteprinderi=mvn.discount_inteprinderi;
    return *this;
}

MONOV_SH& MONOV_SH::operator= (MONOV_SH& mvsh)
{
    MONOVOLUME::operator=(mvsh);
    discout_vechime=mvsh.discout_vechime;
    return *this;
}


void MONOV_NOU::citire (istream& in)
{
    cout<<"\nSe citesc date pentru Masina MONOVOLUM NOU:\nNumele: ";
	AUTOMOBIL::citire();

    cout<<"Tipuri USI: 1.OBISNUITE | 2.SIMETRICE | 3.CULISANTA\n";
    string sir;
    in>>sir;
    sir=UPPER(sir);
    if(sir=="1" || sir=="OBISNUITE") deschidere_usi=1;
    else if(sir=="2" || sir=="SIMETRICE") deschidere_usi=2;
    else if(sir=="3" || sir=="CULISANTA") deschidere_usi=3;

    cout<<"Discout inteprinteri: ";
    in>>discount_inteprinderi;

    cout<<"PRETUL: ";
    in>>pret;
    string n;
    getline(in,n);
}
void MONOV_SH::citire (istream& in)
{
    cout<<"\nSe citesc date pentru Masina MONOVOLUM SECOND-HAND:\nNumele: ";
	AUTOMOBIL::citire();

    cout<<"Tipuri PORTIERE: 1.OBISNUITE | 2.SIMETRICE | 3.CULISANTA\n";
    string sir;
    in>>sir;
    sir=UPPER(sir);
    if(sir=="1" || sir=="OBISNUITE") deschidere_usi=1;
    else if(sir=="2" || sir=="SIMETRICE") deschidere_usi=2;
    else if(sir=="3" || sir=="CULISANTA") deschidere_usi=3;

    discout_vechime=2018-an_fabr;

    cout<<"PRETUL: ";
    in>>pret;
    string n;
    getline(in,n);
}


void MONOV_NOU::citire (ifstream& in)
{
    cout<<"\nSe citesc date pentru Masina MONOVOLUM NOU:\nNumele: ";
	AUTOMOBIL::citire();

    cout<<"Tipuri USI: 1.OBISNUITE | 2.SIMETRICE | 3.CULISANTA\n";
    string sir;
    in>>sir;
    sir=UPPER(sir);
    if(sir=="1" || sir=="OBISNUITE") deschidere_usi=1;
    else if(sir=="2" || sir=="SIMETRICE") deschidere_usi=2;
    else if(sir=="3" || sir=="CULISANTA") deschidere_usi=3;

    cout<<"Discout inteprinteri: ";
    in>>discount_inteprinderi;

    cout<<"PRETUL: ";
    in>>pret;
    string n;
    getline(in,n);
}
void MONOV_SH::citire (ifstream& in)
{
    cout<<"\nSe citesc date pentru Masina MONOVOLUM SECOND-HAND:\nNumele: ";
	AUTOMOBIL::citire();

    cout<<"Tipuri PORTIERE: 1.OBISNUITE | 2.SIMETRICE | 3.CULISANTA\n";
    string sir;
    in>>sir;
    sir=UPPER(sir);
    if(sir=="1" || sir=="OBISNUITE") deschidere_usi=1;
    else if(sir=="2" || sir=="SIMETRICE") deschidere_usi=2;
    else if(sir=="3" || sir=="CULISANTA") deschidere_usi=3;

    discout_vechime=2018-an_fabr;

    cout<<"PRETUL: ";
    in>>pret;
    string n;
    getline(in,n);
}
void MONOV_NOU::afisare (ostream& out)
{
    if(Marca!= " ")
        {
        out<<"Marca : "<<Marca<<" | Anul: "<<an_fabr<<" | Lungime: "<<lungime<<"m | Litraj:  "<<litraj<<" L";
        if(deschidere_usi==1) out<<" | Portiere OBISNUITE";
        else if(deschidere_usi==2) out<<" Portiere SIMETRICE";
        else if(deschidere_usi==3) out<<"Portiere CULISANTE";
        out<<"\n|Tip: Monovolum NOU | Discout inteprinderi: "<<discount_inteprinderi<<"%";;
        out<<" | PRET: "<<pret<<" EURO";
        if(discount_inteprinderi) out<<" / "<<pret*(1-discount_inteprinderi/100)<<"EURO (pentru inteprinderi)\n\n";
        }
}
void MONOV_SH::afisare (ostream& out)
{
    if(Marca!= " ")
        {
        float dis=(discout_vechime>0&& discout_vechime<100)?(1-discout_vechime/100):(1.0);
        out<<"Marca : "<<Marca<<" | Anul: "<<an_fabr<<" | Lungime: "<<lungime<<"m | Litraj:  "<<litraj<<" L";
        if(deschidere_usi==1) out<<" | Portiere OBISNUITE";
        else if(deschidere_usi==2) out<<" | Portiere SIMETRICE";
        else if(deschidere_usi==3) out<<" | Portiere CULISANTE";
        out<<"\n|Tip: Monovolum Second-Hand | Discout vechime: "<<discout_vechime<<"%";
        out<<" | PRET: "<<pret<<" EURO / "<<pret*dis;
        out<<" EURO (+discout vechime) / "<<pret*0.9*dis<<" EURO (pe timp de vara)";
        }
}


ifstream& operator>> (ifstream& in, MONOV_NOU& mv_n)
{
    mv_n.citire(in);
    return in;
}
istream& operator>> (istream& in, MONOV_NOU& mv_n)
{
    mv_n.citire(in);
    return in;
}
ostream& operator<< (ostream& out, MONOV_NOU& mv_n)
{
    mv_n.afisare(out);
    return out;
}

ifstream& operator>> (ifstream& in, MONOV_SH& mv_sh)
{
    mv_sh.citire(in);
    return in;
}
istream& operator>> (istream& in, MONOV_SH& mv_sh)
{
    mv_sh.citire(in);
    return in;
}
ostream& operator<< (ostream& out, MONOV_SH& mv_sh)
{
    mv_sh.afisare(out);
    return out;
}

istream& operator>> (istream&in, MONOVOLUME& mv)
{
    mv.citire(in);
    return in;
}
ostream& operator<< (ostream&out, MONOVOLUME& mv)
{
    mv.afisare(out);
    return out;
}

