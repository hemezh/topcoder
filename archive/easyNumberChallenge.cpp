#include<iostream>
#include <cmath>
#define MOD 1073741824
#define SIZE 1000000
#define FOR(i,a,b) for(i=a;i<b;i++)
using namespace std;
int store[1000010];
int primes[78500];
bool arr[SIZE];
void Addsol(){
    int size = 0;
    primes[0] = 2;
    for(int i = 3; i < SIZE; i += 2)
        if(arr[i])
            primes[++size] = i;
}
 
void initialize(){
    arr[2] = true;
    for( int i = 3; i < SIZE; i+= 2) {
        arr[i] = true;
    }
}
void findprimes(){
    int i, j, tmp;
    tmp = (int)sqrt(SIZE);
    for( i = 3; i <= tmp; i += 2){
        if(arr[i]){
            for( j = i*i; j < SIZE; j += i)
                arr[j] = false;
        }
    }
} 
int divCount(int n){
	int i,j,t=1,temp,r;
	i = 0, j = (int)sqrt(n);
    for( ; primes[i] <= j+1 && i < 78498; ++i){
        temp = primes[i];
        r = 0;
        while( n%temp == 0){
            ++r;
            n /= temp;
        }
		if(arr[n]){
			t*=2;
			n=1;
		}
        if(r)
			t *= (r+1);
    }
    return t;
}
int main(){
	int i,k,j,a,b,c;
	initialize();
	findprimes();
	Addsol();
	cin>>a>>b>>c;
	int sum=0;
	FOR(i,1,a+1){
		FOR(j,1,b+1){
			FOR(k,1,c+1){
				if(!store[i*j*k])
					store[i*j*k]=divCount(i*j*k);
				sum+=store[i*j*k];
				if(sum>MOD)
					sum-=MOD;
			}
		}
	}
	cout<<sum;
}
