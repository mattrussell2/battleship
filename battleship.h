//battleship.h 
//by matt russell
//2019

#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
#include "ship.h"
using namespace std;

typedef vector< vector<string> > board;
typedef vector< vector<int> > pboard;

class battleship{
 public:
  battleship();
  ~battleship();
  
  void print_game() const;
  void start_game();
  void pc_test();
  void run_game();
  
 private: 
  void init_board(board *b);
  void init_pboard(pboard *pb);

  void find_best_guess(board *b, pboard *pb, pos &p); //int &x, int &y);
  bool is_perfect_loc(board *b, pos &p) const; //int &x, int &y) const;
  double dist_from_center(pos p) const; //int x, int y) const;
  bool is_valid_loc(board *b, pos p) const; //int x, int y) const;
  bool blood_in_the_water(board *b, pos &p) const; //int &x, int &y) const;
  bool search_for_hit_location(board *b, pos &p) const; //int &x, int &y) const;

  void calc_probabilities(board *b, pboard *pb);
  void find_medium_good_spot(board *b, pos &p) const; //int &x, int &y) const;
  void easy_guess(board *b, pos &p) const; //int &x, int &y) const;
  
  void update_probabilities(board *b, pboard *pb, pos p, int len, bool d); //int x, int y
  bool check_nearby_hit(board *b, int len, pos p, int d) const; //int x, int y, 

  void get_start_coord(board *b, int len, pos &p, bool &d) const; //int &x, int &y, 
  void generate_ships(board *b, vector<ship> *ships, bool hu_pc);
  void find_valid_start_loc(board *b,int len, pos &p, bool &d) const; // int &x, int &y
  bool check_clear_area(board *b,int len, pos p, int d) const; //int x, int y, 
  void place_ship(board *b,int len, pos p, bool d, string s); //int x, int y, 

  void register_hit(board *hit_board,board *fire_board,
		    pboard *fire_pboard, pos p); //int x, int y
  void register_miss(board *missed_board,board *f_board,
		     pboard *f_pboard, pos p); //int x, int y

  bool test_for_hit(board *b, pos p) const; //int i, int j
    
  bool game_ready(board *human_board) const; 
  bool gameover() const;

  //these two functions make the guesses and call register hits/miss fns.
  string hu_make_guess();
  string pc_make_guess();

  //first board is the TRY board; add letters to it if a ship is sunk
  void add_hit_to_ships(board *b,vector<ship> *ships, pboard *pb,
			pos p, bool disp); //int x, int y
  
  //searches through the ships to find which one is sunk
  void check_sunken_ships(board *hit_board, vector<ship> *ships) const;

  void print_board(board *b) const; 
  void print_two_boards(board *b, board *b2) const;
  void print_user_game_data() const;
  void print_full_game_data(string outstr) const;

  board *pc_own_board;
  board *pc_try_board;
  board *hu_own_board;
  board *hu_try_board;

  pboard *hu_pboard;
  pboard *pc_pboard;
 
  int ship_len_lookup[5] = { 5, 4, 3, 3, 2 };
  string ship_class_lookup[5] = {"\u001b[33;1mA\u001b[0m",
				 "\u001b[36;1mB\u001b[0m",
				 "\u001b[37;1mC\u001b[0m",
				 "\u001b[35;1mS\u001b[0m",
				 "\u001b[32;1mD\u001b[0m"};
  string ship_name_lookup[5] = {"Aircraft Carrier", "Battleship", "Crusier",
				"Submarine","Destroyer"};
  vector<ship> *pc_ships;
  vector<ship> *hu_ships;

  string difficulty;

  vector<string> pc_guesses;
  vector<string> hu_guesses;

};
