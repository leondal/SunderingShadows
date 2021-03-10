//Coded by Lujke, all on his own - with a little (vital) help from Grendel
// on setting up the arrays, and much credit to all the other wizzes who 
// put up withn Lujke bugging them about it - notably Cythera and Circe.

#include <std.h>
inherit OBJECT;

#define BLACK 1
#define WHITE 2
#define ERROR 666

#define EMPTY 0
#define B_PAWN 1
#define W_PAWN 2
#define B_ROOK 3
#define W_ROOK 4
#define B_KNIGHT 5
#define W_KNIGHT 6
#define B_BISHOP 7
#define W_BISHOP 8
#define B_QUEEN 9
#define W_QUEEN 10
#define B_KING 11
#define W_KING 12


// There are 64 squares on the board. Each square is represented by an
// int in the array 'squares'. Each int in the array represents a piece
// type, from 0 (empty) through to W_KING (12). See definitions above.

int *squares;


// squares are numbered from 0-63, in rows of 8
// at the start of the game, white's pieces occupy the first two rows:
// ie squares 0-7 and 8-15. Black's pieces occupy the last two rows:
// ie squares 56-63 and 48-55.

//nextmove keeps track of which colour is next to play.
int nextmove;

// lastsquare and lastmove track the position of the last piece to be 
// moved, and the move that was made to get it there. lastpiece remembers // the piece (if any) that was captured during the last move.

int lastsquare;
int lastmove;
int lastpiece;

// cheating is set to 0 most of the time, but 1 if a player decides to 
// cheat. It's used to allow the player to make a move that isn't legal 
// within the rules of the game.

int cheating;

// The variables w_king_move through b_rook_move_2 track whether the 
// pieces involved in castling have been moved so far in the game

int w_king_move;
int w_rook_move_1;
int w_rook_move_2;
int b_king_move;
int b_rook_move_1;
int b_rook_move_2;


int calculate_position(string str);
int check_bishop_move(int startpos, int move, object ob);
int check_board(string str);
int cheat_move(string str);
int check_diagonal_move(int start_pos,int move, object ob);
int check_end_square(int startpos, int move, object ob);
int check_horiz_move(int startpos, int move, object ob);
int check_king_move(int startpos, int move, object ob);
int check_knight_move(int startpos, int move, object ob);
int check_legal_move(int piecetype, int startpos, int move, object ob);
int check_occupied(int square);
int check_pawn_move(int startpos, int move, object ob);
int check_queen_move(int startpos, int move, object ob);
int check_rook_move(int startpos, int move, object ob);
int check_safe(int square, int colour, object ob);
int check_vert_move(int startpos, int move, object ob);
int clear_board(string str);
void clear_board2(object ob);
void finalise_move(int startpos, int move);
string get_piece_name(int piecetype);
string get_position_name(int position);
int help_board(string str);
int move_piece(string str);
int place_piece(string str);
void reset_board();
void send_move_message(int startpos, object ob, string str);
void send_capture_message(int startpos, int endpos, object ob, 
                                                     string str);
int set_board(string str);
void set_board2(object ob);
string show_board();
string show_next_move();
string show_square(int square);
int take_back(string str);
int upset_board(string str);

void create() {
    ::create();
    squares = allocate(64);
    reset_board();
    cheating = 0;
    w_king_move = 0;
    w_rook_move_1 = 0;
    w_rook_move_2 = 0;
    b_king_move = 0;
    b_rook_move_1 = 0;
    b_rook_move_2 = 0;
    nextmove = WHITE;
    set_id( ({"board", "chessboard", "chess board", "game", 
                                                    "game board"}) );
    set_name("chessboard");
    set_short("chess board");
    set_long("%^ORANGE%^A finely crafted chess board made to fold away "
            +"into \na box for easy storage. All the pieces are hand\n"
            +"carved and laquered.\n"
            +"You can %^BOLD%^%^YELLOW%^<check board>%^RESET%^%^ORANGE%^"
            +" to see the current state of play.\n"
            +"Use %^BOLD%^%^YELLOW%^<help board>%^RESET%^%^ORANGE%^ for"
            +" help in how to play");
    set_weight(1);
    set_value(5000 + random(2000));
}


void init() {
    ::init();
      add_action("check_board", "check");
	add_action("move_piece","piece");
      add_action("set_board", "set");
      add_action("help_board","help");
      add_action("cheat_move", "cheat");
      add_action("take_back", "take");
      add_action("place_piece", "place");
      add_action("upset_board", "upset");
      add_action("clear_board", "clear");
}

