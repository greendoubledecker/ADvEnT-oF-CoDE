#include <iostream>
#include <vector>

using namespace std;

int preambleLen = 25;

int main(){
	vector<int> preamble(preambleLen);
	for(int i = 0; i < preambleLen; ++i){
		cin >> preamble[i];
	}
	while (true){
		int num;
		cin >> num;
		bool works = false;
		for(int i = 0; i < preambleLen; ++i){
			for(int j = i + 1; j < preambleLen; ++j){
				if(preamble[i] + preamble[j] == num){
					works = true;
				}
			}
		}
		if(!works){
			cout << num;
			return 0;
		}
		preamble.erase(preamble.begin());
		preamble.push_back(num);
	}
}
