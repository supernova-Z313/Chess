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


// ===========================================================================================
// Rook check which homes can go
void Rook_go_checker(string map[8][8], int Position[2], int result[14][2], int stater, char tim_n){
	int list_counter = stater;

	// column + checker
	for(int i=1; Position[0]+i<8; i++){
		if(map[Position[0]+i][Position[1]] != "  "){
			if(map[Position[0]+i][Position[1]][1] == tim_n){
				break;
			}
			else{
				result[list_counter][0] = Position[0]+i;
				result[list_counter][1] = Position[1];
				list_counter++;
				break;
			}
		}
		else{
			result[list_counter][0] = Position[0]+i;
			result[list_counter][1] = Position[1];
			list_counter++;
		}
	}

	// column - checker
	for(int i=1; Position[0]-i<8; i++){
		if(map[Position[0]-i][Position[1]] != "  "){
			if(map[Position[0]-i][Position[1]][1] == tim_n){
				break;
			}
			else{
				result[list_counter][0] = Position[0]-i;
				result[list_counter][1] = Position[1];
				list_counter++;
				break;
			}
		}
		else{
			result[list_counter][0] = Position[0]-i;
			result[list_counter][1] = Position[1];
			list_counter++;
		}
	}

	// row + checker
	for(int i=1; Position[1]+i<8; i++){
		if(map[Position[0]][Position[1]+i] != "  "){
			if(map[Position[0]][Position[1]+i][1] == tim_n){
				break;
			}
			else{
				result[list_counter][0] = Position[0];
				result[list_counter][1] = Position[1]+i;
				list_counter++;
				break;
			}
		}
		else{
			result[list_counter][0] = Position[0];
			result[list_counter][1] = Position[1]+i;
			list_counter++;
		}
	}

	// row - checker
	for(int i=1; Position[1]-i<8; i++){
		if(map[Position[0]][Position[1]-i] != "  "){
			if(map[Position[0]][Position[1]-i][1] == tim_n){
				break;
			}
			else{
				result[list_counter][0] = Position[0];
				result[list_counter][1] = Position[1]-i;
				list_counter++;
				break;
			}
		}
		else{
			result[list_counter][0] = Position[0];
			result[list_counter][1] = Position[1]-i;
			list_counter++;
		}
	}

	stater = list_counter;
};

// -------------------------------------------------------
// check is Rook can go to that position or not
int Rook_is_in(int res[14][2], int Pos[2]){
	for(int i=0; i<14; i++){
		if(res[i][0] == Pos[0] and res[i][1] == Pos[1]){
			return 0;
		}
	}
	return 1;
};

// -------------------------------------------------------
// Rook check Operation and state
void Rook_opr(string map[8][8], int beat[2], int house[2], char Turn, string del_beat_1[16], string del_beat_2[16]){
	int all_home[14][2];
	for(int i=0; i<14; i++){
		all_home[i][0] = -1; all_home[i][1] = -1;
	}

	Rook_go_checker(map, beat, all_home, 0, Turn);
	while(Rook_is_in(all_home, house)){
		cout<<"Cant move to selected house, Please enter another:  ";
		string wrong; cin>>wrong;
		string_to_Position(wrong, house);
	}

	if(map[house[0]][house[1]] != "  "){
		for(int i=0; i<16; i++){
			if(Turn == '1'){
				if(del_beat_1[i] == ""){
					del_beat_1[i] = map[house[0]][house[1]];
					break;
				}
			}
			else{
				if(del_beat_2[i] == ""){
					del_beat_2[i] = map[house[0]][house[1]];
					break;	
				}
			}
		}
		map[house[0]][house[1]] = map[beat[0]][beat[1]];
		map[beat[0]][beat[1]] = "  ";

		int del_l[14][2] = {{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1}};
		int K = del_row_column(map, house, del_l);
		if(K){
			del_row_column_beat(map, del_l, del_beat_1, del_beat_2);
		}
	}

	else{
		map[house[0]][house[1]] = map[beat[0]][beat[1]];
		map[beat[0]][beat[1]] = "  ";
	}
};


