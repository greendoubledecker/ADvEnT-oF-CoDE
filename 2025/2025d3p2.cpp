#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int num = 12;

int main(){
	string s;
	long long total = 0;
	while(true){
		cin >> s;
		if(s == "END") break;
		long long max = 0, maxInd = -1;
		long long jolts = 0;
		for(int i = num; i > 0; --i){
			for(int j = maxInd + 1; j < s.size() - i + 1; ++j){
				//cout << "j " << j << endl;
				if(s[j] - '0' > max){
					max = s[j] - '0';
					maxInd = j;
				}
			}
			jolts += max * pow(10, i - 1);
			max = 0;
		}
		//cout << jolts << " jolts." << endl;
		total += jolts;
	}
	cout << total;
	return 0;
}
