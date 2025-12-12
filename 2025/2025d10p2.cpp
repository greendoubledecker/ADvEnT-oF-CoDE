#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

bool more(vector<int> b1, vector<int> b2){
	return b1.size() > b2.size();
}

int countPresses(vector<vector<int>> buttons, vector<int> target){
	sort(buttons.begin(), buttons.end(), more);
	vector<int> clicks(target.size(), 0);
	int ans = 0;
	while(clicks != target){
		
		cout << "clicks" << endl;
		for(int c : clicks){
			cout << c << " ";
		}
		
		cout << endl;
		int minimum = 1000;
		int index = 0;
		for(int i = 0; i < clicks.size(); ++i){
			if(target[i] - clicks[i] < minimum && target[i] - clicks[i] != 0){
				minimum = target[i] - clicks[i];
				index = i;
			}
		}
		//cout << "minimum is " << minimum << ", index is " << index << endl;
		for(vector<int> button : buttons){
			/*
			cout << "button:" << endl;
			for(int i : button){
				cout << i << " ";
			}
			*/
			//cout << endl;
			if(find(button.begin(), button.end(), index) != button.end()){
				//cout << "nside if" << endl;
				bool moveOn = false;
				for(int i = 0; i < button.size(); ++i){
					if(target[button[i]] == clicks[button[i]]){
						//cout << "trigger" << endl;
						moveOn = true;
					}
				}
				if(moveOn) continue;
				for(int i = 0; i < button.size(); ++i){
					clicks[button[i]] += minimum;
				}
				ans += minimum;
				break;
			}
		}
	}
	return ans;
}

int tc(){
	vector<vector<int>> buttons;
	string b;
	cin >> b >> b;
	while(b[0] != '{'){
		vector<int> button;
		for(int i = 1; i < b.size(); i += 2){
			button.push_back(b[i] - '0');
		}
		buttons.push_back(button);
		cin >> b;
	}
	vector<int> target;
	b.erase(0, 1);
	b.pop_back();
	stringstream ss(b);
	while(ss.good()){
        string substr;
        getline(ss, substr, ',');
        int t = stoi(substr);
        target.push_back(t);
    }
	return countPresses(buttons, target);
}

int main(){
	long long sum = 0;
	while(true){
		sum += tc();
		cout << sum << endl;
	}
}