int help_board(string str)
{
  if (str=="board"||str =="chess board"||str=="chess set" 
                  ||str== "chessboard")
  {
    tell_object(TP,"This is a standard chess board. Commands are as"
                  +" follows:\n"
                  +"%^BOLD%^%^YELLOW%^check board \t- %^RESET%^\tsee the"
                  +" current state of play\n"
                  +"%^BOLD%^%^YELLOW%^set board \t-\t%^RESET%^reset all"
                  +" the pieces to their starting positions. \n\t\t\t(Not"
                  +" a great idea if someone else is playing.)\n"
                  +"%^BOLD%^%^YELLOW%^piece A1 to A2 \t- %^RESET%^\tmove"
                  +" the piece on square A1 to square A2. \n\t\t\t"
                  +"%^CYAN%^(NB This will only work if you are making a"
                  +" legal move)%^RESET%^\n"
                  +"%^BOLD%^%^YELLOW%^take back \t-%^RESET%^\ttake back"
                  +" the last move made\n"
                  +"%^BOLD%^%^YELLOW%^upset board \t- \t%^RESET%^knock"
                  +" the board over, knocking the pieces out of position."
                  +"\n\t\t\tThe recourse of bad losers the realms over.\n"
                  +"%^BOLD%^%^YELLOW%^clear board \t- %^RESET%^\tclears" 
                  +" all the pieces from the board.\n"
                  +"%^BOLD%^%^YELLOW%^clear <position> - %^RESET%^\t"
                  +"clears the piece from the named square\n"
                  +"%^BOLD%^%^YELLOW%^help pieces \t- %^RESET%^\tgives a" 
                  +" list of the pieces and how they move.\n"
                  +"%^BOLD%^%^YELLOW%^place %^CYAN%^<colour>"
                  +" %^RED%^<piece name> %^YELLOW%^on %^GREEN%^<square>"
                  +" %^YELLOW%^- %^RESET%^this places a piece of the"
                  +" named colour and type on the square specified. E.g"
                  +" 'place white knight on b7'. Useful for setting up"
                  +" puzzles or challenges, as well as for returning to"
                  +" old games.\n");

    return 1;
  }
  if (str== "pieces")
  {
    tell_object(TP, "%^BOLD%^%^RED%^In a standard game of chess, the"
    +" basic moves are as follows:\n%^RESET%^%^BOLD%^%^YELLOW%^Pawns"
    +" %^RESET%^(%^BOLD%^%^WHITE%^p%^RESET%^)"
    +"%^BOLD%^%^BLACK%^:\n%^RESET%^The pawns can advance only one square"
    +" at a time (eg d7 to d6), except on their first move, at which time"
    +" they can advance two sqares (eg a2 to a4)\nHowever, pawns may only"
    +" capture an opponent's piece by moving one space %^CYAN%^diagonally"
    +" %^RESET%^forward.\n"

    +"NB The %^CYAN%^en passant%^RESET%^ rule says that if a pawn moves"
    +" two spaces forwards on its first move, and the first square is"
    +" threatened by one of the opponent's pawns, the opponent may"
    +" capture the pawn in his next move, by moving his pawn as if the"
    +" first player had only moved his pawn one square\n"
   
    +"%^BOLD%^%^YELLOW%^Castles %^RESET%^aka Rooks (%^BOLD%^%^WHITE%^"
    +"C%^RESET%^)%^BOLD%^%^BLACK%^:\n"
    +"%^RESET%^Castles can advance any distance in a straight vertical or"
    +" horizontal line, as long as there are no other pieces in the way."
    +" A castle can capture an opponent's piece if it is at the end of"
    +" the castle's move.\n"

    +"%^BOLD%^%^YELLOW%^Knights %^RESET%^aka Horses (%^BOLD%^%^WHITE%^"
    +"Kn%^RESET%^)"
    +"%^BOLD%^%^BLACK%^:"
    +"\n%^RESET%^Knights move by moving two squares forwards in any"
    +" horizontal or vertical direction, followed by one square to the"
    +" side. They can jump over any obstacle between the beginning and"
    +" end of their move, and can capture an opponent's piece located at"
    +" the end of the knight's move.\n"

    +"%^BOLD%^%^YELLOW%^Bishops%^RESET%^ (%^BOLD%^%^WHITE%^B%^RESET%^)"
    +"%^BOLD%^%^BLACK%^:\n%^RESET%^"
    +"Bishops can move any distance in any diagonal line across the"
    +" board, as long as there are no other pieces in the way. A bishop"
    +" can capture an opponent's piece if it is at the end of the"
    +" bishop's move.\n"

    +"%^BOLD%^%^YELLOW%^Queens%^RESET%^ (%^BOLD%^%^WHITE%^Q%^RESET%^)"
    +"%^BOLD%^%^BLACK%^:\n%^RESET%^"
    +"Queens can move any distance in any vertical, horizontal or"
    +" diagonal line, as long as there are no other pieces in the way. A"
    +" queen can capture an opponent's piece if it is at the end of the"
    +" castle's move.\n%^RESET%^"

    +"%^BOLD%^%^YELLOW%^Kings%^RESET%^ (%^BOLD%^%^WHITE%^Ki%^RESET%^)"
    +"%^BOLD%^%^BLACK%^:\n%^RESET%^"
    +"Kings can move one square in any direction and can capture an"
    +" opponent's piece if it is located in the square the king moves to."
    +" A king is not allowed to move into any square that is threatened"
    +" by one of the opponent's pieces.\n"
   
    +"NB The king also has a special protective move available, called"
    +" %^BOLD%^%^YELLOW%^castling%^RESET%^. See %^BOLD%^%^YELLOW%^<help"
    +" castling>");

    return 1;
  }
  if (interact ("castling", str))
  {
    tell_object(TP, "\t\t%^BOLD%^%^YELLOW%^ Castling\n\n%^RESET%^"
    +" This move involves the king"
    +" and one of his castles. It can only be done if neither the king"
    +" nor the castle have yet moved, and if there are no other pieces"
    +" standing between them./n/nIn order to castle, the king moves two"
    +" squares towards his castle. The castle is then placed on the"
    +" square adjacent to the king, on the opposite side of him that it"
    +" began. The king is not allowed to castle out of check, nor if"
    +" doing so would place him in check, nor if he would have to move"
    +" through a square threatened by an enemy piece in order to castle."
    +"\n\n%^BOLD%^%^YELLOW%^Example%^RESET%^The %^BOLD%^%^WHITE%^White" 
    +" King%^RESET%^ is on square E1 and has a"
    +" %^BOLD%^%^WHITE%^castle%^RESET%^ on square A1. Neither piece has"
    +" moved so far in the game, and all the squares between them (B1, C1"
    +" and D1) are empty. The %^BOLD%^%^WHITE%^King%^RESET%^ can %^BOLD%^"
    +"%^YELLOW%^castle%^RESET%^ by moving from E1 to C1 (two squares"
    +" towards the %^BOLD%^%^WHITE%^castle%^RESET%^). The"
    +" %^BOLD%^%^WHITE%^castle%^RESET%^ is then moved from square A1 to"
    +" square D1 (adjacent to the %^BOLD%^%^WHITE%^King%^RESET%^, on the"
    +" opposite side to him from here it started). This move can only"
    +" take place if the %^BOLD%^%^WHITE%^King%^RESET%^is not in check,"
    +" and if the squares D1 and C1 are not threatened by any enemy"
    +" pieces.");
  }
  return 0;
}

