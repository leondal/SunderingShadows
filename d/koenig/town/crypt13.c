#include <std.h>
#include "crypt.h"
inherit ROOM;

void create()
{
  ::create();
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
   set_property("light", 0);
  set_property("indoors", 1);
  set_short("A Dark Room Beneath the Crypt");
  set_long("%^BOLD%^%^BLACK%^Your fall downward comes to an abrupt end! You find yourself further below the %^RESET%^damp%^BOLD%^%^BLACK%^ and %^RESET%^%^GREEN%^decaying%^BOLD%^%^BLACK%^ surface of both the crypt and graveyard. The %^RESET%^%^CYAN%^stench%^BOLD%^%^BLACK%^ is almost overpowering. There is some light here due to a few %^YELLOW%^torches%^BOLD%^%^BLACK%^ set in the wall, but at the moment the only thing that catches your eye is the torch light that dances across the now 6-foot long, huge %^BOLD%^%^GREEN%^crystal figurine%^BOLD%^%^BLACK%^ of the scorpion. Even worse, IT IS MOVING!%^RESET%^\n");
  set_smell("default", "The stench here of the undead is almost overwhelming!");
  set_listen("default", "The sound of crystal clanking softly against itself and stone.");
  set_pre_exit_functions(({"east"}),({"go_east"}));
  set_exits( ([
     "east" : "/d/koenig/town/crypt14.c"
]) );
}
void reset()
{
  ::reset();
  if(!present("crystal scorpion"))
{
  new("/d/koenig/town/mon/crysmon1.c")->move(this_object());
  }
}

int go_east() {
if(present("crystal scorpion")) {
write("%^BOLD%^%^CYAN%^It will not let you pass!%^RESET%^");
return 0;
}
return 1;
}
