#include <std.h>
inherit ROOM;



void create()
{
  ::create();
   set_terrain(BUILT_TUNNEL);
   set_travel(DIRT_ROAD);
  set_property("light", 0);
  set_property("indoors", 1);
  set_short("A Dark Room Beneath the Crypt");
  set_long("%^BOLD%^%^BLACK%^Yep, these rooms further in are less %^RESET%^%^CYAN%^unnerving%^BOLD%^%^BLACK%^ than the "
         "staircase. The further in you go, the more the place is in "
           "%^RESET%^disrepair%^BOLD%^%^BLACK%^ and %^RESET%^decay%^BOLD%^%^BLACK%^. Walk carefully, friend, for there is no telling "
      "what all lies within this place. You can hear someone playing an "
           "%^RESET%^%^ORANGE%^organ%^BOLD%^%^BLACK%^ down here, maybe you should follow the %^MAGENTA%^music%^BOLD%^%^BLACK%^...%^RESET%^\n");
  set_exits( ([
     "north" : "/d/koenig/town/crypt3",
     "northwest" : "/d/koenig/town/crypt6"
           ]) );
}

void init()
{
  ::init();
do_random_encounters( ({"/d/koenig/town/mon/skelcat"}),80,5);
}
