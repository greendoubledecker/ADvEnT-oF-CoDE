#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <sstream>

using namespace std;

int main(){
	vector<pair<long long, long long>> ranges;
	vector<long long> ingredients;
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
	cin >> s;
	while(s != "END"){
		ingredients.push_back(stoll(s));
		cin >> s;
	}
	int count = 0;
	for(long long i : ingredients){
		for(pair<long long, long long> r : ranges){
			if(i >= r.first && i <= r.second){
				++count;
				break;
			}
		}
	}
	cout << count << endl;
	return 0;
}
