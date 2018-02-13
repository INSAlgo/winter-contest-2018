#define _USE_MATH_DEFINES 
#include <cmath> 
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>

using namespace std;

// projects angles on [0, pi/2]
float quarterproj(float angle) {
	if(angle < 0)
		angle += M_PI;
	if(angle > M_PI / 2)
		angle -= M_PI / 2;
	return angle;
}

// processes input and calculates probability to cut 0 pepper
float success_probability() {
	int N;
	float x1, y1, x2, y2; // reading as float avoids instability of a cast

	cin >> N;

	// Coordinates are immediately converted into angles
	vector<pair<float, float>> angles;
	for(int i = 0; i < N; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		angles.push_back(pair<float, float>(atan2(y1,x1), atan2(y2, x2)));
	}

	// Ordering couples in direct order, then storing first angle and difference
	vector<pair<float, float>> ang_segments;
	for(pair<float, float> angle: angles) {
		if ((angle.first < angle.second && angle.second - angle.first > M_PI)
         || (angle.first > angle.second && angle.first - angle.second < M_PI)) {
			angle = pair<float, float>(angle.second, angle.first);
		}
		float diff;
		if(angle.second >= angle.first)
			diff = angle.second - angle.first;
		else
			diff = angle.second + 2*M_PI - angle.first;
		ang_segments.push_back(pair<float, float>(angle.first, diff));
	}

	// Projecting angles on the same quarter of the circle (interval [0, pi/2])
	vector<pair<float, float>> ang_proj;
	for(pair<float, float> seg: ang_segments) {
		ang_proj.push_back(pair<float, float>(quarterproj(seg.first), seg.second));
	}

	// Dividing segments which exceed angle pi/2
	// Storing start and end angles (no more diff)
	// NB: it needs to be a multimap because we want it sorted
	multimap<float, float> ang_div;
	for(pair<float, float> proj: ang_proj) {
		if(proj.second >= M_PI/2)
			return 0;
		if(proj.first + proj.second < M_PI/2) {
			ang_div.insert(pair<float, float>(proj.first, proj.first + proj.second));
		}
		else {
			ang_div.insert(pair<float, float>(proj.first, M_PI/2));
			ang_div.insert(pair<float, float>(0, proj.first + proj.second - M_PI/2));
		}
	}

	// Finally calculating the proportion of range [0, pi/2] which is "free"
	float proportion = 0;
	float prev_max = 0;
	for(pair<float, float> div: ang_div) { 
		if(div.first > prev_max)
			proportion += div.first - prev_max;
		if(div.second > prev_max)
			prev_max = div.second;
	}
	proportion += M_PI/2 - prev_max;

	if(proportion < 0)
		proportion = 0; // sometimes numerical instability occurs

	return 2 * proportion / M_PI;
}

int main() {
	cout << fixed << setprecision(2) << success_probability() << endl;

	return 0;
}