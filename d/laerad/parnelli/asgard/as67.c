//Coded by Bane//
#include <std.h>
#include "/d/laerad/laerad.h"

inherit ASGARD;

void create(){
    ::create();
/*
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
    set_name("Central market square");
    set_short("Central market square");
    set_long(
	"%^BOLD%^Central market square%^RESET%^
You have walked into Asgard's central market square.  The streets are mobbed "+
	"with street vendors, peasants, guards and tourists from around the "+
	"realms.  The square extends for blocks in all directions.  You can "+
	"see hundreds of tents and carts set up alongside the roads."
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","A cool breeze blows through the street.");
    set_listen("default","The sound of hundreds of people talking surround you.");
*/
    set_long(::query_long()+"\nJudging from the relative lack of rubble, "
       "this seems to have once been part of Asgard's marketplace.\n");
    set_exits( ([
	"east":"/d/laerad/parnelli/asgard/as72",
	"north":"/d/laerad/parnelli/asgard/tower7",
	"west":"/d/laerad/parnelli/asgard/as63",
	"south":"/d/laerad/parnelli/asgard/as68"
    ]) );
}
/*
void reset(){
    ::reset();
    if(!present("peasant")){
	new("/d/laerad/mon/peasant1")->move(this_object());
    }
}
*/