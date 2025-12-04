#include <iostream>
#include <vector>
#include <utility>

using namespace std;

pair<vector<vector<bool>>, long long> step(vector<vector<bool>> hasRoll){
	vector<vector<bool>> ans = hasRoll;
	ans[0][0] = false;
	ans[0][hasRoll[0].size() - 1] = false;
	ans[hasRoll.size() - 1][0] = false;
	ans[hasRoll.size() - 1][hasRoll[0].size() - 1] = false;
	long long count = 0;
	if(hasRoll[0][0]) ++count;
	if(hasRoll[0][hasRoll[0].size() - 1]) ++count;
	if(hasRoll[hasRoll.size() - 1][0]) ++count;
	if(hasRoll[hasRoll.size() - 1][hasRoll[0].size() - 1]) ++count;
	for(int i = 1; i < hasRoll.size() - 1; ++i){
		if(hasRoll[i][0]){
			int n = 0;
			if(hasRoll[i - 1][0]) ++n;
			if(hasRoll[i + 1][0]) ++n;
			if(hasRoll[i - 1][1]) ++n;
			if(hasRoll[i + 1][1]) ++n;
			if(hasRoll[i    ][1]) ++n;
			if(n < 4){
				++count;
				ans[i][0] = false;
			}
		}
		if(hasRoll[i][hasRoll[0].size() - 1]){
			int n = 0;
			if(hasRoll[i - 1][hasRoll[0].size() - 1]) ++n;
			if(hasRoll[i + 1][hasRoll[0].size() - 1]) ++n;
			if(hasRoll[i - 1][hasRoll[0].size() - 2]) ++n;
			if(hasRoll[i + 1][hasRoll[0].size() - 2]) ++n;
			if(hasRoll[i    ][hasRoll[0].size() - 2]) ++n;
			if(n < 4){
				++count;
				ans[i][hasRoll[0].size() - 1] = false;
			}
		}
	}
	for(int i = 1; i < hasRoll[0].size() - 1; ++i){
		if(hasRoll[0][i]){
			int n = 0;
			if(hasRoll[0][i - 1]) ++n;
			if(hasRoll[0][i + 1]) ++n;
			if(hasRoll[1][i - 1]) ++n;
			if(hasRoll[1][i + 1]) ++n;
			if(hasRoll[1][i    ]) ++n;
			if(n < 4){
				++count;
				ans[0][i] = false;
			}
		}
		if(hasRoll[hasRoll[0].size() - 1][i]){
			int n = 0;
			if(hasRoll[hasRoll.size() - 1][i - 1]) ++n;
			if(hasRoll[hasRoll.size() - 1][i + 1]) ++n;
			if(hasRoll[hasRoll.size() - 2][i - 1]) ++n;
			if(hasRoll[hasRoll.size() - 2][i + 1]) ++n;
			if(hasRoll[hasRoll.size() - 2][i    ]) ++n;
			if(n < 4){
				++count;
				ans[hasRoll[0].size() - 1][i] = false;
			}
		}
	}
	for(int i = 1; i < hasRoll.size() - 1; ++i){
		for(int j = 1; j < hasRoll[0].size() - 1; ++j){
			if(hasRoll[i][j]){
				int n = 0;
				if(hasRoll[i - 1][j - 1]) ++n;
				if(hasRoll[i - 1][j    ]) ++n;
				if(hasRoll[i - 1][j + 1]) ++n;
				if(hasRoll[i    ][j - 1]) ++n;
				if(hasRoll[i    ][j + 1]) ++n;
				if(hasRoll[i + 1][j - 1]) ++n;
				if(hasRoll[i + 1][j    ]) ++n;
				if(hasRoll[i + 1][j + 1]) ++n;
				if(n < 4){
					++count;
					ans[i][j] = false;
				};
			}
		}
	}
	return {ans, count};
}

int main(){
	vector<vector<bool>> hasRoll;
	string s;
	cin >> s;
	while(s != "END"){
		vector<bool> row;
		for(char c : s){
			if(c == '@'){
				row.push_back(true);
			}else{
				row.push_back(false);
			}
		}
		hasRoll.push_back(row);
		cin >> s;
	}
	long long count = 0;
	pair<vector<vector<bool>>, long long> ans = step(hasRoll);
	hasRoll = ans.first;
	count = ans.second;
	while(ans.second != 0){
		ans = step(hasRoll);
		hasRoll = ans.first;
		count += ans.second;
	}
	cout << count << endl;
	return 0;
}
