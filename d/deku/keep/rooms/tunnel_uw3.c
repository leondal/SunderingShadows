#include <std.h>
#include "../keep.h"

inherit TUNNELUW;

void create() {
    ::create();
	set_long(TO->query_long() + "%^YELLOW%^  This tunnel continues here, up and "+
	"perhaps out, or down to whatever depths this leads, it is your decision.%^RESET%^");
     set_exits(([
		"up": KEEPR + "tunnel_uw2", "down" : KEEPR + "tunnel_uw4"
    ] ));
	
}