string query_long(string str)
{

  return ::query_long(str) + show_board();
}
int check_board(string str)
{
  if (str=="board"||str =="chess board"||str=="chess set" 
                  ||str== "chessboard")
  {
    tell_object(TP, show_board());
    return 1;
  }
  return 0;
}

int set_board(string str)

{
  if (str=="board"||str =="chess board"||str=="chess set" 
                  ||str== "chessboard")
  {
    tell_object(TP,"You begin setting the chess pieces back to their"
                 +" starting positions.");
    tell_room(ETO, TPQCN + " begins setting the chess pieces back in"
                 +" their starting positions.", TP);
    call_out("set_board2",5, TP);
    return 1;
  }
  return 0;
}

void set_board2(object ob)
{
  if (!objectp(ob)){return;}
  tell_object(ob, "You finish setting up the chess pieces. The board is"
                 +" all ready to start play again.");
  tell_room(ETO, ob->query_cap_name() + " finishes setting up the chess"
               +" pieces. The board is all ready to start play"
               +" again.",ob);
  reset_board();

}

void reset_board()
{
  int i;
  
  lastmove = 0;
  lastsquare = 32;
  lastpiece = 0;
  nextmove=WHITE;
  cheating = 0;
  w_king_move = 0;
  w_rook_move_1 = 0;
  w_rook_move_2 = 0;
  b_king_move = 0;
  b_rook_move_1 = 0;
  b_rook_move_2 = 0;
 
  squares[0]=W_ROOK;
  squares[1]=W_KNIGHT;
  squares[2]=W_BISHOP;
  squares[3]=W_QUEEN;
  squares[4]=W_KING;
  squares[5]=W_BISHOP;
  squares[6]=W_KNIGHT;
  squares[7]=W_ROOK;

  for (i=8;i<16;i++)
  {
    squares[i]=W_PAWN;
  }
  for (i=16;i<48;i++)
  {
    squares[i]=0;
  }
  for (i=48;i<56;i++)
  {
    squares[i]=B_PAWN;
  }

  squares[56]=B_ROOK;
  squares[57]=B_KNIGHT;
  squares[58]=B_BISHOP;
  squares[59]=B_QUEEN;
  squares[60]=B_KING;
  squares[61]=B_BISHOP;
  squares[62]=B_KNIGHT;
  squares[63]=B_ROOK;
}

void send_move_message(int startpos, object ob, string str)
{
  tell_object(TP, "You move the " + get_piece_name(squares[startpos]) 
                 +" from " + str);
  tell_room(ETO, TPQCN + " moves the " 
               + get_piece_name(squares[startpos]) + " from " + str
               , TP);
}
void send_capture_message(int startpos, int endpos, object ob, string str)
{
  tell_object(TP, "You capture the " + get_piece_name(squares[endpos]) 
                 +" with your " + get_piece_name (squares[startpos])
                 +",\n in an attacking move from " + str +"!");
  tell_room(ETO, TPQCN + " takes the " + get_piece_name(squares[endpos]) 
                 +" with " + TP->QP +" "
                 + get_piece_name (squares[startpos])
                 +",\n in an attacking move from " + str+"!", TP);  

}


int check_legal_move(int piecetype, int startpos, int move, object ob)
{
//tell_room(ETO, "int check_legal_move(int piecetype, int startpos,"
 //             +" int move)");
  // returns 
  // 0 if move is illegal
  // 1 if move is legal
  // 2 if move is a capture

  if (piecetype>0 && piecetype <B_ROOK)
  {
    return check_pawn_move(startpos, move, ob);
  }
  
  if (piecetype>W_PAWN && piecetype <B_KNIGHT)
  {
    return check_rook_move(startpos, move, ob);
  }
  if (piecetype>W_ROOK && piecetype <B_BISHOP)
  {
    return check_knight_move(startpos, move, ob);
  }
  if (piecetype>W_KNIGHT && piecetype <B_QUEEN)
  {
    return check_bishop_move(startpos, move, ob);
  }
  if (piecetype > W_BISHOP && piecetype <B_KING)
  {
    return check_queen_move(startpos, move, ob);
  }
  
return check_king_move(startpos, move, ob);

}

int check_safe(int square, int colour, object ob)
{
  // this function is used to check whether square[square] is safe from 
  // attack for the pieces of the player of colour 'colour'
  // return 1 if the square is safe
  // return 0 if the square is threatened
  int i;
  int legal;

  for (i=0;i<64;i++)
  {
    if (colour==BLACK && check_occupied(i)== WHITE
       || colour==WHITE && check_occupied(i)==BLACK)
    {
      if (check_legal_move(squares[i],i,square-i, ob)>0)
      {
        return 0;
      }         
    }
  }
  return 1;
}

int check_pawn_move(int startpos, int move, object ob)
{
  // returns 
  // 0 if move is illegal
  // 1 if move is legal
  // 2 if move is a capture
  // 3 if move was an en-passant capture
  int i;
  int colour;
  colour = check_occupied(startpos);

//tell_room(ETO, "int check_pawn_move(int startpos, int move)");

  //disallow 0 move
  if (move==0)
  {
    return 0;
  }


  //check for simple advance across the board
  if ((move==8&&colour==WHITE)||(move==-8&&colour==BLACK))
  { 
    //make sure destination square is empty
    if (check_occupied(startpos+move)==0)
    return 1;
  }

  //check for two space move on first play
  if (move==16||move==-16)
  {
    if (check_occupied(startpos) == WHITE && startpos>7 && startpos<16)
    { 
      //check no other pieces in path of move
      if (check_occupied(startpos+move)==EMPTY
         && check_occupied(startpos+(move/2))==EMPTY)
      return 1;
    }
    if (check_occupied(startpos) == BLACK && startpos>47 && startpos<56)
    {
      //check no other pieces in path of move
      if (check_occupied(startpos+move)==EMPTY
         && check_occupied(startpos+(move/2))==EMPTY)
      return 1;
    }
    return 0; 
  }
  
  //check for a diagonal move by white to capture opponent's piece
  if (move==7||move==9)
  {
    if (check_occupied(startpos)==WHITE
       && check_occupied(startpos + move)==BLACK)
    {
      return 2;
    }
    //check for 'en passant' capture by white
    if (check_occupied(startpos)==WHITE)
    {
      //check whether the end position is in row 6
      if ((startpos+move)/8==5)
      {
        //check whether the last move taken was to move black's pawn two
        // squares into the square just behind the end position
        if (startpos + move == lastsquare + 8)
        {
          if (squares[lastsquare] == B_PAWN  && lastmove == -16 )
          {
            return 3;
          }
        }
      }
    }
  }
  if (move ==-7||move==-9){
    //check for capture by black
    if (check_occupied(startpos)==BLACK 
       && check_occupied(startpos + move)==WHITE)
    {
      return 2;
    }
    //check for 'en passant' capture by BLACK
    if (check_occupied(startpos)==BLACK)
    {
      //check whether the end position is in row 3
      if ((startpos+move)/8==2)
      {
        //check whether the last move taken was to move black's pawn two
        // squares into the square just behind the end position
        if (startpos + move == lastsquare - 8)
        {
          if (squares[lastsquare] == W_PAWN  && lastmove == 16 )
          {
            return 3;
          }
        }
      }
    }
  }
  return 0;
}


