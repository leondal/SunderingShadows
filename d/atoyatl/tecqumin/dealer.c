//dealer.c - a card dealer                                
// Coded by Lujke 29/12/06
#include <std.h>
#include "../tecqumin.h"
#define DECK "/d/shadow/obj/misc/deckofcards"
inherit MOB + "QNPC.c";

int add_player(object player);
string calculate_winner();
void catch_tell(string str);
int check_flush(string * hand);
int check_straight(string * hand);
void clear_decks();
void collect_cards();
int compare_kickers(string * hand1, string * hand2);
int deal();
string describe_hand(string * hand);
void get_fresh_deck();
string * get_highest_hand(object player);
mapping how_many_of_a_kind(string * hand);
int * order_values(int * vals);
void put_deck_away();
string query_card_name(int val);
string query_card_suit(string card);
int query_card_value(string card);
string query_deck_id();
int query_hand_value(string * hand);
mapping query_hands();
int query_high_card(string * hand, int num);
string query_lowest_card(string * hand);
mapping query_most_of_a_kind(string * hand);
mapping query_second_most_of_a_kind(string * hand);
void set_responses();
void start_game();

object * players;
mapping hands;
mapping bets;
string deck_id;

void create(){
   object deck;
   ::create();
   players = ({});
   hands = ([]);
   set_name("Dealer");
   set_id( ({"dealer","card dealer"}) );
   set_short("A card dealer");
   set_long("A dealer of cards");
   set_gender("male");
   set_race("human");
   set_body_type("human");
   set_hd(20,5);
   set_alignment(5);
   set_max_hp(200);
   set_hp(query_max_hp());
   set_overall_ac(-10);
   set_class("fighter");
   set_mlevel("fighter",25);
   set_level(25);
   set_stats("wisdom",13);
   set_stats("strength",12);
   set_stats("constitution",10);
   set_stats("intelligence",15);
   set_stats("charisma",17);
   set_stats("dexterity",17);
   set_exp(60);
   set("aggressive",0);
   set_responses();
   deck = new(DECK);
   deck->move(TO);
   deck_id = deck->query_id();
}

int add_player(object player){
  if (!objectp(player)){return 0;}
  if (player->query_invis()){
    force_me(" say Ahh, no way fella. I ain't having no-one I can't see"
            +" sitting in on my game");
    return 0;
  }
  hands += ([player->QCN : ({}) ]);
  players += ({player});
  force_me("say alright, " + player->QCN + ". Draw up a seat and let's get"
          +" on with the game.");
  return 1;
}

string calculate_winner(){
  mapping highhands;
  object * winners; 
  string result;
  int * vals, i, j, * order;
  highhands = ([]);
  vals = allocate(10);
  order = allocate(10);
  winners = ({});
  for (i=0;i<sizeof(players);i++){
    highhands+= ([ players[i] : get_highest_hand(players[i]) ]);
    vals[i] = query_hand_value(highhands[players[i]]);
    force_me("say The value of " + players[i]->QCN + "'s best hand is: "
            + vals[i]);
  }
  order[0] = 0;
  for (i=1;i<sizeof(players);i++){
    for (j=i-1;j>=0;j--){
      if (vals[i]>vals[order[j]]){ 
        order[j+1] = order[j];
        order[j] = i;
      } else{
        order[j+1] = i;
        break;
      }
    }
  }
  force_me("say The order of players' hand values is:");
  for (i=0;i<sizeof(order);i++){
   force_me("say " + players[order[i]]->QCN);
  }
  winners += ({players[order[0]]});
  for(i=1;i<sizeof(order);i++){
    if (vals[order[i]] == vals[order[0]]){
      winners += ({players[order[i]]});
    }else{
      break;
    }    
  }
  if (sizeof(winners)<2){
    return winners[0]->QCN + " wins with " 
         + describe_hand(highhands[winners[0]]);
  }else{
    result = "";
    for(i=0;i<sizeof(winners)-1;i++){
      if (i<sizeof(winners)-2){
        result += winners[i]->QCN + ", ";
      }else{
        result += winners[i]->QCN + " and ";
      }
    }
    result += winners[i]->QCN + " draw, with ";
    result+= describe_hand(highhands[winners[0]]);
    return result;
  }

  return "The order is: " + order[0] + ", " + order[1] + ", " + order[2] + ", " + order[3] + ", " + order[4];
}

void catch_tell(string str){
  string name;
  object dropper, card;
  if (!objectp(ETO)){return;}
  if (interact("drops A card.", str)){
    force_me("get card");
    card = present("card", TO);
    force_me("return card");
    if (sscanf(str, "%s drops A card.", name)==1){
      dropper = present(name, ETO);
      if (objectp(dropper)){
        force_me("emoteat dropper glares at $N");
        force_me("say We're trying to have a card game here, don't be"
                +" making a mess!");
      }
    }
  }
}

