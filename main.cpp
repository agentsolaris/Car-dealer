#include "LIBR/FISIERE.h"
#include<windows.h>
int main()
{

    VANZARI<AUTOMOBIL> V;
    VANZARI<unsigned> M;
    int op=1;
    while(op)
    {
        //system("pause");
        //system("cls");
        cout<<"1.ADD AUTOMOBILES IN STOCK\n";
        cout<<"2.ADD MONOVOLUMES IN STOCK\n";
        cout<<"3.SELL AUTOMOBILES\n";
        cout<<"4.SELL MONOVOLUMES\n";
        cout<<"5.SHOW AUTOMOBILES\n";
        cout<<"6.SHOW MONOVOLUMES\n";
        cout<<"0.EXIT\n";
        cin>>op;
        switch(op)
        {
        case 1:
        {
            V.adaugare_stock();
            break;
        }
        case 2:
        {
            M.adaugare_stock();
            break;
        }
        case 3:
        {
            V.afis_stock();
            cout<<"CHOSE A NUMBER FROM 1 TO "<<V.cate_stock()<<": ";
            int ii;
            cin>>ii;
            ///V-=ii;
            V.vinde(ii);
            break;
        }
        case 4:
        {
            M.afis_stock();
            cout<<"CHOSE A NUMBER FROM 1 TO "<<M.cate_stock()<<": ";
            int ii;
            cin>>ii;
            M.vinde(ii);
            break;
        }
        case 5:
        {
            int op1;
            cout<<"\t1.SHOW STOCK\n";
            cout<<"\t2.SHOW SOLD\n";
            cin>>op1;
            if(op1==1)
                V.afis_stock();
            if(op==2)
                V.afis_vandute();
            break;
        }
        case 6:
        {
            int op1;
			cout << "\t1.SHOW STOCK\n";
			cout << "\t2.SHOW SOLD\n";
            cin>>op1;
            if(op1==1)
                M.afis_stock();
            if(op==2)
                M.afis_vandute();
            break;
        }
        case 0:
        {
            cout<<"HAVE A NICE DAY :)\n";
            break;
        }
        default:
        {
            cout<<"INVALID INPUT\n";
            break;
        }
        }

    }

    return 0;
}
