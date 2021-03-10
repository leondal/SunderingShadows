//Coded by Bane//
#include <std.h>
#include "/d/laerad/laerad.h"

inherit ASGARD;

void create(){
    ::create();
/*   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
    set_name("Asgard barracks");
    set_short("Asgard barracks");
    set_long(
	"%^BOLD%^Asgard's barracks%^RESET%^
You are standing in the guards barracks.  A few bunks line the southern "+
	"wall, while two tables and numerous chairs take up the rest of the "+
	"room.  The city guards live here while on duty."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_property("no bump",1);
    set_smell("default","The barracks smell of old food and sweat.");
    set_listen("default","You hear the chatter of the city guards.");
*/
   set_long(::query_long()+"\nThe city barracks once stood here, evidenced "
      "by the shattered remains of the wooden bunks mixed in among the rubble.\n");
    set_exits( ([
	"southeast":"/d/laerad/parnelli/asgard/tower2",
	"north":"/d/laerad/parnelli/asgard/as02"
    ]) );
}
/*
void reset(){
    ::reset();
    if(!present("guard")){
	new("/d/laerad/mon/guard")->move(this_object());
	new("/d/laerad/mon/guard")->move(this_object());
	new("/d/laerad/mon/guard")->move(this_object());
    }
}
*/