int check_rook_move(int startpos, int move, object ob)
{
//tell_room(ETO, "int check_rook_move(int startpos, int move)");
// return 
// 0 for illegal move
// 1 for legal move
// 2 for capture
  
  
  //disallow 0 move
  if (move==0)
  return 0;

// check for a move along the same row
  if (startpos/8==(move+startpos)/8)
  {
    //return 0 if there is another piece in the way
    if (check_horiz_move(startpos, move, ob)==0)
    {
      return 0;
    }
    return check_end_square(startpos, move, ob);
  }
  //check for move along the same column
  if (move%8==0)
  {
    //return 0 if there is another piece in the way
    if (check_vert_move(startpos,move, ob)==0)
    {
      return 0;
    }
    return check_end_square(startpos, move, ob);
  }
//tell_room(ETO, "That is neither a horizontal move nor a vertical one");

  //if move is neither along same row nor along same column, disallow move
  return 0;
  
}

int check_knight_move(int startpos, int move, object ob)
{
// return 
// 0 for illegal move
// 1 for legal move
// 2 for capture
  if (move==17||move==15||move==10||move==-6||move==-15||move==-17
      ||move==-10||move==6)
  {
    return check_end_square(startpos,move, ob);
  }
  return 0;
}

int check_bishop_move(int startpos, int move, object ob)
{
// return 
// 0 for illegal move
// 1 for legal move
// 2 for capture
  
  
  //disallow 0 move
  if (move==0)
  return 0;

  if (move%9==0||move%7==0)
  {
    //return 0 if there is another piece in the way
    if (check_diagonal_move(startpos, move, ob)==0)
    {
      return 0;
    }
    return check_end_square(startpos, move, ob);

  }
  return 0;
}

int check_queen_move(int startpos, int move, object ob)
{
// return 
// 0 for illegal move
// 1 for legal move
// 2 for capture
  
  
  //disallow 0 move
  if (move==0)
  return 0;

// check for a move along the same row
  if (startpos/8==(move+startpos)/8)
  {
    //return 0 if there is another piece in the way
    if (check_horiz_move(startpos, move, ob)==0)
    {
      return 0;
    }
    return check_end_square(startpos, move, ob);
  }
  //check for move along the same column
  if (move%8==0)
  {
    //return 0 if there is another piece in the way
    if (check_vert_move(startpos,move, ob)==0)
    {
      return 0;
    }
    return check_end_square(startpos, move, ob);
  }


  //check for a diagonal move
  if (move%9==0||move%7==0)
  {
    //return 0 if there is another piece in the way
    if (check_diagonal_move(startpos, move, ob)==0)
    {
      return 0;
    }
    return check_end_square(startpos, move, ob);

  }
  // if move is not horizontal, vertical or diagonal, it is invalid
  return 0;
}

int check_king_move(int startpos, int move, object ob)
{
// return 
// 0 for illegal move
// 1 for legal move
// 2 for capture
  
  
  //disallow 0 move
  if (move==0)
  return 0;

  if (move==1||move==7||move==8||move==9||move==-1
             ||move==-7||move==-8||move==-9)
  {
    return check_end_square(startpos,move, ob);
  }
  // check for castling - white

  if (startpos == 4  && squares[startpos]==W_KING )
  { 
 //   tell_object(ob, "starting position is valid to castle with white");

    switch (move)
    {
    case -2:
      if (w_rook_move_1==1)
      {
        tell_object(ob, "You can't castle that way. You have moved the"
                       +" castle already.");
        return 0;
      }
      if (w_king_move == 1)
      {
        tell_object(ob, "it's too late to castle. You have already"
                       +" moved your king.");
        return 0;
      }
      if (check_horiz_move(startpos, move, ob)==1)
      {
        if (check_occupied(startpos + move)!=0)
        {
          tell_object(ob, "You can't castle there. There is a " 
                         + get_piece_name(squares[startpos+move]) 
                         +" in the way.");
          return 0;
        }
        return 4;
      }
      tell_object(ob,"You can't castle - there is a piece in the way");
      return 0;
      break;

    case 2:
      if (w_rook_move_2==1)
      {
        tell_object(ob, "You can't castle that way. You have moved the"
                       +" castle already.");
        return 0;
      }
      if (w_king_move == 1)
      {
        tell_object(ob, "it's too late to castle. You have already"
                       +" moved your king.");
        return 0;
      }
      if (check_horiz_move(startpos, move, ob)==1)
      {
        if (check_occupied(startpos + move)!=0)
        {
          tell_object(ob, "You can't castle there. There is a " 
                         + get_piece_name(squares[startpos+move]) 
                         +" in the way.");
          return 0;
        }
        return 4;
      }
      tell_object(ob,"You can't castle - there is a piece in the way");
      return 0;
      break;

    }
  return 0;
  }
  //check for castling - black
  tell_object(ob, "Checking to see if you are trying to castle with"
                 +" black");

  if (startpos == 60  && squares[startpos]==B_KING )
  { 
    tell_object(ob, "starting position is valid to castle with black");

    switch (move)
    {
    case -2:
      if (b_rook_move_1==1)
      {
        tell_object(ob, "You can't castle that way. You have moved the"
                       +" castle already.");
        return 0;
      }
      if (b_king_move == 1)
      {
        tell_object(ob, "it's too late to castle. You have already"
                       +" moved your king.");
        return 0;
      }
      if (check_horiz_move(startpos, move, ob)==1)
      {
        if (check_occupied(startpos + move)!=0)
        {
          tell_object(ob, "You can't castle there. There is a " 
                         + get_piece_name(squares[startpos+move]) 
                         +" in the way.");
          return 0;
        }
        return 4;
      }
      tell_object(ob,"You can't castle - there is a piece in the way");
      return 0;
      break;

    case 2:
      if (b_rook_move_2==1)
      {
        tell_object(ob, "You can't castle that way. You have moved the"
                       +" castle already.");
      }
      if (b_king_move == 1)
      {
        tell_object(ob, "it's too late to castle. You have already"
                       +" moved your king.");
        return 0;
      }
      if (check_horiz_move(startpos, move, ob)==1)
      {
        if (check_occupied(startpos + move)!=0)
        {
          tell_object(ob, "You can't castle there. There is a " 
                         + get_piece_name(squares[startpos+move]) 
                         +" in the way.");
          return 0;
        }
        return 4;
      }
      tell_object(ob,"You can't castle - there is a piece in the way");
      return 0;
      break;

    }
  }
  return 0;
}



