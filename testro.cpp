#include<iostream>
#include<stdlib.h>
#include <string.h>
using namespace std;


int gg(){
	return 5;
};

int test(){
	if (gg()){
	return 1;}
	return 0;
};


int main()
{
	string a[5];
	for(int i=0; i<5; i++){
	cout<<a[i];}
	cout<<"ff";
	/*
	string a = "hello";
	if(a[1] == 'e'){
		cout<<"hmmm";
	}
	cout<<"hello"<<endl<<flush;

	system("clear");

	string b = "4";
	string a = "te" + b;
	cout<<a<<endl;
	
	if(test()){
		cout<<55<<endl;
	}
	*/

	return 0;
}

/*
Blank space = black space

 WP = White pawn &  BP = Black pawn

 WN = White Knight & BN = Black Knight

 WB = White Bishop & BB = Black Bishop

 WR = White Rook & BR = Black Rook

 WQ = White Queen & BQ = Black Queen

 WK = White King & BK =Black King
 */