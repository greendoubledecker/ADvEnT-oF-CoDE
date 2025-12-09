#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

int width = 100000;
int height = 100000;

int main(){
	vector<pair<long long, long long>> reds;
	vector<vector<int>> grid(width, vector<int>(height, 0)); //0,1,2 is black, red, yellow = edges(don't need green)
	cout << "ready!" << endl;
	string s;
	cin >> s;
	while(s != "END"){
		string numStr;
		stringstream ss(s);
		pair<int, int> nums;
		getline(ss, numStr, ',');
		nums.first = stoi(numStr);
		getline(ss, numStr, ',');
		nums.second= stoi(numStr);
		reds.push_back(nums);
		grid[nums.first][nums.second] = 1;
		cin >> s;
	}
	
	vector<pair<int, int>> yellows;
	for(int i = 0; i < reds.size() - 1; ++i){
		pair<int, int> r1 = reds[i], r2 = reds[i + 1];
		if(r1.first == r2.first){
			int bottom = min(r1.second, r2.second);
			int top = max(r1.second, r2.second);
			for(int j = bottom + 1; j < top; ++j){
				grid[r1.first][j] = 2;
			}
		}
		if(r1.second == r2.second){
			int left = min(r1.first, r2.first);
			int right = max(r1.first, r2.first);
			for(int j = left + 1; j < right; ++j){
				grid[j][r1.second] = 2;
			}
		}
	}
	pair<int, int> r1 = reds[0];
	pair<int, int> r2 = reds[reds.size() - 1];
	if(r1.first == r2.first){
		int bottom = min(r1.second, r2.second);
		int top = max(r1.second, r2.second);
		for(int j = bottom + 1; j < top; ++j){
			grid[r1.first][j] = 2;
		}
	}
	if(r1.second == r2.second){
		int left = min(r1.first, r2.first);
		int right = max(r1.first, r2.first);
		for(int j = left + 1; j < right; ++j){
			grid[j][r1.second] = 2;
		}
	}
	
	cout << "now testing pairs..." << endl;
	
	long long maxx = 0;
	for(int i = 0; i < reds.size() - 1; ++i){
		for(int j = i + 1; j < reds.size(); ++j){
			auto r1 = reds[i];
			auto r2 = reds[j];
			cout << "iterating " << r1.first << " " << r1.second << ", " << r2.first << " " << r2.second << ", ";
			long long area = (abs(r1.first - r2.first) + 1) * (abs(r1.second - r2.second) + 1);
			cout << "area is " << area << "." << endl;
			if(area <= maxx){
				continue;
			}
			bool works = true;
			for(int k = min(r1.first, r2.first) + 1; k < max(r1.first, r2.first); ++k){
				if(grid[k][min(r1.second, r2.second) + 1] != 0){
					works = false;
					break;
				}
				if(grid[k][max(r1.second, r2.second) - 1] != 0){
					works = false;
					break;
				}
			}
			for(int l = min(r1.second, r2.second) + 1; l < max(r1.second, r2.second); ++l){
				if(grid[min(r1.first, r2.first) + 1][l] != 0){
					works = false;
					break;
				}
				if(grid[max(r1.first, r2.first) - 1][l] != 0){
					works = false;
					break;
				}
			}
			if(works){
				maxx = area;
			}
		}
	}
	cout << maxx << endl;
	return 0;
	/*
	for(int i = 0; i < width; ++i){
		for(int j = 0; j < height; ++j){
			cout << grid[i][j];
		}
		cout << endl;
	}
	return 0;
	*/
}
