#include <std.h>
#include "../keep.h"

inherit TUNNELUW;

void create() {
    ::create();
	set_long(TO->query_long() + "%^YELLOW%^  This tunnel continues here, up and "+
	"perhaps out, or eastward to whatever rests down in the depths.%^RESET%^");
     set_exits(([
		"up": KEEPR + "tunnel_uw3", "east" : KEEPR + "tunnel_uw5"
    ] ));
	
}




