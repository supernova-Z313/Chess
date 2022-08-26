#include<iostream>
#include<stdlib.h>
#include <string.h>
using namespace std;

// ===========================================================================================
// Define functions for main
void First_map_setter(string a[8][8]);
void Shape_show(string a[8][8]);
void Color_changer(string a);
void string_to_Position(string a, int b[2]);
int is_true_beat(int a[2], char b, string map[8][8]);
string winner_changer(string a);
char turn_changer(char a);

/* Beats operations */
void Rook_opr(string map[8][8], int beat[2], int house[2], char Turn, string del_beat_1[16], string del_beat_2[16]);
void Knight_opr(string map[8][8], int beat[2], int house[2], char Turn, string del_beat_1[16], string del_beat_2[16]);
void Bishop_opr(string map[8][8], int beat[2], int house[2], char Turn, string del_beat_1[16], string del_beat_2[16]);
void Queen_opr(string map[8][8], int beat[2], int house[2], char Turn, string del_beat_1[16], string del_beat_2[16]);
void King_opr(string map[8][8], int beat[2], int house[2], char Turn, string del_beat_1[16], string del_beat_2[16]);
void Pawn_opr(string map[8][8], int beat[2], int house[2], char Turn, string del_beat_1[16], string del_beat_2[16]);

// ===========================================================================================
int main(){
	// Show Rules
	string rule = "Rule and Guide:\n\nP1 = White pawn &  P2 = Black pawn\nN1 = White Knight & N2 = Black Knight\nB1 = White Bishop & B2 = Black Bishop\nR1 = White Rook & R2 = Black Rook\nWQ = White Queen & BQ = Black Queen\nWK = White King & BK =Black King\n\n";
	cout<<rule<<"For continue enter 1: \n";
	cin>>rule;
	system("cls");

	// Set some first varible
	string winner = "White";
	string Map[8][8];
	First_map_setter(Map);
	char turn = '1';
	string beat = " ";
	string house = " ";
	string white_del[16];
	string black_del[16];

	while(1){
		// Show playground and turn
		system("cls");
		cout<<endl<<endl<<winner<<" trun:"<<endl;
		Shape_show(Map);

		// Get the Positions
		cout<<"Please enter the Position of the Bead you want to Move:(or exit for end of game)  ";
		cin>>beat;
		if(beat == "exit"){
			winner_changer(winner);
			break;
		}
		int beat_P[2];
		string_to_Position(beat, beat_P);
		while(is_true_beat(beat_P, turn, Map)){
			cout<<"Selected Position is incorrect, Please enter another:  ";
			cin>>beat;
			string_to_Position(beat, beat_P);
		}

		// Get Target
		cout<<"Please enter the Position of the house you want to move to:  ";
		cin>>house;
		int house_P[2];
		string_to_Position(house, house_P);

		// Start Processing
		switch (Map[beat_P[0]][beat_P[1]][0]){
			// Rook operations
			case 'R':
			Rook_opr(Map, beat_P, house_P, turn, white_del, black_del);
			break;

			// Knight operations
			case 'N':
			Knight_opr(Map, beat_P, house_P, turn, white_del, black_del);
			break;

			// Bishop operations
			case 'B':
			Bishop_opr(Map, beat_P, house_P, turn, white_del, black_del);
			break;

			// Queen operations
			case 'Q':
			Queen_opr(Map, beat_P, house_P, turn, white_del, black_del);
			break;

			// King operations
			case 'K':
			King_opr(Map, beat_P, house_P, turn, white_del, black_del);
			break;

			// Pawn operations
			case 'P':
			Pawn_opr(Map, beat_P, house_P, turn, white_del, black_del);
			break;
		}
		winner = winner_changer(winner);
		turn = turn_changer(turn);
	}

	system("cls");
	cout<<"The winner is "<<winner<<endl;

	return 0;
}

