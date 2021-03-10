#include <std.h>
#include "crypt.h"
inherit ROOM;

#define Messages ({\
"You find yourself falling through darkness!",\
"As you fall further down it slowly begins to become lighter.",\
"You notice the figurine has fallen with you...",\
"As the figurine falls with you it begins to grow and MOVE!",\
"You can see the end of your fall coming up fast...",\
"With a THUD and an Ooofff your fall ends on a tunnel floor...",\
})

void create()
{
  ::create();
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("You are falling quickly through space.");
  set_long("You see the walls flying by and the tunnel floor rushing up to meet you!");
  set_listen("default", "Air rushes by as you fall down to meet the bottom.");
  set_exits( ([]) );
}
void do_fall(int x, object who) {
  int hurt;
  if(!who) return;
  if(environment(who) != this_object()) return;
  message("my_action", "%^BOLD%^%^RED%^ "+Messages[x]+" \n\n", who);
  x++;
  if(x < 6) call_out ("do_fall", 1, x, who); else {
  who->move_player("/d/koenig/town/crypt13");
  if(random(6) == 0) {
    tell_object((who), "\n You rub your bruises.\n");
    hurt = (int)who->query_hp();
    hurt = (hurt > 10) ? 10 : (hurt -1);
    who->do_damage("torso", hurt);
  }  else tell_object((who), "\n You rub your head.");
}
}
void start_fall(){
  if(!this_player()) return;
  call_out("do_fall", 1, 0, this_player());
}
