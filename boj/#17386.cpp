#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;
using ll = long long;

struct Point {
	ll x, y;
	Point(ll x, ll y) : x(x), y(y) {}
};

ll ccw(Point a, Point b, Point c) {
	ll ret = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);

	if (ret > 0)
		return 1;
	else
		return -1;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<Point> points;

	ll x, y;
	for (int i = 0; i < 4; i++) {
		cin >> x >> y;

		points.push_back(Point(x, y));
	}

	ll a = ccw(points[0], points[1], points[2]);
	ll b = ccw(points[0], points[1], points[3]);
	ll c = ccw(points[2], points[3], points[0]);
	ll d = ccw(points[2], points[3], points[1]);

	if (a * b <= 0 && c * d <= 0)
		cout << 1 << "\n";
	else
		cout << 0 << "\n";

	return 0;
}
