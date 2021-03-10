//Coded by Bane//
#include <std.h>
inherit CROOM;

void create(){
    set_monsters(({"/d/laerad/mon/trollg2", "/d/laerad/mon/troll2", "/d/laerad/mon/troll2"}), ({1,1,1}));
    ::create();
    set_terrain(VILLAGE);
    set_travel(DIRT_ROAD);
    set_name("Systyquah entrance");
    set_short("Systyquah entrance");
    set_long(
	"%^BOLD%^A dirt road%^RESET%^
You have walked into the famous city of Trolls, Systyquah.  A long dirt "+
	"road continues to the north.  To the east and west are the "+
	"massive city walls, gates lead into either side.  To the south "+
	"are the Systyquah city gates."
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","The breeze carries a rank, nauseating smell.");
    set_listen("default","You hear the occasional scream of a troll war party.");
    set_exits( ([
	"east":"/d/laerad/parnelli/systyquah/sys094",
	"west":"/d/laerad/parnelli/systyquah/sys093",
	"north":"/d/laerad/parnelli/systyquah/sys018",
	"south":"/d/laerad/parnelli/systyquah/sys021"
    ]) );
    set_pre_exit_functions( ({"south"}),({"go_south"}) );
}
void reset(){
    ::reset();
/* changed to use CROOM  *Styx* 7/2002
    if(!present("guard")){
	new("/d/laerad/mon/trollg2")->move(TO);
	new("/d/laerad/mon/troll2")->move(TO);
	new("/d/laerad/mon/troll2")->move(TO);
    }
*/
}
int go_south(){
    tell_object(TP,"You walk through the city gates.");
    tell_room(ETO,""+TPQCN+" walks through the city gates.",TP);
    return 1;
}
