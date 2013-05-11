#include <string>
#include <vector>
#include <map>
#include <cstdio>
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

bool tab[101][101][101];
class ParallelepipedUnion {
public:
	int getVolume(vector <string> p){
		int i, a, b, c, x1, x2, y1, y2, z1, z2;
		memset(tab, 0, sizeof tab);
		FOR(i, 0, SZ(p)){
			sscanf(p[i].c_str(), "%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);
			FOR(a, x1, x2) FOR(b, y1, y2) FOR(c, z1, z2)
				tab[a][b][c] = 1;
		}
		int ans = 0;
		FOR(a, 0, 101) FOR(b, 0, 101) FOR(c, 0, 101)
			if(tab[a][b][c]) ans++;
		return ans;
	} 
};

 
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	ParallelepipedUnion *obj;
	int answer;
	obj = new ParallelepipedUnion();
	clock_t startTime = clock();
	answer = obj->getVolume(p0);
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
	
	vector <string> p0;
	int p1;
	
	{
	// ----- test 0 -----
	string t0[] = {"1 1 1 4 4 2","3 2 1 5 3 3"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 12;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"1 1 1 2 2 2","3 3 3 4 4 4"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"1 10 20 5 15 23","2 12 22 3 14 23"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 60;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"28 31 21 67 60 81","60 1 21 67 50 81"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 80460;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"34 3 50 37 6 53","36 1 51 38 4 55"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 49;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
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