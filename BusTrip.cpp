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
#include <fstream>
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
vi splitstr(string s)
{
	string r = s; REV(r);
    s = s + " " + r;
    vi out;
    int n;
    stringstream in(s);
    while(in >> n) out.push_back(n);
    out.erase(out.end()-1);
    return out;
}
int arr[1010][110];
class BusTrip {
	public:
	int returnTime(int N, vector <string> buses) {
		int i, j, n = SZ(buses);
		memset(arr, -1, sizeof arr);
		FOR(i, 0, SZ(buses)){
			vi v = splitstr(buses[i]);
			int t = 0, n = SZ(v), x = 0, a;
			while(t <= 1000){
				arr[t][i] = v[x];
				a = v[x];
				x = (x+1)%n;
				t += abs(v[x] - a);
			}
		}
		int x = 0;
		while(x < n && t < 1001){
			FOR(j, 0, n) if(arr[t][j] != -1){
				t = 
			}
		}
		return 0;
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
			int N                     = 3;
			string buses[]            = {"0 1 2"};
			int expected__            = 12;

			clock_t start__           = clock();
			int received__            = BusTrip().returnTime(N, vector <string>(buses, buses + (sizeof buses / sizeof buses[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 51;
			string buses[]            = {"0 5 10 15 20 25 30 35 40 50"};
			int expected__            = 1000;

			clock_t start__           = clock();
			int received__            = BusTrip().returnTime(N, vector <string>(buses, buses + (sizeof buses / sizeof buses[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 3;
			string buses[]            = {"0 1 2", "2 1 0"};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = BusTrip().returnTime(N, vector <string>(buses, buses + (sizeof buses / sizeof buses[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 5;
			string buses[]            = {"0 1 2 3 4", "3 1 2 0", "4 1 2 3 0", "1 2 0 3 4", "4 0"};
			int expected__            = 12;

			clock_t start__           = clock();
			int received__            = BusTrip().returnTime(N, vector <string>(buses, buses + (sizeof buses / sizeof buses[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 25;
			string buses[]            = {"24 14 9 7 2", "21 4 18 24 7 1 2 11 8 9 14 16 5 17 13 23 19 15 22", "12 22 24 9 1 5 10 8 7 18 16 19 4 13 17", 
 "14 5 17 9 23 7 16 22 10 4 6", "19 8 1 9 24 3 5 22 16 7 6 4 10 23 17 0 13 15", 
 "2 16 10 13 14 1 11 20 0 24 22 23 19 4 18", "19 15 18 0", "15 9 22 5 20 8 23 14 24 18 21 6 13 19", 
 "2 6 19 3 21 10 20 22 24 13 16 15 8 18 17 14 5", "19 10 1 7 5 11 21 8 14 0 17 23 12 2 3 16"};
			int expected__            = 157;

			clock_t start__           = clock();
			int received__            = BusTrip().returnTime(N, vector <string>(buses, buses + (sizeof buses / sizeof buses[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int N                     = 100;
			string buses[]            = {"0 10 30 45 60 46 39 31 20", "9 20 0 86"};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = BusTrip().returnTime(N, vector <string>(buses, buses + (sizeof buses / sizeof buses[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int N                     = ;
			string buses[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BusTrip().returnTime(N, vector <string>(buses, buses + (sizeof buses / sizeof buses[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			string buses[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BusTrip().returnTime(N, vector <string>(buses, buses + (sizeof buses / sizeof buses[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int N                     = ;
			string buses[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BusTrip().returnTime(N, vector <string>(buses, buses + (sizeof buses / sizeof buses[0])));
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
