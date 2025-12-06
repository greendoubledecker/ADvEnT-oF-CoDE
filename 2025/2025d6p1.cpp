#include <iostream>
#include <vector>

using namespace std;

int probSize = 4;

int main(){
	vector<vector<int>> problems;
	for(int i = 0; i < probSize; ++i){
		string s;
		cin >> s;
		vector<int> row;
		while(s != "END"){
			int num = stoi(s);
			row.push_back(num);
			cin >> s;
		}
		problems.push_back(row);
	}
	char c;
	cin >> c;
	vector<char> ops;
	while(c != 'E'){
		ops.push_back(c);
		cin >> c;
	}
	long long total = 0;
	for(int p = 0; p < problems[0].size(); ++p){
		char op = ops[p];
		if(op == '*'){
			long long answer = 1;
			for(int n = 0; n < probSize; ++n){
				answer *= problems[n][p];
			}
			total += answer;
		}
		if(op == '+'){
			long long answer = 0;
			for(int n = 0; n < probSize; ++n){
				answer += problems[n][p];
			}
			total += answer;
		}
	}
	cout << total << endl;
	return 0;
}
