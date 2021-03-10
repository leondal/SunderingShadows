//Coded by Bane//
#include <std.h>
#include "/d/laerad/laerad.h"

inherit ASGARD;

void create(){
    ::create();
/*
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
    set_name("South Thunder road");
    set_short("South Thunder road");
    set_long(
	"%^BOLD%^South Thunder road%^RESET%^
You are on one of Asgard's central roads.  The cobblestone street leads east "+
	"into the inner city and northwest to Asgard's main road, Excalibur.  "+
	"You can see the backs of tall buildings and warehouses to the "+
	"south and a park off in the distance to the north."
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","A cool breeze blows through the street.");
    set_listen("default","Silence dominates this road.");
*/
    set_exits( ([
	"east":"/d/laerad/parnelli/asgard/as45",
	"northwest":"/d/laerad/parnelli/asgard/as08"
    ]) );
}
