#include <std.h>
inherit ROOM;

void create()
{
  ::create();
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
  set_property("light", 0);
  set_property("indoors", 1);
  set_short("A Dark Crossroads Beneath the Crypt");
  set_long("%^BOLD%^%^BLACK%^Well adventurer, you have made it rather far and now you find yourself at a crossroad... Or should I say a crosstunnel? There are several %^RESET%^boulders%^BOLD%^%^BLACK%^ scattered about.. You have four directions you can go, but only three new ones. One of them will surely lead you to the %^RED%^Crypt Keeper%^BOLD%^%^BLACK%^. Choose your direction wisely, my friend, for you are %^RESET%^very%^BOLD%^%^BLACK%^ close to his lair.%^RESET%^\n");
  set_smell("default", "You are overwhelmed by the stench of death here.");
  set_listen("default", "You can hear noises coming from all four directions.");
  set_exits( ([
     "east" : "/d/koenig/town/crypt15",
     "north" : "/d/koenig/town/crypt16",
     "south" : "/d/koenig/town/crypt17",
     "west" : "/d/koenig/town/crypt13"
]) );
}

void init()
{
  ::init();
do_random_encounters( ({"/d/koenig/town/items/boulder.c"}),50,5);
}
