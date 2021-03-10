#include <std.h>
#include "../wemic.h"

inherit OBJ + "othello2.c";

int check_board(string str);
int place_piece(string str);
int show_rules(string str);
int set_piece(string str);
int setup_board(string str);
void setup_board2(object ob);
int show_small(string str);

void create(){
  ::create();
  set_id(({"board","game board", "game", "board"}));

  set_name("game board");
  set_short("an interesting looking game board");
  set_long( (: TO, "long_desc" :) );
  set_read("To play: \n"
          +"%^BOLD%^%^YELLOW%^rules %^RESET%^: gives you the standard rules"
          +" of play\n"
          +"%^BOLD%^%^YELLOW%^setup%^RESET%^: Sets up the board with the"
          +" starting positions.\n"
          +"%^BOLD%^%^YELLOW%^place <colour> A5 %^RESET%^: Places a piece"
          +" of the named colour (black or white), at the indicated"
          +" position. Flips any other pieces that should be flipped,"
          +" according to the %^BOLD%^%^YELLOW%^rules%^RESET%^.\n"
          +"%^BOLD%^%^YELLOW%^reverse move %^RESET%^: Takes back the last"
          +" move played\n"
          +"%^BOLD%^%^YELLOW%^check board %^RESET%^: Lets you check the"
          +" current position of the pieces, without looking at the whole"
          +" board description, or telling others you were looking.\n"
          +"%^BOLD%^%^YELLOW%^set A5 <colour> %^RESET%^: Sets the named"
          +" square to the appropriate colour (black, white or blank). Does"
          +" NOT flip any other pieces. This is NOT used for playing the"
          +" game, but for setting up the"
          +" board to a previous game or play puzzle.\n"
       +"%^BOLD%^%^YELLOW%^display small %^RESET%^: Toggles your display to"
          +" show a smaller version of the board, which may be easier to"
          +" view on some clients. Lasts until you log out.\n"
       +"%^BOLD%^%^YELLOW%^display large %^RESET%^: Returns you to a large"
          +" size display of the board, if you have previously chosen to"
          +" have a small display.");
           
}

void init(){
  ::init();
  add_action("check_board", "check");
  add_action("place_piece", "place");
  add_action("set_piece", "set");
  add_action("setup_board", "setup");
  add_action("show_rules", "rules");
  add_action("show_small", "display");
  add_action("reverse_move", "reverse");
}

string long_desc(){
  string desc;
  desc = "A board made from some sort of red %^RED%^hide%^RESET%^, divided"
         +" up into eight rows of eight squares. The board comes with a"
         +" number of counters. These are discs of%^BOLD%^%^BLACK%^"
         +" obsidian%^RESET%^ and%^BOLD%^%^WHITE%^"
         +" iv%^RESET%^o%^BOLD%^%^WHITE%^ry%^RESET%^, somehow attached"
         +" together to make counters with one %^BOLD%^%^WHITE%^white face"
         +" %^RESET%^and one %^BOLD%^%^BLACK%^black face%^RESET%^ each."
         +" There are some instructions written on the board.\n";
  desc += get_board_display(TP);
  return desc;
}

int check_board(string str){
  if (!stringp(str) || !id(str)){
    tell_object(TP, "Try 'check board'");
    return 1;
  }
  tell_object(TP, get_board_display(TP));
  return 1;
}

