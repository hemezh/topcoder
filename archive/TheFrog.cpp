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
#define X first
#define Y second
int D;
vector <int> L, R;
class TheFrog {
public:
	bool check(double val ){
		int i;
		double dist;		
		dist = val;
		bool f = true;
		while(dist < D){
			FOR(i, 0, SZ(L)){
				if(dist > L[i] && dist < R[i])
					f = false;
			}
			dist += val;
		}
		return f;
	}
	double getMinimum(int d, vector <int> l, vector <int> r) {
		D = d; L = l; R = r;
		double hi = D, lo = 0, mid;
		int i;
		FOR(i, 0, D-1){
			if(!check(i) && check(i+1)){
				hi = i;
				lo = i-1;
				break;
			}
		}
		cout << hi;
		int step, j;
		FOR(step, 0, 100){
			mid = (hi+lo)/2;
			if(check(mid)){
				hi = mid;
			}
			else
				lo = mid;
		}
		return hi;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, vector <int> p2, bool hasAnswer, double p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}";
	cout << "]" << endl;
	TheFrog *obj;
	double answer;
	obj = new TheFrog();
	clock_t startTime = clock();
	answer = obj->getMinimum(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = fabs(p3 - answer) <= 1e-9 * max(1.0, fabs(p3));
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
	
	int p0;
	vector <int> p1;
	vector <int> p2;
	double p3;
	
	{
	// ----- test 0 -----
	p0 = 16;
	int t1[] = {2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {7};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 7.0;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 25;
	int t1[] = {11,3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {21,7};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 10.5;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 100;
	int t1[] = {0};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {100};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 100.0;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 100;
	int t1[] = {0,50};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {50,100};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 50.0;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 30000;
	int t1[] = {17,25281,5775,2825,14040};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {55,26000,5791,3150,14092};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 787.8787878787879;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
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
