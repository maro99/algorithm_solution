//============================================================================
// Name        : 6_2.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;
#include <vector>

void printPicked(vector<int>& picked){
	for(int i=0; i<picked.size(); i++){
		cout << picked.at(i) <<endl;
	}
	cout << "@@@@@@@@@@@@@@@@@@@" <<endl;
}

void pick(int n, vector<int>& picked, int toPick ){
	//기저 사례: 더 고를 원소가 없을 때 고른 원소들을 출력한다.
	if(toPick==0){
		printPicked(picked); return;
	}
	//고를 수 있는 가장 작은 번호를 d계산한다.
	int smallest = picked.empty() ? 0 : picked.back() +1;
	for(int next = smallest; next < n; ++next){
		picked.push_back(next);
		pick(n, picked, toPick -1);
		picked.pop_back();
	}

}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	vector<int> picked;

//	for(int i=0; i<6; i++){
//		picked.push_back(i);
//	}

	pick(6,picked,4);

	return 0;

}
