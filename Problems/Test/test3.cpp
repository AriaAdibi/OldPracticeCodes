#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main(){
	bitset<4> first( string("1001") );
	bitset<4> second(string("0011") );
	cerr << first << endl;
	cerr << second << endl;
	cerr << "^ " << endl;
	cout << (first^=second) << endl;
	cerr << "& " << endl;
	cout << (first&=second) << endl;
	cerr << "| " << endl;
	cout << (first|=second) << endl;
	return 0;
}
