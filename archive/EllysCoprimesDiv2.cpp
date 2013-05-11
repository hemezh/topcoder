#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <complex>

 
using namespace std;
 
typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<int> pnt;
typedef pair<int, int> pii;

#define FOR(i,a,b) for(i=a;i<b;i++) 
#define RA(x) (x).begin(), (x).end()
#define REV(x) reverse(RA(x))
#define FE(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())
#define X first
#define Y second

class EllysCoprimesDiv2 {
	public:
	int gcd(int a, int b){ return __gcd(a, b);}
	vector<int> getDiv(int n){
		vector<int> v;
		for(int i = 2; i*i <= n; i++){
			if(n%i == 0){
				v.push_back(i);
				if(n != i*i)
					v.push_back(n/i);
			}
		}
		return v;
	}
	int getCount(vector <int> n) {
		sort(RA(n));
		int i, c = 0, j, k, f, ff;
		FOR(i, 1, SZ(n)){
			f = ff = 0;
			if(gcd(n[i], n[i-1])==1) continue;
			FOR(j, n[i-1]+1, n[i]) {
				if(gcd(j, n[i]) == 1 && gcd(j, n[i-1]) == 1){
					c++; f = 1; break;
				}
			}
			if(!f)
			FOR(j, n[i-1]+1, n[i]){
				if(gcd(j, n[i-1]) == 1) FOR(k, j+1, n[i]){
					if(gcd(k, n[i]) == 1 && gcd(j, k) == 1){
						c +=2; ff = 1; break;
					}
				}
				if(ff) break;
			}
		}
		return c;
	}
};



// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			cerr << "No test cases run." << endl;
		} else if (correct < total) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int numbers[]             = {2200, 42, 2184, 17};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = EllysCoprimesDiv2().getCount(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int numbers[]             = {13, 1, 6, 20, 33};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = EllysCoprimesDiv2().getCount(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int numbers[]             = {7, 42};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = EllysCoprimesDiv2().getCount(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int numbers[]             = {55780, 44918, 55653, 4762, 41536, 40083, 79260, 7374, 24124, 91858, 7856, 12999, 64025, 12706, 19770, 71495, 32817, 79309, 53779, 8421, 97984, 34586, 893, 64549, 77792, 12143, 52732, 94416, 54207, 51811, 80845, 67079, 14829, 25350, 22976, 23932, 62273, 58871, 82358, 13283, 33667, 64263, 1337, 42666};
			int expected__            = 15;

			clock_t start__           = clock();
			int received__            = EllysCoprimesDiv2().getCount(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int numbers[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysCoprimesDiv2().getCount(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int numbers[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysCoprimesDiv2().getCount(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int numbers[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysCoprimesDiv2().getCount(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}
 

int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE
