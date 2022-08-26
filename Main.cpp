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

// ===========================================================================================
// Turn Position entered to index
void string_to_Position(string a, int b[2]){
	char x[8] = {'A','B','C','D','E','F','G','H'};
	char y[8] = {'8','7','6','5','4','3','2','1'};
	for(int i=0; i<8; i++){
		if(x[i] == a[0]){
			b[1] = i;
			break;
		}
	}
	for(int i=0; i<8; i++){
		if(y[i] == a[1]){
			b[0] = i;
			break;
		}
	}
};


// -------------------------------------------------------
// Change winner varible state
string winner_changer(string a){
	if(a == "White"){
		return "Black";
	}
	else{
		return "White";
	}
};


// -------------------------------------------------------
// Change turn varible state
char turn_changer(char a){
	if(a == '1'){
		return '2';
	}
	else{
		return '1';
	}
};


// -------------------------------------------------------
// Check is the Selected house is True or not
int is_true_beat(int a[2], char b, string map[8][8]){
	if(map[a[0]][a[1]][1] == b){
		return 0;
	}
	return 1;
};


// -------------------------------------------------------
// Display the playground on the screen
void Shape_show(string a[8][8]){
	cout<<"    A    B    C    D    E    F    G    H  "<<endl;
	string aline = "=========================================";
	int line_c = 8;
	cout<<"  "<<aline<<endl;
	for(int i=0; i<8; i++){
		cout<<line_c<<" ";
		for(int j=0; j<8; j++){
			cout<<"| "<<a[i][j]<<" ";
		}
		cout<<"|"<<endl;
		cout<<"  "<<aline<<endl;
		line_c--;
	}
};


// -------------------------------------------------------
// Picking game pieces in early houses
void First_map_setter(string a[8][8]){
	// The color of the beads
	// After crossing the second line, its value changes to white
	string color = "2";
	// Statr Proccessing on houses
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			// Placement of ♖ nut
			if((i == 0 || i == 7) && (j == 0 || j == 7)){
				a[i][j] = "R" + color;
				continue;
			}
			// Placement of ♘ nut
			else if((i == 0 || i == 7) && (j == 1 || j == 6)){
				a[i][j] = "N" + color;
				continue;
			}
			// Placement of ♗ nut
			else if((i == 0 || i == 7) && (j == 2 || j == 5)){
				a[i][j] = "B" + color;
				continue;
			}
			// Placement of ♕ nut
			else if((i == 0 || i == 7) && (j == 3)){
				a[i][j] = "Q" + color;
				continue;
			}
			// Placement of ♔ nut
			else if((i == 0 || i == 7) && (j == 4)){
				a[i][j] = "K" + color;
				continue;
			}
			// Placement of ♙ nut
			else if(i == 1 || i == 6){
				a[i][j] = "P" + color;
				continue;
			}
			// Empty houses
			else{
				a[i][j] = "  ";
			}
		}
	// Change color
	if(i == 2){
		color = "1";
	}
	}
};


// ===========================================================================================
// check in row and column
int del_row_column(string map[8][8], int position[2], int del_list[14][2]){
	int count = 0;
	int King = 1;
	for(int i=0; i<8; i++){
		if(i == position[0]){
			continue;
		}
		else if(map[i][position[1]] != "  "){
			del_list[count][0] = i;  del_list[count][1] = position[1];
			count++;
			if (map[i][position[1]][0] == 'K'){
				King = 0;
			}
		}
	}
	for(int i=0; i<8; i++){
		if(i == position[1]){
			continue;
		}
		else if(map[position[0]][i] != "  "){
			del_list[count][0] = position[0];  del_list[count][1] = i;
			count++;
			if (map[position[0]][i][0] == 'K'){
				King = 0;
			}
		}
	}
	return King;
};


// ===========================================================================================
// Delete Beat in row and column and update the map
void del_row_column_beat(string map[8][8], int del_l[14][2], string del_beat_1[16], string del_beat_2[16]){
	for(int j=0; j<14; j++){
		if(del_l[j][0] == -1){
			break;
		}
		else{
			if(map[del_l[j][0]][del_l[j][1]][1] == '1'){
				for(int l=0; l<16; l++){
					if(del_beat_1[l] == ""){
						del_beat_1[l] = map[del_l[j][0]][del_l[j][1]];
						map[del_l[j][0]][del_l[j][1]] = "  ";
						break;
					}
				}
			}
			else if(map[del_l[j][0]][del_l[j][1]][1] == '2'){
				for(int l=0; l<16; l++){
					if(del_beat_2[l] == ""){
						del_beat_2[l] = map[del_l[j][0]][del_l[j][1]];
						map[del_l[j][0]][del_l[j][1]] = "  ";
						break;
					}
				}
			}
		}
	}
};


