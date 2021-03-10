//dealer.c - a card dealer                                
// Coded by Lujke 29/12/06
#include <std.h>
#define CHEATYOU ({"slipped a card from their sleeve into their hand",\
"palmed a card from their pocket into their hand",\
"swapped one of their cards with one they had hidden in their clothing",})
#define CHEATME ({"slipped a card from your sleeve into your hand",\
"palmed a card from your pocket into your hand",\
"swapped one of your cards with one you had hidden in your clothing",})
#define DECK "/d/shadow/obj/misc/deckofcards"
#define TABLE "/d/shadow/obj/misc/card_table"
#define CHIPS "/d/shadow/obj/misc/chips"
#define VOID "/d/shadowgate/void"
inherit NPC;

int add_player(object player);
advance_bet_order();
int all_bets_are_equal();
int buy_chips(string str);
string calculate_winner();
int cash_chips(string str);
void catch_tell(string str);
int check_flush(string * hand);
int check_straight(string * hand);
void clear_decks();
void cleanup_players();
//void collect_cards();
int compare_kickers(string * hand1, string * hand2);
int deal();
string describe_hand(string * hand);
void end_game();
void evict_absentee(object absentee);
void end_hand();

int get_current_bet();
void get_fresh_deck();
string * get_highhand(object pl, string * myhand);
string * get_highest_hand(object player);
void give_chips(object player, int amount);
void handout_winnings(object * winners);
int help(string str);
mapping how_many_of_a_kind(string * hand);
int join_game(string str);
int leave_game(string str);
void next_bet();
void next_round();
int * order_values(int * vals);
void put_deck_away();
int query_bet_limit();
mapping query_bets();
string query_card_name(int val);
string query_card_suit(string card);
int query_card_value(string card);
string query_deck_id();
int * query_hand_values(string * hand);
int query_hand_value(string * hand);
mapping query_hands();
int query_high_card(string * hand, int num);
string query_lowest_card(string * hand);
mapping query_max_bets();
mapping query_most_of_a_kind(string * hand);
mapping query_second_most_of_a_kind(string * hand);
object * remove_duplicates(object * arr);
void reveal_hand(object player, object card1, object card2);
int set_limit(string str);
void set_table_deck_id(); 
int setup_bets();
void setup_table();
int show_hand(string str);
void start_game(string str);
int take_bet(object player,int amount);

object * players, * waiters, * folders, * allin, * revealers, * correctors, heard_reveal, heard_reveal2;
mapping hands, bets, max_bets;
int stg, next_better, small_blind, big_blind, winnings, bet_counter, num_folders, num_allin, bet_limit, eviction;
string deck_id, cardname1, cardname2;

void create(){
   object deck, table;
   ::create();
   bets = ([]);
   max_bets = ([]);
   waiters = ({});
   revealers = ({});
   folders = ({});
   players = ({});
   allin = ({});
   correctors = ({});
   hands = ([]);
   eviction = 0;
   stg = 0;
   bet_limit = 0;
   winnings = 0;
   next_better = 0;
   bet_counter = 0;
   small_blind = 10;
   big_blind = 20;
   num_folders = 0;
   num_allin = 0;
   heard_reveal = 0;
   heard_reveal2 = 0;
   cardname1 = "";
   cardname2 = "";
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
   deck = new(DECK);
   deck->move(TO);
   deck_id = deck->query_id();
}

init(){
  ::init();
  add_action("bet","bet");
  add_action("bet", "call");
  add_action("bet", "raise");
  add_action("bet", "check");
  add_action("bet", "all");
  add_action("bet", "fold");
  add_action("help", "help");
  add_action("correct", "correct");
  add_action("force_ending", "end");
  add_action("join_game", "join");
  add_action("leave_game", "leave");
  add_action("buy_chips", "buy");
  add_action("cash_chips", "cash");
  add_action("start_game", "start");
  add_action("deal_hand", "deal");
  add_action("set_limit", "set");
  add_action("show_hand", "show");
  set_table_deck_id();
}

int add_player(object player){
  if (!objectp(player)){return 0;}
  if(member_array(player, players)!=-1){
    force_me("say You're already in the game, " + player->QCN);
    return 0;
  }
  if (stg > 0){
    force_me("say Okay, " + player->QCN + ", hang around and I'll deal you"
            +" in on the next hand");
    if (member_array(player, waiters)==-1){
      waiters += ({player});
    }
    return 0;
  }
  if (player->query_invis() && !avatarp(player)){
    force_me(" say Ahh, no way fella. I ain't having no-one I can't see"
            +" sitting in on my game");
    return 0;
  }
  hands += ([player : ({}) ]);
  players += ({player});
  force_me("say alright, " + player->QCN + ". Draw up a seat and let's get"
          +" on with the game.");
  set_table_deck_id();
  return 1;
}

void advance_bet_order(){
  int i;
  object * temp;
  temp = ({});
//  force_me("say advancing bet order. Starting order is: ");
//  for (i=0;i<sizeof(players);i++){
//    force_me("say " + players[i]->QCN);
//  }
  if (sizeof(players)<2){return;}
  for (i=1;i<sizeof(players);i++){
    temp+= ({players[i]});
  }
  temp += ({players[0]});
  for (i=0;i<sizeof(players);i++){
    players[i] = temp[i];
  }
//  force_me("say finished advancing. Final order is: ");
//  for (i=0;i<sizeof(players);i++){
//    force_me("say " + players[i]->QCN);
//  }
}

int all_bets_are_equal(){
  int i, high_bet;
  object * unequals;
  unequals = ({});
  high_bet = get_current_bet();
  for (i=0;i<sizeof(players);i++){
    if (bets[players[i]]<high_bet){
      unequals += ({players[i]});
    }
  }
  if (sizeof(unequals)>0){
    for (i=0;i<sizeof(unequals);i++){
      if (member_array(unequals[i], folders)==-1){
        if (member_array(unequals[i], allin)==-1){
          return 0;
        }
      }
    }
  }
  return 1;
}

int all_folded(){
 int i;
 if (sizeof(players)-sizeof(folders)<2){
    for(i=0;i<sizeof(players);i++){
      if (member_array(players[i], folders)==-1){
        force_me("say " + players[i]->QCN + " wins by default!");
        handout_winnings( ({players[i]}) );
        end_hand();
        return 1;
      }
    }
  }
  return 0;
}

void anticipate(){
  force_me("say That's everyone's hands shown!");
  call_out("anticipate2", 1+ random(1));
}

