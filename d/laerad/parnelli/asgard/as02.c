//Coded by Bane//

#include <std.h>
#include "/d/laerad/laerad.h"

inherit ASGARD;

void create(){
    ::create();
/*   set_terrain(CITY);
   set_travel(PAVED_ROAD);
    set_name("Asgard entrance");
    set_short("Asgard entrance");
    set_long(
	"%^BOLD%^Excalibur street%^RESET%^
You have walked into the fabled city of Asgard.  A wide cobblestone "+
	"street continues far to the east.  To the north and south are "+
   "guard barracks where the king's militia stay in their defense of "+
	"the town.  To the west are the city gates."
    );
    set_property("indoors",0);
    set_property("light",2);
    set_property("no bump",1);
    set_smell("default","A cool breeze blows through the street.");
    set_listen("default","You hear the chatter of the city guards.");
*/
   set_long(::query_long()+"\nThe ruins of the city barracks stand to "
      "both the north and south, their towers cleaved short by some desctructive force.\n");
    set_exits( ([
	"east":"/d/laerad/parnelli/asgard/as03",
	"west":"/d/laerad/parnelli/asgard/as01",
	"north":"/d/laerad/parnelli/asgard/as13",
	"south":"/d/laerad/parnelli/asgard/as14"
    ]) );
//    set_pre_exit_functions( ({"west"}),({"go_west"}) );
}
int go_west(){
    tell_object(TP,"You walk through the city gates.");
    tell_room(ETO,""+TPQCN+" walks through the city gates.",TP);
    return 1;
}
