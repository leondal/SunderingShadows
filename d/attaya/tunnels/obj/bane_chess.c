//Coded by Lujke
#include <std.h>
inherit "/d/common/obj/misc/chessboard";

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


string show_square(int square);
string get_piece_name(int piecetype);

void create() 
{
  ::create();
  set_obvious_short("%^BOLD%^%^GREEN%^A %^BOLD%^%^BLACK%^grim"
                   +"%^GREEN%^ looking c%^BOLD%^%^BLACK%^h%^GREEN%^e"
                   +"%^BOLD%^%^BLACK%^s%^GREEN%^s board");
  set_short("%^BOLD%^%^BLACK%^Chessboard of the Bl%^BOLD%^%^GREEN%^a"
           +"%^BOLD%^%^BLACK%^ck H%^BOLD%^%^GREEN%^a%^BOLD%^%^BLACK%^nd");
  set_long("%^BOLD%^%^BLACK%^A traveller's c%^GREEN%^h%^BOLD%^%^BLACK%^e"
          +"%^BOLD%^%^GREEN%^s%^BOLD%^%^BLACK%^s %^GREEN%^b%^BOLD%^"
          +"%^BLACK%^o%^GREEN%^a%^BOLD%^%^BLACK%^r%^GREEN%^d%^BOLD%^"
          +"%^BLACK%^, decorated with %^BOLD%^%^GREEN%^g%^BOLD%^"
          +"%^BLACK%^ree%^GREEN%^n t%^BOLD%^%^BLACK%^ri%^GREEN%^m"
          +" %^BOLD%^%^BLACK%^. It is designed to fold into a box to make"
          +" it easier to carry. %^BOLD%^%^BLACK%^%^The centre"
          +" of the board is \ndecorated %^BOLD%^%^BLACK%^with a black"
          +" fist clutching r%^BOLD%^%^GREEN%^a%^BOLD%^%^BLACK%^ys of"
          +" %^RESET%^%^GREEN%^gr%^BOLD%^%^GREEN%^ee%^RESET%^%^GREEN%^n" 
          +" l%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^ght%^BOLD%^%^BLACK%^."
          +" The pieces are intricately fashioned from stones of"
          +" %^RESET%^%^RED%^bl%^BOLD%^%^RED%^oo%^RESET%^%^RED%^d red"
          +" r%^BOLD%^%^RED%^u%^RESET%^%^RED%^by%^BOLD%^%^BLACK%^ and"
          +" %^RESET%^%^GREEN%^a%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^gir"
          +"%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^ne%^BOLD%^%^BLACK%^. They"
          +" stand ready to obey every order, and to stamp their lord's"
          +" d%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^min%^RESET%^%^RED%^a"
          +"%^BOLD%^%^BLACK%^nce on the game.");
   set_id( ({"board", "chessboard", "chess board", "game", "table", 
                            "helm board", "chess table", "game board"}) );
   set_lore("The game of chess is considered significant within the"
           +" faith of Bane, as it teaches the use of strategy and"
           +" discipline to acheive dominance. Some say that the game"
           +" was invented by Bane to teach just those virtues.\nThe"
           +" Chess sets of the Black Hand were crafted and enchanted"
           +" in appeasement of Bane and are played in fear of His wrath."
           +" Loss of a game can lead to loss of favour in His eyes, or"
           +" other terrible punishments.");
   set_weight(2);
   set_value(20000);
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
      str = "%^B_GREEN%^";
    }
  }
  else
  {
    if (square%2==0)
    {
      str = "%^B_GREEN%^";
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
    str += "%^BOLD%^%^GREEN%^ p %^RESET%^";
    break;
  case B_ROOK:
    str +="%^BOLD%^%^RED%^ C %^RESET%^";
    break;
  case W_ROOK:
    str +="%^BOLD%^%^GREEN%^ C %^RESET%^";
    break;
  case B_KNIGHT:
    str +="%^BOLD%^%^RED%^ Kn%^RESET%^";
    break;
  case W_KNIGHT:
    str +="%^BOLD%^%^GREEN%^ Kn%^RESET%^";
    break;
  case B_BISHOP:
    str +="%^BOLD%^%^RED%^ B %^RESET%^";
    break;
  case W_BISHOP: 
    str +="%^BOLD%^%^GREEN%^ B %^RESET%^";
    break;
  case B_QUEEN:
    str +="%^BOLD%^%^RED%^ Q %^RESET%^";
    break;
  case W_QUEEN:
    str +="%^BOLD%^%^GREEN%^ Q %^RESET%^";
    break;
  case B_KING:
    str +="%^BOLD%^%^RED%^ Ki%^RESET%^";
    break;
  case W_KING:
    str +="%^BOLD%^%^GREEN%^ Ki%^RESET%^";
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
      str = "%^B_GREEN%^";
    }
  }
  else
  {
    if (square%2==0)
    {
      str = "%^B_GREEN%^";
    }
    else
    {
      str = "%^B_BLACK%^";
    }
  }
  str +="   ";
  return str;
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
    return "%^BOLD%^%^GREEN%^green pawn%^RESET%^";
  case W_ROOK:
    return "%^BOLD%^%^GREEN%^green castle%^RESET%^";
  case W_KNIGHT:
    return "%^BOLD%^%^GREEN%^green knight%^RESET%^";
  case W_BISHOP:
    return "%^BOLD%^%^GREEN%^green bishop%^RESET%^";
  case W_QUEEN:
    return "%^BOLD%^%^GREEN%^green queen%^RESET%^";
  case W_KING:
    return "%^BOLD%^%^GREEN%^green king%^RESET%^";
  }
}