int check_horiz_move(int startpos, int move, object ob)
{

  //returns 1 if the path between starpos and the end of the move is clear
  //returns 0 if there are other pieces in the way.

  //i is used for looping
  int i;

  if (move==1||move==-1)
  {
    return 1;
  }

  //tell_room(ETO, "int check_horiz_move(int startpos, int move)"); 
  //check for other pieces in the path of the move
  //first for positive values of move

  if (move>1)
  {
    for (i=startpos+1;i<startpos+move;i++)
    {
      if (check_occupied(i)>0)
      {
        return 0;
      }
    }
  }
  //then for negative values of move

  if(move <-1)
  {
    for (i=startpos-1;i>startpos+move;i--)
    {
      if (check_occupied(i)>0)
      {
        return 0;
      }
    }
  }

  return 1;
}



int check_vert_move(int startpos, int move, object ob)
{
  //returns
  //0 if there are other pieces in the way and the move is illegal
  //1 if the path is clear and the move is legal

  //i is used for looping
  int i;

//tell_room(ETO, "int check_vert_move(int startpos, int move)");

  if (move==8||move==-8)
  {
    return 1;
  }

  //check for pieces in path of move
  // first for positive values of move
  if (move > 8)
  {
//    tell_room(ETO,"Checking path to end square.");

    for (i=startpos+8;i<startpos+move;i+=8)
    {
//      tell_room(ETO,"Checking square..");
      if (check_occupied(i)>0)
      {
        return 0;
      }
//    tell_room(ETO,"Path clear to end square.");
   
    }
  }
  //then for negative values of move
 if (move < -8)
  {
    for (i=startpos-8;i>startpos+move;i-=8)
    {
      if (check_occupied(i)>0)
      {
        return 0;
      }
    }
  }

  return 1;
}


int check_diagonal_move(int startpos, int move, object ob)
{
  // returns 0 if the path between startpos and the end position is clear
  // returns 1 if there is another piece in the way

  int i;
  int step;

  if (move==0)
  {
    tell_room(ETO,"diagonal move check incorrectly called on a 0 move!"
                 +"Please do a bug report on the chess board");
    return 1;
  }


  if (move %9 == 0)
  {
    if (move >0)
    {
     step = 9;

    }
    if (move < 0)
    {
      step = -9;
    }
  }
  if (move%7==0)
  {
    if (move > 0)
    {
      step=7;
    }
    if (move <0)
    {
      step = -7;
    }
  }
  if (move==63)
  {
    step = 9;
  }
  if (move==-63)
  {
    step =-7;
  }
  for (i=startpos+step;i!=(startpos+move) && i>=0 && i<64;i+=step)
  {
    if (check_occupied(i)>0)
    {
      return 0;
    }
  }
  return 1;
}

int check_end_square(int startpos, int move, object ob)
{

  //returns 0 if end square is occupied by player's own piece
  //(and the move is therefore illegal)
  //returns 1 if end square is empty
  //returns 2 if the end square is occupied by the opponent's piece
  //(resulting in a capture)

  if (squares[startpos+move]==0)
  {
    return 1;
  }

  if (squares[startpos+move]%2==squares[startpos]%2)
  {
    return 0;
  }
  else
  {
    return 2;
  }
 
  return 5;

}

int check_occupied(int square)
{
//tell_room(ETO, "int check_occupied(int square)");
// returns 
// 0 if the square is unoccupied, 
// 1 if it is occupied by BLACK
// 2 if the square is occupied by WHITE

//tell_room(ETO, "int check_occupied(int square);");

  if (squares[square]==0)
  {
    return EMPTY;
  }
  if(squares[square]%2==1)
  {
    return BLACK;
  } 
  if (squares[square]%2==0)
  {
    return WHITE;
  }
  return ERROR;
}

int cheat_move(string str)
{
  if (!str)
  {
    tell_object(TP, "Try 'cheat a1 to a2', etc");
    return 1;
  }
  if (strlen(str)<6)
  {
    tell_object(TP, "Try 'cheat a1 to a2', etc");
    return 1;
  }
  if (str[3..4]!="to")
  {
    tell_object(TP, "Try 'cheat a1 to a2', etc");
    return 1;
  }
  cheating = 1;
  return move_piece(str);
}

