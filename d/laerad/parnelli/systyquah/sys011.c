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
	"%^BOLD%^East Main street%^RESET%^
You are standing on one of the central roads of Systyquah.  The "+
        "street leads off to the west and southeast "+
        "here.  You can see a number of wood huts to either side "+
        "of the road.  A few bonfires are lit in the gutters of the "+
        "street, smoke pouring into the sky."
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","The breeze carries a rank, nauseating smell.");
    set_listen("default","You hear the shouts of bugbears and troll war parties.");
    set_exits( ([
        "west":"/d/laerad/parnelli/systyquah/sys009",
        "southeast":"/d/laerad/parnelli/systyquah/sys013"
	]) );
}