void anticipate2(){
  force_me("emote pauses for effect");
  stg = 5;
  call_out("next_round", 3+ random(1));
}
int bet(string str){
  int amount, bet, val, max_bet, curr_bet;
  object chips;
  string verb;
  verb = query_verb();
//  force_me("say The number of the next better is: " + next_better);
//  force_me("say This means the next better is: " 
//                             + players[next_better]->QCN);
  if (member_array(TP, players)==-1){
    return 0;
  }
  if (players[next_better] !=TP){
    tell_object(TP, "It's "+ players[next_better]->QCN + "'s turn to bet");
    return 1;
  }
  max_bet = max_bets[TP];
  bet = bets[TP];
  curr_bet = get_current_bet();
  val = 0;
  chips = present("chips", TP);
  if (objectp(chips)){
    val = chips->query_val();
  }
  if (val<1 && verb != "fold"  && bet<curr_bet){
    tell_object(TP, "You don't have any chips left. Your only option is to"
                   +" %^BOLD%^%^YELLOW%^fold%^RESET%^");
    return 1;
  }
  if ((bet == max_bet||(bet_limit>0 && bet==bet_limit)) && verb != "fold"  
                &&  verb != "check" && verb != "all"){
    tell_object(TP, "You've already bet the most you are allowed to on"
                   +" this hand. See %^BOLD%^%^YELLOW%^help betting"
                   +"%^RESET%^ for details");
    return 1;
  }
 
  switch(verb){
  case "all":
    if (str!= "in"){
      tell_object(TP, "If you want to go all in, try"
                     +" '%^BOLD%^%^YELLOW%^all in%^RESET%^'.");
      return 1;
    }
    if(member_array(TP, allin)!=-1){
      tell_object(TP, "You already are all in. The silly dealer shouldn't"
                     +" even be allowing you a turn at betting. Next!");
      break;
    }
    if (bet + val < max_bet){
      tell_object(TP, "You don't seem to have enough chips in your hand to"
                     +" go all in. You started the round with " + max_bet
                     +", you have bet "+ bet + ", but you only have " + val
                     +" chips left. Perhaps someone stole from you?"
                     +" Anyway, you're going to need to get some more"
                     +" chips from somewhere before you can go all in.");
      if (present("chips 2", TP)){
        tell_object(TP, "Combining your stacks of chips with"
                        +" %^BOLD%^%^YELLOW%^<stack chips>%^RESET%^ may"
                        +" help");
      }
      return 1;
    }
    if (bet + val > bet_limit && bet_limit>0){
      amount = bet_limit;
    } else {
      amount = bet + val;
    }
    TP->set("last say", "");
    TP->force_me("say All in, " + amount + "!");
    take_bet(TP, amount - bet);
    allin += ({TP});
    break;
  case "bet":
    if (stg > 1 || (sizeof(players)>2 && next_better != 2)||
                          (sizeof(players)==2 && next_better != 1)){
      tell_object(TP, "The current bet is :" + curr_bet + ". You"
                     +" can %^BOLD%^%^YELLOW%^call%^RESET%^, %^BOLD%^"
                     +"%^YELLOW%^fold%^RESET%^ or %^BOLD%^%^YELLOW%^raise"
                     +"%^RESET%^. Type 'help betting' for"
                     +" more details");
      return 1;
    }
    sscanf(str, "%d", amount);
    if (amount<big_blind){
      tell_object(TP, "Your starting bet must be at least the size of the"
                   +" big blind, which is " + big_blind + " in this game");
      return 1;
    }
    if (amount-bet > val){
      tell_object(TP, "You don't have enough chips in your hand to cover"
                     +" that bet");
      return 1;
    }
    if(amount - bet >= val){
      tell_object(TP, "If you want to bet all your chips, you need to go"
                     +" %^BOLD%^%^YELLOW%^all in%^RESET%^");
      return 1;
    }
    if (amount > bet_limit && bet_limit>0){
      tell_object(TP, "You can't bet more than the bet limit for the hand,"
                     +" which is " + bet_limit + ".");
      return 1;
    }

    TP->set("last say", "");
    TP->force_me("say I bet " + amount);
    take_bet(TP, amount-bet);
    break;
  case "call": 
    if (curr_bet>max_bet){
      tell_object(TP, "You can only bet up to the amount of chips you had"
                     +" in your stack at the start of the round, which was"
                     +" " + max_bet + ". The current bet is " + curr_bet 
                     +". Your only options are to %^BOLD%^%^YELLOW%^fold"
                     +" %^RESET%^or go %^BOLD%^%^YELLOW%^ all in"
                     +"%^RESET%^.");
       return 1;
    }
    if (bet == curr_bet){
      tell_object(TP, "Your bet (" + bet + " chips) already equals the"
                     +"current bet. You can %^BOLD%^%^YELLOW%^check"
                     +"%^RESET%^, %^BOLD%^%^YELLOW%^fold%^RESET%^, or"
                     +" %^BOLD%^%^YELLOW%^raise%^RESET%^");
      return 1;
    }
    if (val < curr_bet - amount){
      tell_object(TP, "You don't seem to have enough chips in your hand to"
                     +" cover that call. You started the round with " 
                     + max_bet + " chips"
                     +", you have bet "+ bet + ", but you only have " + val
                     +" chips left. Perhaps someone stole from you?"
                     +" Anyway, you're going to need to get some more"
                     +" chips from somewhere before you can call.");
      if (present("chips 2", TP)){
        tell_object(TP, "Combining your stacks of chips with"
                        +" %^BOLD%^%^YELLOW%^<stack chips>%^RESET%^ may"
                        +" help");
      }
      return 1;
    }
    TP->set("last say", "");
    TP->force_me("say Call!");
    bet = bets[TP];
    amount = get_current_bet();
    take_bet(TP, amount - bet);
    break;
  case "raise":
//    force_me("say taking a raise from " + TPQCN);
    sscanf(str, "%d", amount);
    if (amount ==0){
      return 0;
    }
    if (amount <0){
      tell_object(TP, "You can't get away with lowering your bet by"
                     +" raising a negative amount. You naughty player. Tsk"
                     +" tsk tsk for even thinking about it.");
      return 1;
    }
    chips = present("chips", TP);
    if (!objectp(chips)){
      tell_object(TP, "You seem not to have any chips. You either have to"
                      +" get some, or you'll need to fold");
      return 1;
    }
    bet = bets[TP];
    val = chips->query_val();
    if (amount + get_current_bet()- bet > val){
      tell_object(TP, "You can't afford that bet. You only have " + val
                    + " chips in your stack");
      return 1;
    }
    if(amount + get_current_bet() - bet == val){
      tell_object(TP, "If you want to bet all your chips, you need to go"
                     +" %^BOLD%^%^YELLOW%^all in%^RESET%^");
      return 1;
    }
    if (amount + get_current_bet()>bet_limit && bet_limit >0){
      tell_object(TP, "You can't bet more than the bet limit for the hand,"
                     +" which is " + bet_limit + " chips. You have already"
                     +" bet " + bet + ", so the most you can raise by is "
                     + (bet_limit - bet) + ".");
      return 1;
    }
    if (amount + get_current_bet() > max_bets[TP] ){
      tell_object(TP, "You can only bet up to the amount of chips that you"
                     +" had in your hand when the hand was dealt. You had"
                     +" " + max_bets[TP] + ".");
      return 1;
    }
    TP->set("last say", "");
    TP->force_me("say Raise " + amount);
    bet = bets[TP];
    take_bet(TP, amount + get_current_bet() - bet);
    break;
  case "check":
//    force_me("say taking a check from " + TPQCN);
    bet = get_current_bet();
    if (bets[TP]<bet){
      if (max_bets[TP]<bet){
//        force_me("say The current bet is " + bet + ", but the most you"
//                     +" can bet is " + max_bets[TP]+ ". You must either"
//                       +" %^BOLD%^%^YELLOW%^fold%^RESET%^ or go"
//                       +" %^BOLD%^%^YELLOW%^all in%^RESET%^.");
        tell_object(TP, "The current bet is " + bet + ", but the most you"
                       +" can bet is " + max_bets[TP]+ ". You must either"
                       +" %^BOLD%^%^YELLOW%^fold%^RESET%^ or go"
                       +" %^BOLD%^%^YELLOW%^all in%^RESET%^.");
         return 1;
      }
//      force_me("say You need to at least match the current bet, which"
//                     +" is " + bet + ". You can %^BOLD%^%^YELLOW%^call"
//                   +" %^RESET%^or %^BOLD%^%^YELLOW%^raise%^RESET%^. Type"
//                     +" %^BOLD%^%^YELLOW%^help betting%^RESET%^ for more"
//                     +" details");

      tell_object(TP, "You need to at least match the current bet, which"
                     +" is " + bet + ". You can %^BOLD%^%^YELLOW%^call"
                     +" %^RESET%^or %^BOLD%^%^YELLOW%^raise%^RESET%^. Type"
                     +" %^BOLD%^%^YELLOW%^help betting%^RESET%^ for more"
                     +" details");
      return 1;
    }
    TP->set("last say", "");
    TP->force_me("say check");
    break;
  case "fold":
//    force_me("say taking a fold from " + TPQCN);
    TP->set("last say", "");
    TP->force_me("say Fold");
    tell_room(ETO, "The dealer acknowledges that "+TPQCN+" has folded");
    folders += ({TP}); 
    if (all_folded()==1){
      return 1;
    } 
    break;
  default:
    force_me("say I don't recognize the command: " + verb);
  }
  next_better++;
  bet_counter ++;
  if (next_better>sizeof(players)-1){
    next_better = 0;
  }
  while (member_array(players[next_better], folders)!= -1 || member_array(players[next_better], allin)!= -1 ){
//    force_me("say passing over " + players[next_better]->QCN + ", who has
// either folded or is all in");
    next_better++;
    if(next_better>sizeof(players)-1){      
      next_better = 0;
    } 
    if (all_bets_are_equal()==1 
                && bet_counter >= sizeof(players)-num_folders-num_allin){
 //     force_me("say All bets are equal. Bet counter: " + bet_counter 
 //           + "\nnumber of players: " + sizeof(players) + "\nnumber of //folders: " + num_folders + "\nnumber all in: " + num_allin);

      next_round();
      return 1;
    }
  }
  if (all_bets_are_equal()==1 && bet_counter >= sizeof(players)-num_folders - num_allin){
//    force_me("say All bets are equal. Bet counter: " + bet_counter 
//            + "\nnumber of players: " + sizeof(players) + "\nnumber of //folders: " + num_folders + "\nnumber all in: " + num_allin);
//    force_me("say starting next round");
    call_out("next_round", 2);
    return 1;
  }
//  force_me("say Not time to move on. Bet counter: " + bet_counter 
//            + "\nnumber of players: " + sizeof(players) + "\nnumber of //folders: " + num_folders + "\nnumber all in: " + num_allin);
 // force_me("say about to start next bet");
  call_out("next_bet", 2);
  return 1;
}

