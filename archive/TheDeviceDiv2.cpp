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

 
class TheDeviceDiv2 {
public:
	string identify(vector <string> p){
		int i, j;
		FOR(i, 0, SZ(p[0])){
			int o = 0, z = 0; 
			FOR(j, 0, SZ(p))
				if(p[j][i] == '1')
					o++;
				else
					z++;
			if(o < 2 || z < 1)
				return "NO";
		}
		return "YES";
	} 
};

 
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	TheDeviceDiv2 *obj;
	string answer;
	obj = new TheDeviceDiv2();
	clock_t startTime = clock();
	answer = obj->identify(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p1 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
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
	string p1;
	
	{
	// ----- test 0 -----
	string t0[] = {"010","011","000"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "NO";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"1","0","1","0"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "YES";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"11111"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "NO";
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"0110011","0101001","1111010","1010010"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "NO";
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"101001011","011011010","010110010","111010100","111111111"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "YES";
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