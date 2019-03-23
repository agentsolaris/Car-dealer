#include "CARS/MONOVOLUME.h"

template <class T>
class VANZARI
{
    int nr_stock;
    int nr_vandute;
    vector<T*> stock;
    vector<T*> vandute;
public:
    VANZARI(){nr_stock=nr_vandute=0;}
    ~VANZARI()
    {
        nr_stock=nr_vandute=0;
        stock.clear();
        vandute.clear();
    }
    int cate_stock(){return nr_stock;}
    int operator-=(int i)
    {
        if(i>nr_stock) return 0;
        else
        {
            vinde(i);
            return 1;
        }
    }
    void vinde (int i)
    {
        vandute.push_back(stock[i-1]);
        stock.erase(stock.begin()+(i-1));
        nr_stock--;
        nr_vandute++;
    }
    void adaugare_stock()
    {
        string sters;
        int n, op;
        cout<<"Numarul de Masini de introdus: ";
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cout<<">Ce tip este MASINA "<<i+1<<"?";
            cout<<"\n\t1.MINI";
            cout<<"\n\t2.MICA";
            cout<<"\n\t3.HATCHBACK COMPACTA";
            cout<<"\n\t4.COMBI COMPACTA ";
            cout<<"\n\t5.SEDAN COMPACTA \n";
            cout<<"Alegeti: ";
            cin>>op;
            getline(cin,sters);
            T* elm;
            elm=NULL;
            switch(op)
            {
            case 1:
                {
                    elm=dynamic_cast<MINI*>(elm);
                    elm=new MINI;
                    break;
                }
            case 2:
                {
                    elm=dynamic_cast<MICA*>(elm);
                    elm=new MICA;
                    break;
                }
            case 3:
                {
                    elm=dynamic_cast<HATCHBACK*>(elm);
                    elm=new HATCHBACK;
                    break;
                }
            case 4:
                {
                    elm=dynamic_cast<COMBI*>(elm);
                    elm=new COMBI;
                    break;
                }
            case 5:
                {
                    elm=dynamic_cast<SEDAN*>(elm);
                    elm=new SEDAN;
                    break;
                }
            default:
                {
                elm=new T;
                break;
                }
            }
            cout<<"\tSe citeste Masina de tipul "<<elm->tip()<<" :\n";
            cin>>(*elm);
            try
            {
                if(elm->check()) throw elm->check();
            }
            catch(int x)
            {
                cout<<"\nELEMENT INTRODUS INVALID\n\n";
                delete elm;
                continue;
            }
            elm=dynamic_cast<T*> (elm);
            stock.push_back(elm);
            nr_stock++;
        }
    }

    void adaugare_stock_fisier(char* fis)
    {ifstream f (fis);
        T pt_tip;
        string sters;
        int n;
        f>>n;
        getline(f,sters);
        for(int i=0;i<n;i++)
        {
            T* elm=new T;
            f>>(*elm);
            stock.push_back(elm);
            nr_stock++;
        }
    f.close();
    }

    void afis_stock()
    {cout<<"\n";
        T pt_tip;

        if(nr_stock==0) cout<<"Nu exista masini in stoc.\n";
        else
        {
        cout<<"Masini EXISTENTE IN STOC:\n";
        for(int i=0;i<nr_stock;i++)
            cout<<*(stock[i]);
        }
    }
    void afis_vandute()
    {cout<<"\n";
        T pt_tip;
        if(nr_vandute==0) cout<<"Nu s-au vandut inca masini.\n";
        else
        {
        cout<<"\tMasini VANDUTE :\n";
        for(int i=0;i<nr_vandute;i++)
            cout<<*(vandute[i]);
        }

    }
};


template <>
class VANZARI<unsigned>
{
    int nr_stock;
    int nr_vandute;
    vector<MONOVOLUME*> stock;
    vector<MONOVOLUME*> vandute;
public:
    VANZARI(){nr_stock=nr_vandute=0;}
    ~VANZARI()
    {
        nr_stock=nr_vandute=0;
        stock.clear();
        vandute.clear();
    }
    int cate_stock(){return nr_stock;}
    int operator-=(int i)
    {
        if(i>nr_stock) return 0;
        else
        {
            vinde(i);
            return 1;
        }
    }
    void vinde (int i)
    {
        vandute.push_back(stock[i-1]);
        stock.erase(stock.begin()+(i-1));
        nr_stock--;
        nr_vandute++;
    }

    void adaugare_stock()
    {
        string sters;
        int n, op;
        cout<<"Numarul de Masini de introdus: ";
        cin>>n;
        for(int i=0;i<n;i++)
        {   MONOVOLUME* elm;
            cout<<">Ce fel de MONOVOLUM "<<i+1<<"?";
            cout<<"\n\t1.NOU";
            cout<<"\n\t2.SECOND HAND\n";
            cout<<"Alegeti: ";
            cin>>op;
            getline(cin,sters);
            switch(op)
            {
            case 1:
                {
                    elm=dynamic_cast<MONOV_NOU*>(elm);
                    elm=new MONOV_NOU;
                    break;
                }
            case 2:
                {
                    elm=dynamic_cast<MONOV_SH*>(elm);
                    elm=new MONOV_SH;
                    break;
                }
            default:
                {
                cout<<"OPTIUNE INTRODUSA INVALIDA";
                i--;
                continue;
                }
            }
            cout<<"\tSe citeste Masina de tipul "<<elm->tip()<<" :\n";
            cin>>(*elm);
            try
            {
                if(elm->check()) throw elm->check();
            }
            catch(int x)
            {
                cout<<"\nELEMENT INTRODUS INVALID\n\n";
                delete elm;
                continue;
            }
            elm=dynamic_cast<MONOVOLUME*> (elm);
            stock.push_back(elm);
            nr_stock++;
        }

    }

    void afis_stock()
    {cout<<"\n";
        if(nr_stock==0) cout<<"Nu exista masini in stoc.\n";
        else
        {
        cout<<"Masini EXISTENTE IN STOC:\n";
        for(int i=0;i<nr_stock;i++)
            cout<<*(stock[i]);
        }
    }

    void afis_vandute()
    {cout<<"\n";
        if(nr_vandute==0) cout<<"Nu s-au vandut inca masini.\n";
        else
        {
        cout<<"\tMasini VANDUTE :\n";
        for(int i=0;i<nr_vandute;i++)
            cout<<*(vandute[i]);
        }

    }

};
