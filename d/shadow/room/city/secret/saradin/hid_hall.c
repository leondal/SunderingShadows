//Coded by Diego//

#include <std.h>
#include "../secrets.h"

inherit VAULT;

void create(){
	::create();
	set_name("hidden hallway");
   set_short("hidden hallway");
   set_long(
   	"%^RESET%^%^ORANGE%^"+
   	"This is a secret passageway that branches off the "+
   	"main tunnel.  The room is relatively well kept for "+
   	"having been dug primatively out of the ground."+
   	"%^RESET%^\n"
   );
   set_property("indoors",1);
   set_property("light",1);
   set_smell("default","You smell old sweat.");
   set_listen("default","The room is quiet save for the sounds you make.");
   set_items(([
   	({"wall","walls","floor","ceiling"}) : "The walls are made of dirt and "+
   		"stone and seem to have been dug quickly, but "+
   		"efficiently.  Little work was done to make them "+
   		"look prettier after the tunneling was complete.\n"
  	]));
   set_exits(([
		"north" : SARADIN+"cent_room",
		"south" : SARADIN+"hid_hall0"
	]));
}