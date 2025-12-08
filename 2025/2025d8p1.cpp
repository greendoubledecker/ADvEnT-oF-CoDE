#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <cmath>
#include <algorithm>

using namespace std;

int wires = 1000;
int num = 3;

struct Box{
	int x = -1;
	int y = -1;
	int z = -1;
};

vector<int> combine(vector<int> a, vector<int> b){
	vector<int> ans;
	for(int i : a) ans.push_back(i);
	for(int j : b) ans.push_back(j);
	return ans;
}

bool bigger(vector<int> a, vector<int> b){
	return a.size() > b.size();
}

bool closer(pair<pair<int, int>, double> a, pair<pair<int, int>, double> b){
	return a.second < b.second;
}

int main(){
	vector<Box> boxes;
	string s;
	cin >> s;
	while(s != "END"){
		stringstream ss(s);
		Box b;
		ss >> b.x;
		ss.ignore();
		ss >> b.y;
		ss.ignore();
		ss >> b.z;
		boxes.push_back(b);
		cin >> s;
	}
	vector<pair<pair<int, int>, double>> dists;
	for(int i = 1; i < boxes.size(); ++i){
		for(int j = 0; j < i; ++j){
			double x = boxes[i].x - boxes[j].x;
			double y = boxes[i].y - boxes[j].y;
			double z = boxes[i].z - boxes[j].z;
			dists.push_back({{i, j}, sqrt(x*x + y*y + z*z)});
		}
	}
	sort(dists.begin(), dists.end(), closer);
	cout << "sorted" << endl;
	vector<vector<int>> circuits;
	for(int i = 0; i < wires; ++i){
		int boxIndex1 = dists[i].first.first, boxIndex2 = dists[i].first.second;
		int circuit1 = -1, circuit2 = -1;
		for(int j = 0; j < circuits.size(); ++j){
			for(int k = 0; k < circuits[j].size(); ++k){
				if(circuits[j][k] == boxIndex1){
					circuit1 = j;
				}
				if(circuits[j][k] == boxIndex2){
					circuit2 = j;
				}
				if(circuit1 != -1 && circuit2 != -1) break;
			}
		}
		if(circuit1 == -1 && circuit2 == -1){
			circuits.push_back(vector<int>{boxIndex1, boxIndex2});
			cout << "new circuit" << endl;
		}
		if(circuit1 == -1 && circuit2 != -1){
			circuits[circuit2].push_back(boxIndex1);
		}
		if(circuit1 != -1 && circuit2 == -1){
			circuits[circuit1].push_back(boxIndex2);
		}
		if(circuit1 != -1 && circuit2 != -1){
			if(circuit1 != circuit2){
				vector<vector<int>> newCircuits = circuits;
				newCircuits[circuit2] = combine(circuits[circuit1], circuits[circuit2]);
				newCircuits.erase(newCircuits.begin() + circuit1);
				circuits = newCircuits;
			}
		}
		for(int j = 0; j < circuits.size(); ++j){
			cout << endl << "circuit " << j << ":" << endl;
			for(int k = 0; k < circuits[j].size(); ++k){
				cout << circuits[j][k] << " ";
			}
		}
	}
	sort(circuits.begin(), circuits.end(), bigger);
	int product = 1;
	cout << "sizes:" << endl;
	for(int i = 0; i < num; ++i){
		cout << circuits[i].size() << endl;
		product *= circuits[i].size();
	}
	cout << product << endl;
	return 0;
}
