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
        "street leads off to the northwest, northeast and southwest "+
        "here.  You can see a number of wood huts to either side of "+
        "the road.  A few bonfires are lit in the gutters of the "+
        "street, smoke pouring into the sky."
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","The breeze carries a rank, nauseating smell.");
    set_listen("default","You hear the shouts of bugbears and troll war parties.");
    set_exits( ([
        "northeast":"/d/laerad/parnelli/systyquah/sys015",
        "southwest":"/d/laerad/parnelli/systyquah/sys018",
	"northwest":"/d/laerad/parnelli/systyquah/sys019"
    ]) );
}
