#include <../dragon.h>
#include <std.h>

inherit ROOM;

#define Messages ({\
  "You find yourself sliding through darkness and sewage.",\
  "The further you slide, the faster and faster you become.",\
  "The force is too powerful, you cannot breath.",\
   "You try gasping for air, but it's impossible.",\
  "SPLASH",\
  "All of a sudden you splash into a large pool of disgusting sewage!",\
  })

void create() {
  ::create();
  set_property("light", -3);
  set_property("indoors", 1);
   set_property("no teleport",1);
  set_short("Down a sewage pipe");
  set_long("You are sliding through a sewage pipe under the city of Sanctuary.");
  set_exits(([ ]));
}

void do_slide(int x, object who) {
  int hurt;
  if(!who) return;
  if(environment(who) != this_object()) return;
  message("my_action", "%^GREEN%^"+Messages[x]+" \n\n", who);
  x++;
  if(x < 6) call_out("do_slide", 1, x, who); else {
  who->move_player("/d/dragon/sewer/pool");
  who->do_damage("head", roll_dice(4,6));
  tell_object((who), "\n%^GREEN%^You look up and notice that the drain was some 40 feet up in the air.\n");
  return 1;
  }
}

void start_slide() {
  if(!this_player()) return;
  call_out("do_slide", 1, 0, this_player());
}
