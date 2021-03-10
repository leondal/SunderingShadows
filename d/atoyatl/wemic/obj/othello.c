#include <std.h>
#define DIRECTIONS ({-8,-7,1,9,8,7,-1,-9})


inherit OBJECT;

int * board, next_player;

int flip(int col, int pos,int dir);
int place_counter(string colour, string x, int y);
int set_board(int pos, int setting);
string display_board();

void create(){
  ::create();
  board = allocate(64);
  set_id(({"board","game board", "game"}));
  set_name("game board");
  set_short("an interesting looking game board");
  setup_board();
  set_long( (: TO, "long_desc" :) );
  set_read(instruction());
  if (random (2)) next_player = 1; else next_player = -1;
}

void init(){
  ::init();
  add_action("place_counter", "place");
  add_action("prepare_board", "setup");
}

int query_counter(int pos){
  return board[pos];
}

void setup_board(){
  int i;
  for (i=0;i<64;i++){
    board[i] = 0;
  }
  set_board(27, -1);
  set_board(28, 1);
  set_board(35, 1);
  set_board(36, -1);
}

int prepare_board(string str){
  if (str != "board" && str != "game")
  {
    return notify_fail("Try <setup board>");
  }
  tell_object(TP, "You begin setting up the game board, ready to play");
  tell_room(ETP, TPQCN + " begins setting up the game board, ready to play", TP);
  call_out("prepare_board2", 2, TP);
  return 1;
}

void prepare_board2(object ob){
  if (!objectp(ob)) return;
  if (!present(TO, ob))
  {
    if (!objectp(environment(ob))|| !present(TO, environment(ob)) )
    {
      tell_object(TP, "The game isn't around here, so you can't finish setting it up");
      return;
    }
  }
  setup_board();
  tell_object(ob, "You finish setting up the game");
  if (objectp(environment(ob))) tell_room(environment(ob), ob->QCN + " finishes setting up the game", ob);
}

int place_counter(string str){
  string square, letter, number, colour;
  int num, x, y, loc, result;
  num = sscanf(str, "%s counter on %s", colour, square);
  if (num<2)
  num = sscanf(str, "%s on %s", colour, square);
  if (strlen(square)>1)
  {
    letter = square[0..0];
    number = square[1..1];
    y = atoi(number);
  }
  if (y<1 && number != "0") return notify_fail("You need to enter a letter followed by a number, like 'A4' or 'C3'");
  if (y>8 ) return notify_fail("You need to enter a letter followed by a number between 1 and 8, like 'A4' or 'C3'");
  if (lower_case(colour) == "white" && next_player !=1)
  {
    tell_object(TP,  "It's not white's turn next!");
   return 1;
  }
  if (lower_case(colour) == "black" && next_player != -1)
  {
    tell_object(TP,  "It's not black's turn next!");
   return 1;
  }
  switch(lower_case(letter))
  {
  case "a":
    x = 0;
    break;
  case "b":
    x=1;
    break;
  case "c":
    x=2;
    break;
  case "d":
    x=3;
    break;
  case "e":
    x=4;
    break;
  case "f":
    x=5;
    break;
  case "g":
    x=6;
    break;
  case "h":
    x=7;
    break;
  default:
    return notify_fail("You need to enter a letter between A and H, followed by a number, like 'A4' or 'C7'");
    break;
  }   
  loc = (y-1) *8 + x;
  report("Attempting to place a " + colour + " counter at position " + loc);
  result = set_counter(colour, letter, y, 0);
  if (result != 1) 
  {
    tell_object(TP, "It is not a legal move to place a " + colour + " counter at position " + letter + number + ". You can only place counters adjacent to existing counters, and the placement must result in at least one counter being flipped");
    return 1;
  }
  tell_object(TP, "You place a " + colour + " counter at position " + letter + number + " and flip all the relevant counters for the move"); 
  tell_room(ETP, TPQCN + " places a "+ colour + " counter at position " + letter + number + " and flips all the relevant counters for the move", TP);
  switch(colour){
  case "white":
    if (can_move("black"))
    {
      next_player = -1;
    } else 
    {
      if (!can_move("white"))
      {
        tell_room(ETP, "Neither player can move, Game over");
        tell_room(ETP, announce_winner());
        return 1;
      }
      tell_room(ETP, "There are no legal moves for black to make. White's turn again.");
    }
    tell_room(ETP, "Black's turn next");
    next_player = -1;
    break;
  case "black":
    if (can_move("white"))
    {
      next_player = -1;
    } else 
    {
      tell_room(ETP, "There are no legal moves for white to make. Black's turn again.");
    }
    tell_room(ETP, "White's turn next");
    next_player = 1;
    break;
  }
  tell_object(TP, display_board());
  return 1;
}

