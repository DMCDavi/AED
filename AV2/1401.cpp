#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;

int main(){
	list<string> listPermute;
	list<string>::iterator it;
	int  num_entries, i;
	string word;
	cin >> num_entries;
	for(i = 0; i < num_entries; i++){
		cin >> word;
	}
	sort(word.begin(), word.end());
	listPermute.push_front(word);
	while(true){
		
	}
	//cout << *listPermute.begin();
	//printa a lista
	for(it = listPermute.begin(); it != listPermute.end(); it++){
		cout << *it << endl;
	}
}