//Coded by Bane//
//added pre-exits to keep Commandos in to eliminate the need for their wander
//inherit - Styx 12/29/01

#include <std.h>
//inherit CROOM;
#include "/d/laerad/laerad.h"

inherit ASGARD;

void create(){
//    set_monsters(({"/d/laerad/mon/commando"}),({random(3)}));
    ::create();
/*
    set_repop(50);
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_name("Asgard entrance");
    set_short("Asgard entrance");
    set_long(
	"%^BOLD%^Asgard gate%^RESET%^
You have walked into the fabled city of Asgard.  A wide cobblestone "+
	"street leads to the northwest and southwest.  To the north and "+
   "south are guard barracks where the king's elite commandos stay in "+
	"their defense of the town and forest.  To the east are the city gates."
    );
    set_property("indoors",0);
    set_property("light",2);
    set_property("no bump",1);
    set_smell("default","A cool breeze blows through the street.");
    set_listen("default","It is oddly quiet.");
*/
    set_exits( ([
	"east":"/d/laerad/parnelli/asgard/as59",
	"northwest":"/d/laerad/parnelli/asgard/as56",
	"southwest":"/d/laerad/parnelli/asgard/as57",
	"north":"/d/laerad/parnelli/asgard/as60",
	"south":"/d/laerad/parnelli/asgard/as61"
    ]) );
//    set_pre_exit_functions( ({"east"}),({"go_east"}) );
}
/*
int go_east(){
    tell_object(TP,"You walk through the city gates.");
    tell_room(ETO,""+TPQCN+" walks through the city gates.",TP);
    return 1;
}
*/