int place_piece(string str){
  object room;
  string location, x, colour, desc, ystring;
  int y, pos, result;
  if (sscanf (str, "%s %s", colour, location)<2){
    tell_object(TP, "Try <place 'colour' 'location'>, eg <place black a5>");
    return 1;
  }
  if (colour != "black" && colour != "white"){
    tell_object(TP, "You must use a colour of either 'black' or 'white'");
    return 1;
  }
  x = location[0..0];
  ystring = location[1..1];
  y = atoi(ystring);
  if (y>8||y<1){
    tell_object(TP, "Location must be stated in a format with one letter"
                   +" and one number, corresponding to the markings on the"
                   +" board, e.g 'A5'. The number must be between 1 and"
                   +" 8.");
    return 1;
  }
  pos = calculate_position(x, y);
  if (pos <0){
    tell_object(TP, "Location must be stated in a format with one letter"
                   +" and one number, corresponding to the markings on the"
                   +" board, e.g 'A5'. The number must be between 1 and"
                   +" 8. The letter should be A,B,C,D,E,F,G or H");
    return 1;
  }
  result = place_counter(colour, x, y);
  switch(result){
  case 1: 
    desc =  "%^ORANGE%^You place a counter " + colour + " face up on square"
           +" " + location + ". You then flip over all the counters of the"
           +" other colour that are sandwiched between this counter and"
           +" another counter the same colour. The board now looks like"
           +" this: %^RESET%^";
    desc += get_board_display(TP);
    tell_object (TP, desc);
    room = ETP;
    if (objectp(room)){
      tell_room(room, "%^ORANGE%^" + TPQCN + "%^RESET%^%^ORANGE%^ places"
                     +" a counter " + colour + " face up on square " 
                     + location + " and flips over a number of other"
                     +" counters, completing " + TP->QP + " turn.", TP);
    }
    break;
  case -2: 
    tell_object(TP, "There is already a counter at location " + location  
                   +", so this is not a valid move. If you want to put a"
                   +" counter there anyway , use the command 'set " 
                   + location + " " + colour + "'");
    break;
  case -3:
    tell_object(TP, "That is not a valid location. Please try again, the"
                   +" location should look something like this: D6");
    break;
  case -1: 
    tell_object(TP, "Placing a " + colour + " counter at location " 
                   + location + " does not sandwich any counters of the"
                   +" other colour between this counter and another " 
                   + colour + " one, so this is not a valid move. If you"
                   +" want to put a counter there anyway , use the command"
                   +" 'set " + location + " " + colour + "'");
    break;
  }
  return 1;
}

int show_rules(string str){
  tell_object(TP, "%^BOLD%^%^WHITE%^1) %^RESET%^%^ORANGE%^The board is set"
                 +" up with four pieces, two %^BOLD%^%^BLACK%^black"
                 +" %^RESET%^%^ORANGE%^and two %^BOLD%^%^WHITE%^white"
                 +" %^RESET%^%^ORANGE%^, in"
                 +" the centre four squares. The colours are arranged in a"
                 +" diagonal cross. Each player takes it in turns to place"
                 +" a counter on the board, with their own colour showing"
                 +". Either player may start\n"
                 +"%^BOLD%^%^WHITE%^2) %^RESET%^%^ORANGE%^Players may only"
                 +" place a counter on an empty square. The counter must be"
                 +" placed so as to 'sandwich' one or more counters" 
                 +" showing the opponent's colour. A counter is considered"
                 +" 'sandwiched if it lies in a straight line between the"
                 +" placed counter and another counter showing the current"
                 +" player's colour.\n"
                 +"%^BOLD%^%^WHITE%^3) %^RESET%^%^ORANGE%^When a counter is"
                 +" placed, all of the opponent's colour counters which are"
                 +" sandwiched between the placed counter and any other"
                 +" counter showing the player's colour are 'flipped', so"
                 +" that they now show the player's colour.\n"
                 +"%^BOLD%^%^WHITE%^4) %^RESET%^%^ORANGE%^If a player is"
                 +" unable to place a counter so that it will sandwich one"
                 +" or more of the opponent's counters, the player must"
                 +" miss a turn.\n"
                 +"%^BOLD%^%^WHITE%^5) %^RESET%^%^ORANGE%^If a player is"
                 +" able to place a counter so that it will sandwich one or"
                 +" more of the opponent's counters, they must do so."
                 +" Players may not elect to miss a turn.\n"
                 +"%^BOLD%^%^WHITE%^6) %^RESET%^%^ORANGE%^If neither player"
                 +" is able to place a counter, or if the board is full,"
                 +" the game ends.\n"
                 +"%^BOLD%^%^WHITE%^7) %^RESET%^%^ORANGE%^The winner is the"
                 +" player whose colour is showing on most counters"
                 +" at the end of the game.");
  return 1;
}

