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
#include <ctime>
#include <cstring>
#define Y second
#define X first
using namespace std;


class BaronsAndCoins {
public:
	int ans;
	vector< pair<int, int> > points;
	map< pair<int, pair<int, int> >, bool > seen; 
	void solve(int idx, int coin, int k)
	{
		pair<int, pair<int, int> > pp = make_pair(idx, make_pair(coin, k));
		if (seen.find(pp) != seen.end()) return;
		seen[pp] = true;
		ans = max(ans, coin);
		for (int i = idx+1; i < points.size(); i++) if (points[i].Y > points[idx].Y) {
			int y1 = points[idx].Y, y2 = points[i].Y;
			int x1 = points[idx].X, x2 = points[i].X;
			int dx = (x2-x1);
			int dy = (y2-y1);
			int m;
			if (dx < (m = dy*k + dy*(dy+1)/2)) continue;
			solve(i, coin+1, k+dy+(dx-m)/dy + ((dx-m)%dy != 0));
		}
	}
	int getMaximum(vector <int> x, vector <int> y) {
		points.resize(x.size()+1);
		ans = 0;
		points[0] = make_pair(0, 0);
		for (int i = 0; i < x.size(); i++) points[i+1] = make_pair(x[i], y[i]);
		sort(points.begin(), points.end());
		solve(0, 0, 0);
		return ans;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}";
	cout << "]" << endl;
	BaronsAndCoins *obj;
	int answer;
	obj = new BaronsAndCoins();
	clock_t startTime = clock();
	answer = obj->getMaximum(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
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
	
	vector <int> p0;
	vector <int> p1;
	int p2;
	
	{
	// ----- test 0 -----
	int t0[] = {15,5,30};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {4,5,6};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 2;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {10};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {10};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 0;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {1,3,6,10,15,21};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,2,3,4,5,6};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 6;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {5,10,15,20,25,30,35,40,45};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,1,1,2,2,2,3,3,3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 3;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {1,3,6,10,22,35,50,66};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,2,3,1,2,3,4,5};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 5;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
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
