//	castleCH1.c
//	Pator@Shadowgate
//      Thu 11 May 1995
#include <castle.h>

inherit ROOM;

void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_light(1);
    set_indoors(1);
    set_short("Inside the chapel");
    set_long(
@PATOR
You are inside the chapel and you see lots of wooden benches for sitting and kneeling. There is music here and there are lots of candles lit. Also a statue of St. Anton is here as a patronage of this chapel. However there doesn't seem to be an altar !
PATOR
    );
set_smell("default","You smell incense and candlewax.");
set_listen("default","You hear churchmusic.");
    set_exits(([
       "east"  : CASTLE+"castleE5.c",
       "west"  : CASTLE+"castleCH2.c" 
    ] ));
    set_items(([
       "wall" : "The walls are made from stone and are very thick.",
       "walls" : "The walls are made from stone and are very thick.",
       "candles" : "They are in great quantities and they are all lit.",
       "statue" : "It is depicting St. Anton the most famous priest in his days.",
       "St. Anton" : "A statue depicting this most famous priest."
    ] ));
}
