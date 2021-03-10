//Coded by Bane//
#include <std.h>
#include "/d/laerad/laerad.h"

inherit ASGARD;

void create(){
    ::create();
/*   set_terrain(CITY);
   set_travel(PAVED_ROAD);
    set_name("Wendigo street");
    set_short("Wendigo street");
    set_long(
	"%^BOLD%^Wendigo street%^RESET%^
You are in Asgard's residential area.  The cobblestone street leads northwest "+
	"into a back alley and south towards Asgard's main street Excalibur.  "+
	"You can see a few run down houses to the west and a small path to "+
	"the northeast leading into another alley.  The city wall is to the "+
	"north."
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","A cool breeze blows through the street.");
    set_listen("default","You can hear the chatter of peasants.");
*/
    set_exits( ([
	"west":"/d/laerad/parnelli/asgard/as26",
	"northeast":"/d/laerad/parnelli/asgard/as42",
	"northwest":"/d/laerad/parnelli/asgard/as19",
	"south":"/d/laerad/parnelli/asgard/as21"
    ]) );
}
