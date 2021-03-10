//Coded by Bane//
#include <std.h>
#include "/d/laerad/laerad.h"

inherit ASGARD;

void create(){
    ::create();
/*
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
    set_short("Wendigo street");
    set_short("Wendigo street");
    set_long(
	"%^BOLD%^Wendigo street%^RESET%^
You are in Asgard's residential area.  The cobblestone street leads north "+
	"along the residential district and south towards Asgard's main "+
	"road Excalibur.  You can see a few run down houses to the west, a "+
	"couple peasants sit on the steps of some of the homes."
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","A cool breeze blows through the street.");
    set_listen("default","You can hear the chatter of peasants.");
*/
    set_exits( ([
	"west":"/d/laerad/parnelli/asgard/as27",
	"north":"/d/laerad/parnelli/asgard/as21",
	"south":"/d/laerad/parnelli/asgard/as07"
    ]) );
}
/*
void reset(){
    ::reset();
    if(!present("peasant")){
	new("/d/laerad/mon/peasant")->move(this_object());
    }
}
*/