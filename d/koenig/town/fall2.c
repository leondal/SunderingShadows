#include <std.h>
#include "crypt.h"
inherit ROOM;

#define Messages ({\
"You are falling through darkness!",\
"The further you fall the darker it seems to get.",\
"darker...",\
"            darker...",\
"Can a pit in hell get any darker then this?!",\
"You are beginning to wonder if this trip will ever end...",\
"Oooofff! You find your eternal decent through darkness has come to a rather abrupt, if not painful end.",\
})
void create()
{
  ::create();
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
  set_property("light", 0);
  set_property("indoors", 1);
  set_short("You are falling through darkness.");
  set_long("You are surrounded by darkness.");
  set_listen("default", "You hear only the air rush by.");
  set_exits(([]));
}
void do_fall(int x, object who) {
  int hurt;
  if(!who) return;
  if(environment(who) != this_object()) return;
  message("my_action", "%^BOLD%^%^BLUE%^" +Messages[x]+ "\n\n", who);
  x++;
  if(x < 5) call_out ("do_fall", 1, x, who); else {
    who->move_player("/d/koenig/town/dungeon3");
  if(random(5) == 0) {
   tell_object((who), "\nYou rub your bruises.\n");
    hurt = (int)who->query_hp();
    hurt = (hurt > 10) ? 10 : (hurt -1);
    who->do_damage("torso", hurt);
  }  else tell_object((who), "\nYou rub your pride.\n");
}
}
void start_fall() {
  if(! this_player()) return;
  call_out("do_fall", 1, 0, this_player());
}