int buy_chips(string str){
  string what;
  int amount, copper, silver, electrum, gold, platinum, total, cost;
  object chips;
  if (sscanf(str, "%d %s", amount, what)!=2){
    return 0;
  }
  if (what!="chips"){
    return 0;    
  }
  copper = TP->query_money("copper");
  silver = TP->query_money("silver");
  electrum = TP->query_money("electrum");
  gold = TP->query_money("gold");
  platinum = TP->query_money("platinum");
  total = (copper/100) + (silver/10) + (electrum/5) + gold + (platinum *5);
  cost = amount * 105/100;
  if (cost>total){
    tell_object(TP, "You can't afford that many chips. The most you could"
               +" afford would be " + (total /105*100) + ".");
    return 1;
  }
  tell_object(TP, "You buy " + amount + " chips from the dealer, at a cost"
                 +" of " + cost + ".");
  tell_room(ETO, TPQCN + " buys some chips from the dealer.", TP);
  if (cost<gold){
    TP->add_money("gold", (-1* cost));
    cost = 0;
  } 
  if (cost>0){
    if ((cost/5)<=platinum){
      TP->add_money("platinum", (-1*cost/5));
      cost = cost%5;
    }else{
      TP->add_money("platinum", (-1*platinum));
      cost -= (platinum*5);
    }
  }
  if (cost>0){
    if (cost<= gold){
      TP->add_money("gold", (-1* gold));
      cost = 0;
    }else{
      TP->add_money("gold", (-1* gold));
      cost-= gold;
    }
  }
  if (cost>0){
    if (cost*2>electrum){
      cost -= electrum/2;
      TP->add_money("electrum", (-1*(electrum/2)));
    }else{
      TP->add_money("electrum", (-2*cost));
      cost = 0;
    }
  }
  if (cost>0){
    if (cost*10>silver){
      cost -= silver/10;
      TP->add_money("silver", (-1*(silver/10)));
    }else{
      TP->add_money("silver", (-10*cost));
      cost = 0;
    }
  }
  if (cost>0){
    if (cost*100>copper){
      cost -= copper/100;
      TP->add_money("copper", (-1*(copper/100)));
    }else{
      TP->add_money("copper", (-100*cost));
      cost = 0;
    }
  }
  give_chips(TP, amount);
  return 1;
}
string calculate_winner(){
  mapping highhands;
  object * winners, player1, player2; 
  string result, * hand1, * hand2, descrip;
  int * vals, i, j, * order, kickers, kick;
  highhands = ([]);
  vals = allocate(10);
  order = allocate(10);
  kick = 0;
  winners = ({});
//  force_me("say about to get best hands and values for all players");
  for (i=0;i<sizeof(players);i++){
//    force_me("say about to get best hands and value for " 
//                                              + players[i]->QCN);
    highhands+= ([ players[i] : get_highest_hand(players[i]) ]);
    if (member_array(players[i], folders)!=-1){
      vals[i] = 0;
    } else {
      vals[i] = query_hand_value(highhands[players[i]]);
    }
//    force_me("say best value is: " + vals[i]);
  }

  result = "";

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
//  force_me("say The order of players' hand values is:");
//  for (i=0;i<sizeof(order);i++){
//   force_me("say " + players[order[i]]->QCN);
//  }
  winners += ({players[order[0]]});
  for(i=1;i<sizeof(order);i++){
    if (vals[order[i]] == vals[order[0]]){
      winners += ({players[order[i]]});
    }else{
      break;
    }    
  }
//  force_me("say The winners are: ");
//  for (i=0;i<sizeof(winners);i++){
//    tell_room(ETO, winners[i]->QCN);
//  }
  if (sizeof(winners)>2){
    winners = remove_duplicates(winners);
  }
  if (sizeof(winners)>1){
    for (i=sizeof(winners)-1;i>0;i--){
      player1 = winners[i];
      player2 = winners[i-1];
//      force_me("say comparing the kickers for " + player1->QCN + " and "
// + player2->QCN);
      kickers = compare_kickers(highhands[player1],highhands[player2]);
      switch(kickers){
      case 0: // hands are equal by kickers;
 //       force_me("say A draw!");
        break;
      case 1: // the first hand wins by kickers;
//        force_me("say " + player1->QCN + " wins!");
        winners -= ({player2});
        kick = 1;
        break;
      case 2: // the second hand wins by kickers;
        winners -= ({player1});
//        force_me("say " + player2->QCN + " wins!");
        kick = 1;
        break;
      }
    }
  }
  if (sizeof(winners)<2){
    if (kick ==0){
      result = winners[0]->QCN + " wins with " 
            + describe_hand(highhands[winners[0]]);
    } else {
      descrip = describe_hand(highhands[winners[0]]);
      result = winners[0]->QCN + " wins with "+ descrip;
      if (interact("the high card - ", descrip)==0){
        result += " and the highest cards in the rest of " + winners[0]->QP
               + " hand";
      }
    }
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
    descrip = describe_hand(highhands[winners[0]]);
    result += descrip;
    if (kick ==1){
      if (interact("the high card - ", descrip)==0){
        result += " and the highest cards in the rest of their hands";
      }
    }
  }
  force_me("say %^BOLD%^%^RED%^" + result);
  handout_winnings(winners);
  call_out("end_hand", 3);
  return result;
}

int cash_chips(string str){
  object chips;
  int amount;
  chips = present("chips", TP);
  if (!objectp(chips)){
    tell_object(TP, "You don't have any chips to cash");
    return 1;
  }
  amount = chips->query_val();
  if (amount<1){
    tell_object(TP, "Your chips aren't worth anything");
    return 1;
  }
  tell_object(TP, "You cash in your chips for " + amount + " %^BOLD%^"
         +"%^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^%^YELLOW%^ld%^RESET%^");
  if (objectp(ETO)){
    tell_room(ETO, TPQCN + " cashes in " + TP->QP + " chips.", TP);
  }
  chips->move(VOID);
  TP->add_money("gold", amount); 
  return 1;
}

