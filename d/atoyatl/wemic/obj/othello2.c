#include <std.h>
#define DIRECTIONS ({-8,-7,1,9,8,7,-1,-9})


inherit OBJECT;

int * board, * last_move;
string get_board_display(object ob);
string display_board();
string display_board_small();
int flip(int col, int pos,int dir);
int place_counter(string colour, string x, int y);
int set_board(int pos, int setting);
void setup();


void create(){
  ::create();
  board = allocate(64);
  last_move = allocate(64);
//  set_id(({"board","game board", "game"}));

//  set_name("game board");
//  set_short("an interesing looking game board");
//  set_long( (: TO, "long_desc" :) );
  setup();
}

void setup(){
  int i;
  for (i=0;i<64;i++){
    board[i] = 0;
  }
  set_board(27, -1);
  set_board(28, 1);
  set_board(35, 1);
  set_board(36, -1);
  for (i=0;i<64;i++){
    last_move[i] = board[i];
  }
}

int set_board(int pos, int setting){
  if (pos > 63 || pos <0){
    return -1;
  }
  if (setting <-1 ||setting >1){
    return -1;
  }
  board[pos] = setting;
  return 1;
}

int is_clear(int pos){
  if (board[pos]==0){
    return 1;
  }
  return -1;
}

int * query_board(){
  return board;
}

int * query_last_move(){
  return last_move;
}

string display_board_small(){
  int i, j, k, x;
  string display;
  display = "%^B_RED%^-+-+-+-+-+-+-+-+-%^RESET%^\n";
  display += "%^B_RED%^ |A|B|C|D|E|F|G|H|%^RESET%^\n";
  for (i=0;i<8;i++){
    display += "%^B_RED%^-+-+-+-+-+-+-+-+-+%^RESET%^\n";
    display += "%^B_RED%^" + (i+1);
    for (j=0;j<16;j++){
      switch (j%2){
      case 0:
        display += "%^B_RED%^|";
        continue;
      case 1..2:
        k = (i*8) + (j/2);
        switch (board[k]){
        case -1:
          display += "%^B_BLACK%^ ";
          continue;
        case 0:
          display += "%^B_RED%^ ";
          continue;
        case 1:
          display += "%^B_WHITE%^ ";
          continue;
        }
      }
    }
    display += "%^B_RED%^|%^RESET%^\n";
  }
  display += "%^B_RED%^-+-+-+-+-+-+-+-+-+%^RESET%^\n";
  return display;
}


string get_board_display(object ob){
  string desc;
  if (objectp(ob)){
    if (ob->query_property("showsmall")){
      desc = display_board_small();
    } else {
      desc = display_board();
    }
  } else {
    desc = "%^BOLD%^%^CYAN%^You're not even a real person. I'm not telling"
           +" you any more!";
  }
  return desc;
}

string display_board(){
  int i, j, k, x;
  string display;
  display = "%^B_RED%^---+---+---+---+---+---+---+---+---%^RESET%^\n";
  display += "%^B_RED%^   | A | B | C | D | E | F | G | H |%^RESET%^\n";
  display += "%^B_RED%^   |   |   |   |   |   |   |   |   |%^RESET%^\n";
  for (i=0;i<8;i++){
    display += "%^B_RED%^---+---+---+---+---+---+---+---+---+%^RESET%^\n";
    for (x=0;x<2;x++){
      if (x==0) display += "%^B_RED%^   ";
      if (x==1) display += "%^B_RED%^ " + (i+1) + " ";
      for (j=0;j<32;j++){
        switch (j%4){
        case 0:
          display += "%^B_RED%^|";
          continue;
        case 1..3:
          k = (i*8) + (j/4);
          switch (board[k]){
          case -1:
            display += "%^B_BLACK%^ ";
            continue;
          case 0:
            display += "%^B_RED%^ ";
            continue;
          case 1:
            display += "%^B_WHITE%^ ";
            continue;
          }
        }
      }
      display += "%^B_RED%^|%^RESET%^\n";
    }
  }
  display += "%^B_RED%^---+---+---+---+---+---+---+---+---+%^RESET%^\n";
  return display;
}

int calculate_position(string x, int y){
  int pos;
  y--;
  pos = y*8;
  switch(x){  //capitalise x
  case "a": x="A"; break;
  case "b": x="B"; break;
  case "c": x="C"; break;
  case "d": x="D"; break;
  case "e": x="E"; break;
  case "f": x="F"; break;
  case "g": x="G"; break;
  case "h": x="H"; break;
}
  switch (x){
  case "A":
    pos += 0;
    break;
  case "B":
    pos += 1;
    break;
  case "C":
    pos += 2;
    break;
  case "D":
    pos += 3;
    break;
  case "E":
    pos += 4;
    break;
  case "F":
    pos += 5;
    break;
  case "G":
    pos += 6;
    break;
  case "H":
    pos += 7;
    break;
  default:
    return -1;
  }
  return pos;
}

int flip(int col,int pos,int dir){
  int * flip_pos, i, j, curr_pos, flipping, result, final_result;
  final_result = -1;
  result = 0;
  curr_pos = pos;
  flipping = 0;  
  flip_pos = ({});
  for (j=0;j<7;j++){
    curr_pos += dir;
    if (curr_pos<0 || curr_pos >63){
      break;
    }
    if ((dir == 1||dir == 9 || dir ==-7) && curr_pos % 8 < pos %8){
      break;
    }
    if ((dir == -1||dir == -9|| dir ==7) && curr_pos % 8 > pos %8){
      break;
    }
    if (flipping == 0 && board[curr_pos] == col){
        break;
    }
    if (board[curr_pos]==0){
      break;
    }
    if (flipping == 1 && board[curr_pos] == col){
      result = 1;
      break;
    }
    if (board[curr_pos] == col *-1){
      flipping = 1;
      flip_pos += ({ curr_pos });
      continue;
    }
  }
  if (sizeof(flip_pos)>0 && result == 1){
    for (j=0;j<sizeof(flip_pos);j++){
      curr_pos = flip_pos[j];
      board[curr_pos] = col;
    }
    final_result = 1;
  }
  return final_result;
}

int place_counter(string colour, string x, int y){
  int pos, col, i, j, k, dir, result, * backup;
  backup = allocate(64);
  result = -1;
  pos = calculate_position(x, y);
  if (pos <0 ||pos >63){
    return -3;
  }
  if (board[pos]!=0){
    return -2;
  }
  switch(colour){
  case "black":
    col = -1;
    break;
  case "white":
    col = 1;
    break;
  }
  for (i=0;i<64;i++){
    backup[i] = last_move[i];
  }
  for (i=0;i<64;i++){
    last_move[i] = board[i];
  } 
  for (i=0;i<8;i++){
    dir = DIRECTIONS[i];
    if (flip(col,pos,dir)>0){
      result = 1;
      board[pos]=col;
    }
  }
  if (result < 1){
    for (i=0;i<64;i++){
      last_move[i] = backup[i];
    }
  }
  return result;
}