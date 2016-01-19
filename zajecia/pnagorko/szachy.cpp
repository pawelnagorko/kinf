#include <iostream>
#include <string>
using namespace std;
 
int main()
{
    //teorzenie zmiennych
        //m.n-szer. i wys. planszy
            //opis
          //  cout<<"podaj wymiary planszy\n";
            int a=0;
            int m=0;
            int n=0;
        //czytanie ich wartosci
        cin>>m>>n;
        //tab.dwu wymiarowa tab
        int tab[n][m];
    //czytanie danych
        //opis
           //cout<<"podaj punktacje pol\n"; 
            for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        cin>>tab[i][j]; 
                    }
                }
 
	//cout << "odczytalem" << endl;
 
    //liczenie 
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                        for(int k=0;k<n;k++){
                            for(int l=0;l<m;l++){
                                //glowny warunek jezeli(if)wspo.x 1wiezy(i)nie rowna sie(=!)wspo.x 2wiezy(k)oraz(&&)...
                                if(i!=k&&j!=l){
                                    //najwieksza wartosc pol na ktorych stoi wieza
                                    if(tab[i][j]+tab[k][l]>a){
                                        a=tab[i][j]+tab[k][l];    
                                    }
                                }
                            }
                        }
                    }
                }
    //wynik
        //opis
        //cout<<"wynik\n"<<endl;
	cout<<a;
    return 0;
}				
