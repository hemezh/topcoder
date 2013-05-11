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

class ImprovingStatistics {
	public:
	int howManyGames(ll p, ll w) {
		ll cur = w*100/p + 1, i, lo = 0, mid, hi = 1LL<<30; 
		FOR(i, 0, 100){
			mid = (lo+hi)/2;
			if((w+mid)*100/(p+mid) >= cur){
				hi= mid;
			}
			else lo = mid;
		}	
		if(hi == 1<<30) hi = -1;
		return hi;		
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
			int played                = 10;
			int won                   = 8;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = ImprovingStatistics().howManyGames(played, won);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int played                = 100;
			int won                   = 80;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = ImprovingStatistics().howManyGames(played, won);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int played                = 47;
			int won                   = 47;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = ImprovingStatistics().howManyGames(played, won);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int played                = 99000;
			int won                   = 0;
			int expected__            = 1000;

			clock_t start__           = clock();
			int received__            = ImprovingStatistics().howManyGames(played, won);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int played                = 1000000000;
			int won                   = 470000000;
			int expected__            = 19230770;

			clock_t start__           = clock();
			int received__            = ImprovingStatistics().howManyGames(played, won);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int played                = ;
			int won                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ImprovingStatistics().howManyGames(played, won);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int played                = ;
			int won                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ImprovingStatistics().howManyGames(played, won);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int played                = ;
			int won                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ImprovingStatistics().howManyGames(played, won);
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