int * get_scores(){
  int w_score, b_score, point;
  w_score = 0;
  b_score = 0;
  foreach(point in board)
  {
    if (point == 1) w_score ++;
    if (point == -1) b_score ++;
  }
  return ({w_score, b_score});
}

string announce_scores(int w_score, int b_score){
  string result;
  result = "%^BOLD%^%^WHITE%^White: " + w_score + "     %^BOLD%^%^BLACK%^Black: " + b_score;
  return result;
}

string announce_winner(int w_score, int b_score){
  string result;
  if (w_score == b_score)
  {
    result = "\n%^BOLD%^%^YELLOW%^Result: %^BOLD%^%^RED%^DRAW!"; 
  } else
  {
    if (w_score > b_score) result = "\n%^BOLD%^%^YELLOW%^Winner:%^BOLD%^%^WHITE%^ WHITE";
    else result = "\n%^BOLD%^%^YELLOW%^Winner:%^BOLD%^%^BLACK%^ BLACK"; 
  }
  return result;
}

int set_board(int pos, int setting){
  if (pos > 59 || pos <0){
    return -1;
  }
  if (setting <-1 ||setting >1){
    return -1;
  }
  board[pos] = setting;
  return 1;
}

string long_desc(){
  string desc;
  desc = "A board made from some sort of hide, divided up into eight rows"
         +" of eight squares. There are 64 counters, each with a white side and a black side. There are some instructions for how to play written on the board\n";
  desc += display_board();
  return desc;
}

