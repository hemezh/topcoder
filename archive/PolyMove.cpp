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

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
double ans = 0;
class PolyMove {
	public:
	double area(vector<pii> v){
		int i, n = SZ(v);
		double a = 0;
		FOR(i, 0, SZ(v)) a += 1.0*v[i].X*v[(i+1)%n].Y - 1.0*v[(i+1)%n].X*v[i].Y;
		return abs(a)/2;
	}
	void solve(vector<pii> v, int i, vi arr){
		int n = SZ(v);
		if(i==n){
			int j;
			FOR(j, 0, n) cout << "("<<v[j].X<<", "<<v[j].Y<<"), ";
			cout << area(v)<<endl;
			ans = max(ans, area(v));
			return;
		}
		solve(v, i+1, arr);
		int a = (i-1)%n, b = (i+1)%n;
		if(!arr[a] && !arr[b] && !arr[i]){
			arr[i] = 1;
			int x = v[i].X, y = v[i].Y, j;
			FOR(j, 0, 4){
				int xx = x, yy = y;
				xx += dx[j], yy += dy[j];
				v[i].X = xx; v[i].Y = yy;
				solve(v, i+1, arr);
				v[i].X = x; v[i].Y = y;
			}
			arr[i] = 0;
		}		
	}
	double addedArea(vector <int> x, vector <int> y) {
		vector<pii> v;
		int i;
		ans = 0;
		FOR(i, 0, SZ(x)) v.push_back(pii(x[i], y[i]));
		double a = area(v);
		solve(v, 0, vi(SZ(x), 0));
		return ans - a;
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ(double expected, double result) { if (isnan(expected)) { return isnan(result); } else if (isinf(expected)) { if (expected > 0) { return result > 0 && isinf(result); } else { return result < 0 && isinf(result); } } else if (isnan(result) || isinf(result)) { return false; } else if (fabs(result - expected) < MAX_DOUBLE_ERROR) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error(double expected, double result) { if (isnan(expected) || isinf(expected) || isnan(result) || isinf(result) || expected == 0) return 0; return fabs(result-expected) / fabs(expected); }
	
	int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received); 
			if (rerr > 0) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			int x[]                   = {0,1,2};
			int y[]                   = {0,1,0};
			double expected__         = 1.0;

			clock_t start__           = clock();
			double received__         = PolyMove().addedArea(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int x[]                   = {0,1,1,0};
			int y[]                   = {1,1,0,0};
			double expected__         = 1.4142135623730951;

			clock_t start__           = clock();
			double received__         = PolyMove().addedArea(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 2: {
			int x[]                   = ;
			int y[]                   = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = PolyMove().addedArea(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 3: {
			int x[]                   = ;
			int y[]                   = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = PolyMove().addedArea(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			int x[]                   = ;
			int y[]                   = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = PolyMove().addedArea(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
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
