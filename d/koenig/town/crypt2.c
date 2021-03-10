#include <std.h>
#include "crypt.h"
inherit ROOM;

void create()
{
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("light", 1);
  set_property("indoors", 1);
  new("/d/koenig/town/items/goldpouch.c")->move(this_object());
  set_short("A Dark Room Beneath the Crypt");
  set_long("%^BOLD%^%^BLACK%^Talk about your spooky hangouts! While descending the stairs, you "+
"notice the walls are made of %^RESET%^%^ORANGE%^wood%^BOLD%^%^BLACK%^, not dirt like one would expect. The "+
"wood is of very high quality and well cared for, something else you would "+
"not expect. By this time the %^RESET%^Crypt Keeper%^BOLD%^%^BLACK%^ really has you "+ 
"wondering what he is like... Or, perhaps, what he IS. What self-respecting %^RESET%^%^CYAN%^monster%^BOLD%^%^BLACK%^ actually keeps "+
"a house? Hmmmm, I think you're in trouble, my friend. You have come to a "+ 
"landing and your only way is %^RESET%^down%^BOLD%^%^BLACK%^, or you could try to open that crypt "+ 
"door again.%^RESET%^\n");
   set_smell("default", "The air in here is a bit more refreshing than up above.");
  set_listen("default", "You hear someone playing an organ down below.");
  set_items( ([
     "wall" : "They are highly polished and well kept.",
     "stairs" : "They are carpeted.",
     "carpet" : "It is the color of blood."
]) );
  set_exits( ([
     "down" : "/d/koenig/town/crypt3"
]) );
}
void init()
{
  ::init();
}
int get_pouch(string str)
{
  if(!str)
  return notify_fail("You want to take what?\n");
    //  if(lower_case(str) != "pouch")
    if(!id(lower_case(str)))
  return notify_fail("You cant take that!\n");
  write("%^YELLOW%^You will pay for being so %^RESET%^%^ORANGE%^greedy%^YELLOW%^, adventurer!");
  say((string)TP->query_cap_name()+" has activated a trap because of their greed!");
  write("%^BOLD%^%^BLACK%^The floor beneath you suddenly opens up and swallows you into the darkness!%^RESET%^");
  if(!TP->move("/d/koenig/town/fall3"))
  environment(TP)->start_fall();
  return 1;
}
