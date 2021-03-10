//Coded by Bane//
#include <std.h>
#include "/d/laerad/laerad.h"

inherit ASGARD;

void create(){
    ::create();
/*
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
    set_name("Excalibur street");
    set_short("Excalibur street");
    set_long(
	"%^BOLD%^Excalibur street%^RESET%^
You are on Asgard's main city road.  The cobblestone street leads west "+
	"to the city gates and east towards the inner city.  To the north and "+
	"south are the sides of buildings in the residential districts.  You "+
	"see a few strings running down the sides of the buildings with clothes "+
	"hanging from them."
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","A cool breeze blows through the street.");
    set_listen("default","Silence dominates this road.");
*/
    set_exits( ([
	"west":"/d/laerad/parnelli/asgard/as04",
	"east":"/d/laerad/parnelli/asgard/as06"
    ]) );
}