int set_piece(string str){
  string colour, location, x, ystring;
  int y, pos, setting;
  if (!stringp(str)) {return 0;}
  if (sscanf(str, "%s %s", colour, location)<2){
    tell_object(TP, "Try 'set <location> <colour>', eg 'set a5 black'");
    return 1;
  }
  switch (colour){
  case "black":
    setting  = -1;
    break;
  case "white":
    setting = 1;
    break;
  case "blank":
    setting = 0;
    break;
  default:
    tell_object(TP, "You can only set a square with the colour 'black' or"
                   +" 'white' - or 'blank'");
    return 1;
  }
  x = location[0..0];
  ystring = location[1..1];
  y = atoi(ystring);
  if (y<1 || y>8){
    tell_object(TP, "You can only specify a square in the format of a"
                   +" letter followed by a number (eg A5). The number must"
                   +" be between 1 and 8");
    return 1;
  }
  pos = calculate_position(x,y);
  if (pos <0 ||pos >63){
    tell_object(TP, "You can only specify a square in the format of a"
                   +" letter followed by a number (eg A5). The letter must"
                   +" be A,B,C,D,E,F,G or H");
    return 1;
  }
  set_board(pos, setting);
  return 1;
}

void setup_board2(object ob){
  object room;
  if (!objectp(ob)){
    return;
  }
  room = environment(ob);
  tell_object(ob, "%^ORANGE%^You finish setting up the playing pieces");
  if (objectp(room)){
    tell_room(room, "%^ORANGE%^" + ob->QCN + "%^RESET%^%^ORANGE%^ finishes"
                   +" setting up the playing pieces", ob);
  }
  setup();
  return 1;
}

int setup_board(string str){
  tell_object(TP, "%^ORANGE%^You set about returning the pieces to their"
                 +" starting positions");
  if (objectp(ETP)){
    tell_room(ETP, "%^ORANGE%^" + TPQCN + "%^RESET%^%^ORANGE%^ begins"
             +" setting up the playing counters in their starting"
             +" positions", TP);
  }
  call_out("setup_board2", 3, TP);
  return 1;
}

int show_small(string str){
  if (!str){
    tell_object(TP, "Try 'display small' or 'display large'");
    return 1;
  }
  switch (str){
  case "small":
    if (TP->query_property("showsmall")){
      tell_object(TP,"You are already viewing the game as a small display."
                    +" Try 'display large' if you would like to see the"
                    +" bigger picture.");
      return 1;
    }
    TP->set_property("showsmall", 1);
    tell_object(TP, "You will now view the game as a small display. Use"
                   +" 'display large' if you would like to see the bigger"
                   +" picture again.");
    return 1;
  case "large":
    if (TP->query_property("showsmall")){
      TP->remove_property("showsmall");
      tell_object(TP,"You will now view the game as a large display. Use"
                    +"'display small' if you would prefer to see the"
                    +" smaller version again.");
      return 1;
    }
    tell_object(TP, "You are already seeing the game as a large display."
                   +" Use 'display small' if you would rather see the"
                   +" smaller version.");
    return 1;
  default:
    tell_object(TP, "Use 'display small' to view the game as a small sized"
                   +" display, or 'display large' to see the bigger"
                   +" version.");
    return 1;
  }
}

int reverse_move(string str){
  object room;
  if (!str || str != "move"){
    return 0;
  }
  if (last_move == board){
    tell_object(TP, "There is no last move stored for you to revert to."
                   +" Sorry. You may be able to set the board how you want"
                   +" it, using the 'set' command.");
    return 1;
  }
  board = last_move;
  room  = ETP;
  tell_object (TP, "%^ORANGE%^You rearrange the pieces, setting them back"
                  +" to the previous position");
  if (objectp(room)){
    tell_room(room, "%^ORANGE%^" + TPQCN + "%^RESET%^%^ORANGE%^ rearranges"
                   +" the pieces on the gameboard, setting them back to the"
                   +" previous position", TP);
  }
  return 1;
}