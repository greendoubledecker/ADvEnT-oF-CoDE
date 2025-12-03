#include <iostream>
#include <vector>

using namespace std;

int main(){
	string s;
	int total = 0;
	while(true){
		cin >> s;
		if(s == "END") break;
		int max = 0, maxInd = 0;
		int jolts = 0;
		for(int i = 0; i < s.size() - 1; ++i){
			if(s[i] - '0' > max){
				max = s[i] - '0';
				maxInd = i;
			}
		}
		jolts = max * 10;
		int max2 = 0;
		for(int j = maxInd + 1; j < s.size(); ++j){
			if(s[j] - '0' > max2) max2 = s[j] - '0';
		}
		jolts += max2;
		total += jolts;
	}
	cout << total;
	return 0;
}
