//Coded by Bane//
#include <std.h>
#include "/d/laerad/laerad.h"

inherit ASGARD;

void create(){
    ::create();
/*
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
    set_name("Nirvana avenue");
    set_short("Nirvana avenue");
    set_long(
	"%^BOLD%^Nirvana avenue%^RESET%^
You are in Asgard's residential area.  The cobblestone street leads southeast "+
	"into a back alley and north towards Asgard's main street Excalibur.  "+
	"You can see a few run down houses to the east and a small path to "+
	"the northwest leads towards a guard tower.  The city wall is to the "+
	"south."
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","A cool breeze blows through the street.");
    set_listen("default","You can hear the chatter of peasants.");
*/
    set_exits( ([
	"east":"/d/laerad/parnelli/asgard/as38",
	"southeast":"/d/laerad/parnelli/asgard/as31",
	"northwest":"/d/laerad/parnelli/asgard/tower2",
	"north":"/d/laerad/parnelli/asgard/as29"
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