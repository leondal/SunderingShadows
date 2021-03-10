//sroom
#include <std.h>
#include <rooms.h>
#include "../yntala.h"
inherit CROOM;

void create(){
::create();
   set_property("indoors",1);
   set_property("light",-3);
   set_property("no teleport",1);
   set_terrain(VILLAGE);
   set_travel(PAVED_ROAD);
   set_name("%^RESET%^The summoning room");
   set_short("%^RESET%^The inside of a pyramid%^RESET%^");
   set_listen("default","Whispers and soft hisses seem to float upon the stale air.");
   set_long("%^BOLD%^%^BLACK%^This dark room is large and circular.  What appears to have once been a pentagram"
" has been etched into the center of the room, but it is worn out and hard to see now.  The walls are completely"
" smooth and void of any decoration at all.  Seven candle holders have been set into the floor and each of them "
"still hold a candle.%^RESET%^");
   set_items(([
   "pentagram":"It is to difficult to make out the old drawing except for a few light lines here and there.",
   "candles":"The candles still stand upright and unlit in the holders.",
   "candle holders":"Seven candle holders are set within the floor at what seems to have once been the points of the pentagram.  Each holder still holds a candle.",
]));
   set_exits((["north":INRMS+"hall7"]));
}
void reset() {
   ::reset();
   query_exit("portal");
   remove_exit("portal");
}
void init(){
  ::init();
  add_action("light","light");
}
int light(string str){
   if(str == "candles"||str=="the candles"){
      tell_object(TP,"%^BOLD%^%^CYAN%^You reach down and light the candles one by one.  The pentagram begins to glow and a glowing portal appears in the center of the room!%^RESET%^");
      tell_room(TO,"%^BOLD%^%^CYAN%^"+TPQCN+" reaches down and lights the candles one by one.  The pentagram begins to glow and a large, glowing portal appears in the center of the room!",TP);
      add_exit(INRMS+"lepland","portal");
      return 1;
   }
}
