#include <std.h>
#include "../defs.h"
inherit ROOM;

void create() {
    ::create();
    set_property("indoors",1);  
    set_property("light",1);
    set_travel(FOOT_PATH);
    set_terrain(NAT_TUNNEL);
    set_name("A tight tunnel");    
    set_short("%^RESET%^%^ORANGE%^A tight tunnel%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^The tunnel here is tight and very "
"restricted.  Despite the care at shoring up the walls with thick timbers "
"of wood, this passage has half way collapsed along its southern side.  "
"Clearly something gave way recently, hopefully nothing else does while "
"you're down here.%^RESET%^\n");
    set_smell("default","Dust fills the air, clogging your sense of smell.");
    set_listen("default","The creak and groan of the timbers carries through the dark passage.");

    set_items(([
      ({"cavein","collapse","tunnel"}) : "%^RESET%^%^ORANGE%^It looks as "
"though some of the timbers must not have been placed properly as part of "
"the wall had collapsed down upon the tunnel making it narrow and harder "
"to traverse.%^RESET%",
      ({"earth","stone"}) : "%^RESET%^%^ORANGE%^There is very little "
"stone here as most of the walls are made up of hard packed earth that is "
"secured by thick wooden beams.  What stone you can see appears in slabs "
"and shorn off formations that have been smoothed in order to help form "
"this tunnel.%^RESET%^",
      ({"soil","dirt"}) : "%^RESET%^%^ORANGE%^The occasional shifting of "
"loose soil can be seen falling from the ceiling or floors.  Clogging the "
"air with dust and causing you to wonder if this passage is indeed "
"safe.%^RESET%^",
      ({"beams","wood","timbers","timber","beam"}) : "%^RESET%^%^ORANGE%^"
"Apparently new, the wooden timbers have been carefully arranged to "
"provide structural support to the walls and ceiling of this passage.  "
"Thick bindings of rope attach these timbers to one another in some "
"places while others are held by wooden peg or tongue-n-groove "
"fastening.%^RESET%^",
      ({"walls","ceiling","floor"}) : "%^RESET%^%^ORANGE%^Carved from the "
"hard pack earth of the walls, floor and ceiling have been smoothed by "
"use of some tool or another.  Wooden beams are set ever dozen feet or so "
"with support beams crossing back and forth adding additional support to "
"the earth all around you.%^RESET%^",
    ]));

    set_exits(([
      "east" : TUNNEL"tonovi02",
      "southwest" : TUNNEL"tunnel26",
    ]));
}
