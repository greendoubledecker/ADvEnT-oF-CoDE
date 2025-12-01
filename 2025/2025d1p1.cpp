#include <iostream>

using namespace std;

int ticks = 100;
int start = 50;

int main(){
	int pos = start;
	int count = 0;
	while(true){
		char c;
		cin >> c;
		if(c == '-') break;
		int num;
		cin >> num;
		if(c == 'L'){
			pos -= num;
		}
		if(c == 'R'){
			pos += num;
		}
		pos %= ticks;
		if(pos == 0){
			++count;
		}
	}
	cout << count << endl;
	return 0;
}
