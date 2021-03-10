#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",0);
    set_short("Shadowlord forest");
    set_terrain(HEAVY_FOREST);
    set_travel(FOOT_PATH);
    set_long(
@KAYLA
%^GREEN%^An old footpath meanders through this section of the forest.  The 
trees seem to be greener and much healthier here than what you can
see of the rest of the forest.  Even the undergrowth is more vibrant
as if something is healing this area of whatever ails the rest.  You
can see a clearing to the south among a stand of massive oak trees.
KAYLA
    );
    set_listen("default","Peculiar, the forest is deadly quiet.");
    set_exits(([
       "south":"/d/deku/open/dforest3-2",
       "north" : "/d/deku/open/dforest3"
    ] ));
    set_items(([
    ] ));
}