// ===========================================================================================
// Pawn check which homes can go
int Pawn_go_checker(string map[8][8], int Position[2], int result[3][2], char tim_n){
	int res_counter = 0;
	if(tim_n == '1'){
		if(Position[0]-1 < 0){
			return 1;
		}
		else{
			if(map[Position[0]-1][Position[1]] == "  "){
				result[res_counter][0] = Position[0]-1; result[res_counter][1] = Position[1];
				res_counter++;
			}
			if((Position[1]+1 < 8) && map[Position[0]-1][Position[1]+1][1] == '2'){
				result[res_counter][0] = Position[0]-1; result[res_counter][1] = Position[1]+1;
				res_counter++;
			}
			if((Position[1]-1 > -1) && map[Position[0]-1][Position[1]-1][1] == '2'){
				result[res_counter][0] = Position[0]-1; result[res_counter][1] = Position[1]-1;
				res_counter++;
			}
			if(Position[0] == 6 && map[Position[0]-2][Position[1]] == "  "){
				result[res_counter][0] = Position[0]-2; result[res_counter][1] = Position[1];
				res_counter++;
			}
			return 0;
		}
	}
	else{
		if(Position[0]+1 > 8){
			return 1;
		}
		else{
			if(map[Position[0]+1][Position[1]] == "  "){
				result[res_counter][0] = Position[0]+1; result[res_counter][1] = Position[1];
				res_counter++;
			}
			if(Position[1]+1 < 8 && map[Position[0]+1][Position[1]+1][1] == '1'){
				result[res_counter][0] = Position[0]-1; result[res_counter][1] = Position[1]+1;
				res_counter++;
			}
			if(Position[1]-1 > -1 && map[Position[0]+1][Position[1]-1][1] == '1'){
				result[res_counter][0] = Position[0]-1; result[res_counter][1] = Position[1]-1;
				res_counter++;
			}
			if(Position[0] == 1 && map[Position[0]+2][Position[1]] == "  "){
				result[res_counter][0] = Position[0]+2; result[res_counter][1] = Position[1];
				res_counter++;
			}
			return 0;
		}
	}
};

// -------------------------------------------------------
// heck is Pawn can go to that position or not
int Pawn_is_in(int res[3][2], int Pos[2]){
	for(int i=0; i<3; i++){
		if(res[i][0] == Pos[0] and res[i][1] == Pos[1]){
			return 0;
		}
	}
	return 1;
};

// -------------------------------------------------------
// Pawn check Operation and state
void Pawn_opr(string map[8][8], int beat[2], int house[2], char Turn, string del_beat_1[16], string del_beat_2[16]){
	int all_home[3][2] = {{-1,-1},{-1,-1},{-1,-1}};

	int Last_line = Pawn_go_checker(map, beat, all_home, Turn);
	// if Pawn in last line Do this:
	if(Last_line){
		if(Turn == '1'){
			int is_empty = 0;
			for(int i=0; i<16; i++){
				if(del_beat_1[i] != ""){
					is_empty = 1;
					break;
				}
			}
			if(is_empty){
				cout<<"Which beat you want to back?  ";
				string want;
				cin>>want;
				int bre = 1;
				while(bre){
					for(int i=0; i<16; i++){
						if(del_beat_1[i] == want){
							del_beat_1[i] = "";
							map[beat[0]][beat[1]] = want;
							bre = 0;
							break;
						}
					}
					if(bre == 0){
						break;
					}
					cout<<"You don't have it\nWhich beat you want to back?  ";
					cin>>want;
				}
			}
			else{
				cout<<"You have no choice to Change your Pawn.";
			}
		}
		else{
			int is_empty = 0;
			for(int i=0; i<16; i++){
				if(del_beat_2[i] != ""){
					is_empty = 1;
					break;
				}
			}
			if(is_empty){
				cout<<"Which beat you want to back?  ";
				string want;
				cin>>want;
				int bre;
				while(bre){
					for(int i=0; i<16; i++){
						if(del_beat_2[i] == want){
							del_beat_2[i] = "";
							map[beat[0]][beat[1]] = want;
							bre = 0;
							break;
						}
					}
					if(bre == 0){
						break;
					}
					cout<<"You don't have it\nWhich beat you want to back?  ";
					cin>>want;
				}
			}
			else{
				cout<<"You have no choice to Change your Pawn.";
			}
		}
	}

	// if Pawn wasnt in last line: 
	else{
		while(Pawn_is_in(all_home, house)){
			cout<<"Cant move to selected house, Please enter another:  ";
			string wrong; cin>>wrong;
			string_to_Position(wrong, house);
		}


		if(map[house[0]][house[1]] != "  "){
			if(map[house[0]][house[1]] != "  "){
				for(int i=0; i<16; i++){
					if(Turn == '1'){
						if(del_beat_1[i] == ""){
							del_beat_1[i] = map[house[0]][house[1]];
							break;
						}
					}
					else{
						if(del_beat_2[i] == ""){
							del_beat_2[i] = map[house[0]][house[1]];
							break;	
						}
					}
				}
			}
			map[house[0]][house[1]] = map[beat[0]][beat[1]];
			map[beat[0]][beat[1]] = "  ";

			int del_l[14][2] = {{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1}};
			int K = del_row_column(map, house, del_l);
			if(K){
				del_row_column_beat(map, del_l, del_beat_1, del_beat_2);
			}
		}
		else{
			map[house[0]][house[1]] = map[beat[0]][beat[1]];
			map[beat[0]][beat[1]] = "  ";
		}
	}
};