int check_flush(string * hand){
  int i;
  string suit;
  suit = query_card_suit(hand[0]);
  for (i=1;i<5;i++){
    if (query_card_suit(hand[i]) != suit){
      return -1;
    }
  }
  return 1;
}

int check_straight(string * hand){
  string * straight, * temphand, card;
  int i, val1, val2;
  if (sizeof(hand)<1){
    tell_room(ETO, "The hand is empty");
    return 0;
  }
//  tell_room(ETO, "checking for a straight in this hand:");
//  for (i=0;i<sizeof(hand);i++){
//    tell_room(ETO, hand[i]);
//  }
  straight = ({});
  temphand = ({});
  for (i=0;i<(sizeof(hand));i++){
    temphand += ({hand[i]});
  }
  for (i=0;i<5;i++){
     card = query_lowest_card(temphand);
    straight += ({card});
    temphand = temphand - ({card});
    if (i==0){
      continue;
    }
    val1=query_card_value(straight[i]); 
    val2 = query_card_value(straight[i-1]);
    if (val1-1 != val2 && 
      !(val1== 14 && val2 != 14 && query_card_value(straight[0])==2)) {
      return -1;
    } 
  }
  return 1;
}

void clear_decks(){
  
}

void collect_cards(){
  int i, j;
  object player, card, * inv;
  if (sizeof(players)<1||!objectp(ETO)){
    return;
  }
  force_me("emote collects in the cards from all the players");
  for(i=0;i<sizeof(players);i++){
    player = players[i];
    if (!objectp(player)||!present(player, ETO)){
      continue;
    }
    inv = all_inventory(player);
    for (j=0;j<sizeof(inv);j++){
      card = inv[j];
      if (card->id("card") && (string)card->get_deck_id() == deck_id){
        card->remove();
      }
    }
  }  
}

int compare_kickers(string * hand1, string * hand2){
  int * vals1, * vals2, i, result;
  vals1 = ({});
  vals2 = ({});
  for (i=0;i<sizeof(hand1);i++){
    vals1 += query_card_value(hand1[i]);
  }
  for (i=0;i<sizeof(hand2);i++){
    vals1 += query_card_value(hand2[i]);
  }
  
}


int deal(){
  int i, j, k;
  string players, player, card_name, player_name;
  object absentee, deck, card, dealee;
  mapping newhands;
  if (!objectp(ETO)){return 0;}
  get_fresh_deck();
  force_me("shuffle");
  players = keys(hands);
  for(i=0;i<sizeof(players);i++){
    hands[players[i]] = ({});
  }
  for (i=0;i<2;i++){
    for(j=0;j<sizeof(hands);j++){
      player = players[j];
      if (!present(player, ETO)){
        absentee = find_player(player);
        if (objectp(absentee)){
          force_me("say Looks like " + absentee->QCN + " has wandered off."
                  +" Guess I'll just deal " + absentee->QO + " out."
                  +" Everyone put down your cards and let me know when to" 
                  +" start again");

        } else{
          force_me("say hmm, seems like someone's wandered off. I guess"
                  +" I'll just deal them out, but we'll need to start over."
                  +" Everyone put your cards on the table and I'll break"
                  +" out a fresh deck.");
        }
        newhands = ([]);
        for (k=0;k<sizeof(players);k++){
          if (present(players[k], ETO)){
            newhands += ([ players[k]: ({}) ]);   
          }
        }
        hands = newhands;
        return -1;
      }
      dealee = present(player, ETO);
      force_me("deal to " + dealee->QCN);
      card = present("card", dealee);
      if (objectp(card)){
        hands[player] += ({card->query_card_name()});
      }
    }
  }
  for (i=0;i<5;i++){
    force_me("deal to dealer");
  }
  return 1;
}

string describe_hand(string * hand){
  string result, card, most_name, second_most_name;
  int val, most, second_most;
  val = query_hand_value(hand);
  card = query_card_name(query_high_card(hand,1));
  most = keys(query_most_of_a_kind(hand))[0];
  second_most = keys(query_second_most_of_a_kind(hand))[0];
  most_name = query_card_name(most);
  second_most_name = query_card_name(second_most);
  if (most_name == "Lady"){ most_name = "Ladie";}
  if (second_most_name == "Lady"){ second_most_name = "Ladie";}
  if (val<100){
    result = "the high card - " + card;
    return result;
  }
  if (val<300){
    result = "a pair of " + most_name + "s";
    return result;
  }
  if (val<1500){
    result = "two pair - " + most_name + "s and " + second_most_name + "s";
    return result;
  }
  if (val<1600){
    result = "three of a kind - " + most_name + "s";
    return result;
  }
  if (val<1700){
    result = "a straight";
    return result;
  }
  if (val<1900){
    result = "a flush";
    return result;
  }
  if (val<3100){
    result = "a full house - " + most_name + "s over " + second_most_name 
            + "s";
    return result;
  } 
  if (val<3300){
    result = "four of a kind - " + most_name + "s";
    return result;
  }
  if(val>3300){
    if (card=="Rogue"){
      result = "a Royal flush";
    }else{
      result = "a straight flush";
    } 
    return result;
  }

}

