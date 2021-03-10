//Coded by Bane//
#include <std.h>
#include "/d/laerad/laerad.h"

inherit ASGARD;

void create(){
    ::create();
/*
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
    set_name("Excalibur and Wendigo crossroad");
    set_short("Excalibur and Wendigo crossroad");
    set_long(
	"%^BOLD%^Excalibur and Wendigo crossroad%^RESET%^
You are on Asgard's main city road.  The cobblestone street leads west "+
   "to the city gates and east towards the inner city.  Asgard's "+
	"residential districts lie to the north and south.  You can see a few "+
	"peasants on the steps of their homes."
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","A cool breeze blows through the street.");
    set_listen("default","You can hear the chatter of peasants.");
*/
    set_exits( ([
	"west":"/d/laerad/parnelli/asgard/as06",
	"east":"/d/laerad/parnelli/asgard/as08",
	"north":"/d/laerad/parnelli/asgard/as22",
	"south":"/d/laerad/parnelli/asgard/as35"
    ]) );
}
