#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int main(){
	vector<pair<int, int>> reds;
	string s;
	cin >> s;
	while(s != "END"){
		string numStr;
		stringstream ss(s);
		pair<int, int> nums;
		getline(ss, numStr, ',');
		nums.first = stoi(numStr);
		getline(ss, numStr, ',');
		nums.second= stoi(numStr);
		reds.push_back(nums);
		cin >> s;
	}
	long long max = 0;
	for(int i = 0; i < reds.size(); ++i){
		for(int j = i + 1; j < reds.size(); ++j){
			auto r1 = reds[i];
			auto r2 = reds[j];
			long long x = abs(r1.first - r2.first);
			long long y = abs(r1.second- r2.second);
			++x;
			++y;
			long long area = x * y;
			if(area > max){
				max = area;
				cout << r1.first << ", " << r1.second << " and " << r2.first << ", " << r2.second << endl;
			}
		}
	}
	cout << max << endl;
	return 0;
}
