#include<iostream>
#include<algorithm>
#define FOR(i,a,b) for(i=a;i<=b;i++)
using namespace std;
int main(){
	int i,j,k,mx=0;
	int z=157;
	FOR(i,0,z)
		FOR(j,0,z)
			FOR(k,0,z){
				if(__gcd(i,j)*__gcd(i*j,k)){					
					int x=i*j*k/((__gcd(i,j)*__gcd(i*j,k)));
					mx=max(mx,x);
//					cout<<x<<endl;
				}
			}
	cout<<mx<<endl;
}