int place_piece(string str)
{
  int i,j;
  string piece;
  string colour;
  string preposition;
  string position;
  int piecetype;
  int pos;
  piece = "";
  colour = "";
  preposition = "";
  position = "";

  for (i=0;i<strlen(str);i++)
  {
    if (str[i..i]==" ")
    { 
      colour += str[0..i-1];
      j=i+1;
      break;
    }
//    colour+=str[i];
  }
  for (i=j;i<strlen(str);i++)
  {
    if (str[i..i]==" ")
    {
      piece += str[j..i-1];
      j=i+1;
      break;
    }
//    piece+=str[i..i];
  }
  for (i=j;i<strlen(str);i++)
  {
    if (str[i..i]==" ")
    {
      preposition += str[j..i-1];
      j = i+1;
      break;
    }
//    preposition+=str[i];
  }
  for (i=j;i<strlen(str);i++)
  {
    if (str[i..i]==" ")
    {
      position = str[j..i-1];
      break;
    }
  }
  if (position=="")
  {
    position = str[j..strlen(str)];
  }
  if (preposition !="on")
  {
    tell_object(TP,"Use 'place <colour> <piece> on <position>\nEg 'place"
                  +" white queen on e4'");
  }
  switch(piece)
  {
  case "pawn":
    piecetype=B_PAWN;
    break;
  case "rook":
    piecetype=B_ROOK;
    break;
  case "castle":
    piecetype=B_ROOK;
    break;
  case "horse":
    piecetype=B_KNIGHT;
    break;
  case "knight":
    piecetype=B_KNIGHT;
    break;
  case "bishop":
    piecetype = B_BISHOP;
    break;
  case "queen":
    piecetype = B_QUEEN;
    break;
  case "king":
    piecetype = B_KING;
    break;
 // default:
    tell_object(TP, "'" + piece + "' is not a valid chess piece\n"
                   +"Try: 'pawn'\t'castle'\t'knight'\n'bishop'\t'queen'"
                    +"\t'king'");
    return 1;
  }
  if (colour == "white" || colour == "yellow")
  {
    piecetype+=1;
  }
  else
  {
    if (colour != "black" && colour != "red" && colour != "blue")
    {
      tell_object(TP, "'" + colour + "' isn't a valid colour!"
                     +"\nTry 'white' or 'red'");
      return 1;
    }
  }
  pos = calculate_position(position);
  if (pos>63)
  {
    tell_object(TP, "'" + position + "' is not a valid position.\n"
                    "+positions run from 'A1' through 'H8'");
    return 1;
  }
  squares[pos] = piecetype;
  tell_object(TP, "You place a " + get_piece_name(piecetype) + " on"
                 +" square " + position);
  tell_room(ETO, TPQCN + " places a " + get_piece_name(piecetype) + " on" 
               +" square " + position, TP);
  return 1;
}

int calculate_position(string str)
{
  int x;
  int y;
  switch(str[0])
  {
  case 'A':
  case 'a':
    x = 0;
    break;
  case 'B':
  case 'b':
    x = 1;
    break;
  case 'C':
  case 'c':
    x = 2;
    break;
  case 'D':
  case 'd':
    x = 3;
    break;
  case 'E':
  case 'e':
    x = 4;
    break;
  case 'F':
  case 'f':
    x = 5;
    break;
  case 'G':
  case 'g':
    x = 6;
    break;
  case 'H':
  case 'h':
    x = 7;
    break;
   default:
    x = 100;
  }
    switch(str[1])
  {
  case '1':
    y = 0;
    break;
  case '2':
    y = 1;
    break;
  case '3':
    y = 2;
    break;
  case '4':
    y = 3;
    break;
  case '5':
    y = 4;
    break;
  case '6':
    y = 5;
    break;
  case '7':
    y = 6;
    break;
  case '8':
    y = 7;
    break;
  default:
    y = 100;
  }
  return x+(y*8);

}

int move_piece(string str)
{
//  int startx;
//  int starty;
//  int finalx;
//  int finaly;
  int startpos;
  int endpos;
  int move;
  int result;
 if(!str) 
 {
   tell_object(TP,"Use 'piece [square 1] to [square 2]'\n(eg 'piece A1"
                 +" to B3'\n");
   return 1;
 }
  if (strlen(str)<5)
  {
    tell_object(TP, "Use 'piece [square 1] to [square 2]'");
    tell_object(TP, "(eg 'piece A1 to B3')");
  }
  if (str[3..4]!="to")
  {
    tell_object(TP, "Use 'piece [square 1] to [square 2]'");
    tell_object(TP, "(eg 'piece A1 to B3')");
  }
  startpos = calculate_position(str[0..1]);
  endpos = calculate_position(str[6..7]);

// disallow moves that begin or end beyond the scope of the board
  if (startpos>63||endpos>63)
  {
    tell_object(TP,"That's not a valid move!");
    return 0;
  }
  move = endpos-startpos;

// check whether the correct colour piece is being played
  if (check_occupied(startpos)==EMPTY)
  {
    tell_object(TP, "There's no piece on square " + str[0..1] + "!");
    return 1;
  }


  if (nextmove != check_occupied(startpos)&& cheating ==0)
  {
    tell_object(TP, "It's not that colour's turn to move! It would be"
                   +" cheating to do that!");
    return 1;
  }

  result = check_legal_move(squares[startpos],startpos,move, TP);
  switch(result)
  {

  case 0:
  // move invalid   
    if (cheating==0)
    {
      tell_object(TP,"That's not a valid move! You would have to cheat"
                    +" to do that.");
      return 1;
      break;
    }
   
  case 1:
  // legal move
    send_move_message(startpos, TP, str);
    squares[endpos] = squares[startpos];
    squares[startpos] = 0;
    finalise_move(startpos, move);
    return 1;
    break;
   
  case 2:
  // capture of piece
    send_capture_message(startpos, endpos, TP, str);
    squares[endpos] = squares[startpos];
    squares[startpos] = 0;
    finalise_move(startpos, move);
    return 1;
    break;
 
   case 3:
   // en passant capture
     tell_object(TP, "You capture the " 
                    + get_piece_name(squares[lastsquare])+ " with your "
                    + get_piece_name(squares[startpos]) + " in an"
                    +" %^CYAN%^en passant%^RESET%^ move from " 
                    + str +"!");
     tell_room(ETO, TPQCN + " captures the " 
                  + get_piece_name(squares[lastsquare]) +" with " + TP->QP
                  + get_piece_name(squares[startpos]) + " in an"
                  +" %^CYAN%^en passant%^RESET%^ move from " 
                  + str +"!", TP);
    squares[endpos] = squares[startpos];
    squares[startpos]=0;
    if (move>0)
    {
      squares[endpos-8]=0;
    }
    if (move<0)
    {
      squares[endpos+8]=0;
    }
    
    finalise_move(startpos, move);
    return 1;
    break;
  case 4:
  // successful castling
    switch(move)
    {
    case 2:
      squares[startpos+move-1]=squares[startpos+move+1];
      squares[startpos+move+1]=0;
      break;
    case -2:
      squares[startpos+move+1]=squares[startpos+move-2];
      squares[startpos+move-2]=0;
      break;
    }
     tell_object(TP, "You move your " + get_piece_name(squares[startpos])
                    +" to safety by %^BOLD%^%^YELLOW%^castling%^RESET%^"
                    +" him from " + str +"!");
     tell_room(ETO, TPQCN + " moves " + TP->QP + " " 
                   +get_piece_name(squares[startpos]) +" to safety by"
                   +" %^BOLD%^%^YELLOW%^castling%^RESET%^ him "
                   +" from " + str +"!", TP);
  finalise_move(startpos, move);
  squares[startpos+move]=squares[startpos];
  squares[startpos]=0;

  return 1;
  break;

  default:
    tell_object(TP,"Error with the the chessboard. Your move did not"
                  +" resolve. Please make a bug report");
  }
}

