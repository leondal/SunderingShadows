#include <std.h>
#include "../keep.h"

inherit TUNNELUW;

void create() {
    ::create();
	set_long(TO->query_long() + "%^YELLOW%^  This tunnel continues westward here.  "+
	"Above you though, there is a faint light shining down into the murky water.  Perhaps "+
	"you have, afterall, found something within the depths of this water grave?");
     set_exits(([
		"west": KEEPR + "tunnel_uw11", "up" : KEEPR + "burial_chamber_1"
    ] ));
	
}




