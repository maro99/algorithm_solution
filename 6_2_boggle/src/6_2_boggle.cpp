//============================================================================
// Name        : 6_2_boggle.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


/*
// 보글은 5x5 크기의 알파벳 격자를 가지고 하는 게임
// 이때 게임의 목적은 상하좌우 /대각선으로 인접한 칸들의 글자들을 이어서 단어를 찾아내는것.
​
// U R L P M
// X P R E T
// G I A E T
// X T N Z Y
// X O Q R S
​
//이렇꼐 잇으면 PRETTY, GIRL, REPEAT등 단어
// 대각선, 한글자 두번사용, 등이 가능하다.
​
// 주어진 칸에서 시작해서 특정 단어를 찾을 수 있는지 확인하는 문제를 풀어보자.
​
//hasWord(y,x,word) = 보글 게임판의 (y,x)에 시작하는 단어 word의 존재여부를 반환한다.
​
//기저 사례
//더 이상의 탐색 없이 간단히 답을 낼 수 있는 다음 경우들을 기저 사례로 선택.
//1. 위치(y,x)에 있는 글자가 원하는 단어의 첫 글자가 아닌 경우 항상 실패
//2. (1번 경우에 해당되지 않을 경우) 원하는 단어가 한 글자인 경우 항상 성공.
// + 위 두경우 + 현재 위치가 보글 게임팡르 벗어난 경우, 첫 글자가 일치하지 않는 경우를 모두 기저 사례로 선택해 처리하자.
​
​
​
//예제 입력
//1
//URLPM
//XPRET
//GIAET
//XTNZY
//XOQRS
//6
//PRETTY
//GIRL
//REPEAT
//KARA
//PANDORA
//GIAZAPX
//
//예제 출력
//PRETTY YES
//GIRL YES
//REPEAT YES
//KARA NO
//PANDORA NO
//GIAZAPX YES
​*/

#include <iostream>
using namespace std;
#include <vector>
#include <sstream>

vector<string> board;
vector<string> words;

const int dx[8] = {-1,-1,-1,0,1,1,1,0};
const int dy[8] = {-1,0,1,1,1,0,-1,-1};

bool test(){
	return false;
}

bool hasWord(int y, int x, const string& word){
	//더이상 탐색 안해도 되는 경우가 기저 사례로 선택.
	//(y,x)의 글자가 원하는 단어의 첫글자가 아닌 경우. 실패, 게임판 벋아나는 경우 실패.
	//  (1번 경우에 해당되지 않을 경우) 원하는 단어가 한 글자인 경우 항상 성공.
	if(y<0 || y>4 || x<0 || x>4){
		return false;
	}
	if(board[y][x] != word[0]){
		return false;
	}
	if(word.size()==1){
		return true;
	}

	//주변의 8 방향에 대해서도 hasWord함수를 재귀적으로 호출해 준다.
	for(int i=0; i<8;i++){
		int next_y = y+ dy[i];
		int next_x = x+ dx[i];
		if(hasWord(next_y,next_x,word.substr(1))){
			return true;
		}

	}
	return false;
}




int main() {

	int cases;
	cin >> cases;

	while(cases--)
	{

		//5 줄 입력을 받음.
		for(int i=0; i<5; i++){
			string line;
			cin >>line;
			board.push_back(line);
		}


		int word_cases;
		cin >> word_cases;

		for(int i=0; i<word_cases; i++){
			string line2;
			cin >>line2;
			words.push_back(line2);
		}

//		cout << "@@@@@@@@@@@@" <<endl;

		for(int i=0; i<word_cases; i++){

			string word = words[i];
//			cout << word <<endl;


			bool is_found = false;
			for(int y=0;y<5;y++){
				for(int x=0; x<5; x++){

					if(hasWord(y,x,word)){
						is_found = true;
						break;
					}
				}
			}
			if(is_found){
				cout<<word<<" YES"<<endl;
			}
			else{
				cout<<word<<" NO"<<endl;
			}

		}


	}

	return 0;
}


//이하는 테스트 해보던것
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


//	//5 줄 입력을 받음.
//	board.push_back("URLPM");
//	board.push_back("XPRET");
//	board.push_back("GIAET");
//	board.push_back("XTNZY");
//	board.push_back("XOQRS");
//
//	string word = "PRETTY";
//
//	bool is_found = false;
//	for(int y=0;y<5;y++){
//		for(int x=0; x<5; x++){
//
//			if (hasWord(y,x,word)){
//				is_found = true;
//				break;
//			}
//		}
//	}
//
//	if(is_found){
//		cout<<word<<" YES"<<endl;
//	}
//	else{
//		cout<<word<<" NO"<<endl;
//	}
//




//	string a;
//	a = "asdf";
//	cout <<a[0] <<endl;
//	cout <<a.substr(0,1) <<endl;
//	cout <<a.substr() <<endl;
//	cout <<a.size()<<endl;







//
//
//	vector<string> board;
//
//	string input;
//	cout <<"write 25 char in here 5개씩 공백으로 구분해라"<<endl;
//	cin >> input;
//
//	stringstream ss(input);
//
//	string str;
//	while(ss>>str){
//		board.push_back(str);
//		cout <<input <<endl;
//
//	}
//
//
//	//입력한 5x5를 출력해 주겠슴.
//	cout << "you wrote this"<<endl;
//	for(vector<string>::iterator it  = board.begin();it!=board.end();++it){
//		cout<<*it<<"\n";
//	}

//	string a = "1234567890";
//	string temp = a.substr(1);