void finalise_move(int startpos, int move)
{
  lastsquare = startpos + move;
  lastmove = move;
  if (nextmove == WHITE)
  {
    nextmove = BLACK;
  }
  else
  {
    nextmove = WHITE;
  }
// check for moves that would make castling later invalid
  switch (startpos)
  {
  case 0:
    w_rook_move_1 = 1;
    break;
  case 4:
    w_king_move = 1;
    break;
  case 7:
    w_rook_move_2 = 1;
    break;
  case 56:
    b_rook_move_1 = 1;
    break;
  case 60:
    b_king_move = 1;
    break;
  case 63:
    b_rook_move_2 = 1;
    break;
  }
  cheating = 0;
}

string get_position_name(int position)
{
  string posname;
  switch(position%8)
  {
  case 0:
    posname = "A";
    break;
  case 1:
    posname = "B";
    break;
  case 2:
    posname = "C";
    break;
  case 3:
    posname = "D";
    break;
  case 4:
    posname = "E";
    break;
  case 5:
    posname = "F";
    break;
  case 6:
    posname = "G";
    break;
  case 7:
    posname = "H";
    break;
  }
  switch(position/8)
  {
  case 0:
    posname += "1";
    break;
  case 1:
    posname += "2";
    break;
  case 2:
    posname += "3";
    break;
  case 3:
    posname += "4";
    break;
  case 4:
    posname += "5";
    break;
  case 5:
    posname += "6";
    break;
  case 6:
    posname += "7";
    break;
  case 7:
    posname += "8";
    break;
  }
  return posname;
}
int take_back(string str)
{
  if (str!="back move" && str != "back")
  {
    tell_object(TP,"Do you want to 'take back' your move?");
    return 1;
  }
  if (lastmove==0)
  {
    tell_object(TP, "There is no last move recorded. If you want to"
                   +" rearrange things, use the %^BOLD%^%^YELLOW%^<place>"
                   +"%^RESET%^ and %^BOLD%^%^YELLOW%^<clear>%^RESET%^"
                   +" commands.");
    return 1;
  }
  tell_object(TP,"You move the " + get_piece_name(squares[lastsquare])
                +" back from " + get_position_name(lastsquare) + " to "
                + get_position_name(lastsquare-lastmove));
  tell_room(ETO, TPQCN + " moves the " 
                + get_piece_name(squares[lastsquare])
                +" back from " + get_position_name(lastsquare) + " to "
                + get_position_name(lastsquare-lastmove),TP);

  squares[lastsquare-lastmove] = squares[lastsquare];
  squares[lastsquare] = lastpiece;
  if (nextmove == WHITE)
  {
    nextmove = BLACK;
  }
  else
  {
    nextmove = WHITE;
  }
  return 1;
}

string get_piece_name(int piecetype)
{
  switch(piecetype)
  {
  case B_PAWN:
    return "%^BOLD%^%^RED%^red pawn%^RESET%^";
  case B_ROOK:
    return "%^BOLD%^%^RED%^red castle%^RESET%^";
  case B_KNIGHT:
    return "%^BOLD%^%^RED%^red knight%^RESET%^";
  case B_BISHOP:
    return "%^BOLD%^%^RED%^red bishop%^RESET%^";
  case B_QUEEN:
    return "%^BOLD%^%^RED%^red queen%^RESET%^";
  case B_KING:
    return "%^BOLD%^%^RED%^red king%^RESET%^";
  case W_PAWN:
    return "%^BOLD%^%^WHITE%^white pawn%^RESET%^";
  case W_ROOK:
    return "%^BOLD%^%^WHITE%^white castle%^RESET%^";
  case W_KNIGHT:
    return "%^BOLD%^%^WHITE%^white knight%^RESET%^";
  case W_BISHOP:
    return "%^BOLD%^%^WHITE%^white bishop%^RESET%^";
  case W_QUEEN:
    return "%^BOLD%^%^WHITE%^white queen%^RESET%^";
  case W_KING:
    return "%^BOLD%^%^WHITE%^white king%^RESET%^";
  }
}


