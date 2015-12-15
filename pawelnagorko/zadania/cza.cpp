#include <iostream>
using namespace std;

int main()
{
  int a=0,b=0,c=0,d=0;
  cin>>d>>c;
  a=d/c;
  if(a/3600>9){
  cout<<a/3600<<":";
  }
  else{
   cout<<0<<a/3600<<":";   
  }
  b=a%3600;
  if(b/60>9){
  cout<<b/60<<":";
  }
  else{
  cout<<0<<b/60<<":";   
  }
    if(a%60>9){
  cout<<a%60;
  }
  else{
   cout<<0<<a%60;   
  }
  return 0;
}
