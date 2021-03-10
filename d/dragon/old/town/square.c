inherit "std/room";
#include "../dragon.h"

void create()
{
  ::create();
  set_property("outdoors",0);
  set_property("light",2);
    set_short("Main square of Sanctuary");
  set("long","%^CYAN%^%^BOLD%^You are in the main square of %^RESET%^%^GREEN%^%^BOLD%^Sanctuary%^RESET%^%^CYAN%^%^BOLD%^.  All around you are people praying to the large statue that stands before you.  This place looks as though something terrible has ravaged the land.  Many people here are missing legs, arms, and various other limbs. %^RESET%^");
  set_exits(([ "south":"/d/dragon/town/roadS1",
       "down":"/d/dragon/town/coder",
               "north":"/d/dragon/town/roadN1",
                "east":"/d/dragon/town/roadE1",
                 "west":"/d/dragon/town/roadW1"]));
  set_items(([
  "plaque" : "This %^YELLOW%^golden plaque%^RESET%^ would fetch many gold coins at the market.  Too bad it's imbedded in granite.  There is some writing here."
]));
  set_invis_exits(({"down"}));
  set_pre_exit_functions(({"down"}),({"go_down"}));
}
void reset()
{
  ::reset();
  if(!present("monument"))
    new(MISCDIR +"monument")->move(TO);
}

int go_down() {
  if(this_player()->query_level() < 250 ) {
    write("You cannot go that way.");
    return 0;
  }
  return 1;
}
