#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
  vector<long long>a,b;
  for(int i=0;i<3;++i){
    long long x,y;
    cin>>x>>y;
    a.push_back(x);
    b.push_back(y);
  }

  cout<<endl;
  cout<<"x = a (mod b)\n\n";
  for(int i=0;i<a.size();++i){
    cout<<"           x = "<<a[i]<<" (mod "<<b[i]<<")\n";
  }

  cout<<endl;
  long long N=b[0];
  for(int i=1;i<a.size();++i){
    N=N*b[i];
  }

  cout<<"N = "<<N<<endl<<endl;

  vector<long long >n;
  n.push_back(b[1]*b[2]);
  n.push_back(b[0]*b[2]);
  n.push_back(b[0]*b[1]);

  for(int i=0;i<a.size();++i){
    cout<<"     n("<<i+1<<") = "<<n[i]<<"\n";
  }

  cout<<endl<<endl<<endl;

  vector<long long >p;
  for(int i=0;i<3;++i){
    long long x=n[i]%b[i];
    if(x != a[i]){
      long long y=b[i];
      bool flag=true;
      while(y--){
        if( (x*y)%b[i] == 1 && (x*y)%b[i] != a[i]  ){
          long long q=b[i];
          while(q--){
            if( (x*y*q)%b[i] == a[i] ){
              p.push_back( ( (x*y)%b[i] ) * n[i] * ( (y*q)%b[i] ) );
              cout<<"for "<<a[i]<<" (mod "<<b[i]<<") = "<<p[i]<<endl;
              flag=false;
                break;
            }
          }
          if(!flag)
            break;
        }
        else if((x*y)%b[i] == a[i] && (x*y)%b[i] == 1 ){

          p.push_back(y*n[i]);
          cout<<"for "<<a[i]<<" (mod "<<b[i]<<") = "<<p[i]<<endl;
          break;
        }

      }
    }
    else{
      cout<<"for "<<a[i]<<" (mod "<<b[i]<<") = "<<n[i]<<endl;
      p.push_back(n[i]);
    }
  }

  long long sum = 0;
  for(int i=0;i<p.size();++i){
    sum+=p[i];
  }
  cout<<endl;
  cout<<"X = "<<sum<<endl;
  cout<<"X = "<<sum<<" (mod "<<N<<")"<<endl;
  cout<<"X = "<<sum%N<<" (mod "<<N<<")"<<endl<<endl;
  cout<<"X = "<<sum%N<<" + "<<N<<" k , 1 <= k <= n , z\n";
  
  return 0;
}