// ===========================================================================================
// Knight check which homes can go
void Knight_go_checker(string map[8][8], int Position[2], int result[8][2], char tim_n){
	int def_cordin[8][2] = {{2,1}, {2,-1}, {-2,1}, {-2,-1}, {1,2}, {1,-2}, {-1,2}, {-1,-2}};
	int res_counter = 0;
	for(int i=0; i<8; i++){
		if((Position[0]+def_cordin[i][0]>=0 && Position[0]+def_cordin[i][0]<=7) && (Position[1]+def_cordin[i][1]>=0 && Position[1]+def_cordin[i][1]<=7)){
			if(map[Position[0]+def_cordin[i][0]][Position[1]+def_cordin[i][1]][1] != tim_n){
				result[res_counter][0] = Position[0]+def_cordin[i][0];  result[res_counter][1] = Position[1]+def_cordin[i][1];
				res_counter++;
			}
		}
	}
};


// -------------------------------------------------------
// heck is Knight can go to that position or not
int Knight_is_in(int res[8][2], int Pos[2]){
	for(int i=0; i<8; i++){
		if(res[i][0] == Pos[0] and res[i][1] == Pos[1]){
			return 0;
		}
	}
	return 1;
};

// -------------------------------------------------------
// Knight check Operation and state
void Knight_opr(string map[8][8], int beat[2], int house[2], char Turn, string del_beat_1[16], string del_beat_2[16]){
	int all_home[8][2] = {{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}};

	Knight_go_checker(map, beat, all_home, Turn);
	while(Knight_is_in(all_home, house)){
		cout<<"Cant move to selected house, Please enter another:  ";
		string wrong; cin>>wrong;
		string_to_Position(wrong, house);
	}

	if(map[house[0]][house[1]] != "  "){
		if(map[house[0]][house[1]] != "  "){
			for(int i=0; i<16; i++){
				if(Turn == '1'){
					if(del_beat_1[i] == ""){
						del_beat_1[i] = map[house[0]][house[1]];
						break;
					}
				}
				else{
					if(del_beat_2[i] == ""){
						del_beat_2[i] = map[house[0]][house[1]];
						break;	
					}
				}
			}
		}
		map[house[0]][house[1]] = map[beat[0]][beat[1]];
		map[beat[0]][beat[1]] = "  ";

		int del_l[14][2] = {{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1}};
		int K = del_row_column(map, house, del_l);
		if(K){
			del_row_column_beat(map, del_l, del_beat_1, del_beat_2);
		}
	}
	else{
		map[house[0]][house[1]] = map[beat[0]][beat[1]];
		map[beat[0]][beat[1]] = "  ";
	}
};