void catch_tell(string str){
  object * people;
  string name, junk, true_name, * temp_hand, * highhand, result;
  int i, cheat;
  object dropper, card, revealer, card2;
  if(TP == TO){
    return;
  }
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

  if (interact("reveals", str)){
    if (stg !=4){
      force_me("say Hold on - it's not time to show your hands yet");
      return;
    }
    people = all_living(ETO);
    sscanf(str, "%s reveals %s", name, junk);
    if (name[0]=='$'){ // this is to deal with the odd names returned by
      name = name[3..strlen(name)-4];  // PCs from QCN
    }
    name = lower_case(name);

    if (sizeof(people)>0){
      for (i=0;i<sizeof(people);i++){
        true_name = people[i]->query_true_name();
        if (true_name == name){
          heard_reveal = people[i];
        }
      }
    }
  }
  if (interact("1>", str) && objectp(heard_reveal)){
    heard_reveal2 = heard_reveal;
    sscanf(str, "%s1> %s", junk, cardname1);
//    force_me("say " + heard_reveal->QCN + " has " + cardname1);
  }
  if (interact("2>", str) && objectp(heard_reveal2)){
    sscanf(str, "%s2> %s", junk, cardname2);
//    force_me("say " + heard_reveal->QCN + " has " + cardname2);
    if(member_array(heard_reveal, folders)!=-1){
      force_me("emote frowns");
      force_me("say We don't need to see your cards " + heard_reveal->QCN 
              +". You folded.");
      return;
    }
    if (member_array(heard_reveal, revealers)==-1){
      force_me("emote nods");
      force_me("say, okay , " + heard_reveal->QCN + ", that's " + cardname1
              +" and " + cardname2);
      temp_hand = ({cardname1, cardname2});
//      highhand = get_highhand(heard_reveal, temp_hand);
//      result = "%^BOLD%^%^CYAN%^";
//      for (i=0;i<4;i++){
//        result += highhand[i] + ", ";
//      }
//      result += " and " + highhand[4];
//      force_me("say Your best hand with those cards is " + result + ", "
//                                          + heard_reveal->QCN);
//      result = describe_hand(highhand);
//      force_me ("say That gives you " + result);
      revealers += ({heard_reveal});
    } else {
      force_me("say Okay , " + heard_reveal->QCN + ", we already saw your"
              +" cards");
      switch(random(5)){
      case 0:
        force_me("say Don't go getting over-excited on us now");
        break;
      case 1:
        force_me("say They ain't *that* great");
        break;
      case 2:
        force_me("say D'ya think we're slow or somethin?");
        break;
      case 3:
        force_me("say We can read 'em first time around, even iffn you"
                +" can't");
        break;
      case 4:
        force_me("say What d'ya want, a round of applause?");
      }
      return;
    }
    temp_hand = hands[heard_reveal];
    if (sizeof(temp_hand)==2){
      if (member_array(cardname1, temp_hand)==-1||
                   member_array(cardname2, temp_hand)==-1){
        cheat = random(sizeof(CHEATME));
        tell_object(heard_reveal, "The cards you just revealed weren't the"
            +" cards you were dealt. If this was a mistake, you can"
            +" correct it by typing '%^BOLD%^%^YELLOW%^correct%^RESET%^"
            +"' within a few seconds. If you"
            +" meant to reveal different cards than the ones you were"
            +" dealt (i.e you are deliberately cheating), just keep quiet."
            +" We will assume that you " + CHEATME[cheat]+ ". However, you"
            +" may get caught. Type %^BOLD%^%^YELLOW%^Help cheat%^RESET%^"
            +" for more details");
         call_out("cheat", 5, heard_reveal, cheat, cardname1, cardname2);
         temp_hand = ({cardname1, cardname2});
      }
    }
    cardname1= "";
    cardname2= "";
    heard_reveal = 0; 
    if(sizeof(revealers)==sizeof(players)-sizeof(folders)){
      call_out("anticipate", 1);
    }
  }
}

