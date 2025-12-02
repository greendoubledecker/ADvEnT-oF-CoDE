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
			cout << "current: " << num << endl;
			for(int repeatLen = 1; repeatLen < num.size(); ++repeatLen){
				//cout << "repeat len:" << repeatLen << endl;
				if(num.size() % repeatLen != 0) continue;
				vector<string> parts;
				 
				for(int index = 0; index < num.size(); index+=repeatLen){
					string part = num.substr(index, repeatLen);
					parts.push_back(part);
				}
				bool invalid = true;
				for(string part : parts){
					//cout << "p:" << part << endl;
					if(part != parts[0]){
						invalid = false;
						break;
					}
				}
				//cout << "made it" << endl;
				if(invalid){
					cout << "found " << i << endl;
					sum += i;
					break;
				}
			}
		}
	}
	cout << sum << endl;
	return 0;
}	
