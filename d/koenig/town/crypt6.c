#include <std.h>
#include "crypt.h"
inherit ROOM;

int blocked;

void init()
{
  ::init();
  add_action("play","play");
}

void create()
{
  ::create();
   set_terrain(BUILT_TUNNEL);
   set_travel(DIRT_ROAD);
  set_property("light", 1);
  set_property("indoors", 1);
new("/d/koenig/town/items/organ.c")->move(this_object());
  set_short("A Dark Room Beneath the Crypt");
  set_long("%^BOLD%^%^BLACK%^How very strange. This room has %^YELLOW%^torches%^BOLD%^%^BLACK%^ set around the room to give it "+
"some light. You notice sitting in the middle of "+
"the room is an %^RESET%^organ%^BOLD%^%^BLACK%^, a VERY old organ. It is the only other thing down "+
"here that looks to be in very well cared for condition. You also notice "+
"that there is someone or %^BOLD%^%^GREEN%^SOMETHING%^BOLD%^%^BLACK%^ playing it!%^RESET%^\n");
  set_exits( ([
     "east" : "/d/koenig/town/crypt3",
     "northwest" : "/d/koenig/town/crypt7",
     "southwest" : "/d/koenig/town/crypt8",
   "northeast" : "/d/koenig/town/crypt4",
     "down" : "/d/koenig/town/crypt10"
]) );
  set_pre_exit_functions( ({"down"}),({"go_down"}) );
  set_invis_exits( ({"down"}) );
}

void reset()
{
  ::reset();
  remove_exit("down");
  blocked = 0;
  if(!present("zombie"))
{
  new("/d/koenig/town/mon/zombie.c")->move(this_object());
}
}
  int play(string str) {
  if(!str || str != "organ") {
  notify_fail("Play what?\n");
  return 0;
}
  write("%^BOLD%^%^WHITE%^As you begin to play the organ flawlessly, it starts to slide to one side and reveals an exit down.%^RESET%^");
say(this_player()->query_cap_name()+" begins to play the organ flawlessly, in so doing a new exit is revealed as the organ slides to one side.", this_player());
  add_exit("/d/koenig/town/crypt10.c", "down");
  remove_invis_exit("down");
  blocked = 1;
  return 1;
}
string organ(string str) {
  if(blocked) return "You cannot play it.";
}


int go_down() {
  if(present("zombie")) {
  write("%^CYAN%^The zombie clumsily blocks your way. You can not pass!%^RESET%^");
  return 0;
 }
  return 1;
}
