// Ferryboat v2
// Thorn@ShadowGate
// 14 June 2000
// nabatferry.c
//
// Path commands:
// north or n = steer north
// south or s = steer south
// east or e = steer east
// west or w = steer west
// dock or d = steer dock
// out or o = steer out
// wait or t = wait 60
// To repeat a direction x amount of times put a number 
// before the command.  (ie.  west 9 times would be "9w" or "9west"

#include <std.h>
#define PATH ({"t","o","9s","2e","d","t","o","w",\
               "2s","2w","d","t","o","e","11n",\
			   "d"})
#define START_ROOM "/d/verhedin/virtual/wadi/0,2.wadi"
                 
inherit OBJECT;

object interior;

int clean_up(){return 1;}

void create(){
  ::create();
  set_id(({ "ferry","boat","ship" }));
  set_short("the Nabat Ferry");
  set_long(
@FERRY
This is a ferry boat that runs from Nabat Ferry and makes
stops at Fortress Quay, Verhedin City Docks and Nabat Ferry.
The cost for a ferry ride is a mere 5 gp.
Once you pay for nabat ferry, you will be let on the boat.
FERRY
);
  set_weight(10000);
  interior = find_object_or_load("/d/verhedin/virtual/wadi/obj/ferryroom");
  interior->set_room(START_ROOM);
  interior->set_path(PATH);
}

void init(){
  ::init();
  add_action("pay","pay");
}

void remove() {
  ::remove();
  if(interior) { interior->remove(); }
}

int pay(string str){
  string coin;
  int amount,inc,riders;
  object *ob;

  if(!str) return notify_fail("Pay for what?\n");
  if(str != "for nabat ferry")
    return notify_fail("Try <pay for nabat ferry>!\n");
  if(!TP->query_funds(coin, amount))
    return notify_fail("You don't have 5 gold to pay!\n");
  TP->use_funds("gold",5);
  write(
@BOARD

%^BOLD%^A riverman takes 5 gold from your hand, and drops it
into his pocket. He then waves you onto the ferry, and turns
away.%^RESET%^
BOARD
  );
  tell_room(environment(TO),TPQCN+" pays the riverman some money, and is allowed onto the ferry.",TP);
  tell_room(environment(TO),"The riverman yells out: Ferry leaves in one minute!");
  TP->move_player(interior);
  return 1;
}
