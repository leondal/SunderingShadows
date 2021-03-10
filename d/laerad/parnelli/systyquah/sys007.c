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
	"forks to the northwest and southwest here, leading into "+
	"the inner streets in the city.  You can see a few huts off to either "+
	"side of the road.  A few bonfires are lit near by, smoke pouring "+
	"into the sky."
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","The breeze carries a rank, nauseating smell.");
    set_listen("default","You hear the occasional scream of a troll war party.");
    set_exits( ([
	"east":"/d/laerad/parnelli/systyquah/sys056",
	"northwest":"/d/laerad/parnelli/systyquah/sys005",
	"southwest":"/d/laerad/parnelli/systyquah/sys008"
    ]) );
}
