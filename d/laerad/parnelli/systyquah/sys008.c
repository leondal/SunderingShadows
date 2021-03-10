//Coded by Bane//
#include <std.h>
inherit CROOM;

void create(){
    set_monsters(({"/d/laerad/mon/trollt"}),({1}));
    ::create();
    set_terrain(VILLAGE);
    set_travel(DIRT_ROAD);
    set_name("Main street");
    set_short("Main street");
    set_long(
	"%^BOLD%^Main street%^RESET%^
You are standing on the central road of Systyquah.  The street "+
	"forks to the northeast and northwest here, leading into "+
	"the inner streets in the city.  You can see a few huts off to either "+
	"side of the road.  A few bonfires are lit near by, smoke pouring "+
	"into the sky."
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","The breeze carries a rank, nauseating smell.");
    set_listen("default","You hear the occasional scream of a troll war party.");
    set_exits( ([
	"south":"/d/laerad/parnelli/systyquah/sys009",
	"northeast":"/d/laerad/parnelli/systyquah/sys007",
	"northwest":"/d/laerad/parnelli/systyquah/sys006"
    ]) );
}
void reset(){
    ::reset();
/* changed to use CROOM  *Styx* 7/2002
    if(!present("thug")){
	new("/d/laerad/mon/trollt")->move(TO);
    }
*/
}