// ===========================================================================================
// Bishop check which homes can go
void Bishop_go_checker(string map[8][8], int Position[2], int result[16][2], char tim_n){
	int list_counte;

	// column + checker
	for(int i=1; Position[0]+i<8 && Position[0]+i>=0; i++){
		if(map[Position[0]+i][Position[1]+i] != "  "){
			if(map[Position[0]+i][Position[1]+i][1] == tim_n){
				break;
			}
			else{
				result[list_counte][0] = Position[0]+i;
				result[list_counte][1] = Position[1]+i;
				list_counte++;
				break;
			}
		}
		else{
			result[list_counte][0] = Position[0]+i;
			result[list_counte][1] = Position[1]+i;
			list_counte++;
		}
	}

	// column - checker
	for(int i=1; Position[0]-i<8 && Position[0]-i>=0; i++){
		if(map[Position[0]-i][Position[1]-i] != "  "){
			if(map[Position[0]-i][Position[1]-i][1] == tim_n){
				break;
			}
			else{
				result[list_counte][0] = Position[0]-i;
				result[list_counte][1] = Position[1]-i;
				list_counte++;
				break;
			}
		}
		else{
			result[list_counte][0] = Position[0]-i;
			result[list_counte][1] = Position[1]-i;
			list_counte++;
		}
	}

	// row + checker
	for(int i=1; Position[1]+i<8 && Position[1]+i>=0; i++){
		cout<<"3";
		if(map[Position[0]-i][Position[1]+i] != "  "){
			if(map[Position[0]-i][Position[1]+i][1] == tim_n){
				break;
			}
			else{
				result[list_counte][0] = Position[0]-i;
				result[list_counte][1] = Position[1]+i;
				list_counte++;
				break;
			}
		}
		else{
			result[list_counte][0] = Position[0]-i;
			result[list_counte][1] = Position[1]+i;
			list_counte++;
		}
	}

	// row - checker
	for(int i=1; Position[1]-i<8 && Position[1]-i>=0; i++){
		cout<<"4";
		if(map[Position[0]+i][Position[1]-i] != "  "){
			if(map[Position[0]+i][Position[1]-i][1] == tim_n){
				break;
			}
			else{
				result[list_counte][0] = Position[0]+i;
				result[list_counte][1] = Position[1]-i;
				list_counte++;
				break;
			}
		}
		else{
			result[list_counte][0] = Position[0]+i;
			result[list_counte][1] = Position[1]-i;
			list_counte++;
		}
	}
};


// -------------------------------------------------------
// heck is Bishop can go to that position or not
int Bishop_is_in(int res[16][2], int Pos[2]){
	for(int i=0; i<16; i++){
		if(res[i][0] == Pos[0] and res[i][1] == Pos[1]){
			return 0;
		}
	}
	return 1;
};


// -------------------------------------------------------
// Bishop check Operation and state
void Bishop_opr(string map[8][8], int beat[2], int house[2], char Turn, string del_beat_1[16], string del_beat_2[16]){
	int all_home[16][2] = {{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}};

	Bishop_go_checker(map, beat, all_home, Turn);
	while(Bishop_is_in(all_home, house)){
		cout<<"Cant move to selected house, Please enter another:  ";
		string wrong; cin>>wrong;
		string_to_Position(wrong, house);
	}
	
	if(map[house[0]][house[1]] != "  "){
		if(map[house[0]][house[1]] != "  "){
			for(int i=0; i<16; i++){
				if(Turn == '1'){
					if(del_beat_1[i] == ""){
						del_beat_1[i] = map[house[0]][house[1]];
						break;
					}
				}
				else{
					if(del_beat_2[i] == ""){
						del_beat_2[i] = map[house[0]][house[1]];
						break;	
					}
				}
			}
		}
		map[house[0]][house[1]] = map[beat[0]][beat[1]];
		map[beat[0]][beat[1]] = "  ";

		int del_l[14][2] = {{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1}};
		int K = del_row_column(map, house, del_l);
		if(K){
			del_row_column_beat(map, del_l, del_beat_1, del_beat_2);
		}
	}
	else{
		map[house[0]][house[1]] = map[beat[0]][beat[1]];
		map[beat[0]][beat[1]] = "  ";
	}


};


