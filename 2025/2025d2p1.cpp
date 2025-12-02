#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main(){
	string s;
	cin >> s;
	vector<string> pieces;
    stringstream ss(s);
    string substring;
    while(getline(ss, substring, ',')) {
        pieces.push_back(substring);
    }
    long long sum = 0;
    for(string piece : pieces){
		int hypPos = piece.find('-');
		string from = piece.substr(0, hypPos);
		string to = piece.substr(hypPos + 1);
		long long first = stoll(from);
		long long last = stoll(to);
		for(long long i = first; i <= last; ++i){
			string num = to_string(i);
			if(num.size() % 2 == 0){
				string p1 = num.substr(0, num.size() / 2), p2 = num.substr(num.size() / 2);
				if(p1 == p2){
					sum += i;
					//cout << "found " << i << endl;	
				}
			}
		}
	}
	cout << sum << endl;
	return 0;
}	