void cheat(object cheater, int cheat, string cardname1, string cardname2){  
  object * people;
  string cheatstring;
  int i, my_level, witness_level, witness_wis, result, conceal_skill;
  if (member_array(cheater, correctors)!=-1){
    correctors -= cheater;
    return;
  }
  if (!objectp(cheater)){
    cleanup_players();
    return;
  }
  if (!objectp(ETO)){
    tell_object(cheater, "ERROR: There's a problem with the room. Please"
                   +" tell a WIZ");
    return;
  }
  people = all_living(ETO);
  conceal_skill = cheater->query_nwp("concealment");
  my_level = cheater->query_highest_level();
  if (sizeof(people)>0){
    for(i=0;i<sizeof(people);i++){
      witness_level = people[i]->query_highest_level();
      witness_wis = people[i]->query_stats("wisdom");
      result = (my_level-witness_level)*5 + conceal_skill/2 
                                             - ((witness_wis - 11)* 2);
      if (result>95) result= 95;
      if (result<10) result = 10;
      if (random(100)+1 > result){
        if (people[i]==TO){
          force_me("emote looks shocked");
          force_me("say Hey, " + cheater->QCN +"! You cheated! I saw that "
                  + CHEATME[cheat]);
          end_hand();
          return 1;
        }
        tell_object(people[i], "You see that " + cheater->QCN 
                               + CHEATYOU[cheat]);
      }
    }
  }
  return 1;
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

void cleanup_players(){
  int i;
  if (sizeof(players)<1){
    return;
  }
  for (i=0;i<sizeof(players);i++){
    if (!objectp(players[i]) || !present(players[i], ETO)){
      players -= players[i];
    }
  }
}

void clear_decks(){
  object table, player, card;
  int i;
  if (!objectp(ETO)){return;}
  table = present("table", ETO);
  if (objectp(table)){
    force_me("emote clears the table");
    table->clear_table();
  }
  if (sizeof(players)<1){return;}
  for (i=0;i<sizeof(players);i++){
    player = players[i];
    if (!objectp(player)){
      continue;
    }
    if (!objectp(ETO)){
      break;
    }
    if (!present(player, ETO)){
      evict_absentee(player);
    }
    card = present(deck_id, player);
    if (objectp(card)){
      tell_object(player, "The dealer collects your cards");
      tell_room(ETO, "The dealer collects " + player->QCN +"'s cards",
                          player);
    }
    while(present(deck_id, player)){
      card = present(deck_id, player);
      card->move(VOID);
    }
  }
}

/*
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
}*/

int compare_kickers(string * hand1, string * hand2){
  int * vals1, * vals2, i;
  vals1 = query_hand_values(hand1);
  vals2 = query_hand_values(hand2);
  for (i=0;i<sizeof(hand1)&&i<sizeof(hand2);i++){
    if (vals1[i] > vals2[i]){
      return 1;
    }
    if (vals1[i] < vals2[i]){
      return 2;
    }
  }
  return 0;
}

int correct(string str){
  string * hand, card1, card2;
  if (member_array(TP, players)==-1){
    tell_object(TP, "No need for you to correct anything - you're not part"
                   +" of the current hand");
  }
  if (member_array(TP, revealers)==-1){
    tell_object(TP, "Correct what? You haven't revealed your hand yet");
    return 1;
  }
  if (!present(deck_id + " 1", TP) || !present(deck_id + " 2", TP)){
    tell_object(TP, "Sorry, you seem not to have your original cards on"
                   +" you, so you can't correct your mistake");
    return 1;
  }
  hand = hands[TP];
  if (sizeof(hand !=2)){
    tell_object(TP, "ERROR - your original hand seems not to have been"
                   +" recorded correctly. Please tell a Wiz (preferably"
                   +" Lujke). In the meantime, you can't correct your"
                   +" mistake so you'll have to live with it.");
    return 1; 
  }
  card1 = hand[0];
  card2 = hand[1];
  TP->force_me("emote blushes as " + TP->QS + " realises " + TP->QS 
              +" revealed the wrong cards by mistake. " + TP->QS 
              +" quickly shows that " + QP + " actual cards were the"
              +" %^BOLD%^%^YELLOW" + card1 + "%^RESET^% and the %^BOLD%^"
              +"%^YELLOW%^" + card2 + "%^RESET%^.");
  revealers -= ({TP});
  correctors += ({TP});
}

int deal(){
  int i, j, k, l;
  string * playernames, card_name, player_name, hand, racename;
  object absentee, deck, card, dealee, better, player, * critters;
  mapping newhands;
  if (!objectp(ETO)){return 0;}
  get_fresh_deck();
  force_me("shuffle");
//  playernames = keys(hands);
  clear_decks();
  for(i=0;i<sizeof(players);i++){
    hand = allocate(2);
    hands[players[i]] = hand;
  }
  for (i=0;i<2;i++){
    for(j=0;j<sizeof(players);j++){
      player = (players[j]);
      if (!present(player, ETO)){
        if (objectp(player)){
          force_me("say Looks like " + absentee->QCN + " has wandered off."
                  +" Guess I'll just deal " + absentee->QO + " out."
                  +" Everyone put down your cards and let me know when to" 
                  +" start again");

        } else{ 
          force_me("say hmm, seems like someone's wandered off. I guess"
                  +" I'll just deal them out, but we'll need to start"
                  +" over. Everyone put your cards on the table and I'll"
                  +" break out a fresh deck.");
        }
        evict_absentee(player);
        return -1;
      }
      if (!interactive(player)){
        force_me("deal to " + player->QCN);
      } else {
//        force_me("say trying to deal to a player");
        critters = all_living(ETO);
        for (l=0;l<sizeof(critters);l++){
          racename = player->query_race() + " " + (l+1);
//          force_me("say racename is : " + racename);
          if (present(racename, ETO)==player){
//            force_me("say trying to deal to "+ racename);
            force_me("deal to " + racename);
            break;
          }
        }
      }
      card = present("card", player);
      if (objectp(card)){
        card_name = card->query_card_name();
      //force_me("say adding " + card_name + " to " + player->QCN 
      //        +"'s hand");
        hands[player][i] =  card_name;
        card_name = hands[player][i];
      //force_me("say " + player->QCN + " now has the " + card_name);
      } else{
      //force_me("say That's funny. " + player->QCN 
      //       + " doesn't have the card I just dealt " + player->QO);
      }
    }
  }
  for (i=0;i<5;i++){
    force_me("deal to table");
  }
  setup_bets();
  if (next_better>sizeof(players)-1){next_better = 1;}
  better = players[next_better];
  tell_room(ETO, "%^MAGENTA%^" +TO->query_short() + " says:%^RESET%^ Your"
                +" bet, " + better->QCN + "?");
  return 1;
}

int deal_hand(string str){
  if (str != "hand"){
    return 0;
  }
  TP->force_me("emote nods to the dealer, indicating that " + TP->QS 
     + " is ready for the hand to be dealt");
  if (sizeof(players)<2){
    force_me("emote shakes his head.");
    call_out("force_me", 2, "say There's only one fella signed up to"
                          +" play. We gotta have two at least fer a game");
    return 1;
  }
  if (stg ==0){
    deal();
  } else{
    force_me("emote shakes his head, as there's a hand already underway");
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

void end_game(){
  int i;
  object table, deck, chips;
  force_me("say Alright, this game appears to be over. Just ask me to"
          +" %^BOLD%^%^YELLOW%^start game%^RESET%^ if you want to start a"
          +" new game.");
  if (get_current_bet()>0 && sizeof(players)>0){
    for (i=0;i<sizeof(players);i++){
      if (bets[players[i]]>0 && present(players[i], ETO)){
        force_me("emote returns some chips to " + players[i]->QCN);
        chips = present("chips", players[i]);
        if (!objectp(chips)){
          chips = new(CHIPS);
          chips->move(players[i]);
        }
        chips->set_val(chips->query_val()+ bets[players[i]]);
      }
    }
  }
  players = ({});
  allin =({});
  folders = ({});
  revealers = ({});
  hands = ([]);
  bets = ([]);
  max_bets = ([]);
  stg = 0;
  num_folders = 0;
  num_allin = 0;
  next_better = 0;
  small_blind = 10;
  big_blind = 20;
  bet_limit = 0;
  winnings = 0;
  get_fresh_deck();
  if (!objectp(ETO)){ return; }
  table = present("table", ETO);
  table->clear_table();
}


void end_hand(){ 
  int i;
  folders = ({});
  allin = ({});
  revealers =({});
  hands =([]);
  bets = ([]);
  max_bets = ([]);
  stg = 0;
  winnings = 0;
  bet_counter = 0;
  num_folders = 0;
  num_allin = 0;
  force_me("say That's the end of the hand");
  advance_bet_order();
  if (sizeof(waiters)>0){
    for (i=0;i<sizeof(waiters);i++){
      if (present(waiters[i], ETO)){
        force_me("say You can join the game now, " + waiters[i]->QCN 
                +". I'll deal you in on the next hand.");
        players += ({waiters[i]});
      }
    }
    waiters = ({});
  }
  clear_decks();
}

void evict_absentee(object absentee){
  object player, next_to_bet;
  int i,  absentee_number;
  if (!objectp(ETO)){
    end_game();
    return;
  }
  if (present(absentee, ETO) && eviction ==0){
    return;
  }
//  force_me("say evicting someone from the game");
  if (objectp(absentee)){
    absentee_number = member_array(absentee, players);
    if (absentee_number!=-1){
      bet_counter--;
      if (players[next_better] == absentee){
        next_better++;
        if (next_better>sizeof(players)-1){
          next_better = 0;
        }
      }
      next_to_bet = players[next_better];
      players -= ({absentee});
      if (member_array(absentee, folders)!=-1){
        folders -= ({absentee});
      }
      if (member_array(absentee, allin)!=-1){
        allin -= ({absentee});
      }
      map_delete(bets, absentee);
      map_delete(hands, absentee);
      map_delete(max_bets, absentee);
      if (sizeof(players)<2){
        end_game();
        eviction = 0;
        return;
      }
      for (i=0;i<sizeof(players);i++){
        if (players[i]==next_to_bet){
          next_better = i;
        }
      }
    }
    force_me("say Well, " + absentee->QCN +" appears to have left us. I'll"
            +" just deal " + absentee->QO + " out.");
  } else {
    force_me("say Well, someone appears to have left us. I'll just deal"
            +" them out.");
    cleanup_players();
  }
  bets = map_delete(bets, absentee);
  hands = map_delete(hands, absentee);
  max_bets = map_delete(max_bets, absentee);
  eviction = 0;
}

int force_ending(string str){
  if (str!= "game"){
    tell_object(TP, "If you are trying to end the game, try '%^BOLD%^"
                   +"%^YELLOW%^end game%^RESET%^'");
    return 1;
  }
  TP->force_me("%^BOLD%^%^RED%^emote indicates to the dealer that the game"
              +" should be ended now");
  end_game();
  return 1;
}

int get_current_bet(){
  int i, bet, * amounts;
  amounts = values(bets);
  if (sizeof(amounts)<1){ return 0;}
  bet = 0;
  for (i=0;i<sizeof(amounts);i++){
    if (amounts[i]>bet){
      bet = amounts[i];
    }
  }
  return bet;
}

void get_fresh_deck(){
  object deck;
  while(present("deck", TO)){
    force_me("offer deck");
  } 
  while(present("card", TO)){
    present("card", TO)->remove();
  }
  deck =  new(DECK);
  deck->move(TO);
  deck_id = deck->query_deck_id();
  set_table_deck_id();
}

string * get_highhand(object pl, string * myhand){
  object table;
  string * poss_cards, * hand, *final_hand, junk;
  int i, j, k, l, * cards, val, high_val, kick1, kick2;
  object * inv, ob;
  if (!objectp(pl)){ return ({"no player here by that name"});}
//force_me("say finding the highest hand for " + player->QCN);
  if (!objectp(ETO)){return ({"Error in the environment"});}
  table = present("table", ETO);
  if (!objectp(table)){
    return ({"No card table present"});
  }
//  force_me("say getting high hand for " + pl->QCN);
//  force_me("say " + pl->QCN + "'s hand is: ");
//  for (i=0;i<sizeof(myhand);i++){
//    tell_room(ETO, myhand[i]);
//  }
  inv = all_inventory(table);
  poss_cards = ({});
//force_me("say getting " + player->QCN + "'s cards, of which there are: "
//+ sizeof(hands[player]) );
//  tell_room(ETO, hands[pl]);
    poss_cards += myhand;
//force_me("say Getting possible cards:");
  for (i=0;i<sizeof(inv);i++){
    ob = inv[i];
    if (ob->id(deck_id)){
      poss_cards += ({ob->query_card_name()});
    }
  }
  if (sizeof(poss_cards)>7){
    tell_room(ETO, "Warning: There were too many cards (" 
            + sizeof(poss_cards) + ") around the place. They are:");
     for(i=0;i<sizeof(poss_cards);i++){
       junk = poss_cards[i]->query_card_name();
       tell_room(ETO, junk);
     }
  }
  if (sizeof(poss_cards)<7){
    tell_room(ETO, "Warning: There were not enough cards around the"
            +" place");
  }
//tell_room(ETO, "Getting highest hand from this combination of cards:");
//  for (i=0;i<sizeof(poss_cards);i++){
//    tell_room(ETO, poss_cards[i]);
//}
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
      val = query_hand_value(hand);
      if (val==high_val){
        if (compare_kickers(hand, final_hand)==1){
          final_hand = hand;
        }
      }
      if (val>high_val){
        high_val = val;
        final_hand = hand;
      }
    }
  }
  if (member_array(pl, folders)==-1){
    force_me("say " + pl->QCN + "'s best hand is:");
    junk = "%^BOLD%^%^CYAN%^";
    for(i=0;i<5;i++){
      junk+= final_hand[i]+";";  
    }
    tell_room(ETO, junk);
  }
  return final_hand;
}


string * get_highest_hand(object player){
  if (!objectp(player)){ return ({"no player here by that name"});}
  return get_highhand(player, hands[player]);
}

void give_chips(object player, int amount){
  object chips;
  chips = present("chips", player);
  if (objectp(chips)){
    chips ->set_val(chips->query_val()+ amount);
  } else{
    chips = new(CHIPS);
    chips->set_val(amount);
    chips->move(player);
  }
}

void handout_winnings(object * winners){
  object winner;
  mapping handouts;
  int i, j, num_players, num_winners, share,bet, curr_bet, amount,
              betshare;
  cleanup_players();
  handouts = ([]);
  num_players = sizeof(players);
  num_winners = sizeof(winners);
  curr_bet = get_current_bet();
  for (i=0;i<sizeof(players);i++){
    handouts += ([players[i] : 0]);
  }
  if (num_winners <1){
    force_me("say Strange, we appear to have no winners");
    return;
  }
  force_me("emote distributes the winnings and any unclaimed or un-covered"
          +" bets");
  for(i=0;i<num_winners;i++){
    winner = winners[i];
    bet = bets[winner];
    for(j=0;j<sizeof(players);j++){
      curr_bet = bets[players[j]];
      if (bet>=curr_bet){
        handouts[winner]+= curr_bet/sizeof(winners);
        winnings -= curr_bet/sizeof(winners);
      } else {
        betshare = curr_bet/sizeof(winners);
        if (bet<=betshare){
          betshare = bet;
        }
        handouts[winner] += betshare;
        handouts[players[j]] += curr_bet/sizeof(winners) - betshare;
        winnings -= curr_bet/sizeof(winners);
      }
    }
  }
  if (winnings > 0){
    share = winnings / num_winners;
    for (i=0;i<sizeof(winners);i++){
      winner = winners[i];
      handouts[winner] += share;
    }
  }
  for (i = 0;i<sizeof(players);i++){
    winner = players[i];
    amount = handouts[winner];
    if (amount == 0){
      tell_object(winner, "You get nothing");
      tell_room(ETO, winner->QCN + "%^RESET%^ gets nothing", winner);
    } else {
      tell_object(winner, "%^BOLD%^%^CYAN%^You get " + amount + " chips.");
      tell_room(ETO, "%^BOLD%^%^CYAN%^" + winner->QCN + "%^BOLD%^%^CYAN%^"
                    +" gets " + amount + " chips.", winner);
      give_chips(winner, amount);
    }
  }
//  end_hand();
}

int help(string str){
  string result;
  switch(str){
  case "pokiir":
    result = "Pokiir is a card game thought to have originated somewhere in the tsvarani empire, but which has now spread to all cornerns of the realms. It is a betting game, usually played for money in the form of betting counters. It uses the standard pack of 52 cards, from Rogues to Lords in the suits of Clubs, Gems, Swords and Towers. Rogues can be considered to be high or low, depending on the other cards in a player's hand."
+"\n\n%^BOLD%^%^YELLOW%^basics%^RESET%^\n"
+"At the start of play, each player is dealt two cards, and five 'community cards' are dealt face down onto the table.\nAt the end of the hand, the player's hand is considered to be the best hand of five cards he or she can make from his or her own two cards and the five shared community cards. The scoring hand types are as follows:\n"
+"%^BOLD%^%^YELLOW%^Scoring Hands\n"
+"%^BOLD%^%^CYAN%^High card%^RESET%^ - If no other scoring combinations are available, players' hands are compared on the basis of the highest card. Each player's highest card is considered first if two or more players have the same highest card, consideration moves to their second highest cards and so on.\n"
+"%^BOLD%^%^CYAN%^A pair%^RESET%^ - Two cards of the same value. E.g. two fours or two Rogues, etc. If more than one player has a pair, the player with the highest value pair wins. If two players each have a pair of the same value, the values of their other cards are considered.\n"
+"%^BOLD%^%^CYAN%^Two Pair%^RESET%^ - two pairs of different values in the same hand. E.g Two rogues and two fives, or two hunters and two threes. If two or more players each have two pairs, the value of each player's highest pair is considered first, then the value of the second highest pair if there is a draw. If two players each have two pairs of identical values, the non-scoring card is considered.\n"
+"%^BOLD%^%^CYAN%^Three of a kind%^RESET%^ Three cards of the same value in the same hand%^RESET%^. If two players can each make a hand with three of a kind of the same value (possible due to the shared community cards), the values of their remaining cards are considered to separate them.\n"
+"%^BOLD%^%^CYAN%^A straight%^RESET%^ - five cards of consecutive values. E.g a three, a four, a five, a six and a seven. Rogues can either be high(ten, hunter, damesel, lord, rogue) or low (rogue, two, three, four, five). If two players each have a straight, the highest value straight wins.
%^BOLD%^%^CYAN%^A flush%^RESET%^ - Five cards of the same suit in a hand. If two or more players each have a flush, the value of the cards are considered.\n"
+"%^BOLD%^%^CYAN%^Full house%^RESET%^ - Three of a kind, plus a pair in the same hand. If two players both have full houses, the values of the threes are considered first, then the values of the pairs.\n"
+"%^BOLD%^%^CYAN%^Four of a kind%^RESET%^ - Four cards of the same value in a hand. If two players each have four of a kind, the values of the fours are considered first, then the values of their non-scoring cards.\n"
+"%^BOLD%^%^CYAN%^Straight flush%^RESET%^ - Five consecutive cards of the same suit (eg four, five, six, seven and eight of gems). If two players each have a straight flush, the values of their cards are considered.\n"
"%^BOLD%^%^CYAN%^Royal Flush%^RESET%^ - Ten, hunter, damsel, lord and rogue of the same suit. The highest scoring hand possible and a guaranteed win unless someone else has the same (possible due to the shared community cards).\n"
+"%^BOLD%^%^YELLOW%^Order of play%^RESET%^\n"
+"After the cards are dealt, there follow several rounds of betting, during which the community cards are progressively revealed. After the first round of betting, the first three community cards are revealed. There is then a second round of betting, then the fourth community card is revealed. After third round of betting the final community card is revealed. There is then one final round of betting with all the community cards revealed.\n"
+"Once all the betting is completed, any players remaining in the hand reveal their hands and the winning hand is calculated. If all but one player folds before the end, the remaining player wins by default. If two or more players have identical scoring hands, the hand is drawn and the pot is divided between the winning players. See %^BOLD%^%^YELLOW%^help betting%^RESET%^ for more details.\n\n"
+"See also: %^BOLD%^%^YELLOW%^help betting%^RESET%^, %^BOLD%^%^YELLOW%^help pokiir commands%^RESET%^";
    break;
  case "betting":
    result = "%^BOLD%^%^YELLOW%^Betting in Pokiir%^RESET%^\n"
+"Pokiir is a game that is as much about the betting as about the cards themselves. A canny player can win hands they should lose, and avoid losing too much money on a bad hand, by the betting decisions that they make.%^RESET%^\n\n"

+"%^BOLD%^%^YELLOW%^Betting limits%^RESET%^\n"
+"In a given hand of pokiir, each player may only bet up to the number of chips that they had in their stack when the cards were dealt. Some games also have a separate bet limit, which is the most that can be bet by any player on a given hand.\n\n"

+"\n%^BOLD%^%^YELLOW%^Betting rounds%^RESET%^\n"
+"Each hand of pokiir is played with several separate rounds of betting. The same player starts each round of betting for a given hand, but who that player is changes on each hand. The other players are called to make their own bets in turn. The betting continues until all players have bet and all players have either bet equal amounts, gone all in, or folded (see below).\n\n"

+"%^BOLD%^%^YELLOW%^Betting options%^RESET%^\n"
+"Each time it is a player's turn to bet, the following options may be available:\n"
+"%^BOLD%^%^YELLOW%^bet <amount>%^RESET%^ Fairly self explanatory, but only available to the first player to bet on a hand. The first bet must at least match the %^BOLD%^%^YELLOW%^big blind%^RESET%^ (see below).\n"
+"%^BOLD%^%^YELLOW%^call%^RESET%^ A call matches the current highest bet. The dealer will collect enough chips from the player to make up the difference between this and the player's current bet. A player can only call if this will not take their bet above their betting limit. If the current highest bet is above the player's bet limit, they must choose to go %^BOLD%^%^YELLOW%^all in%^RESET%^ or %^BOLD%^%^YELLOW%^fold%^RESET%^(see below)\n"
+"%^BOLD%^%^YELLOW%^raise <amount>%^RESET%^ Raises the current highest bet by the amount specified. The dealer will collect enough chips from the player to make up the difference between this and the player's current bet.\n"
+"%^BOLD%^%^YELLOW%^check%^RESET%^ Leaves the player's current bet as it is. This option is only available if the player's current bet is equal to the current highest bet.\n"
+"%^BOLD%^%^YELLOW%^fold%^RESET%^ Folds the player's hand and drops the player out of the hand. The player loses the chance of winning the hand, but also doesn't have to bet any more. The final benefit is that the player is not required to reveal their cards at the end of the hand.\n"
+"%^BOLD%^%^YELLOW%^all in%^RESET%^ Bets all of the player's remaining chips, up to their bet limit. By going all in, the player removes themselves from further betting. The player may also continue in a hand where the highest bet has risen above the player's bet limit. Should a player who has gone all in win the hand, the most that they can win is an amount equivalent to their bet from each player. Any players who bet a higher amount than this have the balance of their chips returned.\n\n"

+"%^BOLD%^%^YELLOW%^Blinds%^RESET%^\n"
+"Pokiir is usually played with a 'big blind' and a 'small blind'. This means that one player has to bet a small amount and one player has to bet a larger amount at the start of play. Who pays the big blind and who pays the small blind is changed on rotation after each hand. A new player joining the game always starts off paying the big blind.\n\n"
+"See also: %^BOLD%^%^YELLOW%^help pokiir%^RESET%^, %^BOLD%^%^YELLOW%^help pokiir commands%^RESET%^";
    break;
  case "pokiir commands":
    result = "Available commands:\n\n"
+"%^BOLD%^%^YELLOW%^buy <amount> chips%^RESET%^ - buys some chips, worth 1 gold per chip. The dealer charges a 5% commission on chips\n"
+"%^BOLD%^%^YELLOW%^cash chips%^RESET%^ - cashes in the chips in your stack\n"
+"%^BOLD%^%^YELLOW%^start game%^RESET%^ - Asks the dealer to get a game going.\n"
+"%^BOLD%^%^YELLOW%^join game%^RESET%^ - Asks to join the current game\n"
+"%^BOLD%^%^YELLOW%^leave game%^RESET%^ - Asks the dealer to deal you out"
+" of the game\n"
+"%^BOLD%^%^YELLOW%^end game%^RESET%^ - Asks the dealer to end the current"
+" game. Use this to reset the game in case of any problems."
+" %^BOLD%^%^RED%^NOTE: this command is an OOC tool. It shoult NOT be used"
+" to end someone else's ongoing game. If you want to spoil"
+" their fun, make a nuisance of yourself ICly.\n%^RESET%^"
+"%^BOLD%^%^YELLOW%^deal hand%^RESET%^ - Asks the dealer to deal a new hand\n"
+"%^BOLD%^%^YELLOW%^all in%^RESET%^ - betting command - see help betting\n"
+"%^BOLD%^%^YELLOW%^bet%^RESET%^ - betting command - see help betting\n"
+"%^BOLD%^%^YELLOW%^call%^RESET%^ - betting command - see help betting\n"
+"%^BOLD%^%^YELLOW%^check%^RESET%^ - betting command - see help betting\n"
+"%^BOLD%^%^YELLOW%^fold%^RESET%^ - betting command - see help betting\n"
+"%^BOLD%^%^YELLOW%^raise%^RESET%^ - betting command - see help betting\n"
+"%^BOLD%^%^YELLOW%^reveal hand%^RESET%^ - reveals your hand. Shouldn't be done until the dealer asks everyone to reveal their hands at the end of the game. Note: This will reveal the first set of cards in your hand. If you have cards other than the ones you were dealt, the other cards may be revealed. This could lead to you being accused of cheating. If you do this by mistake, you have a few seconds in which you can type 'correct' to put the mistake right (see below). If you do it on purpose, on your own head be it.\n"
+"%^BOLD%^%^YELLOW%^correct%^RESET%^ - corrects your error if you have revealed the wrong cards by mistake. You only have a few seconds in which to do this.\n\n"
+"See also: %^BOLD%^%^YELLOW%^help pokiir%^RESET%^, %^BOLD%^%^YELLOW%^help betting%^RESET%^";;
    break;
  default:
    return 0;
  }
  tell_object(TP, result);
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

int join_game(string str){
  if(str != "game"&&str != "pokiir game" && str != "card game"){
    tell_object(TP, " what?");
  }
  TP->set("last say", "");
  TP->force_me("say I'm in");
  call_out("add_player", 1 + random(1), TP);
  return 1;
}

int leave_game(string str){
  if (str != "game"){
    tell_object(TP, "Try '%^BOLD%^%^YELLOW%^leave game%^RESET%^'");
    return 1;
  }
  if(member_array(TP, players)==-1){
    tell_object(TP, "You're not currently in the game.");
    return 1;
  }
  TP->force_me("emote gets up and leaves the card table");
  eviction =1;
  evict_absentee(TP);
  return 1;
}

void next_bet(){
  object player;
  if (sizeof(players)<1){
    end_game();
  }
  if (sizeof(players)<next_better+1){
    next_better =0;
  }
  player = players[next_better];
  if (!objectp(ETO)||!present(player, ETO)){
    if(objectp(player)){
      evict_absentee(player);
    } else {
      cleanup_players();
    }
    call_out("next_bet", 1);
    return;
  }    
  if (all_bets_are_equal()==1 
          && bet_counter >= sizeof(players)-num_folders-num_allin){
    next_round();
  }
  if (stg < 4){
    if (member_array(player, folders)!= -1  ||
                       member_array(player, allin)!= -1){
      force_me("say " + player->QCN + " has folded, or is all in");
      if (all_folded()==1){
        return;
      }
      next_better ++;
      if (next_better > sizeof(players)-1){
        next_better = 0;
      }
      call_out("next_bet", 1);
      return;
    }
  } else {
    if (sizeof(players)==sizeof(revealers)+ sizeof(folders)){
      stg ++;
      force_me("say All hands are revealed, which means that");
      next_round();
    }
    if (member_array(player, folders)!= -1  ||
                       member_array(player, revealers)!= -1){
      force_me("say " + player->QCN + " has folded, or has already"
              +" revealed " + player->QP + " hand.");
      if (all_folded()==1){
        return;
      }
      next_better ++;
      if (next_better > sizeof(players)-1){
        next_better = 0;
      }
      call_out("next_bet", 1);
      return;
    }
  }
  if (stg == 5){
    force_me("say Time to reveal your hand " + player->QCN + ".");
  } else{
    force_me("say Your bet, " + player->QCN + "?");
  }
}

void next_round(){
  string result;
  int i;
  if (all_folded()==1){
    return;
  }
  num_allin = sizeof(allin);
  num_folders = sizeof(folders);
  switch(stg){
  case 0:
    deal();
    break;
  case 1:
    force_me("say Time to reveal the first of the community cards");
    force_me("flip card 1");
    force_me("flip card 2");
    force_me("flip card 3");
    break;
  case 2:
    force_me("say Time to reveal the next of the community cards");
    force_me("flip card 4");
    break;
  case 3:
    force_me("say Time to reveal the last of the community cards");
    force_me("flip card 5");
    break;
  case 4:
    force_me("say Time to reveal your hands!");
//    result = calculate_winner();
    return;
  case 5:
    calculate_winner();
    return;
//    force_me("say " + result);
  }
   if (sizeof(players)>2){
     next_better = 2;
   } else {
     next_better = 1;
   }
//  force_me("say current stage is: " + stg);
  if (stg<5){
    bet_counter = 0;
    stg++;
    next_bet();
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

int query_bet_limit(){
  return bet_limit;
}
mapping query_bets(){
  return bets;
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

int * query_hand_values(string * hand){
  int * highs, i, j, value;
  highs = allocate(5);
  highs[0] = query_card_value(hand[0]);
  for (i=1;i<5;i++){
    value = query_card_value(hand[i]);
    for (j=i;j>0;j--){
      if (value > highs[j-1]){
        highs[j] = highs[j-1];
        highs[j-1] = value;
      } else{ 
        highs[j] = value;
        break;
      }
    }
  }    
  return highs;
}

int query_high_card(string * hand, int num){//num=1st,2nd,3rd highest, etc)
  int * highs;
  highs = query_hand_values(hand);  
  return highs[num-1];
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
mapping query_max_bets(){
  return max_bets;
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

object * query_players(){
  return players;
}

int query_next_better(){
  return next_better;
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

int query_stg(){
  return stg;
}

void set_stg(int num){
  stg = num;
}

int set_limit(string str){
  int amount;
  if (sscanf(str, "limit %d", amount)!=1){
    return 0;
  }
  TP->force_me("emote mentions something to the dealer");
  if (stg >0){
    force_me("say Ah c'mon, I can't be changin' the bet limit while"
            +" there's a hand playin");  
    return 1;  
  }
  force_me("say Very well, the %^BOLD%^%^RED%^bet limit%^RESET%^ is now"
          +" set at: %^BOLD%^%^RED%^" + amount);
  bet_limit = amount;
  return 1;
}

void set_table_deck_id(){
  object table;
  if (!objectp(ETO)){
    return;
  }
  table = present("card table", ETO);
  if (!objectp(table)){
    table = new(TABLE);
    table->move(ETO);
  } 
  table->set_deck_id(deck_id);

}

int setup_bets(){
  int i;
  object chips,player, small_blinder, big_blinder;
  bets = ([]);
  if (sizeof(players)<2){
    return 0;
  }
  for (i=0;i<sizeof(players);i++){
    player = players[i];
    if (!present("chips", player)){
      tell_object(player, query_short() + " tells you that you need to"
       +" buy some chips before you can play.");
      tell_room(ETO, query_short() + " tells " +  player->QCN + " that"
        + player->QS + " needs to buy some chips before " 
        + player->QO + " can play.", players[i]);
      players -= ({player});
      continue;
    }
    if (present("chips", player)->query_val()<big_blind){
      tell_object(player, query_short() + " tells you that you need at"
       +" least " + big_blind + " chips before you can play.");
      tell_room(ETO, query_short() + " tells " +  player->QCN + " that"
        + player->QS + " at least " + big_blind + " chips before "
        + player->QO + " can play.", player);
      players -= ({player});
      continue;
    }
    bets[player] = 0;
    max_bets+=([player: present("chips", player)->query_val() ]) ;
  }
  small_blinder = players[1];
  big_blinder = players[0];
  tell_object(small_blinder, (string)TO->query_short() + " collects the small blind of " 
           + small_blind + " chips from you.");
  tell_room(ETO, (string)TO->query_short() + " collects the small blind of " + small_blind 
           + " chips from " + small_blinder->QCN, small_blinder);
  tell_object(big_blinder, (string)TO->query_short() + " collects the big blind of " 
           + big_blind + " chips from you.");
  tell_room(ETO, (string)TO->query_short() + " collects the big blind of " + big_blind 
           + " chips from " + big_blinder->QCN, players[0]);
  take_bet(small_blinder, small_blind);
  take_bet(big_blinder, big_blind);
  next_better ++;
  next_better ++;
  stg ++;
  return 1;
}
/*
int cheat(string str){
  object card1, card2, * people;
  string * pic1, * pic2, cheatstring;
  int i, flag, my_level, witness_level,witness_wis, result, conceal_skill,
       cheat;
  flag = 0;
  if (!objectp(ETO)){
    tell_object(TP, "ERROR: There's a problem with the room. Please tell a"
                   +" WIZ");
    return 1;
  }
  if (member_array(TP, revealers)!= -1){
    tell_object(TP, "You have already revealed your hand");
    return 1;
  }
  card1 = present("card", TP);
  card2 = present("card 2", TP);
  if (!objectp(card1)||!objectp(card2)){
    tell_object(TP, "You don't have two cards in your hand to reveal."
        +" You'll need to get some cards back in your inventory, or fold");
  }
  cheat = random(sizeof(CHEATYOU));
  cheatstring = CHEATYOU[cheat];
  people = all_living(ETO);
  conceal_skill = TP->query_nwp("concealment");
  my_level = TP->query_highest_level();
  reveal_hand(TP, card1, card2);
  tell_object(TP, CHEATME[cheat]);
  if (sizeof(people)>0){
    for(i=0;i<sizeof(people);i++){
      witness_level = people[i]->query_highest_level();
      witness_wis = people[i]->query_stats("wisdom");
      result = (my_level-witness_level)*5 + conceal_skill/2 
                                             - ((witness_wis - 11)* 2);
      if (result>95) result= 95;
      if (result<10) result = 10;
      if (random(100)+1 > result){
        if (people[i]==TO){
          force_me("emoteat " + TPQCN + " points at $N");
          force_me("say Hey! You cheated! Those cards aren't from my"
                  +" deck!");
          return 1;
        }
        tell_object(people[i], "You see that " + TPQCN + cheatstring);
      }
    }
  }
  return 1;
}
*/
int show_hand(string str){
  object card1, card2;
  card1 = present("card", TP);
  card2 = present("card 2", TP);
  if (member_array(TP, revealers)!= -1){
    tell_object(TP, "You have already revealed your hand");
    return 1;
  }
  if (str != "hand"){
    return 0;
  }
  if (!objectp(card1)||!objectp(card2)){
    tell_object(TP, "You need at least two cards to reveal your hand. You"
                   +" either need to find your cards, or fold");
    return 1;
  }
  if(!card1->id(deck_id)||!card2->id(deck_id)){
    tell_object(TP, "The first two cards in your inventory are not the"
       +" cards you were dealt. If you want to reveal them anyway, you"
       +" will need to %^BOLD%^%^YELLOW%^<cheat>%^RESET%^. If you decide"
       +" to cheat, you may get caught. The chances of someone noticing if"
       +" you cheat are based on:\nYour level\nThe level of each witness"
       +" present\nThe wisdom score of each witness\nYour concealment"
       +" skill, if any.\n The greatest possible"
       +" chance of getting away with it is 95%\n"
       +"The least possible chance of getting away with it is 10%\n"
       +"Note: these chances are determined for each witness present. The"
       +" more people there, the greater the chance of being found out."
       +" NPCs are always considered to be roughly equivalent in level to"
       +" the cheater");
    return 1;
  }
  reveal_hand(TP, card1, card2);
  return 1;
}
object * remove_duplicates(object * arr){
  int i;
  string * new_arr;
  new_arr = ({});
  if (sizeof(arr)<1){
    return new_arr;
  }
  for (i=0;i<sizeof(arr);i++){
    if (member_array(arr[i], new_arr)==-1){
      new_arr += ({arr[i]});
    }
  }
  return new_arr;
}
void reveal_hand(object player, object card1, object card2){
  string * pic1, * pic2, result;
  int i;
  pic1 = card1->query_card_pic();
  pic2 = card2->query_card_pic();
  player->force_me("emote reveals " + player->QO + " cards.");
  result = "";
  for (i=0;i<sizeof(pic1);i++){
    result += pic1[i];
    result += pic2[i];
    result += "\n";
  }
  tell_room(ETO, result);
  revealers += player;
}

int start_game(string str){
  if (str != "game"){
    tell_object(TP, "If you want the dealer to start a pokiir game, try"
                   +" '%^BOLD%^%^YELLOW%^start game%^RESET%^'.");
    return 1;
  }
  TP->force_me("emote indicates to the dealer that " + TP->QS + " wants to"
              +" get a game going");
  if (sizeof(hands)>0){
    if (stage>0){
      force_me("say There's a game already getting ready to go. Any folks"
              +" that want in jest ask me to join the game and I'll deal"
              +" you in.");
    } else {
      force_me("say There's a game already going. Any folks that want in"
              +" jest ask me to join the game and I'll deal you in next"
              +" hand");
    }
  } else {
    force_me("say Alright, let's get this game unnerway. Any folks that"
            +" want to play, jest ask me to deal you in.");
  }
  return 1;
}

int take_bet(object player,int amount){
  object chips;
  int bet;
  string playername;
  if (!objectp(player)){
    force_me("say Error with player. Abandoning bet");
    return -1;}
  playername = player->QCN;
  chips = present("chips", player);
  if (!objectp(chips)){
    force_me("say error with chips. Abandoning bet");
    return -1;}
  bet = bets[player];
  bet += amount;
  bets[player] = bet;
//force_me("say Setting " + playername + "'s bet to " + bet + ". " 
//          + playername + "'s bet is now " + bets[player]);
  chips->set_val((int)chips->query_val()-amount);
  winnings += amount;
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
