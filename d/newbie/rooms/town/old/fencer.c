#include <std.h>
#include "../../newbie.h"

inherit ROOM;
void create(){
    ::create();
    set_name("Back room of the bar");
    set_short("Back room of the bar");
    set_property("indoors",1);
    set_property("no sticks",1);
    set_property("no teleport",1);
    set_property("light", 1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_long(
@STYX
This room looks like it's mostly used for storage but also has a desk 
in one corner and some chests in another.  There are oil lamps hanging 
for lighting, but only one near the front is lit.  The shadows make it 
almost eerie in the back corner, especially toward a table and some 
chairs that sit partly behind a storage cabinet.
STYX
    );
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_property("no attack",1);
    set_listen("default","You can hear the chatter from the bar over the hushed voices.");
    set_smell("default","Rust, oil, and the gentle scent of candles heavily taint the air.");
    set_exits(([ "curtain" : MAINTOWN"wbar" ]));
}

void reset(){
    ::reset();
  if(!present("granstun"))
  new("/d/newbie/mon/granstun")->move(TO);
}
