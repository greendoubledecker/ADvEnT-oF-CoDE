#include <iostream>
#include <vector>

using namespace std;

int size;

int main(){
	string s;
	cin >> s;
	vector<bool> hasRay;
	for(char c : s){
		if(c == 'S') hasRay.push_back(true);
		else hasRay.push_back(false);
	}
	cin >> s;
	int count = 0;
	while(s != "END"){
		vector<bool> newRays = hasRay;
		for(int i = 0; i < s.size(); ++i){
			if(s[i] == '^' && hasRay[i]){
				newRays[i    ] = false;
				newRays[i - 1] = true;
				newRays[i + 1] = true;
				++count;
			}
		}
		hasRay = newRays;
		cin >> s;
	}
	cout << count << endl;
	return 0;
}
