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
	"continues to the south and north.  To either side of the "+
	"road you can see small huts off in the distance.  You can see "+
	"an occasional bonfire also blazing away near the inner part of town."
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","The breeze carries a rank, nauseating smell.");
    set_listen("default","You hear the occasional scream of a troll war party.");
    set_exits( ([
	"north":"/d/laerad/parnelli/systyquah/sys002",
	"south":"/d/laerad/parnelli/systyquah/sys004",
    ]) );
}