// ===========================================================================================
// King check which homes can go
void King_go_checker(string map[8][8], int Position[2], int result[16][2], char tim_n){
	int def_cordin[8][2] = {{1,0}, {1,-1}, {1,1}, {-1,-1}, {-1,0}, {-1,1}, {0,1}, {0,-1}};
	int res_counter = 0;
	for(int i=0; i<8; i++){
		if((Position[0]+def_cordin[i][0]>=0 && Position[0]+def_cordin[i][0]<=7) && (Position[1]+def_cordin[i][1]>=0 && Position[1]+def_cordin[i][1]<=7)){
			if(map[Position[0]+def_cordin[i][0]][Position[1]+def_cordin[i][1]][1] != tim_n){
				result[res_counter][0] = Position[0]+def_cordin[i][0];  result[res_counter][1] = Position[1]+def_cordin[i][1];
				res_counter++;
			}
		}
	}
};

// -------------------------------------------------------
// heck is King can go to that position or not
int King_is_in(int res[8][2], int Pos[2]){
	for(int i=0; i<8; i++){
		if(res[i][0] == Pos[0] and res[i][1] == Pos[1]){
			return 0;
		}
	}
	return 1;
};

// -------------------------------------------------------
// King check Operation and state
void King_opr(string map[8][8], int beat[2], int house[2], char Turn, string del_beat_1[16], string del_beat_2[16]){
	int all_home[8][2] = {{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}};

	King_go_checker(map, beat, all_home, Turn);
	while(King_is_in(all_home, house)){
		cout<<"Cant move to selected house, Please enter another:  ";
		string wrong; cin>>wrong;
		string_to_Position(wrong, house);
	}

	if(map[house[0]][house[1]] != "  "){
		if(map[house[0]][house[1]] != "  "){
			for(int i=0; i<16; i++){
				if(Turn == '1'){
					if(del_beat_1[i] == ""){
						del_beat_1[i] = map[house[0]][house[1]];
						break;
					}
				}
				else{
					if(del_beat_2[i] == ""){
						del_beat_2[i] = map[house[0]][house[1]];
						break;	
					}
				}
			}
		}
		map[house[0]][house[1]] = map[beat[0]][beat[1]];
		map[beat[0]][beat[1]] = "  ";

		int del_l[14][2] = {{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1}};
		int K = del_row_column(map, house, del_l);
		if(K){
			del_row_column_beat(map, del_l, del_beat_1, del_beat_2);
		}
	}
	else{
		map[house[0]][house[1]] = map[beat[0]][beat[1]];
		map[beat[0]][beat[1]] = "  ";
	}
};


// ===========================================================================================
//  heck is Queen can go to that position or not
int Queen_is_in(int res[16][2], int Pos[2], int y){
	for(int i=0; i<y; i++){
		if(res[i][0] == Pos[0] and res[i][1] == Pos[1]){
			return 1;
		}
	}
	return 0;
};
// -------------------------------------------------------
// Queen check Operation and state
void Queen_opr(string map[8][8], int beat[2], int house[2], char Turn, string del_beat_1[16], string del_beat_2[16]){
	int all_home_1[16][2] = {{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}};
	int all_home_2[14][2] = {{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}};
	Bishop_go_checker(map, beat, all_home_1, Turn);
	Rook_go_checker(map, beat, all_home_2, 0, Turn);
	while(1){
		if(Queen_is_in(all_home_1, house, 16)){
			break;
		}
		else if(Queen_is_in(all_home_2, house, 14)){
			break;
		}
		cout<<"hhhh"<<endl;
		cout<<"Cant move to selected house, Please enter another:  ";
		string wrong; cin>>wrong;
		string_to_Position(wrong, house);
	}

	if(map[house[0]][house[1]] != "  "){
		if(map[house[0]][house[1]] != "  "){
			for(int i=0; i<16; i++){
				if(Turn == '1'){
					if(del_beat_1[i] == ""){
						del_beat_1[i] = map[house[0]][house[1]];
						break;
					}
				}
				else{
					if(del_beat_2[i] == ""){
						del_beat_2[i] = map[house[0]][house[1]];
						break;	
					}
				}
			}
		}
		map[house[0]][house[1]] = map[beat[0]][beat[1]];
		map[beat[0]][beat[1]] = "  ";

		int del_l[14][2] = {{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1}};
		int K = del_row_column(map, house, del_l);
		if(K){
			del_row_column_beat(map, del_l, del_beat_1, del_beat_2);
		}
	}
	else{
		map[house[0]][house[1]] = map[beat[0]][beat[1]];
		map[beat[0]][beat[1]] = "  ";
	}
};
