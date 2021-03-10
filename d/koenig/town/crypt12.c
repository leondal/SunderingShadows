#include <std.h>
#include "crypt.h"

inherit ROOM;


void create()
{
  ::create();
   set_travel(DIRT_ROAD);
   set_terrain(BUILT_TUNNEL);
  set_property("light", 0);
  set_property("indoors", 1);
  new("/d/koenig/town/items/pedastal1.c")->move(this_object());
  new("/d/koenig/town/items/figure1.c")->move(this_object());
  set_short("A Dark Room Beneath the Crypt");
  set_long("%^BOLD%^%^BLACK%^It would appear you have come to a dead end, but there is no Crypt Keeper to be found here. Instead, there is a small %^RESET%^%^CYAN%^crystal figurine%^BOLD%^%^BLACK%^ of a scorpion sitting on a strangly carved %^YELLOW%^pedestal%^BOLD%^%^BLACK%^. Hmmmm, maybe you can %^RESET%^take%^BOLD%^%^BLACK%^ the figurine and sell it. It must be worth a small fortune!%^RESET%^\n");
  set_exits( ([
     "east" : "/d/koenig/town/crypt11"
           ]) );
}

void init()
{
  ::init();
  add_action("take_figurine", "take");
}

int take_figurine(string str)
{
  if(!str)
    return notify_fail("What would you like to get!\n");
  if(lower_case(str) != "figurine")
    return notify_fail("You cant get that!\n");
  write("You grab hold of the figurine and suddenly the pedestal starts to "
        "sink into the floor with a rumble...uhoh!\n");
  say((string)TP->query_cap_name() + " grabs hold of the figurine and you can "
      "hear rumbling as the pedestal sinks into the floor...A TRAP!");
  write("The floor opens up and you find yourself falling fast!\n");
  if(!TP->move("/d/koenig/town/fall1"))
    environment(TP)->start_fall();
  return 1;
}