string show_next_move()
{
  string next_move;
  next_move= "  %^ORANGE%^Next move%^BOLD%^%^BLACK%^:";
  if (nextmove==WHITE)
  {
    next_move+="%^BOLD%^%^GREEN%^\tgreen%^RESET%^";
  }
  else
  {
    next_move+="%^BOLD%^%^RED%^\tred%^RESET%^";
  }
  return next_move;

}
void send_capture_message(int startpos, int endpos, object ob, string str)
{
  if ((string)ob->query_diety() != "bane" )
  {
    ::send_capture_message(startpos, endpos, ob, str);
    return;
  }
  switch(((squares[startpos]+1)/2)*2)
  {
  case W_PAWN:
    tell_object(TP, "%^BOLD%^%^BLACK%^You sternly order your pawn forward"
                   +" into battle. With the force of f%^BOLD%^"
                   +"%^GREEN%^e%^BOLD%^%^BLACK%^ar to compel it, the"
                   +" hapless %^RESET%^%^GREEN%^slave%^BOLD%^%^BLACK%^"
                   +" charges from "+ str +" to bring and end to the"
                   +" existence of your opponent's "
                   + get_piece_name(squares[endpos])
                   +" %^BOLD%^%^BLACK%^in this life!");
    tell_room(ETO,"%^BOLD%^%^BLACK%^" + TPQCN+"%^BOLD%^%^BLACK%^ sternly"
                 +" orders " + TPQP + " pawn forward into battle. With"
                 +" the force of f%^BOLD%^%^GREEN%^e%^BOLD%^%^BLACK%^ar"
                 +" to compel it, the hapless %^RESET%^%^GREEN%^slave"
                 +" %^BOLD%^%^BLACK%^charges from "+ str +" and brings an"
                 +" end to the " + get_piece_name(squares[endpos])
                 +"'s %^BOLD%^%^BLACK%^existence in this life!", TP);  
    break;
  case W_ROOK:
    tell_object(TP, "Your " + get_piece_name(squares[startpos]) 
                  + " moves from " + str + " and takes control of the"
                  +" area, taking your opponent's " 
                  + get_piece_name (squares[endpos])+ " prisoner, and"
                  +" enslaving it to %^BOLD%^%^BLACK%^B%^GREEN%^a%^BOLD%^"
                  +"%^BLACK%^ne%^RESET%^.");
    tell_room(ETO, TPQCN + "'s " + get_piece_name(squares[startpos]) 
                  + " moves from " + str + " and takes control of the"
                  +" area, taking the " + get_piece_name (squares[endpos])
                  + " prisoner, and enslaving it to %^BOLD%^%^BLACK%^B"
                  +"%^GREEN%^a%^BOLD%^%^BLACK%^ne%^RESET%^.", TP);  
    break;
  case W_KNIGHT:
    tell_object(TP, "Your " + get_piece_name(squares[startpos]) 
                  + " gallops accross the field of battle from " + str 
                  + ", jumping over every obstacle in its way and charges"
                  + " down your opponent's " 
                  + get_piece_name (squares[endpos]) + ", crushing it to"
                  +" the ground!");
    tell_room(ETO, TPQCN + "'s " + get_piece_name(squares[startpos]) 
                  + " gallops accross the field of battle from " + str 
                  + ", jumping over every obstacle in its way and charges"
                  + " down the " + get_piece_name(squares[endpos]) 
                  + ", crushing it to the ground!", TP); 
    break;
  case W_BISHOP:
    tell_object(TP, "Your " + get_piece_name(squares[startpos]) 
                  + " steps forth from " + str + " and brings the full"
                  +" weight of %^BOLD%^%^BLACK%^B%^GREEN%^a%^BOLD%^"
                  +"%^BLACK%^ne's%^RESET%^ power and dominion to bear on"
                  +" your opponent's hapless " 
                  + get_piece_name (squares[endpos]) +", which is utterly"
                  +" destroyed.");
    tell_room(ETO, TPQCN + "'s " + get_piece_name(squares[startpos]) 
                  + " steps forth from " + str + " and brings the full"
                  +" weight of %^BOLD%^%^BLACK%^B%^GREEN%^a%^BOLD%^"
                  +"%^BLACK%^ne's%^RESET%^ power and dominion to bear on"
                  +" the hapless " + get_piece_name (squares[endpos]) 
                  +", which is utterly destroyed.", TP); 
    break;
  case W_QUEEN:
    tell_object(TP, "The " + get_piece_name(squares[startpos]) 
                  + " sweeps with tyrannical grace from " + str + " and"
                  + " brings an end to the futile resistance of the " 
                  + get_piece_name (squares[endpos]) + ".");
    tell_room(ETO,  TPQCN + " sweeps the " 
                  + get_piece_name(squares[startpos]) 
                  + " forward with tyrannical grace from " + str + " and"
                  + " brings an end to the futile resistance of the " 
                  + get_piece_name (squares[endpos]) + ".", TP); 

    break;
  case W_KING:
    tell_object(TP, "The " + get_piece_name(squares[startpos]) 
                  + " exerts his power to destroy  "
                  + get_piece_name (squares[endpos]) +" in a decisive"
                  +" movement from " + str + ".");
    tell_room(ETO, TPQCN + " exerts the power of the  " 
                  + get_piece_name(squares[startpos]) 
                  + " to bring an end to "
                  + get_piece_name (squares[endpos]) + " in a decisive"
                  +" movement from " + str + ".",TP);
    break;
  }


}
