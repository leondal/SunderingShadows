#include <std.h>

inherit VAULT;

void set_rope(int rope);

int rope_present;

void create() {
    	::create();
    	set_property("light",0);
    	set_property("indoors",1);
    	set_property("no sticks",1);
    set_terrain(BUILT_CAVE);
    set_travel(DIRT_ROAD);
    	set_short("Gateway to the Abyss");
    	set_long(
@KAYLA
The walls of this cavern are dotted with manacles and hanging
chains.  Most of them have almost rusted away.  A number of bones
are scattered on the ground.  Even covered in shadows the floor looks
somewhat different than the other rooms.
KAYLA
    	);
    	set_exits(([
       	"west" : "/d/deku/dark/drider",
       	"east" : "/d/deku/dark/elite3",
       	"south" : "/d/deku/dark/room9"
    	] ));
    	set_items(([
       	"bones" : "Scattered bones of many creatures lay about.",
       	"floor" : "The floor looks peculiar upon closer examination."
    	] ));
    	
    	set_search("floor","The floor surface looks to be brittle to the west.  "+
    		"Upon closer examination you find that underneath the false floor is a pit!");
    		
        set_climb_exits((["descend":({"/d/deku/dark/pit0",20,6,100})]));
    	set_fall_desc("%^BOLD%^%^RED%^You fall into the pit tumbling into the "+
		"darkness until you come to a sudden and painful stop at the "+
		"bottom!%^RESET%^\n");
}
