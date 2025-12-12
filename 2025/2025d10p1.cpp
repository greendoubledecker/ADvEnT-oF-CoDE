#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int recurse(vector<bool> lights, vector<vector<int>> buttons, vector<int> onButtons, int level){ //buttons is 0-indexed
	if(level == buttons.size()){
		vector<bool> lightsOn(lights.size(), false);
		//cout << "turned on:";
		for(int b : onButtons){
			//cout << endl;
			vector<int> button = buttons[b];
			for(int l : button){
				//cout << " " << l;
				lightsOn[l] = !lightsOn[l];
			}
		}
		//cout << endl;
		if(lightsOn == lights){
			//cout << "valid" << endl;
			return onButtons.size();
		}else{
			return -1;	
		}
	}else{
		vector<int> nextOn = onButtons;
		onButtons.push_back(level);
		int no = recurse(lights, buttons, nextOn, level + 1);
		int yes = recurse(lights, buttons, onButtons, level + 1);
		if(no == -1){
			return yes;
		}else{
			if(yes != -1){
				return min(no, yes);
			}else{
				return no;
			}
		}
	}
}

int tc(){
	string l;
	cin >> l;
	vector<bool> lights;
	for(int i = 1; i < l.size() - 1; ++i){
		if(l[i] == '#') lights.push_back(true);
		else lights.push_back(false);
	}
	vector<vector<int>> buttons;
	string b;
	cin >> b;
	while(b[0] != '{'){
		vector<int> button;
		for(int i = 1; i < b.size(); i += 2){
			button.push_back(b[i] - '0');
		}
		buttons.push_back(button);
		cin >> b;
	}
	return recurse(lights, buttons, {}, 0);
}

int main(){
	long long sum = 0;
	while(true){
		sum += tc();
		cout << sum << endl;
	}
}
