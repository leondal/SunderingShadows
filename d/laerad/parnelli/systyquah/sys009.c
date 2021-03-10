//Coded by Bane//
#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_terrain(VILLAGE);
    set_travel(DIRT_ROAD);
    set_name("Main street");
    set_short("Main street");
    set_long(
	"%^BOLD%^Main street%^RESET%^
You are standing on the central road of Systyquah.  The street "+
	"leads to the east, west and north here.  "+
	"You can see a few huts off to either side of the "+
	"road.  A few bonfires are lit near by, smoke pouring "+
        "into the sky.  To the south lies a short wooden hut."
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","The breeze carries a rank, nauseating smell.");
    set_listen("default","You hear the occasional scream of a troll war party.");
    set_exits( ([
	"north":"/d/laerad/parnelli/systyquah/sys008",
	"west":"/d/laerad/parnelli/systyquah/sys010",
        "east":"/d/laerad/parnelli/systyquah/sys011",
        "south":"/d/laerad/parnelli/systyquah/portal"
    ]) );
}
