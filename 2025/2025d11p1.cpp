#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct Device{
	string name;
	vector<int> connections = {};
	bool operator==(const Device& other) const{
		return name == other.name;
	}
};

vector<Device> rack;

long long recurse(Device you, Device end){
	if(you == end){
		return 1;
	}else{
		long long sum = 0;
		//cout << "has " << you.connections.size() << endl;
		for(int i : you.connections){
			Device d = rack[i];
			//cout << "in connections" << endl;
			sum += recurse(d, end); //it is d end!!
		}
		return sum;
	}
}

int main(){
	cout << "Input the unique words. You can use something like 'https://onlinetexttools.com/find-unique-text-words'. Add 'END' as the last word." << endl;
	string name;
	cin >> name;
	while(name != "END"){
		Device d{name, {}};
		rack.push_back(d);
		cin >> name;
	}
	cout << "Now give the actual testcase. Add 'END' as the last word." << endl;
	cin >> name;
	while(name[name.size() - 1] == ':'){
		name.pop_back();
		int rackIndex = -1;
		for(int i = 0; i < rack.size(); ++i){
			if(rack[i].name == name){
				rackIndex = i;
				break;
			}
		}
		string line;
		getline(cin, line);
		stringstream ss(line);
		string connection;
		while(ss >> connection){
			int next;
			for(int i = 0; i < rack.size(); ++i){
				Device d = rack[i];
				if(d.name == connection){
					next = i;
					//cout << "found next, it's name is " << next.name << endl;
					break;
				}
			}
			rack[rackIndex].connections.push_back(next);
			//cout << "addded a connection to " << rack[rackIndex].name << endl;
		}
		cin >> name;
	}
	//cout << "made it!" << endl;
	Device you, end;
	for(Device d : rack){
		//cout << "Name: " << d.name << endl;
		/*
		for(Device d2: d.connections) {
			cout << "Conn: " << d2.name << endl;
		}
		*/
		if(d.name == "you") you = d;
		if(d.name == "out") end = d;
	}
	//cout << "'you' has the name " << you.name << endl;
	//cout << "'you' has " << you.connections.size() << " connections." << endl;
	cout << recurse(you, end) << endl;
	return 0;
}
