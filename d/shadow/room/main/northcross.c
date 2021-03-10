// North Crossroads, Shadow
// Thorn@ShadowGate
// 970215
// City of Shadow 1997 revision
// northcross.c
// set no_clean & made repop watch only if they get too low *Styx*  1/6/05

#include <std.h>
#include "/d/shadow/room/shadow.h"

inherit CROOM ;

void create() {
    set_monsters( ({ "/d/shadow/mon/guardnew" }), ({random(3)+1}) );
    monster_party(40);
    ::create();
    set_travel(PAVED_ROAD);
    set_terrain(CITY);
	set_light(2);
	set_indoors(0);
  set_short("North Crossroads, Shadow");
  set_long(
@SHADOW
%^BOLD%^CYAN%^North Crossroads%^RESET%^
  The North Crossroads of the great City of Shadow is the stepping
off point for those seeking fame and glory in the northern realms of
the world.  The gate to the north beckons to you, with promises of 
greatness, and the lingering threat of a quick death in these expanses.
  To the south, you can see a road leading into the very center of the
city, while there is a road to the east and west skirting the north
walls.
SHADOW
);
    set_smell("default","You smell the cool fresh air.");
    set_listen("default","You hear the sounds of people moving around the city.");
set_exits(([
// "north" : "/d/shadow/room/city/northgate",
"north" : "/d/shadow/room/main/northgate",
"south" : "/d/shadow/room/main/garrison1",
"east" : ROOMDIR+"eroad1",
"west" : ROOMDIR+"wroad1"
   ]));
//   GUARD_D->watch_party(TO);
}

void reset(){
   ::reset();
        if(!present("street_light",TO))
                new(MISCDIR+"street_light")->move(TO);
}

