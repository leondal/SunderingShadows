//Coded by Bane//
#include <std.h>
inherit CROOM;

void create(){
    set_monsters(({"/d/laerad/mon/trollg2", "/d/laerad/mon/trollp1"}),({1, 1}));
    ::create();
    set_terrain(VILLAGE);
    set_travel(BACK_ALLEY);
    set_name("Dirt road");
    set_short("A dirt road");
    set_long(
        "%^BOLD%^A dirt road%^RESET%^
You are standing on one of the back roads of Systyquah.  The "+
        "street leads off to the west, east and north here.  "+
        "You can see a large wooden hut to the east side of the "+
        "road.  You can see numerous trolls and other creatures "+
        "walking through the roads in troop formation, obviously "+
	"preparing for a huge battle."
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","The breeze carries a rank, nauseating smell.");
    set_listen("default","You hear the shouts of bugbears and troll war parties.");
    set_exits( ([
        "east":"/d/laerad/parnelli/systyquah/hut04",
        "west":"/d/laerad/parnelli/systyquah/sys079",
	"north":"/d/laerad/parnelli/systyquah/sys031"
    ]) );
}
void reset(){
    ::reset();
/* changed to use CROOM  *Styx* 7/2002
    if(!present("troll")){
	new("/d/laerad/mon/trollp1")->move(this_object());
	new("/d/laerad/mon/trollg2")->move(this_object());
    }
*/
}
