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

class KnightTour {
	public:
	bool okay(int a, int b, int c, int d){
		if(abs(a-c) == 2 && abs(b-d) == 1) return 1;
		if(abs(a-c) == 1 && abs(b-d) == 2) return 1;
		return 0;
	}
	string checkTour(vector <string> cells) {
		int i, arr[6][6] = {0}, prex = 0, prey = 0, x, y, stx, sty, c = 0, j;
		FOR(i, 0, SZ(cells)){
			string s = cells[i];
			char a, b;
			stringstream ss; ss << s;
			ss >> a >> b;
			x = a - 'A', y = b - '1';
			if(!i) stx = x, sty = y;
			if((i && !okay(x, y, prex, prey)) || arr[x][y])
				return "Invalid";
			arr[x][y] = 1;
			prex = x; prey = y;
		}
		FOR(i, 0, 6) FOR(j, 0, 6) if(arr[i][j]) c++;
		if(okay(stx, sty, x, y) && c == 36) return "Valid";
		return "Invalid";
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
	
	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			string cells[]            = {"F4", "E6", "D4", "E2", "C1", "A2", "C3", "D5", "F6", "E4", "F2", "D1", "B2", "A4", "B6", "C4", "A5", "B3", "A1", "C2", "E1", "F3", "D2", "B1", "A3", "B5", "D6", "F5", "E3", "F1", "E5", "C6", "B4", "A6", "C5", "D3"};
			string expected__         = "Valid";

			clock_t start__           = clock();
			string received__         = KnightTour().checkTour(vector <string>(cells, cells + (sizeof cells / sizeof cells[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string cells[]            = {"A1", "C2", "E3", "F5", "D4", "B3",
 "A1", "C2", "E3", "F5", "D4", "B3", 
 "A1", "C2", "E3", "F5", "D4", "B3", 
 "A1", "C2", "E3", "F5", "D4", "B3", 
 "A1", "C2", "E3", "F5", "D4", "B3", 
 "A1", "C2", "E3", "F5", "D4", "B3"}
;
			string expected__         = "Invalid";

			clock_t start__           = clock();
			string received__         = KnightTour().checkTour(vector <string>(cells, cells + (sizeof cells / sizeof cells[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string cells[]            = {"D4", "F5", "D6", "B5", "A3", "B1", 
 "D2", "F1", "E3", "D1", "F2", "E4", 
 "F6", "D5", "B6", "A4", "B2", "C4", 
 "A5", "C6", "E5", "F3", "E1", "C2", 
 "A1", "B3", "C5", "E6", "F4", "E2", 
 "C3", "A2", "C1", "D3", "B4", "A6"};
			string expected__         = "Invalid";

			clock_t start__           = clock();
			string received__         = KnightTour().checkTour(vector <string>(cells, cells + (sizeof cells / sizeof cells[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string cells[]            = {"D4", "F5", "D6", "B5", "A3", "B1", 
 "D2", "F1", "E3", "D1", "F2", "E4", 
 "F6", "D5", "B6", "A4", "B2", "C4", 
 "A5", "C6", "E5", "F3", "E1", "C2", 
 "A1", "B3", "C5", "A6", "B4", "A2", 
 "C3", "E2", "C1", "D3", "F4", "E6"};
			string expected__         = "Valid";

			clock_t start__           = clock();
			string received__         = KnightTour().checkTour(vector <string>(cells, cells + (sizeof cells / sizeof cells[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string cells[]            = {"C5", "D3", "F2", "D1", "B2", "A4", 
 "B6", "D5", "C3", "E4", "F6", "B3", 
 "A1", "C2", "E1", "F3", "E5", "C6", 
 "A5", "C4", "A3", "B1", "D2", "F1", 
 "E3", "F5", "D6", "B5", "D4", "E6", 
 "F4", "E2", "C1", "A2", "B4", "A6"}
;
			string expected__         = "Invalid";

			clock_t start__           = clock();
			string received__         = KnightTour().checkTour(vector <string>(cells, cells + (sizeof cells / sizeof cells[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string cells[]            = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = KnightTour().checkTour(vector <string>(cells, cells + (sizeof cells / sizeof cells[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string cells[]            = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = KnightTour().checkTour(vector <string>(cells, cells + (sizeof cells / sizeof cells[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string cells[]            = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = KnightTour().checkTour(vector <string>(cells, cells + (sizeof cells / sizeof cells[0])));
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
