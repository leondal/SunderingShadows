//Coded by Bane//
#include <std.h>
#include "/d/laerad/laerad.h"

inherit ASGARD;

void create(){
    ::create();
/*
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
    set_name("North Thunder road");
    set_short("North Thunder road");
    set_long(
	"%^BOLD%^North Thunder road%^RESET%^
You are on one of Asgard's central roads.  The cobblestone street leads east "+
	"into the inner city and southwest to Asgard's main road, Excalibur.  "+
	"You can see the backs of tall buildings and warehouses to the "+
	"north and a park off in the distance to the south."
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","A cool breeze blows through the street.");
    set_listen("default","Silence dominates this road.");
*/
    set_exits( ([
	"east":"/d/laerad/parnelli/asgard/as44",
	"southwest":"/d/laerad/parnelli/asgard/as08"
    ]) );
}
