#include <std.h>
#include <daemons.h>
#define VOID "/d/shadowgate/void"
inherit "/std/bag_logic";

string * cards;

string deck_id;

string display(object viewer);
string query_deck_id();
string long_desc();
void set_deck_id(string id);


void create(){
    ::create();
    set_name("Card Table");
      set_short("%^GREEN%^Card Table%^RESET%^");
    set_id(({"table","card table", "pokiir table"}));
    set_long( (:TO, "long_desc" :) );
    set_value(5);
    set_weight(2000);
}

void init(){
  ::init();
  add_action("put", "put");
  add_action("deal", "deal");
  add_action("take", "take");
  add_action("flip", "flip");
  add_action("view_table", "view");
}

void clear_table(){
  int i;
  object * inv;
  inv = all_inventory(TO);
  if (sizeof(inv)>0){
    for (i=0;i<sizeof(inv);i++){
      inv[i]->move(VOID);
    }
  }
}

int view_table(string str){
  if (str != "table"){
    return 0;
  }
  tell_object(TP, display(TP));
  return 1;
}

string long_desc(){
  string result;
  result = "%^BOLD%^%^GREEN%^A sturdy pokiir table, with a green beize"
          +" covering and five spaces marked for the community cards."
          +"%^RESET%^\n\n";
//  result += display();
  result += "\nThe following commands are available:\n"
          +"%^BOLD%^%^YELLOW%^View table%^RESET%^:  Shows the current"
          +" players, the bets they have laid and the  community cards on"
          +" the table.\n"
          +"%^BOLD%^%^YELLOW%^help pokiir:%^RESET%^  Shows the rules for"
          +" playing pokiir\n"
          +"%^BOLD%^%^CYAN%^Note: some of these commands will only"
          +" function properly if the card dealer is in the room."
          +"%^RESET%^\n";

  return result;
}

string query_deck_id(){
  return deck_id;
}

void set_deck_id(string id){
  deck_id = id;
}

int flip(string str){
  object * cards;
  int cardnum;
  cards = all_inventory(TO);
  if (sscanf(str, "card %d", cardnum)!=1){
    tell_object(TP, "Try '%^BOLD%^%^YELLOW%^flip card <number>%^RESET%^'");
    return 1;
  }
  if (sizeof(cards)<1){
    tell_object(TP, "There aren't any cards on the table");
    return 1;
  }
  if(cardnum>sizeof(cards)){
    tell_object(TP, "There are only " + sizeof(cards) + " cards on the"
                   +" table");
    return 1;
  }
  if (cardnum<1){
     tell_object(TP, "Very surreal. Now try '%^BOLD%^%^YELLOW%^flip card"
                    +" <number>%^RESET%^', where <number> is greater than"
                    +" 0");
     return 1;
  }
  if (cards[cardnum-1]->query_face_up()==0){
    cards[cardnum-1]->set_face_up(1);    
  } else {
    cards[cardnum-1]->set_face_up(0);    
  }

  tell_object(TP, "You flip over card " + cardnum + " on the table.");
  tell_room(ETO, TPQCN + " flips over card " + cardnum + " on the table.",
                                                                       TP);
  return 1;
}

string query_cap_name(){
  return "the card table";
}

string display(object viewer){
  mapping bets, names, max_bets;
  object * hand, * inv, player, dealer, ob, * players;
  string result, * pic, player_name;
  int i, j, len;
  hand = ({});
  if (!objectp(viewer)){
    return "ERROR - problem with viewer. Please tell a WIZ";
  }
  names = viewer->getRelationships();
  inv = all_inventory(TO);
  if (sizeof(inv)<1){
    return "%^RESET%^"+
 "------------+ ------------+ ------------+ ------------+ ------------+\n"
+"|           | |           | |           | |           | |           |\n"
+"|           | |           | |           | |           | |           |\n"
+"|           | |           | |           | |           | |           |\n"
+"|           | |           | |           | |           | |           |\n"
+"|           | |           | |           | |           | |           |\n"
+"|           | |           | |           | |           | |           |\n"
+"|           | |           | |           | |           | |           |\n"
+"|           | |           | |           | |           | |           |\n"
+"|           | |           | |           | |           | |           |\n"
+"|           | |           | |           | |           | |           |\n"
+"|           | |           | |           | |           | |           |\n"
+"|           | |           | |           | |           | |           |\n"
+"|           | |           | |           | |           | |           |\n"
+"|           | |           | |           | |           | |           |\n"
+"|___________| |___________| |___________| |___________| |___________|";
  }
  result = "%^RESET%^";
  result += inv[0]->get_hand_pic();
  dealer = present("dealer", ETO);
  if (!objectp(dealer)){
    result += "\nNo dealer is present at the moment";
    return result;
  }
  bets = dealer->query_bets();
  max_bets = dealer->query_max_bets();
  players = keys(bets);
  result += "\n%^BOLD%^%^YELLOW%^Player         |   Current Bet  | Chips on table %^RESET%^\n";
  for (i=0;i<sizeof(players);i++){
    player = players[i];
    player_name = player->query_name();
//    tell_room(ETO, "Player " + i + "'s name is " + player_name);
    if (interactive(player)){
      if (stringp(names[player_name])){
        player_name = names[player_name];
      } else {
        player_name = player->getWholeDescriptivePhrase();
      }
    }
//    tell_room(ETO, "Player " + i + "'s name is now" + player_name);
    len = strlen(player_name);
    if (interact("$", player_name)){
      len-=6;
    }    if (strlen(player_name)>15){
      player_name = player_name[0..14];
    } 
    result += player_name;
    if (len<15){
      for (j=0;j<(15-len);j++){
        result += " ";
      }
    }
    result += "%^BOLD%^%^YELLOW%^|%^RESET%^   " + bets[player];
    result += "     ";
    if (bets[player]<10){ result += " ";}
    if (bets[player]<100){ result += " ";}
    if (bets[player]<1000){ result += " ";}
    if (bets[player]<10000){ result += " ";}
    if (bets[player]<100000){ result += " ";}
    if (bets[player]<1000000){ result += " ";}
    if (bets[player]<10000000){ result += " ";}
    result += "%^BOLD%^%^YELLOW%^|%^RESET%^ "+ (max_bets[player]-bets[player]) + "\n";
  }
  result += "%^BOLD%^%^RED%^Current bet limit:%^RESET%^ %^BOLD%^%^CYAN%^";
  if (dealer->query_bet_limit()==0){
    result += "No limit%^RESET%^";
  } else {
    result += ""+ dealer->query_bet_limit()+"%^RESET%^";
  }
  return result;
}

int deal(string str){
  string where;
  if (sscanf(str, "to %s", where)==2){
    if (TO->id(where)){
      if (objectp(ETO) && present("dealer", ETO)){
        tell_object(TP, "The dealer won't let you mess with the table");
        return 1;
      }
    }
  }
  return 0;
}

int put(string str){
  string what, where;
  if (sscanf(str, "%s in %s", what, where)==2){
    if (TO->id(where)){
      if (objectp(ETO) && present("dealer", ETO)){
        tell_object(TP, "The dealer won't let you mess with the table");
        return 1;
      }
    }
  }
  return 0;
}
int take(string str){
  string what, where;
  if (sscanf(str, "%s from %s", what, where)==2){
    if (TO->id(where)){
      if (objectp(ETO) && present("dealer", ETO)){
        tell_object(TP, "The dealer won't let you mess with the table");
        return 1;
      }
    }
  }
  return 0;
}