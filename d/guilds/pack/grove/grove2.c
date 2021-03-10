#include <std.h>
#include "/d/guilds/pack/short.h"
inherit ROOM;
void create(){
    ::create();
   set_terrain(HEAVY_FOREST);
   set_travel(FOOT_PATH);
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
}
void init(){
    ::init();
   if(random(10) == 1) {
   set_short("%^BOLD%^%^BLACK%^Shoikan Grove exit%^RESET%^");
      set_long(
@SEETH
%^BOLD%^%^BLACK%^You are following a path in the grove.%^RESET%^
 %^BLUE%^The grove is very dark as if a large shadow has descended upon the area. The shadows surround it by day and night because of the huge oak trees. There seems to be many different paths you can take. Each direction seems the same, you think that you can get lost in here easily.
SEETH
      );
    set_exits(([
      "north" : GROVE "gate.c",
      "south" : GROVE "g3.c",
      "east" : GROVE "g17.c",
      "west" : GROVE "g12.c",
    ]));
    }
    if((string)TP->query_guild() == "Shadows of Fate"){
    set_name("Gates to Destiny Keep");
    set_short("%^BLACK%^Shoikan Grove exit");
    set_long(
@SEETH
%^BLACK%^You are following a path toward Destiny Keep%^RESET%^
%^BLUE%^The grove is very dark as if a large shadow has descended upon the area. The shadow surrounded it by day and night because of the huge oak trees. There seems to be many different paths you can take. Each direction seems the same, except to the north. Towards the north, you can see a silhouette of a fortress.
SEETH
    );
    set_items( ([
   ]) );
    set_exits(([
      "north" : GROVE "gate.c",
      "south" : GROVE "g3.c",
      "east" : GROVE "g17.c",
      "west" : GROVE "g12.c",
    ]));
    } else {
    set_short("%^BLACK%^Shoikan Grove");
    set_long(
@SEETH
%^BLACK%^You are following a path in the grove.%^RESET%^
%^BLUE%^The grove is very dark as if a large shadow has descended upon the area.
The shadow surrounded it by day and night because of the huge oak trees.
There seems to be many different paths you can take. Each direction seems
the same, you think that you can get lost in here easily.
SEETH
    );
    set_exits(([
      "north" : GROVE "g2.c",
      "south" : GROVE "g3.c",
      "east" : GROVE "g17.c",
      "west" : GROVE "g12.c",
    ]));
    }
}
