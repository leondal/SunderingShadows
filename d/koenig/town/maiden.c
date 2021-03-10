#include <std.h>
inherit ROOM;

void create()
{
  ::create();
   set_terrain(MEADOWLANDS);
   set_travel(DIRT_ROAD);
  set_property("light", 1);
  set_property("outdoors", 1);
  set_short("Near a Pool");
  set_long("%^RESET%^%^CYAN%^You find yourself standing next to the %^BOLD%^%^BLUE%^clear pool%^RESET%^%^CYAN%^ gazing at your reflection. "+ 
  "As you gaze back, you notice, behind yourself, a fresh grave with a headstone and "+
"beyond that the beautiful %^BOLD%^%^WHITE%^snow capped mountains%^RESET%^%^CYAN%^. Standing here you get a very "+
"eerie feeling as you realize this spot where you are standing is exactly where "+
"the maiden was sitting, looking into the pool.%^RESET%^");
  set_smell("default", "The scent of wild flowers is almost overwhelming.");
  set_listen("default", "You hear nothing but the light breeze dancing among the wild flowers.");
  set_items( ([
     "grave" : "It is very fresh indeed. It looks as if someone was just buried.",
     "headstone" : "This headstone is more like a statue. It perfectly resembles the maiden you saw, sitting just as you saw her, but now she looks off into the distance. At the bottom of this headstone is a plaque.",
     "pool" : "It looks very clear and refreshing. You find you have an urge to take a swim.",
     "plaque" : "%^BOLD%^Here lies the maiden of the pool. Killed by unseen and unknown enemies. May she forever rest in peace.%^RESET%^"
]) );
}
void init () {
  ::init();
  add_action("swim", "swim");
}
int swim(string str) {
  write("You slip into the pool with ease and begin to swim across its surface.");
  say("You see "+TPQCN+" slip into the pool and begin to swim across its surface.");
  TP->move_player("/d/koenig/town/pool1");
  return 1;
}
