#include <std.h>
#include "/d/guilds/pack/short.h"

inherit ROOM;

void create() {
    ::create();
   set_terrain(HEAVY_FOREST);
   set_travel(FOOT_PATH);
    set_property("light", 0);
    set_property("indoors", 0);
    set_property("no teleport", 1);
   set_short("%^BOLD%^%^BLACK%^Shoikan Grove%^RESET%^");
    set_long(
@SEETH
%^BOLD%^%^BLACK%^You are following a path in the grove.%^RESET%^
 %^BLUE%^The grove is very dark as if a large shadow has descended upon the area. The shadows surround it by day and night because of the huge oak trees. There seems to be many different paths you can take. Each direction seems the same, you think that you can get lost in here easily.
SEETH
    );
    set_items( ([

      ]) );
    set_exits( ([
    "south" : GROVE "g4.c",
    "north" : GROVE "g17.c",
    "east" : GROVE "g20.c",
    "west" : GROVE "g3.c",
      ]) );


}
