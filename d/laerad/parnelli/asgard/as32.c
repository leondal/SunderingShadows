//Coded by Bane//
#include <std.h>
#include "/d/laerad/laerad.h"

inherit ASGARD;

void create(){
    ::create();
/*
   set_travel(BACK_ALLEY);
   set_terrain(CITY);
    set_name("Back alley");
    set_short("Back alley");
    set_long(
	"%^BOLD%^A back alley%^RESET%^
You are standing in a back alley.  The cobblestone street leads northeast "+
	"toward Wendigo street and further into the alley west.  You can see "+
	"the backs of a few houses to the north and the city wall to the "+
	"south.  Another guard tower is to the east."
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","A cool breeze blows through the street.");
    set_listen("default","The alley is very quiet.");
*/
    set_exits( ([
	"east":"/d/laerad/parnelli/asgard/tower4",
	"northeast":"/d/laerad/parnelli/asgard/as33",
	"west":"/d/laerad/parnelli/asgard/as31"
    ]) );
}