void get_fresh_deck(){
  object deck;
  while(deck = present("deck", TO) && objectp(deck)){
    deck->remove();
  }
  deck =  new(DECK);
  deck->move(TO);
  deck_id = deck->query_deck_id();
}

string * get_highest_hand(object player){
  string * poss_cards, * hand, *final_hand, junk;
  int i, j, k, l, * cards, val, high_val, kick1, kick2;
  object * inv, ob;
  if (!objectp(player)){ return "no player here by that name";}
  inv = all_inventory(TO);
  poss_cards = ({});
  for (i=0;i<2;i++){
    poss_cards += ({hands[player->QCN][i]});
  }
  for (i=0;i<sizeof(inv);i++){
    ob = inv[i];
    if (ob->id(deck_id)){
      poss_cards += ({ob->query_card_name()});
    }
  }
  
  if (sizeof(poss_cards)>7){
    tell_room(ETO, "Warning: There were too many cards around the"
            +" place");

  }
  if (sizeof(poss_cards)<7){
    tell_room(ETO, "Warning: There were not enough cards around the"
            +" place");

  }
  tell_room(ETO, "Getting highest hand from this combination of cards:");
  for (i=0;i<sizeof(poss_cards);i++){
    tell_room(ETO, poss_cards[i]);
  }
  high_val =0;
  final_hand = ({"No cards at all"});
  for(i=0;i<sizeof(poss_cards)-1;i++){
    for(j=i+1;j<sizeof(poss_cards);j++){
      hand = ({});
      for(k=0;k<sizeof(poss_cards);k++){
        if (k!=i&&k!=j){
          hand += ({poss_cards[k]});
        }
      }
/*      junk = "";
      for(k=0;k<sizeof(hand);k++){
        junk+= hand[k] + ";";
      }
      tell_room(ETO, junk);
*/
      val = query_hand_value(hand);

      if (val>high_val){
        high_val = val;
        final_hand = hand;
      }
    }
  }
  force_me("say the best scoring hand from these cards is:");
  junk = "%^BOLD%^%^CYAN%^";
  for(i=0;i<5;i++){
    junk+= final_hand[i]+";";
  }
  tell_room(ETO, junk);
  return final_hand;
}

mapping how_many_of_a_kind(string * hand){
  int i, value, * vals, count;
  mapping map;
  count = 0;
  map = ([]);
  value = query_card_value(hand[0]);
  map[value] = 1;
  for (i=1;i<5;i++){
    value = query_card_value(hand[i]);
    vals = keys(map);
    if (sizeof(vals)>0 && member_array(value, vals)!= -1){
      map[value] = map[value]+1;
    }else{
      map += ([value:1]);
    }
  }
  return map;
}

int * order_values(int * vals){
  int i, j,* temp_vals;
  temp_vals = allocate(sizeof(vals));
  temp_vals[0] = vals[0];
  for (i=1;i<sizeof(vals);i++){
    for(j=i-1;j>=0;j--){
      if vals[i]>temp_vals[j]{
        temp_vals[i] = temp_vals[j];
        temp_vals[j] = vals[i];
      } else{
        temp_vals[i] = vals[i];
        break;
      }
    }
    return temp_vals;
  }
}

void put_deck_away(){
  object deck;
  deck = present("deck", TO);
  if (objectp(deck)){
    force_me("emote puts away a spare deck of cards");
    deck->remove();
  }
}

string query_card_name(int val){
  switch(val){
    case 2:
      return "two";
    case 3:
      return "three";
    case 4:
      return "four";
    case 5:
      return "five";
    case 6: 
      return "six";
    case 7:
      return "seven";
    case 8:
      return "eight";
    case 9:
      return "nine";
    case 10:
      return "ten";
    case 11:
      return "Hunter";
    case 12:
      return "Damsel";
    case 13:
      return "Lord";
    case 14:
      return "Rogue";
    default:
      return "Invalid card";
  }
}

string query_card_suit(string card){
  string suit, value;
  sscanf(card, "%s of %s", value, suit);
  return suit;
}

