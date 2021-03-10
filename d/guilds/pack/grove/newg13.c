#include <std.h>
#include "/d/guilds/pack/short.h"
inherit ROOM;
void create(){
    ::create();
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
/*}
void init(){
    ::init();
   if(random(10) == 1) {
      set_short("%^BLACK%^Shoikan Grove exit");
      set_long(
@SEETH
%^BLACK%^You are following a path in the grove%^RESET%^
%^BLUE%^The grove is very dark as if a large shadow has descended upon the area. The shadow surrounded it by day and night because of the huge oak trees. There seems to be many different paths you can take. Each direction seems the same, you think that you can get lost in here easily.
SEETH
      );
    set_exits(([
      "north" : GROVE "gate.c",
      "south" : GROVE "g3.c",
      "east" : GROVE "g17.c",
      "west" : GROVE "g12.c",
    ]));
    return 1;
    }
    //if((string)TP->query_guild() == "Shadows of Fate"){
    else{*/
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
    //return 1;
}	/*else {
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
    return 1;
    }
}*/
