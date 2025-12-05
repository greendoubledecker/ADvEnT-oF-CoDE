#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <sstream>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool startsFirst(pair<long long, long long> r1, pair<long long, long long> r2){
	return r1.first < r2.first;
}

int main(){
	vector<pair<long long, long long>> ranges;
	string s;
	cin >> s;
	while(s != "END"){
		stringstream ss(s);
		string segment;
		pair<long long, long long> numbers;
		getline(ss, segment, '-');
		numbers.first = stoll(segment);
		getline(ss, segment, '-');
		numbers.second = stoll(segment);
		ranges.push_back(numbers);
		cin >> s;
	}
	sort(ranges.begin(), ranges.end(), startsFirst);
	long long count = 0;
	for(long long i = 0; i < ranges.size(); ++i){
		long long leftBound = ranges[i].first; // inclusive!
		bool invalid = false;
		for(long long j = 0; j < i; ++j){
			if(ranges[j].second >= ranges[i].second){
				invalid = true;
				break;
			}
			leftBound = max(leftBound, ranges[j].second + 1);
		}
		if(invalid) continue;
		count += ranges[i].second - leftBound + 1;
	}
	cout << count << endl;
	return 0;
}
