//Coded by Bane//
#include <std.h>
#include "/d/laerad/laerad.h"

inherit ASGARD;

void create(){
    ::create();
/*
   set_terrain(CITY);
   set_travel(BACK_ALLEY);
    set_name("Back alley");
    set_short("Back alley");
    set_long(
	"%^BOLD%^A back alley%^RESET%^
You are standing in a back alley.  Trash litters the street and dirty water "+
	"gushes down the sides of the road.  The cobblestone street leads into "+
	"another dark alley to the east and to a dead end to the west.  You notice "+
	"a few homeless people wandering through the alley."
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","A cool breeze blows through the street.");
    set_listen("default","The alley is very quiet.");
*/
    set_exits( ([
	"east":"/d/laerad/parnelli/asgard/as83"
    ]) );
}
/*
void reset(){
    ::reset();
    if(!present("urchin")){
	new("/d/laerad/mon/urchin")->move(this_object());
    }
}
*/