//Coded by Bane//
#include <std.h>
inherit CROOM;

void create(){
    set_monsters(({"/d/laerad/mon/trollp1"}),({1}));
    ::create();
    set_terrain(VILLAGE);
    set_travel(BACK_ALLEY);
    set_name("Dirt road");
    set_short("A dirt road");
    set_long(
        "%^BOLD%^A dirt road%^RESET%^
You are standing on one of the back roads of Systyquah.  The "+
        "street leads off to the east, west and north here.  "+
        "You can see a number of wood huts to either side of the "+
        "road.  You can see numerous trolls and other creatures "+
        "walking through the roads in troop formation, obviously "+
	"preparing for a huge battle."
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","The breeze carries a rank, nauseating smell.");
    set_listen("default","You hear the shouts of bugbears and troll war parties.");
    set_exits( ([
        "west":"/d/laerad/parnelli/systyquah/sys037",
        "east":"/d/laerad/parnelli/systyquah/sys035",
	"north":"/d/laerad/parnelli/systyquah/sys029"
    ]) );
}
void reset(){
    ::reset();
/* changed to use CROOM  *Styx* 7/2002
    if(!present("peasant")){
	new("/d/laerad/mon/trollp1")->move(this_object());
    }
*/
}

