#include <std.h>
#include "../keep.h"

inherit TUNNELUW;

void create() {
    ::create();
	set_long(TO->query_long() + "%^YELLOW%^  There is an opening above you, "+
	"that appears to lead out of his stagnated water.  If you dare, you can "+
	"continue downward into what may become your watery grave.%^RESET%^");
     set_exits(([
		"up": KEEPR + "tunnel4", "down" : KEEPR + "tunnel_uw2"
    ] ));
	
}