string display_board(){
  int i, j, k, x, * scores;
  string display;
  display = "Next player: ";
  if (next_player ==1) display += "%^BOLD%^%^WHITE%^white%^RESET%^\n";
  else display += "%^BOLD%^%^BLACK%^black%^RESET%^\n";
  display += "%^B_RED%^--+--+--+--+--+--+--+--+--\n";
  display += "%^B_RED%^  |A |B |C |D |E |F |G |H |\n";
//  display += "%^B_RED%^ | | | | | |   |   |   |\n";
  for (i=0;i<8;i++){
    display += "%^B_RED%^--+--+--+--+--+--+--+--+--+\n";
    for (x=0;x<2;x++){
      if (x==0) display += "%^B_RED%^  ";
      if (x==1) 
      display += "%^B_RED%^" + (i+1) + " ";
      for (j=0;j<24;j++){
        switch (j%3){
        case 0:
          display += "%^B_RED%^|";
          continue;
        case 1..2:
          k = (i*8) + (j/3);
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
      display += "|\n";
    }
  }
  display += "%^B_RED%^--+--+--+--+--+--+--+--+--+\n";
  scores = get_scores();
  display += "\n" + announce_scores(scores[0], scores[1]);
  if (!can_move("white") && !can_move("black"))
  {
    display += "%^RESET%^\n\n" + announce_winner(scores[0], scores[1]);
  }
  return display;
}

void report(string str){
//  "/daemon/reporter_d"->report("lujke", str);
}


int line_crossed(start_point, end_point, dir){
  int start_x, start_y, end_x, end_y, result;
  result = 0;
  start_x = start_point % 8;
  start_y = start_point / 8;
  end_x = end_point % 8;
  end_y = end_point / 8;
  switch(dir)
  {
  case -9:
    if (start_x ==0 || start_y==0) result = 1;
    break;
  case -8:
    if ( start_y==0) result = 1;
    break;
  case -7:
    if (start_x ==7 || start_y==0) result = 1;
    break;
  case -1:
    if (start_x ==0) result = 1;
    break;
  case 1:
    if (start_x ==7) result = 1;
    break;
  case 7:
    if (start_x ==0 || start_y==7) result = 1;
    break;
  case 8:
    if ( start_y==7) result = 1;
    break;
  case 9:
    if (start_x ==7 || start_y==7) result = 1;
    break;
  }
  return result;
}



varargs int flip(int col,int pos,int dir, test){ //pass 1 to test if you are just checking whether a flip is possible
  object lujke;
  int * flip_pos, i, j, curr_pos, flipping, result, final_result;
  final_result = -1;
  lujke = find_player("lujke");
//  for (i=0;i<8;i++){
    result = 0;
    curr_pos = pos;
    flipping = 0;  
    flip_pos = ({});
    for (j=0;j<8;j++){
      curr_pos += dir;
      if (curr_pos<0 || curr_pos >63)
      {
        tell_object(TP, "position " + curr_pos + " is out of bounds");
        break;
      }
      if (line_crossed(curr_pos - dir, curr_pos, dir))
      {
        tell_object(lujke, "%^BOLD%^%^RED%^A line was crossed between position " + (curr_pos - dir) + " and " + curr_pos);
        break;
      } else
      {
        tell_object(lujke, "%^ORANGE%^No line was crossed between position " + (curr_pos - dir) + " and " + curr_pos);
      }
      tell_object(lujke, "Checking square" + curr_pos + "\n");
      if (flipping == 0 && board[curr_pos] == col){
        tell_object(lujke, "No flip available in direction " + dir + "\n");
        break;
      }
      if (board[curr_pos]==0){
        tell_object(lujke, "No counter at location " + curr_pos + "\n");
        break;
      }
      if (flipping == 1 && board[curr_pos] == col){
        tell_object(lujke, "Flip available in direction " + dir + "\n");
        result = 1;
        break;
      }
      if (board[curr_pos] == col *-1){
        flipping = 1;
        flip_pos += ({ curr_pos });
        tell_object(lujke, "Flip ? available in direction " + dir + " Potentially flippable tiles: " + sizeof(flip_pos));
        continue;
      }
    }
    if (test ==1)
    {
      if (sizeof(flip_pos)>0 && result == 1)
      {
        return 1;
      } else
      {
        return 0;
      }
        
    }
    if (sizeof(flip_pos)>0 && result == 1){
      for (j=0;j<sizeof(flip_pos);j++){
        curr_pos = flip_pos[j];
        board[curr_pos] = col;
      }
      final_result = 1;
    }
//  }
  return final_result;
}

varargs int set_counter(string colour, string x, int y, int test){
  object lujke;
  int pos, col, i, j, dir, result;
  lujke = find_player("lujke");
  result = -1;
  y--;
  pos = y*8;
  switch (upper_case(x)){
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
    report("Othello place_counter: Letter is not valid");
    return -1;
  }
  report("Checking position " + pos);
  if (board[pos]!=0){
    report("Othello: position " + pos + " already has a counter: " + board[pos]);
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
  for (i=0;i<8;i++){
    dir = DIRECTIONS[i];
    report("checking direction " + dir + "\n");
    if (flip(col,pos,dir, test)>0){
      report( "Yes, that works!\n");
      result = 1;
      if (test!=1) board[pos]=col;
    } else report("No, that doesn't work");
  }
  return result;
}

string get_letter(int i){
  i = i % 8;
  switch(i)
  {
  case 0:
    return "A";
    break;
  case 1:
    return "B";
    break;
  case 2:
    return "C";
    break;
  case 3:
    return "D";
    break;
  case 4:
    return "E";
    break;
  case 5:
    return "F";
    break;
  case 6:
    return "G";
    break;
  case 7:
    return "H";
    break;
  }
}

int can_move(string colour){
  int i;
  for (i=0;i<sizeof(board);i++)
  {
    if (board[i] != 0) continue;
    if(set_counter(colour, get_letter(i), i/8+1, 1)>0) return 1;
  }
  return 0;
}

string instruction(){
  return "%^BOLD%^%^RED%^Rules of play:%^RESET%^\n\n"

+"%^ORANGE%^*%^RESET%^ Each counter has a %^BOLD%^%^WHITE%^white%^RESET%^ side and a %^BOLD%^%^BLACK%^black%^RESET%^ side, so they can be flipped over to change the colour they are displaying.\n"
+"%^ORANGE%^*%^RESET%^ The game begins with four counters set up in the central squares, alternating %^BOLD%^%^WHITE%^white%^RESET%^-%^BOLD%^%^BLACK%^black%^RESET%^ in a 2x2 square.\n"
+"%^ORANGE%^*%^RESET%^ Two players take turns to place one counter at a time on the board.\n"
+"%^ORANGE%^*%^RESET%^ Each player is assigned a colour, and always places their counter with their own colour face upwards.\n"
+"%^ORANGE%^*%^RESET%^ The winner is the player who has the most counters displaying their colour when the game ends.\n"
+"%^ORANGE%^*%^RESET%^ Each counter played must be laid adjacent to an opponent's counter so that the opponent's counter or a row of opponent's counters is flanked by the new counter and another counter of the player's colour. All of the opponent's counters between these two counters are 'captured' and turned over to match the player's colour.\n"

+"%^ORANGE%^*%^RESET%^ It can happen that a counter is played so that counters or rows of counters in more than one direction are trapped between the new counter played and other counters of the same colour. In this case, all the counters in all viable directions are turned over.\n"

+"%^ORANGE%^*%^RESET%^ The game is over when neither player has a legal move (i.e. a move that captures at least one opposing counter) or when the board is full.\n"
+"\n%^BOLD%^%^YELLOW%^Commands:\n"
+"%^RESET%^%^ORANGE%^<place white|black on [square]> %^RESET%^In place of [square], enter a single letter and number to indicate a square. E.g. A3 or D7\n"
+"%^ORANGE%^<setup board> %^RESET%^Arrange the board ready to start a game";
}
