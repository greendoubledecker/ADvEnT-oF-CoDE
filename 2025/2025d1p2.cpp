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
		int move = num;
		if(c == 'L'){
			for(int i = 0; i < move; ++i){
				--pos;
				if(pos == -1) pos = ticks - 1;
				if(pos == 0) ++count;
			}
		}
		if(c == 'R'){
			for(int i = 0; i < move; ++i){
				++pos;
				if(pos == ticks){
					pos = 0;
					++count;
				}
			}
		}
	}
	cout << count << endl;
	return 0;
}
