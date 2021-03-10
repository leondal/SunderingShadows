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
	"gushes down the sides of the road.  The cobblestone street leads west "+
	"further into the alley and southeast towards the inner city.  You "+
	"see a guard tower to the northwest and the city wall to the north."
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","A cool breeze blows through the street.");
    set_listen("default","The alley is very quiet.");
*/
    set_exits( ([
	"southeast":"/d/laerad/parnelli/asgard/as62",
	"west":"/d/laerad/parnelli/asgard/as82",
	"northwest":"/d/laerad/parnelli/asgard/tower6"
    ]) );
}
