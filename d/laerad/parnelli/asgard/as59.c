//Coded by Bane//
#include <std.h>

//inherit CROOM;
#include "/d/laerad/laerad.h"

inherit ASGARD;

void create(){
//    set_monsters( ({"/d/laerad/mon/commando"}),({1}) );
    ::create();
/*
    set_repop(50);
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
    set_name("City of Asgard");
    set_short("Asgard's Gate");
    set_long(
   "You stand before Asgard's massive city gates.  The walls surrounding "+
	"the city look to be at least 20 feet tall.  Towers line the walls, every "+
	"now and then someone pokes their head out scoping the terrain and forest "+
	"outside the city.  The gates to the city are cracked open, perhaps "+
	"bidding you welcome, or perhaps trouble."
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","A clean, fresh wind blows about.");
    set_listen("default","You can hear the rustle of the city inside the gates.");
*/
    set_long(::query_long()+"\nEerily, the gates here stand largely untouched, "
       "though there is little left for them to guard.\n");
    set_exits( ([
	"east":"/d/laerad/parnelli/forest/for070",
	"west":"/d/laerad/parnelli/asgard/as58"
    ]) );
//    set_pre_exit_functions( ({"west"}),({"go_west"}) );
}
/*
int go_west(){
    tell_object(TP,"You walk through the cities gates.");
    tell_room(ETO,""+TPQCN+" walks through the city gates.",TP);
    return 1;
}
*/
