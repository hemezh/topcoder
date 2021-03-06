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

 
class HuffmanDecoding {
public:
	string decode(string a, vector <string> dictionary){
		map<string, char> m;
		int i;
		FOR(i, 0, SZ(dictionary))
			m[dictionary[i]] = 'A' + i;
		string s = "", ans = "";
		FOR(i, 0, SZ(a)){
			s += a[i];
			if(m[s]){
				ans += m[s];
				s = "";
			}
		}
		return ans;
	} 
};

 
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, string p0, vector <string> p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	HuffmanDecoding *obj;
	string answer;
	obj = new HuffmanDecoding();
	clock_t startTime = clock();
	answer = obj->decode(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p2 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p2;
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
	
	string p0;
	vector <string> p1;
	string p2;
	
	{
	// ----- test 0 -----
	p0 = "101101";
	string t1[] = {"00","10","01","11"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "BDC";
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "10111010";
	string t1[] = {"0","111","10"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "CBAC";
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "0001001100100111001";
	string t1[] = {"1","0"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "BBBABBAABBABBAAABBA";
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = "111011011000100110";
	string t1[] = {"010","00","0110","0111","11","100","101"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "EGGFAC";
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = "001101100101100110111101011001011001010";
	string t1[] = {"110","011","10","0011","00011","111","00010","0010","010","0000"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "DBHABBACAIAIC";
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
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
