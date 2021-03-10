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
  set_long("%^BOLD%^%^BLACK%^How strange, the deeper you tread beneath the ground, the less "+
"elegant and impressive this place looks. It is beginning to show some "+ 
"signs of %^RESET%^%^GREEN%^decay%^BOLD%^%^BLACK%^. It almost puts you at ease to see it begin to look the way, "+
"since it seems as if it should. However, be warned, adventurer, I wouldn't relax "+
"just yet. You can still hear someone playing an %^RESET%^organ%^BOLD%^%^BLACK%^ near by.");

  set_exits( ([
     "south" : "/d/koenig/town/crypt3",
     "southwest" : "/d/koenig/town/crypt6"
]) );
}

void init()
{
  ::init();
do_random_encounters( ({"/d/koenig/town/mon/skelcat.c"}),80,5);
}
