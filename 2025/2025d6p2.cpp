#include <iostream>
#include <vector>
#include <string>

using namespace std;

int probSize = 4;

int main(){
	vector<string> input;
	for(int i = 0; i < probSize; ++i){
		string line;
		getline(cin, line);
		input.push_back(line);
	}
	char c;
	cin >> c;
	vector<char> ops;
	while(c != 'E'){
		ops.push_back(c);
		cin >> c;
	}
	vector<vector<string>> problems;
	vector<string> current(probSize);
	for(int i = 0; i < input[0].size(); ++i){
		bool allSpace = true;
		for(int j = 0; j < probSize; ++j){
			if(input[j][i] != ' ') allSpace = false;
		}
		if(allSpace){
			problems.push_back(current);
			current = {};
			for(int j = 0; j < probSize; ++j){
				current.push_back("");
			}
		}else{
			for(int j = 0; j < probSize; ++j){
				current[j] += input[j][i];
			}
		}
		
	}
	problems.push_back(current);
	
	long long total = 0;
	for(int i = 0; i < problems.size(); ++i){
		vector<string> p = problems[i];
		vector<int> cephNums;
		for(int col = 0; col < p[0].size(); ++col){
			string number;
			for(int row = 0; row < p.size(); ++row){
				if(p[row][col] != ' ') number += p[row][col];
			}
			if(number != ""){
				cephNums.push_back(stoi(number));
			}
		}
		if(ops[i] == '*'){
			long long ans = 1;
			for(int n : cephNums){
				ans *= n;
			}
			total += ans;
		}
		if(ops[i] == '+'){
			long long ans = 0;
			for(int n : cephNums){
				ans += n;
			}
			total += ans;
		}
	}
	cout << total << endl;
	return 0;
}
