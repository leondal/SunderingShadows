#include <std.h>
#include "/d/shadow/room/goblin/short.h"
inherit ROOM;
 
void create() {
    ::create();
    set_terrain(BARREN);
    set_travel(RUBBLE);
    set_property("no castle", 1);
    set_property("light", 2);
    set_short("%^BLUE%^Goblin Tower Roof%^RESET%^");
    set_long(
@STYX
%^BLUE%^You stand on top of the upper chamber of one of the small towers.
The roof is used by the %^CYAN%^goblin rangers%^BLUE%^ to scout the forests
surrounding the stronghold for intruders.  From here you have an 
excellent view of the %^GREEN%^vast forests%^BLUE%^ and %^MAGENTA%^fertile lands %^BLUE%^below.  The 
walls are falling into decay and %^RED%^blood %^BLUE%^is splattered everywhere.
Perhaps the weaker goblins have all been killed or gone into hiding.
STYX
    );
    set_smell("default","The forest smell is rich here.");
    set_listen("default","You hear rustling in the forest beneath you.");
    set_items(([
        "forest":"The forest around the stronghold is dark and dense and most "
	"likely filled with hundreds of goblins.",
    ]));
    set_exits(([
        "down": RPATH "tower2",
    ]));
}

void reset() {
    ::reset();
    if(!present("goblin")) 
    if(!random(5)) {
       switch(random(4)) {
         case 0:  new( MPATH "archer" )->move(TO);
         case 1:  new( MPATH "ranger" )->move(TO);
         case 2..3:  new( MPATH "ranger" )->move(TO);
         break;
       }
   }
}