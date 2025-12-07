#include <iostream>
#include <vector>

using namespace std;

int size;

int main(){
	string s;
	cin >> s;
	vector<long long> paths;
	for(char c : s){
		if(c == 'S') paths.push_back(1);
		else paths.push_back(0);
	}
	cin >> s;
	while(s != "END"){
		vector<long long> newRays = paths;
		for(int i = 0; i < s.size(); ++i){
			if(s[i] == '^'){
				newRays[i    ] =  0;
				newRays[i - 1] += paths[i];
				newRays[i + 1] += paths[i];
			}
		}
		paths = newRays;
		cin >> s;
	}
	long long count = 0;
	for(long long p : paths){
		count += p;
	}
	cout << count << endl;
	return 0;
}
