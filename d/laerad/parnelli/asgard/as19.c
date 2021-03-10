//Coded by Bane//
#include <std.h>
#include "/d/laerad/laerad.h"

inherit ASGARD;

void create(){
    ::create();
/*   set_terrain(CITY);
   set_travel(BACK_ALLEY);
    set_name("Back alley");
    set_short("Back alley");
    set_long(
	"%^BOLD%^A back alley%^RESET%^
You are standing in a back alley.  The cobblestone street leads southeast "+
	"toward Wendigo street and further into the alley west.  You can see "+
	"the backs of a few houses to the south and the city wall to the "+
	"north.  Another guard tower is to the east."
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","A cool breeze blows through the street.");
    set_listen("default","The alley is very quiet.");
*/
    set_exits( ([
	"east":"/d/laerad/parnelli/asgard/tower3",
	"southeast":"/d/laerad/parnelli/asgard/as20",
	"west":"/d/laerad/parnelli/asgard/as18"
    ]) );
}
