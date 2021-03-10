#include <std.h>
#include "../defs.h"
inherit VAULT;

void create() {
    ::create();
    set_property("indoors",1);
    set_property("light",1);
    set_travel(FOOT_PATH);
    set_terrain(ROCKY);
    set_name("A earthen basement");
    set_short("A earthen basement");
    set_long("%^RESET%^%^ORANGE%^You find yourself standing in what "
"appears to be a basement carved out of the earth.  Thick timbers are set "
"around the walls, supporting the earth.  They appear to be in good "
"repair, though an occasional shift of soil does give you cause to "
"wonder.  To the west you can see that at least one beam has given way "
"and a partial colapse has occurred in a tunnel leading away.  Still, it "
"has been cleared a little, and you think you might be able to travel "
"through.%^RESET%^\n");
    set_smell("default","Dust fills the air, clogging your sense of smell.");
    set_listen("default","You can hear the sound of someone moving above you.");

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
      "west" : TUNNEL"tonovi01",
      "up" : "/d/dagger/tonovi/tower1",
        "down":"/d/shadow/ratpaths/rooms/rp_p031_p010",
    ]));
    set_invis_exits(({"down"}));
    set_search("default", "You find a hatch with ladder leading down behind some rubble.");
    set_door("trapdoor","/d/dagger/tonovi/tower1","up",0);
    set_door_description("trapdoor", "%^BOLD%^%^BLACK%^This iron and wood door leads back up to the surface and out of the basement.%^RESET%^");
}
