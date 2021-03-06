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

 
class FoxAndMp3Easy {
public:
	vector <string> playList(int n){
		vs v;
		int i, x, j;
		FOR(i, 1, n+1){
			string s = "";
			x = i;
			while(x){
				char c = '0'+x%10;
				s = c + s;
				x /= 10;
			}
			s += ".mp3";
			v.push_back(s);
		}
		sort(RA(v));
		if(SZ(v) > 50)
		v.erase(v.begin()+50, v.end());
		return v;
	} 
};

 
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, bool hasAnswer, vector <string> p1) {
	cout << "Test " << testNum << ": [" << p0;
	cout << "]" << endl;
	FoxAndMp3Easy *obj;
	vector <string> answer;
	obj = new FoxAndMp3Easy();
	clock_t startTime = clock();
	answer = obj->playList(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p1.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << "\"" << p1[i] << "\"";
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << answer[i] << "\"";
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p1.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p1[i]) {
					res = false;
				}
			}
		}
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
	vector <string> p1;
	
	{
	// ----- test 0 -----
	p0 = 3;
	string t1[] = {"1.mp3","2.mp3","3.mp3"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 10;
	string t1[] = {"1.mp3","10.mp3","2.mp3","3.mp3","4.mp3","5.mp3","6.mp3","7.mp3","8.mp3","9.mp3"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 16;
	string t1[] = {"1.mp3","10.mp3","11.mp3","12.mp3","13.mp3","14.mp3","15.mp3","16.mp3","2.mp3","3.mp3","4.mp3","5.mp3","6.mp3","7.mp3","8.mp3","9.mp3"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 32;
	string t1[] = {"1.mp3","10.mp3","11.mp3","12.mp3","13.mp3","14.mp3","15.mp3","16.mp3","17.mp3","18.mp3","19.mp3","2.mp3","20.mp3","21.mp3","22.mp3","23.mp3","24.mp3","25.mp3","26.mp3","27.mp3","28.mp3","29.mp3","3.mp3","30.mp3","31.mp3","32.mp3","4.mp3","5.mp3","6.mp3","7.mp3","8.mp3","9.mp3"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 109;
	string t1[] = {"1.mp3","10.mp3","100.mp3","101.mp3","102.mp3","103.mp3","104.mp3","105.mp3","106.mp3","107.mp3","108.mp3","109.mp3","11.mp3","12.mp3","13.mp3","14.mp3","15.mp3","16.mp3","17.mp3","18.mp3","19.mp3","2.mp3","20.mp3","21.mp3","22.mp3","23.mp3","24.mp3","25.mp3","26.mp3","27.mp3","28.mp3","29.mp3","3.mp3","30.mp3","31.mp3","32.mp3","33.mp3","34.mp3","35.mp3","36.mp3","37.mp3","38.mp3","39.mp3","4.mp3","40.mp3","41.mp3","42.mp3","43.mp3","44.mp3","45.mp3"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
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
