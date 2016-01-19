
#include <iostream>
#include <string>
using namespace std;

int main()
{
  int a=0;
  cin>>a;
  for(int i=0;i<(a-1)/2;i++){
        for(int j=0;j<a;j++){
                if(j!=0&&j!=a-1){
                cout<<" ";
                }
                if(j==0){
                cout<<"H";
                }
                if(j==a-1){
                cout<<"H"<<endl;
                }
        }
    }
for(int i=0;i<a;i++){
                if(i==a-1){
                cout<<"H"<<endl;
                }else{
                cout<<"H";    
                }
    }
    for(int i=0;i<(a-1)/2;i++){
        for(int j=0;j<a;j++){
                if(j!=0&&j!=a-1){
                cout<<" ";
                }
                if(j==0){
                cout<<"H";
                }
                if(j==a-1){
                cout<<"H"<<endl;
                }
        }
    }
}
