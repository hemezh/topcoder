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

class BirthNumbersValidator {
	public:
	vector <string> validate(vector <string> test) {
		int i;
		FOR(i, 0, SZ(test)){
			string s = test[i], a = "YES";
			int g = 1, f = 0, y;
			int x, days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
			stringstream ss;
			ss << s.substr(0, 2); ss >> x; ss.clear();
			if(x < 7) x += 2000; else x += 1900;
			if(x%400==0 || (x%4==0 && x%100)) f = 1;
			if(f) days[1]++;
			ss << s.substr(2, 2); ss >> x; ss.clear();
			if(x>50) x -= 50;
			if(x<1 || x>12) g = 0;
			ss << s.substr(4, 2); ss >> y; ss.clear();
			if((x <= 12 && days[x-1] < y) || y < 1) g = 0;
			ll z;
			ss << test[i]; ss >> z;
			if(z%11) g = 0;
			if(!g) a = "NO";
			test[i] = a;
		}
		return test;
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
	
	template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }
	template<> ostream& operator<<(ostream &os, const vector<string> &v) { os << "{"; for (vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }

	int verify_case(int casenum, const vector <string> &expected, const vector <string> &received, clock_t elapsed) { 
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
			string test[]             = {"4562895854"};
			string expected__[]       = {"NO" };

			clock_t start__           = clock();
			vector <string> received__ = BirthNumbersValidator().validate(vector <string>(test, test + (sizeof test / sizeof test[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			string test[]             = {"8154121239"};
			string expected__[]       = {"YES" };

			clock_t start__           = clock();
			vector <string> received__ = BirthNumbersValidator().validate(vector <string>(test, test + (sizeof test / sizeof test[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			string test[]             = {"8134120005"};
			string expected__[]       = {"NO" };

			clock_t start__           = clock();
			vector <string> received__ = BirthNumbersValidator().validate(vector <string>(test, test + (sizeof test / sizeof test[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			string test[]             = {"8102310007","8104121235"};
			string expected__[]       = {"NO", "NO" };

			clock_t start__           = clock();
			vector <string> received__ = BirthNumbersValidator().validate(vector <string>(test, test + (sizeof test / sizeof test[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			string test[]             = {"0411131237"};
			string expected__[]       = {"YES" };

			clock_t start__           = clock();
			vector <string> received__ = BirthNumbersValidator().validate(vector <string>(test, test + (sizeof test / sizeof test[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string test[]             = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = BirthNumbersValidator().validate(vector <string>(test, test + (sizeof test / sizeof test[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			string test[]             = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = BirthNumbersValidator().validate(vector <string>(test, test + (sizeof test / sizeof test[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			string test[]             = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = BirthNumbersValidator().validate(vector <string>(test, test + (sizeof test / sizeof test[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
