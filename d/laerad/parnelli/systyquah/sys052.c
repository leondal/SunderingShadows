//Coded by Bane//
#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_terrain(VILLAGE);
    set_travel(BACK_ALLEY);
    set_name("Dirt road");
    set_short("A dirt road");
    set_long(
        "%^BOLD%^A dirt road%^RESET%^
You are standing on one of the back roads of Systyquah.  The "+
        "street leads off to the northwest, southwest and south here.  "+
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
        "southwest":"/d/laerad/parnelli/systyquah/sys054",
	"northwest":"/d/laerad/parnelli/systyquah/sys051",
	"south":"/d/laerad/parnelli/systyquah/sys118"
    ]) );
}
void reset(){
    ::reset();
    if(!present("bugbear")){
	new("/d/laerad/mon/bugbear")->move(this_object());
    }
    if(!present("peasant")){
	new("/d/laerad/mon/trollp1")->move(this_object());
    }
}