string show_square(int square)
{
  string str;
  if ((square/8)%2==0)
  {
    if (square%2==0)
    {
      str = "%^B_BLACK%^";
    }
    else
    {
      str = "%^B_WHITE%^";
    }
  }
  else
  {
    if (square%2==0)
    {
      str = "%^B_WHITE%^";
    }
    else
    {
      str = "%^B_BLACK%^";
    }
  }

  switch(squares[square])
  {
  case EMPTY:
    str += "   ";
    break;
  case B_PAWN:
    str += "%^BOLD%^%^RED%^ p %^RESET%^";
    break;
  case W_PAWN:
    str += "%^BOLD%^%^WHITE%^ p %^RESET%^";
    break;
  case B_ROOK:
    str +="%^BOLD%^%^RED%^ C %^RESET%^";
    break;
  case W_ROOK:
    str +="%^BOLD%^%^WHITE%^ C %^RESET%^";
    break;
  case B_KNIGHT:
    str +="%^BOLD%^%^RED%^ Kn%^RESET%^";
    break;
  case W_KNIGHT:
    str +="%^BOLD%^%^WHITE%^ Kn%^RESET%^";
    break;
  case B_BISHOP:
    str +="%^BOLD%^%^RED%^ B %^RESET%^";
    break;
  case W_BISHOP: 
    str +="%^BOLD%^%^WHITE%^ B %^RESET%^";
    break;
  case B_QUEEN:
    str +="%^BOLD%^%^RED%^ Q %^RESET%^";
    break;
  case W_QUEEN:
    str +="%^BOLD%^%^WHITE%^ Q %^RESET%^";
    break;
  case B_KING:
    str +="%^BOLD%^%^RED%^ Ki%^RESET%^";
    break;
  case W_KING:
    str +="%^BOLD%^%^WHITE%^ Ki%^RESET%^";
    break;   
  };
  return str;
}

string show_empty_square(int square)
{
  string str;
  if ((square/8)%2==0)
  {
    if (square%2==0)
    {
      str = "%^B_BLACK%^";
    }
    else
    {
      str = "%^B_WHITE%^";
    }
  }
  else
  {
    if (square%2==0)
    {
      str = "%^B_WHITE%^";
    }
    else
    {
      str = "%^B_BLACK%^";
    }
  }
  str +="   %^RESET%^";
  return str;
}

string show_board()
{
  int i;
  int j;
  string board;
  board= "\n%^RESET%^   A  B  C  D  E  F  G  H\n";
   for (i=7;i>=0;i--)
  {
    board +="%^RESET%^";
    switch (i)
    {
    case 0:
      board += "1 ";
      break;
    case 1:
      board += "2 ";
      break;
    case 2:
      board += "3 ";
      break;
    case 3:
      board += "4 ";
      break;
    case 4:
      board += "5 ";
      break;
    case 5:
      board += "6 ";
      break;
    case 6:
      board += "7 ";
      break;
    case 7:
      board += "8 ";
      break;
    }
    for (j=0;j<8;j++)
    {
      board += show_square(j+(i*8));
    }
    board +="\n%^RESET%^  ";
    for (j=0;j<8;j++)
    {
      board += show_empty_square(j+(i*8));
    }
    board +="\n%^RESET%^";
  }
  board += show_next_move();
  return board;
}

string show_next_move()
{
  string next_move;
  next_move= "  %^ORANGE%^Next move%^BOLD%^%^BLACK%^:";
  if (nextmove==WHITE)
  {
    next_move+="%^BOLD%^%^WHITE%^\twhite%^RESET%^";
  }
  else
  {
    next_move+="%^BOLD%^%^RED%^\tred%^RESET%^";
  }
  return next_move;

}

int upset_board(string str)
{
  int i;
  int rand;
  if (str != "board" && str!="chessboard" && str != "chess board" 
   && str != "chess set")
  {
     tell_object(TP, "Upset what?");
     return 1;
  }
  for (i=0;i<64;i++)
  {
    if (squares[i]>0)
    {
      rand = random(10);
      if (rand>5)
      {
        rand +=random(10);
      }
      if (random(10)>5)
      {
        rand =random(64);
      }
      if (random(10)<5)
      {
        rand = rand*-1; 
      }
      if (i+rand>0 && i+rand <64)
      {
        squares[i+rand] = squares[i];
      }
      squares[i] = 0;
    }
  }
  tell_object(TP, "In a fit of %^BOLD%^%^RED%^temper%^RESET%^, you knock"
                 +" the board over, sending the pieces"
                 +" %^BOLD%^%^CYAN%^flying%^RESET%^ all over the place!");
  tell_room(TO, "In a fit of %^BOLD%^%^RED%^temper%^RESET%^, " + TPQCN 
               +" knocks the board over, sending the pieces%^BOLD%^"
               +" %^CYAN%^flying%^RESET%^ all over the place!,TP");
  return 1;
}

int clear_board(string str)
{
  int i;
  if (str == "board" || str == "chessboard"||str == "chess board" 
     || str == "chess set" )
  {
    tell_object(TP, "You begin clearing the pieces off the board.");
    tell_room(ETO, TPQCN + " begins clearing the pieces off the board."
               , TP);
    call_out("clear_board2", 4, TP);
    return 1;
  }
  i = calculate_position(str[0..1]);
  if (i>64)
  {
    tell_object(TP, "Clear what?");
    return 1;
  }
  if (squares[i] == EMPTY)
  {
    tell_object(TP, "There's no piece on square " + str);
  }
  tell_object(TP, "You remove the " + get_piece_name(squares[i]) 
                 +" from square " + str);
  tell_room(ETO, TPQCN + " removes the " + get_piece_name(squares[i]) 
                 +" from square " + str, TP);
  squares[i]=0;
  return 1;
}

void clear_board2(object ob)
{
  int i;
  if (!objectp(ob)){return;}
  for (i=0;i<64;i++)
  {
    squares[i] = EMPTY;
  }
  tell_object(ob, "You finish clearing the pieces off of the board");
  tell_room(ETO,TPQCN + " finishes clearing the pieces off of the board"
      , ob);
}