int query_card_value(string card){
   string val, suit;
   sscanf(card, "%s of %s", val, suit);
   switch(val){
   case "Rogue":
     return 14;
   case "Two":
     return 2;
   case "Three":
     return 3;
   case "Four":
     return 4;
   case "Five":
     return 5;
   case "Six":
     return 6;
   case "Seven":
     return 7;
   case "Eight":
     return 8;
   case "Nine":
     return 9;
   case "Ten":
     return 10;
   case "Hunter":
     return 11;
   case "Damsel":
     return 12;
   case "Lord":
     return 13;
   }
}

string query_deck_id(){
  return deck_id;
}

int query_hand_value(string * hand){//arbitrary values for hand ranking
  int val, high_card, most, second, most_keys, second_keys;
  mapping most_of_a_kind, second_most;
  val = 0;
  high_card = query_high_card(hand, 1);
  if (check_straight(hand)==1){
    val += 1600;
    val += high_card;
  }
  if (check_flush(hand)==1){
    val += 1700;
    val += high_card;
  }
  if (val > 0){
    return val;
  }
  most_of_a_kind = query_most_of_a_kind(hand);
  second_most = query_second_most_of_a_kind(hand);
  most = values(most_of_a_kind)[0];
  most_keys = keys(most_of_a_kind)[0];
  second = values(second_most)[0];
  second_keys = keys(second_most)[0];
  if (most == 4){
    val += 3100;
    val += most_keys;
    return val;
  } 
  if (most ==3){
    if(second ==2){
      val += 1600;
      val += (most_keys*100) + second_keys;
    }else{
      val += 1500;
      val += most_keys;
    }
    return val;
  }
  if (most ==2){
    if(second ==2){
      if (most_keys>second_keys){
        val += (most_keys*100) + second_keys;
      } else {
        val += (second_keys*100) + most_keys;
      }
    }else{
      val += 100;
      val += most_keys;
    }
    return val;
  }
  return high_card;
}

mapping query_hands(){
  return hands;
}

int query_high_card(string * hand, int num){//num=1st,2nd,3rd highest, etc)
  int * highs, i, j, value;
  highs = allocate(5);
  highs[0] = query_card_value(hand[0]);
  for (i=1;i<5;i++){
    value = query_card_value(hand[i]);
    for (j=i;j>0;j--){
      if (value < highs[j-1]){
        highs[j] = highs[j-1];
        highs[j-1] = value;
      } else{ 
        highs[j] = value;
        break;
      }
    }
  }    
  return highs[5 - num];
}

string query_lowest_card(string * hand){
  int i, val;
  string lowcard;
  if (sizeof(hand)<1){return "bleh, no cards in that hand";}
  val = 16;
  for (i=0;i<sizeof(hand);i++){
    if (query_card_value(hand[i])<val){
      lowcard = hand[i];
      val = query_card_value(lowcard);
    }
  }
  return lowcard;
}

mapping query_most_of_a_kind(string * hand){
  int i, * nums, hn, * ks;
  mapping map, high_num;
  map = how_many_of_a_kind(hand);
  nums = values(map);
  ks = keys(map);
  hn = nums[0];
  high_num = ([ks[0]:nums[0]]);
  for(i=1;i<sizeof(nums);i++){
    if(nums[i]>hn){
      hn = nums[i];
      high_num = ([ks[i]:nums[i] ]);
    }
  }
  return high_num;
}

mapping query_second_most_of_a_kind(string * hand){
  int i, * nums, * ks, hn, sn;
  mapping map, high_num, second_num;
  map = how_many_of_a_kind(hand);
  nums = values(map);
  ks = keys(map);
  hn = 0;
  sn = 0;
  high_num = ([]);
  second_num = ([]);
  for(i=0;i<sizeof(nums);i++){
    if(nums[i]>hn){
      sn = hn;
      second_num = high_num;
      hn = nums[i];
      high_num = ([ks[i]:nums[i]]);
    } else{
      if (nums[i]>sn){
        second_num = ([ ks[i]:nums[i] ]);
        sn = nums[i];
      }
    }
  }
  return second_num;
}

void set_responses(){
  set_response(({"hello", "greetings", "good day", "gooday"}), 
           ({"Hello there.", }) );
}

void start_game(){
  if (sizeof(hands)>0){
    force_me("say There's a game already getting ready to go. Any folks"
            +" that want in jest ask me to deal you in.");
  }
  force_me("say Alright, let's get this game unnerway. Any folks that want"
          +" to play, jest ask me to deal you in.");
}













/* winning hands, in order 

Royal flush     
Straight flush  3300
Four of a kind  3100 + value = 3102 - 3114
Full house      1600 + three of a kind * 100 + pair = 1902 - 3013
Flush           1700
Straight        1600
Three of a kind 1500 + value = 1502 - 1514
two pair	    highest * 100 + lowest = 302 - 1413
pair twos       102
High card         0

*/
