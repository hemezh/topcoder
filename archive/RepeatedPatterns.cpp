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

class RepeatedPatterns {
	public:
	long long findZeroSegment(string P1, string P2, string zc) {
		int idx, i, pos, j, f = 0;
		sscanf(zc.c_str(), "%d", &i);
		string x, z = string(i, '0');
		ll ans = 0;
		FOR(i, 0, 17){
			x = "";
			FOR(j, 0, 17-i) x += P1;
			FOR(j, 0, i) x += P2;
			if(x.find(z) != string::npos){
				idx = i;
				pos = x.find(z);
				f = 1;
				break;
			}		
			ans += 1e6*SZ(P1) + i*SZ(P2);	
		}
		ans += pos;
		if(!f) ans = -1;
		return ans;
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
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
			string P1                 = "111010100001010";
			string P2                 = "010000001000";
			string zeroCount          = "3";
			long long expected__      = 7;

			clock_t start__           = clock();
			long long received__      = RepeatedPatterns().findZeroSegment(P1, P2, zeroCount);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string P1                 = "1101010010";
			string P2                 = "0001000";
			string zeroCount          = "3";
			long long expected__      = 9999999;

			clock_t start__           = clock();
			long long received__      = RepeatedPatterns().findZeroSegment(P1, P2, zeroCount);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string P1                 = "1101010010";
			string P2                 = "0001000";
			string zeroCount          = "5";
			long long expected__      = 20000011;

			clock_t start__           = clock();
			long long received__      = RepeatedPatterns().findZeroSegment(P1, P2, zeroCount);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string P1                 = "10101010";
			string P2                 = "101010101010";
			string zeroCount          = "9876543219876";
			long long expected__      = -1;

			clock_t start__           = clock();
			long long received__      = RepeatedPatterns().findZeroSegment(P1, P2, zeroCount);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string P1                 = "11111111111111111111111111";
			string P2                 = "0";
			string zeroCount          = "9876543219876";
			long long expected__      = -1;

			clock_t start__           = clock();
			long long received__      = RepeatedPatterns().findZeroSegment(P1, P2, zeroCount);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string P1                 = ;
			string P2                 = ;
			string zeroCount          = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = RepeatedPatterns().findZeroSegment(P1, P2, zeroCount);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string P1                 = ;
			string P2                 = ;
			string zeroCount          = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = RepeatedPatterns().findZeroSegment(P1, P2, zeroCount);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string P1                 = ;
			string P2                 = ;
			string zeroCount          = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = RepeatedPatterns().findZeroSegment(P1, P2, zeroCount);
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
