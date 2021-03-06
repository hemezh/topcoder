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

class LateProfessor {
public:
	double getProbability(int waitTime, int walkTime, int lateTime, int bestArrival, int worstArrival){
		int i = 0, prev = waitTime, sum = 0;
		int total = prev + walkTime - lateTime;
		if(total < prev)
			total = prev;
		while(1){
			if(worstArrival < prev || bestArrival >= total)
				break;
			if(bestArrival > prev && bestArrival <= total)
				sum += min(worstArrival, total) - max(bestArrival, prev);
			else
				sum += min(worstArrival, total) - prev;
			if(worstArrival < total)
				break;
			total += waitTime + walkTime;
			prev += waitTime + walkTime;
			cout << sum << endl;			
		}
		return (sum*1.0) / (worstArrival - bestArrival);
	} 
};

 
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, int p4, bool hasAnswer, double p5) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3 << "," << p4;
	cout << "]" << endl;
	LateProfessor *obj;
	double answer;
	obj = new LateProfessor();
	clock_t startTime = clock();
	answer = obj->getProbability(p0, p1, p2, p3, p4);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p5 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = fabs(p5 - answer) <= 1e-9 * max(1.0, fabs(p5));
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
	int p1;
	int p2;
	int p3;
	int p4;
	double p5;
	
	{
	// ----- test 0 -----
	p0 = 20;
	p1 = 30;
	p2 = 10;
	p3 = 0;
	p4 = 50;
	p5 = 0.4;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 20;
	p1 = 30;
	p2 = 10;
	p3 = 30;
	p4 = 100;
	p5 = 0.42857142857142855;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 20;
	p1 = 40;
	p2 = 50;
	p3 = 0;
	p4 = 300;
	p5 = 0.0;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 101;
	p1 = 230;
	p2 = 10;
	p3 = 654;
	p4 = 17890;
	p5 = 0.6637270828498492;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 20;
	p1 = 30;
	p2 = 10;
	p3 = 90;
	p4 = 90;
	p5 = 1.0;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 1000;
	p1 = 600;
	p2 = 1;
	p3 = 17000;
	p4 = 17000;
	p5 = 0.0;
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, p3, p4, true, p5) && all_right;
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
