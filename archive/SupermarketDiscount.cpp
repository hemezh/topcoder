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

class SupermarketDiscount {
	public:
	int minAmount(vector <int> g) {
		int i;
		sort(RA(g));
		if(g[0]>=50 && g[1] >=50 && g[2] >=50) return g[0]+g[1]+g[2] - 30;
		if(g[2] >= 50 && g[0]+g[1] >= 50) return g[0]+g[1]+g[2] - 20;
		if(g[2]+g[1] >= 50) return g[0]+g[1]+g[2] - 10;
		if(g[0]+g[1]+g[2] >=50) return g[0]+g[1]+g[2]-10;
		return g[0]+g[1]+g[2];
		
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
			int goods[]               = {46, 62, 9};
			int expected__            = 97;

			clock_t start__           = clock();
			int received__            = SupermarketDiscount().minAmount(vector <int>(goods, goods + (sizeof goods / sizeof goods[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int goods[]               = {50, 62, 93};
			int expected__            = 175;

			clock_t start__           = clock();
			int received__            = SupermarketDiscount().minAmount(vector <int>(goods, goods + (sizeof goods / sizeof goods[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int goods[]               = {5, 31, 15};
			int expected__            = 41;

			clock_t start__           = clock();
			int received__            = SupermarketDiscount().minAmount(vector <int>(goods, goods + (sizeof goods / sizeof goods[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int goods[]               = {5, 3, 15};
			int expected__            = 23;

			clock_t start__           = clock();
			int received__            = SupermarketDiscount().minAmount(vector <int>(goods, goods + (sizeof goods / sizeof goods[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int goods[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SupermarketDiscount().minAmount(vector <int>(goods, goods + (sizeof goods / sizeof goods[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int goods[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SupermarketDiscount().minAmount(vector <int>(goods, goods + (sizeof goods / sizeof goods[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int goods[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SupermarketDiscount().minAmount(vector <int>(goods, goods + (sizeof goods / sizeof goods[0])));
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
