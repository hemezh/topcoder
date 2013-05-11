#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <set>
#include <iostream>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include <utility>
#include <iterator>
#include <numeric>
#include <list>
#include <complex>
 
using namespace std;
 
typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<int> pnt;
typedef pair<int, int> pii;

#define FOR(i,a,b) for(i=a;i<b;i++) 
#define RA(x) (x).begin(), (x).end()
#define FE(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())

 
class UnfairDivision {
public:
	int albertsShare(vector <int> a){
		int n = SZ(a), i, j, k, mx = 0;
		FOR(i, 0, n-1){
			int mxa = 0, mxb = 0, mxc = 0;
			FOR(j, 0, n-1){
				if(i == j)
					continue;
				int arr[3] = {0, 0, 0};
				FOR(k, 0, min(i,j)+1)
					arr[0] += a[k];
				FOR(k, min(i,j)+1, max(i,j)+1)
					arr[1] += a[k];
				FOR(k, max(i,j)+1, n)
					arr[2] += a[k];
				sort(arr, arr+3);
				cout << arr[0] << " " << arr[1] << " " << arr[2]  << endl;
				if(mxb < arr[1] || (mxb == arr[1] && mxc < arr[2])){
					mxa = arr[0];
					mxb = arr[1];
					mxc = arr[2];
				}
			}
			mx = max(mx, mxa);
		}
		return mx;
	} 
};

 
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	UnfairDivision *obj;
	int answer;
	obj = new UnfairDivision();
	clock_t startTime = clock();
	answer = obj->albertsShare(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	vector <int> p0;
	int p1;
	
	{
	// ----- test 0 -----
	int t0[] = {40, 19, 1, 1, 19, 1, 40};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 19;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {5,5,5};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 5;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {1,1,1,1,1,1,1,1,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {1,2,3,4,5,6,7,8,9};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 10;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
 

//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
