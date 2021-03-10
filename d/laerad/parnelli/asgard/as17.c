//Coded by Bane//
#include <std.h>
#include "/d/laerad/laerad.h"

inherit ASGARD;

void create(){
    ::create();
/*   set_terrain(CITY);
   set_travel(PAVED_ROAD);
    set_name("Nirvana avenue");
    set_short("Nirvana avenue");
    set_long(
	"%^BOLD%^Nirvana avenue%^RESET%^
You are in Asgard's residential area.  The cobblestone street leads northeast "+
	"into a back alley and south towards Asgard's main street Excalibur.  "+
	"You can see a few run down houses to the east and a small path to "+
	"the southwest leads towards a guard tower.  The city wall is to the "+
	"north."
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","A cool breeze blows through the street.");
    set_listen("default","You can hear the chatter of peasants.");
*/
   set_long(::query_long()+"\nThis was once the residential section of the "
      "city, and scattered household items are mixed among the ruins.\n");
    set_exits( ([
	"east":"/d/laerad/parnelli/asgard/as23",
	"northeast":"/d/laerad/parnelli/asgard/as18",
	"southwest":"/d/laerad/parnelli/asgard/tower1",
	"south":"/d/laerad/parnelli/asgard/as16"
    ]) );
}
